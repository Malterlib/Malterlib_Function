// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
			template <typename t_CLeft, typename t_CRight, bint t_bBothFunction>
			struct TCIsTCFunctionCompareInValid;
			
			typedef void (FDelete)(void *_pImpl);
			typedef bint (FCompareEqual)(void const *_pImpl0, void const *_pImp1);
			typedef bint (FCompareLess)(void const *_pImpl0, void const *_pImp1);

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
					return (CType)_Type;
				}
			};

			enum EQualifiers
			{
				EQualifiers_None,
				EQualifiers_Const,
				EQualifiers_Volatile,
				EQualifiers_ConstVolatile,
			};

#ifdef DCompiler_MSVC
			// This is a workaround for MSVC complier bug

			template 
			<
				typename t_CFunction
				, typename t_CEnable = void
			>
			struct TCDetermineFunctionDefinition
			{
				static_assert(NTraits::TCFunctionTraits<t_CFunction>::mc_Arity <= 10, "Unsupported number of function parameters");

				enum
				{
					mc_Qualifiers = EQualifiers_Const
				};
				typedef t_CFunction CType;
			};


			template <typename t_CReturn, typename t_CThisTag, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (t_CThisTag &, tp_CParams...), typename TCEnableIf<NTraits::TCIsSame<t_CThisTag, CThisTag>::mc_Value, void>::CType>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_None
				};
				typedef t_CReturn (CType)(tp_CParams...);
			};

			template <typename t_CReturn, typename t_CThisTag, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (t_CThisTag &, tp_CParams..., ...), typename TCEnableIf<NTraits::TCIsSame<t_CThisTag, CThisTag>::mc_Value, void>::CType>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_None
				};
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};

			template <typename t_CReturn, typename t_CThisTag, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (t_CThisTag const &, tp_CParams...), typename TCEnableIf<NTraits::TCIsSame<t_CThisTag, CThisTag>::mc_Value, void>::CType>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_Const
				};
				typedef t_CReturn (CType)(tp_CParams...);
			};

			template <typename t_CReturn, typename t_CThisTag, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (t_CThisTag const &, tp_CParams..., ...), typename TCEnableIf<NTraits::TCIsSame<t_CThisTag, CThisTag>::mc_Value, void>::CType>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_Const
				};
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};
			

			template <typename t_CReturn, typename t_CThisTag, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (t_CThisTag volatile &, tp_CParams...), typename TCEnableIf<NTraits::TCIsSame<t_CThisTag, CThisTag>::mc_Value, void>::CType>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_Volatile
				};
				typedef t_CReturn (CType)(tp_CParams...);
			};

			template <typename t_CReturn, typename t_CThisTag, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (t_CThisTag volatile &, tp_CParams..., ...), typename TCEnableIf<NTraits::TCIsSame<t_CThisTag, CThisTag>::mc_Value, void>::CType>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_Volatile
				};
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};
			

			template <typename t_CReturn, typename t_CThisTag, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (t_CThisTag const volatile &, tp_CParams...), typename TCEnableIf<NTraits::TCIsSame<t_CThisTag, CThisTag>::mc_Value, void>::CType>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_ConstVolatile
				};
				typedef t_CReturn (CType)(tp_CParams...);
			};

			template <typename t_CReturn, typename t_CThisTag, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (t_CThisTag const volatile &, tp_CParams..., ...), typename TCEnableIf<NTraits::TCIsSame<t_CThisTag, CThisTag>::mc_Value, void>::CType>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_ConstVolatile
				};
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};
#else
			
			template 
			<
				typename t_CFunction
			>
			struct TCDetermineFunctionDefinition
			{
				static_assert(NTraits::TCFunctionTraits<t_CFunction>::mc_Arity <= 10, "Unsupported number of function parameters");

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
			struct TCDetermineFunctionDefinition<t_CReturn (CThisTag volatile &, tp_CParams...)>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_Volatile
				};
				typedef t_CReturn (CType)(tp_CParams...);
			};

			template <typename t_CReturn, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (CThisTag volatile &, tp_CParams..., ...)>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_Volatile
				};
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};
			

			template <typename t_CReturn, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const volatile &, tp_CParams...)>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_ConstVolatile
				};
				typedef t_CReturn (CType)(tp_CParams...);
			};

			template <typename t_CReturn, typename... tp_CParams>
			struct TCDetermineFunctionDefinition<t_CReturn (CThisTag const volatile &, tp_CParams..., ...)>
			{
				enum
				{
					mc_Qualifiers = EQualifiers_ConstVolatile
				};
				typedef t_CReturn (CType)(tp_CParams..., ...);
			};

#endif
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
					mc_bSupportCompare = false
					, mc_bSupportCopy = true
					, mc_bSupportMove = true
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
					mc_bSupportCompare = CParent::mc_bSupportCompare
					, mc_bSupportCopy = CParent::mc_bSupportCopy
					, mc_bSupportMove = CParent::mc_bSupportMove
				};
			};

			template <typename t_CFirst, typename... tp_CParams>
			struct TCParseFunctionOptions<typename TCEnableIf<NTraits::TCIsBaseOf<t_CFirst, NMem::CAllocator_Base>::mc_Value>::CType, t_CFirst, tp_CParams...>
			{
				typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
				typedef typename CParent::CFunctions CFunctions;
				typedef t_CFirst CAllocator;
				typedef typename CParent::CFunctionAllocOptions CFunctionAllocOptions;
				enum
				{
					mc_bSupportCompare = CParent::mc_bSupportCompare
					, mc_bSupportCopy = CParent::mc_bSupportCopy
					, mc_bSupportMove = CParent::mc_bSupportMove
				};
			};

			template <bint t_bAllowAlloc, mint t_MaxSize, mint t_Alignment, typename... tp_CParams>
			struct TCParseFunctionOptions<void, TCFunctionNoAllocOptions<t_bAllowAlloc, t_MaxSize, t_Alignment>, tp_CParams...>
			{
				typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
				typedef typename CParent::CFunctions CFunctions;
				typedef typename CParent::CAllocator CAllocator;
				typedef TCFunctionNoAllocOptions<t_bAllowAlloc, t_MaxSize, t_Alignment> CFunctionAllocOptions;
				enum
				{
					mc_bSupportCompare = CParent::mc_bSupportCompare
					, mc_bSupportCopy = CParent::mc_bSupportCopy
					, mc_bSupportMove = CParent::mc_bSupportMove
				};
			};
			
			template <typename... tp_CParams>
			struct TCParseFunctionOptions<void, CFunctionSupportCompareTag, tp_CParams...>
			{
				typedef TCParseFunctionOptions<void, tp_CParams...> CParent;
				typedef typename CParent::CFunctions CFunctions;
				typedef typename CParent::CAllocator CAllocator;
				typedef typename CParent::CFunctionAllocOptions CFunctionAllocOptions;
				enum
				{
					mc_bSupportCompare = true
					, mc_bSupportCopy = CParent::mc_bSupportCopy
					, mc_bSupportMove = CParent::mc_bSupportMove
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
					mc_bSupportCompare = CParent::mc_bSupportCompare
					, mc_bSupportCopy = false
					, mc_bSupportMove = CParent::mc_bSupportMove
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
					mc_bSupportCompare = CParent::mc_bSupportCompare
					, mc_bSupportCopy = CParent::mc_bSupportCopy
					, mc_bSupportMove = false
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
				template <typename t_CFOpts> class t_TImpBase
				, typename t_CDefaultAllocator //  = NMem::CAllocator_Heap
				, typename t_CDefaultAllocOptions //  = TCFunctionNoAllocOptions<>
				, typename... tp_COptions
			>
			struct TCFunctionOptions
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
					mc_bSupportCompare = CParsedOptions::mc_bSupportCompare
					, mc_bSupportCopy = CParsedOptions::mc_bSupportCopy
					, mc_bSupportMove = CParsedOptions::mc_bSupportMove
				};
				
				typedef typename TCChooseType<NTraits::TCIsVoid<typename CParsedOptions::CAllocator>::mc_Value, t_CDefaultAllocator, typename CParsedOptions::CAllocator>::CType CAllocator;
				typedef typename TCChooseType
				<
					NTraits::TCIsVoid<typename CParsedOptions::CFunctionAllocOptions>::mc_Value, t_CDefaultAllocOptions, typename CParsedOptions::CFunctionAllocOptions
				>::CType CFunctionAllocOptions;

				typedef t_TImpBase<TCFunctionOptions> CImpBase;
			};
		}
	}
}

