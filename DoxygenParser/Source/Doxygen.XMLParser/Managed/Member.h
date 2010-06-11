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
#include "Compound.h"
#include "Param.h"
#include "MemberReference.h"

using namespace System;

namespace Doxygen
{ 
  namespace XMLParser 
  {

    public ref class Member 
    {
    internal:
      Member (IMember* iMember);
      static Member^ Create (IMember* iMember); 

    public:
      enum class MemberKind 
      { 
        Invalid=0,
        Define, 
        Property, 
        Variable, 
        Typedef, 
        Enum,
        Function, 
        Signal, 
        Prototype, 
        Friend, 
        DCOP, 
        Slot, 
        EnumValue
      };
      Compound^ compound();
      Section^ section();
      MemberKind kind();
      String^ kindString();
      String^ id();
      String^ protection();
      String^ virtualness();
      LinkedTextIterator^ type();
      String^ typeString();
      String^ name();
      String^ readAccessor();
      String^ writeAccessor();
      String^ definition();
      String^ argsstring();
      bool isConst();
      bool isVolatile();
      bool isStatic();
      bool isExplicit();
      bool isInline();
      bool isMutable();
      bool isReadable();
      bool isWritable();
      ParamIterator^ parameters();
      ParamIterator^ templateParameters();
      LinkedTextIterator^ initializer();
      LinkedTextIterator^ exceptions();
      MemberReferenceIterator^ references(); 
      MemberReferenceIterator^ referencedBy();
      String^ bodyFile();
      int bodyStart();
      int bodyEnd();
      String^ definitionFile();
      int definitionLine();
      MemberReference^ reimplements();
      MemberReferenceIterator^ reimplementedBy();
      DocRoot^ briefDescription();
      DocRoot^ detailedDescription();
      DocRoot^ inbodyDescription();

    private:
      IMember* iMember;
    };

    public ref class MemberIterator
    {
    internal:
      MemberIterator(IMemberIterator * iMemberIterator);

    public:
      ~MemberIterator();
      !MemberIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      Member^ current();
      void release();

    private:
      IMemberIterator* iMemberIterator;
    };

    public ref class Define : public Member
    {
    internal:
      Define (IDefine* iDefine);
    };

    public ref class Property : public Member
    {
    internal:
      Property (IProperty* iProperty);
    };

    public ref class Variable : public Member
    {
    internal:
      Variable (IVariable* iVariable);
    };

    public ref class Typedef : public Member
    {
    internal:
      Typedef (ITypedef* iTypedef);
    };

    public ref class Function : public Member
    {
    internal:
      Function (IFunction* iFunction);
    };

    public ref class Signal : public Member
    {
    internal:
      Signal (ISignal* iSignal);
    };

    public ref class Prototype : public Member
    {
    internal:
      Prototype (IPrototype* iPrototype);
    };

    public ref class Friend : public Member
    {
    internal:
      Friend (IFriend* iFriend);
    };

    public ref class DCOP : public Member
    {
    internal:
      DCOP (IDCOP* iDCOP);
    };

    public ref class Slot : public Member
    {
    internal:
      Slot (ISlot* iSlot);
    };

    public ref class EnumValue : public Member
    {
    internal:
      EnumValue (IEnumValue* iEnumValue);

    public:
      String^ name();

    private:
      IEnumValue* iEnumValue;
    };

    public ref class Enum : public Member
    {
    internal:
      Enum (IEnum* iEnum);

    public:
      MemberIterator^ enumValues();

    private:
      IEnum* iEnum;
    };
  }
}
