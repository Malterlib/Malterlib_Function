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
			struct TCCallBindExpression<0>
			{
				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)()
				)
				{
					return fg_Forward<tf_CObject>(_Object)();
				}

				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Bind(fg_Forward<tf_CObject>(_Object))
				)
				{
					return fg_Bind(fg_Forward<tf_CObject>(_Object));
				}
			};

			template <>
			struct TCCallBindExpression<1>
			{
				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0))
				)
				{
					return fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0));
				}

				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0))
				)
				{
					return fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0));
				}
			};

			template <>
			struct TCCallBindExpression<2>
			{
				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1))
				)
				{
					return fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1));
				}

				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1))
				)
				{
					return fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1));
				}

			};

			template <>
			struct TCCallBindExpression<3>
			{
				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2))
				)
				{
					return fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2));
				}

				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2))
				)
				{
					return fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2));
				}
			};

			template <>
			struct TCCallBindExpression<4>
			{
				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3))
				)
				{
					return fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3));
				}

				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3))
				)
				{
					return fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3));
				}
			};

			template <>
			struct TCCallBindExpression<5>
			{
				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3), fg_Forward<tf_CP4>(_P4))
				)
				{
					return fg_Forward<tf_CObject>(_Object)(fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3), fg_Forward<tf_CP4>(_P4));
				}

				template 
				<	
					typename tf_CObject
					, typename tf_CP0
					, typename tf_CP1
					, typename tf_CP2
					, typename tf_CP3
					, typename tf_CP4
#ifndef DMibRestrictNumberOfBindParams
					, typename tf_CP5
					, typename tf_CP6
					, typename tf_CP7
					, typename tf_CP8
					, typename tf_CP9
#endif
				>
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
#ifndef DMibRestrictNumberOfBindParams
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
#endif
				)
				-> 
				decltype
				(
					fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3), fg_Forward<tf_CP4>(_P4))
				)
				{
					return fg_Bind(fg_Forward<tf_CObject>(_Object), fg_Forward<tf_CP0>(_P0), fg_Forward<tf_CP1>(_P1), fg_Forward<tf_CP2>(_P2), fg_Forward<tf_CP3>(_P3), fg_Forward<tf_CP4>(_P4));
				}
			};

#ifndef DMibRestrictNumberOfBindParams

			template <>
			struct TCCallBindExpression<6>
			{
				template 
				<	
					typename tf_CObject
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
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
					)
				)
				{
					return fg_Forward<tf_CObject>(_Object)
						(
							fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
						)
					;
				}

				template 
				<	
					typename tf_CObject
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
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				-> 
				decltype
				(
					fg_Bind
					(
						fg_Forward<tf_CObject>(_Object)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
					)
				)
				{
					return fg_Bind
						(
							fg_Forward<tf_CObject>(_Object)
							, fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
						)
					;
				}
			};

			template <>
			struct TCCallBindExpression<7>
			{
				template 
				<	
					typename tf_CObject
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
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
					)
				)
				{
					return fg_Forward<tf_CObject>(_Object)
						(
							fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
							, fg_Forward<tf_CP6>(_P6)
						)
					;
				}

				template 
				<	
					typename tf_CObject
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
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				-> 
				decltype
				(
					fg_Bind
					(
						fg_Forward<tf_CObject>(_Object)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
					)
				)
				{
					return fg_Bind
						(
							fg_Forward<tf_CObject>(_Object)
							, fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
							, fg_Forward<tf_CP6>(_P6)
						)
					;
				}
			};

			template <>
			struct TCCallBindExpression<8>
			{
				template 
				<	
					typename tf_CObject
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
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
					)
				)
				{
					return fg_Forward<tf_CObject>(_Object)
						(
							fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
							, fg_Forward<tf_CP6>(_P6)
							, fg_Forward<tf_CP7>(_P7)
						)
					;
				}

				template 
				<	
					typename tf_CObject
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
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				-> 
				decltype
				(
					fg_Bind
					(
						fg_Forward<tf_CObject>(_Object)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
					)
				)
				{
					return fg_Bind
						(
							fg_Forward<tf_CObject>(_Object)
							, fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
							, fg_Forward<tf_CP6>(_P6)
							, fg_Forward<tf_CP7>(_P7)
						)
					;
				}
			};

			template <>
			struct TCCallBindExpression<9>
			{
				template 
				<	
					typename tf_CObject
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
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				-> 
				decltype
				(
					fg_Forward<tf_CObject>(_Object)
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
					)
				)
				{
					return fg_Forward<tf_CObject>(_Object)
						(
							fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
							, fg_Forward<tf_CP6>(_P6)
							, fg_Forward<tf_CP7>(_P7)
							, fg_Forward<tf_CP8>(_P8)
						)
					;
				}

				template 
				<	
					typename tf_CObject
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
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				-> 
				decltype
				(
					fg_Bind
					(
						fg_Forward<tf_CObject>(_Object)
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
				)
				{
					return fg_Bind
						(
							fg_Forward<tf_CObject>(_Object)
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
					;
				}
			};

			template <>
			struct TCCallBindExpression<10>
			{
				template 
				<	
					typename tf_CObject
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
				static auto fs_Call
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				->
				decltype
				(
					fg_Forward<tf_CObject>(_Object)
					(
						fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
					)
				)
				{
					return fg_Forward<tf_CObject>(_Object)
						(
							fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
							, fg_Forward<tf_CP6>(_P6)
							, fg_Forward<tf_CP7>(_P7)
							, fg_Forward<tf_CP8>(_P8)
							, fg_Forward<tf_CP9>(_P9)
						)
					;
				}

				template 
				<	
					typename tf_CObject
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
				static auto fs_PartialBind
				(
					tf_CObject &&_Object
					, tf_CP0 &&_P0
					, tf_CP1 &&_P1
					, tf_CP2 &&_P2
					, tf_CP3 &&_P3
					, tf_CP4 &&_P4
					, tf_CP5 &&_P5
					, tf_CP6 &&_P6
					, tf_CP7 &&_P7
					, tf_CP8 &&_P8
					, tf_CP9 &&_P9
				)
				->
				decltype
				(
					fg_Bind
					(
						fg_Forward<tf_CObject>(_Object)
						, fg_Forward<tf_CP0>(_P0)
						, fg_Forward<tf_CP1>(_P1)
						, fg_Forward<tf_CP2>(_P2)
						, fg_Forward<tf_CP3>(_P3)
						, fg_Forward<tf_CP4>(_P4)
						, fg_Forward<tf_CP5>(_P5)
						, fg_Forward<tf_CP6>(_P6)
						, fg_Forward<tf_CP7>(_P7)
						, fg_Forward<tf_CP8>(_P8)
						, fg_Forward<tf_CP9>(_P9)
					)
				)
				{
					return fg_Bind
						(
							fg_Forward<tf_CObject>(_Object)
							, fg_Forward<tf_CP0>(_P0)
							, fg_Forward<tf_CP1>(_P1)
							, fg_Forward<tf_CP2>(_P2)
							, fg_Forward<tf_CP3>(_P3)
							, fg_Forward<tf_CP4>(_P4)
							, fg_Forward<tf_CP5>(_P5)
							, fg_Forward<tf_CP6>(_P6)
							, fg_Forward<tf_CP7>(_P7)
							, fg_Forward<tf_CP8>(_P8)
							, fg_Forward<tf_CP9>(_P9)
						)
					;
				}
			};
#endif


		}
	}
}

