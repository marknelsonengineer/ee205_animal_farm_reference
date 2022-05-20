///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// Birds are feathered theropods and constitute the only known living dinosaurs.
///
/// @file Bird.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   18_May_2022
///////////////////////////////////////////////////////////////////////////////
#include <string>
#include <cassert>

#include "../../config.h"
#include "../../Utility/Trim.h"
#include "Bird.h"

using namespace std;


/// @todo Make the order of the Animal parameters consistent
Bird::Bird( const std::string_view newSpecies
           ,const Weight::t_weight newMaxWeight
           ,const std::string_view newName
           ,const Gender           newGender
           ,const Weight::t_weight newWeight )
        : Animal( newGender, newWeight, newMaxWeight, CLASSIFICATION_NAME, newSpecies )  // Delegating constructor
        , name { trim_in( newName ) }  // Member initializer list
{ }  // Nothing to do


/// Required to safely use `delete` on a Bird object
Bird::~Bird() = default;


std::string_view Bird::getName() const noexcept {
   return name;
}


std::string_view Bird::speak() const noexcept {
   return "Tweet"sv ;
}


/// Ensure the Bird is healthy before dumping its contents.
///
/// #### Sample Output
/**@verbatim
======================================================
Bird                name                Boo
@endverbatim */
void Bird::dump() const noexcept {
   assert( validate() ) ;

   Animal::dump() ;

   FORMAT_LINE_FOR_DUMP( "Bird", "name" ) << getName() << endl ;
}


bool Bird::validate() const noexcept {
   assert( Animal::validate() );

   assert( Name::validateName( getName() ) );

   /// Nothing else to validate

   return true;
}


/// @anchor Bird_comparison
/// The `this` member is the left side of the operator.
/// @param rhs_bird `rhs` stands for Right Hand Side and is the right side of the operator.
/// @return `true` if `this` < `rhs_bird`
bool Bird::operator<( const Bird& rhs_bird ) const {
   return name < rhs_bird.name;
}


/// @anchor Bird_Node_comparison
/// Compare a Bird and a Node.  This is the operator that gets overridden by a generic comparison (for example in an algorithm that knows about Nodes, but not Birds).
///
/// The `this` member is the left side of the operator.
/// @param rhs_node `rhs` stands for Right Hand Side and is the right side of the operator.
/// @return `true` if `this` < `rhs_node`
bool Bird::operator<( const Node& rhs_node ) const {
   try {
      const Bird& rhs_bird = dynamic_cast<const Bird&>(rhs_node);  /// First, try to dynamically cast `rhs_node` to a Bird.
      return *this < rhs_bird;               /// If both the left and right sides are Birds, then, use the Bird comparison like @ref Bird_comparison "operator<( Bird& rhs_bird )"
   } catch ( bad_cast& exception ) {        /// If `rhs_node` is not a Bird, it will throw a `bad_cast` exception...
      return Animal::operator<( rhs_node ); /// which will be caught and we will try an Animal comparison like @ref Animal_comparison "Animal::operator<( Animal& rhs_animal )"
   }
}
