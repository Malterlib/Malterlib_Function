// Copyright © Unbroken AB
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once

#include <Mib/Storage/BitStorePointer>

namespace NMib::NFunction::NPrivate
{
	template <typename t_CFOpts>
	struct TCFunctionBase
	{
		using CFunctionOptions = t_CFOpts;

	private:
		template <typename t_CFunctor2, typename t_CFOpts2, bool t_bSupportEqualityCompare2, bool t_bSupportOrderedCompare2, bool t_bSupportCopy2, bool t_bSupportMove2>
		friend struct TCImpl;

		using CNullFunction = TCImpl<TCNullFunctionImpl<CFunctionOptions::mc_bNoExcept>, t_CFOpts>;
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;
		using FCallType0 = typename TCFunctionCallDefinition<typename t_CFOpts::FCall0>::FType;
		using CAllocator = typename t_CFOpts::CAllocator;

	protected:
		struct CData : public CAllocator
		{
			template <typename ...tfp_CParams>
			CData(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params);

			CData();
			CData(CData &&_Other);
			CData(CData const &_Other);

			void *m_pImpl;
			FCallType0 *m_pCall;
			CVTable const *m_pVTable;
			CData &operator = (CData &&_Other);
			CData &operator = (CData const &_Other);
		};

		CData mp_Data;

		template <typename ...tfp_CParams>
		TCFunctionBase(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params);

		TCFunctionBase() = default;
		TCFunctionBase(TCFunctionBase const &_Other) = default;
		TCFunctionBase(TCFunctionBase &&_Other) = default;

		bool fp_IsDefault() const;
		void fp_SetDefault();
		void fp_Move(TCFunctionBase &&_Other);
		void fp_MoveAssign(TCFunctionBase &&_Other);

		template <typename tf_CObject, typename tf_CParam>
		tf_CObject *fp_ConstructObject(tf_CParam &&_Param);

		template <typename tf_CFunction>
		void fp_Construct(tf_CFunction &&_Function);

		void const *fp_GetFirstFunctionPointer() const;

		template <typename tf_CFunction>
		void fp_Assign(tf_CFunction &&_Function);

		template <bool t_bMove, typename t_CDummy = void>
		struct TCGetDuplicateSignature
		{
			using CType = TCFunctionBase const &;
		};

		template <typename t_CDummy>
		struct TCGetDuplicateSignature<true, t_CDummy>
		{
			using CType = TCFunctionBase &&;
		};

		template <bool tf_bMove>
		void fp_Duplicate(typename TCGetDuplicateSignature<tf_bMove>::CType _Other);

		mark_nodebug only_parameters_aliased return_not_aliased inline_small void *fp_GetImpl();
		mark_nodebug only_parameters_aliased return_not_aliased inline_small void *fp_GetImpl() const;
		mark_nodebug only_parameters_aliased return_not_aliased inline_small void *fp_GetFunctor() const;
		mark_nodebug only_parameters_aliased return_not_aliased inline_small void *fp_GetFunctorUnsafe() const;
		mark_nodebug inline_small CVTable const *fp_VTable() const;
		mark_nodebug FDelete *fp_DestroyCall() const;
		typename CFunctionDefinition::FDuplicate *fp_DuplicateCall() const;
		typename CFunctionDefinition::FDuplicateMove *fp_DuplicateMoveCall() const;

		template <umint t_iCall, typename t_CDummmy = void>
		struct TCCallRet
		{
			mark_artificial mark_nodebug inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::FType *fs_Get(TCFunctionBase const *_pThis);
		};

		template <typename t_CDummmy>
		struct TCCallRet<0, t_CDummmy>
		{
			mark_artificial mark_nodebug inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, 0>::FType *fs_Get(TCFunctionBase const *_pThis);
		};

		template <umint tf_iCall>
		inline_always typename TCGetFunctionCallDefinition<t_CFOpts, tf_iCall>::FType *fp_Call() const;

		FCompareEqual *fp_CompareEqual() const noexcept;
		FCompareSpaceship *fp_CompareSpaceship() const noexcept;
		void fp_Destroy();
	};

	template <typename t_CFOpts>
	struct TCFunctionSmallBase
	{
		using CFunctionOptions = t_CFOpts;

	private:
		template <typename t_CFunctor2, typename t_CFOpts2, bool t_bSupportEqualityCompare2, bool t_bSupportOrderedCompare2, bool t_bSupportCopy2, bool t_bSupportMove2>
		friend struct TCImpl;

	public:
		using CNullFunction = TCImpl<TCNullFunctionImpl<CFunctionOptions::mc_bNoExcept>, t_CFOpts>;

	private:
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;
		using CAllocator = typename t_CFOpts::CAllocator;

	protected:
		struct CImplementationData
		{
			CVTable const *m_pVTable;
		};

		static constexpr CImplementationData mcp_NullImplementation =
			{
				&TCFunctionSmallBase<t_CFOpts>::CNullFunction::CVTable::mc_VTable
			}
		;
		struct CData : public CAllocator
		{
			template <typename ...tfp_CParams>
			CData(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params);

			CData();
			CData(CData &&_Other);
			CData(CData const &_Other);

			CImplementationData *m_pImp;
			CData &operator = (CData &&_Other);
			CData &operator = (CData const &_Other);
		};

		CData mp_Data;

		template <typename ...tfp_CParams>
		TCFunctionSmallBase(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params);

		TCFunctionSmallBase() = default;
		TCFunctionSmallBase(TCFunctionSmallBase const &_Other) = default;
		TCFunctionSmallBase(TCFunctionSmallBase &&_Other) = default;

		bool fp_IsDefault() const;
		void fp_SetDefault();
		mark_nodebug only_parameters_aliased return_not_aliased inline_small void *fp_GetImpl();
		mark_nodebug only_parameters_aliased return_not_aliased inline_small void *fp_GetImpl() const;
		mark_nodebug only_parameters_aliased return_not_aliased inline_small void *fp_GetFunctor() const;
		mark_nodebug only_parameters_aliased return_not_aliased inline_small void *fp_GetFunctorUnsafe() const;
		mark_nodebug inline_small CVTable const *fp_VTable() const;
		void fp_Destroy();
		void fp_Move(TCFunctionSmallBase &&_Other);
		void fp_MoveAssign(TCFunctionSmallBase &&_Other);

		template <typename t_CFunctor>
		struct TCConstructObject : public CImplementationData
		{
			t_CFunctor m_Functor;
			template <typename tf_CFunction>
			TCConstructObject(tf_CFunction &&_Function);
		};

		template <typename tf_CObject, typename tf_CParam>
		void *fp_ConstructObject(tf_CParam &&_Param);

		template <typename tf_CFunction>
		void fp_Construct(tf_CFunction &&_Function);

		void const *fp_GetFirstFunctionPointer() const;

		template <typename tf_CFunction>
		void fp_Assign(tf_CFunction &&_Function);

		template <bool t_bMove, typename t_CDummy = void>
		struct TCGetDuplicateSignature
		{
			using CType = TCFunctionSmallBase const &;
		};

		template <typename t_CDummy>
		struct TCGetDuplicateSignature<true, t_CDummy>
		{
			using CType = TCFunctionSmallBase &&;
		};

		template <bool tf_bMove>
		void fp_Duplicate(typename TCGetDuplicateSignature<tf_bMove>::CType _Other);

		mark_nodebug FDelete *fp_DestroyCall() const;
		typename CFunctionDefinition::FDuplicate *fp_DuplicateCall() const;
		typename CFunctionDefinition::FDuplicateMove *fp_DuplicateMoveCall() const;

		template <umint t_iCall, typename t_CDummmy = void>
		struct TCCallRet
		{
			mark_artificial mark_nodebug inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::FType *fs_Get(TCFunctionSmallBase const *_pThis);
		};

		template <umint tf_iCall>
		mark_artificial mark_nodebug inline_always typename TCGetFunctionCallDefinition<t_CFOpts, tf_iCall>::FType *fp_Call() const;

		FCompareEqual *fp_CompareEqual() const noexcept;
		FCompareSpaceship *fp_CompareSpaceship() const noexcept;

	public:
	};

	template <typename t_CFOpts>
	struct TCFunctionNoAllocBaseSeparateCall
	{
		using CFunctionOptions = t_CFOpts;

	private:
		template <typename t_CFunctor2, typename t_CFOpts2, bool t_bSupportEqualityCompare2, bool t_bSupportOrderedCompare2, bool t_bSupportCopy2, bool t_bSupportMove2>
		friend struct TCImpl;

		using CNullFunction = TCImpl<TCNullFunctionImpl<CFunctionOptions::mc_bNoExcept>, t_CFOpts>;
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;
		using FCallType0 = typename TCFunctionCallDefinition<typename t_CFOpts::FCall0>::FType;
		using CAllocator = typename t_CFOpts::CAllocator;

	protected:
		FCallType0 *mp_pCall;
		NStorage::TCBitStorePointer<CVTable const, 2> mp_pVTable;

		alignas(t_CFOpts::CFunctionAllocOptions::mc_Alignment) uint8 mp_Storage[t_CFOpts::CFunctionAllocOptions::mc_MaxSize];

		TCFunctionNoAllocBaseSeparateCall();
		TCFunctionNoAllocBaseSeparateCall(TCFunctionNoAllocBaseSeparateCall const &_Other);
		TCFunctionNoAllocBaseSeparateCall(TCFunctionNoAllocBaseSeparateCall &&_Other);
		~TCFunctionNoAllocBaseSeparateCall();
		bool fp_IsDefault() const;
		void fp_SetDefault();
		void fp_Destroy();

		template <bool t_bMove, typename t_CDummy = void>
		struct TCGetDuplicateSignature
		{
			using CType = TCFunctionNoAllocBaseSeparateCall const &;
		};

		template <typename t_CDummy>
		struct TCGetDuplicateSignature<true, t_CDummy>
		{
			using CType = TCFunctionNoAllocBaseSeparateCall &&;
		};

		template <bool tf_bMove>
		void fp_Duplicate(typename TCGetDuplicateSignature<tf_bMove>::CType _Other);

		void fp_Move(TCFunctionNoAllocBaseSeparateCall &&_Other);
		void fp_MoveAssign(TCFunctionNoAllocBaseSeparateCall &&_Other);

		template <typename tf_CObject, typename tf_CParam>
		tf_CObject *fp_ConstructObject(tf_CParam &&_Param);

		template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy = void>
		struct TCConstructInternal
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function);
		};

		template <typename t_CDummy>
		struct TCConstructInternal<true, true, t_CDummy>
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function);
		};

		template <typename tf_CFunction>
		void fp_Construct(tf_CFunction &&_Function);

		template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy = void>
		struct TCAssignInternal
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function);
		};

		template <typename t_CDummy>
		struct TCAssignInternal<true, true, t_CDummy>
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBaseSeparateCall &_This, tf_CFunction &&_Function);
		};

		void const *fp_GetFirstFunctionPointer() const;

		template <typename tf_CFunction>
		void fp_Assign(tf_CFunction &&_Function);

		mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetImpl();
		mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetImpl() const;
		mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetFunctor() const;
		mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetFunctorUnsafe() const;
		mark_nodebug inline_small CVTable const *fp_VTable() const;
		mark_nodebug FDelete *fp_DestroyCall() const;
		typename CFunctionDefinition::FDuplicate *fp_DuplicateCall() const;
		typename CFunctionDefinition::FDuplicateMove *fp_DuplicateMoveCall() const;

		template <umint t_iCall, typename t_CDummmy = void>
		struct TCCallRet
		{
			mark_artificial mark_nodebug inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::FType *fs_Get(TCFunctionNoAllocBaseSeparateCall const *_pThis);
		};

		template <typename t_CDummmy>
		struct TCCallRet<0, t_CDummmy>
		{
			mark_artificial mark_nodebug inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, 0>::FType *fs_Get(TCFunctionNoAllocBaseSeparateCall const *_pThis);
		};

		template <umint tf_iCall>
		mark_artificial mark_nodebug inline_always typename TCGetFunctionCallDefinition<t_CFOpts, tf_iCall>::FType *fp_Call() const;

		FCompareEqual *fp_CompareEqual() const noexcept;
		FCompareSpaceship *fp_CompareSpaceship() const noexcept;
	};

	template <typename t_CFOpts>
	struct TCFunctionNoAllocBase
	{
		using CFunctionOptions = t_CFOpts;

	private:
		template <typename t_CFunctor2, typename t_CFOpts2, bool t_bSupportEqualityCompare2, bool t_bSupportOrderedCompare2, bool t_bSupportCopy2, bool t_bSupportMove2>
		friend struct TCImpl;

		using CNullFunction = TCImpl<TCNullFunctionImpl<CFunctionOptions::mc_bNoExcept>, t_CFOpts>;
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;
		using FCallType0 = typename TCFunctionCallDefinition<typename t_CFOpts::FCall0>::FType;
		using CAllocator = typename t_CFOpts::CAllocator;

	protected:
		NStorage::TCBitStorePointer<CVTable const, 2> mp_pVTable;

		alignas(t_CFOpts::CFunctionAllocOptions::mc_Alignment) uint8 mp_Storage[t_CFOpts::CFunctionAllocOptions::mc_MaxSize];

		TCFunctionNoAllocBase();
		TCFunctionNoAllocBase(TCFunctionNoAllocBase const &_Other);
		TCFunctionNoAllocBase(TCFunctionNoAllocBase &&_Other);
		~TCFunctionNoAllocBase();
		bool fp_IsDefault() const;
		void fp_SetDefault();
		void fp_Destroy();

		template <bool t_bMove, typename t_CDummy = void>
		struct TCGetDuplicateSignature
		{
			using CType = TCFunctionNoAllocBase const &;
		};

		template <typename t_CDummy>
		struct TCGetDuplicateSignature<true, t_CDummy>
		{
			using CType = TCFunctionNoAllocBase &&;
		};

		template <bool tf_bMove>
		void fp_Duplicate(typename TCGetDuplicateSignature<tf_bMove>::CType _Other);

		void fp_Move(TCFunctionNoAllocBase &&_Other);
		void fp_MoveAssign(TCFunctionNoAllocBase &&_Other);

		template <typename tf_CObject, typename tf_CParam>
		tf_CObject *fp_ConstructObject(tf_CParam &&_Param);

		template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy = void>
		struct TCConstructInternal
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function);
		};

		template <typename t_CDummy>
		struct TCConstructInternal<true, true, t_CDummy>
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function);
		};

		template <typename tf_CFunction>
		void fp_Construct(tf_CFunction &&_Function);

		template <bool t_bMustAlloc, bool t_bAllowAlloc, typename t_CDummy = void>
		struct TCAssignInternal
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function);
		};

		template <typename t_CDummy>
		struct TCAssignInternal<true, true, t_CDummy>
		{
			template <typename tf_CFunction>
			static void fs_Perform(TCFunctionNoAllocBase &_This, tf_CFunction &&_Function);
		};

		void const *fp_GetFirstFunctionPointer() const;

		template <typename tf_CFunction>
		void fp_Assign(tf_CFunction &&_Function);

		mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetImpl();
		mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetImpl() const;
		mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetFunctor() const;
		mark_nodebug only_parameters_aliased return_not_aliased inline_small uint8 *fp_GetFunctorUnsafe() const;
		mark_nodebug inline_small CVTable const *fp_VTable() const;
		mark_nodebug FDelete *fp_DestroyCall() const;
		typename CFunctionDefinition::FDuplicate *fp_DuplicateCall() const;
		typename CFunctionDefinition::FDuplicateMove *fp_DuplicateMoveCall() const;

		template <umint t_iCall>
		struct TCCallRet
		{
			mark_artificial mark_nodebug inline_always static typename TCGetFunctionCallDefinition<t_CFOpts, t_iCall>::FType *fs_Get(TCFunctionNoAllocBase const *_pThis);
		};

		template <umint tf_iCall>
		mark_artificial mark_nodebug inline_always typename TCGetFunctionCallDefinition<t_CFOpts, tf_iCall>::FType *fp_Call() const;

		FCompareEqual *fp_CompareEqual() const noexcept;
		FCompareSpaceship *fp_CompareSpaceship() const noexcept;
	};

	template
	<
		umint t_iFunction
		, typename t_CBase
		, typename t_FFunc = typename TCGetCallInfo<typename t_CBase::CFunctionOptions::CFunctionList, t_iFunction>::FType
		, int t_Qualifiers = TCGetCallInfo<typename t_CBase::CFunctionOptions::CFunctionList, t_iFunction>::mc_Qualifiers
	>
	struct TCFunctionImplementation0;

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	struct TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_Const>
		: public t_CBase
	{
		using t_CBase::t_CBase;

		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) const;
	};

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	struct TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_None>
		: public t_CBase
	{
		using t_CBase::t_CBase;

		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params);
	};

	template <typename t_CBase, umint t_iFunction, typename t_CReturn, typename ...tp_CParams>
	struct TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_Const>
		: public TCFunctionImplementation0<t_iFunction - 1, t_CBase>
	{
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::TCFunctionImplementation0;
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::operator ();

		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) const;
	};

	template <typename t_CBase, umint t_iFunction, typename t_CReturn, typename ...tp_CParams>
	struct TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams ...p_Params), EQualifiers_None>
		: public TCFunctionImplementation0<t_iFunction - 1, t_CBase>
	{
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::TCFunctionImplementation0;
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::operator ();

		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params);
	};

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	struct TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_Const>
		: public t_CBase
	{
		using t_CBase::t_CBase;

		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) const noexcept;
	};

	template <typename t_CBase, typename t_CReturn, typename ...tp_CParams>
	struct TCFunctionImplementation0<0, t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_None>
		: public t_CBase
	{
		using t_CBase::t_CBase;

		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) noexcept;
	};

	template <typename t_CBase, umint t_iFunction, typename t_CReturn, typename ...tp_CParams>
	struct TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_Const>
		: public TCFunctionImplementation0<t_iFunction - 1, t_CBase>
	{
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::TCFunctionImplementation0;
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::operator ();

		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) const noexcept;
	};

	template <typename t_CBase, umint t_iFunction, typename t_CReturn, typename ...tp_CParams>
	struct TCFunctionImplementation0<t_iFunction, t_CBase, t_CReturn (tp_CParams ...p_Params) noexcept, EQualifiers_None>
		: public TCFunctionImplementation0<t_iFunction - 1, t_CBase>
	{
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::TCFunctionImplementation0;
		using TCFunctionImplementation0<t_iFunction - 1, t_CBase>::operator ();

		mark_artificial inline_always t_CReturn operator () (typename TCGetReferenceType<tp_CParams>::CType ...p_Params) noexcept;
	};

	template <typename t_CFOpts, bool t_bSupportEqualityCompare = t_CFOpts::mc_bSupportEqualityCompare, bool t_bSupportOrderedCompare = t_CFOpts::mc_bSupportOrderedCompare>
	struct TCFunctionImplementation : public TCFunctionImplementation0<t_CFOpts::mc_NumFunctions - 1, typename t_CFOpts::CImpBase>
	{
	private:
		// Declared before the public section, which uses it.
		using CSuper = TCFunctionImplementation0<t_CFOpts::mc_NumFunctions - 1, typename t_CFOpts::CImpBase>;

	public:
		/// The options available for the function
		using CFunctionOptions = t_CFOpts;

		using CSuper::operator ();

		~TCFunctionImplementation();
		TCFunctionImplementation();

		template <typename ...tfp_CParams>
		TCFunctionImplementation(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params);

		TCFunctionImplementation(TCFunctionImplementation const &_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation const &_Other);
		TCFunctionImplementation(TCFunctionImplementation &_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation &_Other);
		TCFunctionImplementation(TCFunctionImplementation &&_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation &&_Other);

		template <typename tf_CFunction>
		TCFunctionImplementation(tf_CFunction &&_Function);

		template <typename tf_CFunction>
		TCFunctionImplementation &operator = (tf_CFunction &&_Function);

		void f_Clear();
		void const *f_GetFirstFunctionPointer() const;
		TCFunctionImplementation(CNullPtr _pNull);
		TCFunctionImplementation &operator = (CNullPtr _pNull);
		inline_small bool f_IsEmpty() const;
		inline_small explicit operator bool () const;
		inline_small void *f_Unsafe_GetFunctor() const;
		inline_small void *f_GetFunctor() const;

	private:
		using CNullFunction = TCImpl<TCNullFunctionImpl<t_CFOpts::mc_bNoExcept>, t_CFOpts>;
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;
	};

	template <typename t_CFOpts>
	struct TCFunctionImplementation<t_CFOpts, true, true> : public TCFunctionImplementation0<t_CFOpts::mc_NumFunctions - 1, typename t_CFOpts::CImpBase>
	{
	private:
		// Declared before the public section, which uses it.
		using CSuper = TCFunctionImplementation0<t_CFOpts::mc_NumFunctions - 1, typename t_CFOpts::CImpBase>;

	public:
		using CFunctionOptions = t_CFOpts;

		using CSuper::operator ();

		~TCFunctionImplementation();
		TCFunctionImplementation();

		template <typename ...tfp_CParams>
		TCFunctionImplementation(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params);

		TCFunctionImplementation(TCFunctionImplementation const &_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation const &_Other);
		TCFunctionImplementation(TCFunctionImplementation &_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation &_Other);
		TCFunctionImplementation(TCFunctionImplementation &&_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation &&_Other);

		template <typename tf_CFunction>
		TCFunctionImplementation(tf_CFunction &&_Function);

		template <typename tf_CFunction>
		TCFunctionImplementation &operator = (tf_CFunction &&_Function);

		void f_Clear();
		TCFunctionImplementation(CNullPtr _pNull);
		TCFunctionImplementation &operator = (CNullPtr _pNull);
		inline_small bool f_IsEmpty() const;
		inline_small explicit operator bool () const;
		inline_small void *f_Unsafe_GetFunctor() const;
		inline_small void *f_GetFunctor() const;
		bool operator == (TCFunctionImplementation const &_Other) const noexcept;
		COrdering_Partial operator <=> (TCFunctionImplementation const &_Other) const noexcept;

	private:
		using CNullFunction = TCImpl<TCNullFunctionImpl<t_CFOpts::mc_bNoExcept>, t_CFOpts>;
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;
	};

	template <typename t_CFOpts>
	struct TCFunctionImplementation<t_CFOpts, false, true> : public TCFunctionImplementation0<t_CFOpts::mc_NumFunctions - 1, typename t_CFOpts::CImpBase>
	{
	private:
		// Declared before the public section, which uses it.
		using CSuper = TCFunctionImplementation0<t_CFOpts::mc_NumFunctions - 1, typename t_CFOpts::CImpBase>;

	public:
		using CFunctionOptions = t_CFOpts;

		using CSuper::operator ();

		~TCFunctionImplementation();
		TCFunctionImplementation();

		template <typename ...tfp_CParams>
		TCFunctionImplementation(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params);

		TCFunctionImplementation(TCFunctionImplementation const &_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation const &_Other);
		TCFunctionImplementation(TCFunctionImplementation &_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation &_Other);
		TCFunctionImplementation(TCFunctionImplementation &&_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation &&_Other);

		template <typename tf_CFunction>
		TCFunctionImplementation(tf_CFunction &&_Function);

		template <typename tf_CFunction>
		TCFunctionImplementation &operator = (tf_CFunction &&_Function);

		void f_Clear();
		TCFunctionImplementation(CNullPtr _pNull);
		TCFunctionImplementation &operator = (CNullPtr _pNull);
		inline_small bool f_IsEmpty() const;
		inline_small explicit operator bool () const;
		inline_small void *f_Unsafe_GetFunctor() const;
		inline_small void *f_GetFunctor() const;
		COrdering_Partial operator <=> (TCFunctionImplementation const &_Other) const noexcept;

	private:
		using CNullFunction = TCImpl<TCNullFunctionImpl<t_CFOpts::mc_bNoExcept>, t_CFOpts>;
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;
	};

	template <typename t_CFOpts>
	struct TCFunctionImplementation<t_CFOpts, true, false> : public TCFunctionImplementation0<t_CFOpts::mc_NumFunctions - 1, typename t_CFOpts::CImpBase>
	{
	private:
		// Declared before the public section, which uses it.
		using CSuper = TCFunctionImplementation0<t_CFOpts::mc_NumFunctions - 1, typename t_CFOpts::CImpBase>;

	public:
		using CFunctionOptions = t_CFOpts;

		using CSuper::operator ();

		~TCFunctionImplementation();
		TCFunctionImplementation();

		template <typename ...tfp_CParams>
		TCFunctionImplementation(CAllocatorConstructTag const &_Tag, tfp_CParams && ...p_Params);

		TCFunctionImplementation(TCFunctionImplementation const &_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation const &_Other);
		TCFunctionImplementation(TCFunctionImplementation &_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation &_Other);
		TCFunctionImplementation(TCFunctionImplementation &&_Other);
		TCFunctionImplementation &operator = (TCFunctionImplementation &&_Other);

		template <typename tf_CFunction>
		TCFunctionImplementation(tf_CFunction &&_Function);

		template <typename tf_CFunction>
		TCFunctionImplementation &operator = (tf_CFunction &&_Function);

		void f_Clear();
		TCFunctionImplementation(CNullPtr _pNull);
		TCFunctionImplementation &operator = (CNullPtr _pNull);
		inline_small bool f_IsEmpty() const;
		inline_small explicit operator bool () const;
		inline_small void *f_Unsafe_GetFunctor() const;
		inline_small void *f_GetFunctor() const;
		bool operator == (TCFunctionImplementation const &_Other) const noexcept;

	private:
		using CNullFunction = TCImpl<TCNullFunctionImpl<t_CFOpts::mc_bNoExcept>, t_CFOpts>;
		using CFunctionDefinition = TCFunctionDefinitions<t_CFOpts>;
		using CVTable = typename CFunctionDefinition::CVTable;
	};
}

#include "Malterlib_Function_Function_Implementation.hpp"
