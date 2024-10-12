// Copyright © 2024 Favro Holding AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#include <Mib/Function/Traits>
#include <Mib/Test/Test>

namespace
{
	struct CTestGeneric
	{
		void f_TestGeneric()
		{
		}
	};

	struct CTestVirtual
	{
		void f_TestGeneric()
		{
		}

		virtual void f_TestVirtual()
		{
		}

		virtual void f_TestVirtual2()
		{
		}
	};

	struct CTestVirtual2
	{
		void f_TestGeneric2()
		{
		}

		virtual void f_TestVirtual()
		{
		}

		virtual void f_TestVirtual3()
		{
		}
	};

	struct CTestVirtualDiamond : public CTestVirtual, public CTestVirtual2
	{
		void f_TestGeneric3()
		{
		}

		virtual void f_TestVirtual() override
		{
		}

		virtual void f_TestVirtual2() override
		{
		}

		virtual void f_TestVirtual3() override
		{
		}
		
		virtual void f_TestVirtual4()
		{
		}
	};

	struct CTestVirtualVirtual : virtual CTestVirtual, virtual CTestVirtual2
	{
		void f_TestGeneric3()
		{
		}

		virtual void f_TestVirtual() override
		{
		}

		virtual void f_TestVirtual2() override
		{
		}

		virtual void f_TestVirtual3() override
		{
		}
		
		virtual void f_TestVirtual4()
		{
		}
	};

#ifdef DMibCanDetectVirtualMemberFunctions_Constexpr

	static_assert(!NMib::NTraits::cIsVirtualMemberFunction<&CTestGeneric::f_TestGeneric>);
	static_assert(!NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtual::f_TestGeneric>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtual::f_TestVirtual>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtual::f_TestVirtual2>);
	static_assert(!NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtual2::f_TestGeneric2>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtual2::f_TestVirtual>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtual2::f_TestVirtual3>);
	static_assert(!NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualDiamond::f_TestGeneric3>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualDiamond::f_TestVirtual>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualDiamond::f_TestVirtual2>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualDiamond::f_TestVirtual3>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualDiamond::f_TestVirtual4>);
	static_assert(!NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualVirtual::f_TestGeneric3>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualVirtual::f_TestVirtual>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualVirtual::f_TestVirtual2>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualVirtual::f_TestVirtual3>);
	static_assert(NMib::NTraits::cIsVirtualMemberFunction<&CTestVirtualVirtual::f_TestVirtual4>);

#endif

#ifdef DMibCanDetectVirtualMemberFunctions_Dynamic

	class CTraits_Tests : public NMib::NTest::CTest
	{
	public:
		void f_DoTests()
		{
			DMibTestSuite("IsVirtual")
			{
				DMibExpectTrue(!NMib::NFunction::fg_IsVirtualCall(&CTestGeneric::f_TestGeneric));
				DMibExpectTrue(!NMib::NFunction::fg_IsVirtualCall(&CTestVirtual::f_TestGeneric));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtual::f_TestVirtual));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtual::f_TestVirtual2));
				DMibExpectTrue(!NMib::NFunction::fg_IsVirtualCall(&CTestVirtual2::f_TestGeneric2));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtual2::f_TestVirtual));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtual2::f_TestVirtual3));
				DMibExpectTrue(!NMib::NFunction::fg_IsVirtualCall(&CTestVirtualDiamond::f_TestGeneric3));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtualDiamond::f_TestVirtual));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtualDiamond::f_TestVirtual2));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtualDiamond::f_TestVirtual3));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtualDiamond::f_TestVirtual4));
				DMibExpectTrue(!NMib::NFunction::fg_IsVirtualCall(&CTestVirtualVirtual::f_TestGeneric3));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtualVirtual::f_TestVirtual));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtualVirtual::f_TestVirtual2));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtualVirtual::f_TestVirtual3));
				DMibExpectTrue(NMib::NFunction::fg_IsVirtualCall(&CTestVirtualVirtual::f_TestVirtual4));
			};
		}
	};

	DMibTestRegister(CTraits_Tests, Malterlib::Function);

#endif
}

