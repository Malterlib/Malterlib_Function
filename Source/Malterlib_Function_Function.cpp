// Copyright © 2019 Nonna Holding AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

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
