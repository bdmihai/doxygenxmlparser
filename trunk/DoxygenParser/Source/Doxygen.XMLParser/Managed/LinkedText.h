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

    public ref class LinkedText
    {
    internal:
      LinkedText(ILinkedText *iLinkedText);

      static LinkedText^ Create(ILinkedText *iLinkedText);

    public:
      enum class Kind 
      { 
        Kind_Text, 
        Kind_Ref 
      };

      Kind kind();

    private:
      ILinkedText * iLinkedText;
    };

    public ref class LT_Text : public LinkedText
    {
    internal:
      LT_Text(ILT_Text *iLT_Text);

    public:
      String^ text();

    private:
      ILT_Text * iLT_Text;
    };

    public ref class LT_Ref : public LinkedText
    {
    internal:
      LT_Ref(ILT_Ref *iLT_Ref);

    public:
      enum class TargetKind 
      { 
        Member, 
        Compound 
      };

      String^ id();
      TargetKind targetKind();
      String^ external();
      String^ text();

    private:
      ILT_Ref *iLT_Ref;
    };

    public ref class LinkedTextIterator
    {
    internal:
      LinkedTextIterator(ILinkedTextIterator* iLinkedTextIterator);

    public:
      ~LinkedTextIterator();
      !LinkedTextIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      LinkedText^ current();
      void release();

    private:
      ILinkedTextIterator* iLinkedTextIterator;
    };
  }
}
