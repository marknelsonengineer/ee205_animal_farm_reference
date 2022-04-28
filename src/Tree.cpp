///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab15a_animal_farm_4 - EE 205 - Spr 2022
///
/// @file Tree.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   25_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>

#include "config.h"
#include "Tree.h"

using namespace std;


void Tree::insert( Node* newNode ) {
   TRACE_START

   /// @throws invalid_argument If `newNode` is `nullptr`.
   if( newNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": newNode can't be nullptr" );
   }

   /// @throws domain_error If `newNode` is not valid.
   if( !newNode->validate() ) {
      throw domain_error( PROGRAM_NAME ": newNode is not valid" );
   }

   /// @throws logic_error If `newNode` is already in the container.
   if( isIn( newNode ) ) {
      throw logic_error( PROGRAM_NAME ": Node is already in container!" );
   }

   assert( validate() );

   newNode->left  = nullptr;    // These should already be null, but I'd like to make sure
   newNode->right = nullptr;    /// @todo call newNode->reset();

   if( rootNode == nullptr ) {  // If the BST is empty, then...
      rootNode = newNode;
   } else {
      insert( rootNode, newNode );
   }

   count++;
   assert( validate() );

   #ifdef DEBUG
   // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
   // newNode->dump();
   #endif

   TRACE_END
}


/// This method assumes that this is called by `insert( Node* newNode )`and its
/// validations will run on it.
void Tree::insert( Node* atNode, Node* newNode ) {
   TRACE_START

   /// @throws invalid_argument If `atNode` is `nullptr`.
   if( atNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": atNode can't be nullptr" );
   }

   assert( atNode->validate() );

   /// @throws logic_error If `newNode` is already in the container.
   if( isIn( newNode ) ) {
      throw logic_error( PROGRAM_NAME ": Node is already in container!" );
   }

   if( atNode > newNode ) {
      if( atNode->left == nullptr ) {
         atNode->left = newNode;
      } else {
         insert( atNode->left, newNode );
      }
   }

   if( newNode > atNode ) {
      if( atNode->right == nullptr ) {
         atNode->right = newNode;
      } else {
         insert( atNode->right, newNode );
      }
   }
   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
}


void Tree::dfsInorderReverse( Node* atCat, int depth ) const {

}


void Tree::dfsInorder( Node* atCat ) const {

}


void Tree::catTail( Node* atCat, Tree* tailList ) const {

}


void Tree::dfsPreorder( Node* atCat ) const {

}
