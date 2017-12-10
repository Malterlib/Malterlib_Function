// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
			template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
			struct TCCallImpl;
			
			struct CReturnReference;

			typedef CReturnReference const &  CReturnReferenceReturn;
			class CNullFunctionImpl;
			
			struct CReturnReference
			{
#if defined(DCompiler_MSVC_Workaround) && DMibCompilerVersion == 1912
			public:
#else
			private:
#endif
				friend class CNullFunctionImpl;
				template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
				friend struct TCCallImpl;
				
#if defined(DCompiler_MSVC_Workaround)
				template <typename t_CReturn>
				__declspec(noreturn) operator t_CReturn && () const
				{
					fg_NoReturn();
				}
#else
				template <typename t_CReturn>
				[[noreturn]] operator t_CReturn && () const
				{
					fg_NoReturn();
				}
#endif
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

				template <typename... tp_CParams>
				[[noreturn]] CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) volatile
				{
					DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
				}
				
				template <typename... tp_CParams>
				[[noreturn]] CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) const volatile
				{
					DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
				}

				bint operator == (CNullFunctionImpl const &_Other) const
				{
					return true;
				}
				bint operator < (CNullFunctionImpl const &_Other) const
				{
					return false;
				}
			};

		}
	}
}

