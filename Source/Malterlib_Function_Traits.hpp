// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

#ifndef DPlatformFamily_Windows

namespace NMib::NFunction
{
	namespace NPrivate
	{
		bool fg_IsVirtualCallImpl(void *_pMemberFunctionPointer);
	}

	template <typename tf_CMemberFunctionPointer>
	bool fg_IsVirtualCall(tf_CMemberFunctionPointer _pFunctionPointer)
		requires (NTraits::cIsMemberFunctionPointer<tf_CMemberFunctionPointer>)
	{
		return NPrivate::fg_IsVirtualCallImpl((void *)&_pFunctionPointer);
	}
}

#endif
