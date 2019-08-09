// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFunctor, bool t_bSupportCopy, bool t_bSupportMove>
	struct TCImplBase
	{
		enum
		{
			mc_IsIndirection = false
		};

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

		t_CFunctor m_Functor;
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, false, true>
	{
		enum
		{
			mc_IsIndirection = false
		};

		TCImplBase(TCImplBase &&_Other)
			: m_Functor(fg_Move(_Other.m_Functor))
		{
		}
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
		{
		}

		TCImplBase(TCImplBase const &_Other) = delete;

		t_CFunctor m_Functor;
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, true, false>
	{
		enum
		{
			mc_IsIndirection = false
		};

		TCImplBase(TCImplBase const &_Other)
			: m_Functor(_Other.m_Functor)
		{
		}
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
		{
		}

		TCImplBase(TCImplBase &&_Other) = delete;

		t_CFunctor m_Functor;
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, false, false>
	{
		enum
		{
			mc_IsIndirection = false
		};

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_Functor(fg_Forward<tf_CFunctor>(_Functor))
		{
		}

		TCImplBase(TCImplBase &&_Other) = delete;
		TCImplBase(TCImplBase const &_Other) = delete;

		t_CFunctor m_Functor;
	};

	template <typename t_CFunctor, typename ...tp_COptions>
	struct TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, true>
	{
		enum
		{
			mc_IsIndirection = true
		};


		TCImplBase(TCImplBase const &_Other)
			: m_pFunctor(fg_Copy(_Other.m_pFunctor))
		{
		}
		TCImplBase(TCImplBase &&_Other)
			: m_pFunctor(fg_Move(_Other.m_pFunctor))
		{
		}
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_pFunctor(fg_Construct(fg_Forward<tf_CFunctor>(_Functor)))
		{
		}

		NStorage::TCUniquePointer<t_CFunctor, tp_COptions...> m_pFunctor;
	};

	template <typename t_CFunctor, typename ...tp_COptions>
	struct TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, false, true>
	{
		enum
		{
			mc_IsIndirection = true
		};

		TCImplBase(TCImplBase &&_Other)
			: m_pFunctor(fg_Move(_Other.m_pFunctor))
		{
		}
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_pFunctor(fg_Construct(fg_Forward<tf_CFunctor>(_Functor)))
		{
		}

		TCImplBase(TCImplBase const &_Other) = delete;

		NStorage::TCUniquePointer<t_CFunctor, tp_COptions...> m_pFunctor;
	};

	template <typename t_CFunctor, typename ...tp_COptions>
	struct TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, false>
	{
		enum
		{
			mc_IsIndirection = true
		};

		TCImplBase(TCImplBase const &_Other)
			: m_pFunctor(fg_Copy(_Other.m_pFunctor))
		{
		}
		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_pFunctor(fg_Construct(fg_Forward<tf_CFunctor>(_Functor)))
		{
		}

		TCImplBase(TCImplBase &&_Other) = delete;

		NStorage::TCUniquePointer<t_CFunctor, tp_COptions...> m_pFunctor;
	};

	template <typename t_CFunctor, typename ...tp_COptions>
	struct TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, false, false>
	{
		enum
		{
			mc_IsIndirection = true
		};

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor)
			: m_pFunctor(fg_Construct(fg_Forward<tf_CFunctor>(_Functor)))
		{
		}

		TCImplBase(TCImplBase &&_Other) = delete;
		TCImplBase(TCImplBase const &_Other) = delete;

		NStorage::TCUniquePointer<t_CFunctor, tp_COptions...> m_pFunctor;
	};


	template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
	struct TCCallImpl;

	template <typename t_CBase, typename t_CReturn, typename... tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams...), EQualifiers_None>
	{
		mark_no_coroutine_debug static t_CReturn fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			if constexpr (t_CBase::mc_IsIndirection)
				return (*((t_CBase *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
			else
				return ((t_CBase *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename... tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams...), EQualifiers_None>
	{
		mark_no_coroutine_debug static void fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			if constexpr (t_CBase::mc_IsIndirection)
				(*((t_CBase *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
			else
				((t_CBase *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename t_CReturn, typename... tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams...), EQualifiers_Const>
	{
		mark_no_coroutine_debug static t_CReturn fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			if constexpr (t_CBase::mc_IsIndirection)
				return (*((t_CBase const *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
			else
				return ((t_CBase const *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
	template <typename t_CBase, typename... tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams...), EQualifiers_Const>
	{
		mark_no_coroutine_debug static void fs_Call(void *_pImpl, tp_CParams... p_Params)
		{
			if constexpr (t_CBase::mc_IsIndirection)
				(*((t_CBase const *)_pImpl)->m_pFunctor)(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
			else
				((t_CBase const *)_pImpl)->m_Functor(TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};
}
