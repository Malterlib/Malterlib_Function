// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFunctor, typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare, bool t_bSupportCopy, bool t_bSupportMove>
	void TCImpl<t_CFunctor, t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare, t_bSupportCopy, t_bSupportMove>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare, bool t_bSupportCopy, bool t_bSupportMove>
	only_parameters_aliased return_not_aliased auto TCImpl<t_CFunctor, t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare, t_bSupportCopy, t_bSupportMove>::fs_Duplicate
		(
			void const *_pImpl
			, CAllocator &_Allocator
		)
		-> void *
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
	}

	template <typename t_CFunctor, typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare, bool t_bSupportCopy, bool t_bSupportMove>
	only_parameters_aliased return_not_aliased auto TCImpl<t_CFunctor, t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare, t_bSupportCopy, t_bSupportMove>::fs_DuplicateMove
		(
			void *_pImpl
			, CAllocator &_Allocator
		)
		-> void *
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, true, true, true, true>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, true, true, true, true>::fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, true, true, true, true>::fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	bool TCImpl<t_CFunctor, t_CFOpts, true, true, true, true>::fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	COrdering_Partial TCImpl<t_CFunctor, t_CFOpts, true, true, true, true>::fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, true, false, true, true>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, true, false, true, true>::fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, true, false, true, true>::fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	bool TCImpl<t_CFunctor, t_CFOpts, true, false, true, true>::fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, false, true, true, true>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, false, true, true, true>::fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, false, true, true, true>::fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	COrdering_Partial TCImpl<t_CFunctor, t_CFOpts, false, true, true, true>::fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, false, false, false, true>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, false, false, false, true>::fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, true, true, false, true>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, true, true, false, true>::fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	bool TCImpl<t_CFunctor, t_CFOpts, true, true, false, true>::fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	COrdering_Partial TCImpl<t_CFunctor, t_CFOpts, true, true, false, true>::fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, true, false, false, true>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, true, false, false, true>::fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	bool TCImpl<t_CFunctor, t_CFOpts, true, false, false, true>::fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, false, true, false, true>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, false, true, false, true>::fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	COrdering_Partial TCImpl<t_CFunctor, t_CFOpts, false, true, false, true>::fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, false, false, true, false>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, true, true, true, false>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, true, true, true, false>::fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	bool TCImpl<t_CFunctor, t_CFOpts, true, true, true, false>::fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	COrdering_Partial TCImpl<t_CFunctor, t_CFOpts, true, true, true, false>::fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, true, false, true, false>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, true, false, true, false>::fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	bool TCImpl<t_CFunctor, t_CFOpts, true, false, true, false>::fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, false, true, true, false>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	only_parameters_aliased return_not_aliased void *TCImpl<t_CFunctor, t_CFOpts, false, true, true, false>::fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
	{
		return _Allocator.template fp_ConstructObject<CImplBase>(*((CImplBase const *)_pImpl));
	}

	template <typename t_CFunctor, typename t_CFOpts>
	COrdering_Partial TCImpl<t_CFunctor, t_CFOpts, false, true, true, false>::fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, false, false, false, false>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, true, true, false, false>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	bool TCImpl<t_CFunctor, t_CFOpts, true, true, false, false>::fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	COrdering_Partial TCImpl<t_CFunctor, t_CFOpts, true, true, false, false>::fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, true, false, false, false>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	bool TCImpl<t_CFunctor, t_CFOpts, true, false, false, false>::fs_CompareEqual(void const *_pImpl0, void const *_pImpl1) noexcept
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

	template <typename t_CFunctor, typename t_CFOpts>
	void TCImpl<t_CFunctor, t_CFOpts, false, true, false, false>::fs_Destroy(void *_pImpl)
	{
		((CImplBase *)_pImpl)->~CImplBase();
	}

	template <typename t_CFunctor, typename t_CFOpts>
	COrdering_Partial TCImpl<t_CFunctor, t_CFOpts, false, true, false, false>::fs_CompareSpaceship(void const *_pImpl0, void const *_pImpl1) noexcept
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
}
