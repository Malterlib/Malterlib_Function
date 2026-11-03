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
		[[noreturn]] operator tf_CReturn && () const;
	};

	extern CReturnReference const gc_ReturnReference;

	template <bool t_bNoExcept>
	struct TCNullFunctionImpl
	{
		template <typename ...tfp_CParams>
		[[noreturn]] CReturnReferenceReturn operator () (tfp_CParams && ...p_Params);
		template <typename ...tfp_CParams>
		[[noreturn]] CReturnReferenceReturn operator () (tfp_CParams && ...p_Params) const;

		bool operator == (TCNullFunctionImpl const &_Other) const noexcept;
		COrdering_Partial operator <=> (TCNullFunctionImpl const &_Other) const noexcept;
	};

	template <>
	struct TCNullFunctionImpl<true>
	{
		template <typename ...tfp_CParams>
		[[noreturn]] CReturnReferenceReturn operator () (tfp_CParams && ...p_Params) noexcept;
		template <typename ...tfp_CParams>
		[[noreturn]] CReturnReferenceReturn operator () (tfp_CParams && ...p_Params) const noexcept;

		bool operator == (TCNullFunctionImpl const &_Other) const noexcept;
		COrdering_Partial operator <=> (TCNullFunctionImpl const &_Other) const noexcept;
	};
}

#include "Malterlib_Function_Function_NullFunction.hpp"
