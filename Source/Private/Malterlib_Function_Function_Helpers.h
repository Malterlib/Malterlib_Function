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
		using CType = TCConditional
			<
				NTraits::cIsReference<t_CParamType>
				, t_CParamType
				, NTraits::TCAddLValueReference<NTraits::TCAddConst<t_CParamType>>
			>
		;

		template <typename tf_CType>
		inline_small static CType fs_Forward(tf_CType &&_Type)
		{
			return static_cast<CType>(_Type);
		}
	};

	enum EQualifiers
	{
		EQualifiers_None,
		EQualifiers_Const,
	};

	template
	<
		typename t_CFunction
	>
	struct TCDetermineFunctionDefinition
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		using CType = t_CFunction;
	};


	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &, tp_CParams...)>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_None
		};
		using CType = t_CReturn (tp_CParams...);
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &, tp_CParams..., ...)>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_None
		};
		using CType = t_CReturn (tp_CParams..., ...);
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &, tp_CParams...)>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		using CType = t_CReturn (tp_CParams...);
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &, tp_CParams..., ...)>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		using CType = t_CReturn (tp_CParams..., ...);
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &, tp_CParams...) noexcept>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_None
		};
		using CType = t_CReturn (tp_CParams...) noexcept;
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &, tp_CParams..., ...) noexcept>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_None
		};
		using CType = t_CReturn (tp_CParams..., ...) noexcept;
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &, tp_CParams...) noexcept>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		using CType = t_CReturn (tp_CParams...) noexcept;
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &, tp_CParams..., ...) noexcept>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		using CType = t_CReturn (tp_CParams..., ...) noexcept;
	};


	template <typename t_CFirst, int _FirstQualifiers, typename t_CSecond, int _SecondQualifiers>
	concept cIsSameFunction = NTraits::cIsSame<t_CFirst, t_CSecond> && _FirstQualifiers == _SecondQualifiers;

	template <typename t_CIsFunction, typename... tp_CParams>
	struct TCParseFunctionOptions;

	template <>
	struct TCParseFunctionOptions<void>
	{
		using CFunctions = NMeta::TCTypeList<>;
		using CAllocator = void;
		using CFunctionAllocOptions = void;

		enum
		{
			mc_bSupportEqualityCompare = false
			, mc_bSupportOrderedCompare = false
			, mc_bSupportCopy = true
			, mc_bSupportMove = true
			, mc_nExcept = 0
			, mc_nNoExcept = 0
		};
	};

	template <typename t_CFirst, typename... tp_CParams>
	struct TCParseFunctionOptions<TCEnableIf<NTraits::cIsFunction<t_CFirst>>, t_CFirst, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = NMeta::TCTypeList_Concat<NMeta::TCTypeList<t_CFirst>, typename CParent::CFunctions>;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		enum
		{
			mc_bIsNoExcept = NTraits::TCFunctionTraits<t_CFirst>::mc_IsNoExcept

			, mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare
			, mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare
			, mc_bSupportCopy = CParent::mc_bSupportCopy
			, mc_bSupportMove = CParent::mc_bSupportMove
			, mc_nExcept = CParent::mc_nExcept + !mc_bIsNoExcept
			, mc_nNoExcept = CParent::mc_nNoExcept + mc_bIsNoExcept
		};
	};

	template <typename t_CFirst, typename... tp_CParams>
	struct TCParseFunctionOptions<TCEnableIf<NTraits::cIsBaseOf<t_CFirst, NMemory::CAllocator_Base>>, t_CFirst, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = t_CFirst;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		enum
		{
			mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare
			, mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare
			, mc_bSupportCopy = CParent::mc_bSupportCopy
			, mc_bSupportMove = CParent::mc_bSupportMove
			, mc_nExcept = CParent::mc_nExcept
			, mc_nNoExcept = CParent::mc_nNoExcept
		};
	};

	template <bool t_bAllowAlloc, umint t_MaxSize, umint t_Alignment, bool t_bSeparateCallPointer, typename... tp_CParams>
	struct TCParseFunctionOptions<void, TCFunctionNoAllocOptions<t_bAllowAlloc, t_MaxSize, t_Alignment, t_bSeparateCallPointer>, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = TCFunctionNoAllocOptions<t_bAllowAlloc, t_MaxSize, t_Alignment, t_bSeparateCallPointer>;

		enum
		{
			mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare
			, mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare
			, mc_bSupportCopy = CParent::mc_bSupportCopy
			, mc_bSupportMove = CParent::mc_bSupportMove
			, mc_nExcept = CParent::mc_nExcept
			, mc_nNoExcept = CParent::mc_nNoExcept
		};
	};

	template <typename... tp_CParams>
	struct TCParseFunctionOptions<void, CFunctionSupportEqualityCompareTag, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		enum
		{
			mc_bSupportEqualityCompare = true
			, mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare
			, mc_bSupportCopy = CParent::mc_bSupportCopy
			, mc_bSupportMove = CParent::mc_bSupportMove
			, mc_nExcept = CParent::mc_nExcept
			, mc_nNoExcept = CParent::mc_nNoExcept
		};
	};

	template <typename... tp_CParams>
	struct TCParseFunctionOptions<void, CFunctionSupportOrderedCompareTag, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		enum
		{
			mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare
			, mc_bSupportOrderedCompare = true
			, mc_bSupportCopy = CParent::mc_bSupportCopy
			, mc_bSupportMove = CParent::mc_bSupportMove
			, mc_nExcept = CParent::mc_nExcept
			, mc_nNoExcept = CParent::mc_nNoExcept
		};
	};

	template <typename... tp_CParams>
	struct TCParseFunctionOptions<void, CFunctionNoCopyTag, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		enum
		{
			mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare
			, mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare
			, mc_bSupportCopy = false
			, mc_bSupportMove = CParent::mc_bSupportMove
			, mc_nExcept = CParent::mc_nExcept
			, mc_nNoExcept = CParent::mc_nNoExcept
		};
	};

	template <typename... tp_CParams>
	struct TCParseFunctionOptions<void, CFunctionNoMoveTag, tp_CParams...>
	{
		using CParent = TCParseFunctionOptions<void, tp_CParams...>;
		using CFunctions = typename CParent::CFunctions;
		using CAllocator = typename CParent::CAllocator;
		using CFunctionAllocOptions = typename CParent::CFunctionAllocOptions;

		enum
		{
			mc_bSupportEqualityCompare = CParent::mc_bSupportEqualityCompare
			, mc_bSupportOrderedCompare = CParent::mc_bSupportOrderedCompare
			, mc_bSupportCopy = CParent::mc_bSupportCopy
			, mc_bSupportMove = false
			, mc_nExcept = CParent::mc_nExcept
			, mc_nNoExcept = CParent::mc_nNoExcept
		};
	};

	template <typename t_CFunctionList, umint t_iCall>
	struct TCGetCallInfo;

	template <umint t_iCall, typename... tp_CFunctions>
	struct TCGetCallInfo<NMeta::TCTypeList<tp_CFunctions...>, t_iCall>
	{
		using CFunctionDefinition = TCDetermineFunctionDefinition<tp_CFunctions...[t_iCall]>;
		using CType = typename CFunctionDefinition::CType;

		enum
		{
			mc_Qualifiers = CFunctionDefinition::mc_Qualifiers
		};
	};

	template <typename t_CFunctionList, umint t_Compare, umint t_Start, umint t_End, bool t_bOutOfBounds = t_Start >= t_End>
	struct TCHasDuplicateFunctionInner
	{
		enum
		{
			mc_Value = cIsSameFunction
				<
					typename TCGetCallInfo<t_CFunctionList, t_Compare>::CType
					, TCGetCallInfo<t_CFunctionList, t_Compare>::mc_Qualifiers
					, typename TCGetCallInfo<t_CFunctionList, t_Start>::CType
					, TCGetCallInfo<t_CFunctionList, t_Start>::mc_Qualifiers
				>
				|| TCHasDuplicateFunctionInner<t_CFunctionList, t_Compare, t_Start + 1, t_End>::mc_Value
		};
	};

	template <typename t_CFunctionList, umint t_Compare, umint t_Start, umint t_End>
	struct TCHasDuplicateFunctionInner<t_CFunctionList, t_Compare, t_Start, t_End, true>
	{
		enum
		{
			mc_Value = false
		};
	};

	template <typename t_CFunctionList, umint t_Start, umint t_End, bool t_bOutOfBounds = t_Start >= t_End>
	struct TCHasDuplicateFunction
	{
		enum
		{
			mc_Value = TCHasDuplicateFunctionInner<t_CFunctionList, t_Start, t_Start + 1, t_End>::mc_Value
			|| TCHasDuplicateFunction<t_CFunctionList, t_Start + 1, t_End>::mc_Value
		};
	};

	template <typename t_CFunctionList, umint t_Start, umint t_End>
	struct TCHasDuplicateFunction<t_CFunctionList, t_Start, t_End, true>
	{
		enum
		{
			mc_Value = false
		};
	};

	template
	<
		typename t_CDefaultAllocator //  = NMemory::CAllocator_Heap
		, typename t_CDefaultAllocOptions //  = TCFunctionNoAllocOptions<>
		, typename... tp_COptions
	>
	struct TCFunctionOptionsShared
	{
		using CParsedOptions = TCParseFunctionOptions<void, tp_COptions...>;
		using CFunctionList = typename CParsedOptions::CFunctions;
		// Contracts

		enum
		{
			mc_NumFunctions = NMeta::gc_TypeList_Len<CFunctionList>
		};

		static_assert(umint(mc_NumFunctions) > 0, "You have to specify at least one function definition");

		using CCall0 = typename TCGetCallInfo<CFunctionList, 0>::CType;

		enum
		{
			mc_Qualifiers0 = TCGetCallInfo<CFunctionList, 0>::mc_Qualifiers
		};

		// Contracts
		static_assert(!TCHasDuplicateFunction<CFunctionList, 0, mc_NumFunctions>::mc_Value, "Cannot specify the same signature twice");

		enum
		{
			mc_bSupportEqualityCompare = CParsedOptions::mc_bSupportEqualityCompare
			, mc_bSupportOrderedCompare = CParsedOptions::mc_bSupportOrderedCompare
			, mc_bSupportCopy = CParsedOptions::mc_bSupportCopy
			, mc_bSupportMove = CParsedOptions::mc_bSupportMove
			, mc_bNoExcept = CParsedOptions::mc_nNoExcept != 0
		};

		static_assert(!!CParsedOptions::mc_nNoExcept != !!CParsedOptions::mc_nExcept, "You cannot mix noexcept(true) and noexcept(false) functions");

		using CAllocator = TCConditional<NTraits::cIsVoid<typename CParsedOptions::CAllocator>, t_CDefaultAllocator, typename CParsedOptions::CAllocator> ;
		using CFunctionAllocOptions = TCConditional<NTraits::cIsVoid<typename CParsedOptions::CFunctionAllocOptions>, t_CDefaultAllocOptions, typename CParsedOptions::CFunctionAllocOptions>;
	};
}
