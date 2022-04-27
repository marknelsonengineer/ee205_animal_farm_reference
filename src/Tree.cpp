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


void Tree::addCat( Node* newCat ) {
   assert( newCat != nullptr );

   newCat->left  = nullptr;    // These should already be null, but I'd like to make sure
   newCat->right = nullptr;

   if( topCat == nullptr ) {  // If the BST is empty, then...
      topCat = newCat;

      return;
   }

   addCat( topCat, newCat );
}


void Tree::catFamilyTree() const {
   if( topCat == nullptr ) {
      cout << PROGRAM_NAME ": No cats!" << endl;
      return;
   }

   dfsInorderReverse( topCat, 1 );
}


void Tree::catList() const {

}


void Tree::catTail( Tree* tailList ) const {

}


void Tree::catBegat() const {

}


void Tree::catGenerations() const {

}


void Tree::addCat( Node* atCat, Node* newCat ) {
   assert( atCat != nullptr );
   assert( newCat != nullptr );

   if( atCat > newCat ) {
      if( atCat->left == nullptr ) {
         atCat->left = newCat;
      } else {
         addCat( atCat->left, newCat );
      }
   }

   if( newCat > atCat ) {
      if( atCat->right == nullptr ) {
         atCat->right = newCat;
      } else {
         addCat( atCat->right, newCat );
      }
   }
}


void Tree::dfsInorderReverse( Node* atCat, int depth ) const {
   assert( atCat != nullptr );
   const int nameLen = 6;

   if( atCat->right != nullptr )
      dfsInorderReverse( atCat->right, depth + 1 );

   /// @todo Fix this with C++
   cout << string( (depth-1) * nameLen, ' ' ) << atCat->speak();

   if( atCat->left == nullptr && atCat->right == nullptr )
      cout << endl;
   if( atCat->left != nullptr && atCat->right != nullptr )
      cout << '<' << endl;
   if( atCat->left != nullptr && atCat->right == nullptr )
      cout << '\\' << endl;
   if( atCat->left == nullptr && atCat->right != nullptr )
      cout << '/' << endl;

   if( atCat->left != nullptr )
      dfsInorderReverse( atCat->left, depth + 1 );
}


void Tree::dfsInorder( Node* atCat ) const {

}


void Tree::catTail( Node* atCat, Tree* tailList ) const {

}


void Tree::dfsPreorder( Node* atCat ) const {

}
