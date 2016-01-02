// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{

			template 
			<
				typename t_CFunctor
				, typename t_CFOpts
				, typename t_CSequence = typename NMeta::TCMakeConsecutiveIndices<t_CFOpts::mc_NumFunctions>::CType
				, bint t_bSupportCompare = t_CFOpts::mc_bSupportCompare
			>
			struct TCImplVTable;

			template <typename t_CFunctor, typename t_CFOpts, mint... tp_Indicies>
			struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, false>
			{
				typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
				typedef typename CFunctionDefinition::CVTable CVTable;
				static CVTable ms_VTable;
			};
			template <typename t_CFunctor, typename t_CFOpts, mint... tp_Indicies>
			struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, true>
			{
				typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
				typedef typename CFunctionDefinition::CVTable CVTable;
				static CVTable ms_VTable;
			};
		}
	}
}

