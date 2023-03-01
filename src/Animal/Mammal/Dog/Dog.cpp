///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Some of my favorite cats are dogs
///
/// @file   Dog.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <random>
#include <stdexcept>

#include "../../../Utility/Trim.h"
#include "Dog.h"

using namespace std ;

/// Data file that holds a list of dog names
#define DOG_NAMES_FILE "./data/dogNames.txt"sv

/// This is static, so the list will be available for any and all Dogs to use (but nobody else).
///
/// #### Internal
/// The scope of this **member** variable is `public:`.  This is to facilitate
/// testing.  It's very difficult to friend some of the Boost test fixtures.
Name Dog::names( DOG_NAMES_FILE );


Dog::Dog( const std::string_view newName
         ,const Color            newColor
         ,const Gender           newGender
         ,const Weight::t_weight newWeight )
        : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME )  // Delegating constructor
        , name { trim_in( newName ) } {  // Member initializer list

   if( !Name::validateName( name ) ) {
      /// @throws invalid_argument If the Dog doesn't have a name
      throw invalid_argument( "The dog's name [" + name + "] is invalid" );
   }

   Dog::validate();
}


/// Required to safely use `delete` on a Dog object
Dog::~Dog() = default;


string_view Dog::getName() const noexcept {
   return name;
}


std::string_view Dog::speak() const noexcept {
   return "Woof"sv ;
}


/// Output the contents of this object (and its parents).
///
/// #### Sample Output
/**@verbatim
======================================================
Dog                 name                Boo
@endverbatim */
void Dog::dump() const noexcept {
   assert( validate() ) ;

   Mammal::dump() ;

   FORMAT_LINE_FOR_DUMP( "Dog", "name" ) << getName() << endl ;
}


/// Check the Dog object
bool Dog::validate() const noexcept {
   assert( Mammal::validate() );

   assert( Name::validateName( getName() ) );

   /// Nothing else to validate

   return true;
}


/// @pattern Factory Method
///
/// #### Internal
/// This function will use `new` to create a random Dog (Animal) on the heap.
/// Be sure to `delete` the Animal when it's no longer needed
Animal& Dog::newRandomAnimal() {
   return (Animal&) newRandomDog();
}


/// @pattern Factory Method
///
/// #### Internal
/// This function will use `new` to create a Dog on the heap.  Be sure to
/// `delete` the Dog when it's no longer needed
Dog& Dog::newRandomDog() {
   uniform_real_distribution<> weightRNG( Dog::MIN_WEIGHT, Dog::MAX_WEIGHT );

   Dog* aDog = new Dog( names.getNextName(), newRandomColor(), newRandomGender(), (Weight::t_weight) weightRNG( ANIMAL_FARM_RNG ) );

   // aDog->dump();

   assert( aDog != nullptr );

   return *aDog;
}


/// @anchor Dog_comparison
/// The `this` member is the left side of the operator.
/// @param rhs_dog `rhs` stands for Right Hand Side and is the right side of the operator.
/// @return `true` if `this` < `rhs_dog`
bool Dog::operator<( const Dog& rhs_dog ) const {
   return name < rhs_dog.name;
}


/// @anchor Dog_Node_comparison
/// Compare a Dog and a Node.  This is the operator that gets overridden by a generic comparison (for example in an algorithm that knows about Nodes, but not Dogs).
///
/// The `this` member is the left side of the operator.
/// @param rhs_node `rhs` stands for Right Hand Side and is the right side of the operator.
/// @return `true` if `this` < `rhs_node`
bool Dog::operator<( const Node& rhs_node ) const {
   try {
      const Dog& rhs_dog = dynamic_cast<const Dog&>(rhs_node);  /// First, try to dynamically cast `rhs_node` to a Dog.
      return *this < rhs_dog;               /// If both the left and right sides are Dogs, then, use the Dog comparison like @ref Dog_comparison "operator<( Dog& rhs_dog )"
   } catch ( bad_cast& exception ) {        /// If `rhs_node` is not a Dog, it will throw a `bad_cast` exception...
      return Animal::operator<( rhs_node ); /// which will be caught and we will try an Animal comparison like @ref Animal_comparison "Animal::operator<( Animal& rhs_animal )"
   }
}
