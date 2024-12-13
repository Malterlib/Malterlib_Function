// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

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
	class TCMemberFunctionFunctor
	{
		typedef typename NTraits::TCMemberFunctionPointerTraits<t_CFunctionMemberPointer>::CReturn CReturn;
		typedef typename NTraits::TCMemberFunctionPointerTraits<t_CFunctionMemberPointer>::CClass CClass;
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
		TCMemberFunctionFunctor &operator =(TCMemberFunctionFunctor &_Other)
		{
			mp_pFunction = _Other.mp_pFunction;
			return *this;
		}
		TCMemberFunctionFunctor &operator =(TCMemberFunctionFunctor const &_Other)
		{
			mp_pFunction = _Other.mp_pFunction;
			return *this;
		}
		TCMemberFunctionFunctor &operator =(TCMemberFunctionFunctor &&_Other)
		{
			mp_pFunction = fg_Move(_Other.mp_pFunction);
			return *this;
		}
		template <typename tf_C0>
		mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor(tf_C0 &&_P0)
			: mp_pFunction(fg_Forward<tf_C0>(_P0))
		{
		}
		template <typename tf_C0>
		mark_artificial mark_nodebug inline_always TCMemberFunctionFunctor &operator =(tf_C0 &&_P0)
		{
			mp_pFunction = fg_Forward<tf_C0>(_P0);
			return *this;
		}

	public:
		template <typename... tfp_CParams>
		mark_artificial inline_always CReturn operator ()(CClass &_Reference, tfp_CParams &&...p_Params) const
		{
			return (_Reference.*fg_RemoveQualifiers(mp_pFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}
		template <typename... tfp_CParams>
		mark_artificial inline_always CReturn operator ()(CClass const &_Reference, tfp_CParams &&...p_Params) const
		{
			return (_Reference.*fg_RemoveQualifiers(mp_pFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}

		template <typename tf_CPtr, typename... tfp_CParams>
		mark_artificial inline_always CReturn operator ()(tf_CPtr &&_pPtr, tfp_CParams &&...p_Params) const
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
	class TCMemberFunctionBoundFunctor
	{
		typedef typename NTraits::TCMemberFunctionPointerTraits<t_CFunctionMemberPointer>::CReturn CReturn;
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
		TCMemberFunctionBoundFunctor &operator =(TCMemberFunctionBoundFunctor &_Other)
		{
			mp_pFunction = _Other.mp_pFunction;
			mp_pThis = _Other.mp_pThis;
			return *this;
		}
		TCMemberFunctionBoundFunctor &operator =(TCMemberFunctionBoundFunctor const &_Other)
		{
			mp_pFunction = _Other.mp_pFunction;
			mp_pThis = _Other.mp_pThis;
			return *this;
		}
		TCMemberFunctionBoundFunctor &operator =(TCMemberFunctionBoundFunctor &&_Other)
		{
			mp_pFunction = fg_Move(_Other.mp_pFunction);
			mp_pThis = fg_Move(_Other.mp_pThis);
			return *this;
		}
		template <typename tf_C0, typename tf_C1>
		mark_artificial mark_nodebug inline_always TCMemberFunctionBoundFunctor(tf_C0 &&_P0, tf_C1 &&_P1)
			: mp_pFunction(fg_Forward<tf_C0>(_P0))
			, mp_pThis(fg_Forward<tf_C1>(_P1))
		{
		}

	public:
		template <typename... tfp_CParams>
		mark_artificial inline_always CReturn operator ()(tfp_CParams &&...p_Params) const
		{
			return (const_cast<t_CThis>(mp_pThis)->*fg_RemoveQualifiers(mp_pFunction))(fg_Forward<tfp_CParams>(p_Params)...);
		}
		template <typename... tfp_CParams>
		mark_artificial inline_always CReturn operator ()(tfp_CParams &&...p_Params)
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
	template <typename t_CFunctionPtr>
	mark_artificial mark_nodebug inline_always auto fg_MemberFunctionFunctor(t_CFunctionPtr _pPtr)
	->
	typename TCEnableIf
	<
		NTraits::TCMemberFunctionPointerTraits<t_CFunctionPtr>::mc_IsMemberFunctionPointer
		, TCMemberFunctionFunctor<t_CFunctionPtr>
	>::CType
	{
		return TCMemberFunctionFunctor<t_CFunctionPtr>(_pPtr);
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
	template <typename t_CFunctionPtr, typename t_CClass>
	mark_artificial mark_nodebug inline_always auto fg_MemberFunctionFunctor(t_CFunctionPtr _pPtr, t_CClass _pClassPtr)
	->
	typename TCEnableIf
	<
		NTraits::TCMemberFunctionPointerTraits<t_CFunctionPtr>::mc_IsMemberFunctionPointer
		, TCMemberFunctionBoundFunctor<t_CFunctionPtr, t_CClass>
	>::CType
	{
		return TCMemberFunctionBoundFunctor<t_CFunctionPtr, t_CClass>(_pPtr, _pClassPtr);
	}
}

#ifndef DMibPNoShortCuts
	using namespace NMib::NFunction;
#endif
