///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   17_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cassert>

#include "Cat.h"

using namespace std ;


const std::string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;


string Cat::getName() const noexcept {
   return name;
}


void Cat::setName( const string& newName ) {
   if( !validateName( newName )) {
      /// @throw invalid_argument Cats should have a name
      /// @todo Go back and make sure the Mammal and Animal classes throw consistent exceptions
      throw invalid_argument( "Cats should have a good name" );
   }
   name = newName ;
}


bool Cat::isFixed() const noexcept {
   return isCatFixed;
}


/// Once the cat is fixed, it can never be un-fixed.
void Cat::fixCat() noexcept {
   Cat::isCatFixed = true;
}


/// #### Sample Output
///
///     Cat     name                Kali
///     Cat     isFixed             false
///
void Cat::dump() const noexcept {
   assert( validate() ) ;

   Node::dump() ;
   Mammal::dump() ;

   FORMAT_LINE_FOR_DUMP( "Cat", "name" )    << getName() << endl ;
   FORMAT_LINE_FOR_DUMP( "Cat", "isFixed" ) << isFixed() << endl ;
}


/// Check the Cat object.
bool Cat::validate() const noexcept {
   Node::validate() ;
   Mammal::validate() ;

   assert( validateName( getName() ));

   return true;
}


/// @param newName The name to check
/// @return `true` if the name is valid (not empty).  `false` if the cat doesn't have a name.
bool Cat::validateName( const std::string& newName ) {
   if( newName.empty() ) {
      cout << PROGRAM_NAME ": A cat should have a name" << endl;
      return false;
   }

   return true;
}


std::string Cat::speak() const noexcept {
   return "Meow" ;
}
