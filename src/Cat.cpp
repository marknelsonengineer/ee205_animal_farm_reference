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

#include <stdexcept>
#include <iostream>
#include <cassert>
#include <random>
#include <fstream>


#include "Cat.h"

using namespace std ;

#define CAT_NAMES_FILE "../../data/catNames.txt"


const std::string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;


string Cat::getName() const noexcept {
   return name;
}


void Cat::setName( const string& newName ) {
   if( !validateName( newName )) {
      /// @throw invalid_argument Cats should have a name
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

   Mammal::dump() ;

   FORMAT_LINE_FOR_DUMP( "Cat", "name" )    << getName() << endl ;
   FORMAT_LINE_FOR_DUMP( "Cat", "isFixed" ) << isFixed() << endl ;
}


/// Check the Cat object.
bool Cat::validate() const noexcept {
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


static std::vector<std::string> names;


/// @internal This function will use `new` to create a Cat on the heap
///           Be sure to `delete` the cat when it's no longer needed
Cat& Cat::generateCat() {
   if( names.empty() ) {
      cout << "Loading... ";

      ifstream file( CAT_NAMES_FILE );
      string line;
      while (getline(file, line)) names.push_back(line);

      cout << to_string( names.size() ) << " names." << endl;
   }

   random_device RNG;        // Seed with a real random value, if available
   uniform_int_distribution<> nameRNG( 0, (int) names.size()-1 );
   uniform_real_distribution<> weightRNG (0.1 ,Cat::MAX_WEIGHT);
   bernoulli_distribution isFixedRNG(0.85); // 85% of cats are neutered
   uniform_int_distribution<> colorRNG((int) Color::UNKNOWN_COLOR, (int) Color::CALICO);
   uniform_int_distribution<> genderRNG((int) Gender::UNKNOWN_GENDER, (int) Gender::FEMALE);

   Cat* aCat = new Cat( names[nameRNG( RNG )], (Color) colorRNG( RNG ), isFixedRNG( RNG ), (Gender) genderRNG( RNG ), (float) weightRNG( RNG ) );

   // aCat->dump();

   assert( aCat != nullptr );

   return *aCat;
}
