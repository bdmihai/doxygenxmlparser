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

#include "MemberReference.h"
#include "Member.h"

using namespace Doxygen::XMLParser;

MemberReference::MemberReference (IMemberReference* iMemberReference)
{
  this->iMemberReference = iMemberReference;
}

Member^ MemberReference::member()
{
  return Member::Create (iMemberReference->member());
}

String^ MemberReference::name()
{
  return gcnew String(iMemberReference->name()->latin1());
}

String^ MemberReference::scope()
{
  return gcnew String(iMemberReference->scope()->latin1());
}

String^ MemberReference::protection()
{
  return gcnew String(iMemberReference->protection()->latin1());
}

String^ MemberReference::virtualness()
{
  return gcnew String(iMemberReference->virtualness()->latin1());
}

String^ MemberReference::ambiguityScope()
{
  return gcnew String(iMemberReference->ambiguityScope()->latin1());
}

//////////////////////////////////////////////////////////////////////////

MemberReferenceIterator::MemberReferenceIterator(IMemberReferenceIterator * iMemberReferenceIterator)
{
  this->iMemberReferenceIterator = iMemberReferenceIterator;
}

MemberReferenceIterator::~MemberReferenceIterator()
{
  this->!MemberReferenceIterator();
}

MemberReferenceIterator::!MemberReferenceIterator()
{
  release();
}

void MemberReferenceIterator::toFirst()
{
  iMemberReferenceIterator->toFirst();
}

void MemberReferenceIterator::toLast()
{
  iMemberReferenceIterator->toLast();
}

void MemberReferenceIterator::toNext()
{
  iMemberReferenceIterator->toNext();
}

void MemberReferenceIterator::toPrev()
{
  iMemberReferenceIterator->toPrev();
}

MemberReference^ MemberReferenceIterator::current()
{
  if (iMemberReferenceIterator->current() != nullptr)
    return gcnew MemberReference(iMemberReferenceIterator->current());
  else
    return nullptr;
}

void MemberReferenceIterator::release()
{
  if (iMemberReferenceIterator != nullptr)
  {
    iMemberReferenceIterator->release();
    iMemberReferenceIterator = nullptr;
  }
}

