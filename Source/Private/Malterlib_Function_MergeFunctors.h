// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename ...tp_CFunctors>
	struct TCMergedFunctors;

	template <typename t_CFirstFunctor, typename ...tp_CFunctors>
	struct TCMergedFunctors<t_CFirstFunctor, tp_CFunctors...>
		: public TCMergedFunctors<tp_CFunctors...>
		, public t_CFirstFunctor
	{

		using t_CFirstFunctor::operator ();
		using TCMergedFunctors<tp_CFunctors...>::operator ();

		template <typename tf_CFirstFunctor, typename ...tfp_CFunctors>
		TCMergedFunctors(tf_CFirstFunctor &&_FirstFunctor, tfp_CFunctors ...p_Functors)
			: t_CFirstFunctor(fg_Forward<tf_CFirstFunctor>(_FirstFunctor))
			, TCMergedFunctors<tp_CFunctors...>(fg_Forward<tfp_CFunctors>(p_Functors)...)
		{
		}
	};

	template<typename t_CFirstFunctor>
	struct TCMergedFunctors<t_CFirstFunctor> : public t_CFirstFunctor
	{
		using t_CFirstFunctor::operator ();

		TCMergedFunctors(t_CFirstFunctor l1)
			: t_CFirstFunctor(l1)
		{
		}
	};
}
