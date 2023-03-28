// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NFunction::NPrivate
{
	typedef void (FDelete)(void *_pImpl);
	typedef bool (FCompareEqual)(void const *_pImpl0, void const *_pImp1);
	typedef COrdering_Partial (FCompareSpaceship)(void const *_pImpl0, void const *_pImp1);

	template <typename t_CParamType>
	struct TCGetReferenceType
	{
		typedef typename TCChooseType
			<
				NTraits::TCIsReference<t_CParamType>::mc_Value
				, t_CParamType
				, typename NTraits::TCAddLValueReference
				<
					typename NTraits::TCAddConst
					<
						t_CParamType
					>::CType
				>::CType
			>::CType CType;

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
		typedef t_CFunction CType;
	};


	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &, tp_CParams...)>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_None
		};
		typedef t_CReturn (CType)(tp_CParams...);
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &, tp_CParams..., ...)>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_None
		};
		typedef t_CReturn (CType)(tp_CParams..., ...);
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &, tp_CParams...)>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		typedef t_CReturn (CType)(tp_CParams...);
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &, tp_CParams..., ...)>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		typedef t_CReturn (CType)(tp_CParams..., ...);
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &, tp_CParams...) noexcept>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_None
		};
		typedef t_CReturn (CType)(tp_CParams...) noexcept;
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag &, tp_CParams..., ...) noexcept>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_None
		};
		typedef t_CReturn (CType)(tp_CParams..., ...) noexcept;
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &, tp_CParams...) noexcept>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		typedef t_CReturn (CType)(tp_CParams...) noexcept;
	};

	template <typename t_CReturn, typename... tp_CParams>
	struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const &, tp_CParams..., ...) noexcept>
	{
		enum
		{
			mc_Qualifiers = EQualifiers_Const
		};
		typedef t_CReturn (CType)(tp_CParams..., ...) noexcept;
	};


	template <typename t_CFirst, int _FirstQualifiers, typename t_CSecond, int _SecondQualifiers>
	struct TCIsSameFunction
	{
		enum
		{
			mc_Value = NTraits::TCIsSame<t_CFirst, t_CSecond>::mc_Value && _FirstQualifiers == _SecondQualifiers
		};
	};

	template <typename t_CIsFunction, typename... tp_CParams>
	struct TCParseFunctionOptions;

	template <>
	struct TCParseFunctionOptions<void>
	{
		typedef NMeta::TCTypeList<> CFunctions;
		typedef void CAllocator;
		typedef void CFunctionAllocOptions;
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
	struct TCParseFunctionOptions<typename TCEnableIf<NTraits::TCIsFunction<t_CFirst>::mc_Value>::CType, t_CFirst, tp_CParams...>
	{
		typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
		typedef typename NMeta::TCTypeList_Concat<NMeta::TCTypeList<t_CFirst>, typename CParent::CFunctions>::CType CFunctions;
		typedef typename CParent::CAllocator CAllocator;
		typedef typename CParent::CFunctionAllocOptions CFunctionAllocOptions;

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
	struct TCParseFunctionOptions<typename TCEnableIf<NTraits::TCIsBaseOf<t_CFirst, NMemory::CAllocator_Base>::mc_Value>::CType, t_CFirst, tp_CParams...>
	{
		typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
		typedef typename CParent::CFunctions CFunctions;
		typedef t_CFirst CAllocator;
		typedef typename CParent::CFunctionAllocOptions CFunctionAllocOptions;
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

	template <bool t_bAllowAlloc, mint t_MaxSize, mint t_Alignment, bool t_bSeparateCallPointer, typename... tp_CParams>
	struct TCParseFunctionOptions<void, TCFunctionNoAllocOptions<t_bAllowAlloc, t_MaxSize, t_Alignment, t_bSeparateCallPointer>, tp_CParams...>
	{
		typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
		typedef typename CParent::CFunctions CFunctions;
		typedef typename CParent::CAllocator CAllocator;
		typedef TCFunctionNoAllocOptions<t_bAllowAlloc, t_MaxSize, t_Alignment, t_bSeparateCallPointer> CFunctionAllocOptions;
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
		typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
		typedef typename CParent::CFunctions CFunctions;
		typedef typename CParent::CAllocator CAllocator;
		typedef typename CParent::CFunctionAllocOptions CFunctionAllocOptions;
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
		typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
		typedef typename CParent::CFunctions CFunctions;
		typedef typename CParent::CAllocator CAllocator;
		typedef typename CParent::CFunctionAllocOptions CFunctionAllocOptions;
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
		typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
		typedef typename CParent::CFunctions CFunctions;
		typedef typename CParent::CAllocator CAllocator;
		typedef typename CParent::CFunctionAllocOptions CFunctionAllocOptions;
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
		typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
		typedef typename CParent::CFunctions CFunctions;
		typedef typename CParent::CAllocator CAllocator;
		typedef typename CParent::CFunctionAllocOptions CFunctionAllocOptions;
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

	template <typename t_CFunctionList, mint t_iCall>
	struct TCGetCallInfo
	{
		typedef TCDetermineFunctionDefinition<typename NMeta::TCTypeList_Get<t_iCall, t_CFunctionList>::CType> CFunctionDefinition;
		typedef typename CFunctionDefinition::CType CType;
		enum
		{
			mc_Qualifiers = CFunctionDefinition::mc_Qualifiers
		};
	};

	template <typename t_CFunctionList, mint t_Compare, mint t_Start, mint t_End, bool t_bOutOfBounds = t_Start >= t_End>
	struct TCHasDuplicateFunctionInner
	{
		enum
		{
			mc_Value = TCIsSameFunction
				<
					typename TCGetCallInfo<t_CFunctionList, t_Compare>::CType
					, TCGetCallInfo<t_CFunctionList, t_Compare>::mc_Qualifiers
					, typename TCGetCallInfo<t_CFunctionList, t_Start>::CType
					, TCGetCallInfo<t_CFunctionList, t_Start>::mc_Qualifiers
				>::mc_Value
			|| TCHasDuplicateFunctionInner<t_CFunctionList, t_Compare, t_Start + 1, t_End>::mc_Value
		};
	};

	template <typename t_CFunctionList, mint t_Compare, mint t_Start, mint t_End>
	struct TCHasDuplicateFunctionInner<t_CFunctionList, t_Compare, t_Start, t_End, true>
	{
		enum
		{
			mc_Value = false
		};
	};

	template <typename t_CFunctionList, mint t_Start, mint t_End, bool t_bOutOfBounds = t_Start >= t_End>
	struct TCHasDuplicateFunction
	{
		enum
		{
			mc_Value = TCHasDuplicateFunctionInner<t_CFunctionList, t_Start, t_Start + 1, t_End>::mc_Value
			|| TCHasDuplicateFunction<t_CFunctionList, t_Start + 1, t_End>::mc_Value
		};
	};

	template <typename t_CFunctionList, mint t_Start, mint t_End>
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
		//typedef NMeta::TCTypeList<tp_COptions...> COptionList;
		typedef TCParseFunctionOptions<void, tp_COptions...> CParsedOptions;
		typedef typename CParsedOptions::CFunctions CFunctionList;
		// Contracts

		enum
		{
			mc_NumFunctions = NMeta::TCTypeList_Len<CFunctionList>::mc_Value
		};

		static_assert(mint(mc_NumFunctions) > 0, "You have to specify at least one function definition");

		typedef typename TCGetCallInfo<CFunctionList, 0>::CType CCall0;

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

		typedef typename TCChooseType<NTraits::TCIsVoid<typename CParsedOptions::CAllocator>::mc_Value, t_CDefaultAllocator, typename CParsedOptions::CAllocator>::CType CAllocator;
		typedef typename TCChooseType
		<
			NTraits::TCIsVoid<typename CParsedOptions::CFunctionAllocOptions>::mc_Value, t_CDefaultAllocOptions, typename CParsedOptions::CFunctionAllocOptions
		>::CType CFunctionAllocOptions;
	};
}
