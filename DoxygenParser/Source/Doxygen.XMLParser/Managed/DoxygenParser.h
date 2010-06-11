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

    public ref class DoxygenParser
    {
    public:
	    DoxygenParser(void);
	    virtual ~DoxygenParser(void);
      !DoxygenParser(void);

      /*! Returns an iterator that can be used to iterate over the list
      *  of compounds found in the project.
      */
      CompoundIterator^ compounds();

      /*! Returns a compound given its unique \a id. If you have a
      *  compound id this function is much more efficient than iterating
      *  over the compound list. Returns 0 if the id is not valid.
      */
      Compound^ compoundById(String^ id);

      /*! Returns a compound given its name (including the scope). 
      *  Returns 0 if the name is not found in the project.
      */
      Compound^ compoundByName(String^ name);

      /*! Returns an interface to a compound containing a member given it the
      *  member's id. Given the ICompound interface one can use the same id
      *  to obtain the IMember interface.
      *  @param id The member id.
      */
      Compound^ memberById(String^ id);

      /*! Returns a list of all compounds containing at least one members 
      *  with a certain name. Each compound can be asked to return the
      *  list of members with that name.
      *  @param name The name of the member.
      */
      Compound^ memberByName(String^ name);

      /*! Releases the memory for the object hierarchy obtained by 
      *  createdObjecModelFromXML(). First release all iterators before calling
      *  this function.
      */
      void release();

      /*! Sets the debug level.
      *  - 0 all debugging messages are disabled (the default).
      *  - 1 display important messages only
      *  - 2 display any messages.
      */
      void setDebugLevel(int level);

      /*! Reads an XML directory produced by doxygen and builds up a data 
      *  structure representing the contents of the XML files in the directory. 
      */
      bool readXMLDir(String^ xmlDirName);

    private:
      IDoxygen* iDoxygen;
    };
  }
}
