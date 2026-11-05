// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <functional>
#include <boost/function.hpp>

#include <Mib/Function/Function>
#include <Mib/Memory/MemoryManager>
#include <Mib/Test/Exception>
#include <Mib/Time/PerfTimeMeasure>

// TODO
// Combined function

namespace
{
	int g_Test = 0;
	int volatile g_TestCopy = 0;
	int g_Add = 1;
	using namespace NMib::NFunction;
	using namespace NMib;

	template <typename ...tp_FFunction>
	using TCFunctionNSCP = NFunction::TCFunction<tp_FFunction..., NFunction::TCFunctionNoAllocOptions<true, sizeof(void *), NFunction::TCFunctionNoAllocOptions<>::mc_Alignment, false>>;

	namespace
	{
		struct CFunction_Tests : public NTest::CTest
		{
			//int m_Test;

			struct CMoveFunctorBig
			{
				CMoveFunctorBig();
				CMoveFunctorBig(CMoveFunctorBig &&_fOther);
				CMoveFunctorBig(CMoveFunctorBig const &_fOther);

				void operator () () const;

				double m_AlignOn8;
				uint8 m_BigData[128];
				NContainer::CByteVector m_Data;
			};

			struct CMoveFunctor
			{
				CMoveFunctor();
				CMoveFunctor(CMoveFunctor &&_fOther);
				CMoveFunctor(CMoveFunctor const &_fOther);

				void operator () () const;

				NContainer::CByteVector m_Data;
			};

			struct CMoveFunctorBigMove
			{
				CMoveFunctorBigMove();
				CMoveFunctorBigMove(CMoveFunctorBigMove &&_fOther);
				CMoveFunctorBigMove(CMoveFunctorBigMove const &_fOther);

				void operator () () const;

				double m_AlignOn8;
				uint8 m_BigData[128];
				NContainer::CByteVector m_Data;
			};

			struct CValidCallTest
			{
				CValidCallTest();
				CValidCallTest(CValidCallTest &&_Other);
				CValidCallTest(CValidCallTest const &_Other);

				uint8 operator () () const;

				NContainer::CByteVector m_Data;
			};

			struct CValidCallTestBig
			{
				CValidCallTestBig();
				CValidCallTestBig(CValidCallTestBig &&_Other);
				CValidCallTestBig(CValidCallTestBig const &_Other);

				uint8 operator () () const;

				double m_AlignOn8;
				uint8 m_BigData[128];
				NContainer::CByteVector m_Data;
			};

			struct CTesting
			{
				void operator () (int _Value);
				void operator () (float _Value);
			};

			struct CFunctorCompare
			{
				CFunctorCompare(umint _Value);

				void operator () () const;
				bool operator == (CFunctorCompare const &_fOther) const noexcept;
				auto operator <=> (CFunctorCompare const &_fOther) const noexcept;

				umint m_Value;
			};

			struct CCommand
			{
				virtual ~CCommand();
			};

			struct CDispatchTypeTag
			{
			};

			struct CCounter
			{
				CCounter(int32 &_Count);
				~CCounter();
				CCounter(CCounter const &_Other);

				int32 *m_pCount;
			};

			struct CCallAll
			{
				int operator () ();
				int operator () () const;

				template <typename tf_CParam0, typename ...tfp_CParams>
				int operator () (tf_CParam0 _Param, tfp_CParams ...p_Params);

				template <typename tf_CParam0, typename ...tfp_CParams>
				int operator () (tf_CParam0 _Param, tfp_CParams ...p_Params) const;
			};

			template <typename tf_FFunctor>
			static void fs_DoTestRecursive(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestCreate(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestAssign(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestAssignBig(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestCopy(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestCopyBig(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestMove(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestMoveBig(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestValidCall(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTestValidCallBig(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTest(NStr::CStr const &_Name);

			static void fs_DoTestDirect(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTest1(NStr::CStr const &_Name);

			static void fs_DoTestDirect1(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTest2(NStr::CStr const &_Name);

			static void fs_DoTestDirect2(NStr::CStr const &_Name);

			template <typename tf_CFunctor>
			static void fs_DoTest10(NStr::CStr const &_Name);

			static void fs_DoTestDirect10(NStr::CStr const &_Name);

			static void fs_Test();

			template <typename tf_CFunction>
			void f_DoFunctionTests();

			template <typename tf_CFunction>
			void f_DoFunctionTestsBig();

			void f_Capture(std::function<void (CDispatchTypeTag *_pTag)> const &_fFunction);

			void f_DoTests();

#ifdef DMibDebug
			static constexpr umint mc_nTests = 3;
			static constexpr umint mc_nLoops = 1000;
#else
			static constexpr umint mc_nTests = 3;
			static constexpr umint mc_nLoops = 20000;
#endif
		};

		CFunction_Tests::CMoveFunctorBig::CMoveFunctorBig()
		{
			m_Data.f_SetLen(16);
		}

		CFunction_Tests::CMoveFunctorBig::CMoveFunctorBig(CMoveFunctorBig &&_fOther)
			: m_Data(fg_Move(_fOther.m_Data))
		{
		}

		CFunction_Tests::CMoveFunctorBig::CMoveFunctorBig(CMoveFunctorBig const &_fOther)
			: m_Data(_fOther.m_Data)
		{
		}

		void CFunction_Tests::CMoveFunctorBig::operator () () const
		{
			++g_Test;
		}

		CFunction_Tests::CMoveFunctor::CMoveFunctor()
		{
			m_Data.f_SetLen(512);
		}

		CFunction_Tests::CMoveFunctor::CMoveFunctor(CMoveFunctor &&_fOther)
			: m_Data(fg_Move(_fOther.m_Data))
		{
		}

		CFunction_Tests::CMoveFunctor::CMoveFunctor(CMoveFunctor const &_fOther)
			: m_Data(_fOther.m_Data)
		{
		}

		void CFunction_Tests::CMoveFunctor::operator () () const
		{
			++g_Test;
		}

		CFunction_Tests::CMoveFunctorBigMove::CMoveFunctorBigMove()
		{
			m_Data.f_SetLen(512);
		}

		CFunction_Tests::CMoveFunctorBigMove::CMoveFunctorBigMove(CMoveFunctorBigMove &&_fOther)
			: m_Data(fg_Move(_fOther.m_Data))
		{
		}

		CFunction_Tests::CMoveFunctorBigMove::CMoveFunctorBigMove(CMoveFunctorBigMove const &_fOther)
			: m_Data(_fOther.m_Data)
		{
		}

		void CFunction_Tests::CMoveFunctorBigMove::operator () () const
		{
			++g_Test;
		}

		CFunction_Tests::CValidCallTest::CValidCallTest()
		{
			m_Data.f_Insert(33);
		}

		CFunction_Tests::CValidCallTest::CValidCallTest(CValidCallTest &&_Other)
			: m_Data(fg_Move(_Other.m_Data))
		{
		}

		CFunction_Tests::CValidCallTest::CValidCallTest(CValidCallTest const &_Other)
			: m_Data(_Other.m_Data)
		{
		}

		uint8 CFunction_Tests::CValidCallTest::operator () () const
		{
			return m_Data[0];
		}

		CFunction_Tests::CValidCallTestBig::CValidCallTestBig()
		{
			m_Data.f_Insert(33);
		}

		CFunction_Tests::CValidCallTestBig::CValidCallTestBig(CValidCallTestBig &&_Other)
			: m_Data(fg_Move(_Other.m_Data))
		{
		}

		CFunction_Tests::CValidCallTestBig::CValidCallTestBig(CValidCallTestBig const &_Other)
			: m_Data(_Other.m_Data)
		{
		}

		uint8 CFunction_Tests::CValidCallTestBig::operator () () const
		{
			return m_Data[0];
		}

		void CFunction_Tests::CTesting::operator () (int _Value)
		{
		}

		void CFunction_Tests::CTesting::operator () (float _Value)
		{
		}

		CFunction_Tests::CFunctorCompare::CFunctorCompare(umint _Value)
			: m_Value(_Value)
		{
		}

		void CFunction_Tests::CFunctorCompare::operator () () const
		{
		}

		bool CFunction_Tests::CFunctorCompare::operator == (CFunctorCompare const &_fOther) const noexcept
		{
			return m_Value == _fOther.m_Value;
		}

		auto CFunction_Tests::CFunctorCompare::operator <=> (CFunctorCompare const &_fOther) const noexcept
		{
			return m_Value <=> _fOther.m_Value;
		}

		CFunction_Tests::CCommand::~CCommand()
		{
		}

		CFunction_Tests::CCounter::CCounter(int32 &_Count)
			: m_pCount(&_Count)
		{
			++(*m_pCount);
		}

		CFunction_Tests::CCounter::~CCounter()
		{
			--(*m_pCount);
		}

		CFunction_Tests::CCounter::CCounter(CCounter const &_Other)
			: m_pCount(_Other.m_pCount)
		{
			++*m_pCount;
		}

		int CFunction_Tests::CCallAll::operator () ()
		{
			return 100000;
		}

		int CFunction_Tests::CCallAll::operator () () const
		{
			return 1000000;
		}

		template <typename tf_CParam0, typename ...tfp_CParams>
		int CFunction_Tests::CCallAll::operator () (tf_CParam0 _Param, tfp_CParams ...p_Params)
		{
			return _Param + (*this)(p_Params...);
		}

		template <typename tf_CParam0, typename ...tfp_CParams>
		int CFunction_Tests::CCallAll::operator () (tf_CParam0 _Param, tfp_CParams ...p_Params) const
		{
			return _Param + (*this)(p_Params...);
		}

		template <typename tf_FFunctor>
		void CFunction_Tests::fs_DoTestRecursive(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
#if defined(DMibDebug) || defined(DMibSanitizerEnabled_Address)
			constexpr int c_nRecurse = 100;
#else
			constexpr int c_nRecurse = 4000;
#endif
			tf_FFunctor fTestRecursive = [&](int _Value)
				{
					if (_Value >= c_nRecurse)
						return;
					++g_Test;
					fTestRecursive(_Value + 1);
				}
			;

			//tf_FFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				fTestRecursive(0);
				g_TestCopy = g_Test;
				Timer.f_Stop();
			}
			Timer /= c_nRecurse;

			if (NMib::NTest::fg_GroupActive("Performance"))
				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestCreate(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;

			//tf_CFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					tf_CFunctor Test0 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test1 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test2 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test3 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test4 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test5 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test6 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test7 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test8 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test9 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test10 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test11 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test12 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test13 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test14 = []()
						{
							++g_Test;
						}
					;
					tf_CFunctor Test15 = []()
						{
							++g_Test;
						}
					;
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			if (NMib::NTest::fg_GroupActive("Performance"))
				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestAssign(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = []()
				{
					++g_Test;
				}
			;

			//tf_CFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					Test = []()
						{
							++g_Test;
						}
					;
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			if (NMib::NTest::fg_GroupActive("Performance"))
				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestAssignBig(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;

			tf_CFunctor Test = CFunction_Tests::CMoveFunctorBig();

			//tf_CFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					Test = CFunction_Tests::CMoveFunctorBig();
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			if (NMib::NTest::fg_GroupActive("Performance"))
				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestCopy(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = []()
				{
					++g_Test;
				}
			;
			tf_CFunctor Test2;

			//tf_CFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			if (NMib::NTest::fg_GroupActive("Performance"))
				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestCopyBig(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;

			tf_CFunctor Test = CFunction_Tests::CMoveFunctorBig();
			tf_CFunctor Test2;

			//tf_CFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					Test2 = Test;
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			if (NMib::NTest::fg_GroupActive("Performance"))
				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestMove(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = CFunction_Tests::CMoveFunctor();
			tf_CFunctor Test2;

			//tf_CFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			if (NMib::NTest::fg_GroupActive("Performance"))
				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestMoveBig(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = CFunction_Tests::CMoveFunctorBigMove();
			tf_CFunctor Test2;

			//tf_CFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					Test2 = fg_Move(Test);
					Test = fg_Move(Test2);
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			if (NMib::NTest::fg_GroupActive("Performance"))
				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestValidCall(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = CFunction_Tests::CValidCallTest();
			tf_CFunctor Test2 = Test;
			tf_CFunctor Test3;
			Test3 = Test;
			tf_CFunctor TestSource = CFunction_Tests::CValidCallTest();
			tf_CFunctor Test4 = fg_Move(TestSource);
			tf_CFunctor Test5;
			TestSource = CFunction_Tests::CValidCallTest();
			Test5 = fg_Move(TestSource);

			DMibTest(DMibExpr(Test()) == DMibExpr(33));
			DMibTest(DMibExpr(Test2()) == DMibExpr(33));
			DMibTest(DMibExpr(Test3()) == DMibExpr(33));
			DMibTest(DMibExpr(Test4()) == DMibExpr(33));
			DMibTest(DMibExpr(Test5()) == DMibExpr(33));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTestValidCallBig(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = CFunction_Tests::CValidCallTestBig();
			tf_CFunctor Test2 = Test;
			tf_CFunctor Test3;
			Test3 = Test;
			tf_CFunctor TestSource = CFunction_Tests::CValidCallTestBig();
			tf_CFunctor Test4 = fg_Move(TestSource);
			tf_CFunctor Test5;
			TestSource = CFunction_Tests::CValidCallTestBig();
			Test5 = fg_Move(TestSource);

			DMibTest(DMibExpr(Test()) == DMibExpr(33));
			DMibTest(DMibExpr(Test2()) == DMibExpr(33));
			DMibTest(DMibExpr(Test3()) == DMibExpr(33));
			DMibTest(DMibExpr(Test4()) == DMibExpr(33));
			DMibTest(DMibExpr(Test5()) == DMibExpr(33));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTest(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test
				(
					[]()
					{
						++g_Test;
					}
				)
			;
			//tf_CFunctor Test = Test1;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					Test();
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		void CFunction_Tests::fs_DoTestDirect(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			auto fTest = []()
				{
					++g_Test;
				}
			;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					fTest();
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTest1(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = [](int _Value)
				{
					g_Test += _Value;
				}
			;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test(1);
					Test(2);
					Test(3);
					Test(4);
					Test(5);
					Test(6);
					Test(7);
					Test(8);
					Test(9);
					Test(10);
					Test(11);
					Test(12);
					Test(13);
					Test(14);
					Test(15);
					Test(16);
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		void CFunction_Tests::fs_DoTestDirect1(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			auto fTest = [](int _Value)
				{
					g_Test += _Value;
				}
			;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					fTest(1);
					fTest(2);
					fTest(3);
					fTest(4);
					fTest(5);
					fTest(6);
					fTest(7);
					fTest(8);
					fTest(9);
					fTest(10);
					fTest(11);
					fTest(12);
					fTest(13);
					fTest(14);
					fTest(15);
					fTest(16);
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTest2(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = [](int _Value0, int _Value1)
				{
					g_Test += _Value0 + _Value1;
				}
			;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test(1, 17);
					Test(2, 18);
					Test(3, 19);
					Test(4, 20);
					Test(5, 21);
					Test(6, 22);
					Test(7, 23);
					Test(8, 24);
					Test(9, 25);
					Test(10, 26);
					Test(11, 27);
					Test(12, 28);
					Test(13, 29);
					Test(14, 30);
					Test(15, 31);
					Test(16, 32);
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		void CFunction_Tests::fs_DoTestDirect2(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			auto fTest = [](int _Value0, int _Value1)
				{
					g_Test += _Value0 + _Value1;
				}
			;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					fTest(1, 17);
					fTest(2, 18);
					fTest(3, 19);
					fTest(4, 20);
					fTest(5, 21);
					fTest(6, 22);
					fTest(7, 23);
					fTest(8, 24);
					fTest(9, 25);
					fTest(10, 26);
					fTest(11, 27);
					fTest(12, 28);
					fTest(13, 29);
					fTest(14, 30);
					fTest(15, 31);
					fTest(16, 32);
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		template <typename tf_CFunctor>
		void CFunction_Tests::fs_DoTest10(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			tf_CFunctor Test = [](int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)
				{
					g_Test += _Value0 + _Value1 + _Value2 + _Value3 + _Value4 + _Value5 + _Value6 + _Value7 + _Value8 + _Value9;
				}
			;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					Test(1, 17, 1, 17, 1, 17, 1, 17, 1, 17);
					Test(2, 18, 2, 18, 2, 18, 2, 18, 2, 18);
					Test(3, 19, 3, 19, 3, 19, 3, 19, 3, 19);
					Test(4, 20, 4, 20, 4, 20, 4, 20, 4, 20);
					Test(5, 21, 5, 21, 5, 21, 5, 21, 5, 21);
					Test(6, 22, 6, 22, 6, 22, 6, 22, 6, 22);
					Test(7, 23, 7, 23, 7, 23, 7, 23, 7, 23);
					Test(8, 24, 8, 24, 8, 24, 8, 24, 8, 24);
					Test(9, 25, 9, 25, 9, 25, 9, 25, 9, 25);
					Test(10, 26, 10, 26, 10, 26, 10, 26, 10, 26);
					Test(11, 27, 11, 27, 11, 27, 11, 27, 11, 27);
					Test(12, 28, 12, 28, 12, 28, 12, 28, 12, 28);
					Test(13, 29, 13, 29, 13, 29, 13, 29, 13, 29);
					Test(14, 30, 14, 30, 14, 30, 14, 30, 14, 30);
					Test(15, 31, 15, 31, 15, 31, 15, 31, 15, 31);
					Test(16, 32, 16, 32, 16, 32, 16, 32, 16, 32);
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		void CFunction_Tests::fs_DoTestDirect10(NStr::CStr const &_Name)
		{
			DMibTestPath(_Name);
			NTime::CPrefCyclesTimeMeasureMin Timer;
			auto fTest = [](int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)
				{
					g_Test += _Value0 + _Value1 + _Value2 + _Value3 + _Value4 + _Value5 + _Value6 + _Value7 + _Value8 + _Value9;
				}
			;
			for (umint iTest = 0; iTest < mc_nTests; ++iTest)
			{
				g_Test = 0;
				Timer.f_Start();
				for (umint iLoop = 0; iLoop < mc_nLoops; ++iLoop)
				{
					fTest(1, 17, 1, 17, 1, 17, 1, 17, 1, 17);
					fTest(2, 18, 2, 18, 2, 18, 2, 18, 2, 18);
					fTest(3, 19, 3, 19, 3, 19, 3, 19, 3, 19);
					fTest(4, 20, 4, 20, 4, 20, 4, 20, 4, 20);
					fTest(5, 21, 5, 21, 5, 21, 5, 21, 5, 21);
					fTest(6, 22, 6, 22, 6, 22, 6, 22, 6, 22);
					fTest(7, 23, 7, 23, 7, 23, 7, 23, 7, 23);
					fTest(8, 24, 8, 24, 8, 24, 8, 24, 8, 24);
					fTest(9, 25, 9, 25, 9, 25, 9, 25, 9, 25);
					fTest(10, 26, 10, 26, 10, 26, 10, 26, 10, 26);
					fTest(11, 27, 11, 27, 11, 27, 11, 27, 11, 27);
					fTest(12, 28, 12, 28, 12, 28, 12, 28, 12, 28);
					fTest(13, 29, 13, 29, 13, 29, 13, 29, 13, 29);
					fTest(14, 30, 14, 30, 14, 30, 14, 30, 14, 30);
					fTest(15, 31, 15, 31, 15, 31, 15, 31, 15, 31);
					fTest(16, 32, 16, 32, 16, 32, 16, 32, 16, 32);
					g_TestCopy = g_Test;
				}
				Timer.f_Stop();
			}
			Timer /= mc_nLoops * 16;

			DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
		}

		void CFunction_Tests::fs_Test()
		{
		}

		template <typename tf_CFunction>
		void CFunction_Tests::f_DoFunctionTests()
		{
			tf_CFunction Test = [&](int const &_Test)
				{
				}
			;
			Test(3);

			Test = [&](int const &_Test)
				{
				}
			;

			Test(4);
			tf_CFunction Test3 = Test;
			Test3(5);
			Test3 = Test;
			Test3(6);
			tf_CFunction Test4(fg_Move(Test));
			tf_CFunction Test5;
			Test5 = fg_Move(Test3);
		}

		template <typename tf_CFunction>
		void CFunction_Tests::f_DoFunctionTestsBig()
		{
			tf_CFunction Test = [&](int const &_Test)
				{
				}
			;
			Test(3);

			Test = [&](int const &_Test)
				{
				}
			;

			Test(4);
			tf_CFunction Test3 = Test;
			Test3(5);
			Test3 = Test;
			Test3(6);
			tf_CFunction Test4(fg_Move(Test));
			tf_CFunction Test5;
			Test5 = fg_Move(Test3);

			struct CTestClass
			{
			private:
				uint32 mp_Data[555];
			};

			CTestClass TestData;
			tf_CFunction Test6 = [TestData](int const &_Test)
				{
					(void)TestData;
				}
			;
			tf_CFunction Test7 = fg_Move(Test6);
			tf_CFunction Test8;
			Test8 = fg_Move(Test7);

			NContainer::CByteVector Vector;
			Vector.f_SetLen(100);
			tf_CFunction Test9 = [Vector](int const &_Test)
				{
				}
			;
			tf_CFunction Test10 = fg_Move(Test9);
			tf_CFunction Test11;
			Test8 = fg_Move(Test10);
		}

		void CFunction_Tests::f_Capture(std::function<void (CDispatchTypeTag *_pTag)> const &_fFunction)
		{
			auto fTest = [_fFunction]()
				{
					_fFunction(nullptr);
				}
			;
		}

		void CFunction_Tests::f_DoTests()
		{
			DMibTestSuite("Misc")
			{
				f_DoFunctionTestsBig<TCFunction<void (int _Value)>>();
				f_DoFunctionTests<TCFunctionNoAlloc<void (int _Value)>>();
				f_DoFunctionTestsBig<TCFunctionSmall<void (int _Value)>>();
			};

			if (0)
			{
				TCFunction<int (int _Value)> fTest;
				TCFunctionNoAlloc<int (int _Value)> fTest2;
				TCFunctionSmall<int (int _Value), NMemory::TCAllocator_Static<sizeof(void *) * 3>> fTest3;

				std::function<int (int _Value)> fTest4;
				boost::function<int (int _Value)> fTest5;

				TCFunction<void ()> fTestGlobal(&CFunction_Tests::fs_Test);
				TCFunction<void ()> fTestGlobalRef(CFunction_Tests::fs_Test);

				struct CSizedStruct
				{
					CSizedStruct()
					{
						for (umint iByte = 0; iByte < sizeof(void *) * 3; ++iByte)
							m_Data[iByte] = iByte;
					}

					uint8 m_Data[sizeof(void *) * 3];
				};

				CSizedStruct Test00;
				auto fTestLambda = [Test00](int const &_Test) -> int
					{
						(void)Test00;
						return 3;
					}
				;

				fTest = fTestLambda;
				//fTest2 = fTestLambda;
				fTest3 = fTestLambda;
				fTest4 = fTestLambda;
				fTest5 = fTestLambda;

				uint32 TestRes = fTest(6);
				//uint32 TestRes2 = fTest2(6);
				uint32 TestRes3 = fTest3(6);
				uint32 TestRes4 = fTest4(6);
				uint32 TestRes5 = fTest5(6);

				DMibTrace("sizeof(TCFunction): {}\r\n", sizeof(fTest));
				DMibTrace("sizeof(TCFunctionNoAlloc): {}\r\n", sizeof(fTest2));
				DMibTrace("sizeof(TCFunctionSmall): {}\r\n", sizeof(TCFunctionSmall<void (int _Value)>));
				DMibTrace("sizeof(TCFunctionSmall static): {}\r\n", sizeof(fTest3));
				DMibTrace("sizeof(TCFunctionFastCall): {}\r\n", sizeof(TCFunctionFastCall<void (int _Value)>));
				DMibTrace("sizeof(std::function): {}\r\n", sizeof(fTest4));
				DMibTrace("sizeof(boost::function): {}\r\n", sizeof(fTest5));
			}

			DMibTestSuite("Capture")
			{
				int32 Count = 0;
				{
					CCounter Counter(Count);
					f_Capture
						(
							[Counter](CDispatchTypeTag *_pTag)
							{
							}
						)
					;
				}
				DMibTest(DMibExpr(Count) == DMibExpr(0));
			};

			DMibTestSuite("Qualifiers tests")
			{
				struct CFunctorConst
				{
					int operator () () const
					{
						return 1;
					}
				};

				struct CFunctor
				{
					int operator () ()
					{
						return 0;
					}
				};

				struct CFunctorAll
				{
					int operator () ()
					{
						return 0;
					}

					int operator () () const
					{
						return 1;
					}
				};

				TCFunction<int (), int (CThisTag &_ThisTag)> fTestAll;
				TCFunction<int (CThisTag &_ThisTag)> fTest;
				TCFunction<int (CThisTag const &_ThisTag)> fTestConst;

				{
					DMibTestPath("All");
					fTestAll = CFunctorAll();

					DMibTest(DMibExpr(fTestAll()) == DMibExpr(0));
					DMibTest(DMibExpr(fg_Const(fTestAll)()) == DMibExpr(1));

					fTest = CFunctorAll();
					fTestConst = CFunctorAll();

					DMibTest(DMibExpr(fTest()) == DMibExpr(0));
					DMibTest(DMibExpr(fTestConst()) == DMibExpr(1));
					DMibTest(DMibExpr(fg_Const(fTestConst)()) == DMibExpr(1));
				}

				{
					DMibTestPath("Const");

					fTest = CFunctorConst();
					fTestConst = CFunctorConst();
					DMibTest(DMibExpr(fTest()) == DMibExpr(1));
					DMibTest(DMibExpr(fTestConst()) == DMibExpr(1));
					DMibTest(DMibExpr(fg_Const(fTestConst)()) == DMibExpr(1));
				}
			};

			// Test compares
			DMibTestSuite("Compare")
			{
				TCFunction<void (), CFunctionSupportEqualityCompareTag, CFunctionSupportOrderedCompareTag> fTest1;
				TCFunction<void (), CFunctionSupportEqualityCompareTag, CFunctionSupportOrderedCompareTag> fTest2;
				DMibTest(DMibExpr(fTest1) == DMibExpr(fTest2))(ETestFlag_NoValues);

				fTest1 = CFunction_Tests::CFunctorCompare(2);

				DMibTest(DMibExpr(fTest1) != DMibExpr(fTest2))(ETestFlag_NoValues);

				fTest2 = CFunction_Tests::CFunctorCompare(2);

				DMibTest(DMibExpr(fTest1) == DMibExpr(fTest2) && DMibExpr(2))(ETestFlag_NoValues);

				fTest2 = CFunction_Tests::CFunctorCompare(3);

				DMibTest(DMibExpr(fTest1) != DMibExpr(fTest2) && DMibExpr(2))(ETestFlag_NoValues);

				DMibTest(DMibExpr(fTest1) < DMibExpr(fTest2))(ETestFlag_NoValues);
				DMibTest(DMibExpr(fTest2) > DMibExpr(fTest1))(ETestFlag_NoValues);
			};

			DMibTestSuite("Copy and movable compatibility")
			{
				TCFunction<void ()> fTest;

				TCFunction<void (), CFunctionNoCopyTag> fTestNoCopy(fTest);
				TCFunction<void (), CFunctionNoMoveTag> fTestNoMove(fTest);
				TCFunction<void (), CFunctionNoCopyTag, CFunctionNoMoveTag> fTestNoCopyNoMove(fTest);

				TCFunction<void (TCFunction<void (), CFunctionNoCopyTag> &&_fFunction)> fTest2;
			};

			DMibTestSuite("Empty function")
			{
				TCFunction<NStr::CStr ()> fTest;

				DMibExpectException(fTest(), DMibImpErrorInstance(NMib::NException::CExceptionBadFunctionCall, "Trying to call an empty TCFunction"));
			};

			DMibTestSuite("Usage Tests")
			{
				struct CFunctor1
				{
					void operator () (int _Value) const
					{
					}

					int operator () () const
					{
						return 3;
					}
				};

				CFunctor1 fFunctor1;

				{
					using FFunction1 = TCFunction
						<
							int (int _Value)
							, int (CThisTag &_ThisTag, int _Value)
							, int (int _Value0, int _Value1)
							, int (CThisTag &_ThisTag, int _Value0, int _Value1)
							, int (int _Value0, int _Value1, int _Value2)
							, int (CThisTag &_ThisTag, int _Value0, int _Value1, int _Value2)
							, int (int _Value0, int _Value1, int _Value2, int _Value3)
							, int (CThisTag &_ThisTag, int _Value0, int _Value1, int _Value2, int _Value3)
						>
					;

					FFunction1 fFunction1;
					fFunction1 = CCallAll();
					DMibTest(DMibExpr(fFunction1(1)) == DMibExpr(100001));
					DMibTest(DMibExpr(fFunction1(1, 1)) == DMibExpr(100002));
					DMibTest(DMibExpr(fFunction1(1, 1, 1)) == DMibExpr(100003));
					DMibTest(DMibExpr(fFunction1(1, 1, 1, 1)) == DMibExpr(100004));
					DMibTest(DMibExpr(fg_Const(fFunction1)(1)) == DMibExpr(1000001));
					DMibTest(DMibExpr(fg_Const(fFunction1)(1, 1)) == DMibExpr(1000002));
					DMibTest(DMibExpr(fg_Const(fFunction1)(1, 1, 1)) == DMibExpr(1000003));
					DMibTest(DMibExpr(fg_Const(fFunction1)(1, 1, 1, 1)) == DMibExpr(1000004));
				}
				{
					using FFunction1 = TCFunction<void (int _Value)>;
					FFunction1 fFunction1;
					DMibTest(DMibExpr(!fFunction1));
					FFunction1 fFunction2(fFunctor1);
					DMibTest(DMibExpr(!!fFunction2))(ETestFlag_NoValues);
					FFunction1 fFunction3(fFunction2);
					FFunction1 fFunction4([](int _Value) -> void {});
				}
				{
					using FFunction1 = TCFunction<void (char _Value)>;
					FFunction1 fFunction1;
					FFunction1 fFunction2(fFunctor1);
				}
				{
					using FFunction1 = TCFunction<int ()>;
					FFunction1 fFunction1;
					FFunction1 fFunction2(fFunctor1);
				}
				{
					using FFunction1 = TCFunction<void (int _Value), void ()>;
					FFunction1 fFunction1;
					FFunction1 fFunction2(fFunctor1); // return value ignored. OK? Yes
					// FFunction1 fFunction3([](int)->void {}); // Fails
					// Fails: FFunction1 fFunction4([](int)->void {},[]()->void {}); (waiting for TCCombinedFunction support)
				}
				{
					//using FFunction1 = TCFunction<void (int),void (int)>;  // Fails
					//FFunction1 fFunction1;
					//FFunction1 fFunction2(fFunctor1);
				}
				{
					using FFunction1 = TCFunction<void (int _Value), void ()>;
					using FFunction2 = TCFunction<void (int _Value)>;
					FFunction1 fFunction1(fFunctor1);
					FFunction2 fFunction2(fFunction1);
					// FFunction1 fFunction3(fFunction2);
					//std::function<void(int)> fFunction4 = fFunction1;
					//std::function<void()> fFunction5 = std::bind(fFunction2,3);
				}

				// No
				{
					using FFunction1 = TCFunction<void (int _Value0, int _Value1)>;
					FFunction1 fFunction1;
					// FFunction1 fFunction2(fFunctor1);  // Ignoring extra parameters might be ok?
				}
				{
					struct CFunctor2
					{
						int operator () ()
						{
							return 2;
						}

						int operator () () const
						{
							return 3;
						}
					} fFunctor2;
					struct CFunctor3
					{
						int operator () ()
						{
							return 4;
						}
					} fFunctor3;
					struct CFunctor4
					{
						int operator () () const
						{
							return 5;
						}
					} fFunctor4;

					fFunctor3();
					fFunctor4();

					using FFunction1 = TCFunction<int (CThisTag &_ThisTag), int ()>;
					FFunction1 fFunction1(fFunctor2);
					DMibTest(DMibExpr(fFunction1()) == DMibExpr(2));
					FFunction1 const fFunction2(fFunctor2);
					DMibTest(DMibExpr(fFunction2()) == DMibExpr(3));
					int Member;
					FFunction1 fFunction3
						(
							[Member]() -> int
							{
								return Member;
							}
						)
					;
					//FFunction1 fFunction3([Member] mutable ()->int { return ++Member;});

					{
						// FFunction1 fFunction1(fFunctor3); // Cannot compile (const trying to call non-const)
					}
					{
						FFunction1 fFunction1(fFunctor4);
						DMibTest(DMibExpr(fFunction1()) == DMibExpr(5));
						FFunction1 const fFunction2(fFunctor4);
						DMibTest(DMibExpr(fFunction2()) == DMibExpr(5));
					}
					{
						auto fLambda1 = [](int _Value) -> int
							{
								return 1;
							}
						;
						auto fLambda2 = [](int &_Value) -> int
							{
								return 2;
							}
						;
						auto fLambda3 = [](int const &_Value) -> int
							{
								return 3;
							}
						;
						int Value = 10;
						//FFunction1 fFunction1(boost::bind(fLambda1,Value));
						//FFunction1 fFunction2(std::bind(fLambda2,ref(Value)));
						//FFunction1 fFunction3(std::bind(fLambda3,cref(Value)));
						//FFunction1 fFunction4(fFunction2,fFunction3);
						//FFunction1 const fFunction5(fFunction4);
						//DMibTest(DMibExpr(fFunction4())==DMibExpr(2));
						//DMibTest(DMibExpr(fFunction5())==DMibExpr(5));
					}
					{
						struct CFunctor2
						{
							void f_Fun(int _Value)
							{
							}

							int f_Fun(void *_pValue)
							{
								return 3;
							}
						}; // fFunctor2;

						//using FFunction1 = TCFunction<void (int)>;
						//FFunction1 fFunction1(boost::bind(&CFunctor2::f_Fun,fFunctor2));
					}

					//using FFunction1 = TCFunction<int ()>;
				}

				{
					TCFunction<void ()> fEmptyFunc;
					TCFunction<void ()> fNonEmptyFunc = []()
						{
						}
					;

					DMibTest(DMibExpr(!fEmptyFunc) == DMibExpr(true));
					DMibTest(DMibExpr(fEmptyFunc ? true : false) == DMibExpr(false));
					DMibTest(DMibExpr(fEmptyFunc.f_IsEmpty()) == DMibExpr(true));

					DMibTest(DMibExpr(!fNonEmptyFunc) == DMibExpr(false));
					DMibTest(DMibExpr(fNonEmptyFunc ? true : false) == DMibExpr(true));
					DMibTest(DMibExpr(fNonEmptyFunc.f_IsEmpty()) == DMibExpr(false));
				}
			};

			DMibTestSuite("ValidCall")
			{
				CFunction_Tests::fs_DoTestValidCall<TCFunctionNoAlloc<uint8 ()>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTestValidCall<TCFunction<uint8 ()>>("TCFunction");
				CFunction_Tests::fs_DoTestValidCall<TCFunctionNSCP<uint8 ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestValidCall<TCFunctionSmall<uint8 ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestValidCall<TCFunctionSmall<uint8 (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestValidCall<TCFunctionFastCall<uint8 ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestValidCall<std::function<uint8 ()>>("std::function");
				CFunction_Tests::fs_DoTestValidCall<boost::function<uint8 ()>>("boost::function");
			};

			DMibTestSuite("ValidCallBig")
			{
				//CFunction_Tests::fs_DoTestValidCallBig<TCFunctionNoAlloc<uint8 ()>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTestValidCallBig<TCFunction<uint8 ()>>("TCFunction");
				CFunction_Tests::fs_DoTestValidCallBig<TCFunctionNSCP<uint8 ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestValidCallBig<TCFunctionSmall<uint8 ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestValidCallBig<TCFunctionSmall<uint8 (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestValidCallBig<TCFunctionFastCall<uint8 ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestValidCallBig<std::function<uint8 ()>>("std::function");
				CFunction_Tests::fs_DoTestValidCallBig<boost::function<uint8 ()>>("boost::function");
			};

			DMibTestSuite("Create")
			{
				CFunction_Tests::fs_DoTestCreate<TCFunctionNoAlloc<void ()>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTestCreate<TCFunction<void ()>>("TCFunction");
				CFunction_Tests::fs_DoTestCreate<TCFunctionNSCP<void ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestCreate<TCFunctionSmall<void ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestCreate<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestCreate<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestCreate<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTestCreate<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("Copy")
			{
				CFunction_Tests::fs_DoTestCopy<TCFunctionNoAlloc<void ()>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTestCopy<TCFunction<void ()>>("TCFunction");
				CFunction_Tests::fs_DoTestCopy<TCFunctionNSCP<void ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestCopy<TCFunctionSmall<void ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestCopy<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestCopy<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestCopy<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTestCopy<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("CopyBig")
			{
				CFunction_Tests::fs_DoTestCopyBig<TCFunction<void ()>>("TCFunction");
				CFunction_Tests::fs_DoTestCopyBig<TCFunctionNSCP<void ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestCopyBig<TCFunctionSmall<void ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestCopyBig<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestCopyBig<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestCopyBig<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTestCopyBig<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("Assign")
			{
				CFunction_Tests::fs_DoTestAssign<TCFunctionNoAlloc<void ()>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTestAssign<TCFunction<void ()>>("TCFunction");
				CFunction_Tests::fs_DoTestAssign<TCFunctionNSCP<void ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestAssign<TCFunctionSmall<void ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestAssign<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestAssign<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestAssign<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTestAssign<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("AssignBig")
			{
				CFunction_Tests::fs_DoTestAssignBig<TCFunction<void ()>>("TCFunction");
				CFunction_Tests::fs_DoTestAssignBig<TCFunctionNSCP<void ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestAssignBig<TCFunctionSmall<void ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestAssignBig<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestAssignBig<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestAssignBig<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTestAssignBig<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("Move")
			{
				CFunction_Tests::fs_DoTestMove<TCFunctionNoAlloc<void ()>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTestMove<TCFunction<void ()>>("TCFunction");
				CFunction_Tests::fs_DoTestMove<TCFunctionNSCP<void ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestMove<TCFunctionSmall<void ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestMove<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestMove<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestMove<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTestMove<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("MoveBig")
			{
				CFunction_Tests::fs_DoTestMoveBig<TCFunction<void ()>>("TCFunction");
				CFunction_Tests::fs_DoTestMoveBig<TCFunctionNSCP<void ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestMoveBig<TCFunctionSmall<void ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestMoveBig<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestMoveBig<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestMoveBig<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTestMoveBig<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("Recursive")
			{
				CFunction_Tests::fs_DoTestRecursive<TCFunctionNoAlloc<void (int _Value)>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTestRecursive<TCFunction<void (int _Value)>>("TCFunction");
				CFunction_Tests::fs_DoTestRecursive<TCFunctionNSCP<void (int _Value)>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTestRecursive<TCFunctionSmall<void (int _Value)>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTestRecursive<TCFunctionSmall<void (int _Value), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTestRecursive<TCFunctionFastCall<void (int _Value)>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTestRecursive<std::function<void (int _Value)>>("std::function");
				CFunction_Tests::fs_DoTestRecursive<boost::function<void (int _Value)>>("boost::function");
			};

			DMibTestSuite("Zero param")
			{
				fs_DoTestDirect("Direct lambda");
				CFunction_Tests::fs_DoTest<TCFunctionNoAlloc<void ()>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTest<TCFunction<void ()>>("TCFunction");
				CFunction_Tests::fs_DoTest<TCFunctionNSCP<void ()>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTest<TCFunctionSmall<void ()>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTest<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTest<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTest<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("No copy")
			{
				fs_DoTestDirect("Direct lambda");
				CFunction_Tests::fs_DoTest<TCFunctionNoAlloc<void (), CFunctionNoCopyTag>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTest<TCFunction<void (), CFunctionNoCopyTag>>("TCFunction");
				CFunction_Tests::fs_DoTest<TCFunctionNSCP<void (), CFunctionNoCopyTag>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), CFunctionNoCopyTag>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), CFunctionNoCopyTag, NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTest<TCFunctionFastCall<void (), CFunctionNoCopyTag>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTest<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTest<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("No move")
			{
				fs_DoTestDirect("Direct lambda");
				CFunction_Tests::fs_DoTest<TCFunctionNoAlloc<void (), CFunctionNoMoveTag>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTest<TCFunction<void (), CFunctionNoMoveTag>>("TCFunction");
				CFunction_Tests::fs_DoTest<TCFunctionNSCP<void (), CFunctionNoMoveTag>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), CFunctionNoMoveTag>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), CFunctionNoMoveTag, NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTest<TCFunctionFastCall<void (), CFunctionNoMoveTag>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTest<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTest<boost::function<void ()>>("boost::function");
			};

			DMibTestSuite("No copy no move")
			{
				fs_DoTestDirect("Direct lambda");
				CFunction_Tests::fs_DoTest<TCFunctionNoAlloc<void (), CFunctionNoMoveTag, CFunctionNoCopyTag>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTest<TCFunction<void (), CFunctionNoMoveTag, CFunctionNoCopyTag>>("TCFunction");
				CFunction_Tests::fs_DoTest<TCFunctionNSCP<void (), CFunctionNoMoveTag, CFunctionNoCopyTag>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), CFunctionNoMoveTag, CFunctionNoCopyTag>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), CFunctionNoMoveTag, CFunctionNoCopyTag, NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTest<TCFunctionFastCall<void (), CFunctionNoMoveTag, CFunctionNoCopyTag>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTest<std::function<void ()>>("std::function");
				CFunction_Tests::fs_DoTest<boost::function<void ()>>("boost::function");
			};
			DMibTestSuite("One param")
			{
				fs_DoTestDirect1("Direct lambda");
				CFunction_Tests::fs_DoTest1<TCFunctionNoAlloc<void (int _Value)>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTest1<TCFunction<void (int _Value)>>("TCFunction");
				CFunction_Tests::fs_DoTest1<TCFunctionNSCP<void (int _Value)>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTest1<TCFunctionSmall<void (int _Value)>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTest1<TCFunctionSmall<void (int _Value), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTest1<TCFunctionFastCall<void (int _Value)>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTest1<std::function<void (int _Value)>>("std::function");
				CFunction_Tests::fs_DoTest1<boost::function<void (int _Value)>>("boost::function");
			};

			DMibTestSuite("Two param")
			{
				fs_DoTestDirect2("Direct lambda");
				CFunction_Tests::fs_DoTest2<TCFunctionNoAlloc<void (int _Value0, int _Value1)>>("TCFunctionNoAlloc");
				CFunction_Tests::fs_DoTest2<TCFunction<void (int _Value0, int _Value1)>>("TCFunction");
				CFunction_Tests::fs_DoTest2<TCFunctionNSCP<void (int _Value0, int _Value1)>>("TCFunctionNSCP");
				CFunction_Tests::fs_DoTest2<TCFunctionSmall<void (int _Value0, int _Value1)>>("TCFunctionSmall");
				CFunction_Tests::fs_DoTest2<TCFunctionSmall<void (int _Value0, int _Value1), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
				CFunction_Tests::fs_DoTest2<TCFunctionFastCall<void (int _Value0, int _Value1)>>("TCFunctionFastCall");
				CFunction_Tests::fs_DoTest2<std::function<void (int _Value0, int _Value1)>>("std::function");
				CFunction_Tests::fs_DoTest2<boost::function<void (int _Value0, int _Value1)>>("boost::function");
			};

			DMibTestSuite("Ten param")
			{
				fs_DoTestDirect10("Direct lambda");
				CFunction_Tests
					::fs_DoTest10<TCFunctionNoAlloc<void (int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)>>
					(
						"TCFunctionNoAlloc"
					)
				;
				CFunction_Tests
					::fs_DoTest10<TCFunction<void (int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)>>
					(
						"TCFunction"
					)
				;
				CFunction_Tests
					::fs_DoTest10<TCFunctionNSCP<void (int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)>>
					(
						"TCFunctionNSCP"
					)
				;
				CFunction_Tests
					::fs_DoTest10<TCFunctionSmall<void (int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)>>
					(
						"TCFunctionSmall"
					)
				;
				CFunction_Tests::fs_DoTest10
					<
						TCFunctionSmall
						<
							void (int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)
							, NMemory::TCAllocator_Static<sizeof(void *) * 3>
						>
					>
					("TCFunctionSmall static")
				;
				CFunction_Tests
					::fs_DoTest10<TCFunctionFastCall<void (int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)>>
					(
						"TCFunctionFastCall"
					)
				;
				CFunction_Tests
					::fs_DoTest10<std::function<void (int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)>>
					(
						"std::function"
					)
				;
				CFunction_Tests
					::fs_DoTest10<boost::function<void (int _Value0, int _Value1, int _Value2, int _Value3, int _Value4, int _Value5, int _Value6, int _Value7, int _Value8, int _Value9)>>
					(
						"boost::function"
					)
				;
			};

			DMibTestSuite("Allocator behavior")
			{
				using CMemoryManagerParams = NMemory::TCMemoryManagerParams<>;
				using CMemoryManager = NMemory::TCMemoryManager<CMemoryManagerParams>;
				using CStatefulAllocator = NMemory::TCAllocator_MemoryManager<CMemoryManagerParams>;
				using CFunctionStateful = TCFunctionSmall<int32 (), CStatefulAllocator>;
				// Use a large static buffer to test static allocations properly
				using CFunctionStatic = TCFunctionSmall<int32 (), NMemory::TCAllocator_Static<128>>;

				// Functor that tracks whether data was copied or moved
				struct CFunctorWithData
				{
					CFunctorWithData(int32 _Value)
						: m_Value(_Value)
						, m_pData(new uint8[16])
					{
					}

					~CFunctorWithData()
					{
						delete[] m_pData;
					}

					CFunctorWithData(CFunctorWithData const &_fOther)
						: m_Value(_fOther.m_Value)
						, m_pData(new uint8[16])
					{
					}

					CFunctorWithData(CFunctorWithData &&_fOther)
						: m_Value(_fOther.m_Value)
						, m_pData(fg_Exchange(_fOther.m_pData, nullptr))
					{
					}

					int32 operator () () const
					{
						return m_Value;
					}

					int32 m_Value;
					uint8 *m_pData;
				};

				DMibTestCategory("DefaultAllocator")
				{
					// Default allocator is stateless - always steals
					{
						DMibTestPath("MoveConstruct");
						TCFunction<int32 ()> fSource = CFunctorWithData(42);
						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						TCFunction<int32 ()> fDest(fg_Move(fSource));
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						DMibTest(!DMibExpr(fSource)); // Source should be empty after steal
					}

					{
						DMibTestPath("MoveAssign");
						TCFunction<int32 ()> fSource = CFunctorWithData(42);
						TCFunction<int32 ()> fDest;
						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						fDest = fg_Move(fSource);
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						DMibTest(!DMibExpr(fSource)); // Source should be empty after steal
					}
				};

				DMibTestCategory("StatefulAllocator")
				{
					CMemoryManager MemoryManagerA{NMemory::CMemoryManagerConfig()};
					CMemoryManager MemoryManagerB{NMemory::CMemoryManagerConfig()};

					{
						DMibTestPath("MoveConstruct/SameAllocator");
						// Same allocator instance - should steal
						CFunctionStateful fSource(CAllocatorConstructTag(), &MemoryManagerA);
						fSource = CFunctorWithData(42);
						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						CFunctionStateful fDest(fg_Move(fSource));
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						DMibTest(!DMibExpr(fSource)); // Source should be empty after steal
					}

					{
						DMibTestPath("MoveConstruct/DifferentAllocator");
						// Different allocator instances (both using same memory manager, but different instances)
						CFunctionStateful fSource(CAllocatorConstructTag(), &MemoryManagerA);
						fSource = CFunctorWithData(42);
						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						// Move construct copies allocator from source, so can always steal
						CFunctionStateful fDest(fg_Move(fSource));
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						// Source should be empty after move
						DMibTest(!DMibExpr(fSource));
					}

					{
						DMibTestPath("MoveAssign/SameAllocator");
						CFunctionStateful fSource(CAllocatorConstructTag(), &MemoryManagerA);
						fSource = CFunctorWithData(42);
						CFunctionStateful fDest(CAllocatorConstructTag(), &MemoryManagerA);

						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						fDest = fg_Move(fSource);
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						DMibTest(!DMibExpr(fSource)); // Source should be empty after steal
					}

					{
						DMibTestPath("MoveAssign/DifferentAllocator");
						CFunctionStateful fSource(CAllocatorConstructTag(), &MemoryManagerA);
						fSource = CFunctorWithData(42);
						CFunctionStateful fDest(CAllocatorConstructTag(), &MemoryManagerB);

						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						fDest = fg_Move(fSource);
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						// Source should be empty after move (data was duplicated then source destroyed)
						DMibTest(!DMibExpr(fSource));
					}
				};

				DMibTestCategory("StaticAllocator")
				{
					// Small functor that fits in static buffer
					struct CSmallFunctor
					{
						CSmallFunctor(int32 _Value)
							: m_Value(_Value)
						{
						}

						int32 operator () () const
						{
							return m_Value;
						}

						int32 m_Value;
					};

					// Large functor that overflows static buffer and uses heap
					struct CLargeFunctor
					{
						CLargeFunctor(int32 _Value)
							: m_Value(_Value)
						{
						}

						int32 operator () () const
						{
							return m_Value;
						}

						int32 m_Value;
						uint8 m_Data[256]; // Large enough to force heap allocation
					};

					{
						DMibTestPath("StaticAllocation/MoveConstruct");
						// Static allocations should NOT be stolen between different function objects
						CFunctionStatic fSource;
						fSource = CSmallFunctor(42);
						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						// Move construct - since static allocation, should copy
						CFunctionStatic fDest(fg_Move(fSource));
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						// Source is emptied after move even when copying (duplicated then destroyed)
						DMibTest(!DMibExpr(fSource));
					}

					{
						DMibTestPath("StaticAllocation/MoveAssign");
						CFunctionStatic fSource;
						fSource = CSmallFunctor(42);
						CFunctionStatic fDest;

						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						fDest = fg_Move(fSource);
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						// Source is emptied after move even when copying
						DMibTest(!DMibExpr(fSource));
					}

					{
						DMibTestPath("HeapOverflow/MoveConstruct");
						// Large allocation that overflows to heap - should be stolen
						CFunctionStatic fSource;
						fSource = CLargeFunctor(42);
						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						CFunctionStatic fDest(fg_Move(fSource));
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						DMibTest(!DMibExpr(fSource)); // Source should be empty after steal
					}

					{
						DMibTestPath("HeapOverflow/MoveAssign");
						CFunctionStatic fSource;
						fSource = CLargeFunctor(42);
						CFunctionStatic fDest;

						DMibTest(DMibExpr(fSource()) == DMibExpr(42));

						fDest = fg_Move(fSource);
						DMibTest(DMibExpr(fDest()) == DMibExpr(42));
						DMibTest(!DMibExpr(fSource)); // Source should be empty after steal
					}
				};
			};
		}
	}

	DMibTestRegister(CFunction_Tests, Malterlib::Function);
}

