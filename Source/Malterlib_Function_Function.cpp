// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "Malterlib_Function_Function.h"

namespace NMib::NFunction
{
	template class TCFunction<void ()>;
	template struct TCFunctionMutable<void ()>;
	template struct TCFunctionMovable<void ()>;

	template class TCFunctionFastCall<void ()>;
	template class TCFunctionFastCall<typename NPrivate::TCAddThisTag<void (), CThisTag &>::CType>;
	template class TCFunctionFastCall<typename NPrivate::TCAddThisTag<void (), CThisTag &>::CType, CFunctionNoCopyTag>;

	template class TCFunctionNoAlloc<void ()>;
	template class TCFunctionNoAlloc<typename NPrivate::TCAddThisTag<void (), CThisTag &>::CType>;
	template class TCFunctionNoAlloc<typename NPrivate::TCAddThisTag<void (), CThisTag &>::CType, CFunctionNoCopyTag>;
}

namespace NMib::NFunction::NPrivate
{
	constexpr CReturnReference const g_ReturnReference;
}
