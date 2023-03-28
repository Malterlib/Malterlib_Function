// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include <functional>
#include <boost/function.hpp>
#include <Mib/Function/Function>
#include <Mib/Test/Exception>

// TODO
// Combined function

namespace
{

	int g_Test = 0;
	volatile int g_TestCopy = 0;
	int g_Add = 1;
	using namespace NMib::NFunction;
	using namespace NMib;
	namespace
	{
		class CFunction_Tests : public NTest::CTest
		{
		public:
			//int m_Test;

			struct CMoveFunctorBig
			{
				double m_AlignOn8;
				uint8 m_BigData[128];
				NContainer::CByteVector m_Data;
				CMoveFunctorBig()
				{
					m_Data.f_SetLen(16);
				}
				CMoveFunctorBig(CMoveFunctorBig && _Other)
					: m_Data (fg_Move(_Other.m_Data))
				{
				}
				CMoveFunctorBig(CMoveFunctorBig const &_Other)
					: m_Data (_Other.m_Data)
				{
				}
				void operator () () const
				{
					++g_Test;
				}
			};

#ifdef DMibDebug
			static const mint mc_nTests = 3;
			static const mint mc_nLoops = 1000;
#else
			static const mint mc_nTests = 3;
			static const mint mc_nLoops = 20000;
#endif

			template <typename t_CFunctor>
			static void fs_DoTestRecursive(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
#ifdef DMibDebug
				const int s_nRecurse = 100;
#else
				const int s_nRecurse = 4000;
#endif
				t_CFunctor flr_TestRecursive = [&](int _Value)
				{
					if (_Value >= s_nRecurse)
						return;
					++g_Test;
					flr_TestRecursive(_Value + 1);
				};

				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					flr_TestRecursive(0);
					g_TestCopy = g_Test;
					Timer.f_Stop();
				}
				Timer /= s_nRecurse;

				if (NMib::NTest::fg_GroupActive("Performance"))
					DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			template <typename t_CFunctor>
			static void fs_DoTestCreate(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;

				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
					{
						t_CFunctor Test0 = [] (){++g_Test;};
						t_CFunctor Test1 = [] (){++g_Test;};
						t_CFunctor Test2 = [] (){++g_Test;};
						t_CFunctor Test3 = [] (){++g_Test;};
						t_CFunctor Test4 = [] (){++g_Test;};
						t_CFunctor Test5 = [] (){++g_Test;};
						t_CFunctor Test6 = [] (){++g_Test;};
						t_CFunctor Test7 = [] (){++g_Test;};
						t_CFunctor Test8 = [] (){++g_Test;};
						t_CFunctor Test9 = [] (){++g_Test;};
						t_CFunctor Test10 = [] (){++g_Test;};
						t_CFunctor Test11 = [] (){++g_Test;};
						t_CFunctor Test12 = [] (){++g_Test;};
						t_CFunctor Test13 = [] (){++g_Test;};
						t_CFunctor Test14 = [] (){++g_Test;};
						t_CFunctor Test15 = [] (){++g_Test;};
						g_TestCopy = g_Test;
					}
					Timer.f_Stop();
				}
				Timer /= mc_nLoops*16;

				if (NMib::NTest::fg_GroupActive("Performance"))
					DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			template <typename t_CFunctor>
			static void fs_DoTestAssign(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = [] (){++g_Test;};

				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
					{
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						Test = [] (){++g_Test;};
						g_TestCopy = g_Test;
					}
					Timer.f_Stop();
				}
				Timer /= mc_nLoops*16;

				if (NMib::NTest::fg_GroupActive("Performance"))
					DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			template <typename t_CFunctor>
			static void fs_DoTestAssignBig(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;

				t_CFunctor Test = CFunction_Tests::CMoveFunctorBig();

				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				if (NMib::NTest::fg_GroupActive("Performance"))
					DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			template <typename t_CFunctor>
			static void fs_DoTestCopy(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = [] (){++g_Test;};
				t_CFunctor Test2;

				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				if (NMib::NTest::fg_GroupActive("Performance"))
					DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			template <typename t_CFunctor>
			static void fs_DoTestCopyBig(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;

				t_CFunctor Test = CFunction_Tests::CMoveFunctorBig();
				t_CFunctor Test2;

				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				if (NMib::NTest::fg_GroupActive("Performance"))
					DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			struct CMoveFunctor
			{
				NContainer::CByteVector m_Data;
				CMoveFunctor()
				{
					m_Data.f_SetLen(512);
				}
				CMoveFunctor(CMoveFunctor && _Other)
					: m_Data (fg_Move(_Other.m_Data))
				{
				}
				CMoveFunctor(CMoveFunctor const &_Other)
					: m_Data (_Other.m_Data)
				{
				}
				void operator () () const
				{
					++g_Test;
				}
			};

			template <typename t_CFunctor>
			static void fs_DoTestMove(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = CFunction_Tests::CMoveFunctor();
				t_CFunctor Test2;

				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				if (NMib::NTest::fg_GroupActive("Performance"))
					DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			struct CMoveFunctorBigMove
			{
				double m_AlignOn8;
				uint8 m_BigData[128];
				NContainer::CByteVector m_Data;
				CMoveFunctorBigMove()
				{
					m_Data.f_SetLen(512);
				}
				CMoveFunctorBigMove(CMoveFunctorBigMove && _Other)
					: m_Data (fg_Move(_Other.m_Data))
				{
				}
				CMoveFunctorBigMove(CMoveFunctorBigMove const &_Other)
					: m_Data (_Other.m_Data)
				{
				}
				void operator () () const
				{
					++g_Test;
				}
			};

			template <typename t_CFunctor>
			static void fs_DoTestMoveBig(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = CFunction_Tests::CMoveFunctorBigMove();
				t_CFunctor Test2;

				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				if (NMib::NTest::fg_GroupActive("Performance"))
					DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			struct CValidCallTest
			{
				NContainer::CByteVector m_Data;
				CValidCallTest()
				{
					m_Data.f_Insert(33);
				}
				CValidCallTest(CValidCallTest && _Other)
					: m_Data (fg_Move(_Other.m_Data))
				{
				}
				CValidCallTest(CValidCallTest const &_Other)
					: m_Data (_Other.m_Data)
				{
				}
				uint8 operator () () const
				{
					return m_Data[0];
				}
			};

			template <typename t_CFunctor>
			static void fs_DoTestValidCall(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = CFunction_Tests::CValidCallTest();
				t_CFunctor Test2 = Test;
				t_CFunctor Test3;
				Test3 = Test;
				t_CFunctor TestSource = CFunction_Tests::CValidCallTest();
				t_CFunctor Test4 = fg_Move(TestSource);
				t_CFunctor Test5;
				TestSource = CFunction_Tests::CValidCallTest();
				Test5 = fg_Move(TestSource);

				DMibTest(DMibExpr(Test()) == DMibExpr(33));
				DMibTest(DMibExpr(Test2()) == DMibExpr(33));
				DMibTest(DMibExpr(Test3()) == DMibExpr(33));
				DMibTest(DMibExpr(Test4()) == DMibExpr(33));
				DMibTest(DMibExpr(Test5()) == DMibExpr(33));
			}

			struct CValidCallTestBig
			{
				double m_AlignOn8;
				uint8 m_BigData[128];
				NContainer::CByteVector m_Data;
				CValidCallTestBig()
				{
					m_Data.f_Insert(33);
				}
				CValidCallTestBig(CValidCallTestBig && _Other)
					: m_Data (fg_Move(_Other.m_Data))
				{
				}
				CValidCallTestBig(CValidCallTestBig const &_Other)
					: m_Data (_Other.m_Data)
				{
				}
				uint8 operator () () const
				{
					return m_Data[0];
				}
			};

			template <typename t_CFunctor>
			static void fs_DoTestValidCallBig(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = CFunction_Tests::CValidCallTestBig();
				t_CFunctor Test2 = Test;
				t_CFunctor Test3;
				Test3 = Test;
				t_CFunctor TestSource = CFunction_Tests::CValidCallTestBig();
				t_CFunctor Test4 = fg_Move(TestSource);
				t_CFunctor Test5;
				TestSource = CFunction_Tests::CValidCallTestBig();
				Test5 = fg_Move(TestSource);

				DMibTest(DMibExpr(Test()) == DMibExpr(33));
				DMibTest(DMibExpr(Test2()) == DMibExpr(33));
				DMibTest(DMibExpr(Test3()) == DMibExpr(33));
				DMibTest(DMibExpr(Test4()) == DMibExpr(33));
				DMibTest(DMibExpr(Test5()) == DMibExpr(33));
			}

			template <typename t_CFunctor>
			static void fs_DoTest(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test
					(
						[] ()
						{
							++g_Test;
						}
					)
				;
				//t_CFunctor Test = Test1;
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			static void fs_DoTestDirect(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				auto Test = [] ()
				{
					++g_Test;
				};
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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

			template <typename t_CFunctor>
			static void fs_DoTest1(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = [] (int _X)
				{
					g_Test += _X;
				};
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			static void fs_DoTestDirect1(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				auto Test = [] (int _X)
				{
					g_Test += _X;
				};
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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

			template <typename t_CFunctor>
			static void fs_DoTest2(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = [] (int _0, int _1)
				{
					g_Test += _0 + _1;
				};
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			static void fs_DoTestDirect2(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				auto Test = [] (int _0, int _1)
				{
					g_Test += _0 + _1;
				};
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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

			template <typename t_CFunctor>
			static void fs_DoTest10(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				t_CFunctor Test = [] (int _0, int _1, int _2, int _3, int _4, int _5, int _6, int _7, int _8, int _9)
				{
					g_Test += _0 + _1 + _2 + _3 + _4 + _5 + _6 + _7 + _8 + _9;
				};
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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
				Timer /= mc_nLoops*16;

				DMibTest(DMibExpr(Timer) / DMibExpr(Timer) <= DMibExpr(1.0));
			}

			static void fs_DoTestDirect10(NStr::CStr const &_Name)
			{
				DMibTestPath(_Name);
				NTime::CCyclesMin Timer;
				auto Test = [] (int _0, int _1, int _2, int _3, int _4, int _5, int _6, int _7, int _8, int _9)
				{
					g_Test += _0 + _1 + _2 + _3 + _4 + _5 + _6 + _7 + _8 + _9;
				};
				for (mint i = 0; i < mc_nTests; ++i)
				{
					g_Test = 0;
					Timer.f_Start();
					for (mint i = 0; i < mc_nLoops; ++i)
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

			static void fs_Test()
			{
			}

			struct CTesting
			{
				void operator () (int)
				{
				}
				void operator () (float)
				{
				}
			};

			template <typename t_CFunction>
			void f_DoFunctionTests()
			{
				t_CFunction Test = [&](int const &_Test){};
				Test(3);

				Test = [&](int const &_Test){};

				Test(4);
				t_CFunction Test3 = Test;
				Test3(5);
				Test3 = Test;
				Test3(6);
				t_CFunction Test4(fg_Move(Test));
				t_CFunction Test5;
				Test5 = fg_Move(Test3);

			}
			template <typename t_CFunction>
			void f_DoFunctionTestsBig()
			{
				t_CFunction Test = [&](int const &_Test){};
				Test(3);

				Test = [&](int const &_Test){};

				Test(4);
				t_CFunction Test3 = Test;
				Test3(5);
				Test3 = Test;
				Test3(6);
				t_CFunction Test4(fg_Move(Test));
				t_CFunction Test5;
				Test5 = fg_Move(Test3);

				class CTestClass
				{
					uint32 m_Data[555];
				};
				CTestClass TestData;
				t_CFunction Test6 = [TestData](int const &_Test){(void)TestData;};
				t_CFunction Test7 = fg_Move(Test6);
				t_CFunction Test8;
				Test8 = fg_Move(Test7);

				NContainer::CByteVector Vector;
				Vector.f_SetLen(100);
				t_CFunction Test9 = [Vector](int const &_Test){};
				t_CFunction Test10 = fg_Move(Test9);
				t_CFunction Test11;
				Test8 = fg_Move(Test10);
			}

			struct CFunctorCompare
			{
				mint m_Value;
				CFunctorCompare(mint _Value)
					: m_Value(_Value)
				{
				}

				void operator () () const
				{
				}

				bool operator == (CFunctorCompare const &_Other) const
				{
					return m_Value == _Other.m_Value;
				}

				auto operator <=> (CFunctorCompare const &_Other) const
				{
					return m_Value <=> _Other.m_Value;
				}
			};

			struct CCommand
			{
				virtual ~CCommand()
				{
				}
			};

			struct CDispatchTypeTag
			{
			};

			void f_Capture(std::function<void (CDispatchTypeTag *)> const &_Function)
			{
				auto fTest
					= [_Function]()
					{
						_Function(nullptr);
					}
				;
			}

			struct CCounter
			{
				int32 *m_pCount;
				CCounter(int32 &_Count)
					: m_pCount(&_Count)
				{
					++(*m_pCount);
				}
				~CCounter()
				{
					--(*m_pCount);
				}
				CCounter(CCounter const &_Other)
					: m_pCount(_Other.m_pCount)
				{
					++*m_pCount;
				}
			};

			struct CCallAll
			{
				int operator ()()
				{
					return 100000;
				}
				int operator ()() const
				{
					return 1000000;
				}

				template <typename tf_CParam0, typename... tfp_CParams>
				int operator ()(tf_CParam0 _Param, tfp_CParams... p_Params)
				{
					return _Param + (*this)(p_Params...);
				}
				template <typename tf_CParam0, typename... tfp_CParams>
				int operator ()(tf_CParam0 _Param, tfp_CParams... p_Params) const
				{
					return _Param + (*this)(p_Params...);
				}
			};

			void f_DoTests()
			{

				f_DoFunctionTestsBig<TCFunction<void (int)>>();
				f_DoFunctionTests<TCFunctionNoAlloc<void (int)>>();
				f_DoFunctionTestsBig<TCFunctionSmall<void (int)>>();


				if (0)
				{
					TCFunction<int (int)> Test;
					TCFunctionNoAlloc<int (int)> Test2;
					TCFunctionSmall<int (int), NMemory::TCAllocator_Static<sizeof(void *) * 3>> Test3;

					std::function<int (int)> Test4;
					boost::function<int (int)> Test5;

					TCFunction<void ()> TestGlobal(&CFunction_Tests::fs_Test);
					TCFunction<void ()> TestGlobalRef(CFunction_Tests::fs_Test);

					struct CSizedStruct
					{
						uint8 m_Data[sizeof(void *)*3];
						CSizedStruct()
						{
							for (mint i = 0; i < sizeof(void *)*3; ++i)
								m_Data[i] = i;
						}
					};
					CSizedStruct Test00;
					auto fl_Test = [Test00] (int const &_Test)-> int {(void)Test00; return 3;};

					Test = fl_Test;
					//Test2 = fl_Test;
					Test3 = fl_Test;
					Test4 = fl_Test;
					Test5 = fl_Test;

					uint32 TestRes = Test(6);
					//uint32 TestRes2 = Test2(6);
					uint32 TestRes3 = Test3(6);
					uint32 TestRes4 = Test4(6);
					uint32 TestRes5 = Test5(6);


					DMibTrace("sizeof(TCFunction): {}\r\n", sizeof(Test));
					DMibTrace("sizeof(TCFunctionNoAlloc): {}\r\n", sizeof(Test2));
					DMibTrace("sizeof(TCFunctionSmall): {}\r\n", sizeof(TCFunctionSmall<void (int)>));
					DMibTrace("sizeof(TCFunctionSmall static): {}\r\n", sizeof(Test3));
					DMibTrace("sizeof(TCFunctionFastCall): {}\r\n", sizeof(TCFunctionFastCall<void (int)>));
					DMibTrace("sizeof(std::function): {}\r\n", sizeof(Test4));
					DMibTrace("sizeof(boost::function): {}\r\n", sizeof(Test5));
				}

				{
					TCFunction<void (int), void (float), void (const ch8 *)> Test10;
					TCFunction<void (float)> Test2;
//					CTesting Test2;
					//Test10((const ch8 *)"testing");
					//Test10(3.0f);
					//Test10(1);
					//Test10(3.0);
				}
				DMibTestSuite("Capture")
				{
					int32 Count = 0;
					{
						CCounter Counter(Count);
						f_Capture
							(
								[Counter](CDispatchTypeTag *)
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

					TCFunction<int (), int (CThisTag &)> TestAll;
					TCFunction<int (CThisTag &)> Test;
					TCFunction<int (CThisTag const &)> TestConst;

					{
						DMibTestPath("All");
						TestAll = CFunctorAll();

						DMibTest(DMibExpr(TestAll()) == DMibExpr(0));
						DMibTest(DMibExpr(fg_Const(TestAll)()) == DMibExpr(1));

						Test = CFunctorAll();
						TestConst = CFunctorAll();

						DMibTest(DMibExpr(Test()) == DMibExpr(0));
						DMibTest(DMibExpr(TestConst()) == DMibExpr(1));
						DMibTest(DMibExpr(fg_Const(TestConst)()) == DMibExpr(1));
					}

					{
						DMibTestPath("Const");

						Test = CFunctorConst();
						TestConst = CFunctorConst();
						DMibTest(DMibExpr(Test()) == DMibExpr(1));
						DMibTest(DMibExpr(TestConst()) == DMibExpr(1));
						DMibTest(DMibExpr(fg_Const(TestConst)()) == DMibExpr(1));
					}
				};

				// Test compares
				DMibTestSuite("Compare")
				{
					TCFunction<void (), CFunctionSupportEqualityCompareTag, CFunctionSupportOrderedCompareTag> Test1;
					TCFunction<void (), CFunctionSupportEqualityCompareTag, CFunctionSupportOrderedCompareTag> Test2;
					DMibTest(DMibExpr(Test1) == DMibExpr(Test2)) (ETestFlag_NoValues);

					Test1 = CFunction_Tests::CFunctorCompare(2);

					DMibTest(DMibExpr(Test1) != DMibExpr(Test2)) (ETestFlag_NoValues);

					Test2 = CFunction_Tests::CFunctorCompare(2);

					DMibTest(DMibExpr(Test1) == DMibExpr(Test2) && DMibExpr(2)) (ETestFlag_NoValues);

					Test2 = CFunction_Tests::CFunctorCompare(3);

					DMibTest(DMibExpr(Test1) != DMibExpr(Test2) && DMibExpr(2)) (ETestFlag_NoValues);

					DMibTest(DMibExpr(Test1) < DMibExpr(Test2)) (ETestFlag_NoValues);
					DMibTest(DMibExpr(Test2) > DMibExpr(Test1)) (ETestFlag_NoValues);

				};

				DMibTestSuite("Copy and movable compatibility")
				{
					TCFunction<void ()> Test;

					TCFunction<void (), CFunctionNoCopyTag> TestNoCopy(Test);
					TCFunction<void (), CFunctionNoMoveTag> TestNoMove(Test);
					TCFunction<void (), CFunctionNoCopyTag, CFunctionNoMoveTag> TestNoCopyNoMove(Test);

					TCFunction<void (TCFunction<void (), CFunctionNoCopyTag> &&)> Test2;
				};

				DMibTestSuite("Empty function")
				{
					TCFunction<NStr::CStr ()> fTest;

					DMibExpectException(fTest(), DMibImpErrorInstance(NMib::NException::CExceptionBadFunctionCall, "Trying to call an empty TCFunction"));
				};

				DMibTestSuite("Usage Tests")
				{
					struct V1
					{
						void operator()(int) const {}
						int operator()() const { return 3; }
					};

					V1 v1;

					{
						typedef TCFunction
							<
								int (int)
								, int (CThisTag &, int)
								, int (int, int)
								, int (CThisTag &, int, int)
								, int (int, int, int)
								, int (CThisTag &, int, int, int)
								, int (int, int, int, int)
								, int (CThisTag &, int, int, int, int)
							>
						F1;


						F1 f1;
						f1 = CCallAll();
						DMibTest(DMibExpr(f1(1)) == DMibExpr(100001));
						DMibTest(DMibExpr(f1(1, 1)) == DMibExpr(100002));
						DMibTest(DMibExpr(f1(1, 1, 1)) == DMibExpr(100003));
						DMibTest(DMibExpr(f1(1, 1, 1, 1)) == DMibExpr(100004));
						DMibTest(DMibExpr(fg_Const(f1)(1)) == DMibExpr(1000001));
						DMibTest(DMibExpr(fg_Const(f1)(1, 1)) == DMibExpr(1000002));
						DMibTest(DMibExpr(fg_Const(f1)(1, 1, 1)) == DMibExpr(1000003));
						DMibTest(DMibExpr(fg_Const(f1)(1, 1, 1, 1)) == DMibExpr(1000004));
					}
					{
						typedef TCFunction<void (int)> F1;
						F1 f1;
						DMibTest(DMibExpr(!f1));
						F1 f2(v1);
						DMibTest(DMibExpr(!!f2)) (ETestFlag_NoValues);
						F1 f3(f2);
						F1 f4([](int)->void {});
					}
					{
						typedef TCFunction<void (char)> F1;
						F1 f1;
						F1 f2(v1);
					}
					{
						typedef TCFunction<int ()> F1;
						F1 f1;
						F1 f2(v1);
					}
					{
						typedef TCFunction<void (int), void ()> F1;
						F1 f1;
						F1 f2(v1); // return value ignored. OK? Yes
						// F1 f3([](int)->void {}); // Fails
						// Fails: F1 f4([](int)->void {},[]()->void {}); (waiting for TCCombinedFunction support)
					}
					{
						//typedef TCFunction<void (int),void (int)> F1;  // Fails
						//F1 f1;
						//F1 f2(v1);
					}
					{
						typedef TCFunction<void (int), void ()> F1;
						typedef TCFunction<void (int)> F2;
						F1 f1(v1);
						F2 f2(f1);
						// F1 f3(f2);
						//std::function<void(int)> f4 = f1;
						//std::function<void()> f5 = std::bind(f2,3);
					}

					// No
					{
						typedef TCFunction<void (int,int)> F1;
						F1 f1;
//						F1 f2(v1);  // Ignoring extra parameters might be ok?
					}
					{
						struct V2
						{
							int operator()() { return 2; }
							int operator()() const { return 3; }
						} v2;
						struct V3
						{
							int operator()() { return 4; }
						} v3;
						struct V4
						{
							int operator()() const { return 5; }
						} v4;

						v3();
						v4();

						typedef TCFunction<int (CThisTag &), int ()> F1;
						F1 f1(v2);
						DMibTest(DMibExpr(f1())==DMibExpr(2));
						F1 const f2(v2);
						DMibTest(DMibExpr(f2())==DMibExpr(3));
						int member;
						F1 f3([member]()->int { return member;});
						//F1 f3([member] mutable ()->int { return ++member;});

						{
							// F1 f1(v3); // Cannot compile (const trying to call non-const)
						}
						{
							F1 f1(v4);
							DMibTest(DMibExpr(f1())==DMibExpr(5));
							F1 const f2(v4);
							DMibTest(DMibExpr(f2())==DMibExpr(5));
						}
						{
							auto lambda1 = [](int)->int { return 1;};
							auto lambda2 = [](int&)->int { return 2;};
							auto lambda3 = [](int const&)->int { return 3;};
							int x = 10;
							//F1 f1(boost::bind(lambda1,x));
							//F1 f2(std::bind(lambda2,ref(x)));
							//F1 f3(std::bind(lambda3,cref(x)));
							//F1 f4(f2,f3);
							//F1 const f5(f4);
							//DMibTest(DMibExpr(f4())==DMibExpr(2));
							//DMibTest(DMibExpr(f5())==DMibExpr(5));
						}
						{
							struct V2
							{
								void fun(int) {}
								int fun(void*) { return 3; }
							};// v2;
							//typedef TCFunction<void (int)> F1;
							//F1 f1(boost::bind(&V2::fun,v2));
						}

						//typedef TCFunction<int ()> F1;
					}

					{
						TCFunction<void ()> EmptyFunc;
						TCFunction<void ()> NonEmptyFunc = [] () {};

						DMibTest(DMibExpr(!EmptyFunc)==DMibExpr(true));
						DMibTest(DMibExpr(EmptyFunc ? true : false)==DMibExpr(false));
						DMibTest(DMibExpr(EmptyFunc.f_IsEmpty())==DMibExpr(true));

						DMibTest(DMibExpr(!NonEmptyFunc)==DMibExpr(false));
						DMibTest(DMibExpr(NonEmptyFunc ? true : false)==DMibExpr(true));
						DMibTest(DMibExpr(NonEmptyFunc.f_IsEmpty())==DMibExpr(false));
					}

				};


				DMibTestSuite("ValidCall")
				{
					CFunction_Tests::fs_DoTestValidCall<TCFunctionNoAlloc<uint8 ()>>("TCFunctionNoAlloc");
					CFunction_Tests::fs_DoTestValidCall<TCFunction<uint8 ()>>("TCFunction");
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
					CFunction_Tests::fs_DoTestCopy<TCFunctionSmall<void ()>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTestCopy<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTestCopy<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTestCopy<std::function<void ()>>("std::function");
					CFunction_Tests::fs_DoTestCopy<boost::function<void ()>>("boost::function");
				};

				DMibTestSuite("CopyBig")
				{
					CFunction_Tests::fs_DoTestCopyBig<TCFunction<void ()>>("TCFunction");
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
					CFunction_Tests::fs_DoTestAssign<TCFunctionSmall<void ()>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTestAssign<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTestAssign<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTestAssign<std::function<void ()>>("std::function");
					CFunction_Tests::fs_DoTestAssign<boost::function<void ()>>("boost::function");
				};

				DMibTestSuite("AssignBig")
				{
					CFunction_Tests::fs_DoTestAssignBig<TCFunction<void ()>>("TCFunction");
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
					CFunction_Tests::fs_DoTestMove<TCFunctionSmall<void ()>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTestMove<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTestMove<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTestMove<std::function<void ()>>("std::function");
					CFunction_Tests::fs_DoTestMove<boost::function<void ()>>("boost::function");
				};

				DMibTestSuite("MoveBig")
				{
					CFunction_Tests::fs_DoTestMoveBig<TCFunction<void ()>>("TCFunction");
					CFunction_Tests::fs_DoTestMoveBig<TCFunctionSmall<void ()>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTestMoveBig<TCFunctionSmall<void (), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTestMoveBig<TCFunctionFastCall<void ()>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTestMoveBig<std::function<void ()>>("std::function");
					CFunction_Tests::fs_DoTestMoveBig<boost::function<void ()>>("boost::function");
				};

				DMibTestSuite("Recursive")
				{
					CFunction_Tests::fs_DoTestRecursive<TCFunctionNoAlloc<void (int)>>("TCFunctionNoAlloc");
					CFunction_Tests::fs_DoTestRecursive<TCFunction<void (int)>>("TCFunction");
					CFunction_Tests::fs_DoTestRecursive<TCFunctionSmall<void (int)>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTestRecursive<TCFunctionSmall<void (int), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTestRecursive<TCFunctionFastCall<void (int)>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTestRecursive<std::function<void (int)>>("std::function");
					CFunction_Tests::fs_DoTestRecursive<boost::function<void (int)>>("boost::function");
				};

				DMibTestSuite("Zero param")
				{
					fs_DoTestDirect("Direct lambda");
					CFunction_Tests::fs_DoTest<TCFunctionNoAlloc<void ()>>("TCFunctionNoAlloc");
					CFunction_Tests::fs_DoTest<TCFunction<void ()>>("TCFunction");
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
					CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), CFunctionNoMoveTag, CFunctionNoCopyTag>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTest<TCFunctionSmall<void (), CFunctionNoMoveTag, CFunctionNoCopyTag, NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTest<TCFunctionFastCall<void (), CFunctionNoMoveTag, CFunctionNoCopyTag>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTest<std::function<void ()>>("std::function");
					CFunction_Tests::fs_DoTest<boost::function<void ()>>("boost::function");
				};
				DMibTestSuite("One param")
				{
					fs_DoTestDirect1("Direct lambda");
					CFunction_Tests::fs_DoTest1<TCFunctionNoAlloc<void (int)>>("TCFunctionNoAlloc");
					CFunction_Tests::fs_DoTest1<TCFunction<void (int)>>("TCFunction");
					CFunction_Tests::fs_DoTest1<TCFunctionSmall<void (int)>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTest1<TCFunctionSmall<void (int), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTest1<TCFunctionFastCall<void (int)>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTest1<std::function<void (int)>>("std::function");
					CFunction_Tests::fs_DoTest1<boost::function<void (int)>>("boost::function");
				};

				DMibTestSuite("Two param")
				{
					fs_DoTestDirect2("Direct lambda");
					CFunction_Tests::fs_DoTest2<TCFunctionNoAlloc<void (int, int)>>("TCFunctionNoAlloc");
					CFunction_Tests::fs_DoTest2<TCFunction<void (int, int)>>("TCFunction");
					CFunction_Tests::fs_DoTest2<TCFunctionSmall<void (int, int)>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTest2<TCFunctionSmall<void (int, int), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTest2<TCFunctionFastCall<void (int, int)>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTest2<std::function<void (int, int)>>("std::function");
					CFunction_Tests::fs_DoTest2<boost::function<void (int, int)>>("boost::function");
				};

				DMibTestSuite("Ten param")
				{
					fs_DoTestDirect10("Direct lambda");
					CFunction_Tests::fs_DoTest10<TCFunctionNoAlloc<void (int, int, int, int, int, int, int, int, int, int)>>("TCFunctionNoAlloc");
					CFunction_Tests::fs_DoTest10<TCFunction<void (int, int, int, int, int, int, int, int, int, int)>>("TCFunction");
					CFunction_Tests::fs_DoTest10<TCFunctionSmall<void (int, int, int, int, int, int, int, int, int, int)>>("TCFunctionSmall");
					CFunction_Tests::fs_DoTest10<TCFunctionSmall<void (int, int, int, int, int, int, int, int, int, int), NMemory::TCAllocator_Static<sizeof(void *) * 3>>>("TCFunctionSmall static");
					CFunction_Tests::fs_DoTest10<TCFunctionFastCall<void (int, int, int, int, int, int, int, int, int, int)>>("TCFunctionFastCall");
					CFunction_Tests::fs_DoTest10<std::function<void (int, int, int, int, int, int, int, int, int, int)>>("std::function");
					CFunction_Tests::fs_DoTest10<boost::function<void (int, int, int, int, int, int, int, int, int, int)>>("boost::function");
				};

			}

		};
	}

	DMibTestRegister(CFunction_Tests, Malterlib::Function);
}


