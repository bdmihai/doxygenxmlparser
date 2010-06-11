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

using namespace System;

namespace Doxygen
{ 
  namespace XMLParser 
  {

    public ref class Doc
    {
    internal:
      Doc(IDoc* iDoc);

      static Doc^ Create (IDoc* iDoc); 

    public:
      enum class Markup 
      { 
        Normal         = 0x000,
        Bold           = 0x001,
        Emphasis       = 0x002,
        ComputerOutput = 0x004,
        Subscript      = 0x008,
        Superscript    = 0x010,
        SmallFont      = 0x020,
        Center         = 0x040,
        Preformatted   = 0x080,
        Heading        = 0x100
      };

      enum class Kind 
      { 
        Invalid = 0,        //  0
        Para,               //  1 -> IDocPara
        Text,               //  2 -> IDocText
        MarkupModifier,     //  3 -> IDocMarkupModifier
        ItemizedList,       //  4 -> IDocItemizedList
        OrderedList,        //  5 -> IDocOrderedList
        ListItem,           //  6 -> IDocListItem
        ParameterList,      //  7 -> IDocParameterList
        Parameter,          //  8 -> IDocParameter
        SimpleSect,         //  9 -> IDocSimpleSect
        Title,              // 10 -> IDocTitle
        Ref,                // 11 -> IDocRef
        VariableList,       // 12 -> IDocVariableList
        VariableListEntry,  // 13 -> IDocVariableListEntry
        HRuler,             // 14 -> IDocHRuler
        LineBreak,          // 15 -> IDocLineBreak
        ULink,              // 16 -> IDocULink
        EMail,              // 17 -> IDocEMail
        Link,               // 18 -> IDocLink
        ProgramListing,     // 19 -> IDocProgramListing
        CodeLine,           // 20 -> IDocCodeLine
        Highlight,          // 21 -> IDocHighlight
        Formula,            // 22 -> IDocFormula
        Image,              // 23 -> IDocImage
        DotFile,            // 24 -> IDocDotFile
        IndexEntry,         // 25 -> IDocIndexEntry
        Table,              // 26 -> IDocTable
        Row,                // 27 -> IDocRow
        Entry,              // 28 -> IDocEntry
        Section,            // 29 -> IDocSection
        Verbatim,           // 30 -> IDocVerbatim
        Copy,               // 31 -> IDocCopy
        TocList,            // 32 -> IDocTocList
        TocItem,            // 33 -> IDocTocItem
        Anchor,             // 34 -> IDocAnchor
        Symbol,             // 35 -> IDocSymbol
        Internal,           // 36 -> IDocInternal
        Root,               // 37 -> IDocRoot
        ParameterItem       // 38 -> IDocParameterItem
      };
      Kind kind();

    private:
      IDoc*  iDoc;
    };

    public ref class DocIterator
    {
    internal:
      DocIterator(IDocIterator * iDocIterator);

    public:
      ~DocIterator();
      !DocIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      Doc^ current();
      void release();

    private:
      IDocIterator* iDocIterator;
    };

    public ref class DocPara : public Doc
    {
    internal:
      DocPara(IDocPara* iDocPara);

    public:
      DocIterator^ contents(); 

    private:
      IDocPara* iDocPara;
    };

    public ref class DocText : public Doc
    {
    internal:
      DocText(IDocText* iDocText);

    public:
      String^ text();
      int markup();
      int headingLevel();

    private:
      IDocText* iDocText;
    };

    public ref class DocMarkupModifier : public Doc
    {
    internal:
      DocMarkupModifier(IDocMarkupModifier* iDocMarkupModifier);

    public:
      bool enabled();
      int markup();
      int headingLevel();

    private:
      IDocMarkupModifier* iDocMarkupModifier;
    };

    public ref class DocItemizedList : public Doc
    {
    internal:
      DocItemizedList(IDocItemizedList* iDocItemizedList);

    public:
      DocIterator^ elements();

    private:
      IDocItemizedList* iDocItemizedList;
    };

    public ref class DocOrderedList : public Doc
    {
    internal:
      DocOrderedList(IDocOrderedList* iDocOrderedList);

    public:
      DocIterator^ elements();

    private:
      IDocOrderedList* iDocOrderedList;
    };

    public ref class DocListItem : public Doc
    {
    internal:
      DocListItem(IDocListItem* iDocListItem);

    public:
      DocIterator^ contents();

    private:
      IDocListItem* iDocListItem;
    };

    public ref class DocParameterList : public Doc
    {
    internal:
      DocParameterList(IDocParameterList* iDocParameterList);

    public:
      enum class Types 
      { 
        Param, 
        RetVal, 
        Exception 
      };

      Types sectType();
      DocIterator^ params();

    private:
      IDocParameterList* iDocParameterList;
    };

    public ref class DocParameterItem : public Doc
    {
    internal:
      DocParameterItem(IDocParameterItem* iDocParameterItem);

    public:
      DocIterator^ paramNames();
      DocPara^ description();

    private:
      IDocParameterItem* iDocParameterItem;
    };

    public ref class DocParameter : public Doc
    {
    internal:
      DocParameter(IDocParameter* iDocParameter);

    public:
      String^  name();

    private:
      IDocParameter* iDocParameter;
    };

    public ref class DocTitle : public Doc
    {
    internal:
      DocTitle(IDocTitle* iDocTitle);

    public:
      DocIterator^ title();

    private:
      IDocTitle* iDocTitle;
    };

    public ref class DocSimpleSect : public Doc
    {
    internal:
      DocSimpleSect(IDocSimpleSect* iDocSimpleSect);

    public:
      enum class Types 
      { Invalid = 0,
        See, 
        Return, 
        Author, 
        Version, 
        Since, 
        Date, 
        Bug, 
        Note,
        Warning, 
        Par, 
        Deprecated, 
        Pre, 
        Post, 
        Invar, 
        Remark, 
        Attention,
        Todo, 
        Test, 
        RCS, 
        EnumValues, 
        Examples
      };
      Types type();
      String^  typeString();
      DocTitle^ title();
      DocPara^ description();

    private:
      IDocSimpleSect* iDocSimpleSect;
    };

    public ref class DocRef : public Doc
    {
    internal:
      DocRef(IDocRef* iDocRef);

    public:
      enum class TargetKind 
      { 
        Member, 
        Compound 
      };

      String^  refId();
      TargetKind targetKind();
      String^  external();
      String^  text();

    private:
      IDocRef* iDocRef;
    };

    public ref class DocVariableList : public Doc
    {
    internal:
      DocVariableList(IDocVariableList* iDocVariableList);

    public:
      DocIterator^ entries();

    private:
      IDocVariableList* iDocVariableList;
    };

    public ref class DocVariableListEntry : public Doc
    {
    internal:
      DocVariableListEntry(IDocVariableListEntry* iDocVariableList);

    public:
      LinkedTextIterator^ term();
      DocPara^ description();

    private:
      IDocVariableListEntry* iDocVariableListEntry;
    };

    public ref class DocHRuler : public Doc
    {
    internal:
      DocHRuler(IDocHRuler* iDocHRuler);
    };

    public ref class DocLineBreak : public Doc
    {
    internal:
      DocLineBreak(IDocLineBreak* iDocLineBreak);
    };

    public ref class DocULink : public Doc
    {
    internal:
      DocULink(IDocULink* iDocULink);

    public:
      String^  url();
      String^  text();

    private:
      IDocULink* iDocULink;
    };

    public ref class DocEMail : public Doc
    {
    internal:
      DocEMail(IDocEMail* iDocEMail);

    public:
      String^  address();

    private:
      IDocEMail* iDocEMail;
    };

    public ref class DocLink : public Doc
    {
    internal:
      DocLink(IDocLink* iDocLink);

    public:
      String^  refId();
      String^  text();

    private:
      IDocLink* iDocLink;
    };

    public ref class DocProgramListing : public Doc
    {
    internal:
      DocProgramListing(IDocProgramListing* iDocProgramListing);

    public:
      DocIterator^ codeLines();

    private:
      IDocProgramListing* iDocProgramListing;
    };

    public ref class DocCodeLine : public Doc
    {
    internal:
      DocCodeLine(IDocCodeLine* iDocCodeLine);

    public:
      int lineNumber();
      String^  refId();
      DocIterator^ codeElements();

    private:
      IDocCodeLine* iDocCodeLine;
    };

    public ref class DocHighlight : public Doc
    {
    internal:
      DocHighlight(IDocHighlight* iDocHighlight);

    public:
      enum class HighlightKind 
      { 
        Invalid=0,
        Comment, 
        Keyword, 
        KeywordType, 
        KeywordFlow, 
        CharLiteral, 
        StringLiteral, 
        Preprocessor
      };
      HighlightKind highlightKind();
      DocIterator^ codeElements();

    private:
      IDocHighlight* iDocHighlight;
    };

    public ref class DocFormula : public Doc
    {
    internal:
      DocFormula(IDocFormula* iDocFormula);

    public:
      String^  id();
      String^  text();

    private:
      IDocFormula* iDocFormula;
    };

    public ref class DocImage : public Doc
    {
    internal:
      DocImage(IDocImage* iDocImage);

    public:
      String^  name();
      String^  caption();

    private:
      IDocImage* iDocImage;
    };

    public ref class DocDotFile : public Doc
    {
    internal:
      DocDotFile(IDocDotFile* iDocDotFile);

    public:
      String^  name();
      String^  caption();

    private:
      IDocDotFile* iDocDotFile;
    };

    public ref class DocIndexEntry : public Doc
    {
    internal:
      DocIndexEntry(IDocIndexEntry* iDocIndexEntry);

    public:
      String^  primary();
      String^  secondary();

    private:
      IDocIndexEntry* iDocIndexEntry;
    };

    public ref class DocTable : public Doc
    {
    internal:
      DocTable(IDocTable* iDocTable);

    public:
      DocIterator^ rows();
      int numColumns();
      String^  caption();

    private:
      IDocTable* iDocTable;
    };

    public ref class DocRow : public Doc
    {
    internal:
      DocRow(IDocRow* iDocRow);

    public:
      DocIterator^ entries();

    private:
      IDocRow* iDocRow;
    };

    public ref class DocEntry : public Doc
    {
    internal:
      DocEntry(IDocEntry* iDocEntry);

    public:
      DocIterator^ contents();

    private:
      IDocEntry* iDocEntry;
    };

    public ref class DocInternal : public Doc
    {
    internal:
      DocInternal(IDocInternal* iDocInternal);

    public:
      DocIterator^ paragraphs();
      DocIterator^ subSections();

    private:
      IDocInternal* iDocInternal;
    };

    public ref class DocSection : public Doc
    {
    internal:
      DocSection(IDocSection* iDocSection);

    public:
      String^  id(); 
      int level();
      DocTitle^ title();
      DocIterator^ paragraphs();
      DocIterator^ subSections();
      DocInternal^ internal();

    private:
      IDocSection* iDocSection;
    };

    public ref class DocTocList : public Doc
    {
    internal:
      DocTocList(IDocTocList* iDocTocList);

    public:
      DocIterator^ elements();

    private:
      IDocTocList* iDocTocList;
    };

    public ref class DocTocItem : public Doc
    {
    internal:
      DocTocItem(IDocTocItem* iDocTocItem);

    public:
      String^ id(); 
      String^ title();

    private:
      IDocTocItem* iDocTocItem;
    };

    public ref class DocCopy : public Doc
    {
    internal:
      DocCopy(IDocCopy* iDocCopy);

    public:
      DocIterator^ contents(); 

    private:
      IDocCopy* iDocCopy;
    };

    public ref class DocVerbatim : public Doc
    {
    internal:
      DocVerbatim(IDocVerbatim* iDocVerbatim);

    public:
      enum class Types 
      { 
        Invalid = 0, 
        HtmlOnly, 
        LatexOnly, 
        Verbatim 
      };

      String^ text(); 
      Types type();

    private:
      IDocVerbatim* iDocVerbatim;
    };

    public ref class DocAnchor : public Doc
    {
    internal:
      DocAnchor(IDocAnchor* iDocAnchor);

    public:
      String^ id(); 

    private:
      IDocAnchor* iDocAnchor;
    };

    public ref class DocSymbol : public Doc
    {
    internal:
      DocSymbol(IDocSymbol* iDocSymbol);

    public:
      enum class Types 
      { 
        Invalid = 0,
        Umlaut, 
        Acute, 
        Grave, 
        Circ, 
        Tilde, 
        Szlig, 
        Cedil, 
        Ring, 
        Nbsp, 
        Copy
      };

      Types type();
      String^  typeString();
      char letter();

    private:
      IDocSymbol* iDocSymbol;
    };

    public ref class DocRoot : public Doc
    {
    internal:
      DocRoot(IDocRoot* iDocRoot);

    public:
      DocIterator^ contents(); 
      DocInternal^ internal(); 

    private:
      IDocRoot* iDocRoot;
    };
  }
}
