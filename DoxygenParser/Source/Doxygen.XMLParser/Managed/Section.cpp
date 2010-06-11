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

#include "Section.h"
#include "Member.h"

using namespace Doxygen::XMLParser;

Section::Section(ISection *iSection)
{
  this->iSection = iSection;
}

String^ Section::kindString()
{
  return gcnew String(iSection->kindString()->latin1());
}

Section::SectionKind Section::kind()
{
  return (Section::SectionKind)iSection->kind();
}

DocRoot^ Section::description()
{
  return gcnew DocRoot(iSection->description());
}

MemberIterator^ Section::members()
{
  return gcnew MemberIterator(iSection->members());
}

bool Section::isStatic()
{
  return iSection->isStatic();
}

bool Section::isPublic()
{
  return iSection->isPublic();
}

bool Section::isPrivate()
{
  return iSection->isPrivate();
}

bool Section::isProtected()
{
  return iSection->isProtected();
}

Section^ Section::Create(ISection *iSection)
{
  if (iSection == nullptr)
    return nullptr;

  switch (iSection->kind())
  {
  case ISection::UserDefined:
    {
      return gcnew UserDefined(dynamic_cast<IUserDefined*>(iSection));
    }
  default:
    {
      return gcnew Section(iSection);
    }
  }

  return nullptr;
}

//////////////////////////////////////////////////////////////////////////

UserDefined::UserDefined(IUserDefined *iUserDefined) : Section (iUserDefined)
{
  this->iUserDefined = iUserDefined;
}

String^ UserDefined::header()
{
  return gcnew String(iUserDefined->header()->latin1());
}

//////////////////////////////////////////////////////////////////////////

SectionIterator::SectionIterator(ISectionIterator * iSectionIterator)
{
  this->iSectionIterator = iSectionIterator;
}

SectionIterator::~SectionIterator()
{
  this->!SectionIterator();
}

SectionIterator::!SectionIterator()
{
  release();
}

void SectionIterator::toFirst()
{
  iSectionIterator->toFirst();
}

void SectionIterator::toLast()
{
  iSectionIterator->toLast();
}

void SectionIterator::toNext()
{
  iSectionIterator->toNext();
}

void SectionIterator::toPrev()
{
  iSectionIterator->toPrev();
}

Section^ SectionIterator::current()
{
  return Section::Create(iSectionIterator->current());
}

void SectionIterator::release()
{
  if (iSectionIterator != nullptr)
  {
    iSectionIterator->release();
    iSectionIterator = nullptr;
  }
}