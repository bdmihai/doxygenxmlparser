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

#include "LinkedText.h"

using namespace Doxygen::XMLParser;

LinkedText::LinkedText(ILinkedText *iLinkedText)
{
  this->iLinkedText = iLinkedText;
}

LinkedText::Kind LinkedText::kind()
{
  return (LinkedText::Kind)iLinkedText->kind();
}

LinkedText^ LinkedText::Create(ILinkedText *iLinkedText)
{
  if (iLinkedText == nullptr)
    return nullptr;

  switch (iLinkedText->kind())
  {
  case ILinkedText::Kind_Text:
    {
      return gcnew LT_Text(dynamic_cast<ILT_Text*>(iLinkedText));
    }
  case ILinkedText::Kind_Ref:
    {
      return gcnew LT_Ref(dynamic_cast<ILT_Ref*>(iLinkedText));
    }
  }

  return nullptr;
}

//////////////////////////////////////////////////////////////////////////

LT_Text::LT_Text(ILT_Text *iLT_Text) : LinkedText(iLT_Text)
{
  this->iLT_Text = iLT_Text;
}

String^ LT_Text::text()
{
  return gcnew String(iLT_Text->text()->latin1());
}

//////////////////////////////////////////////////////////////////////////

LT_Ref::LT_Ref(ILT_Ref *iLT_Ref) : LinkedText(iLT_Ref)
{
  this->iLT_Ref = iLT_Ref;
}

String^ LT_Ref::id()
{
  return gcnew String(iLT_Ref->id()->latin1());
}

LT_Ref::TargetKind LT_Ref::targetKind()
{
  return (LT_Ref::TargetKind)iLT_Ref->targetKind();
}

String^ LT_Ref::external()
{
  return gcnew String(iLT_Ref->external()->latin1());
}

String^ LT_Ref::text()
{
  return gcnew String(iLT_Ref->text()->latin1());
}

//////////////////////////////////////////////////////////////////////////

LinkedTextIterator::LinkedTextIterator(ILinkedTextIterator * iLinkedTextIterator)
{
  this->iLinkedTextIterator = iLinkedTextIterator;
}

LinkedTextIterator::~LinkedTextIterator()
{
  this->!LinkedTextIterator();
}

LinkedTextIterator::!LinkedTextIterator()
{
  release();
}

void LinkedTextIterator::toFirst()
{
  iLinkedTextIterator->toFirst();
}

void LinkedTextIterator::toLast()
{
  iLinkedTextIterator->toLast();
}

void LinkedTextIterator::toNext()
{
  iLinkedTextIterator->toNext();
}

void LinkedTextIterator::toPrev()
{
  iLinkedTextIterator->toPrev();
}

LinkedText^ LinkedTextIterator::current()
{
  return LinkedText::Create(iLinkedTextIterator->current());
}

void LinkedTextIterator::release()
{
  if (iLinkedTextIterator != nullptr)
  {
    iLinkedTextIterator->release();
    iLinkedTextIterator = nullptr;
  }
}