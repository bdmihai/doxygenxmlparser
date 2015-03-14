# Read a folder #

```
parser = new Doxygen.XMLParser.DoxygenParser();

if (!(parser.readXMLDir(xmlFolder)))
{
  throw new System.Exception("Index.xml not found in " + xmlFolder);
}
```

# Parsing compounds #

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