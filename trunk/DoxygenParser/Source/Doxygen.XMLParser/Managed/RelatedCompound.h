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

    public ref class RelatedCompound
    {
    internal:
      RelatedCompound (IRelatedCompound* iRelatedCompound);

    public:
      enum class Protection 
      { 
        Public, 
        Protected, 
        Private 
      };

      enum class Kind 
      { 
        Normal, 
        Virtual 
      };

      Compound^ compound();
      Protection protection();
      Kind kind();
      String^ name();

    private:
      IRelatedCompound* iRelatedCompound;

    };

    public ref class RelatedCompoundIterator
    {
    internal:
      RelatedCompoundIterator(IRelatedCompoundIterator * iRelatedCompoundIterator);

    public:
      ~RelatedCompoundIterator();
      !RelatedCompoundIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      RelatedCompound^ current();
      void release();

    private:
      IRelatedCompoundIterator* iRelatedCompoundIterator;
    };
  }
}
