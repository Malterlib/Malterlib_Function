# CLAUDE.md - Function Module

This file provides guidance to Claude Code (claude.ai/code) when working with the Function module in Malterlib.

## Module Overview

The Function module provides a comprehensive type-erased function wrapper implementation similar to `std::function` but with additional features and optimizations. It offers advanced function object management, member function binding utilities, functor merging capabilities, and operator functors for functional programming patterns.

## Architecture

### Core Components

#### TCFunction Template
The main function wrapper template that provides type-erased storage for callable objects:
- **Location**: `Source/Malterlib_Function_Function.h`
- **Features**:
  - Small buffer optimization (SBO) with configurable size
  - Optional heap allocation support
  - Const-correctness control via `CThisTag`
  - Equality and ordered comparison support via tag types
  - Move and copy semantics control

#### Function Options and Tags
Configuration types for customizing function behavior:
- `TCFunctionNoAllocOptions` - Controls allocation behavior and buffer sizes
- `CFunctionSupportEqualityCompareTag` - Enables equality comparison
- `CFunctionSupportOrderedCompareTag` - Enables ordered comparison
- `CFunctionNoCopyTag` - Disables copy construction
- `CFunctionNoMoveTag` - Disables move construction
- `CThisTag` - Controls const-qualification of stored functors

#### Member Function Binding
Utilities for binding member functions to objects:
- **Location**: `Source/Malterlib_Function_Bind_MemberFunction.h`
- `TCMemberFunctionFunctor` - Wraps member function pointers
- `TCMemberFunctionBoundFunctor` - Binds member functions to specific objects

#### Functor Merging
Capability to merge multiple functors into a single callable:
- **Location**: `Source/Malterlib_Function_MergeFunctors.h`
- `fg_MergeFunctors()` - Combines multiple functors into one

#### Operator Functors
Pre-defined functors for common operators:
- **Location**: `Source/Malterlib_Function_Operators.h`
- Binary operators: arithmetic, comparison, logical, bitwise
- Special operators: comma, conditional, subscript
- Assignment operators

#### Function Traits
Utilities for detecting and analyzing function properties:
- **Location**: `Source/Malterlib_Function_Traits.h`
- Virtual function detection (platform-specific)
- Member function pointer traits

### Internal Implementation

The module uses several internal headers for implementation details:
- `Function_CallImplementation.h` - Call dispatch mechanisms
- `Function_Definition.h` - Core type definitions
- `Function_Helpers.h` - Helper utilities
- `Function_Implementation.h` - Main implementation
- `Function_NullFunction.h` - Null function handling
- `Function_StorageImplementation.h` - Storage management
- `Function_VTable.h` - Virtual table for type erasure

## Usage Patterns

### Basic Function Wrapper

```cpp
// Simple function wrapper with default settings (const invocation)
TCFunction<int (int, int)> fAdd = [](int _A, int _B)
	{
		return _A + _B;
	}
;
int nResult = fAdd(3, 4);	// Returns 7

// Function wrapper with mutable invocation
TCFunction<void (CThisTag &, int)> fMutable = [nCounter = 0](int _Value) mutable
	{
		nCounter += _Value;
		DMibLog(Info, "Counter: {}", nCounter);
	}
;

// Via conveniency type
TCFunctionMutable<void (int)> fMutable = [nCounter = 0](int _Value) mutable
	{
		nCounter += _Value;
		DMibLog(Info, "Counter: {}", nCounter);
	}
;
fMutable(5);	// Can modify captured state
```

### Using Operator Functors

```cpp
// Use pre-defined operator functors
COperatorFunctor_Add fAdd;
int nSum = fAdd(3, 4);	// Returns 7

COperatorFunctor_Less fLess;
bool bResult = fLess(3, 5);	// Returns true

// Conditional operator functor
COperatorFunctor_Conditional fConditional;
int nValue = fConditional(true, 10, 20);	// Returns 10

// Subscript operator functor
COperatorFunctor_Subscript fSubscript;
int Array[5] = {1, 2, 3, 4, 5};
int nElement = fSubscript(Array, 2);	// Returns 3
```

### Advanced Const-Correctness Control

```cpp
// Const invocation (default)
TCFunction<int ()> fConstFunc = []() { return 42; };

// Mutable invocation using TCFunctionMutable
TCFunctionMutable<int ()> fMutableFunc = [nCounter = 0]() mutable
	{
		return ++nCounter;
	}
;

// Const invocation with CThisTag (explicit)
TCFunction<int (CThisTag const &)> fExplicitConst = []()
	{
		return 42;
	}
;
```

## Implementation Details

### Small Buffer Optimization (SBO)
The function wrapper uses SBO to avoid heap allocations for small functors:
- Default buffer size: 4 * sizeof(void*) (typically 32 bytes on 64-bit)
- Configurable via `TCFunctionNoAllocOptions`
- Alignment requirements are respected

### Type Erasure Mechanism
The module uses a virtual table approach for type erasure:
- VTable contains function pointers for operations
- Separate storage for small and large functors
- Optimized call dispatch based on configuration

### Performance Optimizations
- Separate call pointer option for faster invocation
- Compile-time configuration of features
- Minimal overhead for small functors
- Move semantics preferred over copy when possible

### Platform-Specific Features
- Virtual member function detection (non-Windows platforms)
- Uses `DMibCanDetectVirtualMemberFunctions_Dynamic` macro
- Requires parsing of function pointer representation

## Testing

The module includes comprehensive tests in the `Test/` directory:
- `Test_Malterlib_Function_Function.cpp` - Core function wrapper tests
- `Test_Malterlib_Function_Bind.cpp` - Member function binding tests
- `Test_Malterlib_Function_Traits.cpp` - Traits functionality tests

### Running Tests
```bash
# Build and run Function module tests
MalterlibBuildShowProgress=false ./mib build Tests macOS arm64 Debug
/opt/Deploy/Tests/RunAllTests --paths '["Malterlib/Function*"]'
```

## Dependencies

### Internal Dependencies
- **Core** - Core Malterlib functionality
- **Storage** - UniquePointer and memory management
- **Type** - Type traits utilities
- **Test** - Testing framework
- **Debug** - Logging and debugging
- **Container** - Container types (CByteVector)
- **Time** - Performance timing utilities
- **String** - String utilities

### External Dependencies (via Boost)
Only used in tests for comparing performance and correctness against boost implementation.

## Build Configuration

The module is configured via `Malterlib_Function.MHeader`:
- Part of `Lib_Malterlib` library
- Supports internal testing via `MalterlibEnableInternalTests`
- Include root: `Include/` directory
- Module can be enabled/disabled via `MalterlibLibrary_Function` property

## Best Practices

### Function Wrapper Selection
1. Use default `TCFunction` for general purposes
2. Configure buffer size based on typical functor sizes
3. Disable heap allocation for performance-critical code: TCFunctionNoAlloc
4. Use comparison tags only when needed (adds overhead)
5. When you need a mutable function use TCFunctionMutable
6. When you need a mutable function should be movable use TCFunctionMovable

### Member Function Handling
1. Use `TCMemberFunctionFunctor` for unbound member functions
2. Use `TCMemberFunctionBoundFunctor` for bound member functions
3. Consider lifetime of bound objects carefully

### Performance Considerations
1. Prefer small functors that fit in SBO buffer
2. Use move semantics for large functors
3. Configure options at compile time for best performance
4. Avoid unnecessary features (comparison, ordering)

### Const-Correctness
1. Default to const invocation for thread safety
2. Use mutable invocation only when state modification is needed

## Common Patterns

### Deferred Execution
```cpp
using FDeferredAction = TCFunction<void()>;
NContainer::TCLinkedList<FDeferredAction> m_DeferredActions;

void f_Defer(FDeferredAction &&_Action)
{
	m_DeferredActions.f_Push(fg_Move(_Action));
}

void f_ProcessDeferred()
{
	while (!m_DeferredActions.f_IsEmpty())
	{
		auto Action = m_DeferredActions.f_Pop();
		Action();
	}
}
```

## Important Notes

1. The module provides a more feature-rich alternative to `std::function`
2. Configuration is done at compile time for optimal performance
3. The implementation is header-heavy for inlining opportunities
4. Platform differences exist for virtual function detection
5. The module follows Malterlib naming conventions strictly
6. Type erasure overhead is minimized through careful design
7. Small buffer optimization is crucial for performance
