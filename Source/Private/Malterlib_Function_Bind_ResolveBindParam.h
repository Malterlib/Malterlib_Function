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
			| Bind expression																					|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				&& !TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType, tf_Level + 1, tf_nInParams>::mc_Value
				&& !NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				&& !NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				, typename TCResolveBindParamResult
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, tf_CParam
					, tf_CP0
					, tf_CP1
					, tf_CP2
					, tf_CP3
					, tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5
					, tf_CP6
					, tf_CP7
					, tf_CP8
					, tf_CP9
#endif
				>::CType
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CParam>(_Param).template f_NestedCall<tf_Level + 1, tf_nInParams, tf_HighestUsedParam>
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
#ifndef DMibRestrictNumberOfBindParams
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
#endif
					)
				;
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				&& !TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType, tf_Level + 1, tf_nInParams>::mc_Value
				&& NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				&& !NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				, typename TCResolveBindParamResult
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, tf_CParam
					, tf_CP0
					, tf_CP1
					, tf_CP2
					, tf_CP3
					, tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5
					, tf_CP6
					, tf_CP7
					, tf_CP8
					, tf_CP9
#endif
				>::CType
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CParam>(_Param).template f_NestedCallConst<tf_Level + 1, tf_nInParams, tf_HighestUsedParam>
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
#ifndef DMibRestrictNumberOfBindParams
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
#endif
					)
				;
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				&& !TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType, tf_Level + 1, tf_nInParams>::mc_Value
				&& !NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				&& NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				, typename TCResolveBindParamResult
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, tf_CParam
					, tf_CP0
					, tf_CP1
					, tf_CP2
					, tf_CP3
					, tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5
					, tf_CP6
					, tf_CP7
					, tf_CP8
					, tf_CP9
#endif
				>::CType
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CParam>(_Param).template f_NestedCallVolatile<tf_Level + 1, tf_nInParams, tf_HighestUsedParam>
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
#ifndef DMibRestrictNumberOfBindParams
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
#endif
					)
				;
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				&& !TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType, tf_Level + 1, tf_nInParams>::mc_Value
				&& NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				&& NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				, typename TCResolveBindParamResult
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, tf_CParam
					, tf_CP0
					, tf_CP1
					, tf_CP2
					, tf_CP3
					, tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5
					, tf_CP6
					, tf_CP7
					, tf_CP8
					, tf_CP9
#endif
				>::CType
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CParam>(_Param).template f_NestedCallConstVolatile<tf_Level + 1, tf_nInParams, tf_HighestUsedParam>
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
#ifndef DMibRestrictNumberOfBindParams
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
#endif
					)
				;
			}


			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level != tf_Level
				, typename NTraits::TCRemoveQualifiers<tf_CParam>::CType
			>::CType
			{
				return fg_RemoveQualifiers(_Param);
			}


			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 0
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP0
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CP0>(_P0);
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 1
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP1
			>::CType
			{
				return fg_Forward<tf_CP1>(_P1);
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 2
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP2
			>::CType
			{
				return fg_Forward<tf_CP2>(_P2);
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 3
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP3
			>::CType
			{
				return fg_Forward<tf_CP3>(_P3);
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 4
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP4
			>::CType
			{
				return fg_Forward<tf_CP4>(_P4);
			}

#ifndef DMibRestrictNumberOfBindParams

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 5
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP5
			>::CType
			{
				return fg_Forward<tf_CP5>(_P5);
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 6
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP6
			>::CType
			{
				return fg_Forward<tf_CP6>(_P6);
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 7
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP7
			>::CType
			{
				return fg_Forward<tf_CP7>(_P7);
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 8
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP8
			>::CType
			{
				return fg_Forward<tf_CP8>(_P8);
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
			)
			->
			typename TCEnableIf
			<
				TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Param == 9
				&& TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Level == tf_Level
				, tf_CP9
			>::CType
			{
				return fg_Forward<tf_CP9>(_P9);
			}
#endif

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static auto fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			->
			typename TCEnableIf
			<
				!TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value
				&& 
				!
				(
					TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
					&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				)
				, tf_CParam
			>::CType
			{
				return fg_Forward<tf_CParam>(_Param);
			}


			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Partial bind																						|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/


			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				&& TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType, tf_Level + 1, tf_nInParams>::mc_Value
				&& !NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				&& !NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				, typename TCResolveBindParamResult
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, tf_CParam
					, tf_CP0
					, tf_CP1
					, tf_CP2
					, tf_CP3
					, tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5
					, tf_CP6
					, tf_CP7
					, tf_CP8
					, tf_CP9
#endif
				>::CType
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CParam>(_Param).template f_PartialBind<tf_Level + 1, tf_nInParams, tf_HighestUsedParam>
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
#ifndef DMibRestrictNumberOfBindParams
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
#endif
					)
				;
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				&& TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType, tf_Level + 1, tf_nInParams>::mc_Value
				&& NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				&& !NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				, typename TCResolveBindParamResult
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, tf_CParam
					, tf_CP0
					, tf_CP1
					, tf_CP2
					, tf_CP3
					, tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5
					, tf_CP6
					, tf_CP7
					, tf_CP8
					, tf_CP9
#endif
				>::CType
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CParam>(_Param).template f_PartialBindConst<tf_Level + 1, tf_nInParams, tf_HighestUsedParam>
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
#ifndef DMibRestrictNumberOfBindParams
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
#endif
					)
				;
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				&& TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType, tf_Level + 1, tf_nInParams>::mc_Value
				&& !NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				&& NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				, typename TCResolveBindParamResult
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, tf_CParam
					, tf_CP0
					, tf_CP1
					, tf_CP2
					, tf_CP3
					, tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5
					, tf_CP6
					, tf_CP7
					, tf_CP8
					, tf_CP9
#endif
				>::CType
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CParam>(_Param).template f_PartialBindVolatile<tf_Level + 1, tf_nInParams, tf_HighestUsedParam>
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
#ifndef DMibRestrictNumberOfBindParams
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
#endif
					)
				;
			}

			template 
			<	
				mint tf_Level
				, mint tf_nInParams
				, int32 tf_HighestUsedParam
				, typename tf_CParam
				, typename tf_CP0
				, typename tf_CP1
				, typename tf_CP2
				, typename tf_CP3
				, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename tf_CP5
				, typename tf_CP6
				, typename tf_CP7
				, typename tf_CP8
				, typename tf_CP9
#endif
			>
			static typename TCEnableIf
			<
				TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_Value 
				&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType>::mc_bEnableNesting
				&& TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CParam>::CType>::CType, tf_Level + 1, tf_nInParams>::mc_Value
				&& NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				&& NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CParam>::CType>::mc_Value
				, typename TCResolveBindParamResult
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, tf_CParam
					, tf_CP0
					, tf_CP1
					, tf_CP2
					, tf_CP3
					, tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5
					, tf_CP6
					, tf_CP7
					, tf_CP8
					, tf_CP9
#endif
				>::CType
			>::CType fg_ResolveBindParam
			(
				tf_CParam &&_Param
				, tf_CP0 &&_P0
				, tf_CP1 &&_P1
				, tf_CP2 &&_P2
				, tf_CP3 &&_P3
				, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
				, tf_CP5 &&_P5
				, tf_CP6 &&_P6
				, tf_CP7 &&_P7
				, tf_CP8 &&_P8
				, tf_CP9 &&_P9
#endif
			)
			{
				return fg_Forward<tf_CParam>(_Param).template f_PartialBindConstVolatile<tf_Level + 1, tf_nInParams, tf_HighestUsedParam>
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
#ifndef DMibRestrictNumberOfBindParams
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
#endif
					)
				;
			}

		}

	}
}

