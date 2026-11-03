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

	template <typename tf_FMemberFunctionPointer>
	bool fg_IsVirtualCall(tf_FMemberFunctionPointer _fFunctionPointer)
		requires (NTraits::cIsMemberFunctionPointer<tf_FMemberFunctionPointer>)
	{
		return NPrivate::fg_IsVirtualCallImpl((void *)&_fFunctionPointer);
	}
}

#endif
