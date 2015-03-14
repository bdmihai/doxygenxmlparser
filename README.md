# Managed wrapper for doxygen xml documentation

This project is a wrapper over the xml parser provided together with doxygen.

Optional doxygen can output the documentation into xml format allowing other tools to analyze the output. This can be useful for code metrics, special documentation, intelligence tools etc.

Doxygen parser is written into C++ but it may be usefull to be used from C# applications (without changing the parser concept). The wrapper is accomplishing this by having doxygen code together with managed C++ in order to create an assembly that can be used from C#.

This project is licensed under GNU GENERAL PUBLIC LICENSE.

Doxygen is a documentation system for C++, C, Java, Objective-C, Python, IDL (Corba and Microsoft flavors), Fortran, VHDL, PHP, C#, and to some extent D.

http://www.stack.nl/~dimitri/doxygen/index.html

# Getting started with doxygen parser in C#

Read a folder

```
parser = new Doxygen.XMLParser.DoxygenParser();
if (!(parser.readXMLDir(xmlFolder)))
{
  throw new System.Exception("Index.xml not found in " + xmlFolder);
}
```

Parsing compounds
```
/// <summary>
/// This method parses all the compounds and handles all function and
/// structure compounds.
/// </summary>
private void ParseCompounds()
{
  DoxygenParser.CompoundIterator compoundIt;
  DoxygenParser.Compound compound;

  compoundIt = parser.compounds();
  compoundIt.toFirst();

  while ((compound = compoundIt.current()) != null)
  {
    if (compound is Doxygen.XMLParser.File)
    {
       Console.Out.WriteLine("Parsing documentation for file: " + compound.name());
    }

    if (compound is Doxygen.XMLParser.Struct)
    {
       Console.Out.WriteLine("Parsing documentation for structure: " + compound.name());
    }

    // next compound
    compoundIt.toNext();
  }
}
```
