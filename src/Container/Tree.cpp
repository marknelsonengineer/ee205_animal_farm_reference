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

#include "../config.h"
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

   newNode->reset();   // These should already be null, but I'd like to make sure

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


/// This method assumes that it is called by `insert( Node* newNode )` and its
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


/// @param aNode Check aNode to see if it's in the Tree
///
/// @return `true` if `aNode` is in the Tree.  `false` if it's not.
bool Tree::isIn( Node* aNode ) const {
   Container::isIn( aNode );

   return isIn( rootNode, aNode );
}


/// This method assumes that it is called by `isIn( Node* aNode )`
///
/// @param atNode The Node to start searching...
/// @param aNode  The Node to look for
///
/// @return `true` if `aNode` is in the Tree.  `false` if it's not.
bool Tree::isIn( Node* atNode, Node* aNode ) const {
   if( atNode == nullptr )
      return false ;  // We've reached the end of the Tree and haven't found our node

   if( atNode == aNode )
      return true;  // We've found the node we are looking for!

   if( atNode > aNode )
      return isIn( atNode->left, aNode );

   return isIn( atNode->right, aNode );
}


/// @todo Add better documentation
void Tree::dump() const noexcept {
   Container::dump();

   FORMAT_LINE_FOR_DUMP( "Tree", "rootNode" )  << rootNode  << std::endl ;

   dump( rootNode );
}


/// Do an in-order traversal and dump every object in the Tree
void Tree::dump( Node* atNode ) const noexcept {
   if( atNode == nullptr )
      return;  // Done

   atNode->dump();

   dump( atNode->left );
   dump( atNode->right );
}


/// If something is not right, print a message and stop the validation.
/// It will not throw an exception.
///
/// @note This method calls `validate()` on each Node.
///
/// @return `true` if the Tree is healthy.  `false` if otherwise.
bool Tree::validate() const noexcept {
   assert( Container::validate() );

   return( validate( rootNode ));
}


/// This method assumes that it is called by `validate()`
bool Tree::validate( Node* atNode ) const noexcept {
   if( atNode == nullptr )
      return true;  // Looks good so far

   assert( atNode->validate() );

   if( atNode->left != nullptr )
      assert( atNode > atNode->left );

   if( atNode->right != nullptr )
      assert( atNode->right > atNode );

   assert( validate( atNode->left ));
   assert( validate( atNode->right ));

   return true;
}
