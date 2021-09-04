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
		, bool t_bSupportEqualityCompare = t_CFOpts::mc_bSupportEqualityCompare
		, bool t_bSupportOrderedCompare = t_CFOpts::mc_bSupportOrderedCompare
	>
	struct TCFunctionDefinitions;

	template <typename t_CFOpts, mint t_iFunction>
	struct TCGetFunctionCallDefinition
	{
		typedef typename TCFunctionCallDefinition<typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType>::CType CType;
	};

	template <typename t_CFOpts>
	struct TCFunctionDefinitions<t_CFOpts, false, false>
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
			static const uint8 m_pCompareSpaceship = 0;
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
	struct TCFunctionDefinitions<t_CFOpts, true, false>
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
			static const uint8 m_pCompareSpaceship = 0;
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
	struct TCFunctionDefinitions<t_CFOpts, false, true>
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
			FCompareSpaceship *m_pCompareSpaceship;
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
	struct TCFunctionDefinitions<t_CFOpts, true, true>
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
			FCompareSpaceship *m_pCompareSpaceship;
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
