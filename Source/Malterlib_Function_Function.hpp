// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction
{
	template <typename t_CFunction, typename ...tp_COptions>
	inline TCFunction<t_CFunction, tp_COptions...>::~TCFunction()
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
	template <typename t_CFunction, typename ...tp_COptions>
	inline TCFunction<t_CFunction, tp_COptions...>::TCFunction()
	{
	}

	template <typename t_CFunction, typename ...tp_COptions>
	template <typename ...tfp_CParams>
	inline TCFunction<t_CFunction, tp_COptions...>::TCFunction(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CSuper(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
	template <typename t_CFunction, typename ...tp_COptions>
	template
	<
		typename tf_CFunction
		, TCEnableIf
		<
			!NTraits::cIsSame<NTraits::TCRemoveReference<tf_CFunction>, NInternal::CDefault>
			&& !NTraits::cIsSame<NTraits::TCRemoveReferenceAndQualifiers<tf_CFunction>, NPrivate::CReturnReference>
			&& !NPrivate::TCIsSelf<tf_CFunction, TCFunction<t_CFunction, tp_COptions...>>::mc_Value
			, bool
		>
	>
	inline TCFunction<t_CFunction, tp_COptions...>::TCFunction(tf_CFunction &&_Function)
		: CSuper(fg_Forward<tf_CFunction>(_Function))
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
	template <typename t_CFunction, typename ...tp_COptions>
	template
	<
		typename tf_CFunction
		, TCEnableIf
		<
			!NTraits::cIsSame<NTraits::TCRemoveReference<tf_CFunction>, NInternal::CDefault>
			&& !NTraits::cIsSame<NTraits::TCRemoveReferenceAndQualifiers<tf_CFunction>, NPrivate::CReturnReference>
			&& !NPrivate::TCIsSelf<tf_CFunction, TCFunction<t_CFunction, tp_COptions...>>::mc_Value
			, bool
		>
	>
	inline auto TCFunction<t_CFunction, tp_COptions...>::operator = (tf_CFunction &&_Function) -> TCFunction &
	{
		CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
		return *this;
	}

	template <typename t_CFunction, typename ...tp_COptions>
	inline TCFunctionFastCall<t_CFunction, tp_COptions...>::~TCFunctionFastCall()
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
	template <typename t_CFunction, typename ...tp_COptions>
	inline TCFunctionFastCall<t_CFunction, tp_COptions...>::TCFunctionFastCall()
	{
	}

	template <typename t_CFunction, typename ...tp_COptions>
	template <typename ...tfp_CParams>
	inline TCFunctionFastCall<t_CFunction, tp_COptions...>::TCFunctionFastCall(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CSuper(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
	template <typename t_CFunction, typename ...tp_COptions>
	template
	<
		typename tf_CFunction
		, TCEnableIf
		<
			!NTraits::cIsSame<NTraits::TCRemoveReference<tf_CFunction>, NInternal::CDefault>
			&& !NTraits::cIsSame<NTraits::TCRemoveReferenceAndQualifiers<tf_CFunction>, NPrivate::CReturnReference>
			&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionFastCall<t_CFunction, tp_COptions...>>::mc_Value
			, bool
		>
	>
	inline TCFunctionFastCall<t_CFunction, tp_COptions...>::TCFunctionFastCall(tf_CFunction &&_Function)
		: CSuper(fg_Forward<tf_CFunction>(_Function))
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
	template <typename t_CFunction, typename ...tp_COptions>
	template
	<
		typename tf_CFunction
		, TCEnableIf
		<
			!NTraits::cIsSame<NTraits::TCRemoveReference<tf_CFunction>, NInternal::CDefault>
			&& !NTraits::cIsSame<NTraits::TCRemoveReferenceAndQualifiers<tf_CFunction>, NPrivate::CReturnReference>
			&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionFastCall<t_CFunction, tp_COptions...>>::mc_Value
			, bool
		>
	>
	inline auto TCFunctionFastCall<t_CFunction, tp_COptions...>::operator = (tf_CFunction &&_Function) -> TCFunctionFastCall &
	{
		CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
		return *this;
	}

	template <typename t_CFunction, typename ...tp_COptions>
	inline TCFunctionSmall<t_CFunction, tp_COptions...>::~TCFunctionSmall()
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
	template <typename t_CFunction, typename ...tp_COptions>
	inline TCFunctionSmall<t_CFunction, tp_COptions...>::TCFunctionSmall()
	{
	}

	template <typename t_CFunction, typename ...tp_COptions>
	template <typename ...tfp_CParams>
	inline TCFunctionSmall<t_CFunction, tp_COptions...>::TCFunctionSmall(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CSuper(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
	template <typename t_CFunction, typename ...tp_COptions>
	template
	<
		typename tf_CFunction
		, TCEnableIf
		<
			!NTraits::cIsSame<NTraits::TCRemoveReference<tf_CFunction>, NInternal::CDefault>
			&& !NTraits::cIsSame<NTraits::TCRemoveReferenceAndQualifiers<tf_CFunction>, NPrivate::CReturnReference>
			&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionSmall<t_CFunction, tp_COptions...>>::mc_Value
			, bool
		>
	>
	inline TCFunctionSmall<t_CFunction, tp_COptions...>::TCFunctionSmall(tf_CFunction &&_Function)
		: CSuper(fg_Forward<tf_CFunction>(_Function))
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
	template <typename t_CFunction, typename ...tp_COptions>
	template
	<
		typename tf_CFunction
		, TCEnableIf
		<
			!NTraits::cIsSame<NTraits::TCRemoveReference<tf_CFunction>, NInternal::CDefault>
			&& !NTraits::cIsSame<NTraits::TCRemoveReferenceAndQualifiers<tf_CFunction>, NPrivate::CReturnReference>
			&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionSmall<t_CFunction, tp_COptions...>>::mc_Value
			, bool
		>
	>
	inline auto TCFunctionSmall<t_CFunction, tp_COptions...>::operator = (tf_CFunction &&_Function) -> TCFunctionSmall &
	{
		CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
		return *this;
	}

	template <typename t_CFunction, typename ...tp_COptions>
	inline TCFunctionNoAlloc<t_CFunction, tp_COptions...>::~TCFunctionNoAlloc()
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
	template <typename t_CFunction, typename ...tp_COptions>
	inline TCFunctionNoAlloc<t_CFunction, tp_COptions...>::TCFunctionNoAlloc()
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
	template <typename t_CFunction, typename ...tp_COptions>
	template
	<
		typename tf_CFunction
		, TCEnableIf
		<
			!NTraits::cIsSame<NTraits::TCRemoveReference<tf_CFunction>, NInternal::CDefault>
			&& !NTraits::cIsSame<NTraits::TCRemoveReferenceAndQualifiers<tf_CFunction>, NPrivate::CReturnReference>
			&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionNoAlloc<t_CFunction, tp_COptions...>>::mc_Value
			, bool
		>
	>
	inline TCFunctionNoAlloc<t_CFunction, tp_COptions...>::TCFunctionNoAlloc(tf_CFunction &&_Function)
		: CSuper(fg_Forward<tf_CFunction>(_Function))
	{
	}

	/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
	template <typename t_CFunction, typename ...tp_COptions>
	template
	<
		typename tf_CFunction
		, TCEnableIf
		<
			!NTraits::cIsSame<NTraits::TCRemoveReference<tf_CFunction>, NInternal::CDefault>
			&& !NTraits::cIsSame<NTraits::TCRemoveReferenceAndQualifiers<tf_CFunction>, NPrivate::CReturnReference>
			&& !NPrivate::TCIsSelf<tf_CFunction, TCFunctionNoAlloc<t_CFunction, tp_COptions...>>::mc_Value
			, bool
		>
	>
	inline auto TCFunctionNoAlloc<t_CFunction, tp_COptions...>::operator = (tf_CFunction &&_Function) -> TCFunctionNoAlloc &
	{
		CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
		return *this;
	}
}
