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

using namespace System;

namespace Doxygen
{ 
  namespace XMLParser 
  {

    public ref class Include 
    {
    internal:
      Include(IInclude *iInclude);

    public:
      String^ name();
      String^ refId();
      bool isLocal();

    private:
      IInclude * iInclude;
    };

    public ref class IncludeIterator
    {
    internal:
      IncludeIterator(IIncludeIterator* iIncludeIterator);

    public:
      ~IncludeIterator();
      !IncludeIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      Include^ current();
      void release();

    private:
      IIncludeIterator* iIncludeIterator;
    };
  }
}
