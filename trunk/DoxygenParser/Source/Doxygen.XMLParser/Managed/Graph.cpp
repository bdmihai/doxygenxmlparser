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

#include "Graph.h"

using namespace Doxygen::XMLParser;

EdgeLabel::EdgeLabel(IEdgeLabel *iEdgeLabel)
{
  this->iEdgeLabel = iEdgeLabel;
}

String^ EdgeLabel::label()
{
  return gcnew String(iEdgeLabel->label()->latin1());
}

//////////////////////////////////////////////////////////////////////////

EdgeLabelIterator::EdgeLabelIterator(IEdgeLabelIterator * iEdgeLabelIterator)
{
  this->iEdgeLabelIterator = iEdgeLabelIterator;
}

EdgeLabelIterator::~EdgeLabelIterator()
{
  this->!EdgeLabelIterator();
}

EdgeLabelIterator::!EdgeLabelIterator()
{
  release();
}

void EdgeLabelIterator::toFirst()
{
  iEdgeLabelIterator->toFirst();
}

void EdgeLabelIterator::toLast()
{
  iEdgeLabelIterator->toLast();
}

void EdgeLabelIterator::toNext()
{
  iEdgeLabelIterator->toNext();
}

void EdgeLabelIterator::toPrev()
{
  iEdgeLabelIterator->toPrev();
}

EdgeLabel^ EdgeLabelIterator::current()
{
  return gcnew EdgeLabel(iEdgeLabelIterator->current());
}

void EdgeLabelIterator::release()
{
  if (iEdgeLabelIterator != nullptr)
  {
    iEdgeLabelIterator->release();
    iEdgeLabelIterator = nullptr;
  }
}
//////////////////////////////////////////////////////////////////////////

ChildNode::ChildNode(IChildNode *iChildNode)
{
  this->iChildNode = iChildNode;
}

Node^ ChildNode::node()
{
  return gcnew Node(iChildNode->node());
}

ChildNode::NodeRelation ChildNode::relation()
{
  return (ChildNode::NodeRelation)iChildNode->relation();
}

String^ ChildNode::relationString()
{
  return gcnew String(iChildNode->relationString()->latin1());
}

EdgeLabelIterator^ ChildNode::edgeLabels()
{
  return gcnew EdgeLabelIterator(iChildNode->edgeLabels());
}

//////////////////////////////////////////////////////////////////////////

ChildNodeIterator::ChildNodeIterator(IChildNodeIterator * iChildNodeIterator)
{
  this->iChildNodeIterator = iChildNodeIterator;
}

ChildNodeIterator::~ChildNodeIterator()
{
  this->!ChildNodeIterator();
}

ChildNodeIterator::!ChildNodeIterator()
{
  release();
}

void ChildNodeIterator::toFirst()
{
  iChildNodeIterator->toFirst();
}

void ChildNodeIterator::toLast()
{
  iChildNodeIterator->toLast();
}

void ChildNodeIterator::toNext()
{
  iChildNodeIterator->toNext();
}

void ChildNodeIterator::toPrev()
{
  iChildNodeIterator->toPrev();
}

ChildNode^ ChildNodeIterator::current()
{
  return gcnew ChildNode(iChildNodeIterator->current());
}

void ChildNodeIterator::release()
{
  if (iChildNodeIterator != nullptr)
  {
    iChildNodeIterator->release();
    iChildNodeIterator = nullptr;
  }
}

//////////////////////////////////////////////////////////////////////////

Node::Node(INode *iNode)
{
  this->iNode = iNode;
}

String^ Node::id()
{
  return gcnew String(iNode->id()->latin1());
}

String^ Node::label()
{
  return gcnew String(iNode->label()->latin1());
}

String^ Node::linkId()
{
  return gcnew String(iNode->linkId()->latin1());
}

ChildNodeIterator^ Node::children()
{
  return gcnew ChildNodeIterator(iNode->children());
}

//////////////////////////////////////////////////////////////////////////

NodeIterator::NodeIterator(INodeIterator * iNodeIterator)
{
  this->iNodeIterator = iNodeIterator;
}

NodeIterator::~NodeIterator()
{
  this->!NodeIterator();
}

NodeIterator::!NodeIterator()
{
  release();
}

void NodeIterator::toFirst()
{
  iNodeIterator->toFirst();
}

void NodeIterator::toLast()
{
  iNodeIterator->toLast();
}

void NodeIterator::toNext()
{
  iNodeIterator->toNext();
}

void NodeIterator::toPrev()
{
  iNodeIterator->toPrev();
}

Node^ NodeIterator::current()
{
  return gcnew  Node(iNodeIterator->current());
}

void NodeIterator::release()
{
  if (iNodeIterator != nullptr)
  {
    iNodeIterator->release();
    iNodeIterator = nullptr;
  }
}

//////////////////////////////////////////////////////////////////////////

Graph::Graph(IGraph *iGraph)
{
  this->iGraph = iGraph;
}

NodeIterator^ Graph::nodes()
{
  return gcnew NodeIterator(iGraph->nodes());
}
