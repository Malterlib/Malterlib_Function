// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

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
		struct CBind_Tests : public NTest::CTest
		{
			struct CBindFunctor
			{
				using result_type = int;

				bool operator == (CBindFunctor const &_fRight) const noexcept
				{
					return true;
				}

				COrdering_Weak operator <=> (CBindFunctor const &_fRight) const noexcept
				{
					return COrdering_Weak::equivalent;
				}

				template <typename t_CType>
				struct TCResult
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

				NContainer::TCVector<int32> operator () (NContainer::TCVector<int32> const &_Vector)
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

				void f_BinaryTest(int _Value)
				{
				}

				int f_BinaryTest2(int _Value)
				{
					return _Value;
				}

				int f_BinaryTest3(int _Value)
				{
					return _Value;
				}
			};

			struct CTestMemberPtr
			{
				int m_Member;
				CTestMemberPtr()
					: m_Member(3)
				{
				}
			};

			void f_DoMemberPtrTests()
			{
				{
					NStorage::TCUniquePointer<CTestMemberPtr> pTestMemberPtr = fg_Construct();
					auto pMember = &CTestMemberPtr::m_Member;
					[[maybe_unused]] auto TestInit = pTestMemberPtr->*pMember;
				}
				{
					NStorage::TCUniquePointer<CBindFunctor> pTestMemberPtr = fg_Construct();
					auto fMemberFunction = &CBindFunctor::f_BinaryTest2;
					[[maybe_unused]] auto Result = (pTestMemberPtr->*fMemberFunction)(2);
				}
				{
					auto fMemberFunction = fg_MemberFunctionFunctor(&CBindFunctor::f_BinaryTest3);
					CBindFunctor fFununu;
					[[maybe_unused]] auto Result = fMemberFunction(&fFununu, 2);
				}
				{
					NStorage::TCUniquePointer<CBindFunctor> pTestMemberPtr = fg_Construct();
					auto fMemberFunction = &CBindFunctor::f_BinaryTest3;
					[[maybe_unused]] auto Result = (pTestMemberPtr->*fMemberFunction)(2);
				}
				{
					NStorage::TCUniquePointer<CBindFunctor> pTestMemberPtr = fg_Construct();
					auto fMemberFunction = &CBindFunctor::f_UnaryTest;
					(pTestMemberPtr->*fMemberFunction)();
				}
			}

			void f_DoBindTests()
			{
				{
					CBindFunctor fFunctor;

					NContainer::TCVector<int32> TestVector;
					TestVector.f_Insert(5);
					TestVector.f_Insert(7);
					TestVector.f_Insert(8);

					auto fTestMemFun = fg_MemberFunctionFunctor(&CBindFunctor::f_UnaryTest);
					fTestMemFun(fFunctor);

					auto fTestMemFun3 = fg_MemberFunctionFunctor(&CBindFunctor::f_BinaryTest);
					fTestMemFun3(fFunctor, 2);

					auto fFunc = &fg_Test;
					auto TestRef = fg_ConstReference(fFunc);
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
