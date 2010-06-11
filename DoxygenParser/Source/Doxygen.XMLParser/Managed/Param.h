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
#include "LinkedText.h"
#include "Doc.h"

using namespace System;

namespace Doxygen
{ 
  namespace XMLParser 
  {

    public ref class Param
    {
    internal:
      Param(IParam *iParam);

    public:

      LinkedTextIterator^ type();
      String^ declarationName();
      String^ definitionName();
      String^ attrib();
      String^ arraySpecifier();
      LinkedTextIterator^ defaultValue();
      DocRoot^ briefDescription();

    private:
      IParam * iParam;
    };

    public ref class ParamIterator
    {
    internal:
      ParamIterator(IParamIterator* iParamIterator);

    public:
      ~ParamIterator();
      !ParamIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      Param^ current();
      void release();

    private:
      IParamIterator* iParamIterator;
    };
  }
}
