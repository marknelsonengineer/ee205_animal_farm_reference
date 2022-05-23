///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A generic interface for collections.
///
/// @file Container.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"


/// The root of the collection hierarchy.
///
/// Java calls these *Collections*.  The C++ STL calls them *Containers*.  Both
/// hold a group of Objects (that inherit from Node).  Some Containers have keys
/// like Cat.name and some require unique keys.
///
/// Our collection framework takes inspiration from both
/// [Java](https://docs.oracle.com/javase/8/docs/technotes/guides/collections/overview.html)
/// and the
/// [C++ STL](https://en.cppreference.com/w/cpp/container), but
/// implements a reduced set of methods, mostly because Animal Farm meant for teaching.
///
/// The Containers library is a generic collection of class templates and
/// algorithms that allow us to implement common data structures like
/// DoublyLinkedList and BinarySearchTree on the Node class.  Because Animal Farm will demonstrate
/// the utility of Generic/Template programming, we will implement a Cat specific
/// version of these data structures using classes like CatEmpire and CatWrangler.
///
/// We know some things about this Container, like the number of Nodes it has,
/// but this class does not provide any implementation.
///
/// According to the Rule of Three, this class has a:
///   - Copy constructor
///   - Assignment overload
///   - Destructor
///
/// The default constructor is enabled and working.  The copy and assignment
/// overload are disabled and will generate compiler errors.  This ensures
/// that nobody tries to copy a Binary Search Tree.  Essentially, we are saying
/// Animal Farm does not support "deep copies".  We don't need a destructor because
/// we've disabled the copy constructor and assignment overload.
///
/// @see https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
/// @see https://docs.oracle.com/javase/8/docs/api/java/util/Collection.html
///
class Container {
public:  //////////////// Enumerations & Type Definitions //////////////////////

   /// The native datatype of the Container's count/size
   typedef unsigned int t_size;

public:   ///////////////////// Constructors & Destructors /////////////////////
   explicit Container() = default;   ///< Default constructor (allowed)
   constexpr Container(const Container&) = delete;   ///< Copy constructor for a Container is not allowed
   constexpr Container& operator=( const Container& copyFrom ) = delete;  ///< Assignment constructor for a Container is not allowed

   protected:  ////////////////////// Protected Members ///////////////////////////

   t_size count = 0 ;   ///< Maintain a count of the number of Nodes in this Container


public:  /////////////////////////// Public Methods ////////////////////////////

   virtual bool   isEmpty()    const noexcept ;  ///< `true` if the Container is empty
   virtual t_size size()     const noexcept ;    ///< Return the number of Nodes in the Container
   virtual bool   isIn( const Node* aNode ) const;    ///< `true` if `aNode` is in the Container
   virtual void   removeAll() noexcept = 0;      ///< Remove all of the Nodes in the Container.  @todo Replace with a concrete method if/when I bring remove() to this class

   virtual void   dump()     const noexcept ;    ///< Output the member variables in this object
   virtual bool   validate() const noexcept ;    ///< Ensure the object is valid
};
