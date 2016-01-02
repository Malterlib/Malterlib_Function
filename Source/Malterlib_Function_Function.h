// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

/// \file	Malterlib_Function_Function.h
///			File for the function templates

#include <Mib/Storage/Indirection>

namespace NMib
{
	namespace NFunction
	{

		/** \brief Used to specify that a function should implement comparison operators
			
			If you specify this tag the functors you put into the function has to
			support equal and less than comparison operators.
		*/
		struct CFunctionSupportCompareTag
		{
		};

		/// Used to specify that a function should not implement copy constructors 
		struct CFunctionNoCopyTag
		{
		};

		/// Used to specify that a function should not implement move constructors
		struct CFunctionNoMoveTag
		{
		};
		

		/**	\brief Used to specify the qualifiers of a functor invocation
			
			Specify this tag together with qualifiers to determine how the function
			in a function is called, and how a function can be called.
		 
			Examples:
			~~~
			TCFunction<void ()>							// Defaults to const invocation
			TCFunction<void (CThisTag &)>				// mutable invocation
			TCFunction<void (CThisTag const &)>			// const invocation
			TCFunction<void (CThisTag volatile &)>		// volatile invocation
			TCFunction<void (CThisTag const volatile &)>// const volatile invocation
			TCFunction<void (CThisTag &, int)>			// mutable invocation with param
			~~~
		 
			Keep in mind that the tag has to be specified as the first parameter of
			the function, and that it will be stripped.
		 
			Notice also that the tag has to be specified as a reference, otherwise
			the compiler will drop the qualifiers.
		*/
		struct CThisTag
		{
		};

		/**	\brief Used to specify options to to TCFunction and TCFunctionNoAlloc class
		 
		*/
		template 
		<
			bint t_AllowAlloc = false 
			/// Set to true to allow the function to allocate memory dynamically
			, uint32 t_MaxSize = sizeof(void *)*4 
			/// The maximum size of the functor object that can be put in the TCFunctionXXXX object
			, uint32 t_Alignment = TCConstantMax<mint, sizeof(void *), NTraits::TCAlignmentOf<fp64>::mc_Value>::mc_Value 
			/// The maximum alignment of a type that can be put in the TCFunctionXXXX object
		>
		struct TCFunctionNoAllocOptions
		{
			enum
			{
				mc_MaxSize = (t_MaxSize + t_Alignment - 1) & ~mint(t_Alignment - 1)
				, mc_Alignment = t_Alignment
				, mc_bAllowAlloc = t_AllowAlloc
			};
		};
		
		///@}
	}
}

#include "Private/Malterlib_Function_Function_Helpers.h"
#include "Private/Malterlib_Function_Function_NullFunction.h"
#include "Private/Malterlib_Function_Function_Definition.h"
#include "Private/Malterlib_Function_Function_CallImplementation.h"
#include "Private/Malterlib_Function_Function_VTable.h"
#include "Private/Malterlib_Function_Function_StorageImplementation.h"
#include "Private/Malterlib_Function_Function_Implementation.h"

namespace NMib
{
	namespace NFunction
	{

		namespace NPrivate
		{
			template <typename t_CType>
			struct TCIsTCFunctionImpl
			{
				enum
				{
					mc_Value = false
				};
			};

			template <typename t_CLeft, typename t_CRight, bint t_bBothFunction = TCIsTCFunctionImpl<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CLeft>::CType>::CType>::mc_Value && TCIsTCFunctionImpl<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CRight>::CType>::CType>::mc_Value>
			struct TCIsTCFunctionCompareInValid
			{
				enum
				{
					mc_bLeftFunction = TCIsTCFunctionImpl<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CLeft>::CType>::CType>::mc_Value
					, mc_bRightFunction = TCIsTCFunctionImpl<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CRight>::CType>::CType>::mc_Value
					, mc_Value = (mc_bLeftFunction || mc_bRightFunction)
				};
			};

			template <typename t_CLeft, typename t_CRight>
			struct TCIsTCFunctionCompareInValid<t_CLeft, t_CRight, true>
			{
				enum
				{
					mc_Value 
					= 
					!NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CLeft>::CType>::CType, typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<t_CRight>::CType>::CType>::mc_Value
					|| !(NTraits::TCRemoveReference<t_CLeft>::CType::CFunctionOptions::mc_bSupportCompare)
				};
			};
		}
		
		/// General function template tuned for a mix of fast construction and fast calls.
		template 
		<
			typename t_CFunction		/// The function definition to contain
			, typename... tp_COptions	/// Arguments. Can be function definition, option (CFunctionSupportCompareTag) or allocator
		>
		class TCFunction : public NPrivate::TCFunctionImplementation<NPrivate::TCFunctionOptions<NPrivate::TCFunctionNoAllocBase, NMem::CAllocator_Heap, TCFunctionNoAllocOptions<true, sizeof(void *)*3>, t_CFunction, tp_COptions...>>
		{
			template <typename t_CLeft0, typename t_CRight0, bint t_bBothFunction0>
			friend struct NPrivate::TCIsTCFunctionCompareInValid;

			typedef NPrivate::TCFunctionOptions<NPrivate::TCFunctionNoAllocBase, NMem::CAllocator_Heap, TCFunctionNoAllocOptions<true, sizeof(void *)*3>, t_CFunction, tp_COptions...> CFunctionOptions;
			typedef NPrivate::TCFunctionImplementation<CFunctionOptions> CSuper;

			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunction(TCFunction const &_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunction &operator = (TCFunction const &_Other) = delete;
			
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunction(TCFunction &_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunction &operator = (TCFunction &_Other) = delete;
			
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportMove, tf_CDummy> = true>
			TCFunction(TCFunction &&_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportMove, tf_CDummy> = true>
			TCFunction &operator = (TCFunction &&_Other) = delete;

		public:
			~TCFunction()
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
			TCFunction()
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyConstruct
			template <typename tf_CDummy = bool	/**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunction(TCFunction const &_Other)
				: CSuper
				(
					(CSuper const &)_Other
				)
			{
			}
            
			/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyAssignment
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunction &operator = (TCFunction const &_Other)
			{
				CSuper::operator = ((CSuper const &)_Other);
				return *this;
			}
			
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunction(TCFunction &_Other)
				: CSuper((CSuper &)_Other)
			{
			}

			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunction &operator = (TCFunction &_Other)
			{
				CSuper::operator = ((CSuper &)_Other);
				return *this;
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveConstruct
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportMove, tf_CDummy> = true /**@hidden*/>
			TCFunction(TCFunction &&_Other)
				: CSuper((CSuper &&)_Other)
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveAssignment
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportMove, tf_CDummy> = true /**@hidden*/>
			TCFunction &operator = (TCFunction &&_Other)
			{
				CSuper::operator = ((CSuper &&)_Other);
				return *this;
			}
            
			/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
			template 
			<
				typename tf_CFunction
				, TCEnableIfType
				<
					!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
					&& !NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CFunction>::CType>::CType, TCFunction>::mc_Value
					, bool
				> = true /**@hidden*/
			>
			TCFunction(tf_CFunction &&_Function)
				: CSuper(fg_Forward<tf_CFunction>(_Function))
			{
			}	

			/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
			template 
			<
				typename tf_CFunction
				, TCEnableIfType
				<
					!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
					&& !NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CFunction>::CType>::CType, TCFunction>::mc_Value
					, bool
				> = true /**@hidden*/
			>
			TCFunction &operator = (tf_CFunction &&_Function)
			{
				CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
				return *this;
			}
		};

		/// Function template tuned for maximum performance of calls.
		template 
		<
			typename t_CFunction /// The function definition to contain
			, typename... tp_COptions /// Arguments. Can be function definition, option (CFunctionSupportCompareTag) or allocator 
		>
		class TCFunctionFastCall : public NPrivate::TCFunctionImplementation<NPrivate::TCFunctionOptions<NPrivate::TCFunctionBase, NMem::CAllocator_Heap, TCFunctionNoAllocOptions<>, t_CFunction, tp_COptions...>>
		{
			template <typename t_CLeft0, typename t_CRight0, bint t_bBothFunction0>
			friend struct NPrivate::TCIsTCFunctionCompareInValid;

			typedef NPrivate::TCFunctionOptions<NPrivate::TCFunctionBase, NMem::CAllocator_Heap, TCFunctionNoAllocOptions<>, t_CFunction, tp_COptions...> CFunctionOptions;
			typedef NPrivate::TCFunctionImplementation<CFunctionOptions> CSuper;	
			
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionFastCall(TCFunctionFastCall const &_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionFastCall &operator = (TCFunctionFastCall const &_Other) = delete;

			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionFastCall(TCFunctionFastCall &_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionFastCall &operator = (TCFunctionFastCall &_Other) = delete;

			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportMove, tf_CDummy> = true>
			TCFunctionFastCall(TCFunctionFastCall &&_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportMove, tf_CDummy> = true>
			TCFunctionFastCall &operator = (TCFunctionFastCall &&_Other) = delete;

		public:
			~TCFunctionFastCall()
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
			TCFunctionFastCall()
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyConstruct
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionFastCall(TCFunctionFastCall const &_Other)
				: CSuper((CSuper const &)_Other)
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyAssignment
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionFastCall &operator = (TCFunctionFastCall const &_Other)
			{
				CSuper::operator = ((CSuper const &)_Other);
				return *this;
			}

			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionFastCall(TCFunctionFastCall &_Other)
				: CSuper((CSuper &)_Other)
			{
			}

			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionFastCall &operator = (TCFunctionFastCall &_Other)
			{
				CSuper::operator = ((CSuper &)_Other);
				return *this;
			}
			
			/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveConstruct
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportMove, tf_CDummy> = true /**@hidden*/>
			TCFunctionFastCall(TCFunctionFastCall &&_Other)
				: CSuper((CSuper &&)_Other)
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveAssignment
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportMove, tf_CDummy> = true /**@hidden*/>
			TCFunctionFastCall &operator = (TCFunctionFastCall &&_Other)
			{
				CSuper::operator = ((CSuper &&)_Other);
				return *this;
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
			template 
			<
				typename tf_CFunction
				, TCEnableIfType
				<
					!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
					&& !NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CFunction>::CType>::CType, TCFunctionFastCall>::mc_Value
					, bool
				> = true /**@hidden*/
			>
			TCFunctionFastCall(tf_CFunction &&_Function)
				: CSuper(fg_Forward<tf_CFunction>(_Function))
			{
			}	

			/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
			template 
			<
				typename tf_CFunction
				, TCEnableIfType
				<
					!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
					&& !NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CFunction>::CType>::CType, TCFunctionFastCall>::mc_Value
					, bool
				> = true /**@hidden*/
			>
			TCFunctionFastCall &operator = (tf_CFunction &&_Function)
			{
				CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
				return *this;
			}
			
			/// @}
		};

		/// Function template tuned for minimum storage of empty functions.
		template 
		<
			typename t_CFunction /// The function definition to contain
			, typename... tp_COptions /// Arguments. Can be function definition, option (CFunctionSupportCompareTag) or allocator 
		>
		class TCFunctionSmall : public NPrivate::TCFunctionImplementation<NPrivate::TCFunctionOptions<NPrivate::TCFunctionSmallBase, NMem::CAllocator_Heap, TCFunctionNoAllocOptions<>, t_CFunction, tp_COptions...>>
		{
			template <typename t_CLeft0, typename t_CRight0, bint t_bBothFunction0>
			friend struct NPrivate::TCIsTCFunctionCompareInValid;

			typedef NPrivate::TCFunctionOptions<NPrivate::TCFunctionSmallBase, NMem::CAllocator_Heap, TCFunctionNoAllocOptions<>, t_CFunction, tp_COptions...> CFunctionOptions;
			typedef NPrivate::TCFunctionImplementation<CFunctionOptions> CSuper;
			
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionSmall(TCFunctionSmall const &_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionSmall &operator = (TCFunctionSmall const &_Other) = delete;

			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionSmall(TCFunctionSmall &_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionSmall &operator = (TCFunctionSmall &_Other) = delete;

			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportMove, tf_CDummy> = true>
			TCFunctionSmall(TCFunctionSmall &&_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportMove, tf_CDummy> = true>
			TCFunctionSmall &operator = (TCFunctionSmall &&_Other) = delete;

		public:
			~TCFunctionSmall()
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
			TCFunctionSmall()
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyConstruct
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionSmall(TCFunctionSmall const &_Other)
				: CSuper((CSuper const &)_Other)
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyAssignment
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionSmall &operator = (TCFunctionSmall const &_Other)
			{
				CSuper::operator = ((CSuper const &)_Other);
				return *this;
			}

			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionSmall(TCFunctionSmall &_Other)
				: CSuper((CSuper &)_Other)
			{
			}

			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionSmall &operator = (TCFunctionSmall &_Other)
			{
				CSuper::operator = ((CSuper &)_Other);
				return *this;
			}
			
			/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveConstruct
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportMove, tf_CDummy> = true /**@hidden*/>
			TCFunctionSmall(TCFunctionSmall &&_Other)
				: CSuper((CSuper &&)_Other)
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveAssignment
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportMove, tf_CDummy> = true /**@hidden*/>
			TCFunctionSmall &operator = (TCFunctionSmall &&_Other)
			{
				CSuper::operator = ((CSuper &&)_Other);
				return *this;
			}
			
			/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
			template 
			<
				typename tf_CFunction
				, TCEnableIfType
				<
					!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
					&& !NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CFunction>::CType>::CType, TCFunctionSmall>::mc_Value
					, bool
				> = true /**@hidden*/
			>
			TCFunctionSmall(tf_CFunction &&_Function)
				: CSuper(fg_Forward<tf_CFunction>(_Function))
			{
			}	

			/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
			template 
			<
				typename tf_CFunction
				, TCEnableIfType
				<
					!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
					&& !NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CFunction>::CType>::CType, TCFunctionSmall>::mc_Value
					, bool
				> = true /**@hidden*/
			>
			TCFunctionSmall &operator = (tf_CFunction &&_Function)
			{
				CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
				return *this;
			}
		};


		//// Function template tuned for maximum call speed and maximum construction speed.
		template 
		<
			typename t_CFunction /// The function definition to contain
			, typename... tp_COptions /// Arguments. Can be function definition, option (CFunctionSupportCompareTag) or allocator 
		>
		class TCFunctionNoAlloc : public NPrivate::TCFunctionImplementation<NPrivate::TCFunctionOptions<NPrivate::TCFunctionNoAllocBase, NMem::CAllocator_Disable, TCFunctionNoAllocOptions<>, t_CFunction, tp_COptions...>>
		{
			template <typename t_CLeft0, typename t_CRight0, bint t_bBothFunction0>
			friend struct NPrivate::TCIsTCFunctionCompareInValid;

			typedef NPrivate::TCFunctionOptions<NPrivate::TCFunctionNoAllocBase, NMem::CAllocator_Disable, TCFunctionNoAllocOptions<>, t_CFunction, tp_COptions...> CFunctionOptions;
			typedef NPrivate::TCFunctionImplementation<CFunctionOptions> CSuper;
			
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionNoAlloc(TCFunctionNoAlloc const &_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionNoAlloc &operator = (TCFunctionNoAlloc const &_Other) = delete;

			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionNoAlloc(TCFunctionNoAlloc &_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true>
			TCFunctionNoAlloc &operator = (TCFunctionNoAlloc &_Other) = delete;

			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportMove, tf_CDummy> = true>
			TCFunctionNoAlloc(TCFunctionNoAlloc &&_Other) = delete;
			template <typename tf_CDummy = bool, TCEnableIfType<!CFunctionOptions::mc_bSupportMove, tf_CDummy> = true>
			TCFunctionNoAlloc &operator = (TCFunctionNoAlloc &&_Other) = delete;

		public:
			~TCFunctionNoAlloc()
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_Default
			TCFunctionNoAlloc()
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyConstruct
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionNoAlloc(TCFunctionNoAlloc const &_Other)
				: CSuper((CSuper const &)_Other)
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_CopyAssignment
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionNoAlloc &operator = (TCFunctionNoAlloc const &_Other)
			{
				CSuper::operator = ((CSuper const &)_Other);
				return *this;
			}

			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionNoAlloc(TCFunctionNoAlloc &_Other)
				: CSuper((CSuper &)_Other)
			{
			}

			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportCopy, tf_CDummy> = true /**@hidden*/>
			TCFunctionNoAlloc &operator = (TCFunctionNoAlloc &_Other)
			{
				CSuper::operator = ((CSuper &)_Other);
				return *this;
			}
			
			/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveConstruct
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportMove, tf_CDummy> = true /**@hidden*/>
			TCFunctionNoAlloc(TCFunctionNoAlloc &&_Other)
				: CSuper((CSuper &&)_Other)
			{
			}

			/// \copydoc NMib::NFunction::DoxyInternal_Function_MoveAssignment
			template <typename tf_CDummy = bool /**@hidden*/, TCEnableIfType<CFunctionOptions::mc_bSupportMove, tf_CDummy> = true /**@hidden*/>
			TCFunctionNoAlloc &operator = (TCFunctionNoAlloc &&_Other)
			{
				CSuper::operator = ((CSuper &&)_Other);
				return *this;
			}
			
			/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralConstruct
			template 
			<
				typename tf_CFunction
				, TCEnableIfType
				<
					!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
					&& !NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CFunction>::CType>::CType, TCFunctionNoAlloc>::mc_Value
					, bool
				> = true /**@hidden*/
			>
			TCFunctionNoAlloc(tf_CFunction &&_Function)
				: CSuper(fg_Forward<tf_CFunction>(_Function))
			{
			}	

			/// \copydoc NMib::NFunction::DoxyInternal_Function_GeneralAssignment
			template 
			<
				typename tf_CFunction
				, TCEnableIfType
				<
					!NTraits::TCIsSame<typename NTraits::TCRemoveReference<tf_CFunction>::CType, NInternal::CDefault>::mc_Value
					&& !NTraits::TCIsSame<typename NTraits::TCRemoveQualifiers<typename NTraits::TCRemoveReference<tf_CFunction>::CType>::CType, TCFunctionNoAlloc>::mc_Value
					, bool
				> = true /**@hidden*/
			>
			TCFunctionNoAlloc &operator = (tf_CFunction &&_Function)
			{
				CSuper::operator = (fg_Forward<tf_CFunction>(_Function));
				return *this;
			}
			
		};
		
		namespace NPrivate
		{
			template <typename t_CFunction, typename... tp_COptions>
			struct TCIsTCFunctionImpl<TCFunction<t_CFunction, tp_COptions...>>
			{
				enum
				{
					mc_Value = true
				};
			};

			template <typename t_CFunction, typename... tp_COptions>
			struct TCIsTCFunctionImpl<TCFunctionFastCall<t_CFunction, tp_COptions...>>
			{
				enum
				{
					mc_Value = true
				};
			};

			template <typename t_CFunction, typename... tp_COptions>
			struct TCIsTCFunctionImpl<TCFunctionNoAlloc<t_CFunction, tp_COptions...>>
			{
				enum
				{
					mc_Value = true
				};
			};

			template <typename t_CFunction, typename... tp_COptions>
			struct TCIsTCFunctionImpl<TCFunctionSmall<t_CFunction, tp_COptions...>>
			{
				enum
				{
					mc_Value = true
				};
			};
		}

		template <typename tf_CLeft, typename tf_CRight>
		TCEnableIfType<NPrivate::TCIsTCFunctionCompareInValid<tf_CLeft, tf_CRight>::mc_Value, bint> operator == (tf_CLeft &&_Left, tf_CRight &&_Right)
		{
			static_assert(!NPrivate::TCIsTCFunctionCompareInValid<tf_CLeft, tf_CRight>::mc_Value
				, "Compare not allowed");
			return true;
		}

		template <typename tf_CLeft, typename tf_CRight>
		TCEnableIfType<NPrivate::TCIsTCFunctionCompareInValid<tf_CLeft, tf_CRight>::mc_Value, bint> operator < (tf_CLeft &&_Left, tf_CRight &&_Right)
		{
			static_assert(!NPrivate::TCIsTCFunctionCompareInValid<tf_CLeft, tf_CRight>::mc_Value
				, "Compare not allowed");
			return true;
		}
	}



}

#ifndef DMibPNoShortCuts
	using namespace NMib::NFunction;	
#endif

 