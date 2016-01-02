// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NBindExpression
		{
			template 
			<
				typename t_CToBind
				, typename t_CP0 = void
				, typename t_CP1 = void
				, typename t_CP2 = void
				, typename t_CP3 = void
				, typename t_CP4 = void
				, typename t_CP5 = void
				, typename t_CP6 = void
				, typename t_CP7 = void
				, typename t_CP8 = void
	#ifndef DMibRestrictNumberOfBindParams
				, typename t_CP9 = void
				, typename t_CP10 = void
				, typename t_CP11 = void
				, typename t_CP12 = void
				, typename t_CP13 = void
	#endif
			>
			class TCBindExpression 
				: protected NPrivate::TCBindExpressionZeroCall
				<
					NPrivate::TCBindOptions
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
				typedef NPrivate::TCBindExpressionZeroCall
				<
					NPrivate::TCBindOptions
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
				> CSuper;

				template <mint t_Level, mint t_nInParams, typename t_CImplementation, int t_iParam, int32 t_HighestUsedParam, int t_nParams, bint t_bEnable>
				friend struct NPrivate::TCGetBindParam;

				template <int t_nParams>
				friend struct NPrivate::TCDoCompare;

				template <typename t_CType, mint t_Level, mint t_nInParams>
				friend struct NPrivate::TCGetBindExpressionUsedParams;

				template <typename t_CBindExpression>
				friend struct NPrivate::TCGetBindExpressionParamSuper;

				template <typename t_CType, mint t_Level, mint t_nInParams>
				friend struct NPrivate::TCNeedPartialBind;
			
				using CSuper::fp_BoundObject;
				using CSuper::fp_GetSuper;

				typedef typename CSuper::CParamSuper CParamSuper;
				typedef typename CSuper::CToBind CToBind;

			public:
				typedef NPrivate::TCBindOptions
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
				> CBindOptions
				;

				using CSuper::operator ();
				TCBindExpression(TCBindExpression &&_Other)
					: CSuper((CSuper &&)_Other)
				{
				}

				TCBindExpression(TCBindExpression const &_Other)
					: CSuper((CSuper const &)_Other)
				{
				}

				TCBindExpression(TCBindExpression volatile &_Other)
					: CSuper((CSuper volatile &)_Other)
				{
				}

				TCBindExpression(TCBindExpression const volatile &_Other)
					: CSuper((CSuper const volatile &)_Other)
				{
				}

				TCBindExpression(TCBindExpression &_Other)
					: CSuper((CSuper &)_Other)
				{
				}

				TCBindExpression &operator =(TCBindExpression &_Other)
				{
					(*((CSuper *)this)) = ((CSuper &)_Other);
					return *this;
				}

				TCBindExpression &operator =(TCBindExpression const &_Other)
				{
					(*((CSuper *)this)) = ((CSuper const &)_Other);
					return *this;
				}

				TCBindExpression &operator =(TCBindExpression volatile &_Other)
				{
					(*((CSuper *)this)) = ((CSuper volatile &)_Other);
					return *this;
				}

				TCBindExpression &operator =(TCBindExpression const volatile &_Other)
				{
					(*((CSuper *)this)) = ((CSuper const volatile &)_Other);
					return *this;
				}

				TCBindExpression &operator =(TCBindExpression &&_Other)
				{
					(*((CSuper *)this)) = ((CSuper &&)_Other);
					return *this;
				}

				template <typename tf_CToBind>
				TCBindExpression(tf_CToBind &&_ToBind)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind))
				{
				}

				template <typename tf_CToBind, typename tf_CP0>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0))
				{
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1))
				{
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2))
				{
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3))
				{
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3), fg_Forward<tf_CP4>(_P4))
				{
				}

	#ifndef DMibRestrictNumberOfBindParams
				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
					)
				{
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
					)
				{
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6, typename tf_CP7>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
					)
				{
				}

				template 
				<
					typename tf_CToBind
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
				>
				TCBindExpression(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
					)
				{
				}

				template 
				<
					typename tf_CToBind
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
				TCBindExpression
				(
					tf_CToBind &&_ToBind
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
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
					)
				{
				}		
	#endif

#				define DMibTemp_GenerateParam(d_Z, d_Iterator, d_ExtraParam) , DMibPreIf(DMibPreLess(d_Iterator,d_ExtraParam),fg_Forward<tf_CP##d_Iterator>(_P##d_Iterator),CNil())
#				define DMibTemp_GenerateArguments(d_Z, d_Iterator, d_ExtraParam) DMibPreCommaIf(d_Iterator) tf_CP##d_Iterator &&_P##d_Iterator

#ifndef DMibRestrictNumberOfBindParams
#				define DMibTemp_GenerateFunctionOperator(d_nParams, d_Qualifiers)\
				template <DMibPreGenerateParams(d_nParams, typename tf_CP)>\
				auto operator () (DMibPreRepeat(d_nParams, DMibTemp_GenerateArguments, unused)) d_Qualifiers\
				-> \
				decltype\
				(\
					NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, d_nParams>::mc_Value>::fs_Call\
					(\
						fg_GetReference<d_Qualifiers CToBind>()\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 0>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 1>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 2>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 3>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 4>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 5>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 6>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 7>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 8>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 9>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
					)\
				)\
				{\
					static_assert(NPrivate::TCCheckBindParams<CParamSuper, d_nParams>::mc_Value, "");\
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, d_nParams>::mc_Value>::fs_Call\
						(\
							fp_BoundObject()\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 0>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 1>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 2>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 3>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 4>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 5>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 6>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 7>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 8>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 9>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
						)\
					;\
				}

#else

#				define DMibTemp_GenerateFunctionOperator(d_nParams, d_Qualifiers)\
				template <DMibPreGenerateParams(d_nParams, typename tf_CP)>\
				auto operator () (DMibPreRepeat(d_nParams, DMibTemp_GenerateArguments, unused)) d_Qualifiers\
				-> \
				decltype\
				(\
					NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, d_nParams>::mc_Value>::fs_Call\
					(\
						fg_GetReference<d_Qualifiers CToBind>()\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 0>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 1>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 2>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 3>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
						, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 4>::fs_Param\
						(\
							fg_GetReference<d_Qualifiers CParamSuper>()\
							DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
						)\
					)\
				)\
				{\
					static_assert(NPrivate::TCCheckBindParams<CParamSuper, d_nParams>::mc_Value, "");\
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, d_nParams>::mc_Value>::fs_Call\
						(\
							fp_BoundObject()\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 0>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 1>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 2>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 3>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
							, NPrivate::TCGetBindParam<0, d_nParams, d_Qualifiers CParamSuper, 4>::fs_Param\
							(\
								fp_GetSuper()\
								DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, d_nParams)\
							)\
						)\
					;\
				}

#endif

				DMibTemp_GenerateFunctionOperator(1, );
				DMibTemp_GenerateFunctionOperator(1, const);
				DMibTemp_GenerateFunctionOperator(1, volatile);
				DMibTemp_GenerateFunctionOperator(1, const volatile);
				DMibTemp_GenerateFunctionOperator(2, );
				DMibTemp_GenerateFunctionOperator(2, const);
				DMibTemp_GenerateFunctionOperator(2, volatile);
				DMibTemp_GenerateFunctionOperator(2, const volatile);
				DMibTemp_GenerateFunctionOperator(3, );
				DMibTemp_GenerateFunctionOperator(3, const);
				DMibTemp_GenerateFunctionOperator(3, volatile);
				DMibTemp_GenerateFunctionOperator(3, const volatile);
				DMibTemp_GenerateFunctionOperator(4, );
				DMibTemp_GenerateFunctionOperator(4, const);
				DMibTemp_GenerateFunctionOperator(4, volatile);
				DMibTemp_GenerateFunctionOperator(4, const volatile);
				DMibTemp_GenerateFunctionOperator(5, );
				DMibTemp_GenerateFunctionOperator(5, const);
				DMibTemp_GenerateFunctionOperator(5, volatile);
				DMibTemp_GenerateFunctionOperator(5, const volatile);
#ifndef DMibRestrictNumberOfBindParams
				DMibTemp_GenerateFunctionOperator(6, );
				DMibTemp_GenerateFunctionOperator(6, const);
				DMibTemp_GenerateFunctionOperator(6, volatile);
				DMibTemp_GenerateFunctionOperator(6, const volatile);
				DMibTemp_GenerateFunctionOperator(7, );
				DMibTemp_GenerateFunctionOperator(7, const);
				DMibTemp_GenerateFunctionOperator(7, volatile);
				DMibTemp_GenerateFunctionOperator(7, const volatile);
				DMibTemp_GenerateFunctionOperator(8, );
				DMibTemp_GenerateFunctionOperator(8, const);
				DMibTemp_GenerateFunctionOperator(8, volatile);
				DMibTemp_GenerateFunctionOperator(8, const volatile);
				DMibTemp_GenerateFunctionOperator(9, );
				DMibTemp_GenerateFunctionOperator(9, const);
				DMibTemp_GenerateFunctionOperator(9, volatile);
				DMibTemp_GenerateFunctionOperator(9, const volatile);
				DMibTemp_GenerateFunctionOperator(10, );
				DMibTemp_GenerateFunctionOperator(10, const);
				DMibTemp_GenerateFunctionOperator(10, volatile);
				DMibTemp_GenerateFunctionOperator(10, const volatile);
#endif

				/***************************************************************************************************\
				|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
				| Nested 10 arguments																				|
				|___________________________________________________________________________________________________|
				\***************************************************************************************************/
				template 
				<
					mint tf_Level
					, mint tf_nInParams
					, int32 tf_HighestUsedParam
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
				auto f_NestedCall
				(
					tf_CP0 &&_P0
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
				typename NPrivate::TCResolveRecursiveCall
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, CParamSuper
					, CParamSuper
					, CToBind
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
				{
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, tf_nInParams>::mc_Value>::fs_Call
						(
							fp_BoundObject()
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 0, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 1, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 2, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 3, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 4, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#ifndef DMibRestrictNumberOfBindParams
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 5, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 6, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 7, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 8, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 9, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#endif
						)
						;
				}

				template 
				<
					mint tf_Level
					, mint tf_nInParams
					, int32 tf_HighestUsedParam
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
				auto f_NestedCallConst
				(
					tf_CP0 &&_P0
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
				) const
				->
				typename NPrivate::TCResolveRecursiveCall
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, CParamSuper
					, const CParamSuper
					, const CToBind
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
				{
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, tf_nInParams>::mc_Value>::fs_Call
						(
							fp_BoundObject()
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 0, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 1, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 2, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 3, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 4, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#ifndef DMibRestrictNumberOfBindParams
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 5, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 6, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 7, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 8, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 9, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#endif
						)
						;
				}

				template 
				<
					mint tf_Level
					, mint tf_nInParams
					, int32 tf_HighestUsedParam
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
				auto f_NestedCallVolatile
				(
					tf_CP0 &&_P0
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
				) volatile
				->
				typename NPrivate::TCResolveRecursiveCall
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, CParamSuper
					, volatile CParamSuper
					, volatile CToBind
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
				{
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, tf_nInParams>::mc_Value>::fs_Call
						(
							fp_BoundObject()
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 0, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 1, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 2, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 3, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 4, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#ifndef DMibRestrictNumberOfBindParams
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 5, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 6, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 7, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 8, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 9, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#endif
						)
						;
				}

				template 
				<
					mint tf_Level
					, mint tf_nInParams
					, int32 tf_HighestUsedParam
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
				auto f_NestedCallConstVolatile
				(
					tf_CP0 &&_P0
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
				) const volatile
				->
				typename NPrivate::TCResolveRecursiveCall
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, CParamSuper
					, const volatile CParamSuper
					, const volatile CToBind
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
				{
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, tf_nInParams>::mc_Value>::fs_Call
						(
							fp_BoundObject()
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 0, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 1, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 2, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 3, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 4, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#ifndef DMibRestrictNumberOfBindParams
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 5, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 6, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 7, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 8, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 9, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#endif
						)
					;
				}


				/***************************************************************************************************\
				|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
				| Nested bind																						|
				|___________________________________________________________________________________________________|
				\***************************************************************************************************/


				template 
				<
					mint tf_Level
					, mint tf_nInParams
					, int32 tf_HighestUsedParam
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
				auto f_PartialBind
				(
					tf_CP0 &&_P0
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
				typename NPrivate::TCResolvePartialBind
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, CParamSuper
					, CParamSuper
					, CToBind
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
				{
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, tf_nInParams>::mc_Value>::fs_PartialBind
						(
							fp_BoundObject()
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 0, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 1, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 2, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 3, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 4, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#ifndef DMibRestrictNumberOfBindParams
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 5, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 6, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 7, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 8, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, CParamSuper, 9, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#endif
						)
						;
				}

				template 
				<
					mint tf_Level
					, mint tf_nInParams
					, int32 tf_HighestUsedParam
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
				auto f_PartialBindConst
				(
					tf_CP0 &&_P0
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
				) const
				->
				typename NPrivate::TCResolvePartialBind
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, CParamSuper
					, const CParamSuper
					, const CToBind
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
				{
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, tf_nInParams>::mc_Value>::fs_PartialBind
						(
							fp_BoundObject()
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 0, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 1, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 2, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 3, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 4, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#ifndef DMibRestrictNumberOfBindParams
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 5, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 6, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 7, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 8, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const CParamSuper, 9, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#endif
						)
					;
				}


				template 
				<
					mint tf_Level
					, mint tf_nInParams
					, int32 tf_HighestUsedParam
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
				auto f_PartialBindVolatile
				(
					tf_CP0 &&_P0
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
				) volatile
				->
				typename NPrivate::TCResolvePartialBind
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, CParamSuper
					, volatile CParamSuper
					, volatile CToBind
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
				{
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, tf_nInParams>::mc_Value>::fs_PartialBind
						(
							fp_BoundObject()
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 0, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 1, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 2, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 3, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 4, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#ifndef DMibRestrictNumberOfBindParams
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 5, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 6, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 7, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 8, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, volatile CParamSuper, 9, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#endif
						)
					;
				}

				template 
				<
					mint tf_Level
					, mint tf_nInParams
					, int32 tf_HighestUsedParam
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
				auto f_PartialBindConstVolatile
				(
					tf_CP0 &&_P0
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
				) const volatile
				->
				typename NPrivate::TCResolvePartialBind
				<
					tf_Level
					, tf_nInParams
					, tf_HighestUsedParam
					, CParamSuper
					, const volatile CParamSuper
					, const volatile CToBind
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
				{
					return NPrivate::TCCallBindExpression<NPrivate::TCGetFinalParamNumber<CParamSuper, tf_nInParams>::mc_Value>::fs_PartialBind
						(
							fp_BoundObject()
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 0, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 1, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 2, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 3, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 4, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#ifndef DMibRestrictNumberOfBindParams
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 5, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 6, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 7, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 8, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
							, NPrivate::TCGetBindParam<tf_Level, tf_nInParams, const volatile CParamSuper, 9, tf_HighestUsedParam>::fs_Param
							(
								fp_GetSuper() DMibPreRepeat(DMibBindMaxNumParams, DMibTemp_GenerateParam, DMibBindMaxNumParams)
							)
	#endif
						)
					;
				}

#				undef DMibTemp_GenerateFunctionOperator
#				undef DMibTemp_GenerateParam
#				undef DMibTemp_GenerateArguments

				/***************************************************************************************************\
				|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|
				| Compare																							|
				|___________________________________________________________________________________________________|
				\***************************************************************************************************/


				bint f_Equal(TCBindExpression const &_Right) const
				{
					return NPrivate::TCDoCompare<CBindOptions::mc_NumParams>::fs_Equal(*this, _Right);
				}

				bint f_Less(TCBindExpression const &_Right) const
				{
					return NPrivate::TCDoCompare<CBindOptions::mc_NumParams>::fs_Less(*this, _Right);
				}
			};
		}
	}
}
