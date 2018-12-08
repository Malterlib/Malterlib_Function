// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFunctor, bint t_bSupportCopy, bint t_bSupportMove>
	struct TCImplBase
	{
		t_CFunctor m_Functor;
		TCImplBase(TCImplBase const &_Other)
			: m_Functor(_Other.m_Functor)
		{
		}
		TCImplBase(TCImplBase &&_Other)
			: m_Functor(fg_Move(_Other.m_Functor))
		{
		}
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
		{
		}
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, false, true>
	{
		t_CFunctor m_Functor;
		TCImplBase(TCImplBase &&_Other)
			: m_Functor(fg_Move(_Other.m_Functor))
		{
		}
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
		{
		}
	private:
		TCImplBase(TCImplBase const &_Other);
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, true, false>
	{
		t_CFunctor m_Functor;
		TCImplBase(TCImplBase const &_Other)
			: m_Functor(_Other.m_Functor)
		{
		}
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
		{
		}
	private:
		TCImplBase(TCImplBase &&_Other);
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, false, false>
	{
		t_CFunctor m_Functor;
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
		{
		}
	private:
		TCImplBase(TCImplBase &&_Other);
		TCImplBase(TCImplBase const &_Other);
	};

	template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
	struct TCCallImpl;

	template <typename t_CBase, typename t_CReturn, typename... tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams...), EQualifiers_None>
	{
		static t_CReturn fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			return ((t_CBase *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename... tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams...), EQualifiers_None>
	{
		static void fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			((t_CBase *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename t_CReturn, typename... tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams...), EQualifiers_Const>
	{
		static t_CReturn fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			return ((t_CBase const *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename... tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams...), EQualifiers_Const>
	{
		static void fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			((t_CBase const *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename t_CReturn, typename... tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams...), EQualifiers_Volatile>
	{
		static t_CReturn fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			return ((t_CBase volatile *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename... tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams...), EQualifiers_Volatile>
	{
		static void fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			((t_CBase volatile *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename t_CReturn, typename... tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams...), EQualifiers_ConstVolatile>
	{
		static t_CReturn fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			return ((t_CBase const volatile *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename... tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams...), EQualifiers_ConstVolatile>
	{
		static void fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			((t_CBase const volatile *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
}
