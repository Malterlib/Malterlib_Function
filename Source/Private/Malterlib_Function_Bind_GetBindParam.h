// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include "Malterlib_Function_Bind_ResolveBindParam.h"

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
			template <mint t_Level, mint t_nInParams, typename t_CImplementation, int t_iParam, int32 t_HighestUsedParam, int t_nParams>
			struct TCGetBindParam<t_Level, t_nInParams, t_CImplementation, t_iParam, t_HighestUsedParam, t_nParams, false> 
				: public TCGetBindParamDefault<t_iParam + (t_HighestUsedParam - t_CImplementation::CBindOptions::mc_NumParams)>
			{
			};

			template <mint t_Level, mint t_nInParams, typename t_CImplementation, int t_iParam, int32 t_HighestUsedParam, int t_nParams>
			struct TCGetBindParam<t_Level, t_nInParams, t_CImplementation, t_iParam, t_HighestUsedParam, t_nParams, true>
			{
				typedef TCGetBindExpressionStoredParam<typename NTraits::TCRemoveQualifiers<t_CImplementation>::CType, t_iParam> CStoredParamResolver;
				typedef typename NTraits::TCCopyQualifiers<t_CImplementation, typename CStoredParamResolver::CType>::CType CBoundTypeRaw;
				typedef typename NTraits::TCRemoveReference<CBoundTypeRaw>::CType CBoundType;

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
				static typename TCResolveBindParamResult
				<
					t_Level
					, t_nInParams
					, t_HighestUsedParam
					, typename NTraits::TCCopyReference<tf_CObject, CBoundTypeRaw>::CType
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
				fs_Param
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
				{
					static_assert(NTraits::TCIsConst<CBoundTypeRaw>::mc_Value == NTraits::TCIsConst<typename NTraits::TCRemoveReference<tf_CObject>::CType>::mc_Value, "Must be");
					static_assert(NTraits::TCIsVolatile<CBoundTypeRaw>::mc_Value == NTraits::TCIsVolatile<typename NTraits::TCRemoveReference<tf_CObject>::CType>::mc_Value, "Must be");
					return fg_ResolveBindParam<t_Level, t_nInParams, t_HighestUsedParam>
						(
							CStoredParamResolver::fs_Get(_Object)
							, fg_Forward<tf_CP0>(_P0)
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
			};
		}
	}
}

