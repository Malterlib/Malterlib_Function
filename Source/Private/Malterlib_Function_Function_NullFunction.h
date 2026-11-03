// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
	struct TCCallImpl;

	struct CReturnReference;

	using CReturnReferenceReturn = CReturnReference const &;
	template <bool t_bNoExcept>
	struct TCNullFunctionImpl;

	struct CReturnReference
	{
	private:
		template <bool t_bNoExcept>
		friend struct TCNullFunctionImpl;

		template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
		friend struct TCCallImpl;

		template <typename tf_CReturn>
		[[noreturn]] operator tf_CReturn && () const
		{
			fg_NoReturn();
		}
	};

	extern CReturnReference const gc_ReturnReference;

	template <bool t_bNoExcept>
	struct TCNullFunctionImpl
	{
		template <typename ...tfp_CParams>
		[[noreturn]] CReturnReferenceReturn operator () (tfp_CParams && ...p_Params)
		{
			DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
		}

		template <typename ...tfp_CParams>
		[[noreturn]] CReturnReferenceReturn operator () (tfp_CParams && ...p_Params) const
		{
			DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
		}

		bool operator == (TCNullFunctionImpl const &_Other) const noexcept
		{
			return true;
		}

		COrdering_Partial operator <=> (TCNullFunctionImpl const &_Other) const noexcept
		{
			return COrdering_Partial::equivalent;
		}
	};

	template <>
	struct TCNullFunctionImpl<true>
	{
		template <typename ...tfp_CParams>
		[[noreturn]] CReturnReferenceReturn operator () (tfp_CParams && ...p_Params) noexcept
		{
			// Trying to call an empty TCFunction
			DMibPDebugBreak;
			fg_NoReturn();
		}

		template <typename ...tfp_CParams>
		[[noreturn]] CReturnReferenceReturn operator () (tfp_CParams && ...p_Params) const noexcept
		{
			// Trying to call an empty TCFunction
			DMibPDebugBreak;
			fg_NoReturn();
		}

		bool operator == (TCNullFunctionImpl const &_Other) const noexcept
		{
			return true;
		}

		COrdering_Partial operator <=> (TCNullFunctionImpl const &_Other) const noexcept
		{
			return COrdering_Partial::equivalent;
		}
	};
}
