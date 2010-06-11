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

using namespace System;

namespace Doxygen
{ 
  namespace XMLParser 
  {

    public ref class MemberReference
    {
    internal:
      MemberReference (IMemberReference* iMemberReference);

    public:
      Member^ member();
      String^ name();
      String^ scope();
      String^ protection();
      String^ virtualness();
      String^ ambiguityScope();

    private:
      IMemberReference* iMemberReference;

    };

    public ref class MemberReferenceIterator
    {
    internal:
      MemberReferenceIterator(IMemberReferenceIterator * iMemberReferenceIterator);

    public:
      ~MemberReferenceIterator();
      !MemberReferenceIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      MemberReference^ current();
      void release();

    private:
      IMemberReferenceIterator* iMemberReferenceIterator;
    };
  }
}
