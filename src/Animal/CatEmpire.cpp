///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file CatEmpire.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>

#include "../config.h"
#include "CatEmpire.h"

using namespace std;


const char* getEnglishSuffix( int n ) {
   static thread_local string suffix;

   if( n <= 0 )
      suffix = "";

   switch( n%10 ) {
      case 0:
      case 9:
      case 8:
      case 7:
      case 6:
      case 5:
      case 4: suffix = "th";
         break;
      case 3: suffix = (n != 13) ? "rd" : "th";
         break;
      case 2: suffix = (n != 12) ? "nd" : "th";
         break;
      case 1: suffix = (n != 11) ? "st" : "th";
   }

   return suffix.c_str();
}


void CatEmpire::catBegat() const {

}


void CatEmpire::catFamilyTree() const noexcept {
   if( topCat == nullptr ) {
      cout << "No cats!" << endl;
      return;
   }

   dfsInorderReverse( topCat, 1 );
}


void CatEmpire::catList() const noexcept {

}


void CatEmpire::catGenerations() const noexcept {

}


void CatEmpire::catTail( CatEmpire* tailList ) const noexcept {

}


void CatEmpire::dfsPreorder( Cat* atCat ) const noexcept {

}


void CatEmpire::dfsInorder( Cat* atCat ) const noexcept {

}


void CatEmpire::dfsInorderReverse( Cat* atCat, int depth ) const noexcept {
   assert( atCat != nullptr );
   const int nameLen = 6;

   if( atCat->right != nullptr )
      dfsInorderReverse( (Cat*)atCat->right, depth + 1 );

   cout << string( (depth-1) * nameLen, ' ' ) << atCat->getName();

   if( atCat->left == nullptr && atCat->right == nullptr )
      cout << endl;
   if( atCat->left != nullptr && atCat->right != nullptr )
      cout << '<' << endl;
   if( atCat->left != nullptr && atCat->right == nullptr )
      cout << '\\' << endl;
   if( atCat->left == nullptr && atCat->right != nullptr )
      cout << '/' << endl;

   if( atCat->left != nullptr )
      dfsInorderReverse( (Cat*)atCat->left, depth + 1 );
}


void CatEmpire::catTail( Cat* atCat, CatEmpire* tailList ) const noexcept {

}
