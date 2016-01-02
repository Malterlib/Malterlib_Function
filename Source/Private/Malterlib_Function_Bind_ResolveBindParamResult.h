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
			| Params																							|
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
				, bint t_bSamePlaceHolderLevel
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CParam CType;
			};

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
				, mint t_Placeholder
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, true
				, false
				, t_Placeholder
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CParam CType;
			};

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
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, true
				, true
				, 0
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP0 CType;
			};
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
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, true
				, true
				, 1
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP1 CType;
			};
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
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, true
				, true
				, 2
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP2 CType;
			};
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
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, true
				, true
				, 3
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP3 CType;
			};
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
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, true
				, true
				, 4
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP4 CType;
			};
#ifndef DMibRestrictNumberOfBindParams
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
				, typename t_CP5
				, typename t_CP6
				, typename t_CP7
				, typename t_CP8
				, typename t_CP9
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
				, true
				, true
				, 5
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP5 CType;
			};
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
				, typename t_CP5
				, typename t_CP6
				, typename t_CP7
				, typename t_CP8
				, typename t_CP9
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
				, true
				, true
				, 6
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP6 CType;
			};
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
				, typename t_CP5
				, typename t_CP6
				, typename t_CP7
				, typename t_CP8
				, typename t_CP9
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
				, true
				, true
				, 7
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP7 CType;
			};
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
				, typename t_CP5
				, typename t_CP6
				, typename t_CP7
				, typename t_CP8
				, typename t_CP9
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
				, true
				, true
				, 8
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP8 CType;
			};
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
				, typename t_CP5
				, typename t_CP6
				, typename t_CP7
				, typename t_CP8
				, typename t_CP9
				, bint t_bIsConst
				, bint t_bIsVolatile
				, bint t_bPartialBind
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
				, true
				, true
				, 9
				, false
				, t_bIsConst
				, t_bIsVolatile
				, t_bPartialBind
			>
			{
				typedef t_CP9 CType;
			};
#endif

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Nested call																						|
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
				, bint t_bSamePlaceHolderLevel
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, true
				, false
				, false
				, false
			>
			{
				typedef 
				decltype
				(
					fg_GetType<t_CParam>().template f_NestedCall<t_Level + 1, t_nInParams, t_HighestUsedParam>
					(
						fg_GetType<t_CP0>()
						, fg_GetType<t_CP1>()
						, fg_GetType<t_CP2>()
						, fg_GetType<t_CP3>()
						, fg_GetType<t_CP4>()
#ifndef DMibRestrictNumberOfBindParams
						, fg_GetType<t_CP5>()
						, fg_GetType<t_CP6>()
						, fg_GetType<t_CP7>()
						, fg_GetType<t_CP8>()
						, fg_GetType<t_CP9>()
#endif
					)
				)
				CType;
			};
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
				, bint t_bSamePlaceHolderLevel
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, true
				, true
				, false
				, false
			>
			{
				typedef 
				decltype
				(
					fg_GetType<t_CParam>().template f_NestedCallConst<t_Level + 1, t_nInParams, t_HighestUsedParam>
					(
						fg_GetType<t_CP0>()
						, fg_GetType<t_CP1>()
						, fg_GetType<t_CP2>()
						, fg_GetType<t_CP3>()
						, fg_GetType<t_CP4>()
#ifndef DMibRestrictNumberOfBindParams
						, fg_GetType<t_CP5>()
						, fg_GetType<t_CP6>()
						, fg_GetType<t_CP7>()
						, fg_GetType<t_CP8>()
						, fg_GetType<t_CP9>()
#endif
					)
				)
				CType;
			};

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
				, bint t_bSamePlaceHolderLevel
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, true
				, false
				, true
				, false
			>
			{
				typedef 
				decltype
				(
					fg_GetType<t_CParam>().template f_NestedCallVolatile<t_Level + 1, t_nInParams, t_HighestUsedParam>
					(
						fg_GetType<t_CP0>()
						, fg_GetType<t_CP1>()
						, fg_GetType<t_CP2>()
						, fg_GetType<t_CP3>()
						, fg_GetType<t_CP4>()
#ifndef DMibRestrictNumberOfBindParams
						, fg_GetType<t_CP5>()
						, fg_GetType<t_CP6>()
						, fg_GetType<t_CP7>()
						, fg_GetType<t_CP8>()
						, fg_GetType<t_CP9>()
#endif
					)
				)
				CType;
			};
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
				, bint t_bSamePlaceHolderLevel
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, true
				, true
				, true
				, false
			>
			{
				typedef 
				decltype
				(
					fg_GetType<t_CParam>().template f_NestedCallConstVolatile<t_Level + 1, t_nInParams, t_HighestUsedParam>
					(
						fg_GetType<t_CP0>()
						, fg_GetType<t_CP1>()
						, fg_GetType<t_CP2>()
						, fg_GetType<t_CP3>()
						, fg_GetType<t_CP4>()
#ifndef DMibRestrictNumberOfBindParams
						, fg_GetType<t_CP5>()
						, fg_GetType<t_CP6>()
						, fg_GetType<t_CP7>()
						, fg_GetType<t_CP8>()
						, fg_GetType<t_CP9>()
#endif
					)
				)
				CType;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Partial bind																						|
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
				, bint t_bSamePlaceHolderLevel
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, true
				, false
				, false
				, true
			>
			{
				typedef 
				decltype
				(
					fg_GetType<t_CParam>().template f_PartialBind<t_Level + 1, t_nInParams, t_HighestUsedParam>
					(
						fg_GetType<t_CP0>()
						, fg_GetType<t_CP1>()
						, fg_GetType<t_CP2>()
						, fg_GetType<t_CP3>()
						, fg_GetType<t_CP4>()
#ifndef DMibRestrictNumberOfBindParams
						, fg_GetType<t_CP5>()
						, fg_GetType<t_CP6>()
						, fg_GetType<t_CP7>()
						, fg_GetType<t_CP8>()
						, fg_GetType<t_CP9>()
#endif
					)
				)
				CType;
			};
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
				, bint t_bSamePlaceHolderLevel
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, true
				, true
				, false
				, true
			>
			{
				typedef 
				decltype
				(
					fg_GetType<t_CParam>().template f_PartialBindConst<t_Level + 1, t_nInParams, t_HighestUsedParam>
					(
						fg_GetType<t_CP0>()
						, fg_GetType<t_CP1>()
						, fg_GetType<t_CP2>()
						, fg_GetType<t_CP3>()
						, fg_GetType<t_CP4>()
#ifndef DMibRestrictNumberOfBindParams
						, fg_GetType<t_CP5>()
						, fg_GetType<t_CP6>()
						, fg_GetType<t_CP7>()
						, fg_GetType<t_CP8>()
						, fg_GetType<t_CP9>()
#endif
					)
				)
				CType;
			};

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
				, bint t_bSamePlaceHolderLevel
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, true
				, false
				, true
				, true
			>
			{
				typedef 
				decltype
				(
					fg_GetType<t_CParam>().template f_PartialBindVolatile<t_Level + 1, t_nInParams, t_HighestUsedParam>
					(
						fg_GetType<t_CP0>()
						, fg_GetType<t_CP1>()
						, fg_GetType<t_CP2>()
						, fg_GetType<t_CP3>()
						, fg_GetType<t_CP4>()
#ifndef DMibRestrictNumberOfBindParams
						, fg_GetType<t_CP5>()
						, fg_GetType<t_CP6>()
						, fg_GetType<t_CP7>()
						, fg_GetType<t_CP8>()
						, fg_GetType<t_CP9>()
#endif
					)
				)
				CType;
			};
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
				, bint t_bSamePlaceHolderLevel
			>
			struct TCResolveBindParamResult
			<
				t_Level
				, t_nInParams
				, t_HighestUsedParam
				, t_CParam
				, t_CP0
				, t_CP1
				, t_CP2
				, t_CP3
				, t_CP4
#ifndef DMibRestrictNumberOfBindParams
				, t_CP5
				, t_CP6
				, t_CP7
				, t_CP8
				, t_CP9
#endif
				, false
				, t_bSamePlaceHolderLevel
				, 0
				, true
				, true
				, true
				, true
			>
			{
				typedef 
				decltype
				(
					fg_GetType<t_CParam>().template f_PartialBindConstVolatile<t_Level + 1, t_nInParams, t_HighestUsedParam>
					(
						fg_GetType<t_CP0>()
						, fg_GetType<t_CP1>()
						, fg_GetType<t_CP2>()
						, fg_GetType<t_CP3>()
						, fg_GetType<t_CP4>()
#ifndef DMibRestrictNumberOfBindParams
						, fg_GetType<t_CP5>()
						, fg_GetType<t_CP6>()
						, fg_GetType<t_CP7>()
						, fg_GetType<t_CP8>()
						, fg_GetType<t_CP9>()
#endif
					)
				)
				CType;
			};
		}
	}
}

