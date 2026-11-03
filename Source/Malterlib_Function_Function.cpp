// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Malterlib_Function_Function.h"

namespace NMib::NFunction
{
	template struct TCFunction<void ()>;
	template struct TCFunctionMutable<void ()>;
	template struct TCFunctionMovable<void ()>;

	template struct TCFunctionFastCall<void ()>;
	template struct TCFunctionFastCall<typename NPrivate::TCAddThisTag<void (), CThisTag &>::FType>;
	template struct TCFunctionFastCall<typename NPrivate::TCAddThisTag<void (), CThisTag &>::FType, CFunctionNoCopyTag>;

	template struct TCFunctionNoAlloc<void ()>;
	template struct TCFunctionNoAlloc<typename NPrivate::TCAddThisTag<void (), CThisTag &>::FType>;
	template struct TCFunctionNoAlloc<typename NPrivate::TCAddThisTag<void (), CThisTag &>::FType, CFunctionNoCopyTag>;
}

namespace NMib::NFunction::NPrivate
{
	constexpr CReturnReference const gc_ReturnReference;

	bool TCNullFunctionImpl<true>::operator == (TCNullFunctionImpl const &_Other) const noexcept
	{
		return true;
	}

	COrdering_Partial TCNullFunctionImpl<true>::operator <=> (TCNullFunctionImpl const &_Other) const noexcept
	{
		return COrdering_Partial::equivalent;
	}
}
