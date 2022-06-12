///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A generic interface for collections of Cats
///
/// @file CatContainer.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   28_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Cat.h"

/// A generic interface (pure abstract C++ class) for collections of Cats
class CatContainer {
public:  /////////////////////////// Public Methods ////////////////////////////
   virtual void add( Cat* newCat )             = 0;  ///< Add newCat to the Container
   virtual Cat* getRandomNode() const noexcept = 0;  ///< Get a random Node (it will always be a Cat) from the Container
   virtual bool isIn( const Cat* aCat ) const  = 0;  ///< `true` if `aCat` is in the Container
   virtual Cat* remove( Cat* catToRemove )     = 0;  ///< Remove this Cat from the Array
};
