/******************************************************************************
*
* Copyright (C) 2008-2010 by Baneu Mihai.
*
* Permission to use, copy, modify, and distribute this software and its
* documentation under the terms of the GNU General Public License is hereby 
* granted. No representations are made about the suitability of this software 
* for any purpose. It is provided "as is" without express or implied warranty.
* See the GNU General Public License for more details.
*
*/

#pragma once

#include "..\Native\doxmlintf.h"
#include "Section.h"
#include "Doc.h"
#include "Graph.h"
#include "Param.h"
#include "Include.h"

using namespace System;

namespace Doxygen
{ 
  namespace XMLParser 
  {

    ref class Member;
    ref class MemberIterator;
    ref class RelatedCompoundIterator;

    public ref class Compound
    {
    internal:
      Compound(ICompound* compound);

      static Compound^ Create (ICompound* compound);

    public:
      /*! Represents the kind of compounds recognized by doxygen. */
      enum class CompoundKind 
      { 
        Invalid = 0,
        Class, 
        Struct, 
        Union, 
        Interface, 
        Protocol, 
        Category,
        Exception, 
        File, 
        Namespace, 
        Group, 
        Page, 
        Example, 
        Dir
      };

      /*! Returns the name of this compound */
      String^ name();

      /*! Returns the id of this compound. The id is a
      *  unique string representing a specific compound object.
      */
      String^ id();

      /*! Returns the kind of compound. See #CompoundKind for possible
      *  values.
      */
      CompoundKind kind();

      /*! Returns a string representation of the compound kind.
      *  @see kind()
      */
      String^ kindString();

      /*! Returns an iterator for the different member sections in this
      *  compound.
      */
      SectionIterator^ sections();

      /*! Returns a tree-structured representation of the brief
      *  description that is attached to this compound.
      */
      DocRoot^ briefDescription();

      /*! Returns a tree-structured representation of the detailed
      *  description that is attached to this compound.
      */
      DocRoot^ detailedDescription();

      /*! Returns an interface to a member given its id. 
      *  @param id The member id.
      */
      Member^ memberById(String^ id);

      /*! Returns a list of all members within the compound having a certain 
      *  name. Member overloading is the reason why there can be more than 
      *  one member. 
      *  @param name The name of the member.
      */
      MemberIterator^ memberByName(String^ name);

      /*! Decreases the reference counter for this compound. If it reaches
      *  zero, the memory for the compound will be released.
      */
      void release();

    private:
      ICompound* iCompound;
    };

    public ref class CompoundIterator
    {
    internal:
      CompoundIterator(ICompoundIterator * iCompoundIterator);

    public:
      ~CompoundIterator();
      !CompoundIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      Compound^ current();
      void release();

    private:
      ICompoundIterator* iCompoundIterator;
    };

    public ref class Class : public Compound
    {
    internal:
      Class(IClass *iClass);

    public:
      Graph^ inheritanceGraph();
      Graph^ collaborationGraph();
      RelatedCompoundIterator^ baseCompounds();
      RelatedCompoundIterator^ derivedCompounds();
      CompoundIterator^ nestedCompounds();
      ParamIterator^ templateParameters();
      String^ locationFile();
      int locationLine();
      String^ locationBodyFile();
      int locationBodyStartLine();
      int locationBodyEndLine();

    private:
      IClass * iClass;
    };

    public ref class Struct : public Compound
    {
    internal:
      Struct(IStruct *iStruct);

    public:
      CompoundIterator^ nestedCompounds();
      RelatedCompoundIterator^ baseCompounds();
      RelatedCompoundIterator^ derivedCompounds();
      String^ locationFile();
      int locationLine();
      int locationBodyStartLine();
      int locationBodyEndLine();

    private:
      IStruct * iStruct;
    };

    public ref class Union : public Compound
    {
    internal:
      Union(IUnion *iUnion);

    public:
      CompoundIterator^ nestedCompounds();

    private:
      IUnion * iUnion;
    };

    public ref class Interface : public Compound
    {
    internal:
      Interface(IInterface *iInterface);

    public:
      RelatedCompoundIterator^ baseCompounds();
      RelatedCompoundIterator^ derivedCompounds();

    private:
      IInterface * iInterface;
    };

    public ref class Exception : public Compound
    {
    internal:
      Exception(IException *iException);
    };

    public ref class Namespace : public Compound
    {
    internal:
      Namespace(INamespace *iNamespace);

    public:
      CompoundIterator^ nestedCompounds();

    private:
      INamespace * iNamespace;
    };

    public ref class File : public Compound
    {
    internal:
      File(IFile *iFile);

    public:
      Graph^ includeDependencyGraph();
      Graph^ includedByDependencyGraph();
      DocProgramListing^ source();
      CompoundIterator^ nestedCompounds();

      IncludeIterator^ includes();
      IncludeIterator^ includedBy();

    private:
      IFile * iFile;
    };

    public ref class Group : public Compound
    {
    internal:
      Group(IGroup *iGroup);

    public:
      CompoundIterator^ nestedCompounds();

    private:
      IGroup * iGroup;
    };

    public ref class Page : public Compound
    {
    internal:
      Page(IPage *iPage);

    public:
      DocTitle^ title();

    private:
      IPage * iPage;
    };
  }
}
