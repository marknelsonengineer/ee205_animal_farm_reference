///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "Node.h"

void Node::dump() const {

}

bool Node::compareByAddress ( const Node* node1, const Node* node2 ) {
   if( node1 > node2 )
      return true;
   return false;
}

bool Node::operator>(const Node &rightSide) {
   // `this` is the leftSide of the operator, so compare:
   // leftSide > rightSide

   return compareByAddress( this, &(Node&)rightSide );
}
