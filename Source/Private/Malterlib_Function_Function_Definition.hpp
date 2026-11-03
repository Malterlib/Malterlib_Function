// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <umint ...tp_Indices, typename ...tp_FCalls>
	constexpr TCVTableCallsImp<NMeta::TCIndices<tp_Indices...>, tp_FCalls...>::TCVTableCallsImp(tp_FCalls * ...p_fCalls)
		: TCVTableCall<tp_Indices, tp_FCalls>{p_fCalls}...
	{
	}

	template <umint ...tp_Indices, typename ...tp_FCalls>
	template <umint tf_iFunction>
	mark_artificial inline_always tp_FCalls...[tf_iFunction] *TCVTableCallsImp<NMeta::TCIndices<tp_Indices...>, tp_FCalls...>::f_GetFunction() const
	{
		return TCVTableCall<tf_iFunction, tp_FCalls...[tf_iFunction]>::m_pCall;
	}
}
