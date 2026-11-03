// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFOpts>
	template <typename ...tfp_CParams>
	TCFunctionBase<t_CFOpts>::CData::CData(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CAllocator(fg_Forward<tfp_CParams>(p_Params)...)
		, m_pVTable(&CNullFunction::CVTable::mc_VTable)
		, m_pImpl(nullptr)
		, m_pCall(&CNullFunction::CCallImp0::fs_Call)
	{
	}

	template <typename t_CFOpts>
	TCFunctionBase<t_CFOpts>::CData::CData()
		: m_pVTable(&CNullFunction::CVTable::mc_VTable)
		, m_pImpl(nullptr)
		, m_pCall(&CNullFunction::CCallImp0::fs_Call)
	{
	}

	template <typename t_CFOpts>
	TCFunctionBase<t_CFOpts>::CData::CData(CData &&_Other)
		: CAllocator(fg_Move(static_cast<CAllocator &>(_Other)))
		, m_pVTable(&CNullFunction::CVTable::mc_VTable)
		, m_pImpl(nullptr)
		, m_pCall(&CNullFunction::CCallImp0::fs_Call)
	{
	}

	template <typename t_CFOpts>
	TCFunctionBase<t_CFOpts>::CData::CData(CData const &_Other)
		: CAllocator(static_cast<CAllocator const &>(_Other))
		, m_pVTable(&CNullFunction::CVTable::mc_VTable)
		, m_pImpl(nullptr)
		, m_pCall(&CNullFunction::CCallImp0::fs_Call)
	{
	}

	template <typename t_CFOpts>
	auto TCFunctionBase<t_CFOpts>::CData::operator = (CData &&_Other) -> CData &
	{
		*((CAllocator *)this) = fg_Move(*((CAllocator *)&_Other));
		return *this;
	}

	template <typename t_CFOpts>
	auto TCFunctionBase<t_CFOpts>::CData::operator = (CData const &_Other) -> CData &
	{
		*((CAllocator *)this) = *((CAllocator const *)&_Other);
		return *this;
	}

	template <typename t_CFOpts>
	template <typename ...tfp_CParams>
	TCFunctionBase<t_CFOpts>::TCFunctionBase(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: mp_Data(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	template <typename t_CFOpts>
	bool TCFunctionBase<t_CFOpts>::fp_IsDefault() const
	{
		return mp_Data.m_pImpl == nullptr;
	}

	template <typename t_CFOpts>
	void TCFunctionBase<t_CFOpts>::fp_SetDefault()
	{
		mp_Data.m_pImpl = nullptr;
		mp_Data.m_pCall = &CNullFunction::CCallImp0::fs_Call;
		mp_Data.m_pVTable = &CNullFunction::CVTable::mc_VTable;
	}

	template <typename t_CFOpts>
	void TCFunctionBase<t_CFOpts>::fp_Move(TCFunctionBase &&_Other)
	{
		if (_Other.mp_Data.m_pImpl)
		{
			if constexpr (NTraits::cIsEmpty<CAllocator>)
			{
				mp_Data.m_pImpl = _Other.mp_Data.m_pImpl;
				mp_Data.m_pCall = _Other.mp_Data.m_pCall;
				mp_Data.m_pVTable = _Other.mp_Data.m_pVTable;
				mp_Data = fg_Move(_Other.mp_Data);
				_Other.fp_SetDefault();
			}
			else
			{
				bool bCanSteal = false;
				if constexpr (CAllocator::mc_CanBeStatic)
				{
					if (!_Other.mp_Data.f_IsStatic(_Other.mp_Data.m_pImpl))
						bCanSteal = (CAllocator &)mp_Data == (CAllocator &)_Other.mp_Data;
				}
				else
					bCanSteal = (CAllocator &)mp_Data == (CAllocator &)_Other.mp_Data;

				if (bCanSteal)
				{
					mp_Data.m_pImpl = _Other.mp_Data.m_pImpl;
					mp_Data.m_pCall = _Other.mp_Data.m_pCall;
					mp_Data.m_pVTable = _Other.mp_Data.m_pVTable;
					mp_Data = fg_Move(_Other.mp_Data);
					_Other.fp_SetDefault();
				}
				else
				{
					fp_SetDefault();
					fp_Duplicate<true>(fg_Move(_Other));
					_Other.fp_Destroy();
					_Other.fp_SetDefault();
				}
			}
		}
		else
			fp_SetDefault();
	}

	template <typename t_CFOpts>
	void TCFunctionBase<t_CFOpts>::fp_MoveAssign(TCFunctionBase &&_Other)
	{
		if (!_Other.fp_IsDefault())
		{
			if constexpr (NTraits::cIsEmpty<CAllocator>)
			{
				fp_Destroy();
				mp_Data.m_pImpl = _Other.mp_Data.m_pImpl;
				mp_Data.m_pCall = _Other.mp_Data.m_pCall;
				mp_Data.m_pVTable = _Other.mp_Data.m_pVTable;
				mp_Data = fg_Move(_Other.mp_Data);
				_Other.fp_SetDefault();
			}
			else
			{
				bool bCanSteal = false;
				if constexpr (CAllocator::mc_CanBeStatic)
				{
					if (!_Other.mp_Data.f_IsStatic(_Other.mp_Data.m_pImpl))
						bCanSteal = (CAllocator &)mp_Data == (CAllocator &)_Other.mp_Data;
				}
				else
					bCanSteal = (CAllocator &)mp_Data == (CAllocator &)_Other.mp_Data;

				if (bCanSteal)
				{
					fp_Destroy();
					mp_Data.m_pImpl = _Other.mp_Data.m_pImpl;
					mp_Data.m_pCall = _Other.mp_Data.m_pCall;
					mp_Data.m_pVTable = _Other.mp_Data.m_pVTable;
					mp_Data = fg_Move(_Other.mp_Data);
					_Other.fp_SetDefault();
				}
				else
				{
					fp_Duplicate<true>(fg_Move(_Other));
					_Other.fp_Destroy();
					_Other.fp_SetDefault();
				}
			}
		}
		else
		{
			fp_Destroy();
			fp_SetDefault();
		}
	}

	template <typename t_CFOpts>
	template <typename tf_CObject, typename tf_CParam>
	tf_CObject *TCFunctionBase<t_CFOpts>::fp_ConstructObject(tf_CParam &&_Param)
	{
		return fg_ConstructObject<tf_CObject>(mp_Data, fg_Forward<tf_CParam>(_Param));
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	void TCFunctionBase<t_CFOpts>::fp_Construct(tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		mp_Data.m_pImpl = fg_ConstructObject<typename CImpl::CImplBase>(mp_Data, fg_Forward<tf_CFunction>(_Function));
		mp_Data.m_pCall = CImpl::CCallImp0::fs_Call;
		mp_Data.m_pVTable = &CImpl::CVTable::mc_VTable;
	}

	template <typename t_CFOpts>
	void const *TCFunctionBase<t_CFOpts>::fp_GetFirstFunctionPointer() const
	{
		return reinterpret_cast<void const *>(mp_Data.m_pCall);
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	void TCFunctionBase<t_CFOpts>::fp_Assign(tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		if (mp_Data.f_OnlyOneAlloc())
		{
			fp_Destroy();
			fp_SetDefault();
			mp_Data.m_pImpl = fg_ConstructObject<typename CImpl::CImplBase>(mp_Data, fg_Forward<tf_CFunction>(_Function));
		}
		else
		{
			auto *pNew = fg_ConstructObject<typename CImpl::CImplBase>(mp_Data, fg_Forward<tf_CFunction>(_Function));
			fp_Destroy();
			mp_Data.m_pImpl = pNew;
		}
		mp_Data.m_pCall = CImpl::CCallImp0::fs_Call;
		mp_Data.m_pVTable = &CImpl::CVTable::mc_VTable;
	}

	template <typename t_CFOpts>
	template <bool tf_bMove>
	void TCFunctionBase<t_CFOpts>::fp_Duplicate(typename TCGetDuplicateSignature<tf_bMove>::CType _Other)
	{
		if (_Other.mp_Data.m_pImpl)
		{
			if (mp_Data.f_OnlyOneAlloc())
			{
				fp_Destroy();
				fp_SetDefault();
				void *pNew;
				if constexpr (tf_bMove)
					pNew = _Other.fp_DuplicateMoveCall()((void *)_Other.fp_GetImpl(), *this);
				else
					pNew = _Other.fp_DuplicateCall()(_Other.fp_GetImpl(), *this);

				mp_Data.m_pImpl = pNew;
			}
			else
			{
				void *pNew;
				if constexpr (tf_bMove)
					pNew = _Other.fp_DuplicateMoveCall()((void *)_Other.fp_GetImpl(), *this);
				else
					pNew = _Other.fp_DuplicateCall()(_Other.fp_GetImpl(), *this);
				fp_Destroy();
				mp_Data.m_pImpl = pNew;
			}
			mp_Data.m_pCall = _Other.mp_Data.m_pCall;
			mp_Data.m_pVTable = _Other.mp_Data.m_pVTable;
		}
		else
		{
			fp_Destroy();
			fp_SetDefault();
		}
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small void *TCFunctionBase<t_CFOpts>::fp_GetImpl()
	{
		return mp_Data.m_pImpl;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small void *TCFunctionBase<t_CFOpts>::fp_GetImpl() const
	{
		return mp_Data.m_pImpl;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small void *TCFunctionBase<t_CFOpts>::fp_GetFunctor() const
	{
		return mp_Data.m_pImpl;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small void *TCFunctionBase<t_CFOpts>::fp_GetFunctorUnsafe() const
	{
		return mp_Data.m_pImpl;
	}

	template <typename t_CFOpts>
	mark_nodebug inline_small auto TCFunctionBase<t_CFOpts>::fp_VTable() const -> CVTable const *
	{
		return mp_Data.m_pVTable;
	}

	template <typename t_CFOpts>
	mark_nodebug FDelete *TCFunctionBase<t_CFOpts>::fp_DestroyCall() const
	{
		return mp_Data.m_pVTable->m_fDestroy;
	}

	template <typename t_CFOpts>
	auto TCFunctionBase<t_CFOpts>::fp_DuplicateCall() const -> typename CFunctionDefinition::FDuplicate *
	{
		return mp_Data.m_pVTable->m_fDuplicate;
	}

	template <typename t_CFOpts>
	auto TCFunctionBase<t_CFOpts>::fp_DuplicateMoveCall() const -> typename CFunctionDefinition::FDuplicateMove *
	{
		return mp_Data.m_pVTable->m_fDuplicateMove;
	}

	template <typename t_CFOpts>
	template <umint t_iCall, typename t_CDummmy>
	mark_artificial mark_nodebug inline_always auto TCFunctionBase<t_CFOpts>::TCCallRet<t_iCall, t_CDummmy>::fs_Get(TCFunctionBase const *_pThis)
		-> typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::FType *
	{
		return _pThis->mp_Data.m_pVTable->m_Calls.template f_GetFunction<t_iCall>();
	}

	template <typename t_CFOpts>
	template <typename t_CDummmy>
	mark_artificial mark_nodebug inline_always auto TCFunctionBase<t_CFOpts>::TCCallRet<0, t_CDummmy>::fs_Get(TCFunctionBase const *_pThis)
		-> typename TCGetFunctionCallDefinition<t_CFOpts, 0>::FType *
	{
		return _pThis->mp_Data.m_pCall;
	}

	template <typename t_CFOpts>
	template <umint tf_iCall>
	inline_always typename TCGetFunctionCallDefinition<t_CFOpts, tf_iCall>::FType *TCFunctionBase<t_CFOpts>::fp_Call() const
	{
		return TCCallRet<tf_iCall>::fs_Get(this);
	}

	template <typename t_CFOpts>
	FCompareEqual *TCFunctionBase<t_CFOpts>::fp_CompareEqual() const noexcept
	{
		return (FCompareEqual *)mp_Data.m_pVTable->m_fCompareEqual;
	}

	template <typename t_CFOpts>
	FCompareSpaceship *TCFunctionBase<t_CFOpts>::fp_CompareSpaceship() const noexcept
	{
		return (FCompareSpaceship *)mp_Data.m_pVTable->m_fCompareSpaceship;
	}

	template <typename t_CFOpts>
	void TCFunctionBase<t_CFOpts>::fp_Destroy()
	{
		if (mp_Data.m_pImpl)
		{
			fp_DestroyCall()(mp_Data.m_pImpl);
			auto &VTable = *mp_Data.m_pVTable;
			mp_Data.f_Free(mp_Data.m_pImpl, VTable.m_Size);
		}
	}

	template <typename t_CFOpts>
	template <typename ...tfp_CParams>
	TCFunctionSmallBase<t_CFOpts>::CData::CData(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CAllocator(fg_Forward<tfp_CParams>(p_Params)...)
		, m_pImp(const_cast<CImplementationData *>(&mcp_NullImplementation))
	{
	}

	template <typename t_CFOpts>
	TCFunctionSmallBase<t_CFOpts>::CData::CData()
		: m_pImp(const_cast<CImplementationData *>(&mcp_NullImplementation))
	{
	}

	template <typename t_CFOpts>
	TCFunctionSmallBase<t_CFOpts>::CData::CData(CData &&_Other)
		: CAllocator(fg_Move(static_cast<CAllocator &>(_Other)))
		, m_pImp(const_cast<CImplementationData *>(&mcp_NullImplementation))
	{
	}

	template <typename t_CFOpts>
	TCFunctionSmallBase<t_CFOpts>::CData::CData(CData const &_Other)
		: CAllocator(static_cast<CAllocator const &>(_Other))
		, m_pImp(const_cast<CImplementationData *>(&mcp_NullImplementation))
	{
	}

	template <typename t_CFOpts>
	auto TCFunctionSmallBase<t_CFOpts>::CData::operator = (CData &&_Other) -> CData &
	{
		*((CAllocator *)this) = fg_Move(*((CAllocator *)&_Other));
		return *this;
	}

	template <typename t_CFOpts>
	auto TCFunctionSmallBase<t_CFOpts>::CData::operator = (CData const &_Other) -> CData &
	{
		*((CAllocator *)this) = *((CAllocator const *)&_Other);
		return *this;
	}

	template <typename t_CFOpts>
	template <typename ...tfp_CParams>
	TCFunctionSmallBase<t_CFOpts>::TCFunctionSmallBase(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: mp_Data(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	template <typename t_CFOpts>
	bool TCFunctionSmallBase<t_CFOpts>::fp_IsDefault() const
	{
		return mp_Data.m_pImp == &mcp_NullImplementation;
	}

	template <typename t_CFOpts>
	void TCFunctionSmallBase<t_CFOpts>::fp_SetDefault()
	{
		mp_Data.m_pImp = const_cast<CImplementationData *>(&mcp_NullImplementation);
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small void *TCFunctionSmallBase<t_CFOpts>::fp_GetImpl()
	{
		return mp_Data.m_pImp + 1;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small void *TCFunctionSmallBase<t_CFOpts>::fp_GetImpl() const
	{
		return mp_Data.m_pImp + 1;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small void *TCFunctionSmallBase<t_CFOpts>::fp_GetFunctor() const
	{
		return mp_Data.m_pImp + 1;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small void *TCFunctionSmallBase<t_CFOpts>::fp_GetFunctorUnsafe() const
	{
		return mp_Data.m_pImp + 1;
	}

	template <typename t_CFOpts>
	mark_nodebug inline_small auto TCFunctionSmallBase<t_CFOpts>::fp_VTable() const -> CVTable const *
	{
		return mp_Data.m_pImp->m_pVTable;
	}

	template <typename t_CFOpts>
	void TCFunctionSmallBase<t_CFOpts>::fp_Destroy()
	{
		if (!fp_IsDefault())
		{
			fp_DestroyCall()(fp_GetImpl());
			auto &VTable = *mp_Data.m_pImp->m_pVTable;
			uint8 *pStart = fg_AlignDown((uint8 *)mp_Data.m_pImp, VTable.m_Alignment);
			uint8 *pEnd = (uint8 *)fp_GetImpl() + fg_AlignUp(VTable.m_Size, alignof(CImplementationData));
			mp_Data.f_Free(pStart, pEnd - pStart);
		}
	}

	template <typename t_CFOpts>
	void TCFunctionSmallBase<t_CFOpts>::fp_Move(TCFunctionSmallBase &&_Other)
	{
		if (!_Other.fp_IsDefault())
		{
			if constexpr (NTraits::cIsEmpty<CAllocator>)
			{
				mp_Data.m_pImp = _Other.mp_Data.m_pImp;
				mp_Data = fg_Move(_Other.mp_Data);
				_Other.fp_SetDefault();
			}
			else
			{
				bool bCanSteal = false;
				if constexpr (CAllocator::mc_CanBeStatic)
				{
					if (!_Other.mp_Data.f_IsStatic(_Other.mp_Data.m_pImp))
						bCanSteal = (CAllocator &)mp_Data == (CAllocator &)_Other.mp_Data;
				}
				else
					bCanSteal = (CAllocator &)mp_Data == (CAllocator &)_Other.mp_Data;

				if (bCanSteal)
				{
					mp_Data.m_pImp = _Other.mp_Data.m_pImp;
					mp_Data = fg_Move(_Other.mp_Data);
					_Other.fp_SetDefault();
				}
				else
				{
					fp_SetDefault();
					fp_Duplicate<true>(fg_Move(_Other));
					_Other.fp_Destroy();
					_Other.fp_SetDefault();
				}
			}
		}
		else
			fp_SetDefault();
	}

	template <typename t_CFOpts>
	void TCFunctionSmallBase<t_CFOpts>::fp_MoveAssign(TCFunctionSmallBase &&_Other)
	{
		if (!_Other.fp_IsDefault())
		{
			if constexpr (NTraits::cIsEmpty<CAllocator>)
			{
				fp_Destroy();
				mp_Data.m_pImp = _Other.mp_Data.m_pImp;
				mp_Data = fg_Move(_Other.mp_Data);
				_Other.fp_SetDefault();
			}
			else
			{
				bool bCanSteal = false;
				if constexpr (CAllocator::mc_CanBeStatic)
				{
					if (!_Other.mp_Data.f_IsStatic(_Other.mp_Data.m_pImp))
						bCanSteal = (CAllocator &)mp_Data == (CAllocator &)_Other.mp_Data;
				}
				else
					bCanSteal = (CAllocator &)mp_Data == (CAllocator &)_Other.mp_Data;

				if (bCanSteal)
				{
					fp_Destroy();
					mp_Data.m_pImp = _Other.mp_Data.m_pImp;
					mp_Data = fg_Move(_Other.mp_Data);
					_Other.fp_SetDefault();
				}
				else
				{
					fp_Duplicate<true>(fg_Move(_Other));
					_Other.fp_Destroy();
					_Other.fp_SetDefault();
				}
			}
		}
		else
		{
			fp_Destroy();
			fp_SetDefault();
		}
	}

	template <typename t_CFOpts>
	template <typename t_CFunctor>
	template <typename tf_CFunction>
	TCFunctionSmallBase<t_CFOpts>::TCConstructObject<t_CFunctor>::TCConstructObject(tf_CFunction &&_Function)
		: m_Functor(fg_Forward<tf_CFunction>(_Function))
	{
	}

	template <typename t_CFOpts>
	template <typename tf_CObject, typename tf_CParam>
	void *TCFunctionSmallBase<t_CFOpts>::fp_ConstructObject(tf_CParam &&_Param)
	{
		using CConstructObject = TCConstructObject<tf_CObject>;
		CConstructObject *pObject = fg_ConstructObject<CConstructObject>(mp_Data, fg_Forward<tf_CParam>(_Param));
		return pObject;
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	void TCFunctionSmallBase<t_CFOpts>::fp_Construct(tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;
		using CConstructObject = TCConstructObject<typename CImpl::CImplBase>;

		CImplementationData *pObject = (CImplementationData *)(&fg_ConstructObject<CConstructObject>(mp_Data, fg_Forward<tf_CFunction>(_Function))->m_Functor);
		mp_Data.m_pImp = pObject - 1;
		mp_Data.m_pImp->m_pVTable = &CImpl::CVTable::mc_VTable;
	}

	template <typename t_CFOpts>
	void const *TCFunctionSmallBase<t_CFOpts>::fp_GetFirstFunctionPointer() const
	{
		return reinterpret_cast<void const *>(mp_Data.m_pImp->m_pVTable->m_Calls.template f_GetFunction<0>());
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	void TCFunctionSmallBase<t_CFOpts>::fp_Assign(tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;
		using CConstructObject = TCConstructObject<typename CImpl::CImplBase>;

		if (mp_Data.f_OnlyOneAlloc())
		{
			fp_Destroy();
			fp_SetDefault();
			CImplementationData *pObject = (CImplementationData *)(&fg_ConstructObject<CConstructObject>(mp_Data, fg_Forward<tf_CFunction>(_Function))->m_Functor);
			mp_Data.m_pImp = pObject - 1;
			mp_Data.m_pImp->m_pVTable = &CImpl::CVTable::mc_VTable;
		}
		else
		{
			CImplementationData *pObject = (CImplementationData *)(&fg_ConstructObject<CConstructObject>(mp_Data, fg_Forward<tf_CFunction>(_Function))->m_Functor);
			fp_Destroy();
			mp_Data.m_pImp = pObject - 1;
			mp_Data.m_pImp->m_pVTable = &CImpl::CVTable::mc_VTable;
		}
	}

	template <typename t_CFOpts>
	template <bool tf_bMove>
	void TCFunctionSmallBase<t_CFOpts>::fp_Duplicate(typename TCGetDuplicateSignature<tf_bMove>::CType _Other)
	{
		if (!_Other.fp_IsDefault())
		{
			if (mp_Data.f_OnlyOneAlloc())
			{
				fp_Destroy();
				fp_SetDefault();
				CImplementationData *pNew;
				if constexpr (tf_bMove)
					pNew = fg_AlignUp(((CImplementationData *)_Other.fp_DuplicateMoveCall()((void *)_Other.fp_GetImpl(), *this)) + 1, _Other.mp_Data.m_pImp->m_pVTable->m_Alignment);
				else
					pNew = fg_AlignUp(((CImplementationData *)_Other.fp_DuplicateCall()(_Other.fp_GetImpl(), *this)) + 1, _Other.mp_Data.m_pImp->m_pVTable->m_Alignment);

				mp_Data.m_pImp = pNew - 1;
			}
			else
			{
				CImplementationData *pNew;
				if constexpr (tf_bMove)
					pNew = fg_AlignUp(((CImplementationData *)_Other.fp_DuplicateMoveCall()((void *)_Other.fp_GetImpl(), *this)) + 1, _Other.mp_Data.m_pImp->m_pVTable->m_Alignment);
				else
					pNew = fg_AlignUp(((CImplementationData *)_Other.fp_DuplicateCall()(_Other.fp_GetImpl(), *this)) + 1, _Other.mp_Data.m_pImp->m_pVTable->m_Alignment);
				fp_Destroy();
				mp_Data.m_pImp = pNew - 1;
			}
			mp_Data.m_pImp->m_pVTable = _Other.mp_Data.m_pImp->m_pVTable;
		}
		else
		{
			fp_Destroy();
			fp_SetDefault();
		}
	}

	template <typename t_CFOpts>
	mark_nodebug FDelete *TCFunctionSmallBase<t_CFOpts>::fp_DestroyCall() const
	{
		return mp_Data.m_pImp->m_pVTable->m_fDestroy;
	}

	template <typename t_CFOpts>
	auto TCFunctionSmallBase<t_CFOpts>::fp_DuplicateCall() const -> typename CFunctionDefinition::FDuplicate *
	{
		return mp_Data.m_pImp->m_pVTable->m_fDuplicate;
	}

	template <typename t_CFOpts>
	auto TCFunctionSmallBase<t_CFOpts>::fp_DuplicateMoveCall() const -> typename CFunctionDefinition::FDuplicateMove *
	{
		return mp_Data.m_pImp->m_pVTable->m_fDuplicateMove;
	}

	template <typename t_CFOpts>
	template <umint t_iCall, typename t_CDummmy>
	mark_artificial mark_nodebug inline_always auto TCFunctionSmallBase<t_CFOpts>::TCCallRet<t_iCall, t_CDummmy>::fs_Get(TCFunctionSmallBase const *_pThis)
		-> typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::FType *
	{
		return _pThis->mp_Data.m_pImp->m_pVTable->m_Calls.template f_GetFunction<t_iCall>();
	}

	template <typename t_CFOpts>
	template <umint tf_iCall>
	mark_artificial mark_nodebug inline_always typename TCGetFunctionCallDefinition<t_CFOpts, tf_iCall>::FType *TCFunctionSmallBase<t_CFOpts>::fp_Call() const
	{
		return TCCallRet<tf_iCall>::fs_Get(this);
	}

	template <typename t_CFOpts>
	FCompareEqual *TCFunctionSmallBase<t_CFOpts>::fp_CompareEqual() const noexcept
	{
		return (FCompareEqual *)mp_Data.m_pImp->m_pVTable->m_fCompareEqual;
	}

	template <typename t_CFOpts>
	FCompareSpaceship *TCFunctionSmallBase<t_CFOpts>::fp_CompareSpaceship() const noexcept
	{
		return (FCompareSpaceship *)mp_Data.m_pImp->m_pVTable->m_fCompareSpaceship;
	}

	template <typename t_CFOpts>
	TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCFunctionNoAllocBaseSeparateCall()
		: mp_pCall(&CNullFunction::CCallImp0::fs_Call)
		, mp_pVTable(&CNullFunction::CVTable::mc_VTable, 2)
	{
	}

	template <typename t_CFOpts>
	TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCFunctionNoAllocBaseSeparateCall(TCFunctionNoAllocBaseSeparateCall const &_Other)
		: TCFunctionNoAllocBaseSeparateCall()
	{
	}

	template <typename t_CFOpts>
	TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCFunctionNoAllocBaseSeparateCall(TCFunctionNoAllocBaseSeparateCall &&_Other)
		: TCFunctionNoAllocBaseSeparateCall()
	{
	}

	template <typename t_CFOpts>
	TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::~TCFunctionNoAllocBaseSeparateCall()
	{
		//NMemory::fg_Free(m_pStorage);
	}

	template <typename t_CFOpts>
	bool TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_IsDefault() const
	{
		return mp_pVTable.f_GetBits() == 2;
	}

	template <typename t_CFOpts>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_SetDefault()
	{
		mp_pCall = &CNullFunction::CCallImp0::fs_Call;
		mp_pVTable.f_SetBoth(&CNullFunction::CVTable::mc_VTable, 2);
	}

	template <typename t_CFOpts>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_Destroy()
	{
		if (mp_pVTable.f_GetBits() != 2)
			fp_DestroyCall()(fp_GetImpl());
	}

	template <typename t_CFOpts>
	template <bool tf_bMove>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_Duplicate(typename TCGetDuplicateSignature<tf_bMove>::CType _Other)
	{
		if (_Other.mp_pVTable.f_GetBits() != 2)
		{
			fp_Destroy();
			fp_SetDefault();
			if constexpr (tf_bMove)
				_Other.mp_pVTable->m_fDuplicateMove((void *)_Other.fp_GetImpl(), *this);
			else
				_Other.mp_pVTable->m_fDuplicate(_Other.fp_GetImpl(), *this);
			mp_pCall = _Other.mp_pCall;
			mp_pVTable.f_SetBoth(_Other.mp_pVTable);
		}
		else
		{
			fp_Destroy();
			fp_SetDefault();
		}
	}

	template <typename t_CFOpts>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_Move(TCFunctionNoAllocBaseSeparateCall &&_Other)
	{
		fp_Duplicate<true>(fg_Move(_Other));
		_Other.fp_Destroy();
		_Other.fp_SetDefault();
	}

	template <typename t_CFOpts>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_MoveAssign(TCFunctionNoAllocBaseSeparateCall &&_Other)
	{
		fp_Duplicate<true>(fg_Move(_Other));
		_Other.fp_Destroy();
		_Other.fp_SetDefault();
	}

	template <typename t_CFOpts>
	template <typename tf_CObject, typename tf_CParam>
	tf_CObject *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_ConstructObject(tf_CParam &&_Param)
	{
		static_assert(sizeof(tf_CObject) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage (internal error)");
		return new(mp_Storage) tf_CObject(fg_Forward<tf_CParam>(_Param));
	}

	template <typename t_CFOpts>
	template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCConstructInternal<t_bMustAlloc, t_bAllowAlloc, t_CDummy>::fs_Perform
		(
			TCFunctionNoAllocBaseSeparateCall &_This
			, tf_CFunction &&_Function
		)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
		static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

		new(_This.mp_Storage) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));

		_This.mp_pCall = CImpl::CCallImp0::fs_Call;
		_This.mp_pVTable.f_SetBoth(&CImpl::CVTable::mc_VTable, 0);
	}

	template <typename t_CFOpts>
	template <typename t_CDummy>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCConstructInternal<true, true, t_CDummy>::fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function)
	{
		using CUniquePointer = TCConditional
			<
				NTraits::cIsSame<CAllocator, NMemory::CDefaultAllocator>
				, NStorage::TCUniquePointer<NTraits::TCRemoveQualifiers<NTraits::TCRemoveReferenceStorable<tf_CFunction>>>
				, NStorage::TCUniquePointer<NTraits::TCRemoveQualifiers<NTraits::TCRemoveReferenceStorable<tf_CFunction>>, CAllocator>
			>
		;

		using CImpl = typename TCDetermineImpl<CUniquePointer, CFunctionDefinition>::CType;

		static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
		static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

		new(_This.mp_Storage) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));

		_This.mp_pCall = CImpl::CCallImp0::fs_Call;
		_This.mp_pVTable.f_SetBoth(&CImpl::CVTable::mc_VTable, 1);
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_Construct(tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;
		TCConstructInternal
			<
				(sizeof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_MaxSize) || (alignof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_Alignment)
				, t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc
			>
			::fs_Perform(*this, fg_Forward<tf_CFunction>(_Function))
		;
	}

	template <typename t_CFOpts>
	template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCAssignInternal<t_bMustAlloc, t_bAllowAlloc, t_CDummy>::fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
		static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

		// Start by destroying in case of exception in constructor
		_This.fp_Destroy();
		_This.mp_pCall = &CNullFunction::CCallImp0::fs_Call;
		_This.mp_pVTable.f_SetBoth(&CNullFunction::CVTable::mc_VTable, 2);

		new(_This.mp_Storage) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));

		_This.mp_pCall = CImpl::CCallImp0::fs_Call;
		_This.mp_pVTable.f_SetBoth(&CImpl::CVTable::mc_VTable, 0);
	}

	template <typename t_CFOpts>
	template <typename t_CDummy>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCAssignInternal<true, true, t_CDummy>::fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function)
	{
		using CUniquePointer = TCConditional
			<
				NTraits::cIsSame<CAllocator, NMemory::CDefaultAllocator>
				, NStorage::TCUniquePointer<NTraits::TCRemoveQualifiers<NTraits::TCRemoveReferenceStorable<tf_CFunction>>>
				, NStorage::TCUniquePointer<NTraits::TCRemoveQualifiers<NTraits::TCRemoveReferenceStorable<tf_CFunction>>, CAllocator>
			>
		;
		using CImpl = typename TCDetermineImpl<CUniquePointer, CFunctionDefinition>::CType;

		static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
		static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

		// Start by destroying in case of exception in constructor
		_This.fp_Destroy();
		_This.mp_pCall = &CNullFunction::CCallImp0::fs_Call;
		_This.mp_pVTable.f_SetBoth(&CNullFunction::CVTable::mc_VTable, 2);

		new(_This.mp_Storage) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));

		_This.mp_pCall = CImpl::CCallImp0::fs_Call;
		_This.mp_pVTable.f_SetBoth(&CImpl::CVTable::mc_VTable, 1);
	}

	template <typename t_CFOpts>
	void const *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_GetFirstFunctionPointer() const
	{
		return reinterpret_cast<void const *>(mp_pCall);
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_Assign(tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		TCAssignInternal
			<
				(sizeof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_MaxSize) || (alignof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_Alignment)
				, t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc
			>
			::fs_Perform(*this, fg_Forward<tf_CFunction>(_Function))
		;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_GetImpl()
	{
		return mp_Storage;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_GetImpl() const
	{
		return (uint8 *)mp_Storage;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_GetFunctor() const
	{
		if (mp_pVTable.f_GetBits() == 2)
			return nullptr;

		if constexpr (t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc)
		{
			if (mp_pVTable.f_GetBits() == 1)
				return ((NStorage::TCUniquePointer<uint8, CAllocator> *)mp_Storage)->f_Get();
		}

		return (uint8 *)mp_Storage;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_GetFunctorUnsafe() const
	{
		DMibFastCheck(mp_pVTable.f_GetBits() == 0);

		return (uint8 *)mp_Storage;
	}

	template <typename t_CFOpts>
	mark_nodebug inline_small auto TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_VTable() const -> CVTable const *
	{
		return mp_pVTable;
	}

	template <typename t_CFOpts>
	mark_nodebug FDelete *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_DestroyCall() const
	{
		return mp_pVTable->m_fDestroy;
	}

	template <typename t_CFOpts>
	auto TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_DuplicateCall() const -> typename CFunctionDefinition::FDuplicate *
	{
		return mp_pVTable->m_fDuplicate;
	}

	template <typename t_CFOpts>
	auto TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_DuplicateMoveCall() const -> typename CFunctionDefinition::FDuplicateMove *
	{
		return mp_pVTable->m_fDuplicateMove;
	}

	template <typename t_CFOpts>
	template <umint t_iCall, typename t_CDummmy>
	mark_artificial mark_nodebug inline_always auto TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCCallRet<t_iCall, t_CDummmy>::fs_Get(TCFunctionNoAllocBaseSeparateCall const *_pThis)
		-> typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::FType *
	{
		return _pThis->mp_pVTable->m_Calls.template f_GetFunction<t_iCall>();
	}

	template <typename t_CFOpts>
	template <typename t_CDummmy>
	mark_artificial mark_nodebug inline_always auto TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::TCCallRet<0, t_CDummmy>::fs_Get(TCFunctionNoAllocBaseSeparateCall const *_pThis)
		-> typename TCGetFunctionCallDefinition<t_CFOpts, 0>::FType *
	{
		return _pThis->mp_pCall;
	}

	template <typename t_CFOpts>
	template <umint tf_iCall>
	mark_artificial mark_nodebug inline_always typename TCGetFunctionCallDefinition<t_CFOpts, tf_iCall>::FType *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_Call() const
	{
		return TCCallRet<tf_iCall>::fs_Get(this);
	}

	template <typename t_CFOpts>
	FCompareEqual *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_CompareEqual() const noexcept
	{
		return (FCompareEqual *)mp_pVTable->m_fCompareEqual;
	}

	template <typename t_CFOpts>
	FCompareSpaceship *TCFunctionNoAllocBaseSeparateCall<t_CFOpts>::fp_CompareSpaceship() const noexcept
	{
		return (FCompareSpaceship *)mp_pVTable->m_fCompareSpaceship;
	}

	template <typename t_CFOpts>
	TCFunctionNoAllocBase<t_CFOpts>::TCFunctionNoAllocBase()
		: mp_pVTable(&CNullFunction::CVTable::mc_VTable, 2)
	{
	}

	template <typename t_CFOpts>
	TCFunctionNoAllocBase<t_CFOpts>::TCFunctionNoAllocBase(TCFunctionNoAllocBase const &_Other)
		: TCFunctionNoAllocBase()
	{
	}

	template <typename t_CFOpts>
	TCFunctionNoAllocBase<t_CFOpts>::TCFunctionNoAllocBase(TCFunctionNoAllocBase &&_Other)
		: TCFunctionNoAllocBase()
	{
	}

	template <typename t_CFOpts>
	TCFunctionNoAllocBase<t_CFOpts>::~TCFunctionNoAllocBase()
	{
		//NMemory::fg_Free(m_pStorage);
	}

	template <typename t_CFOpts>
	bool TCFunctionNoAllocBase<t_CFOpts>::fp_IsDefault() const
	{
		return mp_pVTable.f_GetBits() == 2;
	}

	template <typename t_CFOpts>
	void TCFunctionNoAllocBase<t_CFOpts>::fp_SetDefault()
	{
		mp_pVTable.f_SetBoth(&CNullFunction::CVTable::mc_VTable, 2);
	}

	template <typename t_CFOpts>
	void TCFunctionNoAllocBase<t_CFOpts>::fp_Destroy()
	{
		if (mp_pVTable.f_GetBits() != 2)
			fp_DestroyCall()(fp_GetImpl());
	}

	template <typename t_CFOpts>
	template <bool tf_bMove>
	void TCFunctionNoAllocBase<t_CFOpts>::fp_Duplicate(typename TCGetDuplicateSignature<tf_bMove>::CType _Other)
	{
		if (_Other.mp_pVTable.f_GetBits() != 2)
		{
			fp_Destroy();
			fp_SetDefault();
			if constexpr (tf_bMove)
				_Other.mp_pVTable->m_fDuplicateMove((void *)_Other.fp_GetImpl(), *this);
			else
				_Other.mp_pVTable->m_fDuplicate(_Other.fp_GetImpl(), *this);
			mp_pVTable.f_SetBoth(_Other.mp_pVTable);
		}
		else
		{
			fp_Destroy();
			fp_SetDefault();
		}
	}

	template <typename t_CFOpts>
	void TCFunctionNoAllocBase<t_CFOpts>::fp_Move(TCFunctionNoAllocBase &&_Other)
	{
		fp_Duplicate<true>(fg_Move(_Other));
		_Other.fp_Destroy();
		_Other.fp_SetDefault();
	}

	template <typename t_CFOpts>
	void TCFunctionNoAllocBase<t_CFOpts>::fp_MoveAssign(TCFunctionNoAllocBase &&_Other)
	{
		fp_Duplicate<true>(fg_Move(_Other));
		_Other.fp_Destroy();
		_Other.fp_SetDefault();
	}

	template <typename t_CFOpts>
	template <typename tf_CObject, typename tf_CParam>
	tf_CObject *TCFunctionNoAllocBase<t_CFOpts>::fp_ConstructObject(tf_CParam &&_Param)
	{
		static_assert(sizeof(tf_CObject) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage (internal error)");
		return new(mp_Storage) tf_CObject(fg_Forward<tf_CParam>(_Param));
	}

	template <typename t_CFOpts>
	template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBase<t_CFOpts>::TCConstructInternal<t_bMustAlloc, t_bAllowAlloc, t_CDummy>::fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
		static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

		new(_This.mp_Storage) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
		_This.mp_pVTable.f_SetBoth(&CImpl::CVTable::mc_VTable, 0);
	}

	template <typename t_CFOpts>
	template <typename t_CDummy>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBase<t_CFOpts>::TCConstructInternal<true, true, t_CDummy>::fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function)
	{
		using CUniquePointer = TCConditional
			<
				NTraits::cIsSame<CAllocator, NMemory::CDefaultAllocator>
				, NStorage::TCUniquePointer<NTraits::TCRemoveQualifiers<NTraits::TCRemoveReferenceStorable<tf_CFunction>>>
				, NStorage::TCUniquePointer<NTraits::TCRemoveQualifiers<NTraits::TCRemoveReferenceStorable<tf_CFunction>>, CAllocator>
			>
		;
		using CImpl = typename TCDetermineImpl<CUniquePointer, CFunctionDefinition>::CType;

		static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
		static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

		new(_This.mp_Storage) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
		_This.mp_pVTable.f_SetBoth(&CImpl::CVTable::mc_VTable, 1);
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBase<t_CFOpts>::fp_Construct(tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		TCConstructInternal
			<
				(sizeof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_MaxSize) || (alignof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_Alignment)
				, t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc
			>
			::fs_Perform(*this, fg_Forward<tf_CFunction>(_Function))
		;
	}

	template <typename t_CFOpts>
	template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBase<t_CFOpts>::TCAssignInternal<t_bMustAlloc, t_bAllowAlloc, t_CDummy>::fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
		static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

		// Start by destroying in case of exception in constructor
		_This.fp_Destroy();
		_This.mp_pVTable.f_SetBoth(&CNullFunction::CVTable::mc_VTable, 2);

		new(_This.mp_Storage) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
		_This.mp_pVTable.f_SetBoth(&CImpl::CVTable::mc_VTable, 0);
	}

	template <typename t_CFOpts>
	template <typename t_CDummy>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBase<t_CFOpts>::TCAssignInternal<true, true, t_CDummy>::fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function)
	{
		using CUniquePointer = TCConditional
			<
				NTraits::cIsSame<CAllocator, NMemory::CDefaultAllocator>
				, NStorage::TCUniquePointer<NTraits::TCRemoveQualifiers<NTraits::TCRemoveReferenceStorable<tf_CFunction>>>
				, NStorage::TCUniquePointer<NTraits::TCRemoveQualifiers<NTraits::TCRemoveReferenceStorable<tf_CFunction>>, CAllocator>
			>
		;
		using CImpl = typename TCDetermineImpl<CUniquePointer, CFunctionDefinition>::CType;

		static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
		static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

		// Start by destroying in case of exception in constructor
		_This.fp_Destroy();
		_This.mp_pVTable.f_SetBoth(&CNullFunction::CVTable::mc_VTable, 2);

		new(_This.mp_Storage) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
		_This.mp_pVTable.f_SetBoth(&CImpl::CVTable::mc_VTable, 1);
	}

	template <typename t_CFOpts>
	void const *TCFunctionNoAllocBase<t_CFOpts>::fp_GetFirstFunctionPointer() const
	{
		return reinterpret_cast<void const *>(mp_pVTable->m_Calls.template f_GetFunction<0>());
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	void TCFunctionNoAllocBase<t_CFOpts>::fp_Assign(tf_CFunction &&_Function)
	{
		using CImpl = typename TCDetermineImpl<NTraits::TCRemoveReferenceStorable<tf_CFunction>, CFunctionDefinition>::CType;

		TCAssignInternal
			<
				(sizeof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_MaxSize) || (alignof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_Alignment)
				, t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc
			>
			::fs_Perform(*this, fg_Forward<tf_CFunction>(_Function))
		;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *TCFunctionNoAllocBase<t_CFOpts>::fp_GetImpl()
	{
		return mp_Storage;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *TCFunctionNoAllocBase<t_CFOpts>::fp_GetImpl() const
	{
		return (uint8 *)mp_Storage;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *TCFunctionNoAllocBase<t_CFOpts>::fp_GetFunctor() const
	{
		if (mp_pVTable.f_GetBits() == 2)
			return nullptr;

		if constexpr (t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc)
		{
			if (mp_pVTable.f_GetBits() == 1)
				return ((NStorage::TCUniquePointer<uint8, CAllocator> *)mp_Storage)->f_Get();
		}

		return (uint8 *)mp_Storage;
	}

	template <typename t_CFOpts>
	mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *TCFunctionNoAllocBase<t_CFOpts>::fp_GetFunctorUnsafe() const
	{
		DMibFastCheck(mp_pVTable.f_GetBits() == 0);

		return (uint8 *)mp_Storage;
	}

	template <typename t_CFOpts>
	mark_nodebug inline_small auto TCFunctionNoAllocBase<t_CFOpts>::fp_VTable() const -> CVTable const *
	{
		return mp_pVTable;
	}

	template <typename t_CFOpts>
	mark_nodebug FDelete *TCFunctionNoAllocBase<t_CFOpts>::fp_DestroyCall() const
	{
		return mp_pVTable->m_fDestroy;
	}

	template <typename t_CFOpts>
	auto TCFunctionNoAllocBase<t_CFOpts>::fp_DuplicateCall() const -> typename CFunctionDefinition::FDuplicate *
	{
		return mp_pVTable->m_fDuplicate;
	}

	template <typename t_CFOpts>
	auto TCFunctionNoAllocBase<t_CFOpts>::fp_DuplicateMoveCall() const -> typename CFunctionDefinition::FDuplicateMove *
	{
		return mp_pVTable->m_fDuplicateMove;
	}

	template <typename t_CFOpts>
	template <umint t_iCall>
	mark_artificial mark_nodebug inline_always auto TCFunctionNoAllocBase<t_CFOpts>::TCCallRet<t_iCall>::fs_Get(TCFunctionNoAllocBase const *_pThis)
		-> typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::FType *
	{
		return _pThis->mp_pVTable->m_Calls.template f_GetFunction<t_iCall>();
	}

	template <typename t_CFOpts>
	template <umint tf_iCall>
	mark_artificial mark_nodebug inline_always typename TCGetFunctionCallDefinition<t_CFOpts, tf_iCall>::FType *TCFunctionNoAllocBase<t_CFOpts>::fp_Call() const
	{
		return TCCallRet<tf_iCall>::fs_Get(this);
	}

	template <typename t_CFOpts>
	FCompareEqual *TCFunctionNoAllocBase<t_CFOpts>::fp_CompareEqual() const noexcept
	{
		return (FCompareEqual *)mp_pVTable->m_fCompareEqual;
	}

	template <typename t_CFOpts>
	FCompareSpaceship *TCFunctionNoAllocBase<t_CFOpts>::fp_CompareSpaceship() const noexcept
	{
		return (FCompareSpaceship *)mp_pVTable->m_fCompareSpaceship;
	}

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	mark_artificial inline_always auto TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_Const>
		::operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) const
		-> t_CReturn
	{
		return this->template fp_Call<0>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	mark_artificial inline_always auto TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_None>
		::operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params)
		-> t_CReturn
	{
		return this->template fp_Call<0>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, umint t_iFunction, typename t_CReturn, typename ...tp_CParams>
	mark_artificial inline_always auto TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_Const>
		::operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) const
		-> t_CReturn
	{
		return this->template fp_Call<t_iFunction>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, umint t_iFunction, typename t_CReturn, typename ...tp_CParams>
	mark_artificial inline_always auto TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_None>
		::operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params)
		-> t_CReturn
	{
		return this->template fp_Call<t_iFunction>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	mark_artificial inline_always auto TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_Const>
		::operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) const noexcept
		-> t_CReturn
	{
		return this->template fp_Call<0>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	mark_artificial inline_always auto TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_None>
		::operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) noexcept
		-> t_CReturn
	{
		return this->template fp_Call<0>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, umint t_iFunction, typename t_CReturn, typename ...tp_CParams>
	mark_artificial inline_always auto TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_Const>
		::operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) const noexcept
		-> t_CReturn
	{
		return this->template fp_Call<t_iFunction>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CBase, umint t_iFunction, typename t_CReturn, typename ...tp_CParams>
	mark_artificial inline_always auto TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_None>
		::operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) noexcept
		-> t_CReturn
	{
		return this->template fp_Call<t_iFunction>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::~TCFunctionImplementation()
	{
		this->fp_Destroy();
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::TCFunctionImplementation()
	{
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	template <typename ...tfp_CParams>
	TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::TCFunctionImplementation(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CSuper(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::TCFunctionImplementation(TCFunctionImplementation const &_Other)
		: CSuper(static_cast<CSuper const &>(_Other))
	{
		this->template fp_Duplicate<false>(_Other);
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	auto TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::operator = (TCFunctionImplementation const &_Other) -> TCFunctionImplementation &
	{
		this->template fp_Duplicate<false>(_Other);
		return *this;
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::TCFunctionImplementation(TCFunctionImplementation &_Other)
		: CSuper(static_cast<CSuper const &>(_Other))
	{
		this->template fp_Duplicate<false>(_Other);
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	auto TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::operator = (TCFunctionImplementation &_Other) -> TCFunctionImplementation &
	{
		this->template fp_Duplicate<false>(_Other);
		return *this;
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::TCFunctionImplementation(TCFunctionImplementation &&_Other)
		: CSuper(fg_Move(static_cast<CSuper &>(_Other)))
	{
		this->fp_Move(fg_Move(_Other));
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	auto TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::operator = (TCFunctionImplementation &&_Other) -> TCFunctionImplementation &
	{
		this->fp_MoveAssign(fg_Move(_Other));
		return *this;
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	template <typename tf_CFunction>
	TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::TCFunctionImplementation(tf_CFunction &&_Function)
	{
		this->fp_Construct(fg_Forward<tf_CFunction>(_Function));
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	template <typename tf_CFunction>
	auto TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::operator = (tf_CFunction &&_Function) -> TCFunctionImplementation &
	{
		this->fp_Assign(fg_Forward<tf_CFunction>(_Function));
		return *this;
	}

	/**	\brief Clears the function object and destroys any contained functor.

		If function ojbect is called after this an exception CExceptionBadFunctionCall will be thrown.
	*/
	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	void TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::f_Clear()
	{
		this->fp_Destroy();
		this->fp_SetDefault();
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	void const *TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::f_GetFirstFunctionPointer() const
	{
		return this->fp_GetFirstFunctionPointer();
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::TCFunctionImplementation(CNullPtr _pNull)
	{
	}

	/// Clears the function object same as if f_Clear was called
	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	auto TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::operator = (CNullPtr _pNull) -> TCFunctionImplementation &
	{
		f_Clear();
		return *this;
	}

	/// Checks if a functor is stored in the function object. If not true is returned
	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	inline_small bool TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::f_IsEmpty() const
	{
		return this->fp_IsDefault();
	}

	/// Checks if a functor is stored in the function object. If a functiored is stored true is returned, otherwise false.
	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	inline_small TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::operator bool () const
	{
		return !this->fp_IsDefault();
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	inline_small void *TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::f_Unsafe_GetFunctor() const
	{
		return this->fp_GetFunctorUnsafe();
	}

	template <typename t_CFOpts, bool t_bSupportEqualityCompare, bool t_bSupportOrderedCompare>
	inline_small void *TCFunctionImplementation<t_CFOpts, t_bSupportEqualityCompare, t_bSupportOrderedCompare>::f_GetFunctor() const
	{
		return this->fp_GetFunctor();
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, true>::~TCFunctionImplementation()
	{
		this->fp_Destroy();
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, true>::TCFunctionImplementation()
	{
	}

	template <typename t_CFOpts>
	template <typename ...tfp_CParams>
	TCFunctionImplementation<t_CFOpts, true, true>::TCFunctionImplementation(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CSuper(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, true>::TCFunctionImplementation(TCFunctionImplementation const &_Other)
		: CSuper(static_cast<CSuper const &>(_Other))
	{
		this->template fp_Duplicate<false>(_Other);
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, true, true>::operator = (TCFunctionImplementation const &_Other) -> TCFunctionImplementation &
	{
		this->template fp_Duplicate<false>(_Other);
		return *this;
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, true>::TCFunctionImplementation(TCFunctionImplementation &_Other)
		: CSuper(static_cast<CSuper const &>(_Other))
	{
		this->template fp_Duplicate<false>(_Other);
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, true, true>::operator = (TCFunctionImplementation &_Other) -> TCFunctionImplementation &
	{
		this->template fp_Duplicate<false>(_Other);
		return *this;
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, true>::TCFunctionImplementation(TCFunctionImplementation &&_Other)
		: CSuper(fg_Move(static_cast<CSuper &>(_Other)))
	{
		this->fp_Move(fg_Move(_Other));
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, true, true>::operator = (TCFunctionImplementation &&_Other) -> TCFunctionImplementation &
	{
		this->fp_MoveAssign(fg_Move(_Other));
		return *this;
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	TCFunctionImplementation<t_CFOpts, true, true>::TCFunctionImplementation(tf_CFunction &&_Function)
	{
		this->fp_Construct(fg_Forward<tf_CFunction>(_Function));
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	auto TCFunctionImplementation<t_CFOpts, true, true>::operator = (tf_CFunction &&_Function) -> TCFunctionImplementation &
	{
		this->fp_Assign(fg_Forward<tf_CFunction>(_Function));
		return *this;
	}

	template <typename t_CFOpts>
	void TCFunctionImplementation<t_CFOpts, true, true>::f_Clear()
	{
		this->fp_Destroy();
		this->fp_SetDefault();
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, true>::TCFunctionImplementation(CNullPtr _pNull)
	{
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, true, true>::operator = (CNullPtr _pNull) -> TCFunctionImplementation &
	{
		f_Clear();
		return *this;
	}

	template <typename t_CFOpts>
	inline_small bool TCFunctionImplementation<t_CFOpts, true, true>::f_IsEmpty() const
	{
		return this->fp_IsDefault();
	}

	template <typename t_CFOpts>
	inline_small TCFunctionImplementation<t_CFOpts, true, true>::operator bool () const
	{
		return !this->fp_IsDefault();
	}

	template <typename t_CFOpts>
	inline_small void *TCFunctionImplementation<t_CFOpts, true, true>::f_Unsafe_GetFunctor() const
	{
		return this->fp_GetFunctorUnsafe();
	}

	template <typename t_CFOpts>
	inline_small void *TCFunctionImplementation<t_CFOpts, true, true>::f_GetFunctor() const
	{
		return this->fp_GetFunctor();
	}

	template <typename t_CFOpts>
	bool TCFunctionImplementation<t_CFOpts, true, true>::operator == (TCFunctionImplementation const &_Other) const noexcept
	{
		if (this->fp_VTable() != _Other.fp_VTable())
			return false;
		return this->fp_CompareEqual()(this->fp_GetImpl(), _Other.fp_GetImpl());
	}

	template <typename t_CFOpts>
	COrdering_Partial TCFunctionImplementation<t_CFOpts, true, true>::operator <=> (TCFunctionImplementation const &_Other) const noexcept
	{
		if (auto Result = this->fp_VTable() <=> _Other.fp_VTable(); Result != 0)
			return Result;

		return this->fp_CompareSpaceship()(this->fp_GetImpl(), _Other.fp_GetImpl());
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, false, true>::~TCFunctionImplementation()
	{
		this->fp_Destroy();
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, false, true>::TCFunctionImplementation()
	{
	}

	template <typename t_CFOpts>
	template <typename ...tfp_CParams>
	TCFunctionImplementation<t_CFOpts, false, true>::TCFunctionImplementation(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CSuper(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, false, true>::TCFunctionImplementation(TCFunctionImplementation const &_Other)
		: CSuper(static_cast<CSuper const &>(_Other))
	{
		this->template fp_Duplicate<false>(_Other);
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, false, true>::operator = (TCFunctionImplementation const &_Other) -> TCFunctionImplementation &
	{
		this->template fp_Duplicate<false>(_Other);
		return *this;
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, false, true>::TCFunctionImplementation(TCFunctionImplementation &_Other)
		: CSuper(static_cast<CSuper const &>(_Other))
	{
		this->template fp_Duplicate<false>(_Other);
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, false, true>::operator = (TCFunctionImplementation &_Other) -> TCFunctionImplementation &
	{
		this->template fp_Duplicate<false>(_Other);
		return *this;
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, false, true>::TCFunctionImplementation(TCFunctionImplementation &&_Other)
		: CSuper(fg_Move(static_cast<CSuper &>(_Other)))
	{
		this->fp_Move(fg_Move(_Other));
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, false, true>::operator = (TCFunctionImplementation &&_Other) -> TCFunctionImplementation &
	{
		this->fp_MoveAssign(fg_Move(_Other));
		return *this;
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	TCFunctionImplementation<t_CFOpts, false, true>::TCFunctionImplementation(tf_CFunction &&_Function)
	{
		this->fp_Construct(fg_Forward<tf_CFunction>(_Function));
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	auto TCFunctionImplementation<t_CFOpts, false, true>::operator = (tf_CFunction &&_Function) -> TCFunctionImplementation &
	{
		this->fp_Assign(fg_Forward<tf_CFunction>(_Function));
		return *this;
	}

	template <typename t_CFOpts>
	void TCFunctionImplementation<t_CFOpts, false, true>::f_Clear()
	{
		this->fp_Destroy();
		this->fp_SetDefault();
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, false, true>::TCFunctionImplementation(CNullPtr _pNull)
	{
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, false, true>::operator = (CNullPtr _pNull) -> TCFunctionImplementation &
	{
		f_Clear();
		return *this;
	}

	template <typename t_CFOpts>
	inline_small bool TCFunctionImplementation<t_CFOpts, false, true>::f_IsEmpty() const
	{
		return this->fp_IsDefault();
	}

	template <typename t_CFOpts>
	inline_small TCFunctionImplementation<t_CFOpts, false, true>::operator bool () const
	{
		return !this->fp_IsDefault();
	}

	template <typename t_CFOpts>
	inline_small void *TCFunctionImplementation<t_CFOpts, false, true>::f_Unsafe_GetFunctor() const
	{
		return this->fp_GetFunctorUnsafe();
	}

	template <typename t_CFOpts>
	inline_small void *TCFunctionImplementation<t_CFOpts, false, true>::f_GetFunctor() const
	{
		return this->fp_GetFunctor();
	}

	template <typename t_CFOpts>
	COrdering_Partial TCFunctionImplementation<t_CFOpts, false, true>::operator <=> (TCFunctionImplementation const &_Other) const noexcept
	{
		if (auto Result = this->fp_VTable() <=> _Other.fp_VTable(); Result != 0)
			return Result;

		return this->fp_CompareSpaceship()(this->fp_GetImpl(), _Other.fp_GetImpl());
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, false>::~TCFunctionImplementation()
	{
		this->fp_Destroy();
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, false>::TCFunctionImplementation()
	{
	}

	template <typename t_CFOpts>
	template <typename ...tfp_CParams>
	TCFunctionImplementation<t_CFOpts, true, false>::TCFunctionImplementation(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params)
		: CSuper(_Tag, fg_Forward<tfp_CParams>(p_Params)...)
	{
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, false>::TCFunctionImplementation(TCFunctionImplementation const &_Other)
		: CSuper(static_cast<CSuper const &>(_Other))
	{
		this->template fp_Duplicate<false>(_Other);
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, true, false>::operator = (TCFunctionImplementation const &_Other) -> TCFunctionImplementation &
	{
		this->template fp_Duplicate<false>(_Other);
		return *this;
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, false>::TCFunctionImplementation(TCFunctionImplementation &_Other)
		: CSuper(static_cast<CSuper const &>(_Other))
	{
		this->template fp_Duplicate<false>(_Other);
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, true, false>::operator = (TCFunctionImplementation &_Other) -> TCFunctionImplementation &
	{
		this->template fp_Duplicate<false>(_Other);
		return *this;
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, false>::TCFunctionImplementation(TCFunctionImplementation &&_Other)
		: CSuper(fg_Move(static_cast<CSuper &>(_Other)))
	{
		this->fp_Move(fg_Move(_Other));
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, true, false>::operator = (TCFunctionImplementation &&_Other) -> TCFunctionImplementation &
	{
		this->fp_MoveAssign(fg_Move(_Other));
		return *this;
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	TCFunctionImplementation<t_CFOpts, true, false>::TCFunctionImplementation(tf_CFunction &&_Function)
	{
		this->fp_Construct(fg_Forward<tf_CFunction>(_Function));
	}

	template <typename t_CFOpts>
	template <typename tf_CFunction>
	auto TCFunctionImplementation<t_CFOpts, true, false>::operator = (tf_CFunction &&_Function) -> TCFunctionImplementation &
	{
		this->fp_Assign(fg_Forward<tf_CFunction>(_Function));
		return *this;
	}

	template <typename t_CFOpts>
	void TCFunctionImplementation<t_CFOpts, true, false>::f_Clear()
	{
		this->fp_Destroy();
		this->fp_SetDefault();
	}

	template <typename t_CFOpts>
	TCFunctionImplementation<t_CFOpts, true, false>::TCFunctionImplementation(CNullPtr _pNull)
	{
	}

	template <typename t_CFOpts>
	auto TCFunctionImplementation<t_CFOpts, true, false>::operator = (CNullPtr _pNull) -> TCFunctionImplementation &
	{
		f_Clear();
		return *this;
	}

	template <typename t_CFOpts>
	inline_small bool TCFunctionImplementation<t_CFOpts, true, false>::f_IsEmpty() const
	{
		return this->fp_IsDefault();
	}

	template <typename t_CFOpts>
	inline_small TCFunctionImplementation<t_CFOpts, true, false>::operator bool () const
	{
		return !this->fp_IsDefault();
	}

	template <typename t_CFOpts>
	inline_small void *TCFunctionImplementation<t_CFOpts, true, false>::f_Unsafe_GetFunctor() const
	{
		return this->fp_GetFunctorUnsafe();
	}

	template <typename t_CFOpts>
	inline_small void *TCFunctionImplementation<t_CFOpts, true, false>::f_GetFunctor() const
	{
		return this->fp_GetFunctor();
	}

	template <typename t_CFOpts>
	bool TCFunctionImplementation<t_CFOpts, true, false>::operator == (TCFunctionImplementation const &_Other) const noexcept
	{
		if (this->fp_VTable() != _Other.fp_VTable())
			return false;
		return this->fp_CompareEqual()(this->fp_GetImpl(), _Other.fp_GetImpl());
	}
}
