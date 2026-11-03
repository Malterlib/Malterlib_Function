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
		TCMergedFunctors(tf_CFirstFunctor &&_FirstFunctor, tfp_CFunctors ...p_Functors);
	};

	template <typename t_CFirstFunctor>
	struct TCMergedFunctors<t_CFirstFunctor> : public t_CFirstFunctor
	{
		using t_CFirstFunctor::operator ();

		TCMergedFunctors(t_CFirstFunctor _FirstFunctor);
	};
}

#include "Malterlib_Function_MergeFunctors.hpp"
