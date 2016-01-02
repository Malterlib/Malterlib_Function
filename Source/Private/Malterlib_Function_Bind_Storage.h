// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
			/// @cond DoxygenClang
			
			template 
			<
				typename t_CBFOpts
				, bint t_bIsEmpty 
					= NTraits::TCIsEmpty<typename t_CBFOpts::CToBind>::mc_Value 
					&& NTraits::TCIsPOD<typename t_CBFOpts::CToBind>::mc_Value
			>
			struct TCBoundFunctionBase
			{
				typedef typename t_CBFOpts::CToBind CToBind;
				typedef t_CBFOpts CBindOptions;
			private:
				CToBind mp_BoundObject;
			public:
				CToBind &fp_BoundObject()
				{
					return mp_BoundObject;
				}
				CToBind const &fp_BoundObject() const
				{
					return mp_BoundObject;
				}
				CToBind volatile &fp_BoundObject() volatile
				{
					return mp_BoundObject;
				}
				CToBind const volatile &fp_BoundObject() const volatile
				{
					return mp_BoundObject;
				}

				struct CDummy
				{
				};

				template <typename tf_CToBind>
				TCBoundFunctionBase(tf_CToBind &&_ToBind)
					: mp_BoundObject(fg_Forward<tf_CToBind>(_ToBind))
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase &&_Other)
					: mp_BoundObject(fg_Move(_Other.mp_BoundObject))
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase &_Other)
					: mp_BoundObject(_Other.mp_BoundObject)
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase const &_Other)
					: mp_BoundObject(_Other.mp_BoundObject)
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase volatile &_Other)
					: mp_BoundObject(_Other.mp_BoundObject)
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase const volatile &_Other)
					: mp_BoundObject(_Other.mp_BoundObject)
				{
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase &&_Other)
				{
					mp_BoundObject = fg_Move(_Other.mp_BoundObject);
					return *this;
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase &_Other)
				{
					mp_BoundObject = _Other.mp_BoundObject;
					return *this;
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase const &_Other)
				{
					mp_BoundObject = _Other.mp_BoundObject;
					return *this;
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase volatile &_Other)
				{
					mp_BoundObject = _Other.mp_BoundObject;
					return *this;
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase const volatile &_Other)
				{
					mp_BoundObject = _Other.mp_BoundObject;
					return *this;
				}

				void operator () (CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy)
				{
				}
			};

			template <typename t_CBFOpts>
			struct TCBoundFunctionBase<t_CBFOpts, true>
			{
				typedef typename t_CBFOpts::CToBind CToBind;
				typedef t_CBFOpts CBindOptions;

				// Just let the this pointer point to this. Should not matter as the object has no storage
				CToBind &fp_BoundObject()
				{
					return *((CToBind *)this);
				}
				CToBind const &fp_BoundObject() const
				{
					return *((CToBind *)this);
				}
				CToBind volatile &fp_BoundObject() volatile
				{
					return *((CToBind *)this);
				}
				CToBind const volatile &fp_BoundObject() const volatile
				{
					return *((CToBind *)this);
				}

				struct CDummy
				{
				};

				template <typename tf_CToBind>
				TCBoundFunctionBase(tf_CToBind &&_ToBind)
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase &&_Other)
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase &_Other)
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase const &_Other)
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase volatile &_Other)
				{
				}

				TCBoundFunctionBase(TCBoundFunctionBase const volatile &_Other)
				{
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase &&_Other)
				{
					return *this;
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase &_Other)
				{
					return *this;
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase const &_Other)
				{
					return *this;
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase volatile &_Other)
				{
					return *this;
				}

				TCBoundFunctionBase &operator =(TCBoundFunctionBase const volatile &_Other)
				{
					return *this;
				}

				void operator () (CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy, CDummy)
				{
				}
			};

			template
			<
				typename t_CBFOpts
				, int t_iParam = t_CBFOpts::mc_NumParams - 1
				, typename t_CParam = typename t_CBFOpts::template TCParam<t_iParam>::CType
				, bint t_bIsEmpty = NTraits::TCIsEmpty<t_CParam>::mc_Value && NTraits::TCIsPOD<t_CParam>::mc_Value
			>
			struct TCBindExpressionParam 
				: public TCBindExpressionParam<t_CBFOpts, t_iParam - 1>
			{
				typedef TCBindExpressionParam<t_CBFOpts, t_iParam - 1> CSuper;
				typedef t_CParam CParam;
				using CSuper::operator ();

				t_CParam mp_Param;

				TCBindExpressionParam(TCBindExpressionParam &&_Other)
					: CSuper((CSuper &&)_Other)
					, mp_Param(fg_Move(_Other.mp_Param))
				{
				}

				TCBindExpressionParam(TCBindExpressionParam &_Other)
					: CSuper((CSuper &)_Other)
					, mp_Param(_Other.mp_Param)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam const &_Other)
					: CSuper((CSuper const &)_Other)
					, mp_Param(_Other.mp_Param)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam volatile &_Other)
					: CSuper((CSuper volatile &)_Other)
					, mp_Param(_Other.mp_Param)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam const volatile &_Other)
					: CSuper((CSuper const volatile &)_Other)
					, mp_Param(_Other.mp_Param)
				{
				}

				TCBindExpressionParam &operator =(TCBindExpressionParam &&_Other)
				{
					(*((CSuper *)this)) = ((CSuper &&)_Other);
					mp_Param = fg_Move(_Other.mp_Param);
					return *this;
				}
				TCBindExpressionParam &operator =(TCBindExpressionParam &_Other)
				{
					(*((CSuper *)this)) = ((CSuper &)_Other);
					mp_Param = _Other.mp_Param;
					return *this;
				}
				TCBindExpressionParam &operator =(TCBindExpressionParam const &_Other)
				{
					(*((CSuper *)this)) = ((CSuper const &)_Other);
					mp_Param = _Other.mp_Param;
					return *this;
				}
				TCBindExpressionParam &operator =(TCBindExpressionParam volatile &_Other)
				{
					(*((CSuper *)this)) = ((CSuper volatile &)_Other);
					mp_Param = _Other.mp_Param;
					return *this;
				}
				TCBindExpressionParam &operator =(TCBindExpressionParam const volatile &_Other)
				{
					(*((CSuper *)this)) = ((CSuper const volatile &)_Other);
					mp_Param = _Other.mp_Param;
					return *this;
				}

				template <typename tf_CToBind, typename tf_CP0>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind))
					, mp_Param(fg_Forward<tf_CP0>(_P0))
				{
					static_assert(t_iParam == 0, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0))
					, mp_Param(fg_Forward<tf_CP1>(_P1))
				{
					static_assert(t_iParam == 1, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1))
					, mp_Param(fg_Forward<tf_CP2>(_P2))
				{
					static_assert(t_iParam == 2, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2))
					, mp_Param(fg_Forward<tf_CP3>(_P3))
				{
					static_assert(t_iParam == 3, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3))
					, mp_Param(fg_Forward<tf_CP4>(_P4))
				{
					static_assert(t_iParam == 4, "Incorrect number of initializers");
				}
#ifndef DMibRestrictNumberOfBindParams

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3), fg_Forward<tf_CP4>(_P4))
					, mp_Param(fg_Forward<tf_CP5>(_P5))
				{
					static_assert(t_iParam == 5, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
					)
					, mp_Param(fg_Forward<tf_CP6>(_P6))
				{
					static_assert(t_iParam == 6, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6, typename tf_CP7>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
					)
					, mp_Param(fg_Forward<tf_CP7>(_P7))
				{
					static_assert(t_iParam == 7, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6, typename tf_CP7, typename tf_CP8>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
					)
					, mp_Param(fg_Forward<tf_CP8>(_P8))
				{
					static_assert(t_iParam == 8, "Incorrect number of initializers");
				}

				template 
				<
					typename tf_CToBind
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
				>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8, tf_CP9 &&_P9)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
					)
					, mp_Param(fg_Forward<tf_CP9>(_P9))
				{
					static_assert(t_iParam == 9, "Incorrect number of initializers");
				}
#endif

			};

			template <typename t_CBFOpts, int t_iParam, typename t_CParam>
			struct TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, true> 
				: public TCBindExpressionParam<t_CBFOpts, t_iParam - 1>
			{
				typedef TCBindExpressionParam<t_CBFOpts, t_iParam - 1> CSuper;
				typedef t_CParam CParam;
				using CSuper::operator ();

				static t_CParam mp_Param;

				TCBindExpressionParam(TCBindExpressionParam &&_Other)
					: CSuper((CSuper &&)_Other)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam &_Other)
					: CSuper((CSuper &)_Other)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam const &_Other)
					: CSuper((CSuper const &)_Other)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam volatile &_Other)
					: CSuper((CSuper volatile &)_Other)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam const volatile &_Other)
					: CSuper((CSuper const volatile &)_Other)
				{
				}

				TCBindExpressionParam &operator =(TCBindExpressionParam &&_Other)
				{
					(*((CSuper *)this)) = ((CSuper &&)_Other);
					return *this;
				}
				TCBindExpressionParam &operator =(TCBindExpressionParam &_Other)
				{
					(*((CSuper *)this)) = ((CSuper &)_Other);
					return *this;
				}
				TCBindExpressionParam &operator =(TCBindExpressionParam const &_Other)
				{
					(*((CSuper *)this)) = ((CSuper const &)_Other);
					return *this;
				}
				TCBindExpressionParam &operator =(TCBindExpressionParam volatile &_Other)
				{
					(*((CSuper *)this)) = ((CSuper volatile &)_Other);
					return *this;
				}
				TCBindExpressionParam &operator =(TCBindExpressionParam const volatile &_Other)
				{
					(*((CSuper *)this)) = ((CSuper const volatile &)_Other);
					return *this;
				}

				template <typename tf_CToBind, typename tf_CP0>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind))
				{
					static_assert(t_iParam == 0, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0))
				{
					static_assert(t_iParam == 1, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1))
				{
					static_assert(t_iParam == 2, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2))
				{
					static_assert(t_iParam == 3, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3))
				{
					static_assert(t_iParam == 4, "Incorrect number of initializers");
				}

#ifndef DMibRestrictNumberOfBindParams

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5)
					: CSuper(fg_Forward<tf_CToBind>(_ToBind), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3), fg_Forward<tf_CP4>(_P4))
				{
					static_assert(t_iParam == 5, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
					)
				{
					static_assert(t_iParam == 6, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6, typename tf_CP7>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
					)
				{
					static_assert(t_iParam == 7, "Incorrect number of initializers");
				}

				template <typename tf_CToBind, typename tf_CP0, typename tf_CP1, typename tf_CP2, typename tf_CP3, typename tf_CP4, typename tf_CP5, typename tf_CP6, typename tf_CP7, typename tf_CP8>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
					)
				{
					static_assert(t_iParam == 8, "Incorrect number of initializers");
				}

				template 
				<
					typename tf_CToBind
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
				>
				TCBindExpressionParam(tf_CToBind &&_ToBind, tf_CP0 &&_P0, tf_CP1 &&_P1, tf_CP2 &&_P2, tf_CP3 &&_P3, tf_CP4 &&_P4, tf_CP5 &&_P5, tf_CP6 &&_P6, tf_CP7 &&_P7, tf_CP8 &&_P8, tf_CP9 &&_P9)
					: CSuper
					(
						fg_Forward<tf_CToBind>(_ToBind)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
					)
				{
					static_assert(t_iParam == 9, "Incorrect number of initializers");
				}
#endif
			};

			template <typename t_CBFOpts, int t_iParam, typename t_CParam>
			t_CParam TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, true>::mp_Param = {};


			template <typename t_CBFOpts, typename t_CParam, bint t_bIsEmpty>
			struct TCBindExpressionParam<t_CBFOpts, -1, t_CParam, t_bIsEmpty> 
				: public TCBoundFunctionBase<t_CBFOpts>
			{
				typedef TCBoundFunctionBase<t_CBFOpts> CSuper;

				using CSuper::operator ();

				TCBindExpressionParam(TCBindExpressionParam &&_Other)
					: CSuper((CSuper &&)_Other)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam &_Other)
					: CSuper((CSuper &)_Other)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam const &_Other)
					: CSuper((CSuper const &)_Other)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam volatile &_Other)
					: CSuper((CSuper volatile &)_Other)
				{
				}

				TCBindExpressionParam(TCBindExpressionParam const volatile &_Other)
					: CSuper((CSuper const volatile &)_Other)
				{
				}

				TCBindExpressionParam &operator =(TCBindExpressionParam &&_Other)
				{
					(*((CSuper *)this)) = ((CSuper &&)_Other);
					return *this;
				}

				TCBindExpressionParam &operator =(TCBindExpressionParam &_Other)
				{
					(*((CSuper *)this)) = ((CSuper &)_Other);
					return *this;
				}

				TCBindExpressionParam &operator =(TCBindExpressionParam const &_Other)
				{
					(*((CSuper *)this)) = ((CSuper const &)_Other);
					return *this;
				}

				TCBindExpressionParam &operator =(TCBindExpressionParam volatile &_Other)
				{
					(*((CSuper *)this)) = ((CSuper volatile &)_Other);
					return *this;
				}

				TCBindExpressionParam &operator =(TCBindExpressionParam const volatile &_Other)
				{
					(*((CSuper *)this)) = ((CSuper const volatile &)_Other);
					return *this;
				}

				template <typename t_CToBind>
				TCBindExpressionParam(t_CToBind &&_ToBind)
					: CSuper(fg_Forward<t_CToBind>(_ToBind))
				{
				}
			};


			template <typename t_CType, int t_iParam>
			struct TCGetBindExpressionStoredParam
			{
			};

			template <typename t_CBFOpts, typename t_CParam, bint t_bIsEmpty, int t_iParam, int t_iParamToGet>
			struct TCGetBindExpressionStoredParam<TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, t_bIsEmpty>, t_iParamToGet>
			{
				typedef TCBindExpressionParam<t_CBFOpts, t_iParamToGet> CBindExpressionParam;
				typedef typename CBindExpressionParam::CParam CType;

				static CType &fs_Get(TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, t_bIsEmpty> &_This)
				{
					return static_cast<CBindExpressionParam &>(_This).mp_Param;
				}
				static CType const &fs_Get(TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, t_bIsEmpty> const &_This)
				{
					return static_cast<CBindExpressionParam const &>(_This).mp_Param;
				}
				static CType volatile &fs_Get(TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, t_bIsEmpty> volatile &_This)
				{
					return static_cast<CBindExpressionParam volatile &>(_This).mp_Param;
				}
				static CType const volatile &fs_Get(TCBindExpressionParam<t_CBFOpts, t_iParam, t_CParam, t_bIsEmpty> const volatile &_This)
				{
					return static_cast<CBindExpressionParam const volatile &>(_This).mp_Param;
				}
			};

			/// @endcond
		}
	}
}

