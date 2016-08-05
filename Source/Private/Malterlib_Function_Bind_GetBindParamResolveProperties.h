// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
			template <mint t_Level, mint t_nInParams, typename t_CImplementation, int t_iParam, int t_nParams>
			struct TCGetBindParamResolveProperties<t_Level, t_nInParams, t_CImplementation, t_iParam, t_nParams, false> 
			{
				static constexpr uint32 mc_UsedParams = t_iParam < t_nParams ? DMibBitTyped(t_iParam, uint32) : 0;
				static constexpr bint mc_bOtherLevelParams = false;
				static constexpr bint mc_bForwardExtra = false;
			};

			template <mint t_Level, mint t_nInParams, typename t_CImplementation, int t_iParam, int t_nParams>
			struct TCGetBindParamResolveProperties<t_Level, t_nInParams, t_CImplementation, t_iParam, t_nParams, true>
			{
				typedef TCGetBindExpressionStoredParam<typename NTraits::TCRemoveQualifiers<t_CImplementation>::CType, t_iParam> CStoredParamResolver;
				typedef typename NTraits::TCCopyQualifiers<t_CImplementation, typename CStoredParamResolver::CType>::CType CBoundTypeRaw;
				typedef typename NTraits::TCRemoveReference<CBoundTypeRaw>::CType CBoundType;

				static constexpr uint32 mc_UsedParams 
					= 
					(
						TCIsBindPlaceholder<CBoundType>::mc_Value && TCIsBindPlaceholder<CBoundType>::mc_Level == t_Level
						? DMibBitTyped(TCIsBindPlaceholder<CBoundType>::mc_Param, uint32) 
						: 0
					)
					| TCGetBindExpressionUsedParams<CBoundType, t_Level + 1, t_nInParams>::mc_UsedParams
				;

				static constexpr bint mc_bOtherLevelParams
					=
					(
						(
							TCIsBindPlaceholder<CBoundType>::mc_Value 
							&& TCIsBindPlaceholder<CBoundType>::mc_Level != t_Level
						)
						|| TCGetBindExpressionUsedParams<CBoundType, t_Level + 1, t_nInParams>::mc_bOtherLevelParams
					)
				;

				static constexpr bint mc_bForwardExtra
					=
					(
						TCGetBindExpressionUsedParams<CBoundType, t_Level, t_nInParams>::mc_bForwardExtra
					)
				;
			};

		}
	}
}

