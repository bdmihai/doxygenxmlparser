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

#include "RelatedCompound.h"

using namespace Doxygen::XMLParser;

RelatedCompound::RelatedCompound (IRelatedCompound* iRelatedCompound)
{
  this->iRelatedCompound = iRelatedCompound;
}


Compound^ RelatedCompound::compound()
{
  return Compound::Create(iRelatedCompound->compound());
}

RelatedCompound::Protection RelatedCompound::protection()
{
  return (RelatedCompound::Protection)iRelatedCompound->protection();
}

RelatedCompound::Kind RelatedCompound::kind()
{
  return (RelatedCompound::Kind)iRelatedCompound->kind();
}

String^ RelatedCompound::name()
{
  return gcnew String(iRelatedCompound->name()->latin1());
}

//////////////////////////////////////////////////////////////////////////

RelatedCompoundIterator::RelatedCompoundIterator(IRelatedCompoundIterator * iRelatedCompoundIterator)
{
  this->iRelatedCompoundIterator = iRelatedCompoundIterator;
}

RelatedCompoundIterator::~RelatedCompoundIterator()
{
  this->!RelatedCompoundIterator();
}

RelatedCompoundIterator::!RelatedCompoundIterator()
{
  release();
}

void RelatedCompoundIterator::toFirst()
{
  iRelatedCompoundIterator->toFirst();
}

void RelatedCompoundIterator::toLast()
{
  iRelatedCompoundIterator->toLast();
}

void RelatedCompoundIterator::toNext()
{
  iRelatedCompoundIterator->toNext();
}

void RelatedCompoundIterator::toPrev()
{
  iRelatedCompoundIterator->toPrev();
}

RelatedCompound^ RelatedCompoundIterator::current()
{
  return gcnew RelatedCompound(iRelatedCompoundIterator->current());
}

void RelatedCompoundIterator::release()
{
  if (iRelatedCompoundIterator != nullptr)
  {
    iRelatedCompoundIterator->release();
    iRelatedCompoundIterator = nullptr;
  }
}

