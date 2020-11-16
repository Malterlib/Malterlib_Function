// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
	struct TCCallImpl;

	struct CReturnReference;

	typedef CReturnReference const &  CReturnReferenceReturn;
	class CNullFunctionImpl;

	struct CReturnReference
	{
	private:
		friend class CNullFunctionImpl;
		template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
		friend struct TCCallImpl;

		template <typename t_CReturn>
		[[noreturn]] operator t_CReturn && () const
		{
			fg_NoReturn();
		}
	};

	class CNullFunctionImpl
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

		bool operator == (CNullFunctionImpl const &_Other) const
		{
			return true;
		}
		bool operator < (CNullFunctionImpl const &_Other) const
		{
			return false;
		}
	};
}
