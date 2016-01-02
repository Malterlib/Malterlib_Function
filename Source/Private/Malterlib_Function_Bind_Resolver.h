// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{

			template <typename t_CType, mint t_Level, mint t_nInParams>
			struct TCNeedPartialBind
			{
				static const uint32 mc_Value = false; 
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Compare																							|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <int t_nParams>
			struct TCDoCompare
			{
				static_assert(t_nParams >= 0 && t_nParams < 10, "Only support 10 params");
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Call bind expression																				|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <int t_nParams>
			struct TCCallBindExpression
			{
				static_assert(t_nParams >= 0 && t_nParams < 10, "Only support 10 params");
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Resolve bind param result																			|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template 
			<	
				mint t_Level
				, mint t_nInParams
				, int32 t_HighestUsedParam
				, typename t_CParam
				, typename t_CP0
				, typename t_CP1
				, typename t_CP2
				, typename t_CP3
				, typename t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, typename t_CP5
				, typename t_CP6
				, typename t_CP7
				, typename t_CP8
				, typename t_CP9
#endif
				, bint t_bIsPlaceholder 
					= TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CParam>::CType>::CType>::mc_Value 
				, bint t_bSamePlaceHolderLevel
					= TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CParam>::CType>::CType>::mc_Level == t_Level
				, mint t_Placeholder 
					= TCIsBindPlaceholder<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CParam>::CType>::CType>::mc_Param
				, bint t_bNested 
					= TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CParam>::CType>::CType>::mc_Value 
					&& TCIsBindExpression<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CParam>::CType>::CType>::mc_bEnableNesting
				, bint t_bIsConst = NTraits::TCIsConst<typename NTraits::TCRemoveReference<t_CParam>::CType>::mc_Value
				, bint t_bIsVolatile = NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<t_CParam>::CType>::mc_Value
				, bint t_bPartialBind = TCNeedPartialBind<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CParam>::CType>::CType, t_Level, t_nInParams>::mc_Value
			>
			struct TCResolveBindParamResult
			{
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Get bind param default																			|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <int tf_iParam>
			struct TCGetBindParamDefault
			{
				template 
				<	
					typename tf_CObject
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
				static auto fs_Param
				(
					tf_CObject &&_Object
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
				-> CNil
				{
					return CNil();
				}
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Get bind expression used params																	|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/


			template <typename t_CType, mint t_Level, mint t_nInParams>
			struct TCGetBindExpressionUsedParams
			{
				static const uint32 mc_UsedParams = 0;
				static const bint mc_bOtherLevelParams = false;
				static const bint mc_bForwardExtra = false;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Get final param number																			|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <typename t_CImplementation, int32 t_nInParams>
			struct TCGetFinalParamNumber;

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Get bind param																					|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/
			
			template 
			<
				mint t_Level
				, mint t_nInParams
				, typename t_CImplementation
				, int t_iParam
				, int32 t_HighestUsedParam = NPrivate::TCGetFinalParamNumber<t_CImplementation, t_nInParams>::mc_HighestUsedParam
				, int t_nParams = t_CImplementation::CBindOptions::mc_NumParams
				, bint t_bEnable = (t_iParam < t_nParams)
			>
			struct TCGetBindParam
			{
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Get bind param resolve properties																	|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template 
			<
				mint t_Level
				, mint t_nInParams
				, typename t_CImplementation
				, int t_iParam
				, int t_nParams = t_CImplementation::CBindOptions::mc_NumParams
				, bint t_bEnable = (t_iParam < t_nParams)
			>
			struct TCGetBindParamResolveProperties
			{
				static const uint32 mc_UsedParams = 0;
				static const bint mc_bOtherLevelParams = false;
				static const bint mc_bForwardExtra = false;
			};

		}
	}
}

