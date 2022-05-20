///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// All things Cat
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

#include "Cat.h"
#include "../../../Utility/Trim.h"

using namespace std ;

/// Data file that holds a list of cat names
#define CAT_NAMES_FILE "./data/catNames.txt"sv


/// This is static, so the list will be available for any and all Cats to use (but nobody else).
Name Cat::names( CAT_NAMES_FILE );


/// This constructor is declared to be `explicit`, so you can't do silly
/// things like `Cat newCat = "Bella";` ... instead, you need to construct
/// a Cat properly like `Cat newCat( "Bella" );`
///
/// @param newName Must be a valid name per Name::validateName
Cat::Cat( const std::string_view newName )
        : Mammal( MAX_WEIGHT, SPECIES_NAME )  // Delegating constructor
        , name { trim_in( newName ) }         // Member initializer list
        , isCatFixed { false } {              // Member initializer list
   if( !Name::validateName( name ) ) {
      /// @throws invalid_argument If the Cat doesn't have a name
      throw invalid_argument( "The cat's name [" + name + "] is invalid" );
   }

   Cat::validate();
}


Cat::Cat( const std::string_view newName
         ,const Color            newColor
         ,const bool             newIsFixed
         ,const Gender           newGender
         ,const Weight::t_weight newWeight )
        : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME )  // Delegating constructor
        , name { trim_in( newName ) }  // Member initializer list
        , isCatFixed { newIsFixed } {  // Member initializer list

   if( !Name::validateName( name ) ) {
      /// @throws invalid_argument If the Cat doesn't have a name
      throw invalid_argument( "The cat's name [" + name + "] is invalid" );
   }

   Cat::validate();
}


/// Required to safely use `delete` on a Cat object
Cat::~Cat() = default;


string_view Cat::getName() const noexcept {
   return name;
}


/// @param newName The Cat's new name.  It must be valid per Name::validateName.
void Cat::setName( const string_view newName ) {
   string trialName { trim_in( newName ) };

   if( !Name::validateName( trialName ) ) {
      /// @throws invalid_argument If the Cat's name is invalid
      throw invalid_argument( "The cat's name [" + trialName + "] is invalid" );
   }

   name = move( trialName );
}


bool Cat::isFixed() const noexcept {
   return isCatFixed;
}


/// Once the Cat is fixed, it can never be un-fixed.
void Cat::fixCat() noexcept {
   Cat::isCatFixed = true;
}


std::string_view Cat::speak() const noexcept {
   return "Meow"sv ;
}


/// Output the contents of this object (and its parents).
///
/// #### Sample Output
/**@verbatim
======================================================
Cat                 name                Boo
Cat                 isFixed             false
@endverbatim */
void Cat::dump() const noexcept {
   assert( validate() ) ;

   Mammal::dump() ;

   FORMAT_LINE_FOR_DUMP( "Cat", "name" )    << getName() << endl ;
   FORMAT_LINE_FOR_DUMP( "Cat", "isFixed" ) << isFixed() << endl ;
}


/// Check the Cat object
bool Cat::validate() const noexcept {
   assert( Mammal::validate() );

   assert( Name::validateName( getName() ) );

   /// Nothing to validate for isCatFixed

   return true;
}


/// @internal This function will use `new` to create a Cat on the heap
///           Be sure to `delete` the Cat when it's no longer needed
Cat& Cat::generateCat() {
   uniform_real_distribution<> weightRNG ( 0.1, Cat::MAX_WEIGHT );
   bernoulli_distribution      isFixedRNG( 0.85 ); // 85% of cats are neutered
   uniform_int_distribution<>  colorRNG( (int) Color::UNKNOWN_COLOR, (int) Color::CALICO );
   uniform_int_distribution<>  genderRNG( (int) Gender::UNKNOWN_GENDER, (int) Gender::FEMALE );

   Cat* aCat = new Cat( names.getNextName(), (Color) colorRNG( ANIMAL_FARM_RNG ), isFixedRNG( ANIMAL_FARM_RNG ), (Gender) genderRNG( ANIMAL_FARM_RNG ), (float) weightRNG( ANIMAL_FARM_RNG ) );

   // aCat->dump();

   assert( aCat != nullptr );

   return *aCat;
}


/// @anchor Cat_comparison
/// The `this` member is the left side of the operator.
/// @param rhs_cat `rhs` stands for Right Hand Side and is the right side of the operator.
/// @return `true` if `this` < `rhs_cat`
bool Cat::operator<( const Cat& rhs_cat ) const {
   // cout << "this.name=[" << name << "]  rhs_cat.name=[" << rhs_cat.name << "]  name < rhs_cat.name=[" << ((name < rhs_cat.name) ? "true" : "false") << "]" << endl;
   return name < rhs_cat.name;
}


/// The actual implementation is in @ref Cat_comparison "operator<( Cat& rhs_cat )"
bool Cat::operator<=( const Cat& rhs_cat ) const {
   return !( rhs_cat < *this );
}


/// The actual implementation is in @ref Cat_comparison "operator<( Cat& rhs_cat )"
bool Cat::operator>( const Cat& rhs_cat ) const {
   return rhs_cat < *this;
}


/// The actual implementation is in @ref Cat_comparison "operator<( Cat& rhs_cat )"
bool Cat::operator>=( const Cat& rhs_cat ) const {
   return !( *this < rhs_cat );
}


/// @anchor Cat_Node_comparison
/// Compare a Cat and a Node.  This is the operator that gets overridden by a generic comparison (for example in an algorithm that knows about Nodes, but not Cats).
///
/// The `this` member is the left side of the operator.
/// @param rhs_node `rhs` stands for Right Hand Side and is the right side of the operator.
/// @return `true` if `this` < `rhs_node`
bool Cat::operator<( const Node& rhs_node ) const {
   try {
      const Cat& rhs_cat = dynamic_cast<const Cat&>(rhs_node);  /// First, try to dynamically cast `rhs_node` to a Cat.
      return *this < rhs_cat;               /// If both the left and right sides are Cats, then, use the Cat comparison like @ref Cat_comparison "operator<( Cat& rhs_cat )"
   } catch ( bad_cast& exception ) {        /// If `rhs_node` is not a Cat, it will throw a `bad_cast` exception...
      return Animal::operator<( rhs_node ); /// which will be caught and we will try an Animal comparison like @ref Animal_comparison "Animal::operator<( Animal& rhs_animal )"
   }
}


/// The actual implementation is in @ref Cat_Node_comparison "operator<( Node& rhs_node )"
bool Cat::operator<=( const Node& rhs_node ) const {
   return Animal::operator<=( rhs_node );
}


/// The actual implementation is in @ref Cat_Node_comparison "operator<( Node& rhs_node )"
bool Cat::operator>( const Node& rhs_node ) const {
   return Animal::operator>( rhs_node );
}


/// The actual implementation is in @ref Cat_Node_comparison "operator<( Node& rhs_node )"
bool Cat::operator>=( const Node& rhs_node ) const {
   return Animal::operator>=( rhs_node );
}
