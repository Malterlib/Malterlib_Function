// Copyright © 2015 Hansoft AB
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFOpts>
	class TCFunctionBase
	{
	public:
		using CFunctionOptions = t_CFOpts;

	private:
		template <typename t_CFunctor2, typename t_CFOpts2, bool t_bSupportEqualityCompare2, bool t_bSupportOrderedCompare2, bool t_bSupportCopy2, bool t_bSupportMove2>
		friend class TCImpl;

		typedef TCImpl<CNullFunctionImpl, t_CFOpts> CNullFunction;
		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
		typedef typename CFunctionDefinition::CVTable CVTable;
		typedef typename TCFunctionCallDefinition<typename t_CFOpts::CCall0>::CType CCallType0;
		typedef typename t_CFOpts::CAllocator CAllocator;

		static CVTable const *fsp_VTable();
	protected:

		class CData : public CAllocator
		{
		public:
			CData()
				: m_pVTable(&CNullFunction::CVTable::mc_VTable)
				, m_pImpl(nullptr)
				, m_pCall(&CNullFunction::CCallImp0::fs_Call)
			{
			}
			void * m_pImpl;
			CCallType0 * m_pCall;
			CVTable const * m_pVTable;
			CData &operator =(CData &&_Other)
			{
				*((CAllocator *)this) = fg_Move(*((CAllocator *)&_Other));
				return *this;
			}
			CData &operator =(CData const &_Other)
			{
				*((CAllocator *)this) = *((CAllocator const *)&_Other);
				return *this;
			}
		};

		CData m_Data;

		TCFunctionBase()
		{
		}

		bool fp_IsDefault() const
		{
			return m_Data.m_pImpl == nullptr;
		}
		void fp_SetDefault()
		{
			m_Data.m_pImpl = nullptr;
			m_Data.m_pCall = &CNullFunction::CCallImp0::fs_Call;
			m_Data.m_pVTable = &CNullFunction::CVTable::mc_VTable;
		}

		void fp_Move(TCFunctionBase &&_Other)
		{
			if (_Other.m_Data.m_pImpl)
			{
				if (_Other.m_Data.f_IsStatic(_Other.m_Data.m_pImpl))
				{
					fp_SetDefault();
					fp_Duplicate<true>(fg_Move(_Other));
					_Other.fp_Destroy();
					_Other.fp_SetDefault();
				}
				else
				{
					m_Data.m_pImpl = _Other.m_Data.m_pImpl;
					m_Data.m_pCall = _Other.m_Data.m_pCall;
					m_Data.m_pVTable = _Other.m_Data.m_pVTable;
					m_Data = fg_Move(_Other.m_Data);
					_Other.fp_SetDefault();
				}
			}
			else
				fp_SetDefault();
		}

		void fp_MoveAssign(TCFunctionBase &&_Other)
		{
			if (!_Other.fp_IsDefault())
			{
				if (_Other.m_Data.f_IsStatic(_Other.m_Data.m_pImpl))
				{
					fp_Duplicate<true>(fg_Move(_Other));
					_Other.fp_Destroy();
					_Other.fp_SetDefault();
				}
				else
				{
					fp_Destroy();
					m_Data.m_pImpl = _Other.m_Data.m_pImpl;
					m_Data.m_pCall = _Other.m_Data.m_pCall;
					m_Data.m_pVTable = _Other.m_Data.m_pVTable;
					m_Data = fg_Move(_Other.m_Data);
					_Other.fp_SetDefault();
				}
			}
			else
			{
				fp_Destroy();
				fp_SetDefault();
			}
		}

		template <typename t_CObject, typename t_CParam>
		t_CObject *fp_ConstructObject(t_CParam &&_Param)
		{
			return fg_ConstructObject<t_CObject>(m_Data, fg_Forward<t_CParam>(_Param));
		}

		template <typename t_CFunction>
		void fp_Construct(t_CFunction &&_Function)
		{
			typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<t_CFunction>::CType, CFunctionDefinition>::CType CImpl;
			m_Data.m_pImpl = fg_ConstructObject<typename CImpl::CImplBase>(m_Data, fg_Forward<t_CFunction>(_Function));
			m_Data.m_pCall = CImpl::CCallImp0::fs_Call;
			m_Data.m_pVTable = &CImpl::CVTable::mc_VTable;
		}

		void const *fp_GetFirstFunctionPointer() const
		{
			return reinterpret_cast<void const *>(m_Data.m_pCall);
		}

		template <typename t_CFunction>
		void fp_Assign(t_CFunction &&_Function)
		{
			typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<t_CFunction>::CType, CFunctionDefinition>::CType CImpl;
			if (m_Data.f_OnlyOneAlloc())
			{
				fp_Destroy();
				fp_SetDefault();
				m_Data.m_pImpl = fg_ConstructObject<typename CImpl::CImplBase>(m_Data, fg_Forward<t_CFunction>(_Function));;
			}
			else
			{
				auto *pNew = fg_ConstructObject<typename CImpl::CImplBase>(m_Data, fg_Forward<t_CFunction>(_Function));
				fp_Destroy();
				m_Data.m_pImpl = pNew;
			}
			m_Data.m_pCall = CImpl::CCallImp0::fs_Call;
			m_Data.m_pVTable = &CImpl::CVTable::mc_VTable;
		}


		template <bool t_bMove, typename t_CDummy = void>
		struct TCGetDuplicateSignature
		{
			typedef TCFunctionBase const & CType;
		};

		template <typename t_CDummy>
		struct TCGetDuplicateSignature<true, t_CDummy>
		{
			typedef TCFunctionBase && CType;
		};

		template <bool t_bMove>
		void fp_Duplicate(typename TCGetDuplicateSignature<t_bMove>::CType _Other)
		{
			if (_Other.m_Data.m_pImpl)
			{
				if (m_Data.f_OnlyOneAlloc())
				{
					fp_Destroy();
					fp_SetDefault();
					void *pNew;
					if constexpr (t_bMove)
						pNew = _Other.fp_DuplicateMoveCall()((void *)_Other.fp_GetImpl(), *this);
					else
						pNew = _Other.fp_DuplicateCall()(_Other.fp_GetImpl(), *this);

					m_Data.m_pImpl = pNew;
				}
				else
				{
					void *pNew;
					if constexpr (t_bMove)
						pNew = _Other.fp_DuplicateMoveCall()((void *)_Other.fp_GetImpl(), *this);
					else
						pNew = _Other.fp_DuplicateCall()(_Other.fp_GetImpl(), *this);
					fp_Destroy();
					m_Data.m_pImpl = pNew;
				}
				m_Data = _Other.m_Data;
				m_Data.m_pCall = _Other.m_Data.m_pCall;
				m_Data.m_pVTable = _Other.m_Data.m_pVTable;
			}
			else
			{
				fp_Destroy();
				fp_SetDefault();
			}
		}

		only_parameters_aliased return_not_aliased inline_small void *fp_GetImpl()
		{
			return m_Data.m_pImpl;
		}

		only_parameters_aliased return_not_aliased inline_small void *fp_GetImpl() const
		{
			return m_Data.m_pImpl;
		}

		inline_small CVTable const *fp_VTable() const
		{
			return m_Data.m_pVTable;
		}

		FDelete *fp_DestroyCall() const
		{
			return m_Data.m_pVTable->m_pDestroy;
		}
		typename CFunctionDefinition::FDuplicate *fp_DuplicateCall() const
		{
			return m_Data.m_pVTable->m_pDuplicate;
		}
		typename CFunctionDefinition::FDuplicateMove *fp_DuplicateMoveCall() const
		{
			return m_Data.m_pVTable->m_pDuplicateMove;
		}

		template <mint t_iCall, typename t_CDummmy = void>
		struct TCCallRet
		{
			mark_artificial inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::CType *fs_Get(TCFunctionBase const *_pThis) { return _pThis->m_pVTable->template f_GetFunction<t_iCall>(); }
		};

		template <typename t_CDummmy>
		struct TCCallRet<0, t_CDummmy>
		{
			mark_artificial inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, 0>::CType *fs_Get(TCFunctionBase const *_pThis) { return _pThis->m_Data.m_pCall; }
		};

		template <mint t_iCall>
		inline_always typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::CType *fp_Call() const
		{
			return TCCallRet<t_iCall>::fs_Get(this);
		}

		FCompareEqual *fp_CompareEqual() const
		{
			return (FCompareEqual *)m_Data.m_pVTable->m_pCompareEqual;
		}

		FCompareSpaceship *fp_CompareSpaceship() const
		{
			return (FCompareSpaceship *)m_Data.m_pVTable->m_pCompareSpaceship;
		}

		void fp_Destroy()
		{
			if (m_Data.m_pImpl)
			{
				fp_DestroyCall()(m_Data.m_pImpl);
				auto &VTable = *m_Data.m_pVTable;
				m_Data.f_Free(m_Data.m_pImpl, VTable.m_Size);
			}
		}
	};

	template <typename t_CFOpts>
	class TCFunctionSmallBase
	{
	public:
		using CFunctionOptions = t_CFOpts;

	private:
		template <typename t_CFunctor2, typename t_CFOpts2, bool t_bSupportEqualityCompare2, bool t_bSupportOrderedCompare2, bool t_bSupportCopy2, bool t_bSupportMove2>
		friend class TCImpl;

	public:
		typedef TCImpl<CNullFunctionImpl, t_CFOpts> CNullFunction;
	private:
		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
		typedef typename CFunctionDefinition::CVTable CVTable;
		typedef typename t_CFOpts::CAllocator CAllocator;

		static CVTable const *fsp_VTable();
	protected:

		struct CImplementationData
		{
			CVTable const * m_pVTable;
		};
		constexpr static CImplementationData mc_NullImplementation =
			{
				&TCFunctionSmallBase<t_CFOpts>::CNullFunction::CVTable::mc_VTable
			}
		;
		class CData : public CAllocator
		{
		public:
			CData()
				: m_pImp(const_cast<CImplementationData *>(&mc_NullImplementation))
			{
			}
			CImplementationData *m_pImp;
			CData &operator =(CData &&_Other)
			{
				*((CAllocator *)this) = fg_Move(*((CAllocator *)&_Other));
				return *this;
			}
			CData &operator =(CData const &_Other)
			{
				*((CAllocator *)this) = *((CAllocator const *)&_Other);
				return *this;
			}
		};

		CData m_Data;

		TCFunctionSmallBase()
		{
		}

		bool fp_IsDefault() const
		{
			return m_Data.m_pImp == &mc_NullImplementation;
		}

		void fp_SetDefault()
		{
			m_Data.m_pImp = const_cast<CImplementationData *>(&mc_NullImplementation);
		}

		only_parameters_aliased return_not_aliased inline_small void *fp_GetImpl()
		{
			return m_Data.m_pImp + 1;
		}

		only_parameters_aliased return_not_aliased inline_small void *fp_GetImpl() const
		{
			return m_Data.m_pImp + 1;
		}

		inline_small CVTable const *fp_VTable() const
		{
			return m_Data.m_pImp->m_pVTable;
		}

		void fp_Destroy()
		{
			if (!fp_IsDefault())
			{
				fp_DestroyCall()(fp_GetImpl());
				auto &VTable = *m_Data.m_pImp->m_pVTable;
				uint8 *pStart = fg_AlignDown((uint8 *)m_Data.m_pImp, VTable.m_Alignment);
				uint8 *pEnd = (uint8 *)fp_GetImpl() + fg_AlignUp(VTable.m_Size, alignof(CImplementationData));
				m_Data.f_Free(pStart, pEnd - pStart);
			}
		}

		void fp_Move(TCFunctionSmallBase &&_Other)
		{
			if (!_Other.fp_IsDefault())
			{
				if (_Other.m_Data.f_IsStatic(_Other.m_Data.m_pImp))
				{
					fp_SetDefault();
					fp_Duplicate<true>(fg_Move(_Other));
					_Other.fp_Destroy();
					_Other.fp_SetDefault();
				}
				else
				{
					m_Data.m_pImp = _Other.m_Data.m_pImp;
					m_Data = fg_Move(_Other.m_Data);
					_Other.fp_SetDefault();
				}
			}
			else
				fp_SetDefault();
		}

		void fp_MoveAssign(TCFunctionSmallBase &&_Other)
		{
			if (!_Other.fp_IsDefault())
			{
				if (_Other.m_Data.f_IsStatic(_Other.m_Data.m_pImp))
				{
					fp_Duplicate<true>(fg_Move(_Other));
					_Other.fp_Destroy();
					_Other.fp_SetDefault();
				}
				else
				{
					fp_Destroy();
					m_Data.m_pImp = _Other.m_Data.m_pImp;
					m_Data = fg_Move(_Other.m_Data);
					_Other.fp_SetDefault();
				}
			}
			else
			{
				fp_Destroy();
				fp_SetDefault();
			}
		}

		template <typename t_CFunctor>
		struct TCConstructObject : public CImplementationData
		{
			t_CFunctor m_Functor;
			template <typename t_CFunction>
			TCConstructObject(t_CFunction &&_Function)
				: m_Functor(fg_Forward<t_CFunction>(_Function))
			{
			}
		};

		template <typename t_CObject, typename t_CParam>
		void *fp_ConstructObject(t_CParam &&_Param)
		{
			typedef TCConstructObject<t_CObject> CConstructObject;
			CConstructObject *pObject = fg_ConstructObject<CConstructObject>(m_Data, fg_Forward<t_CParam>(_Param));
			return pObject;
		}

		template <typename t_CFunction>
		void fp_Construct(t_CFunction &&_Function)
		{
			typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<t_CFunction>::CType, CFunctionDefinition>::CType CImpl;
			typedef TCConstructObject<typename CImpl::CImplBase> CConstructObject;
			CImplementationData *pObject = (CImplementationData *)(&fg_ConstructObject<CConstructObject>(m_Data, fg_Forward<t_CFunction>(_Function))->m_Functor);
			m_Data.m_pImp = pObject - 1;
			m_Data.m_pImp->m_pVTable = &CImpl::CVTable::mc_VTable;
		}

		void const *fp_GetFirstFunctionPointer() const
		{
			return reinterpret_cast<void const *>(m_Data.m_pImp->m_pVTable->m_pCalls[0]);
		}

		template <typename t_CFunction>
		void fp_Assign(t_CFunction &&_Function)
		{
			typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<t_CFunction>::CType, CFunctionDefinition>::CType CImpl;
			typedef TCConstructObject<typename CImpl::CImplBase> CConstructObject;
			if (m_Data.f_OnlyOneAlloc())
			{
				fp_Destroy();
				fp_SetDefault();
				CImplementationData *pObject = (CImplementationData *)(&fg_ConstructObject<CConstructObject>(m_Data, fg_Forward<t_CFunction>(_Function))->m_Functor);
				m_Data.m_pImp = pObject - 1;
				m_Data.m_pImp->m_pVTable = &CImpl::CVTable::mc_VTable;
			}
			else
			{
				CImplementationData *pObject = (CImplementationData *)(&fg_ConstructObject<CConstructObject>(m_Data, fg_Forward<t_CFunction>(_Function))->m_Functor);
				fp_Destroy();
				m_Data.m_pImp = pObject - 1;
				m_Data.m_pImp->m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		}

		template <bool t_bMove, typename t_CDummy = void>
		struct TCGetDuplicateSignature
		{
			typedef TCFunctionSmallBase const & CType;
		};

		template <typename t_CDummy>
		struct TCGetDuplicateSignature<true, t_CDummy>
		{
			typedef TCFunctionSmallBase && CType;
		};

		template <bool t_bMove>
		void fp_Duplicate(typename TCGetDuplicateSignature<t_bMove>::CType _Other)
		{
			if (!_Other.fp_IsDefault())
			{
				if (m_Data.f_OnlyOneAlloc())
				{
					fp_Destroy();
					fp_SetDefault();
					CImplementationData *pNew;
					if constexpr (t_bMove)
						pNew = fg_AlignUp(((CImplementationData *)_Other.fp_DuplicateMoveCall()((void *)_Other.fp_GetImpl(), *this)) + 1, _Other.m_Data.m_pImp->m_pVTable->m_Alignment);
					else
						pNew = fg_AlignUp(((CImplementationData *)_Other.fp_DuplicateCall()(_Other.fp_GetImpl(), *this)) + 1, _Other.m_Data.m_pImp->m_pVTable->m_Alignment);

					m_Data.m_pImp = pNew - 1;
				}
				else
				{
					CImplementationData *pNew;
					if constexpr (t_bMove)
						pNew = fg_AlignUp(((CImplementationData *)_Other.fp_DuplicateMoveCall()((void *)_Other.fp_GetImpl(), *this)) + 1, _Other.m_Data.m_pImp->m_pVTable->m_Alignment);
					else
						pNew = fg_AlignUp(((CImplementationData *)_Other.fp_DuplicateCall()(_Other.fp_GetImpl(), *this)) + 1, _Other.m_Data.m_pImp->m_pVTable->m_Alignment);
					fp_Destroy();
					m_Data.m_pImp = pNew - 1;
				}
				m_Data = _Other.m_Data;
				m_Data.m_pImp->m_pVTable = _Other.m_Data.m_pImp->m_pVTable;
			}
			else
			{
				fp_Destroy();
				fp_SetDefault();
			}
		}

		FDelete *fp_DestroyCall() const
		{
			return m_Data.m_pImp->m_pVTable->m_pDestroy;
		}
		typename CFunctionDefinition::FDuplicate *fp_DuplicateCall() const
		{
			return m_Data.m_pImp->m_pVTable->m_pDuplicate;
		}
		typename CFunctionDefinition::FDuplicateMove *fp_DuplicateMoveCall() const
		{
			return m_Data.m_pImp->m_pVTable->m_pDuplicateMove;
		}

		template <mint t_iCall, typename t_CDummmy = void>
		struct TCCallRet
		{
			mark_artificial inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::CType *fs_Get(TCFunctionSmallBase const *_pThis) { return _pThis->m_Data.m_pImp->m_pVTable->template f_GetFunction<t_iCall>(); }
		};

		template <mint t_iCall>
		mark_artificial inline_always typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::CType *fp_Call() const
		{
			return TCCallRet<t_iCall>::fs_Get(this);
		}


		FCompareEqual *fp_CompareEqual() const
		{
			return (FCompareEqual *)m_Data.m_pImp->m_pVTable->m_pCompareEqual;
		}

		FCompareSpaceship *fp_CompareSpaceship() const
		{
			return (FCompareSpaceship *)m_Data.m_pImp->m_pVTable->m_pCompareSpaceship;
		}

	public:
	};

	template <typename t_CFOpts>
	class TCFunctionNoAllocBaseSeparateCall
	{
	public:
		using CFunctionOptions = t_CFOpts;

	private:
		template <typename t_CFunctor2, typename t_CFOpts2, bool t_bSupportEqualityCompare2, bool t_bSupportOrderedCompare2, bool t_bSupportCopy2, bool t_bSupportMove2>
		friend class TCImpl;

		typedef TCImpl<CNullFunctionImpl, t_CFOpts> CNullFunction;
		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
		typedef typename CFunctionDefinition::CVTable CVTable;
		typedef typename TCFunctionCallDefinition<typename t_CFOpts::CCall0>::CType CCallType0;
		typedef typename t_CFOpts::CAllocator CAllocator;

		typedef uint8 CStorage[t_CFOpts::CFunctionAllocOptions::mc_MaxSize];

		static CVTable const *fsp_VTable();
	protected:
		CCallType0 * m_pCall;
		CVTable const * m_pVTable;

		typename NTraits::TCAlign<CStorage, t_CFOpts::CFunctionAllocOptions::mc_Alignment>::CType m_Storage;

		TCFunctionNoAllocBaseSeparateCall()
			: m_pCall(&CNullFunction::CCallImp0::fs_Call)
			, m_pVTable(&CNullFunction::CVTable::mc_VTable)
		{
		}

		~TCFunctionNoAllocBaseSeparateCall()
		{
			//NMemory::fg_Free(m_pStorage);
		}

		bool fp_IsDefault() const
		{
			return m_pCall == &CNullFunction::CCallImp0::fs_Call;
		}

		void fp_SetDefault()
		{
			m_pCall = &CNullFunction::CCallImp0::fs_Call;
			m_pVTable = &CNullFunction::CVTable::mc_VTable;
		}

		void fp_Destroy()
		{
			if (m_pCall != &CNullFunction::CCallImp0::fs_Call)
			{
				fp_DestroyCall()(fp_GetImpl());
			}
		}

		template <bool t_bMove, typename t_CDummy = void>
		struct TCGetDuplicateSignature
		{
			typedef TCFunctionNoAllocBaseSeparateCall const & CType;
		};

		template <typename t_CDummy>
		struct TCGetDuplicateSignature<true, t_CDummy>
		{
			typedef TCFunctionNoAllocBaseSeparateCall && CType;
		};

		template <bool t_bMove>
		void fp_Duplicate(typename TCGetDuplicateSignature<t_bMove>::CType _Other)
		{
			if (_Other.m_pCall != &CNullFunction::CCallImp0::fs_Call)
			{
				fp_Destroy();
				fp_SetDefault();
				if constexpr (t_bMove)
					_Other.m_pVTable->m_pDuplicateMove((void *)_Other.fp_GetImpl(), *this);
				else
					_Other.m_pVTable->m_pDuplicate(_Other.fp_GetImpl(), *this);
				m_pCall = _Other.m_pCall;
				m_pVTable = _Other.m_pVTable;
			}
			else
			{
				fp_Destroy();
				fp_SetDefault();
			}
		}

		void fp_Move(TCFunctionNoAllocBaseSeparateCall &&_Other)
		{
			fp_Duplicate<true>(fg_Move(_Other));
			_Other.fp_Destroy();
			_Other.fp_SetDefault();
		}

		void fp_MoveAssign(TCFunctionNoAllocBaseSeparateCall &&_Other)
		{
			fp_Duplicate<true>(fg_Move(_Other));
			_Other.fp_Destroy();
			_Other.fp_SetDefault();
		}

		template <typename tf_CObject, typename tf_CParam>
		tf_CObject *fp_ConstructObject(tf_CParam &&_Param)
		{
			static_assert(sizeof(tf_CObject) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage (internal error)");
			return new(m_Storage.m_Aligned) tf_CObject(fg_Forward<tf_CParam>(_Param));
		}

		template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy = void>
		struct TCConstructInternal
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function)
			{
				typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType, CFunctionDefinition>::CType CImpl;
				static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
				static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

				new(_This.m_Storage.m_Aligned) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
				_This.m_pCall = CImpl::CCallImp0::fs_Call;
				_This.m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		};

		template <typename t_CDummy>
		struct TCConstructInternal<true, true, t_CDummy>
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function)
			{
				using CUniquePointer = typename TCChooseType
					<
						NTraits::TCIsSame<CAllocator, NMemory::CDefaultAllocator>::mc_Value
						, NStorage::TCUniquePointer<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType>::CType>
						, NStorage::TCUniquePointer
						<
							typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType>::CType
							, CAllocator
						>
					>::CType
				;
				typedef typename TCDetermineImpl<CUniquePointer, CFunctionDefinition>::CType CImpl;

				static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
				static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

				new(_This.m_Storage.m_Aligned) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
				_This.m_pCall = CImpl::CCallImp0::fs_Call;
				_This.m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		};

		template <typename t_CFunction>
		void fp_Construct(t_CFunction &&_Function)
		{
			typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<t_CFunction>::CType, CFunctionDefinition>::CType CImpl;
			TCConstructInternal
			<
				(sizeof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_MaxSize)
				|| (alignof(CImpl) > t_CFOpts::CFunctionAllocOptions::mc_Alignment)
				, t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc
			>::fs_Perform
			(
				*this, fg_Forward<t_CFunction>(_Function)
			);
		}

		template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy = void>
		struct TCAssignInternal
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function)
			{
				typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType, CFunctionDefinition>::CType CImpl;
				static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
				static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

				// Start by destroying in case of exception in constructor
				_This.fp_Destroy();
				_This.m_pCall = &CNullFunction::CCallImp0::fs_Call;
				_This.m_pVTable = &CNullFunction::CVTable::mc_VTable;

				new(_This.m_Storage.m_Aligned) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
				_This.m_pCall = CImpl::CCallImp0::fs_Call;
				_This.m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		};

		template <typename t_CDummy>
		struct TCAssignInternal<true, true, t_CDummy>
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function)
			{
				using CUniquePointer = typename TCChooseType
					<
						NTraits::TCIsSame<CAllocator, NMemory::CDefaultAllocator>::mc_Value
						, NStorage::TCUniquePointer<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType>::CType>
						, NStorage::TCUniquePointer
						<
							typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType>::CType
							, CAllocator
						>
					>::CType
				;
				typedef typename TCDetermineImpl<CUniquePointer, CFunctionDefinition>::CType CImpl;

				static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
				static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

				// Start by destroying in case of exception in constructor
				_This.fp_Destroy();
				_This.m_pCall = &CNullFunction::CCallImp0::fs_Call;
				_This.m_pVTable = &CNullFunction::CVTable::mc_VTable;

				new(_This.m_Storage.m_Aligned) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
				_This.m_pCall = CImpl::CCallImp0::fs_Call;
				_This.m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		};

		void const *fp_GetFirstFunctionPointer() const
		{
			return reinterpret_cast<void const *>(m_pCall);
		}

		template <typename t_CFunction>
		void fp_Assign(t_CFunction &&_Function)
		{
			typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<t_CFunction>::CType, CFunctionDefinition>::CType CImpl;
			TCAssignInternal
			<
				(sizeof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_MaxSize)
				|| (alignof(CImpl) > t_CFOpts::CFunctionAllocOptions::mc_Alignment)
				, t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc
			>::fs_Perform
			(
				*this, fg_Forward<t_CFunction>(_Function)
			);
		}


		only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetImpl()
		{
			return m_Storage.m_Aligned;
		}

		only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetImpl() const
		{
			return (uint8 *)m_Storage.m_Aligned;
		}

		inline_small CVTable const *fp_VTable() const
		{
			return m_pVTable;
		}
		FDelete *fp_DestroyCall() const
		{
			return m_pVTable->m_pDestroy;
		}
		typename CFunctionDefinition::FDuplicate *fp_DuplicateCall() const
		{
			return m_pVTable->m_pDuplicate;
		}
		typename CFunctionDefinition::FDuplicateMove *fp_DuplicateMoveCall() const
		{
			return m_pVTable->m_pDuplicateMove;
		}

		template <mint t_iCall, typename t_CDummmy = void>
		struct TCCallRet
		{
			mark_artificial inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::CType *fs_Get(TCFunctionNoAllocBaseSeparateCall const *_pThis) { return _pThis->m_pVTable->template f_GetFunction<t_iCall>(); }
		};

		template <typename t_CDummmy>
		struct TCCallRet<0, t_CDummmy>
		{
			mark_artificial inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, 0>::CType *fs_Get(TCFunctionNoAllocBaseSeparateCall const *_pThis) { return _pThis->m_pCall; }
		};

		template <mint t_iCall>
		mark_artificial inline_always typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::CType *fp_Call() const
		{
			return TCCallRet<t_iCall>::fs_Get(this);
		}

		FCompareEqual *fp_CompareEqual() const
		{
			return (FCompareEqual *)m_pVTable->m_pCompareEqual;
		}
		FCompareSpaceship *fp_CompareSpaceship() const
		{
			return (FCompareSpaceship *)m_pVTable->m_pCompareSpaceship;
		}
	};

	template <typename t_CFOpts>
	class TCFunctionNoAllocBase
	{
	public:
		using CFunctionOptions = t_CFOpts;

	private:
		template <typename t_CFunctor2, typename t_CFOpts2, bool t_bSupportEqualityCompare2, bool t_bSupportOrderedCompare2, bool t_bSupportCopy2, bool t_bSupportMove2>
		friend class TCImpl;

		typedef TCImpl<CNullFunctionImpl, t_CFOpts> CNullFunction;
		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;
		typedef typename CFunctionDefinition::CVTable CVTable;
		typedef typename TCFunctionCallDefinition<typename t_CFOpts::CCall0>::CType CCallType0;
		typedef typename t_CFOpts::CAllocator CAllocator;

		typedef uint8 CStorage[t_CFOpts::CFunctionAllocOptions::mc_MaxSize];

		static CVTable const *fsp_VTable();
	protected:
		CVTable const * m_pVTable;

		typename NTraits::TCAlign<CStorage, t_CFOpts::CFunctionAllocOptions::mc_Alignment>::CType m_Storage;

		TCFunctionNoAllocBase()
			: m_pVTable(&CNullFunction::CVTable::mc_VTable)
		{
		}

		~TCFunctionNoAllocBase()
		{
			//NMemory::fg_Free(m_pStorage);
		}

		bool fp_IsDefault() const
		{
			return m_pVTable == &CNullFunction::CVTable::mc_VTable;
		}

		void fp_SetDefault()
		{
			m_pVTable = &CNullFunction::CVTable::mc_VTable;
		}

		void fp_Destroy()
		{
			if (m_pVTable != &CNullFunction::CVTable::mc_VTable)
			{
				fp_DestroyCall()(fp_GetImpl());
			}
		}

		template <bool t_bMove, typename t_CDummy = void>
		struct TCGetDuplicateSignature
		{
			typedef TCFunctionNoAllocBase const & CType;
		};

		template <typename t_CDummy>
		struct TCGetDuplicateSignature<true, t_CDummy>
		{
			typedef TCFunctionNoAllocBase && CType;
		};

		template <bool t_bMove>
		void fp_Duplicate(typename TCGetDuplicateSignature<t_bMove>::CType _Other)
		{
			if (_Other.m_pVTable != &CNullFunction::CVTable::mc_VTable)
			{
				fp_Destroy();
				fp_SetDefault();
				if constexpr (t_bMove)
					_Other.m_pVTable->m_pDuplicateMove((void *)_Other.fp_GetImpl(), *this);
				else
					_Other.m_pVTable->m_pDuplicate(_Other.fp_GetImpl(), *this);
				m_pVTable = _Other.m_pVTable;
			}
			else
			{
				fp_Destroy();
				fp_SetDefault();
			}
		}

		void fp_Move(TCFunctionNoAllocBase &&_Other)
		{
			fp_Duplicate<true>(fg_Move(_Other));
			_Other.fp_Destroy();
			_Other.fp_SetDefault();
		}

		void fp_MoveAssign(TCFunctionNoAllocBase &&_Other)
		{
			fp_Duplicate<true>(fg_Move(_Other));
			_Other.fp_Destroy();
			_Other.fp_SetDefault();
		}

		template <typename tf_CObject, typename tf_CParam>
		tf_CObject *fp_ConstructObject(tf_CParam &&_Param)
		{
			static_assert(sizeof(tf_CObject) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage (internal error)");
			return new(m_Storage.m_Aligned) tf_CObject(fg_Forward<tf_CParam>(_Param));
		}

		template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy = void>
		struct TCConstructInternal
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function)
			{
				typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType, CFunctionDefinition>::CType CImpl;
				static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
				static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

				new(_This.m_Storage.m_Aligned) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
				_This.m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		};

		template <typename t_CDummy>
		struct TCConstructInternal<true, true, t_CDummy>
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function)
			{
				using CUniquePointer = typename TCChooseType
					<
						NTraits::TCIsSame<CAllocator, NMemory::CDefaultAllocator>::mc_Value
						, NStorage::TCUniquePointer<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType>::CType>
						, NStorage::TCUniquePointer
						<
							typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType>::CType
							, CAllocator
						>
					>::CType
				;
				typedef typename TCDetermineImpl<CUniquePointer, CFunctionDefinition>::CType CImpl;

				static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
				static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

				new(_This.m_Storage.m_Aligned) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
				_This.m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		};

		template <typename t_CFunction>
		void fp_Construct(t_CFunction &&_Function)
		{
			typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<t_CFunction>::CType, CFunctionDefinition>::CType CImpl;
			TCConstructInternal
			<
				(sizeof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_MaxSize)
				|| (alignof(CImpl) > t_CFOpts::CFunctionAllocOptions::mc_Alignment)
				, t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc
			>::fs_Perform
			(
				*this, fg_Forward<t_CFunction>(_Function)
			);
		}

		template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy = void>
		struct TCAssignInternal
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function)
			{
				typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType, CFunctionDefinition>::CType CImpl;
				static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
				static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

				// Start by destroying in case of exception in constructor
				_This.fp_Destroy();
				_This.m_pVTable = &CNullFunction::CVTable::mc_VTable;

				new(_This.m_Storage.m_Aligned) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
				_This.m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		};

		template <typename t_CDummy>
		struct TCAssignInternal<true, true, t_CDummy>
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function)
			{
				using CUniquePointer = typename TCChooseType
					<
						NTraits::TCIsSame<CAllocator, NMemory::CDefaultAllocator>::mc_Value
						, NStorage::TCUniquePointer<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType>::CType>
						, NStorage::TCUniquePointer
						<
							typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReferenceStorable<tf_CFunction>::CType>::CType
							, CAllocator
						>
					>::CType
				;
				typedef typename TCDetermineImpl<CUniquePointer, CFunctionDefinition>::CType CImpl;

				static_assert(sizeof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_MaxSize, "Functor does not fit in storage");
				static_assert(alignof(typename CImpl::CImplBase) <= t_CFOpts::CFunctionAllocOptions::mc_Alignment, "Functor cannot be correctly aligned");

				// Start by destroying in case of exception in constructor
				_This.fp_Destroy();
				_This.m_pVTable = &CNullFunction::CVTable::mc_VTable;

				new(_This.m_Storage.m_Aligned) typename CImpl::CImplBase(fg_Forward<tf_CFunction>(_Function));
				_This.m_pVTable = &CImpl::CVTable::mc_VTable;
			}
		};

		void const *fp_GetFirstFunctionPointer() const
		{
			return reinterpret_cast<void const *>(m_pVTable->m_pCalls[0]);
		}

		template <typename t_CFunction>
		void fp_Assign(t_CFunction &&_Function)
		{
			typedef typename TCDetermineImpl<typename NTraits::TCRemoveReferenceStorable<t_CFunction>::CType, CFunctionDefinition>::CType CImpl;
			TCAssignInternal
			<
				(sizeof(typename CImpl::CImplBase) > t_CFOpts::CFunctionAllocOptions::mc_MaxSize)
				|| (alignof(CImpl) > t_CFOpts::CFunctionAllocOptions::mc_Alignment)
				, t_CFOpts::CFunctionAllocOptions::mc_bAllowAlloc
			>::fs_Perform
			(
				*this, fg_Forward<t_CFunction>(_Function)
			);
		}

		only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetImpl()
		{
			return m_Storage.m_Aligned;
		}

		only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetImpl() const
		{
			return (uint8 *)m_Storage.m_Aligned;
		}

		inline_small CVTable const *fp_VTable() const
		{
			return m_pVTable;
		}
		FDelete *fp_DestroyCall() const
		{
			return m_pVTable->m_pDestroy;
		}
		typename CFunctionDefinition::FDuplicate *fp_DuplicateCall() const
		{
			return m_pVTable->m_pDuplicate;
		}
		typename CFunctionDefinition::FDuplicateMove *fp_DuplicateMoveCall() const
		{
			return m_pVTable->m_pDuplicateMove;
		}

		template <mint t_iCall>
		struct TCCallRet
		{
			mark_artificial inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::CType *fs_Get(TCFunctionNoAllocBase const *_pThis) { return _pThis->m_pVTable->template f_GetFunction<t_iCall>(); }
		};

		template <mint t_iCall>
		mark_artificial inline_always typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::CType *fp_Call() const
		{
			return TCCallRet<t_iCall>::fs_Get(this);
		}

		FCompareEqual *fp_CompareEqual() const
		{
			return (FCompareEqual *)m_pVTable->m_pCompareEqual;
		}
		FCompareSpaceship *fp_CompareSpaceship() const
		{
			return (FCompareSpaceship *)m_pVTable->m_pCompareSpaceship;
		}
	};

	template <mint t_iFunction, typename t_CBase, typename t_FFunc = typename TCGetCallInfo<typename t_CBase::CFunctionOptions::CFunctionList, t_iFunction>::CType, int _Qualifiers = TCGetCallInfo<typename t_CBase::CFunctionOptions::CFunctionList, t_iFunction>::mc_Qualifiers>
	class TCFunctionImplementation0;

	template <typename t_CBase, typename t_CReturn, typename... tp_CParams>
	class TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams...), EQualifiers_Const>
		: public t_CBase
	{
	public:
		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType... p_Params) const
		{
			return this->template fp_Call<0>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};

	template <typename t_CBase, typename t_CReturn, typename... tp_CParams>
	class TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams...), EQualifiers_None>
		: public t_CBase
	{
	public:
		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType... p_Params)
		{
			return this->template fp_Call<0>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};

	template <typename t_CBase, mint t_iFunction, typename t_CReturn, typename... tp_CParams>
	class TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams...), EQualifiers_Const>
		: public TCFunctionImplementation0<t_iFunction - 1, t_CBase>
	{
	public:
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::operator ();
		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType... p_Params) const
		{
			return this->template fp_Call<t_iFunction>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};

	template <typename t_CBase, mint t_iFunction, typename t_CReturn, typename... tp_CParams>
	class TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams...), EQualifiers_None>
		: public TCFunctionImplementation0<t_iFunction - 1, t_CBase>
	{
	public:
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::operator ();
		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType... p_Params)
		{
			return this->template fp_Call<t_iFunction>()(this->fp_GetImpl(), TCGetReferenceType<tp_CParams>::fs_Forward(p_Params)...);
		}
	};

	template
	<
		typename t_CFOpts
		, bool t_bSupportEqualityCompare = t_CFOpts::mc_bSupportEqualityCompare
		, bool t_bSupportOrderedCompare = t_CFOpts::mc_bSupportOrderedCompare
	>
	class TCFunctionImplementation : public TCFunctionImplementation0<t_CFOpts::mc_NumFunctions-1, typename t_CFOpts::CImpBase>
	{
		//
		typedef TCFunctionImplementation0<t_CFOpts::mc_NumFunctions-1, typename t_CFOpts::CImpBase> CSuper;
		typedef TCImpl<CNullFunctionImpl, t_CFOpts> CNullFunction;

		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;

		typedef typename CFunctionDefinition::CVTable CVTable;
	public:

		/// The options available for the function
		typedef t_CFOpts CFunctionOptions;

		using CSuper::operator ();

		~TCFunctionImplementation()
		{
			this->fp_Destroy();
		}

		TCFunctionImplementation()
		{
		}

		TCFunctionImplementation(TCFunctionImplementation const &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
		}


		TCFunctionImplementation &operator = (TCFunctionImplementation const &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
			return *this;
		}

		TCFunctionImplementation(TCFunctionImplementation &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
			return *this;
		}

		TCFunctionImplementation(TCFunctionImplementation &&_Other)
		{
			this->fp_Move(fg_Move(_Other));
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation &&_Other)
		{
			this->fp_MoveAssign(fg_Move(_Other));
			return *this;
		}

		template <typename t_CFunction>
		TCFunctionImplementation(t_CFunction &&_Function)
		{
			this->fp_Construct(fg_Forward<t_CFunction>(_Function));
		}

		template <typename t_CFunction>
		TCFunctionImplementation &operator = (t_CFunction &&_Function)
		{
			this->fp_Assign(fg_Forward<t_CFunction>(_Function));
			return *this;
		}


		/**	\brief Clears the function object and destroys any contained functor.

			If function ojbect is called after this an exception CExceptionBadFunctionCall will be thrown.
		*/
		void f_Clear()
		{
			this->fp_Destroy();
			this->fp_SetDefault();
		}

		void const *f_GetFirstFunctionPointer() const
		{
			return this->fp_GetFirstFunctionPointer();
		}

		TCFunctionImplementation(CNullPtr)
		{
		}

		/// Clears the function object same as if f_Clear was called
		TCFunctionImplementation &operator = (CNullPtr)
		{
			f_Clear();
			return *this;
		}

		/// Checks if a functor is stored in the function object. If not true is returned
		inline_small bool f_IsEmpty() const
		{
			return this->fp_IsDefault();
		}

		/// Checks if a functor is stored in the function object. If a functiored is stored true is returned, otherwise false.
		inline_small explicit operator bool() const
		{
			return !this->fp_IsDefault();
		}
	};

	template <typename t_CFOpts>
	class TCFunctionImplementation<t_CFOpts, true, true> : public TCFunctionImplementation0<t_CFOpts::mc_NumFunctions-1, typename t_CFOpts::CImpBase>
	{
		//
		typedef TCFunctionImplementation0<t_CFOpts::mc_NumFunctions-1, typename t_CFOpts::CImpBase> CSuper;
		typedef TCImpl<CNullFunctionImpl, t_CFOpts> CNullFunction;

		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;

		typedef typename CFunctionDefinition::CVTable CVTable;

	public:
		typedef t_CFOpts CFunctionOptions;

		using CSuper::operator ();

		~TCFunctionImplementation()
		{
			this->fp_Destroy();
		}

		TCFunctionImplementation()
		{
		}

		TCFunctionImplementation(TCFunctionImplementation const &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation const &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
			return *this;
		}

		TCFunctionImplementation(TCFunctionImplementation &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
			return *this;
		}

		TCFunctionImplementation(TCFunctionImplementation &&_Other)
		{
			this->fp_Move(fg_Move(_Other));
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation &&_Other)
		{
			this->fp_MoveAssign(fg_Move(_Other));
			return *this;
		}

		template <typename t_CFunction>
		TCFunctionImplementation(t_CFunction &&_Function)
		{
			this->fp_Construct(fg_Forward<t_CFunction>(_Function));
		}

		template <typename t_CFunction>
		TCFunctionImplementation &operator = (t_CFunction &&_Function)
		{
			this->fp_Assign(fg_Forward<t_CFunction>(_Function));
			return *this;
		}

		void f_Clear()
		{
			this->fp_Destroy();
			this->fp_SetDefault();
		}

		TCFunctionImplementation(CNullPtr)
		{

		}
		TCFunctionImplementation &operator = (CNullPtr)
		{
			f_Clear();
			return *this;
		}

		inline_small bool f_IsEmpty() const
		{
			return this->fp_IsDefault();
		}

		inline_small explicit operator bool() const
		{
			return !this->fp_IsDefault();
		}

		bool operator == (TCFunctionImplementation const &_Other) const
		{
			if (this->fp_VTable() != _Other.fp_VTable())
				return false;
			return this->fp_CompareEqual()(this->fp_GetImpl(), _Other.fp_GetImpl());
		}
		
		COrdering_Partial operator <=> (TCFunctionImplementation const &_Other) const
		{
			if (auto Result = this->fp_VTable() <=> _Other.fp_VTable(); Result != 0)
				return Result;

			return this->fp_CompareSpaceship()(this->fp_GetImpl(), _Other.fp_GetImpl());
		}
	};

	template <typename t_CFOpts>
	class TCFunctionImplementation<t_CFOpts, false, true> : public TCFunctionImplementation0<t_CFOpts::mc_NumFunctions-1, typename t_CFOpts::CImpBase>
	{
		//
		typedef TCFunctionImplementation0<t_CFOpts::mc_NumFunctions-1, typename t_CFOpts::CImpBase> CSuper;
		typedef TCImpl<CNullFunctionImpl, t_CFOpts> CNullFunction;

		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;

		typedef typename CFunctionDefinition::CVTable CVTable;

	public:
		typedef t_CFOpts CFunctionOptions;

		using CSuper::operator ();

		~TCFunctionImplementation()
		{
			this->fp_Destroy();
		}

		TCFunctionImplementation()
		{
		}

		TCFunctionImplementation(TCFunctionImplementation const &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation const &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
			return *this;
		}

		TCFunctionImplementation(TCFunctionImplementation &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
			return *this;
		}

		TCFunctionImplementation(TCFunctionImplementation &&_Other)
		{
			this->fp_Move(fg_Move(_Other));
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation &&_Other)
		{
			this->fp_MoveAssign(fg_Move(_Other));
			return *this;
		}

		template <typename t_CFunction>
		TCFunctionImplementation(t_CFunction &&_Function)
		{
			this->fp_Construct(fg_Forward<t_CFunction>(_Function));
		}

		template <typename t_CFunction>
		TCFunctionImplementation &operator = (t_CFunction &&_Function)
		{
			this->fp_Assign(fg_Forward<t_CFunction>(_Function));
			return *this;
		}

		void f_Clear()
		{
			this->fp_Destroy();
			this->fp_SetDefault();
		}

		TCFunctionImplementation(CNullPtr)
		{

		}
		TCFunctionImplementation &operator = (CNullPtr)
		{
			f_Clear();
			return *this;
		}

		inline_small bool f_IsEmpty() const
		{
			return this->fp_IsDefault();
		}

		inline_small explicit operator bool() const
		{
			return !this->fp_IsDefault();
		}

		COrdering_Partial operator <=> (TCFunctionImplementation const &_Other) const
		{
			if (auto Result = this->fp_VTable() <=> _Other.fp_VTable(); Result != 0)
				return Result;

			return this->fp_CompareSpaceship()(this->fp_GetImpl(), _Other.fp_GetImpl());
		}
	};

	template <typename t_CFOpts>
	class TCFunctionImplementation<t_CFOpts, true, false> : public TCFunctionImplementation0<t_CFOpts::mc_NumFunctions-1, typename t_CFOpts::CImpBase>
	{
		//
		typedef TCFunctionImplementation0<t_CFOpts::mc_NumFunctions-1, typename t_CFOpts::CImpBase> CSuper;
		typedef TCImpl<CNullFunctionImpl, t_CFOpts> CNullFunction;

		typedef TCFunctionDefinitions<t_CFOpts> CFunctionDefinition;

		typedef typename CFunctionDefinition::CVTable CVTable;

	public:
		typedef t_CFOpts CFunctionOptions;

		using CSuper::operator ();

		~TCFunctionImplementation()
		{
			this->fp_Destroy();
		}

		TCFunctionImplementation()
		{
		}

		TCFunctionImplementation(TCFunctionImplementation const &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation const &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
			return *this;
		}

		TCFunctionImplementation(TCFunctionImplementation &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation &_Other)
		{
			this->template fp_Duplicate<false>(_Other);
			return *this;
		}

		TCFunctionImplementation(TCFunctionImplementation &&_Other)
		{
			this->fp_Move(fg_Move(_Other));
		}

		TCFunctionImplementation &operator = (TCFunctionImplementation &&_Other)
		{
			this->fp_MoveAssign(fg_Move(_Other));
			return *this;
		}

		template <typename t_CFunction>
		TCFunctionImplementation(t_CFunction &&_Function)
		{
			this->fp_Construct(fg_Forward<t_CFunction>(_Function));
		}

		template <typename t_CFunction>
		TCFunctionImplementation &operator = (t_CFunction &&_Function)
		{
			this->fp_Assign(fg_Forward<t_CFunction>(_Function));
			return *this;
		}

		void f_Clear()
		{
			this->fp_Destroy();
			this->fp_SetDefault();
		}

		TCFunctionImplementation(CNullPtr)
		{

		}
		TCFunctionImplementation &operator = (CNullPtr)
		{
			f_Clear();
			return *this;
		}

		inline_small bool f_IsEmpty() const
		{
			return this->fp_IsDefault();
		}

		inline_small explicit operator bool() const
		{
			return !this->fp_IsDefault();
		}

		bool operator == (TCFunctionImplementation const &_Other) const
		{
			if (this->fp_VTable() != _Other.fp_VTable())
				return false;
			return this->fp_CompareEqual()(this->fp_GetImpl(), _Other.fp_GetImpl());
		}
	};
}
