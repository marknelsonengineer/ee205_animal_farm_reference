///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// Prints data about the Empire of Cats
///
/// @file CatEmpire.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../Animal/Cat.h"
#include "../Container/Tree.h"

/// A Binary Search Tree that's customized to store Cats
class CatEmpire : public Tree {
protected:
   /// The root for the binary search tree is the topCat of our little Empire
   Cat*& topCat = reinterpret_cast<Cat*&>(rootNode);

public:   /////////////////////////// Public Methods ///////////////////////////
   void catBegat() const;
   void catFamilyTree() const noexcept;
   void catList() const noexcept;
   void catGenerations() const noexcept;
   void catTail( CatEmpire* tailList ) const noexcept;

private:   ////////////////////////// Private Methods //////////////////////////
   void dfsPreorder( Cat* atCat ) const noexcept;
   void dfsInorder( Cat* atCat ) const noexcept;
   void dfsInorderReverse( Cat* atCat, int depth ) const noexcept;
   void catTail( Cat* atCat, CatEmpire* tailList ) const noexcept;
};
