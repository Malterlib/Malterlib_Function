// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

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
		typedef TCImplBase<t_CFunctor, t_bSupportCopy, t_bSupportMove> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};

		typedef typename t_CFOpts::CImpBase CAllocator;

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
		typedef TCImplBase<t_CFunctor, true, true> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

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
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, false, true, true>
	{
	public:
		typedef TCImplBase<t_CFunctor, true, true> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

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
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, true, true, true>
	{
	public:
		typedef TCImplBase<t_CFunctor, true, true> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

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
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, false, false, true>
	{
	public:
		typedef TCImplBase<t_CFunctor, false, true> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

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
		typedef TCImplBase<t_CFunctor, false, true> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, false, false, true>
	{
	public:
		typedef TCImplBase<t_CFunctor, false, true> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, true, false, true>
	{
	public:
		typedef TCImplBase<t_CFunctor, false, true> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, false, true, false>
	{
	public:
		typedef TCImplBase<t_CFunctor, true, false> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

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
		typedef TCImplBase<t_CFunctor, true, false> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, false, true, false>
	{
	public:
		typedef TCImplBase<t_CFunctor, true, false> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, true, true, false>
	{
	public:
		typedef TCImplBase<t_CFunctor, true, false> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
		{
			return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
		}
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, false, false, false>
	{
	public:
		typedef TCImplBase<t_CFunctor, false, false> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

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
		typedef TCImplBase<t_CFunctor, false, false> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
		}
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, true, false, false, false>
	{
	public:
		typedef TCImplBase<t_CFunctor, false, false> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static bool fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor == *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFOpts>
	class TCImpl<t_CFunctor, t_CFOpts, false, true, false, false>
	{
	public:
		typedef TCImplBase<t_CFunctor, false, false> CImplBase;
		typedef TCImplVTable<t_CFunctor, t_CFOpts> CVTable;
		typedef TCCallImpl<CImplBase, typename t_CFOpts::CCall0, t_CFOpts::mc_Qualifiers0> CCallImp0;

		template <mint t_iFunction>
		struct TCGetCallImp
		{
			typedef TCCallImpl<CImplBase, typename TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::CType, TCGetCallInfo<typename t_CFOpts::CFunctionList, t_iFunction>::mc_Qualifiers> CType;
		};
		typedef typename t_CFOpts::CImpBase CAllocator;

		static void fs_Destroy(void *_pImpl)
		{
			((CImplBase *)_pImpl)->~CImplBase();
		}
		static constexpr CNullPtr fs_Duplicate = nullptr;
		static constexpr CNullPtr fs_DuplicateMove = nullptr;
		static COrdering_Partial fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1)
		{
			if constexpr (CImplBase::mc_IsIndirection)
				return *((CImplBase const *)_pImpl0)->m_pFunctor <=> *((CImplBase const *)_pImpl1)->m_pFunctor;
			else
				return ((CImplBase const *)_pImpl0)->m_Functor <=> ((CImplBase const *)_pImpl1)->m_Functor;
		}
	};

	template <typename t_CFunctor, typename t_CFunctionDefinition>
	struct TCDetermineImpl
	{
		typedef NPrivate::TCImpl
		<
			typename NTraits::TCRemoveQualifiers<t_CFunctor>::CType
			, typename t_CFunctionDefinition::CFunctionOptions
		> CType;
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
#endif

	template <typename t_CFunctor, typename t_CFOpts, mint... tp_Indicies>
	struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, false, false>
	{
		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
		typedef typename CFunctionDefinition::CVTable CVTable;
		static constexpr CVTable mc_VTable =
			{
				{
					(void *)&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, NTraits::TCAlignmentOf<typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase>::mc_Value
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
	template <typename t_CFunctor, typename t_CFOpts, mint... tp_Indicies>
	struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, true, true>
	{
		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
		typedef typename CFunctionDefinition::CVTable CVTable;
		static constexpr CVTable mc_VTable =
			{
				{
					(void *)&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, NTraits::TCAlignmentOf<typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase>::mc_Value
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

	template <typename t_CFunctor, typename t_CFOpts, mint... tp_Indicies>
	struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, true, false>
	{
		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
		typedef typename CFunctionDefinition::CVTable CVTable;
		static constexpr CVTable mc_VTable =
			{
				{
					(void *)&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, NTraits::TCAlignmentOf<typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase>::mc_Value
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

	template <typename t_CFunctor, typename t_CFOpts, mint... tp_Indicies>
	struct TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, false, true>
	{
		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
		typedef typename CFunctionDefinition::CVTable CVTable;
		static constexpr CVTable mc_VTable =
			{
				{
					(void *)&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, NTraits::TCAlignmentOf<typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase>::mc_Value
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
