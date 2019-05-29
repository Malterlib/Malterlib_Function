// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_FFunc>
	struct TCFunctionCallDefinition;

	template <typename t_CReturnType, typename... tp_CParams>
	struct TCFunctionCallDefinition<t_CReturnType (tp_CParams...)>
	{
		typedef t_CReturnType (CType)(void *_pImpl, tp_CParams...);
	};

	template
	<
		typename t_CFOpts
		, bool t_bSupportCompare = t_CFOpts::mc_bSupportCompare
	>
	struct TCFunctionDefinitions;

	template <typename t_CFOpts, mint t_iFunction>
	struct TCGetFunctionCallDefinition
	{
		typedef typename TCFunctionCallDefinition<typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType>::CType CType;
	};

	template <typename t_CFOpts>
	struct TCFunctionDefinitions<t_CFOpts, false>
	{
		typedef t_CFOpts CFunctionOptions;

		typedef void *(FDuplicate)(void const *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		typedef void *(FDuplicateMove)(void *_pImpl, typename t_CFOpts::CImpBase &_Allocator);

		struct CVTable
		{
			void *m_pCalls[t_CFOpts::mc_NumFunctions];
			uint32 m_Alignment;
			uint32 m_Size;
			FDelete *m_pDestroy;
			FDuplicate *m_pDuplicate;
			FDuplicateMove *m_pDuplicateMove;
			static const uint8 m_pCompareEqual = 0;
			static const uint8 m_pCompareLess = 0;
#ifdef DMibDebuggerHelpers
			ch8 const *m_pFunctorTypeName;
#endif

			template <mint t_iFunction>
			inline_always typename TCFunctionCallDefinition<typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType>::CType *f_GetFunction() const
			{
				return (typename TCFunctionCallDefinition<typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType>::CType *)m_pCalls[t_iFunction];
			}
		};

	};
	template <typename t_CFOpts>
	struct TCFunctionDefinitions<t_CFOpts, true>
	{
		typedef t_CFOpts CFunctionOptions;

		typedef void *(FDuplicate)(void const *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		typedef void *(FDuplicateMove)(void *_pImpl, typename t_CFOpts::CImpBase &_Allocator);

		struct CVTable
		{
			void *m_pCalls[t_CFOpts::mc_NumFunctions];
			uint32 m_Alignment;
			uint32 m_Size;
			FDelete *m_pDestroy;
			FDuplicate *m_pDuplicate;
			FDuplicateMove *m_pDuplicateMove;
			FCompareEqual *m_pCompareEqual;
			FCompareLess *m_pCompareLess;
#ifdef DMibDebuggerHelpers
			ch8 const *m_pFunctorTypeName;
#endif

			template <mint t_iFunction>
			inline_always typename TCFunctionCallDefinition<typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType>::CType *f_GetFunction() const
			{
				return (typename TCFunctionCallDefinition<typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType>::CType *)m_pCalls[t_iFunction];
			}
		};
	};
}
