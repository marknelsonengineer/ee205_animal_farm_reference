///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab15a_animal_farm_4 - EE 205 - Spr 2022
///
/// @file Tree.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

/// Holds Node classes in a Binary Search Tree
class Tree {
private:
   Node* topCat = nullptr;

public:
   bool empty() { return topCat == nullptr; }  ///< Return true if empty

public:
   void addCat( Node* newCat );  ///< Add a cat starting at the root

   void catFamilyTree() const;
   void catList() const;
   void catTail( Tree* tailList ) const;
   void catBegat() const;
   void catGenerations() const;

private:
   void addCat( Node* atCat, Node* newCat );  // Add a cat starting at atCat

   void dfsInorderReverse( Node* atCat, int depth ) const;
   void dfsInorder( Node* atCat ) const;
   void catTail( Node* atCat, Tree* tailList ) const;
   void dfsPreorder( Node* atCat ) const;
};
