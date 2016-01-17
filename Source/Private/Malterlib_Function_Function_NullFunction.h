// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
			struct CReturnReference;

			typedef CReturnReference const &  CReturnReferenceReturn;

			struct CReturnReference
			{
#ifdef DCompiler_MSVC
				template <typename t_CReturn, typename TCEnableIf<NTraits::TCIsConstructorCallableWith<t_CReturn, void (t_CReturn&)>::mc_Value && !NTraits::TCIsConstructorCallableWith<t_CReturn, void (t_CReturn&&)>::mc_Value>::CType * = nullptr>
				__declspec(noreturn) operator t_CReturn &() const
				{
					throw 1; // Should never get here
				}
				template <typename t_CReturn, typename TCEnableIf<NTraits::TCIsConstructorCallableWith<t_CReturn, void (t_CReturn&&)>::mc_Value>::CType * = nullptr>
				__declspec(noreturn) operator t_CReturn &&() const
				{
					throw 1; // Should never get here
				}
#else
				template <typename t_CReturn>
				operator t_CReturn && () const
				{
					return static_cast<t_CReturn &&>((*((t_CReturn *)nullptr)));
				}
#endif
			};

			class CNullFunctionImpl
			{
				static CReturnReferenceReturn fs_GetReference()
				{
					return *((CReturnReference const *)nullptr);
				}
			public:

				template <typename... tp_CParams>
				CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) 
				{
					DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
					return fs_GetReference();
				}

				template <typename... tp_CParams>
				CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) const
				{
					DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
					return fs_GetReference();
				}

				template <typename... tp_CParams>
				CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) volatile
				{
					DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
					return fs_GetReference();
				}
				
				template <typename... tp_CParams>
				CReturnReferenceReturn operator ()(tp_CParams &&... p_Params) const volatile
				{
					DMibErrorBadFunctionCall("Trying to call an empty TCFunction");
					return fs_GetReference();
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

