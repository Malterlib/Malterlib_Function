// Copyright © 2024 Favro Holding AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#ifndef DPlatformFamily_Windows

#include "Malterlib_Function_Traits.h"

namespace NMib::NFunction::NPrivate
{
	namespace
	{
		struct CMemberPointerStruct
		{
			umint m_Pointer;
			umint m_Adjustment;
		};
	}

	bool fg_IsVirtualCallImpl(void *_pMemberFunctionPointer)
	{
		CMemberPointerStruct *pMemberPointer = static_cast<CMemberPointerStruct *>(_pMemberFunctionPointer);

#if defined(DArchitecture_arm) || defined(DArchitecture_arm64) || defined(DArchitecture_arm64e)
		if (pMemberPointer->m_Adjustment & 1)
			return true;
#else
		if (pMemberPointer->m_Pointer & 1)
			return true;
#endif

		return false;
	}
}

#endif
