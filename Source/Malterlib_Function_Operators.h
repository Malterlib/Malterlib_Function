// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		struct COperatorFunctor_Comma
		{
			template <typename tf_CLeft, typename tf_CRight>
			auto operator () (tf_CLeft &&_Left, tf_CRight &&_Right) const volatile
			-> decltype(fg_Forward<tf_CLeft>(_Left) , fg_Forward<tf_CRight>(_Right))
			{
				return fg_Forward<tf_CLeft>(_Left) , fg_Forward<tf_CRight>(_Right);
			}
		};

		struct COperatorFunctor_Conditional
		{
			template <typename tf_CCondition, typename tf_CLeft, typename tf_CRight>
			auto operator () (tf_CCondition &&_Condition, tf_CLeft &&_Left, tf_CRight &&_Right) const volatile
			-> decltype(fg_Forward<tf_CCondition>(_Condition) ? fg_Forward<tf_CLeft>(_Left) : fg_Forward<tf_CRight>(_Right))
			{
				return fg_Forward<tf_CCondition>(_Condition) ? fg_Forward<tf_CLeft>(_Left) : fg_Forward<tf_CRight>(_Right);
			}
		};

		struct COperatorFunctor_Subscript
		{
			template <typename tf_CLeft, typename tf_CRight>
			auto operator () (tf_CLeft &&_Left, tf_CRight &&_Right) const volatile
			-> decltype(fg_Forward<tf_CLeft>(_Left)[fg_Forward<tf_CRight>(_Right)])
			{
				return fg_Forward<tf_CLeft>(_Left)[fg_Forward<tf_CRight>(_Right)];
			}
		};

		struct COperatorFunctor_PostfixIncrement
		{
			template <typename tf_CRight>
			auto operator () (tf_CRight &&_Right) const volatile
			-> decltype(fg_Forward<tf_CRight>(_Right)++)
			{
				return fg_Forward<tf_CRight>(_Right)++;
			}
		};

		struct COperatorFunctor_PostfixDecrement
		{
			template <typename tf_CRight>
			auto operator () (tf_CRight &&_Right) const volatile
			-> decltype(fg_Forward<tf_CRight>(_Right)--)
			{
				return fg_Forward<tf_CRight>(_Right)--;
			}
		};


#		define DMibTempImplementFunctionalBinaryOperator(d_Operator, d_Name) \
		struct COperatorFunctor_##d_Name\
		{\
			template <typename tf_CLeft, typename tf_CRight>\
			auto operator () (tf_CLeft &&_Left, tf_CRight &&_Right) const volatile\
			-> decltype(fg_Forward<tf_CLeft>(_Left) d_Operator fg_Forward<tf_CRight>(_Right))\
			{\
				return fg_Forward<tf_CLeft>(_Left) d_Operator fg_Forward<tf_CRight>(_Right);\
			}\
		};


		DMibTempImplementFunctionalBinaryOperator(==, Equal);
		DMibTempImplementFunctionalBinaryOperator(!=, NotEqual);
		DMibTempImplementFunctionalBinaryOperator(<, Less);
		DMibTempImplementFunctionalBinaryOperator(<=, LessEqual);
		DMibTempImplementFunctionalBinaryOperator(>, Greater);
		DMibTempImplementFunctionalBinaryOperator(>=, GreaterEqual);

		DMibTempImplementFunctionalBinaryOperator(<<, ShiftLeft);
		DMibTempImplementFunctionalBinaryOperator(>>, ShiftRight);

		DMibTempImplementFunctionalBinaryOperator(*, Multiply);
		DMibTempImplementFunctionalBinaryOperator(/, Divide);
		DMibTempImplementFunctionalBinaryOperator(%, Modulu);

		DMibTempImplementFunctionalBinaryOperator(+, Add);
		DMibTempImplementFunctionalBinaryOperator(-, Subtract);

		DMibTempImplementFunctionalBinaryOperator(&, BitwiseAnd);
		DMibTempImplementFunctionalBinaryOperator(^, BitwiseXOR);
		DMibTempImplementFunctionalBinaryOperator(|, BitwiseOr);

		DMibTempImplementFunctionalBinaryOperator(&&, LogicalAnd);
		DMibTempImplementFunctionalBinaryOperator(||, LogicalOr);

		DMibTempImplementFunctionalBinaryOperator(*=, MultiplyAssign);
		DMibTempImplementFunctionalBinaryOperator(/=, DivideAssign);
		DMibTempImplementFunctionalBinaryOperator(%=, MoluluAssign);

		DMibTempImplementFunctionalBinaryOperator(+=, AddAssign);
		DMibTempImplementFunctionalBinaryOperator(-=, SubtractAssign);

		DMibTempImplementFunctionalBinaryOperator(&=, BitwiseAndAssign);
		DMibTempImplementFunctionalBinaryOperator(^=, BitwiseXORAssign);
		DMibTempImplementFunctionalBinaryOperator(|=, BitwiseOrAssign);

		DMibTempImplementFunctionalBinaryOperator(<<=, ShiftLeftAssign);
		DMibTempImplementFunctionalBinaryOperator(>>=, ShiftRightAssign);

		DMibTempImplementFunctionalBinaryOperator(=, Assign);
		DMibTempImplementFunctionalBinaryOperator(.*, PointerToMemberRef);
		DMibTempImplementFunctionalBinaryOperator(->*, PointerToMemberPointer);

#		undef DMibTempImplementFunctionalBinaryOperator


#		define DMibTempImplementFunctionalUnaryOperator(d_Operator, d_Name) \
		struct COperatorFunctor_##d_Name\
		{\
			template <typename tf_CRight>\
			auto operator () (tf_CRight &&_Right) const volatile\
			-> decltype(d_Operator fg_Forward<tf_CRight>(_Right))\
			{\
				return d_Operator fg_Forward<tf_CRight>(_Right);\
			}\
		};

		DMibTempImplementFunctionalUnaryOperator(! , LogicalNot);
		DMibTempImplementFunctionalUnaryOperator(& , AddressOf);
		DMibTempImplementFunctionalUnaryOperator(~ , BitwiseComplement);
		DMibTempImplementFunctionalUnaryOperator(* , Indirection);
		DMibTempImplementFunctionalUnaryOperator(+ , UnaryPlus);
		DMibTempImplementFunctionalUnaryOperator(++ , PrefixIncrement);
		DMibTempImplementFunctionalUnaryOperator(- , UnaryNegate);
		DMibTempImplementFunctionalUnaryOperator(-- , PrefixDecrement);

#		undef DMibTempImplementFunctionalUnaryOperator
	}
}

