///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A specialized Binary Search Tree that holds Cats
///
/// @file CatEmpire.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Cat.h"
#include "../../../Container/BinarySearchTree.h"

/// A Binary Search Tree that's customized to store Cats
class CatEmpire : public BinarySearchTree {
protected:
   /// The root for the binary search tree is the topCat of our little Empire
   Cat*& topCat = reinterpret_cast<Cat*&>(root);

public:   /////////////////////////// Public Methods ///////////////////////////
   void catBegat() const;
   void catFamilyTree() const noexcept;
   void catList() const noexcept;
   void catGenerations() const;
   void catTail( CatEmpire* tailList ) const noexcept;

private:   ////////////////////////// Private Methods //////////////////////////
   void dfsPreorder( Cat* atCat ) const noexcept;
   void dfsInorder( Cat* atCat ) const noexcept;
   void dfsInorderReverse( Cat* atCat, unsigned long depth ) const noexcept;
   void catTail( Cat* atCat, CatEmpire* tailList ) const ;
};
