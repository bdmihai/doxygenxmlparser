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

#include "Compound.h"
#include "Member.h"
#include "RelatedCompound.h"
#include "StringConvertor.h"

using namespace Doxygen::XMLParser::StringUtilities;
using namespace Doxygen::XMLParser;

Compound::Compound(ICompound* compound)
{
  iCompound = compound;
}

String^ Compound::name()
{
  return gcnew String(iCompound->name()->latin1());
}

String^ Compound::id()
{
  return gcnew String(iCompound->id()->latin1());
}

Compound::CompoundKind Compound::kind()
{
  return (Compound::CompoundKind)iCompound->kind();
}

String^ Compound::kindString()
{
  return gcnew String(iCompound->kindString()->latin1());
}

SectionIterator^ Compound::sections()
{
  return gcnew SectionIterator(iCompound->sections());
}

DocRoot^ Compound::briefDescription()
{
  return gcnew DocRoot(iCompound->briefDescription());
}

DocRoot^ Compound::detailedDescription()
{
  return gcnew DocRoot(iCompound->detailedDescription());
}

Member^ Compound::memberById(String^ id)
{
  StringConvertor sc(id);
  return Member::Create (iCompound->memberById(sc.NativeCharPtr));
}

MemberIterator^ Compound::memberByName(String^ name)
{
  StringConvertor sc(name);
  return gcnew MemberIterator (iCompound->memberByName(sc.NativeCharPtr));
}

void Compound::release()
{
  iCompound->release();
}

Compound^ Compound::Create (ICompound* compound)
{
  if (compound == nullptr)
    return nullptr;

  switch (compound->kind())
  {
  case ICompound::Class:
    {
      return gcnew Class(dynamic_cast<IClass*>(compound));
    }
  case ICompound::Struct:
    {
      return gcnew Struct(dynamic_cast<IStruct*>(compound));
    }
  case ICompound::Union:
    {
      return gcnew Union(dynamic_cast<IUnion*>(compound));
    }
  case ICompound::Interface:
    {
      return gcnew Interface(dynamic_cast<IInterface*>(compound));
    }
  case ICompound::Exception:
    {
      return gcnew Exception(dynamic_cast<IException*>(compound));
    }
  case ICompound::Namespace:
    {
      return gcnew Namespace(dynamic_cast<INamespace*>(compound));
    }
  case ICompound::File:
    {
      return gcnew File(dynamic_cast<IFile*>(compound));
    }
  case ICompound::Group:
    {
      return gcnew Group(dynamic_cast<IGroup*>(compound));
    }
  case ICompound::Page:
    {
      return gcnew Page(dynamic_cast<IPage*>(compound));
    }
  }

  return nullptr;
}

//////////////////////////////////////////////////////////////////////////

CompoundIterator::CompoundIterator(ICompoundIterator * iCompoundIterator)
{
  this->iCompoundIterator = iCompoundIterator;
}

CompoundIterator::~CompoundIterator()
{
  this->!CompoundIterator();
}

CompoundIterator::!CompoundIterator()
{
  release();
}

void CompoundIterator::toFirst()
{
  iCompoundIterator->toFirst();
}

void CompoundIterator::toLast()
{
  iCompoundIterator->toLast();
}

void CompoundIterator::toNext()
{
  iCompoundIterator->toNext();
}

void CompoundIterator::toPrev()
{
  iCompoundIterator->toPrev();
}

Compound^ CompoundIterator::current()
{
  return Compound::Create(iCompoundIterator->current());
}

void CompoundIterator::release()
{
  if (iCompoundIterator != nullptr)
  {
    iCompoundIterator->release();
    iCompoundIterator = nullptr;
  }
}

//////////////////////////////////////////////////////////////////////////

Class::Class(IClass *iClass) : Compound (iClass)
{
  this->iClass = iClass;
}

Graph^ Class::inheritanceGraph()
{
  return gcnew Graph(iClass->inheritanceGraph());
}

Graph^ Class::collaborationGraph()
{
  return gcnew Graph(iClass->collaborationGraph());
}

RelatedCompoundIterator^ Class::baseCompounds()
{
  return gcnew RelatedCompoundIterator(iClass->baseCompounds());
}

RelatedCompoundIterator^ Class::derivedCompounds()
{
  return gcnew RelatedCompoundIterator(iClass->derivedCompounds());
}

CompoundIterator^ Class::nestedCompounds()
{
  return gcnew CompoundIterator(iClass->nestedCompounds());
}

ParamIterator^ Class::templateParameters()
{
  return gcnew ParamIterator(iClass->templateParameters());
}

String^ Class::locationFile()
{
  return gcnew String(iClass->locationFile()->latin1());
}

int Class::locationLine()
{
  return iClass->locationLine();
}

String^ Class::locationBodyFile()
{
  return gcnew String(iClass->locationBodyFile()->latin1());
}

int Class::locationBodyStartLine()
{
  return iClass->locationBodyStartLine();
}

int Class::locationBodyEndLine()
{
  return iClass->locationBodyEndLine();
}


//////////////////////////////////////////////////////////////////////////

Struct::Struct(IStruct *iStruct) : Compound (iStruct)
{
  this->iStruct = iStruct;
}

CompoundIterator^ Struct::nestedCompounds()
{
  return gcnew CompoundIterator(iStruct->nestedCompounds());
}

RelatedCompoundIterator^ Struct::baseCompounds()
{
  return gcnew RelatedCompoundIterator(iStruct->baseCompounds());
}

RelatedCompoundIterator^ Struct::derivedCompounds()
{
  return gcnew RelatedCompoundIterator(iStruct->derivedCompounds());
}

String^ Struct::locationFile()
{
  return gcnew String(iStruct->locationFile()->latin1());
}

int Struct::locationLine()
{
  return iStruct->locationLine();
}

int Struct::locationBodyStartLine()
{
  return iStruct->locationBodyStartLine();
}

int Struct::locationBodyEndLine()
{
  return iStruct->locationBodyEndLine();
}

//////////////////////////////////////////////////////////////////////////

Union::Union(IUnion *iUnion) : Compound (iUnion)
{
  this->iUnion = iUnion;
}

CompoundIterator^ Union::nestedCompounds()
{
  return gcnew CompoundIterator(iUnion->nestedCompounds());
}

//////////////////////////////////////////////////////////////////////////

Interface::Interface(IInterface *iInterface) : Compound (iInterface)
{
  this->iInterface = iInterface;
}

RelatedCompoundIterator^ Interface::baseCompounds()
{
  return gcnew RelatedCompoundIterator(iInterface->baseCompounds());
}

RelatedCompoundIterator^ Interface::derivedCompounds()
{
  return gcnew RelatedCompoundIterator(iInterface->derivedCompounds());
}

//////////////////////////////////////////////////////////////////////////

Doxygen::XMLParser::Exception::Exception(IException *iException) : Compound (iException)
{

}

//////////////////////////////////////////////////////////////////////////

Namespace::Namespace(INamespace *iNamespace) : Compound (iNamespace)
{
  this->iNamespace = iNamespace;
}

CompoundIterator^ Namespace::nestedCompounds()
{
  return gcnew CompoundIterator(iNamespace->nestedCompounds());
}

//////////////////////////////////////////////////////////////////////////

File::File(IFile *iFile) : Compound (iFile)
{
  this->iFile = iFile;
}

Graph^ File::includeDependencyGraph()
{
  return gcnew Graph(iFile->includeDependencyGraph());
}

Graph^ File::includedByDependencyGraph()
{
  return gcnew Graph(iFile->includedByDependencyGraph());
}

DocProgramListing^ File::source()
{
  return gcnew DocProgramListing(iFile->source());
}

CompoundIterator^ File::nestedCompounds()
{
  return gcnew CompoundIterator(iFile->nestedCompounds());
}

IncludeIterator^ File::includes()
{
  return gcnew IncludeIterator(iFile->includes());
}

IncludeIterator^ File::includedBy()
{
  return gcnew IncludeIterator(iFile->includedBy());
}


//////////////////////////////////////////////////////////////////////////

Group::Group(IGroup *iGroup) : Compound (iGroup)
{
  this->iGroup = iGroup;
}

CompoundIterator^ Group::nestedCompounds()
{
  return gcnew CompoundIterator(iGroup->nestedCompounds());
}

//////////////////////////////////////////////////////////////////////////

Page::Page(IPage *iPage) : Compound (iPage)
{
  this->iPage = iPage;
}

DocTitle^ Page::title()
{
  return gcnew DocTitle((IDocTitle*)iPage->title());
}