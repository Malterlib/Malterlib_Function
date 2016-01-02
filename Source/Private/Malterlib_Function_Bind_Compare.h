// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{

			template <>
			struct TCDoCompare<0>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject();
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() < _Right.fp_BoundObject();
				}
			};

			template <>
			struct TCDoCompare<1>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<2>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<3>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<4>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<5>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<6>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<7>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<8>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<9>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 9>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 9>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 8>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 8>::fs_Get(_Right);
				}
			};

			template <>
			struct TCDoCompare<10>
			{
				template <typename tf_CType>
				static bint fs_Equal(tf_CType const &_Left, tf_CType const &_Right)
				{
					return _Left.fp_BoundObject() == _Right.fp_BoundObject()
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 9>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 9>::fs_Get(_Right)
						&& TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 10>::fs_Get(_Left) == TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 10>::fs_Get(_Right)
					;
				}

				template <typename tf_CType>
				static bint fs_Less(tf_CType const &_Left, tf_CType const &_Right)
				{
					auto &Left = _Left.fp_BoundObject();
					auto &Right = _Right.fp_BoundObject();
					if (Left < Right)
						return true;
					else if (Right < Left)
						return false;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 0>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 1>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 2>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 3>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 4>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 5>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 6>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 7>::fs_Get(_Left))
						return true;

					if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 8>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 8>::fs_Get(_Right))
						return true;
					else if (TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 8>::fs_Get(_Right) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 8>::fs_Get(_Left))
						return true;

					return TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 9>::fs_Get(_Left) < TCGetBindExpressionStoredParam<typename tf_CType::CParamSuper, 9>::fs_Get(_Right);
				}
			};
		}
	}
}

