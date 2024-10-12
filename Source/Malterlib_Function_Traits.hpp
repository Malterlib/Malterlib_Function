// Copyright © 2024 Favro Holding AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

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
		requires (NTraits::TCIsMemberFunctionPointer<tf_CMemberFunctionPointer>::mc_Value)
	{
		return NPrivate::fg_IsVirtualCallImpl((void *)&_pFunctionPointer);
	}
}

#endif
