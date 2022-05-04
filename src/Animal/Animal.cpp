///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// Where the wild things roam
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>    // For assert()
#include <iostream>   // For cout
#include <stdexcept>  // For out_of_range
#include <iomanip>    // For setw() & setfill()
#include <random>


#include "../config.h"
#include "Animal.h"
#include "Cat.h"

using namespace std;


const std::string Animal::KINGDOM_NAME = "Animalia";


Animal::Animal( const Weight::t_weight newMaxWeight
               ,const std::string& newClassification
               ,const std::string& newSpecies ) : Node(), weight( Weight::POUND, newMaxWeight ) {
   if( !validateClassification( newClassification ) ) {
      /// @throws invalid_argument When the classification is invalid
      throw invalid_argument( "The classification is invalid" );
   }
   classification = newClassification;

   if( !validateSpecies( newSpecies ) ) {
      /// @throws invalid_argument When the species is invalid
      throw invalid_argument( "The species is invalid" );
   }
   species = newSpecies;

   Animal::validate();
}


Animal::Animal( const Gender newGender
               ,const Weight::t_weight newWeight
               ,const Weight::t_weight newMaxWeight
               ,const string& newClassification
               ,const string& newSpecies ) : Node(), weight( newWeight, newMaxWeight ) {

   /// @todo Research delegating constructors and then replace the redundant
   ///       code below.

   if( !validateClassification( newClassification ) ) {
      /// @throws invalid_argument When the classification is invalid
      throw invalid_argument( "The classification is invalid" );
   }
   classification = newClassification;

   if( !validateSpecies( newSpecies ) ) {
      /// @throws invalid_argument When the species is invalid
      throw invalid_argument( "The species is invalid" );
   }
   species = newSpecies;

   setGender( newGender );
   Animal::validate();
}


/// This can be `static` but for symmetry with the other `get` methods, I'm
/// leaving it in the class
///
/// @todo Replace with returning a `string_view`
///
/// @return KINGDOM_NAME
std::string Animal::getKingdom() const noexcept {
   return KINGDOM_NAME;
}


/// @todo Replace with returning a `string_view`
std::string Animal::getClassification() const noexcept {
   return classification;
}


/// @todo Replace with returning a `string_view`
std::string Animal::getSpecies() const noexcept {
   return species;
}


Gender Animal::getGender() const noexcept {
   return gender;
}


Weight::t_weight Animal::getWeight() const noexcept {
   return weight.getWeight() ;
}


void Animal::setWeight( const Weight::t_weight newWeight ) {
   validate();
   weight.setWeight( newWeight );
   validate();
}


/// This is not normally called as you can't change an Animal's gender, therefore
/// this method is protected.
///
/// You can only change the gender if it's currently UNKNOWN_GENDER.
///
/// @param newGender The new gender
void Animal::setGender( const Gender newGender ) {
   if( gender != Gender::UNKNOWN_GENDER ) {
      /// @throws logic_error If you try to change the gender of an Animal
      throw logic_error( PROGRAM_NAME ": The gender is already set, you can't change it" ) ;
   }

   // At this point, gender is unknown...
   assert( gender == Gender::UNKNOWN_GENDER );

   validate();
   gender = newGender ;
   validate();
}


/// It's unfortunate that C++'s string library does not have 'trim
/// whitespace' functionality.  Note:  It *is* available via Boost.
///
/// @todo Add left and right whitespace trim to classification.
///
/// @param checkClassification The classification to check
/// @return `true` if the classification is valid
bool Animal::validateClassification( const std::string& checkClassification ) noexcept {
   if( checkClassification.empty() ) {
      cout << PROGRAM_NAME ": classification must not be empty" << endl ;
      return false;
   }

   return true;
}


/// It's unfortunate that C++'s string library does not have 'trim
/// whitespace' functionality.  Note:  It *is* available via Boost.
///
/// @todo Add left and right whitespace trim to species.
///
/// @param checkSpecies The species to check
/// @return `true` if the species is valid
bool Animal::validateSpecies( const std::string& checkSpecies ) noexcept {
   if( checkSpecies.empty() ) {
      cout << PROGRAM_NAME ": species must not be empty" << endl ;
      return false;
   }

   return true;
}


void Animal::dump() const noexcept {
   assert( validate() ) ;

   PRINT_HEADING_FOR_DUMP ;

   Node::dump();

   FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl ;
   FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << endl ;
   FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << endl ;
   FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << endl ;
   FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << weight << endl ;
}


bool Animal::validate() const noexcept {
   assert( Node::validate() );

   assert( !getKingdom().empty() );
   assert( validateClassification(getClassification()) );
   assert( validateSpecies( getSpecies() ));
   /// Nothing to validate for Gender
   assert( weight.validate() );
   return true;
}


/// @internal This function will use `new` to create a Cat on the heap
///           Be sure to `delete` the cat when it's no longer needed
Animal& Animal::generateAnimal() {
   uniform_int_distribution<> animalRNG( 0, 0 );

   Animal* newAnimal;

   switch( animalRNG( ANIMAL_FARM_RNG ) ) {
    case 0: newAnimal = &(Cat::generateCat()) ;
   }

   return *newAnimal;
}


/// Compare two Animals:  Is the left < right?
/// Both sides are Animals.
/// The `this` member is the left side of the operator.
/// @param rhs_animal `rhs` stands for Right Hand Side and means the right side of the operator.
/// @return `true` if this < `rhs_animal`
bool Animal::operator<( const Animal& rhs_animal ) const {
   if( classification < rhs_animal.classification )
      return true;
   if( rhs_animal.classification < classification )
      return false;
   // If the two `classifications` are equal, compare `species`
   return species < rhs_animal.species;
}


/// Compare two Animals:  Is the left > right?
/// @todo Bring down the documentation
bool Animal::operator>( const Animal& rhs_animal ) const {
   return rhs_animal < *this;
}


/// Compare two Animals:  Is the left <= right?
bool Animal::operator<=( const Animal& rhs_animal ) const {
   return !( rhs_animal < *this );
}


/// Compare two Animals:  Is the left >= right?
bool Animal::operator>=( const Animal& rhs_animal ) const {
   return !( *this < rhs_animal );
}


/// Compare an Animal and a Node.  This is the operator that actually gets
/// overridden by a Generic comparison.  First, we will try to dynamically
/// cast `rhs_node` to an Animal.  If both the left and right sides are Animals,
/// then, use the Animal comparison.  If not, then use Node comparison.
bool Animal::operator<( const Node& rhs_node ) const {
   try {
      const Animal& rhs_animal = dynamic_cast<const Animal&>(rhs_node);
      return *this < rhs_animal;
   } catch ( bad_cast& exception ) {      /// If rhs_node is not an Animal, it will throw a `bad_cast` exception...
      return Node::operator<( rhs_node ); /// which will be caught and we will use Node comparison.
   }
}


bool Animal::operator>( const Node& rhs_node ) const {
   return Node::operator>( rhs_node );
}


bool Animal::operator<=( const Node& rhs_node ) const {
   return Node::operator<=( rhs_node );
}


bool Animal::operator>=( const Node& rhs_node ) const {
   return Node::operator>=( rhs_node );
}
