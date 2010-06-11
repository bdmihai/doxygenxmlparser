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

#include "Param.h"

using namespace Doxygen::XMLParser;

Param::Param(IParam *iParam)
{
  this->iParam = iParam;
}

LinkedTextIterator^ Param::type()
{
  return gcnew LinkedTextIterator(iParam->type());
}

String^ Param::declarationName()
{
  return gcnew String(iParam->declarationName()->latin1());
}

String^ Param::definitionName()
{
  return gcnew String(iParam->definitionName()->latin1());
}

String^ Param::attrib()
{
  return gcnew String(iParam->attrib()->latin1());
}

String^ Param::arraySpecifier()
{
  return gcnew String(iParam->arraySpecifier()->latin1());
}

LinkedTextIterator^ Param::defaultValue()
{
  return gcnew LinkedTextIterator(iParam->defaultValue());
}

DocRoot^ Param::briefDescription()
{
  if (iParam->briefDescription() == nullptr)
    return nullptr;

  return gcnew DocRoot(iParam->briefDescription());
}

//////////////////////////////////////////////////////////////////////////

ParamIterator::ParamIterator(IParamIterator * iParamIterator)
{
  this->iParamIterator = iParamIterator;
}

ParamIterator::~ParamIterator()
{
  this->!ParamIterator();
}

ParamIterator::!ParamIterator()
{
  release();
}

void ParamIterator::toFirst()
{
  iParamIterator->toFirst();
}

void ParamIterator::toLast()
{
  iParamIterator->toLast();
}

void ParamIterator::toNext()
{
  iParamIterator->toNext();
}

void ParamIterator::toPrev()
{
  iParamIterator->toPrev();
}

Param^ ParamIterator::current()
{
  IParam* iParam = iParamIterator->current();

  if (iParam == nullptr)
    return nullptr;

  return gcnew Param(iParam);
}

void ParamIterator::release()
{
  if (iParamIterator != nullptr)
  {
    iParamIterator->release();
    iParamIterator = nullptr;
  }
}
