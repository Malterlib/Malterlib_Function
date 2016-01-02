// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

//#define DMibRestrictNumberOfBindParams
#ifdef DMibRestrictNumberOfBindParams
#define DMibBindMaxNumParams 5
#else
#define DMibBindMaxNumParams 10
#endif

namespace NMib
{
	namespace NFunction
	{

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Class:																							|
		|																									|
		|	Description:		Used to specify that a function should implement comparison operators		|
		|																									|
		|	Comments:			If you specify this tag the functors you put into the function has to		|
		|						support equal and less than comparison operators.							|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Classes																		|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/
		struct CBindSupportCompareTag
		{
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Class:																					|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Classes															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/
		struct CBindNoNestTag
		{
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Class:																					|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Classes															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/
		template <mint t_Level = 0>
		struct TCBindForwardExtraTag
		{
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Class:																					|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Classes															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/
		template
		<
			int32 t_iParam0 = -1
			, int32 t_iParam1 = -1
			, int32 t_iParam2 = -1
			, int32 t_iParam3 = -1
			, int32 t_iParam4 = -1
#ifndef DMibRestrictNumberOfBindParams
			, int32 t_iParam5 = -1
			, int32 t_iParam6 = -1
			, int32 t_iParam7 = -1
			, int32 t_iParam8 = -1
			, int32 t_iParam9 = -1
#endif
		>
		struct TCBindIgnoreParamsTag
		{
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Class:																					|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Classes															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/
		template <mint t_Param, mint t_Level = 0>
		struct TCBindPlaceholder
		{
			static const mint mc_Param = t_Param;
			static const mint mc_Level = t_Level;

			template <mint tf_Param, mint tf_Level>
			TCBindPlaceholder<t_Param, tf_Param> operator [] (TCBindPlaceholder<tf_Param, tf_Level>)
			{
				return TCBindPlaceholder<t_Param, tf_Param>();
			}

			bint operator == (TCBindPlaceholder const &_Other) const
			{
				return true;
			}
			bint operator < (TCBindPlaceholder const &_Other) const
			{
				return false;
			}
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Global:																							|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Globals																		|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/
		namespace 
		{
#ifdef DCompiler_clang
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wunused-variable"
#endif
		
			TCBindPlaceholder<0> g_0 = {};
			TCBindPlaceholder<1> g_1 = {};
			TCBindPlaceholder<2> g_2 = {};
			TCBindPlaceholder<3> g_3 = {};
			TCBindPlaceholder<4> g_4 = {};
#ifndef DMibRestrictNumberOfBindParams
			TCBindPlaceholder<5> g_5 = {};
			TCBindPlaceholder<6> g_6 = {};
			TCBindPlaceholder<7> g_7 = {};
			TCBindPlaceholder<8> g_8 = {};
			TCBindPlaceholder<9> g_9 = {};
#endif

#ifdef DCompiler_clang
	#pragma clang diagnostic pop
#endif
		}

	}
}

#include "Private/Malterlib_Function_Bind_Helpers.h"
#include "Private/Malterlib_Function_Bind_Options.h"
#include "Private/Malterlib_Function_Bind_Storage.h"
#include "Private/Malterlib_Function_Bind_Resolver.h"
#include "Private/Malterlib_Function_Bind_GetBindParam.h"
#include "Private/Malterlib_Function_Bind_GetBindParamDefault.h"
#include "Private/Malterlib_Function_Bind_GetBindParamResolveProperties.h"
#include "Private/Malterlib_Function_Bind_ResolveBindParam.h"
#include "Private/Malterlib_Function_Bind_ResolveBindParamResult.h"
#include "Private/Malterlib_Function_Bind_ResolverMisc.h"
#include "Private/Malterlib_Function_Bind_ZeroCall.h"
#include "Private/Malterlib_Function_Bind_CallBindExpression.h"
#include "Private/Malterlib_Function_Bind_Compare.h"
#include "Malterlib_Function_Bind_BindExpression.h"
#include "Malterlib_Function_Bind_MemberFunction.h"
#include <Mib/Storage/Reference>

namespace NMib
{
	namespace NFunction
	{
		

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Class:																					|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Classes															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/

		template <typename t_CType>
		class TCIsPlaceholder 
			: public NTraits::TCCompileTimeConstant<bint, NPrivate::TCIsBindPlaceholder<t_CType>::mc_Value>
		{
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Class:																					|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Classes															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/

		template <typename t_CType>
		class TCIsBindExpression 
			: public NTraits::TCCompileTimeConstant<bint, NPrivate::TCIsBindExpression<t_CType>::mc_Value>
		{
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Class:																					|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Classes															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/

		template <typename t_CType>
		class TCIsComparableBindExpression 
			: public NTraits::TCCompileTimeConstant
		<
			bint
			, NPrivate::TCIsBindExpression<t_CType>::mc_Value 
			&& NPrivate::TCIsBindExpression<t_CType>::mc_bComparable
		>
		{
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Class:																					|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Classes															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/

		template <typename t_CType>
		class TCIsNonComparableBindExpression 
			: public NTraits::TCCompileTimeConstant
		<
			bint
			, NPrivate::TCIsBindExpression<t_CType>::mc_Value 
			&& !NPrivate::TCIsBindExpression<t_CType>::mc_bComparable
		>
		{
		};

		/*ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯*\
		|	Template Function:																				|
		|																									|
		|	Description:		...																			|
		|																									|
		|	Comments:			.																			|
		|																									|
		|	See Also:			.																			|
		|																									|
		|	Location:			Template Functions															|
		|																									|
		|	Index:				!name																		|
		\*_________________________________________________________________________________________________*/

		template <typename tf_CToBind>
		NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType> fg_Bind(tf_CToBind &&_ToBind)
		{
			return NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType>(_ToBind);
		}

		template <typename tf_CToBind, typename tf_CP0>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
				)
				;
		}

		template <typename tf_CToBind, typename tf_CP0, typename tf_CP1>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
				)
				;
		}

		template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
				)
				;
		}

		template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType

				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
				)
				;
		}

		template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
				)
			;
		}

#ifndef DMibRestrictNumberOfBindParams
		template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
					, fg_Forward<tf_CP5>(_P5)
				)
				;
		}
		template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
				>
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
				;
		}
		template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6, typename tf_CP7>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
				>
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
				;
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
				>
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
				;
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, typename NTraits::TCDecay<tf_CP9>::CType
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8, tf_CP9 &&_P9)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, typename NTraits::TCDecay<tf_CP9>::CType
				>
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
				;
		}
#endif

		/***************************************************************************************************\
		|ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯|
		| One option																						|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		template <typename tf_COption0, typename tf_CToBind>
		NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType, tf_COption0> fg_Bind(tf_CToBind &&_ToBind)
		{
			return NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType, tf_COption0>(_ToBind);
		}

		template <typename tf_COption0, typename tf_CToBind, typename tf_CP0>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, tf_COption0
		> 
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, tf_COption0
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
				)
				;
		}

		template <typename tf_COption0, typename tf_CToBind, typename tf_CP0, typename tf_CP1>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, tf_COption0
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
				)
				;
		}

		template <typename tf_COption0, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, tf_COption0
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
				)
				;
		}

		template <typename tf_COption0, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, tf_COption0
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
				)
				;
		}

		template <typename tf_COption0, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, tf_COption0
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
				)
				;
		}

#ifndef DMibRestrictNumberOfBindParams
		template <typename tf_COption0, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, tf_COption0
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
					, fg_Forward<tf_CP5>(_P5)
				)
				;
		}
		template <typename tf_COption0, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, tf_COption0
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
			, typename tf_CP6
			, typename tf_CP7
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, tf_COption0
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_CToBind
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, tf_COption0
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_CToBind
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, typename NTraits::TCDecay<tf_CP9>::CType
			, tf_COption0
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8, tf_CP9 &&_P9)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, typename NTraits::TCDecay<tf_CP9>::CType
					, tf_COption0
				>
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
				;
		}
#endif
		/***************************************************************************************************\
		|ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯|
		| Two options																						|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		template <typename tf_COption0, typename tf_COption1, typename tf_CToBind>
		NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType, tf_COption0, tf_COption1> fg_Bind(tf_CToBind &&_ToBind)
		{
			return NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType, tf_COption0, tf_COption0>(_ToBind);
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_CToBind, typename tf_CP0>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, tf_COption0
					, tf_COption1
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_CToBind, typename tf_CP0, typename tf_CP1>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, tf_COption0
					, tf_COption1
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, tf_COption0
					, tf_COption1
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, tf_COption0
					, tf_COption1
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, tf_COption0
					, tf_COption1
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
				)
				;
		}

#ifndef DMibRestrictNumberOfBindParams

		template <typename tf_COption0, typename tf_COption1, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, tf_COption0
					, tf_COption1
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
					, fg_Forward<tf_CP5>(_P5)
				)
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
			, typename tf_CP6
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, tf_COption0
					, tf_COption1
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
			, typename tf_CP6
			, typename tf_CP7
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, tf_COption0
					, tf_COption1
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_CToBind
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, tf_COption0
					, tf_COption1
				>
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
			;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_CToBind
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, typename NTraits::TCDecay<tf_CP9>::CType
			, tf_COption0
			, tf_COption1
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8, tf_CP9 &&_P9)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, typename NTraits::TCDecay<tf_CP9>::CType
					, tf_COption0
					, tf_COption1
				>
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
			;
		}
#endif

		/***************************************************************************************************\
		|ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯|
		| Three options																						|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_CToBind>
		NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType, tf_COption0, tf_COption1, tf_COption2> fg_Bind(tf_CToBind &&_ToBind)
		{
			return NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType, tf_COption0, tf_COption1, tf_COption2>(_ToBind);
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_CToBind, typename tf_CP0>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_CToBind, typename tf_CP0, typename tf_CP1>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
				)
				;
		}

#ifndef DMibRestrictNumberOfBindParams

		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
					, fg_Forward<tf_CP5>(_P5)
				)
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
			, typename tf_CP6
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
			, typename tf_CP6
			, typename tf_CP7
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_CToBind
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
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
			;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_CToBind
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, typename NTraits::TCDecay<tf_CP9>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8, tf_CP9 &&_P9)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, typename NTraits::TCDecay<tf_CP9>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
				>
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
			;
		}
#endif

		/***************************************************************************************************\
		|ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯ï¾¯|
		| Four options																						|
		|___________________________________________________________________________________________________|
		\***************************************************************************************************/

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_COption3, typename tf_CToBind>
		NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType, tf_COption0, tf_COption1, tf_COption2, tf_COption3> fg_Bind(tf_CToBind &&_ToBind)
		{
			return NBindExpression::TCBindExpression<typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType, tf_COption0, tf_COption1, tf_COption2, tf_COption3>(_ToBind);
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_COption3, typename tf_CToBind, typename tf_CP0>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_COption3, typename tf_CToBind, typename tf_CP0, typename tf_CP1>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
				)
				;
		}

		template <typename tf_COption0, typename tf_COption1, typename tf_COption2, typename tf_COption3, typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
				)
				;
		}

		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_COption3
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
				)
				;
		}

		template
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_COption3
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
				)
				;
		}

#ifndef DMibRestrictNumberOfBindParams

		template
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_COption3
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
				(
					fg_Forward<tf_CToBind>(_ToBind)
					, fg_Forward<tf_CP0>(_P0)
					, fg_Forward<tf_CP1>(_P1)
					, fg_Forward<tf_CP2>(_P2)
					, fg_Forward<tf_CP3>(_P3)
					, fg_Forward<tf_CP4>(_P4)
					, fg_Forward<tf_CP5>(_P5)
				)
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_COption3
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
			, typename tf_CP6
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_COption3
			, typename tf_CToBind
			, typename tf_CP0
			, typename tf_CP1
			, typename tf_CP2
			, typename tf_CP3
			, typename tf_CP4
			, typename tf_CP5
			, typename tf_CP6
			, typename tf_CP7
		>
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
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
				;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_COption3
			, typename tf_CToBind
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
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
			;
		}
		template 
		<
			typename tf_COption0
			, typename tf_COption1
			, typename tf_COption2
			, typename tf_COption3
			, typename tf_CToBind
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
		NBindExpression::TCBindExpression
		<
			typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
			, typename NTraits::TCDecay<tf_CP0>::CType
			, typename NTraits::TCDecay<tf_CP1>::CType
			, typename NTraits::TCDecay<tf_CP2>::CType
			, typename NTraits::TCDecay<tf_CP3>::CType
			, typename NTraits::TCDecay<tf_CP4>::CType
			, typename NTraits::TCDecay<tf_CP5>::CType
			, typename NTraits::TCDecay<tf_CP6>::CType
			, typename NTraits::TCDecay<tf_CP7>::CType
			, typename NTraits::TCDecay<tf_CP8>::CType
			, typename NTraits::TCDecay<tf_CP9>::CType
			, tf_COption0
			, tf_COption1
			, tf_COption2
			, tf_COption3
		>
		fg_Bind(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8, tf_CP9 &&_P9)
		{
			return NBindExpression::TCBindExpression
				<
					typename NPrivate::TCDoToBindTransform<tf_CToBind>::CType
					, typename NTraits::TCDecay<tf_CP0>::CType
					, typename NTraits::TCDecay<tf_CP1>::CType
					, typename NTraits::TCDecay<tf_CP2>::CType
					, typename NTraits::TCDecay<tf_CP3>::CType
					, typename NTraits::TCDecay<tf_CP4>::CType
					, typename NTraits::TCDecay<tf_CP5>::CType
					, typename NTraits::TCDecay<tf_CP6>::CType
					, typename NTraits::TCDecay<tf_CP7>::CType
					, typename NTraits::TCDecay<tf_CP8>::CType
					, typename NTraits::TCDecay<tf_CP9>::CType
					, tf_COption0
					, tf_COption1
					, tf_COption2
					, tf_COption3
				>
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
			;
		}
#endif


	}
}


#include "Malterlib_Function_Bind_Operators.h"

