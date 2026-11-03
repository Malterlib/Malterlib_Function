// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CParamType>
	template <typename tf_CType>
	inline_small auto TCGetReferenceType<t_CParamType>::fs_Forward(tf_CType &&_Type) -> CType
	{
		return static_cast<CType>(_Type);
	}
}
