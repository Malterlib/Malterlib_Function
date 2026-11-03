// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFunctor, bool t_bSupportCopy, bool t_bSupportMove>
	TCImplBase<t_CFunctor, t_bSupportCopy, t_bSupportMove>::TCImplBase(TCImplBase const &_Other)
		: m_Functor(_Other.m_Functor)
	{
	}

	template <typename t_CFunctor, bool t_bSupportCopy, bool t_bSupportMove>
	TCImplBase<t_CFunctor, t_bSupportCopy, t_bSupportMove>::TCImplBase(TCImplBase &&_Other)
		: m_Functor(fg_Move(_Other.m_Functor))
	{
	}

	template <typename t_CFunctor, bool t_bSupportCopy, bool t_bSupportMove>
	template <typename tf_CFunctor>
	TCImplBase<t_CFunctor, t_bSupportCopy, t_bSupportMove>::TCImplBase(tf_CFunctor &&_Functor)
		: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
	{
	}

	template <typename t_CFunctor>
	TCImplBase<t_CFunctor, false, true>::TCImplBase(TCImplBase &&_Other)
		: m_Functor(fg_Move(_Other.m_Functor))
	{
	}

	template <typename t_CFunctor>
	template <typename tf_CFunctor>
	TCImplBase<t_CFunctor, false, true>::TCImplBase(tf_CFunctor &&_Functor)
		: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
	{
	}

	template <typename t_CFunctor>
	TCImplBase<t_CFunctor, true, false>::TCImplBase(TCImplBase const &_Other)
		: m_Functor(_Other.m_Functor)
	{
	}

	template <typename t_CFunctor>
	template <typename tf_CFunctor>
	TCImplBase<t_CFunctor, true, false>::TCImplBase(tf_CFunctor &&_Functor)
		: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
	{
	}

	template <typename t_CFunctor>
	template <typename tf_CFunctor>
	TCImplBase<t_CFunctor, false, false>::TCImplBase(tf_CFunctor &&_Functor)
		: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
	{
	}

	template <typename t_CFunctor, typename ...tp_COptions>
	TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, true>::TCImplBase(TCImplBase const &_Other)
		: m_pFunctor(fg_Copy(_Other.m_pFunctor))
	{
	}

	template <typename t_CFunctor, typename ...tp_COptions>
	TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, true>::TCImplBase(TCImplBase &&_Other)
		: m_pFunctor(fg_Move(_Other.m_pFunctor))
	{
	}

	template <typename t_CFunctor, typename ...tp_COptions>
	template <typename tf_CFunctor>
	TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, true>::TCImplBase(tf_CFunctor &&_Functor)
		: m_pFunctor(fg_Construct(fg_Forward<tf_CFunctor>(_Functor)))
	{
	}

	template <typename t_CFunctor, typename ...tp_COptions>
	TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, false, true>::TCImplBase(TCImplBase &&_Other)
		: m_pFunctor(fg_Move(_Other.m_pFunctor))
	{
	}

	template <typename t_CFunctor, typename ...tp_COptions>
	template <typename tf_CFunctor>
	TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, false, true>::TCImplBase(tf_CFunctor &&_Functor)
		: m_pFunctor(fg_Construct(fg_Forward<tf_CFunctor>(_Functor)))
	{
	}

	template <typename t_CFunctor, typename ...tp_COptions>
	TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, false>::TCImplBase(TCImplBase const &_Other)
		: m_pFunctor(fg_Copy(_Other.m_pFunctor))
	{
	}

	template <typename t_CFunctor, typename ...tp_COptions>
	template <typename tf_CFunctor>
	TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, false>::TCImplBase(tf_CFunctor &&_Functor)
		: m_pFunctor(fg_Construct(fg_Forward<tf_CFunctor>(_Functor)))
	{
	}

	template <typename t_CFunctor, typename ...tp_COptions>
	template <typename tf_CFunctor>
	TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, false, false>::TCImplBase(tf_CFunctor &&_Functor)
		: m_pFunctor(fg_Construct(fg_Forward<tf_CFunctor>(_Functor)))
	{
	}

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	mark_no_coroutine_debug t_CReturn TCCallImpl<t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_None>::fs_Call(void *_pImpl, tp_CParams ...p_Params)
	{
		if constexpr (t_CBase::mc_IsIndirection)
			return (*((t_CBase *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		else
			return ((t_CBase *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename ...tp_CParams>
	mark_no_coroutine_debug void TCCallImpl<t_CBase, void (tp_CParams ...p_Params), EQualifiers_None>::fs_Call(void *_pImpl, tp_CParams ...p_Params)
	{
		if constexpr (t_CBase::mc_IsIndirection)
			(*((t_CBase *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		else
			((t_CBase *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	mark_no_coroutine_debug t_CReturn TCCallImpl<t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_Const>::fs_Call(void *_pImpl, tp_CParams ...p_Params)
	{
		if constexpr (t_CBase::mc_IsIndirection)
			return (*((t_CBase const *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		else
			return ((t_CBase const *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename ...tp_CParams>
	mark_no_coroutine_debug void TCCallImpl<t_CBase, void (tp_CParams ...p_Params), EQualifiers_Const>::fs_Call(void *_pImpl, tp_CParams ...p_Params)
	{
		if constexpr (t_CBase::mc_IsIndirection)
			(*((t_CBase const *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		else
			((t_CBase const *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	mark_no_coroutine_debug t_CReturn TCCallImpl<t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_None>::fs_Call(void *_pImpl, tp_CParams ...p_Params) noexcept
		requires (NTraits::cIsNothrowCallableWith<typename t_CBase::CFunctor, void (tp_CParams ...p_Params)>)
	{
		if constexpr (t_CBase::mc_IsIndirection)
			return (*((t_CBase *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		else
			return ((t_CBase *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename ...tp_CParams>
	mark_no_coroutine_debug void TCCallImpl<t_CBase, void (tp_CParams ...p_Params) noexcept, EQualifiers_None>::fs_Call(void *_pImpl, tp_CParams ...p_Params) noexcept
		requires (NTraits::cIsNothrowCallableWith<typename t_CBase::CFunctor, void (tp_CParams ...p_Params)>)
	{
		if constexpr (t_CBase::mc_IsIndirection)
			(*((t_CBase *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		else
			((t_CBase *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	mark_no_coroutine_debug t_CReturn TCCallImpl<t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_Const>::fs_Call(void *_pImpl, tp_CParams ...p_Params) noexcept
		requires (NTraits::cIsNothrowCallableWith<typename t_CBase::CFunctor, void (tp_CParams ...p_Params)>)
	{
		if constexpr (t_CBase::mc_IsIndirection)
			return (*((t_CBase const *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		else
			return ((t_CBase const *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename ...tp_CParams>
	mark_no_coroutine_debug void TCCallImpl<t_CBase, void (tp_CParams ...p_Params) noexcept, EQualifiers_Const>::fs_Call(void *_pImpl, tp_CParams ...p_Params) noexcept
		requires (NTraits::cIsNothrowCallableWith<typename t_CBase::CFunctor, void (tp_CParams ...p_Params)>)
	{
		if constexpr (t_CBase::mc_IsIndirection)
			(*((t_CBase const *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		else
			((t_CBase const *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}
}
