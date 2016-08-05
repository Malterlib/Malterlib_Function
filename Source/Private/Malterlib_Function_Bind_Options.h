// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{
			template 
			<
				typename t_CToBind
				, typename t_C0 = void
				, typename t_C1 = void
				, typename t_C2 = void
				, typename t_C3 = void
				, typename t_C4 = void
				, typename t_C5 = void
				, typename t_C6 = void
				, typename t_C7 = void
				, typename t_C8 = void
#ifndef DMibRestrictNumberOfBindParams
				, typename t_C9 = void
				, typename t_C10 = void
				, typename t_C11 = void
				, typename t_C12 = void
				, typename t_C13 = void
#endif
			>
			struct TCBindOptions
			{
				typedef t_CToBind CToBind;

				static constexpr bint mc_bSupportCompare
					= NTraits::TCIsSame<t_C0, CBindSupportCompareTag>::mc_Value 
					|| NTraits::TCIsSame<t_C1, CBindSupportCompareTag>::mc_Value 
					|| NTraits::TCIsSame<t_C2, CBindSupportCompareTag>::mc_Value 
					|| NTraits::TCIsSame<t_C3, CBindSupportCompareTag>::mc_Value 
					|| NTraits::TCIsSame<t_C4, CBindSupportCompareTag>::mc_Value 
					|| NTraits::TCIsSame<t_C5, CBindSupportCompareTag>::mc_Value 
					|| NTraits::TCIsSame<t_C6, CBindSupportCompareTag>::mc_Value 
					|| NTraits::TCIsSame<t_C7, CBindSupportCompareTag>::mc_Value
					|| NTraits::TCIsSame<t_C8, CBindSupportCompareTag>::mc_Value
#ifndef DMibRestrictNumberOfBindParams
					|| NTraits::TCIsSame<t_C9, CBindSupportCompareTag>::mc_Value
					|| NTraits::TCIsSame<t_C10, CBindSupportCompareTag>::mc_Value
					|| NTraits::TCIsSame<t_C11, CBindSupportCompareTag>::mc_Value
					|| NTraits::TCIsSame<t_C12, CBindSupportCompareTag>::mc_Value
					|| NTraits::TCIsSame<t_C13, CBindSupportCompareTag>::mc_Value
#endif
				;

				static constexpr bint mc_bEnableNesting
					= !NTraits::TCIsSame<t_C0, CBindNoNestTag>::mc_Value 
					&& !NTraits::TCIsSame<t_C1, CBindNoNestTag>::mc_Value 
					&& !NTraits::TCIsSame<t_C2, CBindNoNestTag>::mc_Value 
					&& !NTraits::TCIsSame<t_C3, CBindNoNestTag>::mc_Value 
					&& !NTraits::TCIsSame<t_C4, CBindNoNestTag>::mc_Value 
					&& !NTraits::TCIsSame<t_C5, CBindNoNestTag>::mc_Value 
					&& !NTraits::TCIsSame<t_C6, CBindNoNestTag>::mc_Value 
					&& !NTraits::TCIsSame<t_C7, CBindNoNestTag>::mc_Value
					&& !NTraits::TCIsSame<t_C8, CBindNoNestTag>::mc_Value
#ifndef DMibRestrictNumberOfBindParams
					&& !NTraits::TCIsSame<t_C9, CBindNoNestTag>::mc_Value
					&& !NTraits::TCIsSame<t_C10, CBindNoNestTag>::mc_Value
					&& !NTraits::TCIsSame<t_C11, CBindNoNestTag>::mc_Value
					&& !NTraits::TCIsSame<t_C12, CBindNoNestTag>::mc_Value
					&& !NTraits::TCIsSame<t_C13, CBindNoNestTag>::mc_Value
#endif
				;

				static constexpr bint mc_bForwardExtra
					= TCIsBindForwardExtra<t_C0>::mc_Value
					+ TCIsBindForwardExtra<t_C1>::mc_Value
					+ TCIsBindForwardExtra<t_C2>::mc_Value
					+ TCIsBindForwardExtra<t_C3>::mc_Value
					+ TCIsBindForwardExtra<t_C4>::mc_Value
					+ TCIsBindForwardExtra<t_C5>::mc_Value
					+ TCIsBindForwardExtra<t_C6>::mc_Value
					+ TCIsBindForwardExtra<t_C7>::mc_Value
					+ TCIsBindForwardExtra<t_C8>::mc_Value
#ifndef DMibRestrictNumberOfBindParams
					+ TCIsBindForwardExtra<t_C9>::mc_Value
					+ TCIsBindForwardExtra<t_C10>::mc_Value
					+ TCIsBindForwardExtra<t_C11>::mc_Value
					+ TCIsBindForwardExtra<t_C12>::mc_Value
					+ TCIsBindForwardExtra<t_C13>::mc_Value
#endif
				;

				static constexpr mint mc_ForwardExtraLevel
					= TCIsBindForwardExtra<t_C0>::mc_Value ? TCIsBindForwardExtra<t_C0>::mc_Level
					: TCIsBindForwardExtra<t_C1>::mc_Value ? TCIsBindForwardExtra<t_C1>::mc_Level
					: TCIsBindForwardExtra<t_C2>::mc_Value ? TCIsBindForwardExtra<t_C2>::mc_Level
					: TCIsBindForwardExtra<t_C3>::mc_Value ? TCIsBindForwardExtra<t_C3>::mc_Level
					: TCIsBindForwardExtra<t_C4>::mc_Value ? TCIsBindForwardExtra<t_C4>::mc_Level
					: TCIsBindForwardExtra<t_C5>::mc_Value ? TCIsBindForwardExtra<t_C5>::mc_Level
					: TCIsBindForwardExtra<t_C6>::mc_Value ? TCIsBindForwardExtra<t_C6>::mc_Level
					: TCIsBindForwardExtra<t_C7>::mc_Value ? TCIsBindForwardExtra<t_C7>::mc_Level
					: TCIsBindForwardExtra<t_C8>::mc_Value ? TCIsBindForwardExtra<t_C8>::mc_Level
#ifndef DMibRestrictNumberOfBindParams
					: TCIsBindForwardExtra<t_C9>::mc_Value ? TCIsBindForwardExtra<t_C9>::mc_Level
					: TCIsBindForwardExtra<t_C10>::mc_Value ? TCIsBindForwardExtra<t_C10>::mc_Level
					: TCIsBindForwardExtra<t_C11>::mc_Value ? TCIsBindForwardExtra<t_C11>::mc_Level
					: TCIsBindForwardExtra<t_C12>::mc_Value ? TCIsBindForwardExtra<t_C12>::mc_Level
					: TCIsBindForwardExtra<t_C13>::mc_Value ? TCIsBindForwardExtra<t_C13>::mc_Level
#endif
					: 0xffffffff
				;

				static_assert(mc_bForwardExtra <= 1, "You can only specify one extra forwarding level");

				static constexpr uint32 mc_IgnoredParamsExplicit
					= TCIsIgnoreParamsTag<t_C0>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C1>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C2>::mc_IgnoredExplicit 
					| TCIsIgnoreParamsTag<t_C3>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C4>::mc_IgnoredExplicit 
					| TCIsIgnoreParamsTag<t_C5>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C6>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C7>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C8>::mc_IgnoredExplicit
#ifndef DMibRestrictNumberOfBindParams
					| TCIsIgnoreParamsTag<t_C9>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C10>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C11>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C12>::mc_IgnoredExplicit
					| TCIsIgnoreParamsTag<t_C13>::mc_IgnoredExplicit
#endif
				;

				static constexpr uint32 mc_IgnoredParamsImplicit
					= mc_IgnoredParamsExplicit
					| TCIsIgnoreParamsTag<t_C0>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C1>::mc_IgnoredImplicit 
					| TCIsIgnoreParamsTag<t_C2>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C3>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C4>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C5>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C6>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C7>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C8>::mc_IgnoredImplicit
#ifndef DMibRestrictNumberOfBindParams
					| TCIsIgnoreParamsTag<t_C9>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C10>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C11>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C12>::mc_IgnoredImplicit
					| TCIsIgnoreParamsTag<t_C13>::mc_IgnoredImplicit
#endif
				;

				// Contracts
				static constexpr int mc_NumParams 
					= TCChooseInt
					<
						int
						, !TCIsBindParam<t_C0>::mc_Value
						, 0
						, TCChooseInt
						<
							int
							, !TCIsBindParam<t_C1>::mc_Value
							, 1
							, TCChooseInt
							<
								int
								, !TCIsBindParam<t_C2>::mc_Value
								, 2
								, TCChooseInt
								<
									int
									, !TCIsBindParam<t_C3>::mc_Value
									, 3
									, TCChooseInt
									<
										int
										, !TCIsBindParam<t_C4>::mc_Value
										, 4
	#ifndef DMibRestrictNumberOfBindParams
										, TCChooseInt
										<
											int
											, !TCIsBindParam<t_C5>::mc_Value
											, 5
											, TCChooseInt
											<
												int
												, !TCIsBindParam<t_C6>::mc_Value
												, 6
												, TCChooseInt
												<
													int
													, !TCIsBindParam<t_C7>::mc_Value
													, 7
													, TCChooseInt
													<
														int
														, !TCIsBindParam<t_C8>::mc_Value
														, 8
														, TCChooseInt
														<
															int
															, !TCIsBindParam<t_C9>::mc_Value
															, 9
															, 10
														>::mc_Value
													>::mc_Value
												>::mc_Value
											>::mc_Value
										>::mc_Value
	#else
										, 5
	#endif
									>::mc_Value
								>::mc_Value
							>::mc_Value
						>::mc_Value
					>::mc_Value
				;
				
#ifndef DMibRestrictNumberOfBindParams
				static constexpr mint mc_MaxParams = 10;
#else
				static constexpr mint mc_MaxParams = 5;
#endif

				static_assert(mc_NumParams >= 1 || !TCIsBindParam<t_C0>::mc_Value, "All param definitions have to be specified before options");
				static_assert(mc_NumParams >= 2 || !TCIsBindParam<t_C1>::mc_Value, "All param definitions have to be specified before options");
				static_assert(mc_NumParams >= 3 || !TCIsBindParam<t_C2>::mc_Value, "All param definitions have to be specified before options");
				static_assert(mc_NumParams >= 4 || !TCIsBindParam<t_C3>::mc_Value, "All param definitions have to be specified before options");
				static_assert(mc_NumParams >= 5 || !TCIsBindParam<t_C4>::mc_Value, "All param definitions have to be specified before options");
#ifndef DMibRestrictNumberOfBindParams
				static_assert(mc_NumParams >= 6 || !TCIsBindParam<t_C5>::mc_Value, "All param definitions have to be specified before options");
				static_assert(mc_NumParams >= 7 || !TCIsBindParam<t_C6>::mc_Value, "All param definitions have to be specified before options");
				static_assert(mc_NumParams >= 8 || !TCIsBindParam<t_C7>::mc_Value, "All param definitions have to be specified before options");
				static_assert(mc_NumParams >= 9 || !TCIsBindParam<t_C8>::mc_Value, "All param definitions have to be specified before options");
				static_assert(mc_NumParams >= 10 || !TCIsBindParam<t_C9>::mc_Value, "All param definitions have to be specified before options");
#endif

				typedef typename NTraits::TCAddReference<t_C0>::CType C0R;
				typedef typename NTraits::TCAddReference<t_C1>::CType C1R;
				typedef typename NTraits::TCAddReference<t_C2>::CType C2R;
				typedef typename NTraits::TCAddReference<t_C3>::CType C3R;
				typedef typename NTraits::TCAddReference<t_C4>::CType C4R;
#ifndef DMibRestrictNumberOfBindParams
				typedef typename NTraits::TCAddReference<t_C5>::CType C5R;
				typedef typename NTraits::TCAddReference<t_C6>::CType C6R;
				typedef typename NTraits::TCAddReference<t_C7>::CType C7R;
				typedef typename NTraits::TCAddReference<t_C8>::CType C8R;
				typedef typename NTraits::TCAddReference<t_C9>::CType C9R;
#endif

				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C0>::CType>::CType C0CR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C1>::CType>::CType C1CR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C2>::CType>::CType C2CR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C3>::CType>::CType C3CR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C4>::CType>::CType C4CR;
#ifndef DMibRestrictNumberOfBindParams
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C5>::CType>::CType C5CR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C6>::CType>::CType C6CR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C7>::CType>::CType C7CR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C8>::CType>::CType C8CR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddConst<t_C9>::CType>::CType C9CR;
#endif

				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C0>::CType>::CType C0VR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C1>::CType>::CType C1VR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C2>::CType>::CType C2VR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C3>::CType>::CType C3VR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C4>::CType>::CType C4VR;
#ifndef DMibRestrictNumberOfBindParams
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C5>::CType>::CType C5VR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C6>::CType>::CType C6VR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C7>::CType>::CType C7VR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C8>::CType>::CType C8VR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<t_C9>::CType>::CType C9VR;
#endif

				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C0>::CType>::CType>::CType C0CVR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C1>::CType>::CType>::CType C1CVR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C2>::CType>::CType>::CType C2CVR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C3>::CType>::CType>::CType C3CVR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C4>::CType>::CType>::CType C4CVR;
#ifndef DMibRestrictNumberOfBindParams
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C5>::CType>::CType>::CType C5CVR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C6>::CType>::CType>::CType C6CVR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C7>::CType>::CType>::CType C7CVR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C8>::CType>::CType>::CType C8CVR;
				typedef typename NTraits::TCAddReference<typename NTraits::TCAddVolatile<typename NTraits::TCAddConst<t_C9>::CType>::CType>::CType C9CVR;
#endif

				typedef typename TCMakeFunctionType
				<
					mc_NumParams
					, C0R
					, C1R
					, C2R
					, C3R
					, C4R
#ifndef DMibRestrictNumberOfBindParams
					, C5R
					, C6R
					, C7R
					, C8R
					, C9R
#endif
				>::CType CBoundParamsFunc;

				typedef typename TCMakeFunctionType
				<
					mc_NumParams
					, C0CR
					, C1CR
					, C2CR
					, C3CR
					, C4CR
#ifndef DMibRestrictNumberOfBindParams
					, C5CR
					, C6CR
					, C7CR
					, C8CR
					, C9CR
#endif
				>::CType CBoundParamsFuncConst;

				typedef typename TCMakeFunctionType
				<
					mc_NumParams
					, C0VR
					, C1VR
					, C2VR
					, C3VR
					, C4VR
#ifndef DMibRestrictNumberOfBindParams
					, C5VR
					, C6VR
					, C7VR
					, C8VR
					, C9VR
#endif
				>::CType CBoundParamsFuncVolatile;

				typedef typename TCMakeFunctionType
				<
					mc_NumParams
					, C0CVR
					, C1CVR
					, C2CVR
					, C3CVR
					, C4CVR
#ifndef DMibRestrictNumberOfBindParams
					, C5CVR
					, C6CVR
					, C7CVR
					, C8CVR
					, C9CVR
#endif
				>::CType CBoundParamsFuncConstVolatile;


				typedef typename TCChooseType<(mc_NumParams > 0), t_C0, void>::CType CParam0;
				typedef typename TCChooseType<(mc_NumParams > 1), t_C1, void>::CType CParam1;
				typedef typename TCChooseType<(mc_NumParams > 2), t_C2, void>::CType CParam2;
				typedef typename TCChooseType<(mc_NumParams > 3), t_C3, void>::CType CParam3;
				typedef typename TCChooseType<(mc_NumParams > 4), t_C4, void>::CType CParam4;
#ifndef DMibRestrictNumberOfBindParams
				typedef typename TCChooseType<(mc_NumParams > 5), t_C5, void>::CType CParam5;
				typedef typename TCChooseType<(mc_NumParams > 6), t_C6, void>::CType CParam6;
				typedef typename TCChooseType<(mc_NumParams > 7), t_C7, void>::CType CParam7;
				typedef typename TCChooseType<(mc_NumParams > 8), t_C8, void>::CType CParam8;
				typedef typename TCChooseType<(mc_NumParams > 9), t_C9, void>::CType CParam9;
#endif

				template <int t_iParam, typename t_CDummy = void>
				struct TCParam { typedef void CType;};
				template <typename t_CDummy> struct TCParam<0, t_CDummy> { typedef CParam0 CType; };
				template <typename t_CDummy> struct TCParam<1, t_CDummy> { typedef CParam1 CType; };
				template <typename t_CDummy> struct TCParam<2, t_CDummy> { typedef CParam2 CType; };
				template <typename t_CDummy> struct TCParam<3, t_CDummy> { typedef CParam3 CType; };
				template <typename t_CDummy> struct TCParam<4, t_CDummy> { typedef CParam4 CType; };
#ifndef DMibRestrictNumberOfBindParams
				template <typename t_CDummy> struct TCParam<5, t_CDummy> { typedef CParam5 CType; };
				template <typename t_CDummy> struct TCParam<6, t_CDummy> { typedef CParam6 CType; };
				template <typename t_CDummy> struct TCParam<7, t_CDummy> { typedef CParam7 CType; };
				template <typename t_CDummy> struct TCParam<8, t_CDummy> { typedef CParam8 CType; };
				template <typename t_CDummy> struct TCParam<9, t_CDummy> { typedef CParam9 CType; };
#endif
			};
		}
	}
}

