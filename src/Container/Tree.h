///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab15a_animal_farm_4 - EE 205 - Spr 2022
///
/// A generic Binary Search Tree
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

/// Holds Node classes in a Binary Search Tree
class Tree : public Container {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* rootNode = nullptr;  ///< The root for the binary search tree

public:  /////////////////////////// Public Methods ////////////////////////////
   void insert( Node* newNode );              ///< Add a Node to the Tree
   bool isIn( Node* aNode ) const override ;  ///< `true` if `aNode` is in the Tree
   void dump() const noexcept override;       ///< Output the member variables in this object
   bool validate() const noexcept override;   ///< Ensure the object is valid

protected:  ////////////////////// Protected Methods ///////////////////////////
   void insert( Node* atNode, Node* newNode );    ///< Add a Node starting at atNode
   bool isIn( Node* atNode, Node* aNode ) const;  ///< `true` if `aNode` is in the Tree
   void dump( Node* atNode ) const noexcept;      ///< Output the member variables in this object
   bool validate( Node* atNode ) const noexcept;  ///< Ensure the object is valid

// void dfsInorderReverse( Node* atCat, int depth ) const;  ///< Depth First Search - Inorder reverse search
// void dfsInorder( Node* atCat ) const;                    ///< Depth First Search - Inorder search
// void catTail( Node* atCat, Tree* tailList ) const;
// void dfsPreorder( Node* atCat ) const;
};
