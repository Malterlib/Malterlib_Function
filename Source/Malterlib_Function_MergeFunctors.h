// Copyright © 2018 Nonna Holding AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include "Private/Malterlib_Function_MergeFunctors.h"

namespace NMib::NFunction
{
	template <class ...tfp_FToMerge>
	auto fg_MergeFunctors(tfp_FToMerge &&...p_fToMerge)
	{
		using CMergedFunctors = NPrivate::TCMergedFunctors<NTraits::TCDecay<tfp_FToMerge>...>;
		return CMergedFunctors(fg_Forward<tfp_FToMerge>(p_fToMerge)...);
	};
}

#ifndef DMibPNoShortCuts
	using namespace NMib::NFunction;
#endif
