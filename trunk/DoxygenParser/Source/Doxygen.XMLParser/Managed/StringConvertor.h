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

using namespace System;
using namespace System::Runtime::InteropServices;

namespace Doxygen
{ 
  namespace XMLParser 
  {
    namespace StringUtilities
    {

	    //Class StringConvertor
	    //General purpose converter class for System::String (both from and to)
	    ref class StringConvertor
	    {
	    protected:
		    String^ m_String; //The internal System::String object
        IntPtr  m_Ptr;

        bool disposed;


	    public: 
		    //Various constructors each taking a different type as argument
		    StringConvertor(String^ s) : m_String(s)
		    {
			    if(m_String == nullptr)
            throw gcnew System::Exception("You need to pass a non-null String");

          m_Ptr = Marshal::StringToHGlobalAnsi(m_String);

          disposed = false;
		    }

        !StringConvertor()
        {
          // Call the appropriate methods to clean up unmanaged 
          // resources here. If disposing is false when Dispose(bool,
          // disposing) is called, only the following code is executed.
          Marshal::FreeHGlobal(m_Ptr);
          m_Ptr = IntPtr::Zero;
        }

        ~StringConvertor()
        {

          // Call C++ finalizer to clean up unmanaged resources.
          this->!StringConvertor();

          // Mark the class as disposed. This flag allows you to throw an
          // exception if a disposed object is accessed.
          disposed = true;
        }

		    //Methods

		    virtual String^ ToString() override
		    {
			    return m_String;
		    }

		    //Operators

		    operator String^()
		    {
			    return m_String;
		    }

		    //Properties	

		    //Returns a char* (allocated on the native heap)
		    property char* NativeCharPtr
		    {
			    char* get()
			    {
				    return reinterpret_cast<char*>(static_cast<void*>(m_Ptr));	
			    }
		    }

	    };
    }
  }
}