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
			struct TCGetBindParamDefault<0>
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
				static auto fs_Param
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
				-> tf_CP0
				{
					return _P0;
				}
			};
			template <>
			struct TCGetBindParamDefault<1>
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
				static auto fs_Param
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
				-> tf_CP1
				{
					return _P1;
				}
			};
			template <>
			struct TCGetBindParamDefault<2>
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
				static auto fs_Param
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
				-> tf_CP2
				{
					return _P2;
				}
			};
			template <>
			struct TCGetBindParamDefault<3>
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
				static auto fs_Param
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
				-> tf_CP3
				{
					return _P3;
				}
			};
			template <>
			struct TCGetBindParamDefault<4>
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
				static auto fs_Param
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
				-> tf_CP4
				{
					return _P4;
				}
			};
#ifndef DMibRestrictNumberOfBindParams
			template <>
			struct TCGetBindParamDefault<5>
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
				static auto fs_Param
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
				-> tf_CP5
				{
					return _P5;
				}
			};
			template <>
			struct TCGetBindParamDefault<6>
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
				static auto fs_Param
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
				-> tf_CP6
				{
					return _P6;
				}
			};
			template <>
			struct TCGetBindParamDefault<7>
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
				static auto fs_Param
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
				-> tf_CP7
				{
					return _P7;
				}
			};
			template <>
			struct TCGetBindParamDefault<8>
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
				static auto fs_Param
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
				-> tf_CP8
				{
					return _P8;
				}
			};
			template <>
			struct TCGetBindParamDefault<9>
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
				static auto fs_Param
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
				-> tf_CP9
				{
					return _P9;
				}
			};
#endif
		}
	}
}

