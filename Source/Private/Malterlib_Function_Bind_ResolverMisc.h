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
			| TCGetBindExpressionUsedParams																		|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template 
			<
				typename t_CBFOpts
				, int t_iParam
				, typename t_CParam
				, bint t_bIsEmpty
				, mint t_Level
				, mint t_nInParams
			>
			struct TCGetBindExpressionUsedParams
			<
				TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, t_bIsEmpty>
				, t_Level
				, t_nInParams
			>
			{
			private:
				typedef TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, t_bIsEmpty> CParamSuper;
			public:
				static const uint32 mc_UsedParams
					= NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 0>::mc_UsedParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 1>::mc_UsedParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 2>::mc_UsedParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 3>::mc_UsedParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 4>::mc_UsedParams
#ifndef DMibRestrictNumberOfBindParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 5>::mc_UsedParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 6>::mc_UsedParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 7>::mc_UsedParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 8>::mc_UsedParams
					| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 9>::mc_UsedParams
#endif
				;

				static const bint mc_bOtherLevelParams
					= NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 0>::mc_bOtherLevelParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 1>::mc_bOtherLevelParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 2>::mc_bOtherLevelParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 3>::mc_bOtherLevelParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 4>::mc_bOtherLevelParams
#ifndef DMibRestrictNumberOfBindParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 5>::mc_bOtherLevelParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 6>::mc_bOtherLevelParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 7>::mc_bOtherLevelParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 8>::mc_bOtherLevelParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 9>::mc_bOtherLevelParams
#endif
				;

				static const bint mc_bForwardExtra
					= 
					(
						t_CBFOpts::mc_bForwardExtra 
						&& t_CBFOpts::mc_ForwardExtraLevel == t_Level
					)
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 0>::mc_bForwardExtra
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 1>::mc_bForwardExtra
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 2>::mc_bForwardExtra
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 3>::mc_bForwardExtra
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 4>::mc_bForwardExtra
#ifndef DMibRestrictNumberOfBindParams
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 5>::mc_bForwardExtra
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 6>::mc_bForwardExtra
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 7>::mc_bForwardExtra
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 8>::mc_bForwardExtra
					|| NPrivate::TCGetBindParamResolveProperties<t_Level + 1, t_nInParams, CParamSuper, 9>::mc_bForwardExtra
#endif
				;
			};
			
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
				, mint t_Level
				, mint t_nInParams
			>
			struct TCGetBindExpressionUsedParams
			<
				NBindExpression::TCBindExpression
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
				, t_Level
				, t_nInParams
			>
				: public TCGetBindExpressionUsedParams
				<
					typename TCGetBindExpressionParamSuper
					<
						NBindExpression::TCBindExpression
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
					>::CType
					, t_Level
					, t_nInParams
				>
			{
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| TCGetFinalParamNumber																				|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <typename t_CImplementation, int32 t_nInParams>
			struct TCGetFinalParamNumber
			{
				static const mint mc_NumParams = t_CImplementation::CBindOptions::mc_NumParams;
				static const bint mc_bForwardExtra
					= 
					(
						t_CImplementation::CBindOptions::mc_bForwardExtra
						&& t_CImplementation::CBindOptions::mc_ForwardExtraLevel == 0
					)
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 0>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 1>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 2>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 3>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 4>::mc_bForwardExtra
#ifndef DMibRestrictNumberOfBindParams
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 5>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 6>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 7>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 8>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 9>::mc_bForwardExtra
#endif
				;
				static const uint32 mc_UsedParams
					= TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 0>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 1>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 2>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 3>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 4>::mc_UsedParams
#ifndef DMibRestrictNumberOfBindParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 5>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 6>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 7>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 8>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 9>::mc_UsedParams
#endif
				;

				static const int32 mc_HighestUsedParam = NMib::TCHighestBitSet<uint32, mc_UsedParams>::mc_Value;
				static const int32 mc_WantedValue = mc_NumParams + (mc_bForwardExtra ? ((t_nInParams - mc_HighestUsedParam) > 0 ? (t_nInParams - mc_HighestUsedParam) : 0) : 0);
				static const int32 mc_Value = mc_WantedValue > (int32)t_CImplementation::CBindOptions::mc_MaxParams ? (int32)t_CImplementation::CBindOptions::mc_MaxParams : mc_WantedValue;
			};


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
				, mint t_Level
				, mint t_nInParams
			>
			struct TCNeedPartialBind
			<
				NBindExpression::TCBindExpression
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
				, t_Level
				, t_nInParams
			>
			{
			private:
				typedef NBindExpression::TCBindExpression
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
				> CBindExpression;
				typedef typename CBindExpression::CParamSuper CParamSuper;
			public:
				//static_assert(t_Level != 0, "Should never be checked at first level");
				static const uint32 mc_Value
					=
					(
						NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 0>::mc_UsedParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 1>::mc_UsedParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 2>::mc_UsedParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 3>::mc_UsedParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 4>::mc_UsedParams
#ifndef DMibRestrictNumberOfBindParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 5>::mc_UsedParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 6>::mc_UsedParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 7>::mc_UsedParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 8>::mc_UsedParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 9>::mc_UsedParams
#endif
					)
					&&
					(
						NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 0>::mc_bOtherLevelParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 1>::mc_bOtherLevelParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 2>::mc_bOtherLevelParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 3>::mc_bOtherLevelParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 4>::mc_bOtherLevelParams
#ifndef DMibRestrictNumberOfBindParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 5>::mc_bOtherLevelParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 6>::mc_bOtherLevelParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 7>::mc_bOtherLevelParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 8>::mc_bOtherLevelParams
						|| NPrivate::TCGetBindParamResolveProperties<t_Level, t_nInParams, CParamSuper, 9>::mc_bOtherLevelParams
#endif
					)
				;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Check bind params																					|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/

			template <typename t_CImplementation, int32 t_nInParams>
			struct TCCheckBindParams
			{
				static const mint mc_NumParams = t_CImplementation::CBindOptions::mc_NumParams;
				static const bint mc_bForwardExtra 
					= 
					(
						t_CImplementation::CBindOptions::mc_bForwardExtra
						&& t_CImplementation::CBindOptions::mc_ForwardExtraLevel == 0
					)
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 0>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 1>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 2>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 3>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 4>::mc_bForwardExtra
#ifndef DMibRestrictNumberOfBindParams
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 5>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 6>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 7>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 8>::mc_bForwardExtra
					|| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 9>::mc_bForwardExtra
#endif
				;

				static const uint32 mc_UsedParams
					= TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 0>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 1>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 2>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 3>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 4>::mc_UsedParams
#ifndef DMibRestrictNumberOfBindParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 5>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 6>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 7>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 8>::mc_UsedParams
					| TCGetBindParamResolveProperties<0, t_nInParams, t_CImplementation, 9>::mc_UsedParams
#endif
				;

				static const uint32 mc_HighestUsedParam = NMib::TCHighestBitSet<uint32, mc_UsedParams>::mc_Value;

				template <int32 t_iParam>
				struct TCParamUsed
				{
					static const bint mc_Value 
						= (t_iParam >= t_nInParams)
						|| 
						(
							(
								(mc_UsedParams | t_CImplementation::CBindOptions::mc_IgnoredParamsImplicit)
								& DMibBitTyped(t_iParam, uint32)
							)
						)
						|| (mc_bForwardExtra && t_iParam >= mc_HighestUsedParam)
						;
				};

				template <int32 t_iParam>
				struct TCIgnoredParamUsed
				{
					static const bint mc_Value
						= t_iParam < t_nInParams
						&& 
						(
							(mc_UsedParams & t_CImplementation::CBindOptions::mc_IgnoredParamsExplicit)
							& DMibBitTyped(t_iParam, uint32)
						);
				};

				static_assert(TCParamUsed<0>::mc_Value, "Parameter 0 not used");
				static_assert(TCParamUsed<1>::mc_Value, "Parameter 1 not used");
				static_assert(TCParamUsed<2>::mc_Value, "Parameter 2 not used");
				static_assert(TCParamUsed<3>::mc_Value, "Parameter 3 not used");
				static_assert(TCParamUsed<4>::mc_Value, "Parameter 4 not used");
#ifndef DMibRestrictNumberOfBindParams
				static_assert(TCParamUsed<5>::mc_Value, "Parameter 5 not used");
				static_assert(TCParamUsed<6>::mc_Value, "Parameter 6 not used");
				static_assert(TCParamUsed<7>::mc_Value, "Parameter 7 not used");
				static_assert(TCParamUsed<8>::mc_Value, "Parameter 8 not used");
				static_assert(TCParamUsed<9>::mc_Value, "Parameter 9 not used");
#endif

				static_assert(!TCIgnoredParamUsed<0>::mc_Value, "Ignored parameter 0 used");
				static_assert(!TCIgnoredParamUsed<1>::mc_Value, "Ignored parameter 1 used");
				static_assert(!TCIgnoredParamUsed<2>::mc_Value, "Ignored parameter 2 used");
				static_assert(!TCIgnoredParamUsed<3>::mc_Value, "Ignored parameter 3 used");
				static_assert(!TCIgnoredParamUsed<4>::mc_Value, "Ignored parameter 4 used");
#ifndef DMibRestrictNumberOfBindParams
				static_assert(!TCIgnoredParamUsed<5>::mc_Value, "Ignored parameter 5 used");
				static_assert(!TCIgnoredParamUsed<6>::mc_Value, "Ignored parameter 6 used");
				static_assert(!TCIgnoredParamUsed<7>::mc_Value, "Ignored parameter 7 used");
				static_assert(!TCIgnoredParamUsed<8>::mc_Value, "Ignored parameter 8 used");
				static_assert(!TCIgnoredParamUsed<9>::mc_Value, "Ignored parameter 9 used");
#endif
				
				static_assert
					(
						TCGetFinalParamNumber<t_CImplementation, t_nInParams>::mc_Value == TCGetFinalParamNumber<t_CImplementation, t_nInParams>::mc_WantedValue
						, "Unsupported number of params generated"
					)
				;

				static const bint mc_Value = true;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Resolve recursive bind																			|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/
			template 
			<
				mint t_Level
				, mint t_nInParams
				, int32 t_HighestUsedParam
				, typename t_CParamSuper
				, typename t_CParamSuperQualifiers
				, typename t_CToBind
				, typename t_C0 = CNil
				, typename t_C1 = CNil
				, typename t_C2 = CNil
				, typename t_C3 = CNil
				, typename t_C4 = CNil
#ifndef DMibRestrictNumberOfBindParams
				, typename t_C5 = CNil
				, typename t_C6 = CNil
				, typename t_C7 = CNil
				, typename t_C8 = CNil
				, typename t_C9 = CNil
#endif
			>
			struct TCResolveRecursiveCall
			{
				typedef decltype
				(
					NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<t_CParamSuper, t_nInParams>::mc_Value>::fs_Call
					(
						fg_GetReference<t_CToBind>()
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 0, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 1, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 2, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 3, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 4, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
#ifndef DMibRestrictNumberOfBindParams
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 5, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 6, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 7, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 8, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 9, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
#endif
					)
				) CType;
			};

			/***************************************************************************************************\
			|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
			| Resolve partial bind																				|
			|___________________________________________________________________________________________________|
			\***************************************************************************************************/
			template 
			<
				mint t_Level
				, mint t_nInParams
				, int32 t_HighestUsedParam
				, typename t_CParamSuper
				, typename t_CParamSuperQualifiers
				, typename t_CToBind
				, typename t_C0 = CNil
				, typename t_C1 = CNil
				, typename t_C2 = CNil
				, typename t_C3 = CNil
				, typename t_C4 = CNil
#ifndef DMibRestrictNumberOfBindParams
				, typename t_C5 = CNil
				, typename t_C6 = CNil
				, typename t_C7 = CNil
				, typename t_C8 = CNil
				, typename t_C9 = CNil
#endif
			>
			struct TCResolvePartialBind
			{
				typedef decltype
				(
					NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<t_CParamSuper, t_nInParams>::mc_Value>::fs_PartialBind
					(
						fg_GetReference<t_CToBind>()
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 0, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 1, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 2, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 3, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 4, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
#ifndef DMibRestrictNumberOfBindParams
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
#endif
						)
#ifndef DMibRestrictNumberOfBindParams
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 5, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 6, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 7, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 8, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
						, NPrivate::TCGetBindParam<t_Level, t_nInParams, t_CParamSuperQualifiers, 9, t_HighestUsedParam>::fs_Param
						(
							fg_GetReference<t_CParamSuperQualifiers>()
							, fg_GetType<t_C0>()
							, fg_GetType<t_C1>()
							, fg_GetType<t_C2>()
							, fg_GetType<t_C3>()
							, fg_GetType<t_C4>()
							, fg_GetType<t_C5>()
							, fg_GetType<t_C6>()
							, fg_GetType<t_C7>()
							, fg_GetType<t_C8>()
							, fg_GetType<t_C9>()
						)
#endif
					)
				) CType;
			};
		}
	}
}

