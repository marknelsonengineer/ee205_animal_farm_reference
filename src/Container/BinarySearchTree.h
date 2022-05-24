///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A general-purpose Binary Search Tree
///
/// @file BinarySearchTree.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"
#include "Tree.h"

/// Holds Node classes in a Binary Search Tree.
///
/// This is implemented as a recursive data structure with `left` and `right`
/// Nodes.
class BinarySearchTree : public Tree {
public:   /////////////////////////// Public Methods ///////////////////////////
   void  add( Node* newNode ) override;              ///< Add a Node to the Tree
   bool  isIn( const Node* aNode ) const override ;  ///< `true` if `aNode` is in the Tree
   Node* remove( Node* nodeToRemove ) override;      ///< Remove a Node from the Tree
   void  dump() const noexcept override;             ///< Output the member variables in this object
   bool  validate() const noexcept override;         ///< Ensure the object is valid
   Node* getRandomNode() const noexcept override;    ///< Get a random Node from this Container

protected:  ////////////////////// Protected Methods ///////////////////////////
   void add( Node* atNode, Node* newNode );   ///< Add a Node starting at atNode
   bool isIn( const Node* atNode, const Node* aNode ) const;  ///< `true` if `aNode` is in the Tree
   void dump( Node* atNode ) const noexcept;  ///< Output the member variables in this object
   bool validate( Node* atNode, Container::t_size& treeCount ) const noexcept;  ///< Ensure the object is valid
   Node* getRandomNode( Node* aNode, int* nodesLeft ) const noexcept;  ///< Get a random node from the Tree

   // To do these... we really need iterators
   // void dfsInorder( Node* atNode ) const;         ///< Depth First Search - Inorder search
   // void dfsInorderReverse( Node* atNode ) const;  ///< Depth First Search - Inorder reverse search
   // void dfsPreorder( Node* atNode ) const;
   // void dfsPreorderReverse( Node* atNode ) const;
   // void dfsPostorder( Node* atNode ) const;
   // void dfsPostorderReverse( Node* atNode ) const;
};
