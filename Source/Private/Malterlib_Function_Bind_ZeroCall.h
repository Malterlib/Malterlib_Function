// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
#			define DMibTemp_ImplementCommonFirst \
				typedef TCBindExpressionParam<t_CBFOpts> CParamSuper;\
				typedef typename t_CBFOpts::CToBind CToBind;\
				CParamSuper &fp_GetSuper()\
				{\
					return *this;\
				}\
				const CParamSuper &fp_GetSuper() const\
				{\
					return *this;\
				}\
				volatile CParamSuper &fp_GetSuper() volatile\
				{\
					return *this;\
				}\
				const volatile CParamSuper &fp_GetSuper() const volatile\
				{\
					return *this;\
				}\
				template <typename tf_C0>\
				TCBindExpressionZeroCall(tf_C0 &&_P0)\
					: CParamSuper(fg_Forward<tf_C0>(_P0))\
				{\
				}\
				template <typename tf_C0, typename tf_C1>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1)\
					: CParamSuper(fg_Forward<tf_C0>(_P0), fg_Forward<tf_C1>(_P1))\
				{\
				}\
				template <typename tf_C0, typename tf_C1, typename tf_C2>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2)\
					: CParamSuper(fg_Forward<tf_C0>(_P0), fg_Forward<tf_C1>(_P1), fg_Forward<tf_C2>(_P2))\
				{\
				}\
				template <typename tf_C0, typename tf_C1, typename tf_C2, typename tf_C3>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2, tf_C3 &&_P3)\
					: CParamSuper(fg_Forward<tf_C0>(_P0), fg_Forward<tf_C1>(_P1), fg_Forward<tf_C2>(_P2), fg_Forward<tf_C3>(_P3))\
				{\
				}\
				template <typename tf_C0, typename tf_C1, typename tf_C2, typename tf_C3, typename tf_C4>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2, tf_C3 &&_P3, tf_C4 &&_P4)\
					: CParamSuper(fg_Forward<tf_C0>(_P0), fg_Forward<tf_C1>(_P1), fg_Forward<tf_C2>(_P2), fg_Forward<tf_C3>(_P3), fg_Forward<tf_C4>(_P4))\
				{\
				}\
				template <typename tf_C0, typename tf_C1, typename tf_C2, typename tf_C3, typename tf_C4, typename tf_C5>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2, tf_C3 &&_P3, tf_C4 &&_P4, tf_C5 &&_P5)\
					: CParamSuper(fg_Forward<tf_C0>(_P0), fg_Forward<tf_C1>(_P1), fg_Forward<tf_C2>(_P2), fg_Forward<tf_C3>(_P3), fg_Forward<tf_C4>(_P4), fg_Forward<tf_C5>(_P5))\
				{\
				}\
				TCBindExpressionZeroCall(TCBindExpressionZeroCall const &_Other)\
					: CParamSuper((CParamSuper const &)_Other)\
				{\
				}\
				TCBindExpressionZeroCall(TCBindExpressionZeroCall volatile &_Other)\
					: CParamSuper((CParamSuper const &)_Other)\
				{\
				}\
				TCBindExpressionZeroCall(TCBindExpressionZeroCall const volatile &_Other)\
					: CParamSuper((CParamSuper const &)_Other)\
				{\
				}\
				TCBindExpressionZeroCall(TCBindExpressionZeroCall &&_Other)\
					: CParamSuper((CParamSuper &&)_Other)\
				{\
				}\
				TCBindExpressionZeroCall(TCBindExpressionZeroCall &_Other)\
					: CParamSuper((CParamSuper &)_Other)\
				{\
				}\
				TCBindExpressionZeroCall &operator =(TCBindExpressionZeroCall &&_Other)\
				{\
					(*((CParamSuper *)this)) = ((CParamSuper &&)_Other);\
					return *this;\
				}\
				TCBindExpressionZeroCall &operator =(TCBindExpressionZeroCall &_Other)\
				{\
					(*((CParamSuper *)this)) = ((CParamSuper &)_Other);\
					return *this;\
				}\
				TCBindExpressionZeroCall &operator =(TCBindExpressionZeroCall const &_Other)\
				{\
					(*((CParamSuper *)this)) = ((CParamSuper const &)_Other);\
					return *this;\
				}\
				TCBindExpressionZeroCall &operator =(TCBindExpressionZeroCall volatile &_Other)\
				{\
					(*((CParamSuper *)this)) = ((CParamSuper volatile &)_Other);\
					return *this;\
				}\
				TCBindExpressionZeroCall &operator =(TCBindExpressionZeroCall const volatile &_Other)\
				{\
					(*((CParamSuper *)this)) = ((CParamSuper const volatile &)_Other);\
					return *this;\
				}

#			define DMibTemp_ImplementCommonSecond \
				template <typename tf_C0, typename tf_C1, typename tf_C2, typename tf_C3, typename tf_C4, typename tf_C5, typename tf_C6>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2, tf_C3 &&_P3, tf_C4 &&_P4, tf_C5 &&_P5, tf_C6 &&_P6)\
					: CParamSuper\
					(\
						fg_Forward<tf_C0>(_P0)\
						, fg_Forward<tf_C1>(_P1)\
						, fg_Forward<tf_C2>(_P2)\
						, fg_Forward<tf_C3>(_P3)\
						, fg_Forward<tf_C4>(_P4)\
						, fg_Forward<tf_C5>(_P5)\
						, fg_Forward<tf_C6>(_P6)\
					)\
				{\
				}\
				template <typename tf_C0, typename tf_C1, typename tf_C2, typename tf_C3, typename tf_C4, typename tf_C5, typename tf_C6, typename tf_C7>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2, tf_C3 &&_P3, tf_C4 &&_P4, tf_C5 &&_P5, tf_C6 &&_P6, tf_C7 &&_P7)\
					: CParamSuper\
					(\
						fg_Forward<tf_C0>(_P0)\
						, fg_Forward<tf_C1>(_P1)\
						, fg_Forward<tf_C2>(_P2)\
						, fg_Forward<tf_C3>(_P3)\
						, fg_Forward<tf_C4>(_P4)\
						, fg_Forward<tf_C5>(_P5)\
						, fg_Forward<tf_C6>(_P6)\
						, fg_Forward<tf_C7>(_P7)\
					)\
				{\
				}\
				template <typename tf_C0, typename tf_C1, typename tf_C2, typename tf_C3, typename tf_C4, typename tf_C5, typename tf_C6, typename tf_C7, typename tf_C8>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2, tf_C3 &&_P3, tf_C4 &&_P4, tf_C5 &&_P5, tf_C6 &&_P6, tf_C7 &&_P7, tf_C8 &&_P8)\
					: CParamSuper\
					(\
						fg_Forward<tf_C0>(_P0)\
						, fg_Forward<tf_C1>(_P1)\
						, fg_Forward<tf_C2>(_P2)\
						, fg_Forward<tf_C3>(_P3)\
						, fg_Forward<tf_C4>(_P4)\
						, fg_Forward<tf_C5>(_P5)\
						, fg_Forward<tf_C6>(_P6)\
						, fg_Forward<tf_C7>(_P7)\
						, fg_Forward<tf_C8>(_P8)\
					)\
				{\
				}\
				template <typename tf_C0, typename tf_C1, typename tf_C2, typename tf_C3, typename tf_C4, typename tf_C5, typename tf_C6, typename tf_C7, typename tf_C8, typename tf_C9>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2, tf_C3 &&_P3, tf_C4 &&_P4, tf_C5 &&_P5, tf_C6 &&_P6, tf_C7 &&_P7, tf_C8 &&_P8, tf_C9 &&_P9)\
					: CParamSuper\
					(\
						fg_Forward<tf_C0>(_P0)\
						, fg_Forward<tf_C1>(_P1)\
						, fg_Forward<tf_C2>(_P2)\
						, fg_Forward<tf_C3>(_P3)\
						, fg_Forward<tf_C4>(_P4)\
						, fg_Forward<tf_C5>(_P5)\
						, fg_Forward<tf_C6>(_P6)\
						, fg_Forward<tf_C7>(_P7)\
						, fg_Forward<tf_C8>(_P8)\
						, fg_Forward<tf_C9>(_P9)\
					)\
				{\
				}\
				template \
				<\
					typename tf_C0\
					, typename tf_C1\
					, typename tf_C2\
					, typename tf_C3\
					, typename tf_C4\
					, typename tf_C5\
					, typename tf_C6\
					, typename tf_C7\
					, typename tf_C8\
					, typename tf_C9\
					, typename tf_C10\
				>\
				TCBindExpressionZeroCall(tf_C0 &&_P0, tf_C1 &&_P1, tf_C2 &&_P2, tf_C3 &&_P3, tf_C4 &&_P4, tf_C5 &&_P5, tf_C6 &&_P6, tf_C7 &&_P7, tf_C8 &&_P8, tf_C9 &&_P9, tf_C10 &&_P10)\
					: CParamSuper\
					(\
						fg_Forward<tf_C0>(_P0)\
						, fg_Forward<tf_C1>(_P1)\
						, fg_Forward<tf_C2>(_P2)\
						, fg_Forward<tf_C3>(_P3)\
						, fg_Forward<tf_C4>(_P4)\
						, fg_Forward<tf_C5>(_P5)\
						, fg_Forward<tf_C6>(_P6)\
						, fg_Forward<tf_C7>(_P7)\
						, fg_Forward<tf_C8>(_P8)\
						, fg_Forward<tf_C9>(_P9)\
						, fg_Forward<tf_C10>(_P10)\
					)\
				{\
				}

#ifndef DMibRestrictNumberOfBindParams
#			define DMibTemp_ImplementCommon \
					DMibTemp_ImplementCommonFirst \
					DMibTemp_ImplementCommonSecond
#else
#			define DMibTemp_ImplementCommon \
					DMibTemp_ImplementCommonFirst
#endif

#ifndef DMibRestrictNumberOfBindParams
#			define DMibTemp_ImplementCallOperator(_Qualifiers, _QualifiersCap) \
				auto operator () () _Qualifiers \
				-> \
				decltype\
				(\
					TCCallBindExpression<TCGetFinalParamNumber<CParamSuper, 0>::mc_Value>::fs_Call\
					(\
						fg_GetReference<_Qualifiers CToBind>()\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 0>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 1>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 2>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 3>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 4>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 5>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 6>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 7>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 8>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 9>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
					)\
				)\
				{\
					return TCCallBindExpression<TCGetFinalParamNumber<CParamSuper, 0>::mc_Value>::fs_Call\
						(\
							this->fp_BoundObject()\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 0>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 1>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 2>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 3>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 4>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 5>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 6>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 7>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 8>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 9>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil(), CNil())\
						)\
						;\
				}
#else
#			define DMibTemp_ImplementCallOperator(_Qualifiers, _QualifiersCap) \
				auto operator () () _Qualifiers \
				-> \
				decltype\
				(\
					TCCallBindExpression<TCGetFinalParamNumber<CParamSuper, 0>::mc_Value>::fs_Call\
					(\
						fg_GetReference<_Qualifiers CToBind>()\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 0>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 1>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 2>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 3>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil())\
						, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 4>::fs_Param(fg_GetReference<_Qualifiers CParamSuper>(), CNil(), CNil(), CNil(), CNil(), CNil())\
					)\
				)\
				{\
					return TCCallBindExpression<TCGetFinalParamNumber<CParamSuper, 0>::mc_Value>::fs_Call\
						(\
							this->fp_BoundObject()\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 0>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 1>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 2>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 3>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil())\
							, TCGetBindParam<0, 0, _Qualifiers CParamSuper, 4>::fs_Param(fp_GetSuper(), CNil(), CNil(), CNil(), CNil(), CNil())\
						)\
						;\
				}
#endif

			template
			<
				typename t_CBFOpts
				, bint t_bFullyBound = !TCGetBindExpressionUsedParams<TCBindExpressionParam<t_CBFOpts>, 0, 0>::mc_UsedParams
			>
			struct TCEvalCallability
			{
				static const bint mc_HasEmptyFunction = false;
				static const bint mc_HasEmptyFunctionConst = false;
				static const bint mc_HasEmptyFunctionVolatile = false;
				static const bint mc_HasEmptyFunctionConstVolatile = false;
			};
			
			template
			<
				typename t_CBFOpts
			>
			struct TCEvalCallability<t_CBFOpts, true>
			{
				static const bint mc_HasEmptyFunction = NTraits::TCIsCallableWith<typename t_CBFOpts::CToBind, typename t_CBFOpts::CBoundParamsFunc>::mc_Value;
				static const bint mc_HasEmptyFunctionConst = NTraits::TCIsCallableWith<typename t_CBFOpts::CToBind const, typename t_CBFOpts::CBoundParamsFuncConst>::mc_Value;
				static const bint mc_HasEmptyFunctionVolatile = NTraits::TCIsCallableWith<typename t_CBFOpts::CToBind volatile, typename t_CBFOpts::CBoundParamsFuncVolatile>::mc_Value;
				static const bint mc_HasEmptyFunctionConstVolatile = NTraits::TCIsCallableWith<typename t_CBFOpts::CToBind const volatile, typename t_CBFOpts::CBoundParamsFuncConstVolatile>::mc_Value;
			};
				
			template 
			<
				typename t_CBFOpts
				, bint t_bHasEmptyFunction = TCEvalCallability<t_CBFOpts>::mc_HasEmptyFunction
				, bint t_bHasEmptyFunctionConst = TCEvalCallability<t_CBFOpts>::mc_HasEmptyFunctionConst
				, bint t_bHasEmptyFunctionVolatile = TCEvalCallability<t_CBFOpts>::mc_HasEmptyFunctionVolatile
				, bint t_bHasEmptyFunctionConstVolatile = TCEvalCallability<t_CBFOpts>::mc_HasEmptyFunctionConstVolatile
			>
			struct TCBindExpressionZeroCall 
				: public TCBindExpressionParam<t_CBFOpts>
			{
				DMibTemp_ImplementCommon;

			};


			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, true, true, true, true> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(,);
				DMibTemp_ImplementCallOperator(const,Const);
				DMibTemp_ImplementCallOperator(volatile,Volatile);
				DMibTemp_ImplementCallOperator(const volatile,ConstVolatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, false, true, true, true> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(const,Const);
				DMibTemp_ImplementCallOperator(volatile,Volatile);
				DMibTemp_ImplementCallOperator(const volatile,ConstVolatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, true, false, true, true> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(,);
				DMibTemp_ImplementCallOperator(volatile,Volatile);
				DMibTemp_ImplementCallOperator(const volatile,ConstVolatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, true, true, false, true> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(,);
				DMibTemp_ImplementCallOperator(const,Const);
				DMibTemp_ImplementCallOperator(const volatile,ConstVolatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, true, true, true, false> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(,);
				DMibTemp_ImplementCallOperator(const,Const);
				DMibTemp_ImplementCallOperator(volatile,Volatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, false, false, true, true> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(volatile,Volatile);
				DMibTemp_ImplementCallOperator(const volatile,ConstVolatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, false, true, false, true> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(const,Const);
				DMibTemp_ImplementCallOperator(const volatile,ConstVolatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, false, true, true, false> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(const,Const);
				DMibTemp_ImplementCallOperator(volatile,Volatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, true, false, false, true> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(,);
				DMibTemp_ImplementCallOperator(const volatile,ConstVolatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, true, false, true, false> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(,);
				DMibTemp_ImplementCallOperator(volatile,Volatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, true, true, false, false> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(,);
				DMibTemp_ImplementCallOperator(const,Const);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, true, false, false, false> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(,);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, false, true, false, false> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(const,Const);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, false, false, true, false> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(volatile,Volatile);
			};
			template <typename t_CBFOpts>
			class TCBindExpressionZeroCall<t_CBFOpts, false, false, false, true> 
				: public TCBindExpressionParam<t_CBFOpts>
			{
			public:

				DMibTemp_ImplementCommon;
				DMibTemp_ImplementCallOperator(const volatile,ConstVolatile);
			};

#			undef DMibTemp_ImplementCallOperator
#			undef DMibTemp_ImplementCommon
		}
	}
}

