// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include <Mib/Function/Function>
#include <Mib/Function/BindMemberFunction>
#include <Mib/Storage/Indirection>
#include <Mib/Storage/Reference>

namespace
{

	using namespace NMib;
	using namespace NMib::NFunction;
	using namespace NMib;

	void fg_Test()
	{
	}
	
	namespace
	{
		class CBind_Tests : public NTest::CTest
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
			
			void f_DoMemberPtrTests()
			{
				{
					NStorage::TCUniquePointer<CTestMemberPtr> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CTestMemberPtr::m_Member;
					auto TestInit = TestMemberPtr->*MemberPtr;
				}
				{
					NStorage::TCUniquePointer<CBindFunctor> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CBindFunctor::f_BinaryTest2;
					auto Result = (TestMemberPtr->*MemberPtr)(2);					
				}
				{
					auto MemberPtr = fg_MemberFunctionFunctor(&CBindFunctor::f_BinaryTest3);
					CBindFunctor Fununu;
					auto Result = MemberPtr(&Fununu, 2);
				}
				{
					NStorage::TCUniquePointer<CBindFunctor> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CBindFunctor::f_BinaryTest3;
					auto Result = (TestMemberPtr->*MemberPtr)(2);					
				}
				{
					NStorage::TCUniquePointer<CBindFunctor> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CBindFunctor::f_UnaryTest;
					(TestMemberPtr->*MemberPtr)();
				}
			}
			
			void f_DoBindTests()
			{
				{
					CBindFunctor Functor;

					NContainer::TCVector<int32> TestVector;
					TestVector.f_Insert(5);
					TestVector.f_Insert(7);
					TestVector.f_Insert(8);

					auto TestMemFun = fg_MemberFunctionFunctor(&CBindFunctor::f_UnaryTest);
					TestMemFun(Functor);

					auto TestMemFun3 = fg_MemberFunctionFunctor(&CBindFunctor::f_BinaryTest);
					TestMemFun3(Functor, 2);

					auto pFunc = &fg_Test;
					auto TestRef = fg_VolatileReference(fg_ConstReference(pFunc));
					TestRef();
				}
			}
			
			void f_DoTests()
			{
				DMibTestSuite("Member pointers")
				{
					f_DoMemberPtrTests();
				};
				DMibTestSuite("Bind")
				{
					f_DoBindTests();
				};
			}
		};
	}
	
	DMibTestRegister(CBind_Tests, Malterlib::Function);
}
