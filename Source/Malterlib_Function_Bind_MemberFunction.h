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
		using CReturn = typename NTraits::TCMemberFunctionPointerTraits<t_FFunctionMemberPointer>::CReturn;
		using CClass = typename NTraits::TCMemberFunctionPointerTraits<t_FFunctionMemberPointer>::CClass;

	public:
		TCMemberFunctionFunctor(TCMemberFunctionFunctor &_fOther)
			: mp_fFunction(_fOther.mp_fFunction)
		{
		}

		TCMemberFunctionFunctor(TCMemberFunctionFunctor const &_fOther)
			: mp_fFunction(_fOther.mp_fFunction)
		{
		}

		TCMemberFunctionFunctor(TCMemberFunctionFunctor &&_fOther)
			: mp_fFunction(fg_Move(_fOther.mp_fFunction))
		{
		}

		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor &_fOther)
		{
			mp_fFunction = _fOther.mp_fFunction;
			return *this;
		}

		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor const &_fOther)
		{
			mp_fFunction = _fOther.mp_fFunction;
			return *this;
		}

		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor &&_fOther)
		{
			mp_fFunction = fg_Move(_fOther.mp_fFunction);
			return *this;
		}

		template <typename tf_CFunctionPointer>
		mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor(tf_CFunctionPointer &&_P0)
			: mp_fFunction(fg_Forward<tf_CFunctionPointer>(_P0))
		{
		}

		template <typename tf_CFunctionPointer>
		mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor &operator = (tf_CFunctionPointer &&_P0)
		{
			mp_fFunction = fg_Forward<tf_CFunctionPointer>(_P0);
			return *this;
		}

	public:
		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (CClass &_Reference, tfp_CParams && ...p_Params) const
		{
			return (_Reference.*fg_RemoveQualifiers(mp_fFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (CClass const &_Reference, tfp_CParams && ...p_Params) const
		{
			return (_Reference.*fg_RemoveQualifiers(mp_fFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

		template <typename tf_CPtr, typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tf_CPtr &&_Object, tfp_CParams && ...p_Params) const
		{
			return (_Object->*fg_RemoveQualifiers(mp_fFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

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
		using CReturn = typename NTraits::TCMemberFunctionPointerTraits<t_FFunctionMemberPointer>::CReturn;

	public:
		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor &_fOther)
			: mp_fFunction(_fOther.mp_fFunction)
			, mp_pThis(_fOther.mp_pThis)
		{
		}

		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor const &_fOther)
			: mp_fFunction(_fOther.mp_fFunction)
			, mp_pThis(_fOther.mp_pThis)
		{
		}

		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor &&_fOther)
			: mp_fFunction(fg_Move(_fOther.mp_fFunction))
			, mp_pThis(fg_Move(_fOther.mp_pThis))
		{
		}

		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor &_fOther)
		{
			mp_fFunction = _fOther.mp_fFunction;
			mp_pThis = _fOther.mp_pThis;
			return *this;
		}

		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor const &_fOther)
		{
			mp_fFunction = _fOther.mp_fFunction;
			mp_pThis = _fOther.mp_pThis;
			return *this;
		}

		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor &&_fOther)
		{
			mp_fFunction = fg_Move(_fOther.mp_fFunction);
			mp_pThis = fg_Move(_fOther.mp_pThis);
			return *this;
		}

		template <typename tf_CFunctionPointer, typename tf_CThis>
		mark_artificial mark_nodebug inline_always TCMemberFunctionBoundFunctor(tf_CFunctionPointer &&_P0, tf_CThis &&_P1)
			: mp_fFunction(fg_Forward<tf_CFunctionPointer>(_P0))
			, mp_pThis(fg_Forward<tf_CThis>(_P1))
		{
		}

	public:
		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tfp_CParams && ...p_Params) const
		{
			return (const_cast<t_CThis>(mp_pThis)->*fg_RemoveQualifiers(mp_fFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tfp_CParams && ...p_Params)
		{
			return (mp_pThis->*mp_fFunction)(fg_Forward<tfp_CParams>(p_Params)...);
		}

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
	{
		return TCMemberFunctionFunctor<tf_FFunctionPtr>(_fFunction);
	}

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
	{
		return TCMemberFunctionBoundFunctor<tf_FFunctionPtr, tf_CClass>(_fFunction, _pClassPtr);
	}
}

#ifndef DMibPNoShortCuts
using namespace NMib::NFunction;
#endif
