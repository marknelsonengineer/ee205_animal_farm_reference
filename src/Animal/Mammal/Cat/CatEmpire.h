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
class CatEmpire : private BinarySearchTree {
protected:
   /// The root for the binary search tree is the topCat of our little Empire
   Cat*& topCat = reinterpret_cast<Cat*&>(root);

public:  ///////////// Inherited Methods from BinarySearchTree /////////////////
   inline void add( Cat* newNode ) { BinarySearchTree::add( newNode ); }  ///< Add a Cat to the Empire
   inline bool isIn( const Cat* aCat ) const { return BinarySearchTree::isIn( aCat ); }  ///< `true` if `aCat` is in the Empire
   inline Cat* remove( Cat* catToRemove ) { return (Cat*) BinarySearchTree::remove( catToRemove); };      ///< Remove a Cat from the Empire
   inline void dump() const noexcept { BinarySearchTree::dump(); }  ///< Output the member variables in this object
   inline bool validate() const noexcept { return BinarySearchTree::validate(); }  ///< Ensure the Empire is valid
   inline Cat* getRandomNode() const noexcept { return (Cat*) BinarySearchTree::getRandomNode(); }  ///< Get a random Cat from the Empire

public:  ////////////////////// Public Methods from Tree ///////////////////////
   inline void removeAll() noexcept override { BinarySearchTree::removeAll(); }  ///< Remove all of the Cats from the Empire

public:  /////////////////// Public Methods from Container /////////////////////
   inline bool isEmpty() const noexcept { return BinarySearchTree::isEmpty(); }  ///< `true` if the Empire is empty
   inline t_size size() const noexcept { return BinarySearchTree::size(); }   ///< Return the number of Cats in the Empire

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
