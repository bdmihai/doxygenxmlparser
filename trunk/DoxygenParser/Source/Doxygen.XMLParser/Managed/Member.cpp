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

#include "Member.h"

using namespace Doxygen::XMLParser;

Member::Member (IMember* iMember)
{
  this->iMember = iMember;
}

Compound^ Member::compound()
{
  return Compound::Create(iMember->compound());
}

Section^ Member::section()
{
  return Section::Create(iMember->section());
}

Member::MemberKind Member::kind()
{
  return (Member::MemberKind)iMember->kind();
}

String^ Member::kindString()
{
  return gcnew String(iMember->kindString()->latin1());
}

String^ Member::id()
{
  return gcnew String(iMember->id()->latin1());
}

String^ Member::protection()
{
  return gcnew String(iMember->protection()->latin1());
}

String^ Member::virtualness()
{
  return gcnew String(iMember->virtualness()->latin1());
}

LinkedTextIterator^ Member::type()
{
  return gcnew LinkedTextIterator(iMember->type());
}

String^ Member::typeString()
{
  return gcnew String(iMember->typeString()->latin1());
}

String^ Member::name()
{
  return gcnew String(iMember->name()->latin1());
}

String^ Member::readAccessor()
{
  return gcnew String(iMember->readAccessor()->latin1());
}

String^ Member::writeAccessor()
{
  return gcnew String(iMember->writeAccessor()->latin1());
}

String^ Member::definition()
{
  return gcnew String(iMember->definition()->latin1());
}

String^ Member::argsstring()
{
  return gcnew String(iMember->argsstring()->latin1());
}

bool Member::isConst()
{
  return iMember->isConst();
}

bool Member::isVolatile()
{
  return iMember->isVolatile();
}

bool Member::isStatic()
{
  return iMember->isStatic();
}

bool Member::isExplicit()
{
  return iMember->isExplicit();
}

bool Member::isInline()
{
  return iMember->isInline();
}

bool Member::isMutable()
{
  return iMember->isMutable();
}

bool Member::isReadable()
{
  return iMember->isReadable();
}

bool Member::isWritable()
{
  return iMember->isWritable();
}

ParamIterator^ Member::parameters()
{
  return gcnew ParamIterator(iMember->parameters());
}

ParamIterator^ Member::templateParameters()
{
  return gcnew ParamIterator(iMember->templateParameters());
}

LinkedTextIterator^ Member::initializer()
{
  return gcnew LinkedTextIterator(iMember->initializer());
}

LinkedTextIterator^ Member::exceptions()
{
  return gcnew LinkedTextIterator(iMember->exceptions());
}

MemberReferenceIterator^ Member::references()
{
  return gcnew MemberReferenceIterator(iMember->references());
}

MemberReferenceIterator^ Member::referencedBy()
{
  return gcnew MemberReferenceIterator(iMember->referencedBy());
}

String^ Member::bodyFile()
{
  return gcnew String(iMember->bodyFile()->latin1());
}

int Member::bodyStart()
{
  return iMember->bodyStart();
}

int Member::bodyEnd()
{
  return iMember->bodyEnd();
}

String^ Member::definitionFile()
{
  return gcnew String(iMember->definitionFile()->latin1());
}

int Member::definitionLine()
{
  return iMember->definitionLine();
}

MemberReference^ Member::reimplements()
{
  return gcnew MemberReference(iMember->reimplements());
}

MemberReferenceIterator^ Member::reimplementedBy()
{
  return gcnew MemberReferenceIterator(iMember->reimplementedBy());
}

DocRoot^ Member::briefDescription()
{
  return gcnew DocRoot(iMember->briefDescription());
}

DocRoot^ Member::detailedDescription()
{
  return gcnew DocRoot(iMember->detailedDescription());
}

DocRoot^ Member::inbodyDescription()
{
  return gcnew DocRoot(iMember->inbodyDescription());
}

Member^ Member::Create (IMember* iMember)
{
  if (iMember == nullptr)
    return nullptr;

  switch (iMember->kind())
  {
  case IMember::Define:     {return gcnew Define(dynamic_cast<IDefine*>(iMember));} 
  case IMember::Property:   {return gcnew Property(dynamic_cast<IProperty*>(iMember));} 
  case IMember::Variable:   {return gcnew Variable(dynamic_cast<IVariable*>(iMember));} 
  case IMember::Typedef:    {return gcnew Typedef(dynamic_cast<ITypedef*>(iMember));}
  case IMember::Enum:       {return gcnew Enum(dynamic_cast<IEnum*>(iMember));}
  case IMember::Function:   {return gcnew Function(dynamic_cast<IFunction*>(iMember));} 
  case IMember::Signal:     {return gcnew Signal(dynamic_cast<ISignal*>(iMember));} 
  case IMember::Prototype:  {return gcnew Prototype(dynamic_cast<IPrototype*>(iMember));} 
  case IMember::Friend:     {return gcnew Friend(dynamic_cast<IFriend*>(iMember));} 
  case IMember::DCOP:       {return gcnew DCOP(dynamic_cast<IDCOP*>(iMember));} 
  case IMember::Slot:       {return gcnew Slot(dynamic_cast<ISlot*>(iMember));} 
  case IMember::EnumValue:  {return gcnew EnumValue(dynamic_cast<IEnumValue*>(iMember));}
  }

  return nullptr;
}

//////////////////////////////////////////////////////////////////////////

MemberIterator::MemberIterator(IMemberIterator * iMemberIterator)
{
  this->iMemberIterator = iMemberIterator;
}

MemberIterator::~MemberIterator()
{
  this->!MemberIterator();
}

MemberIterator::!MemberIterator()
{
  release();
}

void MemberIterator::toFirst()
{
  iMemberIterator->toFirst();
}

void MemberIterator::toLast()
{
  iMemberIterator->toLast();
}

void MemberIterator::toNext()
{
  iMemberIterator->toNext();
}

void MemberIterator::toPrev()
{
  iMemberIterator->toPrev();
}

Member^ MemberIterator::current()
{
  return Member::Create(iMemberIterator->current());
}

void MemberIterator::release()
{
  if (iMemberIterator != nullptr)
  {
    iMemberIterator->release();
    iMemberIterator = nullptr;
  }
}

//////////////////////////////////////////////////////////////////////////

Define::Define (IDefine* iDefine) : Member(iDefine)
{

}

//////////////////////////////////////////////////////////////////////////

Property::Property (IProperty* iProperty) : Member(iProperty)
{

}

//////////////////////////////////////////////////////////////////////////

Variable::Variable (IVariable* iVariable) : Member(iVariable)
{

}

//////////////////////////////////////////////////////////////////////////

Typedef::Typedef (ITypedef* iTypedef) : Member(iTypedef)
{

}

//////////////////////////////////////////////////////////////////////////

Function::Function (IFunction* iFunction) : Member(iFunction)
{

}

//////////////////////////////////////////////////////////////////////////

Signal::Signal (ISignal* iSignal) : Member(iSignal)
{

}

//////////////////////////////////////////////////////////////////////////

Prototype::Prototype (IPrototype* iPrototype) : Member(iPrototype)
{

}

//////////////////////////////////////////////////////////////////////////

Friend::Friend (IFriend* iFriend) : Member(iFriend)
{

}

//////////////////////////////////////////////////////////////////////////

DCOP::DCOP (IDCOP* iDCOP) : Member(iDCOP)
{

}

//////////////////////////////////////////////////////////////////////////

Slot::Slot (ISlot* iSlot) : Member(iSlot)
{

}

//////////////////////////////////////////////////////////////////////////

EnumValue::EnumValue (IEnumValue* iEnumValue) : Member(iEnumValue)
{
  this->iEnumValue = iEnumValue;
}

String^ EnumValue::name()
{
  return gcnew String(iEnumValue->name()->latin1());
}

//////////////////////////////////////////////////////////////////////////

Doxygen::XMLParser::Enum::Enum (IEnum* iEnum) : Member(iEnum)
{
  this->iEnum = iEnum;
}

MemberIterator^ Doxygen::XMLParser::Enum::enumValues()
{
  return gcnew MemberIterator(iEnum->enumValues());
}

