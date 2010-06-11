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

#include "Doc.h"

using namespace Doxygen::XMLParser;

Doc::Doc(IDoc *iDoc)
{
  this->iDoc = iDoc;
}

Doc::Kind Doc::kind()
{
  return (Doc::Kind)iDoc->kind();
}

Doc^ Doc::Create (IDoc* iDoc)
{
  if (iDoc == nullptr)
    return nullptr;

  switch (iDoc->kind())
  {
  case IDoc::Para               :{return gcnew DocPara(dynamic_cast<IDocPara*>(iDoc));}
  case IDoc::Text               :{return gcnew DocText(dynamic_cast<IDocText*>(iDoc));}
  case IDoc::MarkupModifier     :{return gcnew DocMarkupModifier(dynamic_cast<IDocMarkupModifier*>(iDoc));}
  case IDoc::ItemizedList       :{return gcnew DocItemizedList(dynamic_cast<IDocItemizedList*>(iDoc));}
  case IDoc::OrderedList        :{return gcnew DocOrderedList(dynamic_cast<IDocOrderedList*>(iDoc));}
  case IDoc::ListItem           :{return gcnew DocListItem(dynamic_cast<IDocListItem*>(iDoc));}
  case IDoc::ParameterList      :{return gcnew DocParameterList(dynamic_cast<IDocParameterList*>(iDoc));}
  case IDoc::Parameter          :{return gcnew DocParameter(dynamic_cast<IDocParameter*>(iDoc));}
  case IDoc::SimpleSect         :{return gcnew DocSimpleSect(dynamic_cast<IDocSimpleSect*>(iDoc));}
  case IDoc::Title              :{return gcnew DocTitle(dynamic_cast<IDocTitle*>(iDoc));}
  case IDoc::Ref                :{return gcnew DocRef(dynamic_cast<IDocRef*>(iDoc));}
  case IDoc::VariableList       :{return gcnew DocVariableList(dynamic_cast<IDocVariableList*>(iDoc));}
  case IDoc::VariableListEntry  :{return gcnew DocVariableListEntry(dynamic_cast<IDocVariableListEntry*>(iDoc));}
  case IDoc::HRuler             :{return gcnew DocHRuler(dynamic_cast<IDocHRuler*>(iDoc));}
  case IDoc::LineBreak          :{return gcnew DocLineBreak(dynamic_cast<IDocLineBreak*>(iDoc));}
  case IDoc::ULink              :{return gcnew DocULink(dynamic_cast<IDocULink*>(iDoc));}
  case IDoc::EMail              :{return gcnew DocEMail(dynamic_cast<IDocEMail*>(iDoc));}
  case IDoc::Link               :{return gcnew DocLink(dynamic_cast<IDocLink*>(iDoc));}
  case IDoc::ProgramListing     :{return gcnew DocProgramListing(dynamic_cast<IDocProgramListing*>(iDoc));}
  case IDoc::CodeLine           :{return gcnew DocCodeLine(dynamic_cast<IDocCodeLine*>(iDoc));}
  case IDoc::Highlight          :{return gcnew DocHighlight(dynamic_cast<IDocHighlight*>(iDoc));}
  case IDoc::Formula            :{return gcnew DocFormula(dynamic_cast<IDocFormula*>(iDoc));}
  case IDoc::Image              :{return gcnew DocImage(dynamic_cast<IDocImage*>(iDoc));}
  case IDoc::DotFile            :{return gcnew DocDotFile(dynamic_cast<IDocDotFile*>(iDoc));}
  case IDoc::IndexEntry         :{return gcnew DocIndexEntry(dynamic_cast<IDocIndexEntry*>(iDoc));}
  case IDoc::Table              :{return gcnew DocTable(dynamic_cast<IDocTable*>(iDoc));}
  case IDoc::Row                :{return gcnew DocRow(dynamic_cast<IDocRow*>(iDoc));}
  case IDoc::Entry              :{return gcnew DocEntry(dynamic_cast<IDocEntry*>(iDoc));}
  case IDoc::Section            :{return gcnew DocSection(dynamic_cast<IDocSection*>(iDoc));}
  case IDoc::Verbatim           :{return gcnew DocVerbatim(dynamic_cast<IDocVerbatim*>(iDoc));}
  case IDoc::Copy               :{return gcnew DocCopy(dynamic_cast<IDocCopy*>(iDoc));}
  case IDoc::TocList            :{return gcnew DocTocList(dynamic_cast<IDocTocList*>(iDoc));}
  case IDoc::TocItem            :{return gcnew DocTocItem(dynamic_cast<IDocTocItem*>(iDoc));}
  case IDoc::Anchor             :{return gcnew DocAnchor(dynamic_cast<IDocAnchor*>(iDoc));}
  case IDoc::Symbol             :{return gcnew DocSymbol(dynamic_cast<IDocSymbol*>(iDoc));}
  case IDoc::Internal           :{return gcnew DocInternal(dynamic_cast<IDocInternal*>(iDoc));}
  case IDoc::Root               :{return gcnew DocRoot(dynamic_cast<IDocRoot*>(iDoc));}
  case IDoc::ParameterItem      :{return gcnew DocParameterItem(dynamic_cast<IDocParameterItem*>(iDoc));}
  }

  return nullptr;
}

//////////////////////////////////////////////////////////////////////////

DocIterator::DocIterator(IDocIterator * iDocIterator)
{
  this->iDocIterator = iDocIterator;
}

DocIterator::~DocIterator()
{
  this->!DocIterator();
}

DocIterator::!DocIterator()
{
  release();
}

void DocIterator::toFirst()
{
  iDocIterator->toFirst();
}

void DocIterator::toLast()
{
  iDocIterator->toLast();
}

void DocIterator::toNext()
{
  iDocIterator->toNext();
}

void DocIterator::toPrev()
{
  iDocIterator->toPrev();
}

Doc^ DocIterator::current()
{
  return Doc::Create(iDocIterator->current());
}

void DocIterator::release()
{
  if (iDocIterator != nullptr)
  {
    iDocIterator->release();
    iDocIterator = nullptr;
  }
}

//////////////////////////////////////////////////////////////////////////

DocPara::DocPara(IDocPara* iDocPara) : Doc(iDocPara)
{
  this->iDocPara = iDocPara;
}

DocIterator^ DocPara::contents()
{
  return gcnew DocIterator(iDocPara->contents());
}

//////////////////////////////////////////////////////////////////////////

DocText::DocText(IDocText* iDocText) : Doc(iDocText)
{
  this->iDocText = iDocText;
}

String^ DocText::text()
{
  return gcnew String(iDocText->text()->latin1());
}

int DocText::markup()
{
  return iDocText->markup();
}

int DocText::headingLevel()
{
  return iDocText->headingLevel();
}

//////////////////////////////////////////////////////////////////////////

DocMarkupModifier::DocMarkupModifier(IDocMarkupModifier* iDocMarkupModifier)
  : Doc(iDocMarkupModifier)
{
  this->iDocMarkupModifier = iDocMarkupModifier;
}

bool DocMarkupModifier::enabled()
{
  return iDocMarkupModifier->enabled();
}

int DocMarkupModifier::markup()
{
  return iDocMarkupModifier->markup();
}

int DocMarkupModifier::headingLevel()
{
  return iDocMarkupModifier->headingLevel();
}

//////////////////////////////////////////////////////////////////////////

DocItemizedList::DocItemizedList(IDocItemizedList* iDocItemizedList)
  : Doc (iDocItemizedList)
{
  this->iDocItemizedList = iDocItemizedList;
}

DocIterator^ DocItemizedList::elements()
{
  return gcnew DocIterator(iDocItemizedList->elements());
}

//////////////////////////////////////////////////////////////////////////

DocOrderedList::DocOrderedList(IDocOrderedList* iDocOrderedList) 
  : Doc (iDocOrderedList)
{
  this->iDocOrderedList = iDocOrderedList;
}

DocIterator^ DocOrderedList::elements()
{
  return gcnew DocIterator(iDocOrderedList->elements());
}

//////////////////////////////////////////////////////////////////////////

DocListItem::DocListItem(IDocListItem* iDocListItem) 
  : Doc (iDocListItem)
{
  this->iDocListItem = iDocListItem;
}

DocIterator^ DocListItem::contents()
{
  return gcnew DocIterator(iDocListItem->contents());
}

//////////////////////////////////////////////////////////////////////////

DocParameterList::DocParameterList(IDocParameterList* iDocParameterList)
  : Doc (iDocParameterList)
{
  this->iDocParameterList = iDocParameterList;
}

DocParameterList::Types DocParameterList::sectType()
{
  return (DocParameterList::Types) iDocParameterList->sectType();
}

DocIterator^ DocParameterList::params()
{
  return gcnew DocIterator(iDocParameterList->params());
}

//////////////////////////////////////////////////////////////////////////

DocParameterItem::DocParameterItem(IDocParameterItem* iDocParameterItem)
  : Doc (iDocParameterItem)
{
  this->iDocParameterItem = iDocParameterItem;
}

DocIterator^ DocParameterItem::paramNames()
{
  return gcnew DocIterator(iDocParameterItem->paramNames());
}
    
DocPara^ DocParameterItem::description()
{
  return gcnew DocPara(iDocParameterItem->description());
}

//////////////////////////////////////////////////////////////////////////

DocParameter::DocParameter(IDocParameter* iDocParameter)
  : Doc (iDocParameter)
{
  this->iDocParameter = iDocParameter;
}

String^ DocParameter::name()
{
  return gcnew String(iDocParameter->name()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocTitle::DocTitle(IDocTitle* iDocTitle)
  : Doc (iDocTitle)
{
  this->iDocTitle = iDocTitle;
}

DocIterator^ DocTitle::title()
{
  return gcnew DocIterator(iDocTitle->title());
}

//////////////////////////////////////////////////////////////////////////

DocSimpleSect::DocSimpleSect(IDocSimpleSect* iDocSimpleSect)
  : Doc (iDocSimpleSect)
{
  this->iDocSimpleSect = iDocSimpleSect;
}

DocSimpleSect::Types DocSimpleSect::type()
{
  return (DocSimpleSect::Types)iDocSimpleSect->type();
}

String^ DocSimpleSect::typeString()
{
  return gcnew String(iDocSimpleSect->typeString()->latin1());
}

DocTitle^ DocSimpleSect::title()
{
  if (iDocSimpleSect->title() == nullptr)
    return nullptr;

  return gcnew DocTitle(iDocSimpleSect->title());
}

DocPara^ DocSimpleSect::description()
{
  return gcnew DocPara(iDocSimpleSect->description());
}

//////////////////////////////////////////////////////////////////////////

DocRef::DocRef(IDocRef* iDocRef)
  : Doc (iDocRef)
{
  this->iDocRef = iDocRef;
}

String^ DocRef::refId()
{
  return gcnew String(iDocRef->refId()->latin1());
}

DocRef::TargetKind DocRef::targetKind()
{
  return (DocRef::TargetKind)iDocRef->targetKind();
}

String^ DocRef::external()
{
  return gcnew String(iDocRef->external()->latin1());
}

String^ DocRef::text()
{
  return gcnew String(iDocRef->text()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocVariableList::DocVariableList(IDocVariableList* iDocVariableList)
  : Doc (iDocVariableList)
{
  this->iDocVariableList = iDocVariableList;
}

DocIterator^ DocVariableList::entries()
{
  return gcnew DocIterator(iDocVariableList->entries());
}

//////////////////////////////////////////////////////////////////////////

DocVariableListEntry::DocVariableListEntry(IDocVariableListEntry* iDocVariableListEntry)
  : Doc (iDocVariableListEntry)
{
  this->iDocVariableListEntry = iDocVariableListEntry;
}

LinkedTextIterator^ DocVariableListEntry::term()
{
  return gcnew LinkedTextIterator(iDocVariableListEntry->term());
}

DocPara^ DocVariableListEntry::description()
{
  return gcnew DocPara(iDocVariableListEntry->description());
}

//////////////////////////////////////////////////////////////////////////

DocHRuler::DocHRuler(IDocHRuler* iDocHRuler)
  : Doc (iDocHRuler)
{

}

//////////////////////////////////////////////////////////////////////////

DocLineBreak::DocLineBreak(IDocLineBreak* iDocLineBreak)
  : Doc (iDocLineBreak)
{

}

//////////////////////////////////////////////////////////////////////////

DocULink::DocULink(IDocULink* iDocULink)
  : Doc (iDocULink)
{
  this->iDocULink = iDocULink;
}

String^ DocULink::url()
{
  return gcnew String(iDocULink->url()->latin1());
}

String^ DocULink::text()
{
  return gcnew String(iDocULink->text()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocEMail::DocEMail(IDocEMail* iDocEMail)
  : Doc (iDocEMail)
{
  this->iDocEMail = iDocEMail;
}

String^ DocEMail::address()
{
  return gcnew String(iDocEMail->address()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocLink::DocLink(IDocLink* iDocLink)
  : Doc (iDocLink)
{
  this->iDocLink = iDocLink;
}

String^ DocLink::refId()
{
  return gcnew String(iDocLink->refId()->latin1());
}

String^ DocLink::text()
{
  return gcnew String(iDocLink->text()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocProgramListing::DocProgramListing(IDocProgramListing* iDocProgramListing)
  : Doc (iDocProgramListing)
{
  this->iDocProgramListing = iDocProgramListing;
}

DocIterator^ DocProgramListing::codeLines()
{
  return gcnew DocIterator(iDocProgramListing->codeLines());
}

//////////////////////////////////////////////////////////////////////////

DocCodeLine::DocCodeLine(IDocCodeLine* iDocCodeLine)
  : Doc (iDocCodeLine)
{
  this->iDocCodeLine = iDocCodeLine;
}

int DocCodeLine::lineNumber()
{
  return iDocCodeLine->lineNumber();
}

String^ DocCodeLine::refId()
{
  return gcnew String(iDocCodeLine->refId()->latin1());
}

DocIterator^ DocCodeLine::codeElements()
{
  return gcnew DocIterator(iDocCodeLine->codeElements());
}

//////////////////////////////////////////////////////////////////////////

DocHighlight::DocHighlight(IDocHighlight* iDocHighlight)
  : Doc (iDocHighlight)
{
  this->iDocHighlight = iDocHighlight;
}

DocHighlight::HighlightKind DocHighlight::highlightKind()
{
  return (DocHighlight::HighlightKind)iDocHighlight->highlightKind();
}

DocIterator^ DocHighlight::codeElements()
{
  return gcnew DocIterator(iDocHighlight->codeElements());
}

//////////////////////////////////////////////////////////////////////////

DocFormula::DocFormula(IDocFormula* iDocFormula)
  : Doc (iDocFormula)
{
  this->iDocFormula = iDocFormula;
}

String^ DocFormula::id()
{
  return gcnew String(iDocFormula->id()->latin1());
}

String^ DocFormula::text()
{
  return gcnew String(iDocFormula->text()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocImage::DocImage(IDocImage* iDocImage)
  : Doc (iDocImage)
{
  this->iDocImage = iDocImage;
}

String^ DocImage::name()
{
  return gcnew String(iDocImage->name()->latin1());
}

String^ DocImage::caption()
{
  return gcnew String(iDocImage->caption()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocDotFile::DocDotFile(IDocDotFile* iDocDotFile)
  : Doc (iDocDotFile)
{
  this->iDocDotFile = iDocDotFile;
}

String^ DocDotFile::name()
{
  return gcnew String(iDocDotFile->name()->latin1());
}

String^ DocDotFile::caption()
{
  return gcnew String(iDocDotFile->caption()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocIndexEntry::DocIndexEntry(IDocIndexEntry* iDocIndexEntry)
  : Doc (iDocIndexEntry)
{
  this->iDocIndexEntry = iDocIndexEntry;
}

String^ DocIndexEntry::primary()
{
  return gcnew String(iDocIndexEntry->primary()->latin1());
}

String^ DocIndexEntry::secondary()
{
  return gcnew String(iDocIndexEntry->secondary()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocTable::DocTable(IDocTable* iDocTable)
  : Doc (iDocTable)
{
  this->iDocTable = iDocTable;
}

DocIterator^ DocTable::rows()
{
  return gcnew DocIterator(iDocTable->rows());
}

int DocTable::numColumns()
{
  return iDocTable->numColumns();
}

String^ DocTable::caption()
{
  return gcnew String(iDocTable->caption()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocRow::DocRow(IDocRow* iDocRow)
  : Doc (iDocRow)
{
  this->iDocRow = iDocRow;
}

DocIterator^ DocRow::entries()
{
  return gcnew DocIterator(iDocRow->entries());
}

//////////////////////////////////////////////////////////////////////////

DocEntry::DocEntry(IDocEntry* iDocEntry)
  : Doc (iDocEntry)
{
  this->iDocEntry = iDocEntry;
}

DocIterator^ DocEntry::contents()
{
  return gcnew DocIterator(iDocEntry->contents());
}

//////////////////////////////////////////////////////////////////////////

DocInternal::DocInternal(IDocInternal* iDocInternal)
  : Doc (iDocInternal)
{
  this->iDocInternal = iDocInternal;
}

DocIterator^ DocInternal::paragraphs()
{
  return gcnew DocIterator(iDocInternal->paragraphs());
}

DocIterator^ DocInternal::subSections()
{
  return gcnew DocIterator(iDocInternal->subSections());
}

//////////////////////////////////////////////////////////////////////////

DocSection::DocSection(IDocSection* iDocSection)
  : Doc (iDocSection)
{
  this->iDocSection = iDocSection;
}

String^ DocSection::id()
{
  return gcnew String(iDocSection->id()->latin1());
}
 
int DocSection::level()
{
  return iDocSection->level();
}

DocTitle^ DocSection::title()
{
  return gcnew DocTitle(iDocSection->title());
}

DocIterator^ DocSection::paragraphs()
{
  return gcnew DocIterator(iDocSection->paragraphs());
}

DocIterator^ DocSection::subSections()
{
  return gcnew DocIterator(iDocSection->subSections());
}

DocInternal^ DocSection::internal()
{
  return gcnew DocInternal(iDocSection->internal());
}

//////////////////////////////////////////////////////////////////////////

DocTocList::DocTocList(IDocTocList* iDocTocList)
  : Doc (iDocTocList)
{
  this->iDocTocList = iDocTocList;
}

DocIterator^ DocTocList::elements()
{
  return gcnew DocIterator(iDocTocList->elements());
}

//////////////////////////////////////////////////////////////////////////

DocTocItem::DocTocItem(IDocTocItem* iDocTocItem)
  : Doc (iDocTocItem)
{
  this->iDocTocItem = iDocTocItem;
}

String^ DocTocItem::id()
{
  return gcnew String(iDocTocItem->id()->latin1());
}

String^ DocTocItem::title()
{
  return gcnew String(iDocTocItem->title()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocCopy::DocCopy(IDocCopy* iDocCopy)
  : Doc (iDocCopy)
{
  this->iDocCopy = iDocCopy;
}

DocIterator^ DocCopy::contents()
{
  return gcnew DocIterator(iDocCopy->contents());
}

//////////////////////////////////////////////////////////////////////////

DocVerbatim::DocVerbatim(IDocVerbatim* iDocVerbatim)
  : Doc (iDocVerbatim)
{
  this->iDocVerbatim = iDocVerbatim;
}

String^ DocVerbatim::text()
{
  return gcnew String(iDocVerbatim->text()->latin1());
}

DocVerbatim::Types DocVerbatim::type()
{
  return (DocVerbatim::Types)iDocVerbatim->type();
}

//////////////////////////////////////////////////////////////////////////

DocAnchor::DocAnchor(IDocAnchor* iDocAnchor)
  : Doc (iDocAnchor)
{
  this->iDocAnchor = iDocAnchor;
}

String^ DocAnchor::id()
{
  return gcnew String(iDocAnchor->id()->latin1());
}

//////////////////////////////////////////////////////////////////////////

DocSymbol::DocSymbol(IDocSymbol* iDocSymbol)
  : Doc (iDocSymbol)
{
  this->iDocSymbol = iDocSymbol;
}

DocSymbol::Types DocSymbol::type()
{
  return (DocSymbol::Types)iDocSymbol->type();
}

String^ DocSymbol::typeString()
{
  return gcnew String(iDocSymbol->typeString()->latin1());
}

char DocSymbol::letter()
{
  return iDocSymbol->letter();
}

//////////////////////////////////////////////////////////////////////////

DocRoot::DocRoot(IDocRoot* iDocRoot)
  : Doc (iDocRoot)
{
  this->iDocRoot = iDocRoot;
}

DocIterator^ DocRoot::contents()
{
  return gcnew DocIterator(iDocRoot->contents());
}

DocInternal^ DocRoot::internal()
{
  return gcnew DocInternal(iDocRoot->internal());
}
