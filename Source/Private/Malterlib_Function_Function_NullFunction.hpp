// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename tf_CReturn>
	[[noreturn]] inline CReturnReference::operator tf_CReturn && () const
	{
		fg_NoReturn();
	}

	template <bool t_bNoExcept>
	template <typename ...tfp_CParams>
	[[noreturn]] CReturnReferenceReturn TCNullFunctionImpl<t_bNoExcept>::operator () (tfp_CParams && ...p_Params)
	{
		DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
	}

	template <bool t_bNoExcept>
	template <typename ...tfp_CParams>
	[[noreturn]] CReturnReferenceReturn TCNullFunctionImpl<t_bNoExcept>::operator () (tfp_CParams && ...p_Params) const
	{
		DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
	}

	template <bool t_bNoExcept>
	bool TCNullFunctionImpl<t_bNoExcept>::operator == (TCNullFunctionImpl const &_Other) const noexcept
	{
		return true;
	}

	template <bool t_bNoExcept>
	COrdering_Partial TCNullFunctionImpl<t_bNoExcept>::operator <=> (TCNullFunctionImpl const &_Other) const noexcept
	{
		return COrdering_Partial::equivalent;
	}

	template <typename ...tfp_CParams>
	[[noreturn]] inline CReturnReferenceReturn TCNullFunctionImpl<true>::operator () (tfp_CParams && ...p_Params) noexcept
	{
		// Trying to call an empty TCFunction
		DMibPDebugBreak;
		fg_NoReturn();
	}

	template <typename ...tfp_CParams>
	[[noreturn]] inline CReturnReferenceReturn TCNullFunctionImpl<true>::operator () (tfp_CParams && ...p_Params) const noexcept
	{
		// Trying to call an empty TCFunction
		DMibPDebugBreak;
		fg_NoReturn();
	}
}
