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
#if defined(DCompiler_MSVC_Workaround)
			public:
#else
			private:
#endif
				friend class CNullFunctionImpl;
				template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
				friend struct TCCallImpl;
				
#if defined(DCompiler_MSVC_Workaround)
#if 1
				template 
					<
						typename t_CReturn
						, typename TCEnableIf
						<
							NTraits::TCIsConstructorCallableWith<t_CReturn, void (t_CReturn&&)>::mc_Value
							&& !NTraits::TCIsConstructorCallableWith<t_CReturn, void (t_CReturn&)>::mc_Value
						>::CType * = nullptr
					>
				__declspec(noreturn) operator t_CReturn &&() const
				{
					throw 1; // Should never get here
				}

				template 
					<
						typename t_CReturn
						, typename TCEnableIf
						<
							NTraits::TCIsConstructorCallableWith<t_CReturn, void (t_CReturn&)>::mc_Value
						>::CType * = nullptr
					>
				__declspec(noreturn) operator t_CReturn &() const
				{
					throw 1; // Should never get here
				}
#else
				template <typename t_CReturn>
				__declspec(noreturn) operator t_CReturn && () const
				{
					fg_NoReturn();
				}
#endif
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

