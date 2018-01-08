// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

namespace NMib
{
	namespace NFunction
	{
		namespace NPrivate
		{

			template 
				<
					typename t_CFunctor
					, typename t_CFOpts
					, bint t_bSupportCompare = t_CFOpts::mc_bSupportCompare
					, bint t_bSupportCopy = t_CFOpts::mc_bSupportCopy
					, bint t_bSupportMove = t_CFOpts::mc_bSupportMove
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
			class TCImpl<t_CFunctor, t_CFOpts, true, true, true>
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
				static bint fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
				{
					return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
				}
				static bint fs_CompareLess(void const *_pImpl0, void const *_pImpl1)
				{
					return ((CImplBase const *)_pImpl0)->m_Functor < ((CImplBase const *)_pImpl1)->m_Functor;
				}
			};

			template <typename t_CFunctor, typename t_CFOpts>
			class TCImpl<t_CFunctor, t_CFOpts, false, false, true>
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
				static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
				{
					DMibFastCheck(0);
					return nullptr;
				}
				static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
				{
					return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
				}
			};

			template <typename t_CFunctor, typename t_CFOpts>
			class TCImpl<t_CFunctor, t_CFOpts, true, false, true>
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
				static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
				{
					DMibFastCheck(0);
					return nullptr;
				}
				static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
				{
					return _Allocator.template fp_ConstructObject<CImplBase>(fg_Move(*((CImplBase *)_pImpl)));
				}
				static bint fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
				{
					return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
				}
				static bint fs_CompareLess(void const *_pImpl0, void const *_pImpl1)
				{
					return ((CImplBase const *)_pImpl0)->m_Functor < ((CImplBase const *)_pImpl1)->m_Functor;
				}
			};

			template <typename t_CFunctor, typename t_CFOpts>
			class TCImpl<t_CFunctor, t_CFOpts, false, true, false>
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
				static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
				{
					DMibFastCheck(0);
					return nullptr;
				}
			};

			template <typename t_CFunctor, typename t_CFOpts>
			class TCImpl<t_CFunctor, t_CFOpts, true, true, false>
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
				static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
				{
					DMibFastCheck(0);
					return nullptr;
				}
				static bint fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
				{
					return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
				}
				static bint fs_CompareLess(void const *_pImpl0, void const *_pImpl1)
				{
					return ((CImplBase const *)_pImpl0)->m_Functor < ((CImplBase const *)_pImpl1)->m_Functor;
				}
			};


			template <typename t_CFunctor, typename t_CFOpts>
			class TCImpl<t_CFunctor, t_CFOpts, false, false, false>
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
				static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
				{
					DMibFastCheck(0);
					return nullptr;
				}
				static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
				{
					DMibFastCheck(0);
					return nullptr;
				}
			};

			template <typename t_CFunctor, typename t_CFOpts>
			class TCImpl<t_CFunctor, t_CFOpts, true, false, false>
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
				static only_parameters_aliased return_not_aliased void *fs_Duplicate(void const *_pImpl, CAllocator &_Allocator)
				{
					DMibFastCheck(0);
					return nullptr;
				}
				static only_parameters_aliased return_not_aliased void *fs_DuplicateMove(void *_pImpl, CAllocator &_Allocator)
				{
					DMibFastCheck(0);
					return nullptr;
				}
				static bint fs_CompareEqual(void const *_pImpl0, void const *_pImpl1)
				{
					return ((CImplBase const *)_pImpl0)->m_Functor == ((CImplBase const *)_pImpl1)->m_Functor;
				}
				static bint fs_CompareLess(void const *_pImpl0, void const *_pImpl1)
				{
					return ((CImplBase const *)_pImpl0)->m_Functor < ((CImplBase const *)_pImpl1)->m_Functor;
				}
			};

			template <typename t_CFunctor, typename t_CFunctionDefinition>
			struct TCDetermineImpl
			{
				typedef NPrivate::TCImpl
				<
					t_CFunctor
					, typename t_CFunctionDefinition::CFunctionOptions
				> CType;
			};

			template <typename t_CFunctor, typename t_CFOpts, mint... tp_Indicies>
			typename TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, false>::CVTable 
			TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, false>::ms_VTable 
			= 
			{
				{
					(void *)&TCImpl<t_CFunctor, t_CFOpts>::template TCGetCallImp<tp_Indicies>::CType::fs_Call...
				}
				, NTraits::TCAlignmentOf<typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase>::mc_Value
				, sizeof(typename TCImpl<t_CFunctor, t_CFOpts>::CImplBase)
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Destroy
				, TCImpl<t_CFunctor, t_CFOpts>::fs_Duplicate
				, TCImpl<t_CFunctor, t_CFOpts>::fs_DuplicateMove
			};

			template <typename t_CFunctor, typename t_CFOpts, mint... tp_Indicies>
			typename TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, true>::CVTable 
			TCImplVTable<t_CFunctor, t_CFOpts, NMeta::TCIndices<tp_Indicies...>, true>::ms_VTable 
			= 
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
				, TCImpl<t_CFunctor, t_CFOpts>::fs_CompareLess
			};
		}
	}
}

