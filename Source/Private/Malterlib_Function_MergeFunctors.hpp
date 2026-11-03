// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFirstFunctor, typename ...tp_CFunctors>
	template <typename tf_CFirstFunctor, typename ...tfp_CFunctors>
	TCMergedFunctors<t_CFirstFunctor, tp_CFunctors...>::TCMergedFunctors(tf_CFirstFunctor &&_FirstFunctor, tfp_CFunctors ...p_Functors)
		: t_CFirstFunctor(fg_Forward<tf_CFirstFunctor>(_FirstFunctor))
		, TCMergedFunctors<tp_CFunctors...>(fg_Forward<tfp_CFunctors>(p_Functors)...)
	{
	}

	template <typename t_CFirstFunctor>
	TCMergedFunctors<t_CFirstFunctor>::TCMergedFunctors(t_CFirstFunctor _FirstFunctor)
		: t_CFirstFunctor(_FirstFunctor)
	{
	}
}
