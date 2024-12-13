// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NFunction::NPrivate
{
	template
	<
		typename t_CFunctor
		, typename t_CFOpts
		, typename t_CSequence = NMeta::TCConsecutiveIndices<t_CFOpts::mc_NumFunctions>
		, bool t_bSupportEqualityCompare = t_CFOpts::mc_bSupportEqualityCompare
		, bool t_bSupportOrderedCompare = t_CFOpts::mc_bSupportOrderedCompare
	>
	struct TCImplVTable;
}
