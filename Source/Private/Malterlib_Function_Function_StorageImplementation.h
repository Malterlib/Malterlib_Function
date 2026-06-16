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
	class TCImpl
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, t_bSupportCopy, t_bSupportMove>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> ;
		};

		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, true, true, true>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, true, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, false, true, true>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, true, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, true, true, true>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, true, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase ;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, false, false, true>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, false, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, true, false, true>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, false, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, false, false, true>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, false, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, true, false, true>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, false, true>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, false, true, false>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, true, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, true, true, false>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, true, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, false, true, false>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, true, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, true, true, false>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, true, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, false, false, false>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, false, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, true, false, false>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, false, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, false, false, false>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, false, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, true, false, false>
	{
	public:
		using CImplBase = TCImplBase<t_CFunctor, false, false>;
		using CVTable = TCImplVTable<t_CFunctor, t_CFOpts>;
		using CCallImp0 = TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0>;

		template <umint t_iFunction>
		struct TCGetCallImp
		{
			using CType = TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers>;
		};
		using CAllocator = typename t_CFOpts::CImpBase;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
		{
			if constexpr (CImplBase::mc_IsIndirection)
			{
				static_assert(noexcept(*((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor));
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			}
			else
			{
				static_assert(noexcept(((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor));
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
			}
		}
	};

	template <typename t_CFunctor, typename t_CFunctionDefinition>
	struct TCDetermineImpl
	{
		using CType = NPrivate::TCImpl
			<
				NTraits::TCRemoveQualifiers<t_CFunctor>
				, typename t_CFunctionDefinition::CFunctionOptions
			>
		;
	};

#ifdef DMibDebuggerHelpers
	template <typename t_CFunctor>
	struct TCFunctionObjectTypeHelperName
	{
		static constexpr auto mc_FunctorName = fg_GetTypeNameConstExprArray<TCFunctionObjectTypeHelperName>();
		static t_CFunctor *fs_Debug_GetFunctorType()
		{
			return nullptr;
		}
		static_assert(TCInstantiateValue<&fs_Debug_GetFunctorType>::mc_Value);
	};

	template <typename t_CReturn, typename ...tfp_CParams>
	struct TCFunctionObjectTypeHelperName<t_CReturn (&)(tfp_CParams...)>
	{
		using FFunctor = t_CReturn (*)(tfp_CParams...);
		static constexpr auto mc_FunctorName = fg_GetTypeNameConstExprArray<TCFunctionObjectTypeHelperName>();
		static FFunctor fs_Debug_GetFunctorType()
		{
			return nullptr;
		}
		static_assert(TCInstantiateValue<&fs_Debug_GetFunctorType>::mc_Value);
	};

	template <typename t_CReturn, typename ...tfp_CParams>
	struct TCFunctionObjectTypeHelperName<t_CReturn (&)(tfp_CParams...) noexcept>
	{
		using FFunctor = t_CReturn (*)(tfp_CParams...) noexcept;
		static constexpr auto mc_FunctorName = fg_GetTypeNameConstExprArray<TCFunctionObjectTypeHelperName>();
		static FFunctor fs_Debug_GetFunctorType()
		{
			return nullptr;
		}
		static_assert(TCInstantiateValue<&fs_Debug_GetFunctorType>::mc_Value);
	};
#endif

	template <typename t_CFunctor, typename t_CFOpts, umint... tp_Indicies>
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
	#ifdef DMibDebuggerHelpers
				, TCFunctionObjectTypeHelperName<t_CFunctor>::mc_FunctorName.m_pString
	#endif
			}
		;
	};
	template <typename t_CFunctor, typename t_CFOpts, umint... tp_Indicies>
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
	#ifdef DMibDebuggerHelpers
				, TCFunctionObjectTypeHelperName<t_CFunctor>::mc_FunctorName.m_pString
	#endif
			}
		;
	};

	template <typename t_CFunctor, typename t_CFOpts, umint... tp_Indicies>
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
	#ifdef DMibDebuggerHelpers
				, TCFunctionObjectTypeHelperName<t_CFunctor>::mc_FunctorName.m_pString
	#endif
			}
		;
	};

	template <typename t_CFunctor, typename t_CFOpts, umint... tp_Indicies>
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
	#ifdef DMibDebuggerHelpers
				, TCFunctionObjectTypeHelperName<t_CFunctor>::mc_FunctorName.m_pString
	#endif
			}
		;
	};
}
