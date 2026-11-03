// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_FFunc>
	struct TCFunctionCallDefinition;

	template <typename t_CReturnType, typename ...tp_CParams>
	struct TCFunctionCallDefinition<t_CReturnType (tp_CParams ...p_Params)>
	{
		using FType = t_CReturnType (void *_pImpl, tp_CParams ...p_Params);
	};

	template <typename t_CReturnType, typename ...tp_CParams>
	struct TCFunctionCallDefinition<t_CReturnType (tp_CParams ...p_Params) noexcept>
	{
		using FType = t_CReturnType (void *_pImpl, tp_CParams ...p_Params) noexcept;
	};

	template <typename t_CFOpts, bool t_bSupportEqualityCompare = t_CFOpts::mc_bSupportEqualityCompare, bool t_bSupportOrderedCompare = t_CFOpts::mc_bSupportOrderedCompare>
	struct TCFunctionDefinitions;

	template <typename t_CFOpts, umint t_iFunction, typename t_CFunctionList = typename t_CFOpts::CFunctionList>
	struct TCGetFunctionCallDefinition;

	template <typename t_CFOpts, umint t_iFunction, typename ...tp_CFunctions>
	struct TCGetFunctionCallDefinition<t_CFOpts, t_iFunction, NMeta::TCTypeList<tp_CFunctions...>>
	{
		using FType = typename TCFunctionCallDefinition<typename TCDetermineFunctionDefinition<tp_CFunctions...[t_iFunction]>::FType>::FType;
	};

	template <umint t_iFunction, typename t_FCall>
	struct TCVTableCall
	{
		t_FCall *m_pCall;
	};

	template <typename t_CIndices, typename ...tp_FCalls>
	struct TCVTableCallsImp;

	template <umint ...tp_Indices, typename ...tp_FCalls>
	struct TCVTableCallsImp<NMeta::TCIndices<tp_Indices...>, tp_FCalls...>
		: TCVTableCall<tp_Indices, tp_FCalls>...
	{
		constexpr TCVTableCallsImp(tp_FCalls * ...p_fCalls)
			: TCVTableCall<tp_Indices, tp_FCalls>{p_fCalls}...
		{
		}

		template <umint tf_iFunction>
		mark_artificial inline_always tp_FCalls...[tf_iFunction] *f_GetFunction() const
		{
			return TCVTableCall<tf_iFunction, tp_FCalls...[tf_iFunction]>::m_pCall;
		}
	};

	template <typename t_CFunctionList>
	struct TCGetVTableCalls;

	template <typename ...tp_CFunctions>
	struct TCGetVTableCalls<NMeta::TCTypeList<tp_CFunctions...>>
	{
		using CType = TCVTableCallsImp
			<
				NMeta::TCConsecutiveIndices<sizeof...(tp_CFunctions)>
				, typename TCFunctionCallDefinition<typename TCDetermineFunctionDefinition<tp_CFunctions>::FType>::FType...
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
			FDelete *m_fDestroy;
			FDuplicate *m_fDuplicate;
			FDuplicateMove *m_fDuplicateMove;
			static constexpr FCompareEqual *m_fCompareEqual = nullptr;         // NOLINT(malterlib-variable-naming): stands in for the m_fCompareEqual member of the other CVTables
			static constexpr FCompareSpaceship *m_fCompareSpaceship = nullptr; // NOLINT(malterlib-variable-naming): stands in for the m_fCompareSpaceship member of the other CVTables
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
			FDelete *m_fDestroy;
			FDuplicate *m_fDuplicate;
			FDuplicateMove *m_fDuplicateMove;
			FCompareEqual *m_fCompareEqual;
			static constexpr FCompareSpaceship *m_fCompareSpaceship = nullptr; // NOLINT(malterlib-variable-naming): stands in for the m_fCompareSpaceship member of the other CVTables
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
			FDelete *m_fDestroy;
			FDuplicate *m_fDuplicate;
			FDuplicateMove *m_fDuplicateMove;
			static constexpr FCompareEqual *m_fCompareEqual = nullptr; // NOLINT(malterlib-variable-naming): stands in for the m_fCompareEqual member of the other CVTables
			FCompareSpaceship *m_fCompareSpaceship;
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
			FDelete *m_fDestroy;
			FDuplicate *m_fDuplicate;
			FDuplicateMove *m_fDuplicateMove;
			FCompareEqual *m_fCompareEqual;
			FCompareSpaceship *m_fCompareSpaceship;
		};
	};
}
