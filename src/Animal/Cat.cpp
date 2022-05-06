///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
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

/// Data file that holds a list of cat names
#define CAT_NAMES_FILE "./data/catNames.txt"


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


/// Holds a list of cat names.  This is static, so the list will be built
/// once (on first use) and then remain available for the future.
static std::vector<std::string> names;


unsigned int Cat::remaningCatNames() noexcept {
   return names.size();
}


/// This static method should be used with care... several Animal Farm
/// data structures (like Tree) can't handle Cats with the same name.
///
/// This has been added to facilitate unit testing.
void Cat::resetCatNames() {
   names.clear();

   cout << "Loading... " ;

   ifstream file( CAT_NAMES_FILE );
   string line;
   while( getline( file, line )) {
      names.push_back( line );
   }

   cout << to_string( names.size() ) << " cat names from " CAT_NAMES_FILE << endl;
}


/// @internal This function will use `new` to create a Cat on the heap
///           Be sure to `delete` the cat when it's no longer needed
Cat& Cat::generateCat() {
   if( names.empty() ) {
      resetCatNames();
   }

   uniform_int_distribution<>  nameRNG( 0, (int) names.size()-1 );
   uniform_real_distribution<> weightRNG (0.1 ,Cat::MAX_WEIGHT);
   bernoulli_distribution      isFixedRNG(0.85); // 85% of cats are neutered
   uniform_int_distribution<>  colorRNG((int) Color::UNKNOWN_COLOR, (int) Color::CALICO);
   uniform_int_distribution<>  genderRNG((int) Gender::UNKNOWN_GENDER, (int) Gender::FEMALE);

   /// Remove names as they get used
   auto nameIterator = names.begin();
   int nameIndex = nameRNG( ANIMAL_FARM_RNG );
   while( nameIndex > 0 ) {
      nameIterator++;
      nameIndex -= 1;
   }

   string catName = *nameIterator;
   names.erase( nameIterator );

   Cat* aCat = new Cat( catName, (Color) colorRNG( ANIMAL_FARM_RNG ), isFixedRNG( ANIMAL_FARM_RNG ), (Gender) genderRNG( ANIMAL_FARM_RNG ), (float) weightRNG( ANIMAL_FARM_RNG ) );

   // aCat->dump();

   assert( aCat != nullptr );

   return *aCat;
}


/// This is required to safely use `delete` on a Cat object
Cat::~Cat() {
}


/// Compare two Cats:  Is the left < right?
/// Both sides are Cats.
/// The `this` member is the left side of the operator.
/// @param rhs_cat `rhs` stands for Right Hand Side and means the right side of the operator.
/// @return `true` if this < `rhs_cat`
bool Cat::operator<( const Cat& rhs_cat ) const {
   // cout << "this.name=[" << name << "]  rhs_cat.name=[" << rhs_cat.name << "]  name < rhs_cat.name=[" << ((name < rhs_cat.name) ? "true" : "false") << "]" << endl;
   return name < rhs_cat.name;
}


/// Compare two Cats:  Is the left > right?
/// @todo Bring down the documentation
bool Cat::operator>( const Cat& rhs_cat ) const {
   return rhs_cat < *this;
}


/// Compare two Cats:  Is the left <= right?
bool Cat::operator<=( const Cat& rhs_cat ) const {
   return !( rhs_cat < *this );
}


/// Compare two Cats:  Is the left >= right?
bool Cat::operator>=( const Cat& rhs_cat ) const {
   return !( *this < rhs_cat );
}


/// Compare a Cat and a Node.  This is the operator that actually gets
/// overridden by a Generic comparison.  First, we will try to dynamically
/// cast `rhs_node` to a Cat.  If both the left and right sides are Cats,
/// then, use the Cat comparison.  If not, then try the Animal comparison.
bool Cat::operator<( const Node& rhs_node ) const {
   try {
      const Cat& rhs_cat = dynamic_cast<const Cat&>(rhs_node);
      return *this < rhs_cat;
   } catch ( bad_cast& exception ) {        /// If rhs_node is not a Cat, it will throw a `bad_cast` exception...
      return Animal::operator<( rhs_node ); /// which will be caught and we will use an Animal comparison.
   }
}


bool Cat::operator>( const Node& rhs_node ) const {
   return Animal::operator>( rhs_node );
}


bool Cat::operator<=( const Node& rhs_node ) const {
   return Animal::operator<=( rhs_node );
}


bool Cat::operator>=( const Node& rhs_node ) const {
   return Animal::operator>=( rhs_node );
}
