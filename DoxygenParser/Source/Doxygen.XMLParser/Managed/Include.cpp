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

#include "Include.h"

using namespace Doxygen::XMLParser;

Include::Include(IInclude *iInclude)
{
  this->iInclude = iInclude;
}

String^ Include::name()
{
  return gcnew String(iInclude->name()->latin1());
}

String^ Include::refId()
{
  return gcnew String(iInclude->refId()->latin1());
}

bool Include::isLocal()
{
  return iInclude->isLocal();
}

//////////////////////////////////////////////////////////////////////////

IncludeIterator::IncludeIterator(IIncludeIterator * iIncludeIterator)
{
  this->iIncludeIterator = iIncludeIterator;
}

IncludeIterator::~IncludeIterator()
{
  this->!IncludeIterator();
}

IncludeIterator::!IncludeIterator()
{
  release();
}

void IncludeIterator::toFirst()
{
  iIncludeIterator->toFirst();
}

void IncludeIterator::toLast()
{
  iIncludeIterator->toLast();
}

void IncludeIterator::toNext()
{
  iIncludeIterator->toNext();
}

void IncludeIterator::toPrev()
{
  iIncludeIterator->toPrev();
}

Include^ IncludeIterator::current()
{
  return gcnew Include(iIncludeIterator->current());
}

void IncludeIterator::release()
{
  if (iIncludeIterator != nullptr)
  {
    iIncludeIterator->release();
    iIncludeIterator = nullptr;
  }
}