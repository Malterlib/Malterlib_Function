// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction
{
	/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
	|	Template Class:																					|
	|																									|
	|	Description:		...																			|
	|																									|
	|	Comments:			.																			|
	|																									|
	|	See Also:			.																			|
	|																									|
	|	Location:			Template Classes															|
	|																									|
	|	Index:				!name																		|
	\*_________________________________________________________________________________________________*/
	template <typename t_FFunctionMemberPointer>
	struct TCMemberFunctionFunctor
	{
	private:
		// Declared before the public section, which uses them.
		using CReturn = typename NTraits::TCMemberFunctionPointerTraits<t_FFunctionMemberPointer>::CReturn;
		using CClass = typename NTraits::TCMemberFunctionPointerTraits<t_FFunctionMemberPointer>::CClass;

	public: // NOLINT(malterlib-member-order): the public declarations use CReturn and CClass
		TCMemberFunctionFunctor(TCMemberFunctionFunctor &_fOther);
		TCMemberFunctionFunctor(TCMemberFunctionFunctor const &_fOther);
		TCMemberFunctionFunctor(TCMemberFunctionFunctor &&_fOther);

		template <typename tf_CFunctionPointer>
		mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor(tf_CFunctionPointer &&_P0);

		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor &_fOther);
		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor const &_fOther);
		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor &&_fOther);

		template <typename tf_CFunctionPointer>
		mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor &operator = (tf_CFunctionPointer &&_P0);

		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (CClass &_Reference, tfp_CParams && ...p_Params) const;

		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (CClass const &_Reference, tfp_CParams && ...p_Params) const;

		template <typename tf_CPtr, typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tf_CPtr &&_Object, tfp_CParams && ...p_Params) const;

	private:
		t_FFunctionMemberPointer mp_fFunction;
	};

	/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
	|	Template Class:																					|
	|																									|
	|	Description:		...																			|
	|																									|
	|	Comments:			.																			|
	|																									|
	|	See Also:			.																			|
	|																									|
	|	Location:			Template Classes															|
	|																									|
	|	Index:				!name																		|
	\*_________________________________________________________________________________________________*/

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	struct TCMemberFunctionBoundFunctor
	{
	private:
		// Declared before the public section, which uses it.
		using CReturn = typename NTraits::TCMemberFunctionPointerTraits<t_FFunctionMemberPointer>::CReturn;

	public: // NOLINT(malterlib-member-order): the public declarations use CReturn
		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor &_fOther);
		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor const &_fOther);
		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor &&_fOther);

		template <typename tf_CFunctionPointer, typename tf_CThis>
		mark_artificial mark_nodebug inline_always TCMemberFunctionBoundFunctor(tf_CFunctionPointer &&_P0, tf_CThis &&_P1);

		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor &_fOther);
		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor const &_fOther);
		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor &&_fOther);

		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tfp_CParams && ...p_Params) const;

		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tfp_CParams && ...p_Params);

	private:
		t_FFunctionMemberPointer mp_fFunction;
		t_CThis mp_pThis;
	};

	/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
	|	Template Function:																				|
	|																									|
	|	Description:		...																			|
	|																									|
	|	Comments:			.																			|
	|																									|
	|	See Also:			.																			|
	|																									|
	|	Location:			Template Functions															|
	|																									|
	|	Index:				!name																		|
	\*_________________________________________________________________________________________________*/
	template <typename tf_FFunctionPtr>
	mark_artificial mark_nodebug inline_always auto fg_MemberFunctionFunctor(tf_FFunctionPtr _fFunction)
		-> TCEnableIf<NTraits::TCMemberFunctionPointerTraits<tf_FFunctionPtr>::mc_bIsMemberFunctionPointer, TCMemberFunctionFunctor<tf_FFunctionPtr>>
	;

	/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
	|	Template Class:																					|
	|																									|
	|	Description:		...																			|
	|																									|
	|	Comments:			.																			|
	|																									|
	|	See Also:			.																			|
	|																									|
	|	Location:			Template Classes															|
	|																									|
	|	Index:				!name																		|
	\*_________________________________________________________________________________________________*/
	template <typename tf_FFunctionPtr, typename tf_CClass>
	mark_artificial mark_nodebug inline_always auto fg_MemberFunctionFunctor(tf_FFunctionPtr _fFunction, tf_CClass _pClassPtr)
		-> TCEnableIf<NTraits::TCMemberFunctionPointerTraits<tf_FFunctionPtr>::mc_bIsMemberFunctionPointer, TCMemberFunctionBoundFunctor<tf_FFunctionPtr, tf_CClass>>
	;
}

#ifndef DMibPNoShortCuts
using namespace NMib::NFunction;
#endif

#include "Malterlib_Function_Bind_MemberFunction.hpp"
