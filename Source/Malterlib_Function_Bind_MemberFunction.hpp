// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction
{
	template <typename t_FFunctionMemberPointer>
	TCMemberFunctionFunctor<t_FFunctionMemberPointer>::TCMemberFunctionFunctor(TCMemberFunctionFunctor &_fOther)
		: mp_fFunction(_fOther.mp_fFunction)
	{
	}

	template <typename t_FFunctionMemberPointer>
	TCMemberFunctionFunctor<t_FFunctionMemberPointer>::TCMemberFunctionFunctor(TCMemberFunctionFunctor const &_fOther)
		: mp_fFunction(_fOther.mp_fFunction)
	{
	}

	template <typename t_FFunctionMemberPointer>
	TCMemberFunctionFunctor<t_FFunctionMemberPointer>::TCMemberFunctionFunctor(TCMemberFunctionFunctor &&_fOther)
		: mp_fFunction(fg_Move(_fOther.mp_fFunction))
	{
	}

	template <typename t_FFunctionMemberPointer>
	auto TCMemberFunctionFunctor<t_FFunctionMemberPointer>::operator = (TCMemberFunctionFunctor &_fOther) -> TCMemberFunctionFunctor &
	{
		mp_fFunction = _fOther.mp_fFunction;
		return *this;
	}

	template <typename t_FFunctionMemberPointer>
	auto TCMemberFunctionFunctor<t_FFunctionMemberPointer>::operator = (TCMemberFunctionFunctor const &_fOther) -> TCMemberFunctionFunctor &
	{
		mp_fFunction = _fOther.mp_fFunction;
		return *this;
	}

	template <typename t_FFunctionMemberPointer>
	auto TCMemberFunctionFunctor<t_FFunctionMemberPointer>::operator = (TCMemberFunctionFunctor &&_fOther) -> TCMemberFunctionFunctor &
	{
		mp_fFunction = fg_Move(_fOther.mp_fFunction);
		return *this;
	}

	template <typename t_FFunctionMemberPointer>
	template <typename tf_CFunctionPointer>
	mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor<t_FFunctionMemberPointer>::TCMemberFunctionFunctor(tf_CFunctionPointer &&_P0)
		: mp_fFunction(fg_Forward<tf_CFunctionPointer>(_P0))
	{
	}

	template <typename t_FFunctionMemberPointer>
	template <typename tf_CFunctionPointer>
	mark_artificial mark_nodebug inline_always auto TCMemberFunctionFunctor<t_FFunctionMemberPointer>::operator = (tf_CFunctionPointer &&_P0) -> TCMemberFunctionFunctor &
	{
		mp_fFunction = fg_Forward<tf_CFunctionPointer>(_P0);
		return *this;
	}

	template <typename t_FFunctionMemberPointer>
	template <typename ...tfp_CParams>
	mark_artificial inline_always auto TCMemberFunctionFunctor<t_FFunctionMemberPointer>::operator () (CClass &_Reference, tfp_CParams && ...p_Params) const -> CReturn
	{
		return (_Reference.*fg_RemoveQualifiers(mp_fFunction))(fg_Forward<tfp_CParams>(p_Params)...);
	}

	template <typename t_FFunctionMemberPointer>
	template <typename ...tfp_CParams>
	mark_artificial inline_always auto TCMemberFunctionFunctor<t_FFunctionMemberPointer>::operator () (CClass const &_Reference, tfp_CParams && ...p_Params) const -> CReturn
	{
		return (_Reference.*fg_RemoveQualifiers(mp_fFunction))(fg_Forward<tfp_CParams>(p_Params)...);
	}

	template <typename t_FFunctionMemberPointer>
	template <typename tf_CPtr, typename ...tfp_CParams>
	mark_artificial inline_always auto TCMemberFunctionFunctor<t_FFunctionMemberPointer>::operator () (tf_CPtr &&_Object, tfp_CParams && ...p_Params) const -> CReturn
	{
		return (_Object->*fg_RemoveQualifiers(mp_fFunction))(fg_Forward<tfp_CParams>(p_Params)...);
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor &_fOther)
		: mp_fFunction(_fOther.mp_fFunction)
		, mp_pThis(_fOther.mp_pThis)
	{
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor const &_fOther)
		: mp_fFunction(_fOther.mp_fFunction)
		, mp_pThis(_fOther.mp_pThis)
	{
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor &&_fOther)
		: mp_fFunction(fg_Move(_fOther.mp_fFunction))
		, mp_pThis(fg_Move(_fOther.mp_pThis))
	{
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	auto TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::operator = (TCMemberFunctionBoundFunctor &_fOther) -> TCMemberFunctionBoundFunctor &
	{
		mp_fFunction = _fOther.mp_fFunction;
		mp_pThis = _fOther.mp_pThis;
		return *this;
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	auto TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::operator = (TCMemberFunctionBoundFunctor const &_fOther) -> TCMemberFunctionBoundFunctor &
	{
		mp_fFunction = _fOther.mp_fFunction;
		mp_pThis = _fOther.mp_pThis;
		return *this;
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	auto TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::operator = (TCMemberFunctionBoundFunctor &&_fOther) -> TCMemberFunctionBoundFunctor &
	{
		mp_fFunction = fg_Move(_fOther.mp_fFunction);
		mp_pThis = fg_Move(_fOther.mp_pThis);
		return *this;
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	template <typename tf_CFunctionPointer, typename tf_CThis>
	mark_artificial mark_nodebug inline_always TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::TCMemberFunctionBoundFunctor(tf_CFunctionPointer &&_P0, tf_CThis &&_P1)
		: mp_fFunction(fg_Forward<tf_CFunctionPointer>(_P0))
		, mp_pThis(fg_Forward<tf_CThis>(_P1))
	{
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	template <typename ...tfp_CParams>
	mark_artificial inline_always auto TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::operator () (tfp_CParams && ...p_Params) const -> CReturn
	{
		return (const_cast<t_CThis>(mp_pThis)->*fg_RemoveQualifiers(mp_fFunction))(fg_Forward<tfp_CParams>(p_Params)...);
	}

	template <typename t_FFunctionMemberPointer, typename t_CThis>
	template <typename ...tfp_CParams>
	mark_artificial inline_always auto TCMemberFunctionBoundFunctor<t_FFunctionMemberPointer, t_CThis>::operator () (tfp_CParams && ...p_Params) -> CReturn
	{
		return (mp_pThis->*mp_fFunction)(fg_Forward<tfp_CParams>(p_Params)...);
	}

	template <typename tf_FFunctionPtr>
	mark_artificial mark_nodebug inline_always auto fg_MemberFunctionFunctor(tf_FFunctionPtr _fFunction)
		-> TCEnableIf<NTraits::TCMemberFunctionPointerTraits<tf_FFunctionPtr>::mc_bIsMemberFunctionPointer, TCMemberFunctionFunctor<tf_FFunctionPtr>>
	{
		return TCMemberFunctionFunctor<tf_FFunctionPtr>(_fFunction);
	}

	template <typename tf_FFunctionPtr, typename tf_CClass>
	mark_artificial mark_nodebug inline_always auto fg_MemberFunctionFunctor(tf_FFunctionPtr _fFunction, tf_CClass _pClassPtr)
		-> TCEnableIf<NTraits::TCMemberFunctionPointerTraits<tf_FFunctionPtr>::mc_bIsMemberFunctionPointer, TCMemberFunctionBoundFunctor<tf_FFunctionPtr, tf_CClass>>
	{
		return TCMemberFunctionBoundFunctor<tf_FFunctionPtr, tf_CClass>(_fFunction, _pClassPtr);
	}
}
