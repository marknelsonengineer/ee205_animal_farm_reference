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


/// Return the ordinal number suffix of a number.
///
/// Ordinal numbers always have a suffix tacked onto the end; cardinal numbers do not.
///
///   - Ordinal numbers indicate position or order in relation to other numbers.
///   - Cardinal numbers, on the other hand, express a quantity of something.
///
/// @see https://www.grammarly.com/blog/how-to-write-ordinal-numbers-correctly/
string getEnglishSuffix( int n ) {
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

   return suffix;
}


/// @todo Document this
void CatEmpire::catBegat() const {

}


/// Print a Family Tree of 20 Cats
///
/// Visualize the tree from Left-to-right.  Here are the rules:
///
///   - If the tree is empty, print “`No cats!`”
///   - You’ll need to keep track of your depth, so pass 1 into depth and then
///     increment depth on each call to `dfsInorderReverse`
///   - Do a reverse in-order traversal... so recurse down the right side of
///     the tree first, then print the parent, then recurse down the left side.
///     This will print the family tree on its side.
///   - Print a cat name with these rules:
///     - Assume that each cat name is 6 characters… so print (6 x depth-1)
///       spaces... `cout << string( 6 * (depth-1), ' ' ) << atCat->name;`
///     - ...and then print the cat’s name
///     - If the Cat node is a leaf node (both `left` and `right == nullptr`), just print `endl`
///     - If the node has **both** a `left` and `right` child, print “`<`“ and `endl`
///     - If the node has a `left` **XOR** `right` child, print either “`/`“ or “`\`” as appropriate
///
/// #### You should end up with a family tree that looks like this:
///
///     Print a family tree of 20 cats
///
///                             Zulema
///                       Zinnia/
///                 Simpson<
///                       Saxonia\
///                             Sasha
///           Rolo<
///                 Rayma\
///                       Primo
///     Pierce<
///                 Peregrine\
///                                   Liana
///                             Laman<
///                                   Kaya\
///                                               Jamee
///                                         Hemal/
///                       Grettel<
///                             Evelina\
///                                   Dolby\
///                                         Asher
///           Armen/
///
void CatEmpire::catFamilyTree() const noexcept {
   if( topCat == nullptr ) {
      cout << "No cats!" << endl;
      return;
   }

   dfsInorderReverse( topCat, 1 );
}


/// @todo Document this
void CatEmpire::catList() const noexcept {

}


/// @todo Document this
void CatEmpire::catGenerations() const noexcept {

}


/// @todo Document this
void CatEmpire::catTail( CatEmpire* tailList ) const noexcept {
   tailList = nullptr;
   if( tailList == nullptr )
      return;}


/// @todo Document this
void CatEmpire::dfsPreorder( Cat* atCat ) const noexcept {
   atCat = nullptr;
   if( atCat == nullptr )
      return;}


/// @todo Document this
void CatEmpire::dfsInorder( Cat* atCat ) const noexcept {
   atCat = nullptr;
   if( atCat == nullptr )
      return;
}


/// Depth First Search - Reverse Inorder Traversal... printing cats
/// to support `catFamilyTree`.
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


/// @todo Document this
void CatEmpire::catTail( Cat* atCat, CatEmpire* tailList ) const noexcept {
   atCat = nullptr;
   tailList = nullptr;
   if( atCat == nullptr && tailList == nullptr )
      return;
}
