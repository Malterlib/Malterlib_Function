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
	template <typename t_CFunctionMemberPointer>
	struct TCMemberFunctionFunctor
	{
	private:
		using CReturn = typename NTraits::TCMemberFunctionPointerTraits<t_CFunctionMemberPointer>::CReturn;
		using CClass = typename NTraits::TCMemberFunctionPointerTraits<t_CFunctionMemberPointer>::CClass;

	public:
		TCMemberFunctionFunctor(TCMemberFunctionFunctor &_Other)
			: mp_pFunction(_Other.mp_pFunction)
		{
		}

		TCMemberFunctionFunctor(TCMemberFunctionFunctor const &_Other)
			: mp_pFunction(_Other.mp_pFunction)
		{
		}

		TCMemberFunctionFunctor(TCMemberFunctionFunctor &&_Other)
			: mp_pFunction(fg_Move(_Other.mp_pFunction))
		{
		}

		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor &_Other)
		{
			mp_pFunction = _Other.mp_pFunction;
			return *this;
		}

		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor const &_Other)
		{
			mp_pFunction = _Other.mp_pFunction;
			return *this;
		}

		TCMemberFunctionFunctor &operator = (TCMemberFunctionFunctor &&_Other)
		{
			mp_pFunction = fg_Move(_Other.mp_pFunction);
			return *this;
		}

		template <typename tf_CFunctionPointer>
		mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor(tf_CFunctionPointer &&_P0)
			: mp_pFunction(fg_Forward<tf_CFunctionPointer>(_P0))
		{
		}

		template <typename tf_CFunctionPointer>
		mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor &operator = (tf_CFunctionPointer &&_P0)
		{
			mp_pFunction = fg_Forward<tf_CFunctionPointer>(_P0);
			return *this;
		}

	public:
		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (CClass &_Reference, tfp_CParams && ...p_Params) const
		{
			return (_Reference.*fg_RemoveQualifiers(mp_pFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (CClass const &_Reference, tfp_CParams && ...p_Params) const
		{
			return (_Reference.*fg_RemoveQualifiers(mp_pFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

		template <typename tf_CPtr, typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tf_CPtr &&_pPtr, tfp_CParams && ...p_Params) const
		{
			return (_pPtr->*fg_RemoveQualifiers(mp_pFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

	private:
		t_CFunctionMemberPointer mp_pFunction;
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

	template <typename t_CFunctionMemberPointer, typename t_CThis>
	struct TCMemberFunctionBoundFunctor
	{
	private:
		using CReturn = typename NTraits::TCMemberFunctionPointerTraits<t_CFunctionMemberPointer>::CReturn;

	public:
		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor &_Other)
			: mp_pFunction(_Other.mp_pFunction)
			, mp_pThis(_Other.mp_pThis)
		{
		}

		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor const &_Other)
			: mp_pFunction(_Other.mp_pFunction)
			, mp_pThis(_Other.mp_pThis)
		{
		}

		TCMemberFunctionBoundFunctor(TCMemberFunctionBoundFunctor &&_Other)
			: mp_pFunction(fg_Move(_Other.mp_pFunction))
			, mp_pThis(fg_Move(_Other.mp_pThis))
		{
		}

		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor &_Other)
		{
			mp_pFunction = _Other.mp_pFunction;
			mp_pThis = _Other.mp_pThis;
			return *this;
		}

		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor const &_Other)
		{
			mp_pFunction = _Other.mp_pFunction;
			mp_pThis = _Other.mp_pThis;
			return *this;
		}

		TCMemberFunctionBoundFunctor &operator = (TCMemberFunctionBoundFunctor &&_Other)
		{
			mp_pFunction = fg_Move(_Other.mp_pFunction);
			mp_pThis = fg_Move(_Other.mp_pThis);
			return *this;
		}

		template <typename tf_CFunctionPointer, typename tf_CThis>
		mark_artificial mark_nodebug inline_always TCMemberFunctionBoundFunctor(tf_CFunctionPointer &&_P0, tf_CThis &&_P1)
			: mp_pFunction(fg_Forward<tf_CFunctionPointer>(_P0))
			, mp_pThis(fg_Forward<tf_CThis>(_P1))
		{
		}

	public:
		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tfp_CParams && ...p_Params) const
		{
			return (const_cast<t_CThis>(mp_pThis)->*fg_RemoveQualifiers(mp_pFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

		template <typename ...tfp_CParams>
		mark_artificial inline_always CReturn operator () (tfp_CParams && ...p_Params)
		{
			return (mp_pThis->*mp_pFunction)(fg_Forward<tfp_CParams>(p_Params)...);
		}

	private:
		t_CFunctionMemberPointer mp_pFunction;
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
	template <typename tf_CFunctionPtr>
	mark_artificial mark_nodebug inline_always auto fg_MemberFunctionFunctor(tf_CFunctionPtr _pPtr)
		-> TCEnableIf<NTraits::TCMemberFunctionPointerTraits<tf_CFunctionPtr>::mc_IsMemberFunctionPointer, TCMemberFunctionFunctor<tf_CFunctionPtr>>
	{
		return TCMemberFunctionFunctor<tf_CFunctionPtr>(_pPtr);
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
	template <typename tf_CFunctionPtr, typename tf_CClass>
	mark_artificial mark_nodebug inline_always auto fg_MemberFunctionFunctor(tf_CFunctionPtr _pPtr, tf_CClass _pClassPtr)
		-> TCEnableIf<NTraits::TCMemberFunctionPointerTraits<tf_CFunctionPtr>::mc_IsMemberFunctionPointer, TCMemberFunctionBoundFunctor<tf_CFunctionPtr, tf_CClass>>
	{
		return TCMemberFunctionBoundFunctor<tf_CFunctionPtr, tf_CClass>(_pPtr, _pClassPtr);
	}
}

#ifndef DMibPNoShortCuts
using namespace NMib::NFunction;
#endif
