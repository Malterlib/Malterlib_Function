// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_FFunc>
	struct TCFunctionCallDefinition;

	template <typename t_CReturnType, typename... tp_CParams>
	struct TCFunctionCallDefinition<t_CReturnType (tp_CParams...)>
	{
		using CType = t_CReturnType (void *_pImpl, tp_CParams...);
	};

	template <typename t_CReturnType, typename... tp_CParams>
	struct TCFunctionCallDefinition<t_CReturnType (tp_CParams...) noexcept>
	{
		using CType = t_CReturnType (void *_pImpl, tp_CParams...) noexcept;
	};

	template
	<
		typename t_CFOpts
		, bool t_bSupportEqualityCompare = t_CFOpts::mc_bSupportEqualityCompare
		, bool t_bSupportOrderedCompare = t_CFOpts::mc_bSupportOrderedCompare
	>
	struct TCFunctionDefinitions;

	template <typename t_CFOpts, umint t_iFunction, typename t_CFunctionList = typename t_CFOpts::CFunctionList>
	struct TCGetFunctionCallDefinition;

	template <typename t_CFOpts, umint t_iFunction, typename... tp_CFunctions>
	struct TCGetFunctionCallDefinition<t_CFOpts, t_iFunction, NMeta::TCTypeList<tp_CFunctions...>>
	{
		using CType = typename TCFunctionCallDefinition<typename TCDetermineFunctionDefinition<tp_CFunctions...[t_iFunction]>::CType>::CType;
	};

	template <umint t_iFunction, typename t_FCall>
	struct TCVTableCall
	{
		t_FCall *m_pCall;
	};

	template <typename t_CIndices, typename... tp_FCalls>
	struct TCVTableCallsImp;

	template <umint... tp_Indices, typename... tp_FCalls>
	struct TCVTableCallsImp<NMeta::TCIndices<tp_Indices...>, tp_FCalls...>
		: TCVTableCall<tp_Indices, tp_FCalls>...
	{
		constexpr TCVTableCallsImp(tp_FCalls *...p_Calls)
			: TCVTableCall<tp_Indices, tp_FCalls>{p_Calls}...
		{
		}

		template <umint t_iFunction>
		mark_artificial inline_always tp_FCalls...[t_iFunction] *f_GetFunction() const
		{
			return TCVTableCall<t_iFunction, tp_FCalls...[t_iFunction]>::m_pCall;
		}
	};

	template <typename t_CFunctionList>
	struct TCGetVTableCalls;

	template <typename... tp_CFunctions>
	struct TCGetVTableCalls<NMeta::TCTypeList<tp_CFunctions...>>
	{
		using CType = TCVTableCallsImp
			<
				NMeta::TCConsecutiveIndices<sizeof...(tp_CFunctions)>
				, typename TCFunctionCallDefinition<typename TCDetermineFunctionDefinition<tp_CFunctions>::CType>::CType...
			>
		;
	};

	template <typename t_CFOpts>
	struct TCFunctionDefinitions<t_CFOpts, false, false>
	{
		using CFunctionOptions = t_CFOpts;

		using FDuplicate = void *(void const *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		using FDuplicateMove = void *(void *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		using CCalls = typename TCGetVTableCalls<typename t_CFOpts::CFunctionList>::CType;

		struct CVTable
		{
			CCalls m_Calls;
			uint32 m_Alignment;
			uint32 m_Size;
			FDelete *m_pDestroy;
			FDuplicate *m_pDuplicate;
			FDuplicateMove *m_pDuplicateMove;
			static const uint8 m_pCompareEqual = 0;
			static const uint8 m_pCompareSpaceship = 0;
		};

	};

	template <typename t_CFOpts>
	struct TCFunctionDefinitions<t_CFOpts, true, false>
	{
		using CFunctionOptions = t_CFOpts;

		using FDuplicate = void *(void const *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		using FDuplicateMove = void *(void *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		using CCalls = typename TCGetVTableCalls<typename t_CFOpts::CFunctionList>::CType;

		struct CVTable
		{
			CCalls m_Calls;
			uint32 m_Alignment;
			uint32 m_Size;
			FDelete *m_pDestroy;
			FDuplicate *m_pDuplicate;
			FDuplicateMove *m_pDuplicateMove;
			FCompareEqual *m_pCompareEqual;
			static const uint8 m_pCompareSpaceship = 0;
		};
	};

	template <typename t_CFOpts>
	struct TCFunctionDefinitions<t_CFOpts, false, true>
	{
		using CFunctionOptions = t_CFOpts;

		using FDuplicate = void *(void const *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		using FDuplicateMove = void *(void *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		using CCalls = typename TCGetVTableCalls<typename t_CFOpts::CFunctionList>::CType;

		struct CVTable
		{
			CCalls m_Calls;
			uint32 m_Alignment;
			uint32 m_Size;
			FDelete *m_pDestroy;
			FDuplicate *m_pDuplicate;
			FDuplicateMove *m_pDuplicateMove;
			static const uint8 m_pCompareEqual = 0;
			FCompareSpaceship *m_pCompareSpaceship;
		};
	};

	template <typename t_CFOpts>
	struct TCFunctionDefinitions<t_CFOpts, true, true>
	{
		using CFunctionOptions = t_CFOpts;

		using FDuplicate = void *(void const *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		using FDuplicateMove = void *(void *_pImpl, typename t_CFOpts::CImpBase &_Allocator);
		using CCalls = typename TCGetVTableCalls<typename t_CFOpts::CFunctionList>::CType;

		struct CVTable
		{
			CCalls m_Calls;
			uint32 m_Alignment;
			uint32 m_Size;
			FDelete *m_pDestroy;
			FDuplicate *m_pDuplicate;
			FDuplicateMove *m_pDuplicateMove;
			FCompareEqual *m_pCompareEqual;
			FCompareSpaceship *m_pCompareSpaceship;
		};
	};
}
