// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include <Mib/Function/Operators>

/*¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*\
|	Functions:																						|
|																									|
|	Description:		Operators																	|
|																									|
|	Comments:			.																			|
|																									|
|	See Also:			.																			|
|																									|
|	Location:			Functions																	|
|																									|
|	Index:				!name																		|
\*_________________________________________________________________________________________________*/

//namespace NMib
//{
	//namespace NFunction
	//{
		//namespace NBindExpression
		//{
#			define DMibTempImplementBindBinaryOperator(d_Operator, d_Name) \
				template <typename tf_CLeft, typename tf_CRight> \
				auto operator d_Operator (tf_CLeft &&_Left, tf_CRight &&_Right)\
				-> typename NMib::TCEnableIf\
				<\
					NMib::NFunction::TCIsNonComparableBindExpression<tf_CLeft>::mc_Value || NMib::NFunction::TCIsNonComparableBindExpression<tf_CRight>::mc_Value\
					, NMib::NFunction::NBindExpression::TCBindExpression\
					<\
						typename NMib::NFunction::NPrivate::TCDoToBindTransform<NMib::NFunction::COperatorFunctor_##d_Name>::CType\
						, typename NMib::NTraits::TCDecay<tf_CLeft>::CType\
						, typename NMib::NTraits::TCDecay<tf_CRight>::CType\
					>\
				>::CType\
				{\
					return NMib::NFunction::fg_Bind(NMib::NFunction::COperatorFunctor_##d_Name(), NMib::fg_Forward<tf_CLeft>(_Left), NMib::fg_Forward<tf_CRight>(_Right));\
				}

			DMibTempImplementBindBinaryOperator(==, Equal);
			DMibTempImplementBindBinaryOperator(!=, NotEqual);
			DMibTempImplementBindBinaryOperator(<, Less);
			DMibTempImplementBindBinaryOperator(<=, LessEqual);
			DMibTempImplementBindBinaryOperator(>, Greater);
			DMibTempImplementBindBinaryOperator(>=, GreaterEqual);

			DMibTempImplementBindBinaryOperator(<<, ShiftLeft);
			DMibTempImplementBindBinaryOperator(>>, ShiftRight);

			DMibTempImplementBindBinaryOperator(*, Multiply);
			DMibTempImplementBindBinaryOperator(/, Divide);
			DMibTempImplementBindBinaryOperator(%, Modulu);

			DMibTempImplementBindBinaryOperator(+, Add);
			DMibTempImplementBindBinaryOperator(-, Subtract);

			DMibTempImplementBindBinaryOperator(&, BitwiseAnd);
			DMibTempImplementBindBinaryOperator(^, BitwiseXOR);
			DMibTempImplementBindBinaryOperator(|, BitwiseOr);

			DMibTempImplementBindBinaryOperator(*=, MultiplyAssign);
			DMibTempImplementBindBinaryOperator(/=, DivideAssign);
			DMibTempImplementBindBinaryOperator(%=, MoluluAssign);

			DMibTempImplementBindBinaryOperator(+=, AddAssign);
			DMibTempImplementBindBinaryOperator(-=, SubtractAssign);

			DMibTempImplementBindBinaryOperator(&=, BitwiseAndAssign);
			DMibTempImplementBindBinaryOperator(^=, BitwiseXORAssign);
			DMibTempImplementBindBinaryOperator(|=, BitwiseOrAssign);

			DMibTempImplementBindBinaryOperator(<<=, ShiftLeftAssign);
			DMibTempImplementBindBinaryOperator(>>=, ShiftRightAssign);

			// DMibTempImplementBindBinaryOperator(->*); Has special implementation

#			undef DMibTempImplementBindBinaryOperator

#			define DMibTempImplementBindUnaryOperator(d_Operator, d_Name) \
				template <typename tf_CRight>\
				auto operator d_Operator (tf_CRight &&_Right)\
				-> typename NMib::TCEnableIf\
				<\
					NMib::NFunction::TCIsNonComparableBindExpression<tf_CRight>::mc_Value\
					, NMib::NFunction::NBindExpression::TCBindExpression\
					<\
						typename NMib::NFunction::NPrivate::TCDoToBindTransform<NMib::NFunction::COperatorFunctor_##d_Name>::CType\
						, typename NMib::NTraits::TCDecay<tf_CRight>::CType\
					>\
				>::CType\
				{\
					return NMib::NFunction::fg_Bind(NMib::NFunction::COperatorFunctor_##d_Name(), NMib::fg_Forward<tf_CRight>(_Right));\
				}

#			define DMibTempImplementBindUnaryPostfixOperator(d_Operator, d_Name)\
				template <typename tf_CRight>\
				auto operator d_Operator (tf_CRight &&_Right, int)\
				-> typename NMib::TCEnableIf\
				<\
					NMib::NFunction::TCIsNonComparableBindExpression<tf_CRight>::mc_Value\
					, NMib::NFunction::NBindExpression::TCBindExpression\
					<\
						typename NMib::NFunction::NPrivate::TCDoToBindTransform<NMib::NFunction::COperatorFunctor_##d_Name>::CType\
						, typename NMib::NTraits::TCDecay<tf_CRight>::CType\
					>\
				>::CType\
				{\
					return NMib::NFunction::fg_Bind(NMib::NFunction::COperatorFunctor_##d_Name(), NMib::fg_Forward<tf_CRight>(_Right));\
				}

			DMibTempImplementBindUnaryOperator(!, LogicalNot);
			// DMibTempImplementBindUnaryOperator(&, AddressOf); // Should not be overridden (unsafe)
			DMibTempImplementBindUnaryOperator(~, BitwiseComplement);
			DMibTempImplementBindUnaryOperator(*, Indirection);
			DMibTempImplementBindUnaryOperator(+, UnaryPlus);
			DMibTempImplementBindUnaryOperator(++, PrefixIncrement);
			DMibTempImplementBindUnaryPostfixOperator(++, PostfixIncrement);
			DMibTempImplementBindUnaryOperator(-, UnaryNegate);
			DMibTempImplementBindUnaryOperator(--, PrefixDecrement);
			DMibTempImplementBindUnaryPostfixOperator(--, PostfixDecrement);

#			undef DMibTempImplementBindUnaryOperator
#			undef DMibTempImplementBindUnaryPostfixOperator


			template <typename tf_CType>
			auto operator < (tf_CType const &_Left, tf_CType const &_Right)
			-> typename NMib::TCEnableIf
			<
				NMib::NFunction::TCIsComparableBindExpression<tf_CType>::mc_Value
				, bint
			>::CType
			{
				return _Left.f_Less(_Right);
			}

			template <typename tf_CType>
			auto operator > (tf_CType const &_Left, tf_CType const &_Right)
			-> typename NMib::TCEnableIf
			<
				NMib::NFunction::TCIsComparableBindExpression<tf_CType>::mc_Value
				, bint
			>::CType
			{
				return _Right.f_Less(_Left);
			}

			template <typename tf_CType>
			auto operator >= (tf_CType const &_Left, tf_CType const &_Right)
			-> typename NMib::TCEnableIf
			<
				NMib::NFunction::TCIsComparableBindExpression<tf_CType>::mc_Value
				, bint
			>::CType
			{
				return !_Left.f_Less(_Right);
			}

			template <typename tf_CType>
			auto operator <= (tf_CType const &_Left, tf_CType const &_Right)
			-> typename NMib::TCEnableIf
			<
				NMib::NFunction::TCIsComparableBindExpression<tf_CType>::mc_Value
				, bint
			>::CType
			{
				return !_Right.f_Less(_Left);
			}

			template <typename tf_CType>
			auto operator == (tf_CType const &_Left, tf_CType const &_Right)
			-> typename NMib::TCEnableIf
			<
				NMib::NFunction::TCIsComparableBindExpression<tf_CType>::mc_Value
				, bint
			>::CType
			{
				return _Left.f_Equal(_Right);
			}

			template <typename tf_CType>
			auto operator != (tf_CType const &_Left, tf_CType const &_Right)
			-> typename NMib::TCEnableIf
			<
				NMib::NFunction::TCIsComparableBindExpression<tf_CType>::mc_Value
				, bint
			>::CType
			{
				return !_Left.f_Equal(_Right);
			}

		//}
	//}
//}

