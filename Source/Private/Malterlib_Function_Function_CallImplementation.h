// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFunctor, bool t_bSupportCopy, bool t_bSupportMove>
	struct TCImplBase
	{
		using CFunctor = t_CFunctor;

		static constexpr aint mc_IsIndirection = false;

		TCImplBase(TCImplBase const &_Other);
		TCImplBase(TCImplBase &&_Other);

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor);

		t_CFunctor m_Functor;
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, false, true>
	{
		using CFunctor = t_CFunctor;

		static constexpr aint mc_IsIndirection = false;

		TCImplBase(TCImplBase &&_Other);

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor);

		TCImplBase(TCImplBase const &_Other) = delete;

		t_CFunctor m_Functor;
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, true, false>
	{
		using CFunctor = t_CFunctor;

		static constexpr aint mc_IsIndirection = false;

		TCImplBase(TCImplBase const &_Other);

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor);

		TCImplBase(TCImplBase &&_Other) = delete;

		t_CFunctor m_Functor;
	};

	template <typename t_CFunctor>
	struct TCImplBase<t_CFunctor, false, false>
	{
		using CFunctor = t_CFunctor;

		static constexpr aint mc_IsIndirection = false;

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor);

		TCImplBase(TCImplBase &&_Other) = delete;
		TCImplBase(TCImplBase const &_Other) = delete;

		t_CFunctor m_Functor;
	};

	template <typename t_CFunctor, typename ...tp_COptions>
	struct TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, true>
	{
		using CFunctor = t_CFunctor;

		static constexpr aint mc_IsIndirection = true;

		TCImplBase(TCImplBase const &_Other);
		TCImplBase(TCImplBase &&_Other);

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor);

		NStorage::TCUniquePointer<t_CFunctor, tp_COptions...> m_pFunctor;
	};

	template <typename t_CFunctor, typename ...tp_COptions>
	struct TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, false, true>
	{
		using CFunctor = t_CFunctor;

		static constexpr aint mc_IsIndirection = true;

		TCImplBase(TCImplBase &&_Other);

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor);

		TCImplBase(TCImplBase const &_Other) = delete;

		NStorage::TCUniquePointer<t_CFunctor, tp_COptions...> m_pFunctor;
	};

	template <typename t_CFunctor, typename ...tp_COptions>
	struct TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, true, false>
	{
		using CFunctor = t_CFunctor;

		static constexpr aint mc_IsIndirection = true;

		TCImplBase(TCImplBase const &_Other);

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor);

		TCImplBase(TCImplBase &&_Other) = delete;

		NStorage::TCUniquePointer<t_CFunctor, tp_COptions...> m_pFunctor;
	};

	template <typename t_CFunctor, typename ...tp_COptions>
	struct TCImplBase<NStorage::TCUniquePointer<t_CFunctor, tp_COptions...>, false, false>
	{
		using CFunctor = t_CFunctor;

		static constexpr aint mc_IsIndirection = true;

		template <typename tf_CFunctor>
		TCImplBase(tf_CFunctor &&_Functor);

		TCImplBase(TCImplBase &&_Other) = delete;
		TCImplBase(TCImplBase const &_Other) = delete;

		NStorage::TCUniquePointer<t_CFunctor, tp_COptions...> m_pFunctor;
	};

	template <typename t_CBase, typename t_FFunc, int t_Qualifiers>
	struct TCCallImpl;

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_None>
	{
		mark_no_coroutine_debug static t_CReturn fs_Call(void *_pImpl, tp_CParams ...p_Params);
	};

	template <typename t_CBase, typename ...tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams ...p_Params), EQualifiers_None>
	{
		mark_no_coroutine_debug static void fs_Call(void *_pImpl, tp_CParams ...p_Params);
	};

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_Const>
	{
		mark_no_coroutine_debug static t_CReturn fs_Call(void *_pImpl, tp_CParams ...p_Params);
	};

	template <typename t_CBase, typename ...tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams ...p_Params), EQualifiers_Const>
	{
		mark_no_coroutine_debug static void fs_Call(void *_pImpl, tp_CParams ...p_Params);
	};

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_None>
	{
		mark_no_coroutine_debug static t_CReturn fs_Call(void *_pImpl, tp_CParams ...p_Params) noexcept
			requires (NTraits::cIsNothrowCallableWith<typename t_CBase::CFunctor, void (tp_CParams ...p_Params)>)
		;
	};

	template <typename t_CBase, typename ...tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams ...p_Params) noexcept, EQualifiers_None>
	{
		mark_no_coroutine_debug static void fs_Call(void *_pImpl, tp_CParams ...p_Params) noexcept
			requires (NTraits::cIsNothrowCallableWith<typename t_CBase::CFunctor, void (tp_CParams ...p_Params)>)
		;
	};

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	struct TCCallImpl<t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_Const>
	{
		mark_no_coroutine_debug static t_CReturn fs_Call(void *_pImpl, tp_CParams ...p_Params) noexcept
			requires (NTraits::cIsNothrowCallableWith<typename t_CBase::CFunctor, void (tp_CParams ...p_Params)>)
		;
	};

	template <typename t_CBase, typename ...tp_CParams>
	struct TCCallImpl<t_CBase, void (tp_CParams ...p_Params) noexcept, EQualifiers_Const>
	{
		mark_no_coroutine_debug static void fs_Call(void *_pImpl, tp_CParams ...p_Params) noexcept
			requires (NTraits::cIsNothrowCallableWith<typename t_CBase::CFunctor, void (tp_CParams ...p_Params)>)
		;
	};
}

#include "Malterlib_Function_Function_CallImplementation.hpp"
