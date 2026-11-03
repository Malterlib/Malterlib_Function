// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template
	<
		typename t_CFunctor
		, typename t_CFOpts
		, bool t_bSupportEqualityCompare = t_CFOpts::mc_bSupportEqualityCompare
		, bool t_bSupportOrderedCompare = t_CFOpts::mc_bSupportOrderedCompare
		, bool t_bSupportCopy = t_CFOpts::mc_bSupportCopy
		, bool t_bSupportMove = t_CFOpts::mc_bSupportMove
	>
	struct TCImpl
	{
		using CImplBase = TCImplBase<t_CFunctor, t_bSupportCopy, t_bSupportMove>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator);
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator);
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, true, true, true, true>
	{
		using CImplBase = TCImplBase<t_CFunctor, true, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator);
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator);
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept;
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, true, false, true, true>
	{
		using CImplBase = TCImplBase<t_CFunctor, true, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator);
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator);
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, false, true, true, true>
	{
		using CImplBase = TCImplBase<t_CFunctor, true, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator);
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator);
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, false, false, false, true>
	{
		using CImplBase = TCImplBase<t_CFunctor, false, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator);
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, true, true, false, true>
	{
		using CImplBase = TCImplBase<t_CFunctor, false, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator);
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept;
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, true, false, false, true>
	{
		using CImplBase = TCImplBase<t_CFunctor, false, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator);
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, false, true, false, true>
	{
		using CImplBase = TCImplBase<t_CFunctor, false, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator);
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, false, false, true, false>
	{
		using CImplBase = TCImplBase<t_CFunctor, true, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr;     // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static constexpr CNullPtr fs_DuplicateMove = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_DuplicateMove function of the interface
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, true, true, true, false>
	{
		using CImplBase = TCImplBase<t_CFunctor, true, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator);

		static constexpr CNullPtr fs_DuplicateMove = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_DuplicateMove function of the interface
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept;
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, true, false, true, false>
	{
		using CImplBase = TCImplBase<t_CFunctor, true, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator);

		static constexpr CNullPtr fs_DuplicateMove = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_DuplicateMove function of the interface
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, false, true, true, false>
	{
		using CImplBase = TCImplBase<t_CFunctor, true, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator);

		static constexpr CNullPtr fs_DuplicateMove = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_DuplicateMove function of the interface
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, false, false, false, false>
	{
		using CImplBase = TCImplBase<t_CFunctor, false, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr;     // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static constexpr CNullPtr fs_DuplicateMove = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_DuplicateMove function of the interface
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, true, true, false, false>
	{
		using CImplBase = TCImplBase<t_CFunctor, false, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr;     // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static constexpr CNullPtr fs_DuplicateMove = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_DuplicateMove function of the interface
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept;
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, true, false, false, false>
	{
		using CImplBase = TCImplBase<t_CFunctor, false, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr;     // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static constexpr CNullPtr fs_DuplicateMove = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_DuplicateMove function of the interface
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	struct TCImpl<t_CFunctor, t_CFOpts, false, true, false, false>
	{
		using CImplBase = TCImplBase<t_CFunctor, false, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::FCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl
				<
					CImplBase
					, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::FType
					, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers
				>
			;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl);

		static constexpr CNullPtr fs_Duplicate = nullptr;     // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_Duplicate function of the interface
		static constexpr CNullPtr fs_DuplicateMove = nullptr; // NOLINT(malterlib-variable-naming, malterlib-conceptual-prefix): stands in for the fs_DuplicateMove function of the interface
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept;
	};

	template <typename t_CFunctor, typename t_CFunctionDefinition>
	struct TCDetermineImpl
	{
		using CType = NPrivate::TCImpl<NTraits::TCRemoveQualifiers<t_CFunctor>, typename t_CFunctionDefinition::CFunctionOptions>;
	};

	template <typename t_CFunctor, typename t_CFOpts, umint ...tp_Indicies>
	struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, false, false>
	{
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;

		static constexpr CVTable mc_VTable =
			{
				{
					&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, alignof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, sizeof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Destroy
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Duplicate
				, TCImpl<t_CFunctor, t_CFOpts>::fs_DuplicateMove
			}
		;
	};

	template <typename t_CFunctor, typename t_CFOpts, umint ...tp_Indicies>
	struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, true, true>
	{
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;

		static constexpr CVTable mc_VTable =
			{
				{
					&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, alignof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, sizeof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Destroy
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Duplicate
				, TCImpl<t_CFunctor, t_CFOpts>::fs_DuplicateMove
				, TCImpl<t_CFunctor, t_CFOpts>::fs_CompareEqual
				, TCImpl<t_CFunctor, t_CFOpts>::fs_CompareSpaceship
			}
		;
	};

	template <typename t_CFunctor, typename t_CFOpts, umint ...tp_Indicies>
	struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, true, false>
	{
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;

		static constexpr CVTable mc_VTable =
			{
				{
					&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, alignof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, sizeof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Destroy
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Duplicate
				, TCImpl<t_CFunctor, t_CFOpts>::fs_DuplicateMove
				, TCImpl<t_CFunctor, t_CFOpts>::fs_CompareEqual
			}
		;
	};

	template <typename t_CFunctor, typename t_CFOpts, umint ...tp_Indicies>
	struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, false, true>
	{
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;

		static constexpr CVTable mc_VTable =
			{
				{
					&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, alignof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, sizeof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Destroy
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Duplicate
				, TCImpl<t_CFunctor, t_CFOpts>::fs_DuplicateMove
				, TCImpl<t_CFunctor, t_CFOpts>::fs_CompareSpaceship
			}
		;
	};
}

#include "Malterlib_Function_Function_StorageImplementation.hpp"
