///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A Doubly Linked List that's been specialized to store Cats
///
/// @file CatWrangler.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   24_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Cat.h"
#include "../../../Container/DoublyLinkedList.h"
#include "CatContainer.h"

/// A Doubly Linked List that's been specialized to store Cats
class CatWrangler : private DoublyLinkedList, public CatContainer {
public:  ///////////// Inherited Methods from DoublyLinkedList /////////////////
   inline void add( Cat* newCat ) { DoublyLinkedList::add( newCat ); }  ///< Add a Cat to CatWrangler
   inline Cat* remove( Cat* catToRemove ) { return (Cat*) DoublyLinkedList::remove( catToRemove ); }  ///< Remove `catToRemove` from CatWrangler
   inline void addFront( Cat* newCat ) { DoublyLinkedList::addFront( newCat ); }  ///< Insert `newCat` to the beginning of CatWrangler
   inline void addBack( Cat* newCat ) { DoublyLinkedList::addBack( newCat ); }  ///< Append `newCat` to the end of CatWrangler
   inline Cat* removeFront() noexcept { return (Cat*) DoublyLinkedList::removeFront(); }  ///< Remove and return the first Cat in CatWrangler
   inline Cat* removeBack() noexcept { return (Cat*) DoublyLinkedList::removeBack(); }  ///< Remove and return the last Cat in CatWrangler
   inline void addAfter( Cat* currentCat, Cat* newCat ) { DoublyLinkedList::addAfter( currentCat, newCat ); }  ///< Insert `newCat` after `currentCat`
   inline void addBefore( Cat* currentCat, Cat* newCat ) { DoublyLinkedList::addBefore( currentCat, newCat ); }  ///< Insert `newCat` before `currentCat`
   inline void swap( Cat* cat1, Cat* cat2 ) { DoublyLinkedList::swap( cat1, cat2 ); }  ///< Swap `cat1` and `cat2`
   inline void insertionSort() noexcept { DoublyLinkedList::insertionSort(); }  ///< Runs the insertion sort algorithm on this CatWrangler
   inline Cat* getLast() const noexcept { return (Cat*) DoublyLinkedList::getLast(); }  ///< Get the last Cat in CatWrangler
   inline static Cat* getPrev( const Cat* currentCat ) { return (Cat*) DoublyLinkedList::getPrev( currentCat ); }  ///< Get the previous Cat
   inline void dump() const noexcept { DoublyLinkedList::dump(); }  ///< Output the member variables in this object
   inline bool validate() const noexcept { return DoublyLinkedList::validate(); }  ///< Ensure CatWrangler is valid

public:  /////////////////// Inherited Methods from List ///////////////////////
   inline bool isIn( const Cat* aCat ) const { return DoublyLinkedList::isIn( aCat ); }  ///< `true` if `aCat` is in CatWrangler
   inline bool isSorted() const noexcept { return DoublyLinkedList::isSorted(); }  ///< `true` if CatWrangler is sorted
   inline Cat* getFirst() const noexcept { return (Cat*) DoublyLinkedList::getFirst(); }  ///< Get the first Cat in CatWrangler
   inline void removeAll() noexcept { return DoublyLinkedList::removeAll(); }  ///< Remove all of the Cats from CatWrangler
   inline Cat* getRandomNode() const noexcept { return (Cat*) DoublyLinkedList::getRandomNode(); }  ///< Get a random Cat from CatWrangler
   inline static Cat* getNext( const Cat* currentCat ) { return (Cat*) DoublyLinkedList::getNext( currentCat ); }  ///< Get the next Cat

public:  ///////////////// Inherited Methods from Container ////////////////////
   inline bool isEmpty() const noexcept { return DoublyLinkedList::isEmpty(); }  ///< `true` if CatWrangler is empty
   inline t_size size() const noexcept { return DoublyLinkedList::size(); }   ///< Return the number of Cats in CatWrangler
};
