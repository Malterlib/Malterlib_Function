// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

/// \file	Malterlib_Function_Function.h
///			File for the function templates

#include <Mib/Storage/Indirection>

namespace NMib::NFunction
{
	/** \brief Used to specify that a function should implement comparison operators

		If you specify this tag the functors you put into the function has to
		support equal and less than comparison operators.
	*/
	struct CFunctionSupportCompareTag
	{
	};

	/// Used to specify that a function should not implement copy constructors
	struct CFunctionNoCopyTag
	{
	};

	/// Used to specify that a function should not implement move constructors
	struct CFunctionNoMoveTag
	{
	};


	/**	\brief Used to specify the qualifiers of a functor invocation

		Specify this tag together with qualifiers to determine how the function
		in a function is called, and how a function can be called.

		Examples:
		~~~
		TCFunction<void ()>							// Defaults to const invocation
		TCFunction<void (CThisTag &)>				// mutable invocation
		TCFunction<void (CThisTag const &)>			// const invocation
		TCFunction<void (CThisTag volatile &)>		// volatile invocation
		TCFunction<void (CThisTag const volatile &)>// const volatile invocation
		TCFunction<void (CThisTag &, int)>			// mutable invocation with param
		~~~

		Keep in mind that the tag has to be specified as the first parameter of
		the function, and that it will be stripped.

		Notice also that the tag has to be specified as a reference, otherwise
		the compiler will drop the qualifiers.
	*/
	struct CThisTag
	{
	};

	/**	\brief Used to specify options to to TCFunction and TCFunctionNoAlloc class

	*/
	template
	<
		bint t_AllowAlloc = false
		/// Set to true to allow the function to allocate memory dynamically
		, uint32 t_MaxSize = sizeof(void *)*4
		/// The maximum size of the functor object that can be put in the TCFunctionXXXX object
		, uint32 t_Alignment = TCConstantMax<mint, sizeof(void *), NTraits::TCAlignmentOf<fp64>::mc_Value>::mc_Value
		/// The maximum alignment of a type that can be put in the TCFunctionXXXX object
	>
	struct TCFunctionNoAllocOptions
	{
		static constexpr mint mc_MaxSize = (t_MaxSize + t_Alignment - 1) & ~mint(t_Alignment - 1);
		static constexpr mint mc_Alignment = t_Alignment;
		static constexpr mint mc_bAllowAlloc = t_AllowAlloc;
	};

	///@}
}

#include "Private/Malterlib_Function_Function_Helpers.h"
#include "Private/Malterlib_Function_Function_NullFunction.h"
#include "Private/Malterlib_Function_Function_Definition.h"
#include "Private/Malterlib_Function_Function_CallImplementation.h"
#include "Private/Malterlib_Function_Function_VTable.h"
#include "Private/Malterlib_Function_Function_StorageImplementation.h"
#include "Private/Malterlib_Function_Function_Implementation.h"

namespace NMib::NFunction
{
	namespace NPrivate
	{
		template <typename t_CType>
		struct TCIsTCFunctionImpl
		{
			enum
			{
				mc_Value = false
			};
		};

		template <typename t_CLeft, typename t_CRight, bint t_bBothFunction = TCIsTCFunctionImpl<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CLeft>::CType>::CType>::mc_Value && TCIsTCFunctionImpl<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CRight>::CType>::CType>::mc_Value>
		struct TCIsTCFunctionCompareInValid
		{
			enum
			{
				mc_bLeftFunction = TCIsTCFunctionImpl<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CLeft>::CType>::CType>::mc_Value
				, mc_bRightFunction = TCIsTCFunctionImpl<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CRight>::CType>::CType>::mc_Value
				, mc_Value = (mc_bLeftFunction || mc_bRightFunction)
			};
		};

		template <typename t_CLeft, typename t_CRight>
		struct TCIsTCFunctionCompareInValid<t_CLeft, t_CRight, true>
		{
			enum
			{
				mc_Value
				=
				!NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CLeft>::CType>::CType, typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CRight>::CType>::CType>::mc_Value
				|| !(NTraits::TCRemoveReference<t_CLeft>::CType::CFunctionOptions::mc_bSupportCompare)
			};
		};

		template <typename t_CType, typename t_CSelf>
		struct TCIsSelf
		{
			using CDecayed = typename NTraits::TCDecay<t_CType>::CType;
			enum
			{
				mc_Value = NTraits::TCIsSame<CDecayed, t_CSelf>::mc_Value
			};
		};
	}
	template <typename t_CFunction>
	struct TCFunctionInfo;

	namespace NPrivate
	{
		template <typename... tp_COptions>
		struct TCFunctionOptions : public TCFunctionOptionsShared<NMemory::CAllocator_Heap, TCFunctionNoAllocOptions<true, sizeof(void *)*3>, tp_COptions...>
		{
			typedef NPrivate::TCFunctionNoAllocBase<TCFunctionOptions> CImpBase;
		};
	}

	/// General function template tuned for a mix of fast construction and fast calls.
	template
	<
		typename t_CFunction		/// The function definition to contain
		, typename... tp_COptions	/// Arguments. Can be function definition, option (CFunctionSupportCompareTag) or allocator
	>
	class TCFunction
		: public NPrivate::TCFunctionImplementation
		<
			NPrivate::TCFunctionOptions
			<
				t_CFunction
				, tp_COptions...
			>
		>
		, TCSupportCopyMove<NPrivate::TCParseFunctionOptions<void, tp_COptions...>::mc_bSupportCopy, NPrivate::TCParseFunctionOptions<void, tp_COptions...>::mc_bSupportMove>
	{
		template <typename t_CLeft0, typename t_CRight0, bint t_bBothFunction0>
		friend struct NPrivate::TCIsTCFunctionCompareInValid;

		template <typename t_CFunction0>
		friend struct TCFunctionInfo;


		using CFunctionOptions = NPrivate::TCFunctionOptions<t_CFunction, tp_COptions...>;
		typedef NPrivate::TCFunctionImplementation<CFunctionOptions> CSuper;

	public:
		~TCFunction()
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
		TCFunction()
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyConstruct
		TCFunction(TCFunction const &_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveConstruct
		TCFunction(TCFunction &&_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyAssignment
		TCFunction &operator =(TCFunction const &_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveAssignment
		TCFunction &operator =(TCFunction &&_Other) = default;

		/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
		template
		<
			typename tf_CFunction
			, TCEnableIfType
			<
				!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
				&& !NPrivate::TCIsSelf<tf_CFunction, TCFunction>::mc_Value
				, bool
			> = true /**@hidden*/
		>
		TCFunction(tf_CFunction &&_Function)
			: CSuper(fg_Forward<tf_CFunction>(_Function))
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
		template
		<
			typename tf_CFunction
			, TCEnableIfType
			<
				!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
				&& !NPrivate::TCIsSelf<tf_CFunction, TCFunction>::mc_Value
				, bool
			> = true /**@hidden*/
		>
		TCFunction &operator = (tf_CFunction &&_Function)
		{
			CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
			return *this;
		}
	};

	namespace NPrivate
	{
		template <typename t_FSignature, typename t_CTag>
		struct TCAddThisTag;

		template <typename t_CTag, typename t_CReturn, typename ...tp_CParams>
		struct TCAddThisTag<t_CReturn (tp_CParams...), t_CTag>
		{
			using CType = t_CReturn (t_CTag, tp_CParams...);
		};
	}

	template <typename t_CSignature>
	using TCFunctionMutable = TCFunction<typename NPrivate::TCAddThisTag<t_CSignature, CThisTag &>::CType>;

	template <typename t_CSignature>
	using TCFunctionMovable = TCFunction<typename NPrivate::TCAddThisTag<t_CSignature, CThisTag &>::CType, CFunctionNoCopyTag>;

	namespace NPrivate
	{
		template <typename... tp_COptions>
		struct TCFunctionOptionsFastCall : public TCFunctionOptionsShared<NMemory::CAllocator_Heap, TCFunctionNoAllocOptions<>, tp_COptions...>
		{
			typedef NPrivate::TCFunctionBase<TCFunctionOptionsFastCall> CImpBase;
		};
	}

	/// Function template tuned for maximum performance of calls.
	template
	<
		typename t_CFunction /// The function definition to contain
		, typename... tp_COptions /// Arguments. Can be function definition, option (CFunctionSupportCompareTag) or allocator
	>
	class TCFunctionFastCall
		: public NPrivate::TCFunctionImplementation<NPrivate::TCFunctionOptionsFastCall<t_CFunction, tp_COptions...>>
		, TCSupportCopyMove<NPrivate::TCParseFunctionOptions<void, tp_COptions...>::mc_bSupportCopy, NPrivate::TCParseFunctionOptions<void, tp_COptions...>::mc_bSupportMove>
	{
		template <typename t_CLeft0, typename t_CRight0, bint t_bBothFunction0>
		friend struct NPrivate::TCIsTCFunctionCompareInValid;

		template <typename t_CFunction0>
		friend struct TCFunctionInfo;

		typedef NPrivate::TCFunctionOptionsFastCall<t_CFunction, tp_COptions...> CFunctionOptions;
		typedef NPrivate::TCFunctionImplementation<CFunctionOptions> CSuper;

	public:
		~TCFunctionFastCall()
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
		TCFunctionFastCall()
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyConstruct
		TCFunctionFastCall(TCFunctionFastCall const &_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveConstruct
		TCFunctionFastCall(TCFunctionFastCall &&_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyAssignment
		TCFunctionFastCall &operator =(TCFunctionFastCall const &_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveAssignment
		TCFunctionFastCall &operator =(TCFunctionFastCall &&_Other) = default;

		/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
		template
		<
			typename tf_CFunction
			, TCEnableIfType
			<
				!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
				&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionFastCall>::mc_Value
				, bool
			> = true /**@hidden*/
		>
		TCFunctionFastCall(tf_CFunction &&_Function)
			: CSuper(fg_Forward<tf_CFunction>(_Function))
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
		template
		<
			typename tf_CFunction
			, TCEnableIfType
			<
				!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
				&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionFastCall>::mc_Value
				, bool
			> = true /**@hidden*/
		>
		TCFunctionFastCall &operator = (tf_CFunction &&_Function)
		{
			CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
			return *this;
		}

		/// @}
	};

	template <typename t_CSignature>
	using TCFunctionFastCallMutable = TCFunctionFastCall<typename NPrivate::TCAddThisTag<t_CSignature, CThisTag &>::CType>;

	template <typename t_CSignature>
	using TCFunctionFastCallMovable = TCFunctionFastCall<typename NPrivate::TCAddThisTag<t_CSignature, CThisTag &>::CType, CFunctionNoCopyTag>;

	namespace NPrivate
	{
		template <typename... tp_COptions>
		struct TCFunctionOptionsSmall : public TCFunctionOptionsShared<NMemory::CAllocator_Heap, TCFunctionNoAllocOptions<>, tp_COptions...>
		{
			typedef NPrivate::TCFunctionSmallBase<TCFunctionOptionsSmall> CImpBase;
		};
	}

	/// Function template tuned for minimum storage of empty functions.
	template
	<
		typename t_CFunction /// The function definition to contain
		, typename... tp_COptions /// Arguments. Can be function definition, option (CFunctionSupportCompareTag) or allocator
	>
	class TCFunctionSmall
		: public NPrivate::TCFunctionImplementation<NPrivate::TCFunctionOptionsSmall<t_CFunction, tp_COptions...>>
		, TCSupportCopyMove<NPrivate::TCParseFunctionOptions<void, tp_COptions...>::mc_bSupportCopy, NPrivate::TCParseFunctionOptions<void, tp_COptions...>::mc_bSupportMove>
	{
		template <typename t_CLeft0, typename t_CRight0, bint t_bBothFunction0>
		friend struct NPrivate::TCIsTCFunctionCompareInValid;

		template <typename t_CFunction0>
		friend struct TCFunctionInfo;

		typedef NPrivate::TCFunctionOptionsSmall<t_CFunction, tp_COptions...> CFunctionOptions;
		typedef NPrivate::TCFunctionImplementation<CFunctionOptions> CSuper;

	public:
		~TCFunctionSmall()
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
		TCFunctionSmall()
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyConstruct
		TCFunctionSmall(TCFunctionSmall const &_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveConstruct
		TCFunctionSmall(TCFunctionSmall &&_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyAssignment
		TCFunctionSmall &operator =(TCFunctionSmall const &_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveAssignment
		TCFunctionSmall &operator =(TCFunctionSmall &&_Other) = default;

		/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
		template
		<
			typename tf_CFunction
			, TCEnableIfType
			<
				!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
				&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionSmall>::mc_Value
				, bool
			> = true /**@hidden*/
		>
		TCFunctionSmall(tf_CFunction &&_Function)
			: CSuper(fg_Forward<tf_CFunction>(_Function))
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
		template
		<
			typename tf_CFunction
			, TCEnableIfType
			<
				!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
				&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionSmall>::mc_Value
				, bool
			> = true /**@hidden*/
		>
		TCFunctionSmall &operator = (tf_CFunction &&_Function)
		{
			CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
			return *this;
		}
	};

	template <typename t_CSignature>
	using TCFunctionSmallMutable = TCFunctionSmall<typename NPrivate::TCAddThisTag<t_CSignature, CThisTag &>::CType>;

	template <typename t_CSignature>
	using TCFunctionSmallMovable = TCFunctionSmall<typename NPrivate::TCAddThisTag<t_CSignature, CThisTag &>::CType, CFunctionNoCopyTag>;

	namespace NPrivate
	{
		template <typename... tp_COptions>
		struct TCFunctionOptionsNoAlloc : public TCFunctionOptionsShared<NMemory::CAllocator_Disable, TCFunctionNoAllocOptions<>, tp_COptions...>
		{
			typedef NPrivate::TCFunctionNoAllocBase<TCFunctionOptionsNoAlloc> CImpBase;
		};
	}

	//// Function template tuned for maximum call speed and maximum construction speed.
	template
	<
		typename t_CFunction /// The function definition to contain
		, typename... tp_COptions /// Arguments. Can be function definition, option (CFunctionSupportCompareTag) or allocator
	>
	class TCFunctionNoAlloc
		: public NPrivate::TCFunctionImplementation
		<
			NPrivate::TCFunctionOptionsNoAlloc<t_CFunction, tp_COptions...>
		>
		, TCSupportCopyMove<NPrivate::TCParseFunctionOptions<void, tp_COptions...>::mc_bSupportCopy, NPrivate::TCParseFunctionOptions<void, tp_COptions...>::mc_bSupportMove>
	{
		template <typename t_CLeft0, typename t_CRight0, bint t_bBothFunction0>
		friend struct NPrivate::TCIsTCFunctionCompareInValid;

		template <typename t_CFunction0>
		friend struct TCFunctionInfo;

		typedef NPrivate::TCFunctionOptionsNoAlloc<t_CFunction, tp_COptions...> CFunctionOptions;
		typedef NPrivate::TCFunctionImplementation<CFunctionOptions> CSuper;

	public:
		~TCFunctionNoAlloc()
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
		TCFunctionNoAlloc()
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyConstruct
		TCFunctionNoAlloc(TCFunctionNoAlloc const &_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveConstruct
		TCFunctionNoAlloc(TCFunctionNoAlloc &&_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyAssignment
		TCFunctionNoAlloc &operator =(TCFunctionNoAlloc const &_Other) = default;
		/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveAssignment
		TCFunctionNoAlloc &operator =(TCFunctionNoAlloc &&_Other) = default;

		/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
		template
		<
			typename tf_CFunction
			, TCEnableIfType
			<
				!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
				&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionNoAlloc>::mc_Value
				, bool
			> = true /**@hidden*/
		>
		TCFunctionNoAlloc(tf_CFunction &&_Function)
			: CSuper(fg_Forward<tf_CFunction>(_Function))
		{
		}

		/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
		template
		<
			typename tf_CFunction
			, TCEnableIfType
			<
				!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
				&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionNoAlloc>::mc_Value
				, bool
			> = true /**@hidden*/
		>
		TCFunctionNoAlloc &operator = (tf_CFunction &&_Function)
		{
			CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
			return *this;
		}

	};

	template <typename t_CSignature>
	using TCFunctionNoAllocMutable = TCFunctionNoAlloc<typename NPrivate::TCAddThisTag<t_CSignature, CThisTag &>::CType>;

	template <typename t_CSignature>
	using TCFunctionNoAllocMovable = TCFunctionNoAlloc<typename NPrivate::TCAddThisTag<t_CSignature, CThisTag &>::CType, CFunctionNoCopyTag>;

	namespace NPrivate
	{
		template <typename t_CFunction, typename... tp_COptions>
		struct TCIsTCFunctionImpl<TCFunction<t_CFunction, tp_COptions...>>
		{
			enum
			{
				mc_Value = true
			};
		};

		template <typename t_CFunction, typename... tp_COptions>
		struct TCIsTCFunctionImpl<TCFunctionFastCall<t_CFunction, tp_COptions...>>
		{
			enum
			{
				mc_Value = true
			};
		};

		template <typename t_CFunction, typename... tp_COptions>
		struct TCIsTCFunctionImpl<TCFunctionNoAlloc<t_CFunction, tp_COptions...>>
		{
			enum
			{
				mc_Value = true
			};
		};

		template <typename t_CFunction, typename... tp_COptions>
		struct TCIsTCFunctionImpl<TCFunctionSmall<t_CFunction, tp_COptions...>>
		{
			enum
			{
				mc_Value = true
			};
		};
	}

	template <typename tf_CLeft, typename tf_CRight>
	TCEnableIfType<NPrivate::TCIsTCFunctionCompareInValid<tf_CLeft, tf_CRight>::mc_Value, bint> operator == (tf_CLeft &&_Left, tf_CRight &&_Right)
	{
		static_assert(!NPrivate::TCIsTCFunctionCompareInValid<tf_CLeft, tf_CRight>::mc_Value
			, "Compare not allowed");
		return true;
	}

	template <typename tf_CLeft, typename tf_CRight>
	TCEnableIfType<NPrivate::TCIsTCFunctionCompareInValid<tf_CLeft, tf_CRight>::mc_Value, bint> operator < (tf_CLeft &&_Left, tf_CRight &&_Right)
	{
		static_assert(!NPrivate::TCIsTCFunctionCompareInValid<tf_CLeft, tf_CRight>::mc_Value
			, "Compare not allowed");
		return true;
	}

	template <typename t_CFunction>
	struct TCFunctionInfo
	{
		static constexpr mint mc_nCalls = t_CFunction::CFunctionOptions::mc_NumFunctions;

		template <mint t_iCall>
		using TCCallType = typename NPrivate::TCGetCallInfo<typename t_CFunction::CFunctionOptions::CFunctionList, t_iCall>::CType;
	};
}

#ifndef DMibPNoShortCuts
	using namespace NMib::NFunction;	
#endif
