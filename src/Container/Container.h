///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// A generic collection class.
///
/// @file Container.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"


/// A generic collection class.  We know some things about this Container,
/// like the number of Nodes it contains, but we don't have any implementation.
///
/// Container will be used as a base class for a number of data structures.
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
///
class Container {
public:   ///////////////////// Constructors & Destructors /////////////////////
   explicit Container() = default;   ///< Default constructor (allowed)
   constexpr Container(const Container&) = delete;   ///< Copy constructor for a Container is not allowed
   constexpr Container& operator=( const Container& copyFrom ) = delete;  ///< Assignment constructor for a Container is not allowed

   protected:  ////////////////////// Protected Members ///////////////////////////

   unsigned int count = 0 ;   ///< Maintain a count of the number of Nodes in this Container


public:  /////////////////////////// Public Methods ////////////////////////////

   virtual bool         empty()    const noexcept ;  ///< `true` if the Container is empty
   virtual unsigned int size()     const noexcept ;  ///< Return the number of Nodes in the Container
   virtual bool         isIn( Node* aNode ) const ;  ///< `true` if `aNode` is in the Container

   virtual void         dump()     const noexcept ;  ///< Output the member variables in this object
   virtual bool         validate() const noexcept ;  ///< Ensure the object is valid
};
