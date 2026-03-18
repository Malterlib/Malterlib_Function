// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
	struct TCCallImpl;

	struct CReturnReference;

	using CReturnReferenceReturn = CReturnReference const &;
	template <bool t_bNoExcept>
	class TCNullFunctionImpl;

	struct CReturnReference
	{
	private:
		template <bool t_bNoExcept>
		friend class TCNullFunctionImpl;

		template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
		friend struct TCCallImpl;

		template <typename t_CReturn>
		[[noreturn]] operator t_CReturn && () const
		{
			fg_NoReturn();
		}
	};

	extern CReturnReference const g_ReturnReference;

	template <bool t_bNoExcept>
	class TCNullFunctionImpl
	{
	public:

		template <typename... tp_CParams>
		[[noreturn]] CReturnReferenceReturn operator ()(tp_CParams &&... p_Params)
		{
			DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
		}

		template <typename... tp_CParams>
		[[noreturn]] CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) const
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
	class TCNullFunctionImpl<true>
	{
	public:

		template <typename... tp_CParams>
		[[noreturn]] CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) noexcept
		{
			// Trying to call an empty TCFunction
			DMibPDebugBreak;
			fg_NoReturn();
		}

		template <typename... tp_CParams>
		[[noreturn]] CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) const noexcept
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
