///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A general-purpose Binary Search Tree
///
/// @file Tree.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "List.h"

/// Holds Node classes in a Binary Search Tree.
///
/// This is implemented as a recursive data structure with `left` and `right`
/// Nodes.
class Tree : public Container {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* root = nullptr;  ///< The root for the binary search tree

public:  /////////////////////////// Public Methods ////////////////////////////
   void insert( Node* newNode );              ///< Add a Node to the Tree
   bool isIn( const Node* aNode ) const override ;  ///< `true` if `aNode` is in the Tree
   void erase( Node* nodeToRemove );          ///< Remove a Node from the Tree
   void dump() const noexcept override;       ///< Output the member variables in this object
   bool validate() const noexcept override;   ///< Ensure the object is valid
   Node* getRandomNode() const noexcept;      ///< Get a random Node from the Tree
   virtual void removeAll() noexcept;         ///< Remove all of the Nodes in the Tree

protected:  ////////////////////// Protected Methods ///////////////////////////
   void insert( Node* atNode, Node* newNode );         ///< Add a Node starting at atNode
   bool isIn( const Node* atNode, const Node* aNode ) const;       ///< `true` if `aNode` is in the Tree
   void dump( Node* atNode ) const noexcept;           ///< Output the member variables in this object
   bool validate( Node* atNode, Container::t_size& treeCount ) const noexcept;  ///< Ensure the object is valid
   Node* getRandomNode( Node* aNode, int* nodesLeft ) const noexcept;      ///< Get a random node from the Tree

// void dfsInorderReverse( Node* atCat, int depth ) const;  ///< Depth First Search - Inorder reverse search
// void dfsInorder( Node* atCat ) const;                    ///< Depth First Search - Inorder search
// void catTail( Node* atCat, Tree* tailList ) const;
// void dfsPreorder( Node* atCat ) const;
};
