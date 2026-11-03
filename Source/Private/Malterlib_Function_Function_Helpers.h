// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	using FDelete = void (void *_pImpl);
	using FCompareEqual = bool (void const *_pImpl0, void const *_pImp1) noexcept;
	using FCompareSpaceship = COrdering_Partial (void const *_pImpl0, void const *_pImp1) noexcept;

	template <typename t_CParamType>
	struct TCGetReferenceType
	{
		using CType = TCConditional<NTraits::cIsReference<t_CParamType>, t_CParamType, NTraits::TCAddLValueReference<NTraits::TCAddConst<t_CParamType>>>;

		template <typename tf_CType>
		inline_small static CType fs_Forward(tf_CType &&_Type)
		{
			return static_cast<CType>(_Type);
		}
	};

	enum EQualifiers
	{
		EQualifiers_None
		, EQualifiers_Const
	};

	template <typename t_CFunction>
	struct TCDetermineFunctionDefinition
	{
		static constexpr aint mc_Qualifiers = EQualifiers_Const;

		using FType = t_CFunction;
	};

	template <typename t_CReturn, typename ...tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &_ThisTag, tp_CParams ...p_Params)>
	{
		static constexpr aint mc_Qualifiers = EQualifiers_None;

		using FType = t_CReturn (tp_CParams ...p_Params);
	};

	template <typename t_CReturn, typename ...tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &_ThisTag, tp_CParams ...p_Params, ...)>
	{
		static constexpr aint mc_Qualifiers = EQualifiers_None;

		using FType = t_CReturn (tp_CParams ...p_Params, ...);
	};

	template <typename t_CReturn, typename ...tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &_ThisTag, tp_CParams ...p_Params)>
	{
		static constexpr aint mc_Qualifiers = EQualifiers_Const;

		using FType = t_CReturn (tp_CParams ...p_Params);
	};

	template <typename t_CReturn, typename ...tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &_ThisTag, tp_CParams ...p_Params, ...)>
	{
		static constexpr aint mc_Qualifiers = EQualifiers_Const;

		using FType = t_CReturn (tp_CParams ...p_Params, ...);
	};

	template <typename t_CReturn, typename ...tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &_ThisTag, tp_CParams ...p_Params) noexcept>
	{
		static constexpr aint mc_Qualifiers = EQualifiers_None;

		using FType = t_CReturn (tp_CParams ...p_Params) noexcept;
	};

	template <typename t_CReturn, typename ...tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &_ThisTag, tp_CParams ...p_Params, ...) noexcept>
	{
		static constexpr aint mc_Qualifiers = EQualifiers_None;

		using FType = t_CReturn (tp_CParams ...p_Params, ...) noexcept;
	};

	template <typename t_CReturn, typename ...tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &_ThisTag, tp_CParams ...p_Params) noexcept>
	{
		static constexpr aint mc_Qualifiers = EQualifiers_Const;

		using FType = t_CReturn (tp_CParams ...p_Params) noexcept;
	};

	template <typename t_CReturn, typename ...tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &_ThisTag, tp_CParams ...p_Params, ...) noexcept>
	{
		static constexpr aint mc_Qualifiers = EQualifiers_Const;

		using FType = t_CReturn (tp_CParams ...p_Params, ...) noexcept;
	};

	template <typename t_CFirst, int t_FirstQualifiers, typename t_CSecond, int t_SecondQualifiers>
	concept cIsSameFunction = NTraits::cIsSame<t_CFirst, t_CSecond> && t_FirstQualifiers == t_SecondQualifiers;

	template <typename t_CIsFunction, typename ...tp_CParams>
	struct TCParseFunctionOptions;

	template <>
	struct TCParseFunctionOptions<void>
	{
		using CFunctions = NMeta::TCTypeList<>;
		using CAllocator = void;
		using CFunctionAllocOptions = void;

		static constexpr bool mc_bSupportEqualityCompare = false;
		static constexpr bool mc_bSupportOrderedCompare = false;
		static constexpr bool mc_bSupportCopy = true;
		static constexpr bool mc_bSupportMove = true;
		static constexpr aint mc_nExcept = 0;
		static constexpr aint mc_nNoExcept = 0;
	};

	template <typename t_CFirst, typename ...tp_CParams>
	struct TCParseFunctionOptions<TCEnableIf<NTraits::cIsFunction<t_CFirst>>, t_CFirst, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = NMeta::TCTypeList_Concat<NMeta::TCTypeList<t_CFirst>, typename CParent::CFunctions>;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		static constexpr bool mc_bIsNoExcept = NTraits::TCFunctionTraits<t_CFirst>::mc_bIsNoExcept;
		static constexpr bool mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare;
		static constexpr bool mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare;
		static constexpr bool mc_bSupportCopy = CParent::mc_bSupportCopy;
		static constexpr bool mc_bSupportMove = CParent::mc_bSupportMove;
		static constexpr aint mc_nExcept = CParent::mc_nExcept + !mc_bIsNoExcept;
		static constexpr aint mc_nNoExcept = CParent::mc_nNoExcept + mc_bIsNoExcept;
	};

	template <typename t_CFirst, typename ...tp_CParams>
	struct TCParseFunctionOptions<TCEnableIf<NTraits::cIsBaseOf<t_CFirst, NMemory::CAllocator_Base>>, t_CFirst, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = t_CFirst;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		static constexpr bool mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare;
		static constexpr bool mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare;
		static constexpr bool mc_bSupportCopy = CParent::mc_bSupportCopy;
		static constexpr bool mc_bSupportMove = CParent::mc_bSupportMove;
		static constexpr aint mc_nExcept = CParent::mc_nExcept;
		static constexpr aint mc_nNoExcept = CParent::mc_nNoExcept;
	};

	template <bool t_bAllowAlloc, umint t_MaxSize, umint t_Alignment, bool t_bSeparateCallPointer, typename ...tp_CParams>
	struct TCParseFunctionOptions<void, TCFunctionNoAllocOptions<t_bAllowAlloc, t_MaxSize, t_Alignment, t_bSeparateCallPointer>, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = TCFunctionNoAllocOptions<t_bAllowAlloc, t_MaxSize, t_Alignment, t_bSeparateCallPointer>;

		static constexpr bool mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare;
		static constexpr bool mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare;
		static constexpr bool mc_bSupportCopy = CParent::mc_bSupportCopy;
		static constexpr bool mc_bSupportMove = CParent::mc_bSupportMove;
		static constexpr aint mc_nExcept = CParent::mc_nExcept;
		static constexpr aint mc_nNoExcept = CParent::mc_nNoExcept;
	};

	template <typename ...tp_CParams>
	struct TCParseFunctionOptions<void, CFunctionSupportEqualityCompareTag, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		static constexpr bool mc_bSupportEqualityCompare = true;
		static constexpr bool mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare;
		static constexpr bool mc_bSupportCopy = CParent::mc_bSupportCopy;
		static constexpr bool mc_bSupportMove = CParent::mc_bSupportMove;
		static constexpr aint mc_nExcept = CParent::mc_nExcept;
		static constexpr aint mc_nNoExcept = CParent::mc_nNoExcept;
	};

	template <typename ...tp_CParams>
	struct TCParseFunctionOptions<void, CFunctionSupportOrderedCompareTag, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		static constexpr bool mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare;
		static constexpr bool mc_bSupportOrderedCompare = true;
		static constexpr bool mc_bSupportCopy = CParent::mc_bSupportCopy;
		static constexpr bool mc_bSupportMove = CParent::mc_bSupportMove;
		static constexpr aint mc_nExcept = CParent::mc_nExcept;
		static constexpr aint mc_nNoExcept = CParent::mc_nNoExcept;
	};

	template <typename ...tp_CParams>
	struct TCParseFunctionOptions<void, CFunctionNoCopyTag, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		static constexpr bool mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare;
		static constexpr bool mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare;
		static constexpr bool mc_bSupportCopy = false;
		static constexpr bool mc_bSupportMove = CParent::mc_bSupportMove;
		static constexpr aint mc_nExcept = CParent::mc_nExcept;
		static constexpr aint mc_nNoExcept = CParent::mc_nNoExcept;
	};

	template <typename ...tp_CParams>
	struct TCParseFunctionOptions<void, CFunctionNoMoveTag, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		static constexpr bool mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare;
		static constexpr bool mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare;
		static constexpr bool mc_bSupportCopy = CParent::mc_bSupportCopy;
		static constexpr bool mc_bSupportMove = false;
		static constexpr aint mc_nExcept = CParent::mc_nExcept;
		static constexpr aint mc_nNoExcept = CParent::mc_nNoExcept;
	};

	template <typename t_CFunctionList, umint t_iCall>
	struct TCGetCallInfo;

	template <umint t_iCall, typename ...tp_CFunctions>
	struct TCGetCallInfo<NMeta::TCTypeList<tp_CFunctions...>, t_iCall>
	{
		using CFunctionDefinition = TCDetermineFunctionDefinition<tp_CFunctions...[t_iCall]>;
		using FType = typename CFunctionDefinition::FType;

		static constexpr aint mc_Qualifiers = CFunctionDefinition::mc_Qualifiers;
	};

	template <typename t_CFunctionList, umint t_Compare, umint t_Start, umint t_End, bool t_bOutOfBounds = t_Start >= t_End>
	struct TCHasDuplicateFunctionInner
	{
		static constexpr bool mc_Value = cIsSameFunction
			<
				typename TCGetCallInfo<t_CFunctionList, t_Compare>::FType
				, TCGetCallInfo<t_CFunctionList, t_Compare>::mc_Qualifiers
				, typename TCGetCallInfo<t_CFunctionList, t_Start>::FType
				, TCGetCallInfo<t_CFunctionList, t_Start>::mc_Qualifiers
			>
			|| TCHasDuplicateFunctionInner<t_CFunctionList, t_Compare, t_Start + 1, t_End>::mc_Value
		;
	};

	template <typename t_CFunctionList, umint t_Compare, umint t_Start, umint t_End>
	struct TCHasDuplicateFunctionInner<t_CFunctionList, t_Compare, t_Start, t_End, true>
	{
		static constexpr aint mc_Value = false;
	};

	template <typename t_CFunctionList, umint t_Start, umint t_End, bool t_bOutOfBounds = t_Start >= t_End>
	struct TCHasDuplicateFunction
	{
		static constexpr umint mc_Value
			= TCHasDuplicateFunctionInner<t_CFunctionList, t_Start, t_Start + 1, t_End>::mc_Value || TCHasDuplicateFunction<t_CFunctionList, t_Start + 1, t_End>::mc_Value
		;
	};

	template <typename t_CFunctionList, umint t_Start, umint t_End>
	struct TCHasDuplicateFunction<t_CFunctionList, t_Start, t_End, true>
	{
		static constexpr aint mc_Value = false;
	};

	template
	<
		typename t_CDefaultAllocator //  = NMemory::CAllocator_Heap
		, typename t_CDefaultAllocOptions //  = TCFunctionNoAllocOptions<>
		, typename ...tp_COptions
	>
	struct TCFunctionOptionsShared
	{
		using CParsedOptions = TCParseFunctionOptions<void, tp_COptions...>;
		using CFunctionList = typename CParsedOptions::CFunctions;
		// Contracts

		static constexpr aint mc_NumFunctions = NMeta::gc_TypeList_Len<CFunctionList>;

		static_assert(umint(mc_NumFunctions) > 0, "You have to specify at least one function definition");

		using FCall0 = typename TCGetCallInfo<CFunctionList, 0>::FType;

		static constexpr aint mc_Qualifiers0 = TCGetCallInfo<CFunctionList, 0>::mc_Qualifiers;

		// Contracts
		static_assert(!TCHasDuplicateFunction<CFunctionList, 0, mc_NumFunctions>::mc_Value, "Cannot specify the same signature twice");

		static constexpr bool mc_bSupportEqualityCompare = CParsedOptions::mc_bSupportEqualityCompare;
		static constexpr bool mc_bSupportOrderedCompare = CParsedOptions::mc_bSupportOrderedCompare;
		static constexpr bool mc_bSupportCopy = CParsedOptions::mc_bSupportCopy;
		static constexpr bool mc_bSupportMove = CParsedOptions::mc_bSupportMove;
		static constexpr bool mc_bNoExcept = CParsedOptions::mc_nNoExcept != 0;

		static_assert(!!CParsedOptions::mc_nNoExcept != !!CParsedOptions::mc_nExcept, "You cannot mix noexcept(true) and noexcept(false) functions");

		using CAllocator = TCConditional<NTraits::cIsVoid<typename CParsedOptions::CAllocator>, t_CDefaultAllocator, typename CParsedOptions::CAllocator>;
		using CFunctionAllocOptions = TCConditional<NTraits::cIsVoid<typename CParsedOptions::CFunctionAllocOptions>, t_CDefaultAllocOptions, typename CParsedOptions::CFunctionAllocOptions>;
	};
}
