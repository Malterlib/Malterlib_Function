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
				using result_type = int;

				bool operator == (CBindFunctor const &_Right) const
				{
					return true;
				}

				COrdering_Weak operator <=> (CBindFunctor const &_Right) const
				{
					return COrdering_Weak::equivalent;
				}

				template <typename t_CType>
				struct result
				{
					using type = int;
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

				float operator () () const
				{
					return 5;
				}

				double operator () ()
				{
					return 7;
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
				int f_BinaryTest3(int _x)
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
					[[maybe_unused]] auto TestInit = TestMemberPtr->*MemberPtr;
				}
				{
					NStorage::TCUniquePointer<CBindFunctor> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CBindFunctor::f_BinaryTest2;
					[[maybe_unused]] auto Result = (TestMemberPtr->*MemberPtr)(2);
				}
				{
					auto MemberPtr = fg_MemberFunctionFunctor(&CBindFunctor::f_BinaryTest3);
					CBindFunctor Fununu;
					[[maybe_unused]] auto Result = MemberPtr(&Fununu, 2);
				}
				{
					NStorage::TCUniquePointer<CBindFunctor> TestMemberPtr = fg_Construct();
					auto MemberPtr = &CBindFunctor::f_BinaryTest3;
					[[maybe_unused]] auto Result = (TestMemberPtr->*MemberPtr)(2);
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
					auto TestRef = fg_ConstReference(pFunc);
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
