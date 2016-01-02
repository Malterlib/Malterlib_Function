// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
			
			/***************************************************************************************************\
			 |¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			 | Nil type for unused parameters																	|
			 |___________________________________________________________________________________________________|
			 \***************************************************************************************************/
			struct CNil
			{
			};
		}
			
		namespace NBindExpression
		{
			typedef NFunction::NPrivate::CNil CNil;
			template 
			<
				typename t_CToBind
				, typename t_CP0
				, typename t_CP1
				, typename t_CP2
				, typename t_CP3
				, typename t_CP4
				, typename t_CP5
				, typename t_CP6
				, typename t_CP7
				, typename t_CP8
	#ifndef DMibRestrictNumberOfBindParams
				, typename t_CP9
				, typename t_CP10
				, typename t_CP11
				, typename t_CP12
				, typename t_CP13
	#endif
			>
			class TCBindExpression ;
		}

		namespace NPrivate
		{
			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Forward extra traits																				|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <typename t_CType>
			struct TCIsBindForwardExtra
			{
				static const bint mc_Value = false;
				static const mint mc_Level = 0xFFFFFFFF;
			};

			template <mint t_Level>
			struct TCIsBindForwardExtra<TCBindForwardExtraTag<t_Level>>
			{
				static const bint mc_Value = true;
				static const mint mc_Level = t_Level;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Placeholder traits																				|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <typename t_CType>
			struct TCIsBindPlaceholder
			{
				static const bint mc_Value = false;
				static const mint mc_Param = 0;
				static const mint mc_Level = 0xFFFFFFFF;
			};

			template <mint t_Param, mint t_Level>
			struct TCIsBindPlaceholder<TCBindPlaceholder<t_Param, t_Level>>
			{
				static const bint mc_Value = true;
				static const mint mc_Param = t_Param;
				static const mint mc_Level = t_Level;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Bind param traits																					|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/


			template <typename t_C0>
			struct TCIsBindParam
			{
				static const bint mc_Value = true;
			};

			template <>
			struct TCIsBindParam<void>
			{
				static const bint mc_Value = false;
			};

			template <>
			struct TCIsBindParam<CBindSupportCompareTag>
			{
				static const bint mc_Value = false;
			};

			template <mint t_Level>
			struct TCIsBindParam<TCBindForwardExtraTag<t_Level>>
			{
				static const bint mc_Value = false;
			};

			template
			<
				int32 t_iParam0
				, int32 t_iParam1
				, int32 t_iParam2
				, int32 t_iParam3
				, int32 t_iParam4
#ifndef DMibRestrictNumberOfBindParams
				, int32 t_iParam5
				, int32 t_iParam6
				, int32 t_iParam7
				, int32 t_iParam8
				, int32 t_iParam9
#endif
			>
			struct TCIsBindParam
			<
				TCBindIgnoreParamsTag
				<
					t_iParam0
					, t_iParam1
					, t_iParam2
					, t_iParam3
					, t_iParam4
#ifndef DMibRestrictNumberOfBindParams
					, t_iParam5
					, t_iParam6
					, t_iParam7
					, t_iParam8
					, t_iParam9
#endif
				>
			>
			{
				static const bint mc_Value = false;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Ignore tag traits																					|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <typename t_C0>
			struct TCIsIgnoreParamsTag
			{
				static const bint mc_Value = false;
				static const uint32 mc_IgnoredImplicit = 0;
				static const uint32 mc_IgnoredExplicit = 0;
			};

			template
			<
				int32 t_iParam0
				, int32 t_iParam1
				, int32 t_iParam2
				, int32 t_iParam3
				, int32 t_iParam4
#ifndef DMibRestrictNumberOfBindParams
				, int32 t_iParam5
				, int32 t_iParam6
				, int32 t_iParam7
				, int32 t_iParam8
				, int32 t_iParam9
#endif
			>
			struct TCIsIgnoreParamsTag
			<
				TCBindIgnoreParamsTag
				<
					t_iParam0
					, t_iParam1
					, t_iParam2
					, t_iParam3
					, t_iParam4
#ifndef DMibRestrictNumberOfBindParams
					, t_iParam5
					, t_iParam6
					, t_iParam7
					, t_iParam8
					, t_iParam9
#endif
					>
				>
			{
				static const bint mc_Value = false;
				static const uint32 mc_IgnoredExplicit
					= (t_iParam0 == -1 ? uint32(0) : DMibBitTyped((t_iParam0 == -1 ? 0 : t_iParam0), uint32))
					| (t_iParam1 == -1 ? uint32(0) : DMibBitTyped((t_iParam1 == -1 ? 0 : t_iParam1), uint32))
					| (t_iParam2 == -1 ? uint32(0) : DMibBitTyped((t_iParam2 == -1 ? 0 : t_iParam2), uint32))
					| (t_iParam3 == -1 ? uint32(0) : DMibBitTyped((t_iParam3 == -1 ? 0 : t_iParam3), uint32))
					| (t_iParam4 == -1 ? uint32(0) : DMibBitTyped((t_iParam4 == -1 ? 0 : t_iParam4), uint32))
#ifndef DMibRestrictNumberOfBindParams
					| (t_iParam5 == -1 ? uint32(0) : DMibBitTyped((t_iParam5 == -1 ? 0 : t_iParam5), uint32))
					| (t_iParam6 == -1 ? uint32(0) : DMibBitTyped((t_iParam6 == -1 ? 0 : t_iParam6), uint32))
					| (t_iParam7 == -1 ? uint32(0) : DMibBitTyped((t_iParam7 == -1 ? 0 : t_iParam7), uint32))
					| (t_iParam8 == -1 ? uint32(0) : DMibBitTyped((t_iParam8 == -1 ? 0 : t_iParam8), uint32))
					| (t_iParam9 == -1 ? uint32(0) : DMibBitTyped((t_iParam9 == -1 ? 0 : t_iParam9), uint32))
#endif
				;
				static const uint32 mc_IgnoredImplicit = t_iParam0 == -1 ? uint32(0xffffffffu) : 0;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Bind expression traits																			|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <typename t_CType, typename t_CStrippedType = typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CType>::CType>::CType>
			struct TCIsBindExpression
			{
				static const bint mc_Value = false;
				static const bint mc_bEnableNesting = false;
				static const bint mc_bComparable = false;
			};

			template 
			<
				typename t_CType
				, typename t_CToBind
				, typename t_CP0
				, typename t_CP1
				, typename t_CP2
				, typename t_CP3
				, typename t_CP4
				, typename t_CP5
				, typename t_CP6
				, typename t_CP7
				, typename t_CP8
#ifndef DMibRestrictNumberOfBindParams
				, typename t_CP9
				, typename t_CP10
				, typename t_CP11
				, typename t_CP12
				, typename t_CP13
#endif
			>
			struct TCIsBindExpression
			<
				t_CType
				, NBindExpression::TCBindExpression
				<
					t_CToBind
					, t_CP0
					, t_CP1
					, t_CP2
					, t_CP3
					, t_CP4
					, t_CP5
					, t_CP6
					, t_CP7
					, t_CP8
#ifndef DMibRestrictNumberOfBindParams
					, t_CP9
					, t_CP10
					, t_CP11
					, t_CP12
					, t_CP13
#endif
				>
			>
			{
				typedef typename NBindExpression::TCBindExpression
				<
					t_CToBind
					, t_CP0
					, t_CP1
					, t_CP2
					, t_CP3
					, t_CP4
					, t_CP5
					, t_CP6
					, t_CP7
					, t_CP8
#ifndef DMibRestrictNumberOfBindParams
					, t_CP9
					, t_CP10
					, t_CP11
					, t_CP12
					, t_CP13
#endif
				>::CBindOptions CBindOptions;

				static const bint mc_Value = true;
				static const bint mc_bEnableNesting = CBindOptions::mc_bEnableNesting;
				static const bint mc_bComparable = CBindOptions::mc_bSupportCompare;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Make function																						|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template 
			<
				mint t_nPar
				, typename t_C0
				, typename t_C1
				, typename t_C2
				, typename t_C3
				, typename t_C4
#ifndef DMibRestrictNumberOfBindParams
				, typename t_C5
				, typename t_C6
				, typename t_C7
				, typename t_C8
				, typename t_C9
#endif
			>
			struct TCMakeFunctionType
			{
				typedef void CType();
			};

			template 
			<
				typename t_C0
				, typename t_C1
				, typename t_C2
				, typename t_C3
				, typename t_C4
#ifndef DMibRestrictNumberOfBindParams
				, typename t_C5
				, typename t_C6
				, typename t_C7
				, typename t_C8
				, typename t_C9
#endif
			>
			struct TCMakeFunctionType
			<
				1
				, t_C0
				, t_C1
				, t_C2
				, t_C3
				, t_C4
#ifndef DMibRestrictNumberOfBindParams
				, t_C5
				, t_C6
				, t_C7
				, t_C8
				, t_C9
#endif
			>
			{
				typedef void CType(t_C0 _P0);
			};

			template 
			<
				typename t_C0
				, typename t_C1
				, typename t_C2
				, typename t_C3
				, typename t_C4
#ifndef DMibRestrictNumberOfBindParams
				, typename t_C5
				, typename t_C6
				, typename t_C7
				, typename t_C8
				, typename t_C9
#endif
			>
			struct TCMakeFunctionType
			<
				2
				, t_C0
				, t_C1
				, t_C2
				, t_C3
				, t_C4
#ifndef DMibRestrictNumberOfBindParams
				, t_C5
				, t_C6
				, t_C7
				, t_C8
				, t_C9
#endif
			>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1);
			};

			template 
			<
				typename t_C0
				, typename t_C1
				, typename t_C2
				, typename t_C3
				, typename t_C4
#ifndef DMibRestrictNumberOfBindParams
				, typename t_C5
				, typename t_C6
				, typename t_C7
				, typename t_C8
				, typename t_C9
#endif
			>
			struct TCMakeFunctionType
			<
				3
				, t_C0
				, t_C1
				, t_C2
				, t_C3
				, t_C4
#ifndef DMibRestrictNumberOfBindParams
				, t_C5
				, t_C6
				, t_C7
				, t_C8
				, t_C9
#endif
			>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1, t_C2 _P2);
			};

			template 
			<
				typename t_C0
				, typename t_C1
				, typename t_C2
				, typename t_C3
				, typename t_C4
#ifndef DMibRestrictNumberOfBindParams
				, typename t_C5
				, typename t_C6
				, typename t_C7
				, typename t_C8
				, typename t_C9
#endif
			>
			struct TCMakeFunctionType
			<
				4
				, t_C0
				, t_C1
				, t_C2
				, t_C3
				, t_C4
#ifndef DMibRestrictNumberOfBindParams
				, t_C5
				, t_C6
				, t_C7
				, t_C8
				, t_C9
#endif
			>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1, t_C2 _P2, t_C3 _P3);
			};

#ifndef DMibRestrictNumberOfBindParams
			template <typename t_C0, typename t_C1, typename t_C2, typename t_C3, typename t_C4, typename t_C5, typename t_C6, typename t_C7, typename t_C8, typename t_C9>
			struct TCMakeFunctionType<5, t_C0, t_C1, t_C2, t_C3, t_C4, t_C5, t_C6, t_C7, t_C8, t_C9>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1, t_C2 _P2, t_C3 _P3, t_C4 _P4);
			};

			template <typename t_C0, typename t_C1, typename t_C2, typename t_C3, typename t_C4, typename t_C5, typename t_C6, typename t_C7, typename t_C8, typename t_C9>
			struct TCMakeFunctionType<6, t_C0, t_C1, t_C2, t_C3, t_C4, t_C5, t_C6, t_C7, t_C8, t_C9>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1, t_C2 _P2, t_C3 _P3, t_C4 _P4, t_C5 _P5);
			};

			template <typename t_C0, typename t_C1, typename t_C2, typename t_C3, typename t_C4, typename t_C5, typename t_C6, typename t_C7, typename t_C8, typename t_C9>
			struct TCMakeFunctionType<7, t_C0, t_C1, t_C2, t_C3, t_C4, t_C5, t_C6, t_C7, t_C8, t_C9>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1, t_C2 _P2, t_C3 _P3, t_C4 _P4, t_C5 _P5, t_C6 _P6);
			};

			template <typename t_C0, typename t_C1, typename t_C2, typename t_C3, typename t_C4, typename t_C5, typename t_C6, typename t_C7, typename t_C8, typename t_C9>
			struct TCMakeFunctionType<8, t_C0, t_C1, t_C2, t_C3, t_C4, t_C5, t_C6, t_C7, t_C8, t_C9>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1, t_C2 _P2, t_C3 _P3, t_C4 _P4, t_C5 _P5, t_C6 _P6, t_C7 _P7);
			};

			template <typename t_C0, typename t_C1, typename t_C2, typename t_C3, typename t_C4, typename t_C5, typename t_C6, typename t_C7, typename t_C8, typename t_C9>
			struct TCMakeFunctionType<9, t_C0, t_C1, t_C2, t_C3, t_C4, t_C5, t_C6, t_C7, t_C8, t_C9>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1, t_C2 _P2, t_C3 _P3, t_C4 _P4, t_C5 _P5, t_C6 _P6, t_C7 _P7, t_C8 _P8);
			};

			template <typename t_C0, typename t_C1, typename t_C2, typename t_C3, typename t_C4, typename t_C5, typename t_C6, typename t_C7, typename t_C8, typename t_C9>
			struct TCMakeFunctionType<10, t_C0, t_C1, t_C2, t_C3, t_C4, t_C5, t_C6, t_C7, t_C8, t_C9>
			{
				typedef void CType(t_C0 _P0, t_C1 _P1, t_C2 _P2, t_C3 _P3, t_C4 _P4, t_C5 _P5, t_C6 _P6, t_C7 _P7, t_C8 _P8, t_C9 _P9);
			};
#endif

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Do bind transform to enable member function pointers												|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template 
			<
				typename t_CToBind
				, bint t_bIsMemberFunctionPtr 
					= NTraits::TCIsMemberFunctionPointer
					<
						typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CToBind>::CType>::CType
					>::mc_Value
			>
			struct TCDoToBindTransform
			{
				typedef typename NTraits::TCDecay<t_CToBind>::CType CType;
			};

			template <typename t_CToBind>
			struct TCDoToBindTransform<t_CToBind, true>
			{
				typedef typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CToBind>::CType>::CType CRawType;
				typedef TCMemberFunctionFunctor<CRawType> CType;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Helper for getting param super type																|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			// We need this so we can make this operation a friend
			template <typename t_CBindExpression>
			struct TCGetBindExpressionParamSuper
			{
				typedef typename t_CBindExpression::CParamSuper CType;
			};
		}
	}
}

