// Copyright © 2024 Favro Holding AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include <Mib/Type/Traits>

#ifndef DPlatformFamily_Windows
// You need to parse byte code thunks on Windows to detect virtual function pointers. Leave unimplemented for now

#define DMibCanDetectVirtualMemberFunctions_Dynamic

namespace NMib::NFunction
{
	template <typename tf_CMemberFunctionPointer>
	bool fg_IsVirtualCall(tf_CMemberFunctionPointer _pFunctionPointer)
		requires (NTraits::cIsMemberFunctionPointer<tf_CMemberFunctionPointer>)
	;
}

#ifndef DMibPNoShortCuts
	using namespace NMib::NFunction;
#endif

#include "Malterlib_Function_Traits.hpp"

#endif
