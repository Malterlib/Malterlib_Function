// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction
{
	template <typename tf_CLeft, typename tf_CRight>
	auto COperatorFunctor_Comma::operator () (tf_CLeft &&_Left, tf_CRight &&_Right) const -> decltype(fg_Forward<tf_CLeft>(_Left), fg_Forward<tf_CRight>(_Right))
	{
		return fg_Forward<tf_CLeft>(_Left), fg_Forward<tf_CRight>(_Right);
	}

	template <typename tf_CCondition, typename tf_CLeft, typename tf_CRight>
	auto COperatorFunctor_Conditional::operator () (tf_CCondition &&_Condition, tf_CLeft &&_Left, tf_CRight &&_Right) const
		-> decltype(fg_Forward<tf_CCondition>(_Condition) ? fg_Forward<tf_CLeft>(_Left) : fg_Forward<tf_CRight>(_Right))
	{
		return fg_Forward<tf_CCondition>(_Condition) ? fg_Forward<tf_CLeft>(_Left) : fg_Forward<tf_CRight>(_Right);
	}

	template <typename tf_CLeft, typename tf_CRight>
	auto COperatorFunctor_Subscript::operator () (tf_CLeft &&_Left, tf_CRight &&_Right) const -> decltype(fg_Forward<tf_CLeft>(_Left)[fg_Forward<tf_CRight>(_Right)])
	{
		return fg_Forward<tf_CLeft>(_Left)[fg_Forward<tf_CRight>(_Right)];
	}

	template <typename tf_CRight>
	auto COperatorFunctor_PostfixIncrement::operator () (tf_CRight &&_Right) const -> decltype(fg_Forward<tf_CRight>(_Right)++)
	{
		return fg_Forward<tf_CRight>(_Right)++;
	}

	template <typename tf_CRight>
	auto COperatorFunctor_PostfixDecrement::operator () (tf_CRight &&_Right) const -> decltype(fg_Forward<tf_CRight>(_Right)--)
	{
		return fg_Forward<tf_CRight>(_Right)--;
	}
}
