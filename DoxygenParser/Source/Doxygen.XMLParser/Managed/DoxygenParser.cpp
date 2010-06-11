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

#include "DoxygenParser.h"
#include "StringConvertor.h"

using namespace Doxygen::XMLParser::StringUtilities;
using namespace Doxygen::XMLParser;

DoxygenParser::DoxygenParser(void)
{
  iDoxygen = createObjectModel();
}

DoxygenParser::~DoxygenParser(void)
{
  this->!DoxygenParser();
}

DoxygenParser::!DoxygenParser(void)
{
  release();
}

CompoundIterator^ DoxygenParser::compounds()
{
  return gcnew CompoundIterator (iDoxygen->compounds());
}

Compound^ DoxygenParser::compoundById(String^ id)
{
  StringConvertor sc(id);
  return Compound::Create (iDoxygen->compoundById(sc.NativeCharPtr));
}

Compound^ DoxygenParser::compoundByName(String^ name)
{
  StringConvertor sc(name);
  return Compound::Create (iDoxygen->compoundById(sc.NativeCharPtr));
}

Compound^ DoxygenParser::memberById(String^ id)
{
  StringConvertor sc(id);
  return Compound::Create (iDoxygen->compoundById(sc.NativeCharPtr));
}

Compound^ DoxygenParser::memberByName(String^ name)
{
  StringConvertor sc(name);
  return Compound::Create (iDoxygen->compoundById(sc.NativeCharPtr));
}

void DoxygenParser::release()
{
  if (iDoxygen != nullptr)
  {
    iDoxygen->release();
    iDoxygen = nullptr;
  }
}

void DoxygenParser::setDebugLevel(int level)
{
  iDoxygen->setDebugLevel(level);
}

bool DoxygenParser::readXMLDir(String^ xmlDirName)
{
  StringConvertor sc(xmlDirName);
  return iDoxygen->readXMLDir(sc.NativeCharPtr);
}
