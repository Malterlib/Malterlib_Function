// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#if !defined(DCompiler_MSVC_Workaround) || DMibCompilerVersion != 1912

#include <functional>
#include <boost/bind.hpp>
#include <stdio.h>

//#define DMibRestrictNumberOfBindParams

#include <Mib/Function/Function>
#include <Mib/Function/Bind>
#include <Mib/Storage/Indirection>

//#pragma optimize("", off)
//#pragma inline_depth(0)
// TODO:
// Exhaustive tests
// Performance tests
// Documentation
// Make sure const correctness works

namespace
{

	using namespace NMib::NFunction;
	using namespace NMib;

	void fg_Test()
	{
	}
	
	int fg_Value()
	{
		return 6;
	}
	
	int fg_Mult(int _x, int _y)
	{
		return _x * _y;
	}

#if 1
	int fg_MultFunctor(int _x, TCFunction<int (int)> const &_y)
	{
		return _x * _y(5);
	}
#else
	int fg_MultFunctor(int _x, ...)
	{
		return _x;
	}
#endif

	DMibStaticCheck(( TCIsPlaceholder<decltype(g_0)>::mc_Value ));
	DMibStaticCheck(( !TCIsPlaceholder<int>::mc_Value ));

	DMibStaticCheck(( !TCIsBindExpression<decltype(g_0)>::mc_Value ));
	DMibStaticCheck(( !TCIsBindExpression<int>::mc_Value ));
	DMibStaticCheck(( TCIsBindExpression<decltype(fg_Bind(&fg_Test))>::mc_Value ));

	namespace
	{
		class CBind_Tests 
			: public NTest::CTest
		{
		public:
			struct CBindFunctor
			{
				typedef int result_type;

				bint operator == (CBindFunctor const &_Right) const
				{
					return true;
				}

				bint operator < (CBindFunctor const &_Right) const
				{
					return false;
				}

				template <typename t_CType>
				struct result
				{
					typedef int type;
				};
				int operator () (int _Test, int _Test2, int _Test3, int _Test4) const
				{
					return _Test + _Test2 + _Test3 + _Test4;
				}
				float operator () (int _Test1) const
				{
					return _Test1;
				}

				float operator () (int _Test1, int _Test2) const
				{
					return _Test1 + _Test2;
				}

				double operator () (int _Test1)
				{
					return _Test1;
				}

				NStr::CStr operator () (int _Test1) volatile
				{
					return "Volatile";
				}

				NStr::CWStr operator () (int _Test1) const volatile
				{
					return "Const Volatile";
				}

				float operator () () const
				{
					return 5;
				}

				double operator () ()
				{
					return 7;
				}

/*				int operator () (TCFunction<int (int)> const &_Function)
				{
					return _Function(6);
				}*/

				NStr::CStr operator () () volatile
				{
					return "Volatile no param";
				}

				NStr::CWStr operator () () const volatile
				{
					return "Const Volatile no param";
				}

				NContainer::TCVector<int32> operator() (NContainer::TCVector<int32> const &_Vector)
				{
					return _Vector;
				}
			
				void f_UnaryTest()
				{
				}
				int f_UnaryTest2()
				{
					return 2;
				}
				void f_BinaryTest(int _x)
				{
				}
				int f_BinaryTest2(int _x)
				{
					return _x;
				}
				int f_BinaryTest3(int _x) volatile
				{
					return _x;
				}
			};

			class CTestMemberPtr
			{
			public:
				int m_Member;
				CTestMemberPtr()
					: m_Member(3)
				{
				}
			};
			
			class CTestMemberPointer
			{
			public:
				template <typename ft_CType>
				int operator ->* (ft_CType &_Var) const
				{
					return 2;
				}
			};

			template <typename t_CType>
			class TCTestMemberPointer
			{
			public:
				template <typename ft_CType>
				int operator ->* (ft_CType &_Var) const
				{
					return 2;
				}
			};

			
			void f_DoMemberPtrTests()
			{
				{
					NPtr::TCUniquePointer<CTestMemberPtr> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CTestMemberPtr::m_Member;
					auto TestInit = TestMemberPtr->*MemberPtr;
				}
				{
					NPtr::TCUniquePointer<CBindFunctor> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CBindFunctor::f_BinaryTest2;
					auto Result = (TestMemberPtr->*MemberPtr)(2);					
				}
				{
					auto MemberPtr = fg_MemberFunctionFunctor(&CBindFunctor::f_BinaryTest3);
					CBindFunctor Fununu;
					auto Result = MemberPtr(&Fununu, 2);
				}
				{
					NPtr::TCUniquePointer<CBindFunctor> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CBindFunctor::f_BinaryTest3;
					auto Result = (TestMemberPtr->*MemberPtr)(2);					
				}
				{
					NPtr::TCUniquePointer<CBindFunctor> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CBindFunctor::f_UnaryTest;
					(TestMemberPtr->*MemberPtr)();
				}
			}
			
			static void fs_Ellipsis(const ch8 *_pFormat, ...)
			{
			}
			
			void f_DoForwardExtraTests()
			{
				auto TraceInts
				= 
				fg_Bind<TCBindForwardExtraTag<>>
				(
				 &CBind_Tests::fs_Ellipsis
				 , "%i %i\r\n"
				 )
				;
				
				TraceInts(5, 5);
				TraceInts(3, 1);
				TraceInts(7, 9);
				
				CBindFunctor Functor;
				auto TestForwardBind
				= 
				fg_Bind<TCBindForwardExtraTag<>>
				(
				 Functor
				 )
				;
				
				auto Result = TestForwardBind(0,2,3,5);
				
				int ntohenuheu = 0;
			}
			
			void f_DoBindTests()
			{
				{
					CBindFunctor Functor;

					//auto Bound = fg_Bind(CFunctor(), g_0);
					//Bound;
					auto BoundStl = std::bind(Functor);

					int iTest = BoundStl(1,2,3,4,5,6,7,8,9,10);
					auto BoundBoost = boost::bind(Functor);
					iTest = BoundBoost(1,2,3,4,5,6,7,8,9);
					auto BoundMalterlib = fg_Bind<TCBindIgnoreParamsTag<0>>(Functor, 1);
					auto TestResult = BoundMalterlib(1);
					auto TestResult2 = fg_Const(BoundMalterlib)(1);
					auto TestResult3 = fg_Volatile(BoundMalterlib)(1);
					auto TestResult4 = fg_ConstVolatile(BoundMalterlib)(1);
					iTest = 5;

					auto BoundMalterlib1 = fg_Bind(Functor);
					auto TestResult11 = BoundMalterlib1();
					auto TestResult12 = fg_Const(BoundMalterlib1)();
					auto TestResult13 = fg_Volatile(BoundMalterlib1)();
					auto TestResult14 = fg_ConstVolatile(BoundMalterlib1)();

					auto BoundMalterlib2 = fg_Bind(Functor, 3);
					auto TestResult21 = BoundMalterlib2();
					auto TestResult22 = fg_Const(BoundMalterlib2)();
					auto TestResult23 = fg_Volatile(BoundMalterlib2)();
					auto TestResult24 = fg_ConstVolatile(BoundMalterlib2)();

					auto BoundMalterlib3 = fg_Bind<TCBindIgnoreParamsTag<>>(Functor, g_0);
					auto TestResult31 = BoundMalterlib3(2);
					auto TestResult32 = fg_Const(BoundMalterlib3)(3);
					auto TestResult33 = fg_Volatile(BoundMalterlib3)(4);
					auto TestResult34 = fg_ConstVolatile(BoundMalterlib3)(5);

					auto BoundMalterlib4 = fg_Bind<TCBindIgnoreParamsTag<0,1>>(Functor, g_2);
					auto TestResult41 = BoundMalterlib4(2, 1, 2);
					auto TestResult42 = fg_Const(BoundMalterlib4)(2, 1, 2);
					auto TestResult43 = fg_Volatile(BoundMalterlib4)(2, 1, 2);
					auto TestResult44 = fg_ConstVolatile(BoundMalterlib4)(2, 1, 2);

					NContainer::TCVector<int32> TestVector;
					TestVector.f_Insert(5);
					TestVector.f_Insert(7);
					TestVector.f_Insert(8);
					auto BoundMalterlib5 = fg_Bind(Functor, fg_Move(TestVector));
					auto TestResult51 = BoundMalterlib5();

					auto BoundMalterlib6 = fg_Move(BoundMalterlib5);
					auto TestResult61 = BoundMalterlib6();
					
					BoundMalterlib3(0);
					BoundMalterlib3(0,1);
					BoundMalterlib3(0,1,2);
					BoundMalterlib3(0,1,2,3);
					BoundMalterlib3(0,1,2,3,4);
#ifndef DMibRestrictNumberOfBindParams
					BoundMalterlib3(0,1,2,3,4,5);
					BoundMalterlib3(0,1,2,3,4,5,6);
					BoundMalterlib3(0,1,2,3,4,5,6,7);
					BoundMalterlib3(0,1,2,3,4,5,6,7,8);
					BoundMalterlib3(0,1,2,3,4,5,6,7,8,9);
#endif

					auto TestMemFun = fg_MemberFunctionFunctor(&CBindFunctor::f_UnaryTest);
					TestMemFun(Functor);
					auto TestMemFun2 = fg_Bind(&CBindFunctor::f_UnaryTest, &Functor);
					TestMemFun2();

					auto TestMemFun3 = fg_MemberFunctionFunctor(&CBindFunctor::f_BinaryTest);
					TestMemFun3(Functor, 2);
					auto TestMemFun4 = fg_Bind(&CBindFunctor::f_BinaryTest, &Functor, g_0);
					TestMemFun4(6);

					NPtr::TCUniquePointer<CBindFunctor> FunctorSmartPtr = fg_Construct();
					auto TestMemFun5 = fg_Bind(&CBindFunctor::f_UnaryTest, g_0);
					TestMemFun5(FunctorSmartPtr);

					auto pFunc = &fg_Test;
					auto TestRef = fg_VolatileReference(fg_ConstReference(pFunc));
					TestRef();
					int Test32 = 32;
					auto BoundMalterlib7 = fg_Bind(fg_Reference(Functor), fg_ConstReference(Test32));

					auto TestResult71 = BoundMalterlib7();
					Test32 = 55;
					auto TestResult72 = BoundMalterlib7();

					
					int Test3334 = 0;
				}
				{
					CBindFunctor Functor;
					
					//auto Bound = fg_Bind(CFunctor(), g_0);
					//Bound;
					auto BoundStl = std::bind(Functor, 1, std::placeholders::_3, 5, std::placeholders::_1);
					auto BoundStl1 = std::bind(Functor);
					int ntoheunheo = 0;
					int iTest = BoundStl(3, 4, 5);
					int ntoehu = 0;
					//fg_Bind(CFunctor(), );

					auto BoundBoost = boost::bind(Functor, 1, _3, 5, _1);
					auto BoundBoost1 = boost::bind(Functor);
					iTest = BoundBoost(3, 4, 5);
					auto BoundMalterlib = fg_Bind(Functor, 1, g_2, 5, g_0);
					auto BoundMalterlib1 = fg_Bind(Functor);
//					DMibTrace("BoundStl: {} {} \r\n", sizeof(BoundStl) << sizeof(BoundStl1));
//					DMibTrace("BoundBoost: {} {}\r\n", sizeof(BoundBoost) << sizeof(BoundBoost1));
//					DMibTrace("BoundMalterlib: {} {}\r\n", sizeof(BoundMalterlib) << sizeof(BoundMalterlib1));
					int thntoheu = 0;
				}
			}
			
			void f_DoNestedTests()
			{
				CBindFunctor Functor;
				auto BoundStl = std::bind(Functor, std::bind(fg_Mult, 3, std::placeholders::_1));
				auto ResultStl = BoundStl(5);
				
				auto BoundBoost = boost::bind(Functor, boost::bind(fg_Mult, 3, _1));
				auto ResultBoost = BoundBoost(5);
				
				auto BoundMalterlib = fg_Bind(Functor, fg_Bind(&fg_Mult, 3, g_0[g_1]));
				auto ResultMalterlib = BoundMalterlib(5);
				
				auto BoundMalterlibPartial 
				=
				fg_Bind
				(
				 Functor
				 , fg_Bind
				 (
				  &fg_Mult
				  , g_0[g_1]
				  , g_0[g_1]
				  )
				 )
				;
				
				auto ResultMalterlibPartial = BoundMalterlibPartial(5);
			
#if 1
				auto BoundMalterlibPartial2 
				= 
				fg_Bind
				(
				 &fg_MultFunctor
				 , g_0
				 , fg_Bind
				 (
				  &fg_Mult
				  , g_0[g_1]
				  , fg_Bind
				  (
				   &fg_Mult
				   , g_0[g_1]
				   , g_0[g_2]
				   )
				  )
				 )
				;
#else
				auto BoundMalterlibPartial2 
				= 
				fg_Bind
				(
				 &fg_MultFunctor
				 , 3
				 , fg_Bind
				 (
				  &fg_Mult
				  , g_0
				  , g_0[g_1]
				  )
				 )
				;
#endif
				
				/*				auto Result = BoundMalterlibPartial2.f_PartialBind<1>(6, NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil()
				 , NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil()
				 , NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil());*/
				
				
				//				BoundMalterlibPartial2(1);
				auto Resse2 = BoundMalterlibPartial2(3);
				int nthntoheu = 0;
			}
			
			
			void f_DoIII()
			{
				auto BoundMalterlibPartial2 
				= 
				fg_Bind
				(
				 &fg_MultFunctor
				 , 3
				 , fg_Bind
				 (
				  &fg_Mult
				  , g_0
				  , g_0[g_1]
				  )
				 )
				;
				/*				auto Result = BoundMalterlibPartial2.f_PartialBind<1>(6, NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil()
				 , NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil()
				 , NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil(), NFunction::NPrivate::CNil());*/
				
				
				//				BoundMalterlibPartial2(1);
				auto Resse2 = BoundMalterlibPartial2 (3);
				int nthntoheu = 0;
				
				CBindFunctor Functor;
				auto TestMemFun4 
				= fg_Bind
				(
				 &fg_MultFunctor
				 , 3
				 , fg_Bind
				 (
				  &CBindFunctor::f_BinaryTest3
				  , g_0[g_1]
				  , g_0
				  )
				 )
				;
				
				auto Bling = TestMemFun4(NMib::fg_Reference(Functor));
				
				int ntoheuneh = 0;
				//TestMemFun4(6);
				//auto TestingEEE = fg_Bind(&CBindFunctor::f_BinaryTest2, &Functor, g_0);
				
			}
			void f_OperatorTests()
			{
				CBindFunctor Functor;
				auto Boost = boost::bind(Functor, _1) == boost::bind(Functor, _2);
				auto BoostResult = Boost(3,4);
				
				auto Malterlib = fg_Bind(Functor, g_0[g_1]) == fg_Bind(Functor, g_1[g_1]);
				auto MalterlibResult = Malterlib(3,4);

				{
					auto Bind0 = fg_Bind<CBindSupportCompareTag>(Functor);
					auto Bind1 = fg_Bind<CBindSupportCompareTag>(Functor);
					auto Result = Bind0 == Bind1;
					auto Result2 = Bind0 <= Bind1;
				}
				{
					auto Bind0 = fg_Bind<CBindSupportCompareTag>(Functor, g_0);
					auto Bind1 = fg_Bind<CBindSupportCompareTag>(Functor, g_0);
					auto Result = Bind0 == Bind1;
					auto Result2 = Bind0 <= Bind1;
				}
				{
					auto Bind0 = fg_Bind<CBindSupportCompareTag>(Functor, 3);
					auto Bind1 = fg_Bind<CBindSupportCompareTag>(Functor, 4);
					auto Result = Bind0 == Bind1;
					auto Result2 = Bind0 <= Bind1;
				}
				{
					auto Bind0 = fg_Bind<CBindSupportCompareTag>(Functor, 3, 5);
					auto Bind1 = fg_Bind<CBindSupportCompareTag>(Functor, 4, 6);
					auto Result = Bind0 == Bind1;
					auto Result2 = Bind0 <= Bind1;
				}
				{
					auto Bind0 = fg_Bind<CBindSupportCompareTag>(Functor, 3, 5, 8);
					auto Bind1 = fg_Bind<CBindSupportCompareTag>(Functor, 4, 6, 9);
					auto Result = Bind0 == Bind1;
					auto Result2 = Bind0 <= Bind1;
				}
				
				int notheunheu = 0;
			}

			void f_DoTests()
			{
				DMibTestSuite("Member pointers")
				{
					f_DoMemberPtrTests();
				};
				DMibTestSuite("Forward extra")
				{
					f_DoForwardExtraTests();
				};
				DMibTestSuite("Bind")
				{
					f_DoBindTests();
				};
				DMibTestSuite("Operator")
				{
					f_OperatorTests();
				};
				DMibTestSuite("Partial")
				{
					f_DoIII();
				};
				DMibTestSuite("Nested")
				{
					f_DoNestedTests();
				};
			}
				
		};
	}
	
	DMibTestRegister(CBind_Tests, Malterlib::Function);
}

#endif
