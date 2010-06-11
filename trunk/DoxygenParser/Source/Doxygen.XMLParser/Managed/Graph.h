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

using namespace System;

namespace Doxygen
{ 
  namespace XMLParser 
  {

    ref class Node;

    public ref class EdgeLabel
    {
    internal:
      EdgeLabel(IEdgeLabel *iEdgeLabel);

    public:
      String^ label();

    private:
      IEdgeLabel * iEdgeLabel;
    };

    public ref class EdgeLabelIterator 
    {
    internal:
      EdgeLabelIterator(IEdgeLabelIterator* iEdgeLabelIterator);

    public:
      ~EdgeLabelIterator();
      !EdgeLabelIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      EdgeLabel^ current();
      void release();

    private:
      IEdgeLabelIterator* iEdgeLabelIterator;
    };

    public ref class ChildNode
    {
    internal:
      ChildNode(IChildNode *iChildNode);

    public:
      enum class NodeRelation 
      { 
        PublicInheritance, 
        ProtectedInheritance,
        PrivateInheritance, 
        Usage, 
        TemplateInstance
      };
      
      Node^ node();
      NodeRelation relation();
      String^ relationString();
      EdgeLabelIterator^ edgeLabels();

    private:
      IChildNode * iChildNode;
    };

    public ref class ChildNodeIterator 
    {
    internal:
      ChildNodeIterator(IChildNodeIterator* iChildNodeIterator);

    public:
      ~ChildNodeIterator();
      !ChildNodeIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      ChildNode^ current();
      void release();

    private:
      IChildNodeIterator* iChildNodeIterator;
    };

    public ref class Node
    {
    internal:
      Node(INode *iNode);

    public:
      String^ id();
      String^ label();
      String^ linkId();
      ChildNodeIterator^ children();

    private:
      INode * iNode;
    };

    public ref class NodeIterator 
    {
    internal:
      NodeIterator(INodeIterator* iNodeIterator);

    public:
      ~NodeIterator();
      !NodeIterator();

      void toFirst();
      void toLast();
      void toNext();
      void toPrev();
      Node^ current();
      void release();

    private:
      INodeIterator* iNodeIterator;
    };

    public ref class Graph
    {
    internal:
      Graph(IGraph *iGraph);

    public:
      NodeIterator^ nodes();

    private:
      IGraph * iGraph;
    };
  }
}
