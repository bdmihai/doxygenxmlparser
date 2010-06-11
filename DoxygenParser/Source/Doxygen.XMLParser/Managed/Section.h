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
#include "Doc.h"

using namespace System;

namespace Doxygen
{ 
  namespace XMLParser 
  {

    ref class MemberIterator;

    /*! \brief The interface to a section in the object model. 
    *
    *  A compound can have a number of sections, where each
    *  section contains a set of members with the properties implied by
    *  the section kind. The kind() method returns the kind of the section.
    *  The members of the section can be accessed via members(). Apart
    *  from using kind(), some of the individual properties of the section can 
    *  also be inspected via isStatic(), isPublic(), isProtected() and 
    *  isPrivate().
    */
    public ref class Section
    {
    internal:
      Section(ISection *iSection);

      static Section^ Create(ISection *iSection);

    public:
      enum class SectionKind 
      { 
        Invalid = 0,
        UserDefined,         //!< A user defined member group 
        PubTypes,            //!< Public member typedefs
        PubFuncs,            //!< Public member functions
        PubAttribs,          //!< Public member attributes 
        PubSlots,            //!< Public Qt Slots
        Signals,             //!< Qt Signals
        DCOPFuncs,           //!< KDE-DCOP interface functions
        Properties,          //!< IDL properties
        Events,              //!< C# events
        PubStatFuncs,        //!< Public static member functions
        PubStatAttribs,      //!< Public static attributes
        ProTypes,            //!< Protected member typedefs
        ProFuncs,            //!< Protected member functions
        ProAttribs,          //!< Protected member attributes
        ProSlots,            //!< Protected slots
        ProStatFuncs,        //!< Protected static member functions
        ProStatAttribs,      //!< Protected static member attributes
        PacTypes,            //!< Package member typedefs
        PacFuncs,            //!< Package member functions
        PacAttribs,          //!< Package member attributes
        PacStatFuncs,        //!< Package static member functions
        PacStatAttribs,      //!< Package static member attributes
        PriTypes,            //!< Private member typedefs
        PriFuncs,            //!< Private member functions
        PriAttribs,          //!< Private member attributes
        PriSlots,            //!< Private Qt slots
        PriStatFuncs,        //!< Private static member functions
        PriStatAttribs,      //!< Private static member attributes
        Friend,              //!< Friends
        Related,             //!< Function marked as related
        Defines,             //!< Preprocessor defines
        Prototypes,          //!< Global function prototypes
        Typedefs,            //!< Global typedefs
        Enums,               //!< Enumerations
        Functions,           //!< Global functions
        Variables            //!< Global variables
      };

      /*! Returns a string representation of the value returned by kind() */
      String^ kindString();

      /*! Returns what kind of section this is */
      SectionKind kind();

      /*! Returns the description attached to this section (for user defined
      *  sections, also known as member groups).
      */
      DocRoot^ description();

      /*! Returns an iterator for the members of this section */
      MemberIterator^ members();

      /*! Returns \c true if this section contains statics */
      bool isStatic();

      /*! Returns \c true if this section belongs to a 
      *  public section of a class 
      */
      bool isPublic();

      /*! Returns \c true if this section belongs to a 
      *  private section of a class 
      */
      bool isPrivate();

      /*! Returns \c true if this section belongs to a 
      *  protected section of a class 
      * */
      bool isProtected();

    private:
      ISection * iSection;
    };

    public ref class UserDefined : public Section
    {
    internal:
      UserDefined(IUserDefined *iUserDefined);

    public:
      String^ header();

    private:
      IUserDefined * iUserDefined;
    };

    public ref class SectionIterator
    {
    internal:
      SectionIterator(ISectionIterator* iSectionIterator);

    public:
      ~SectionIterator();
      !SectionIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      Section^ current();
      void release();

    private:
      ISectionIterator* iSectionIterator;
    };
  }
}
