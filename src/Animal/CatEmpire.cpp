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


/// Print a pedigree of 20 Cats
///
/// A pedigree is a record of decedents.  In our case, we will implement a DFS
/// preorder search to print a pedigree of cats.  The rules are:
///
///   - If the tree is empty, print `No cats!`
///   - If the Cat has both a left and right child, print <code><em>parent</em> begat <em>left</em> and <em>right</em></code> substituting the appropriate cat names
///   - If the Cat has only a left (or right) child, print <code><em>parent</em> begat <em>left</em></code> or <code><em>parent</em> begat <em>right</em></code>
///   - If the Cat doesn't have any children, then don’t print anything
///
/// You should end up with a family tree that looks like this:
///
///     Mila begat Avion and Tiernan
///     Avion begat Adony and Manning
///     Manning begat Chrome
///     Chrome begat Cade and Idola
///     Tiernan begat Sweetie and Valeska
///     Sweetie begat Starkitty
///     Starkitty begat Roosevelt
///     Roosevelt begat Olympia and Salvador
///     Olympia begat Reena
///     Reena begat Petty
///     Petty begat Orianna
///     Valeska begat Young
///     Young begat Vevina and Yummy
///
void CatEmpire::catBegat() const {
   if( topCat == nullptr ) {
      cout << "No cats!" << endl;
      return;
   }

   dfsPreorder( topCat );
}


/// Print a Family Tree of 20 Cats
///
/// Visualize the tree from Left-to-right.  Here are the rules:
///
///   - If the tree is empty, print `No cats!`
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
/// You should end up with a family tree that looks like this:
///
///     Print a family tree of 20 cats
///                             Yummy
///                       Young<
///                             Vevina
///                 Valeska/
///           Tiernan<
///                 Sweetie\
///                       Starkitty\
///                                   Salvador
///                             Roosevelt<
///                                         Reena\
///                                               Petty\
///                                                     Orianna
///                                   Olympia/
///     Mila<
///                 Manning\
///                             Idola
///                       Chrome<
///                             Cade
///           Avion<
///                 Adony
///
void CatEmpire::catFamilyTree() const noexcept {
   if( topCat == nullptr ) {
      cout << "No cats!" << endl;
      return;
   }

   dfsInorderReverse( topCat, 1 );
}


/// Print an alphabetized list of 20 Cats
///
/// If the tree is empty, print `No cats!`  If the tree is not empty, use an
/// in-order DFS to traverse the Tree and print Cats.
///
/// You should end up with a list that looks like this:
///
///     Adony
///     Avion
///     Cade
///     Chrome
///     Idola
///     Manning
///     Mila
///     Olympia
///     Orianna
///     Petty
///     Reena
///     Roosevelt
///     Salvador
///     Starkitty
///     Sweetie
///     Tiernan
///     Valeska
///     Vevina
///     Young
///     Yummy
///
void CatEmpire::catList() const noexcept {
   if( topCat == nullptr ) {
      cout << "No cats!" << endl;
      return;
   }

   dfsInorder( topCat );
}


/// @todo Document this
void CatEmpire::catGenerations() const noexcept {

}


/// @todo Document this
void CatEmpire::catTail( CatEmpire* tailList ) const noexcept {
   tailList = nullptr;
   if( tailList == nullptr )
      return;}


/// Depth First Search - Forward Preorder Traversal... printing cats
/// to support CatEmpire::catBegat
void CatEmpire::dfsPreorder( Cat* atCat ) const noexcept {
   assert( atCat != nullptr );

   if( atCat->left != nullptr && atCat->right != nullptr ) {
      cout << atCat->getName() << " begat " << ((Cat*) atCat->left)->getName() << " and " << ((Cat *) atCat->right)->getName() << endl;
      dfsPreorder( (Cat*) atCat->left);
      dfsPreorder( (Cat*) atCat->right);
      return;
   }

   if( atCat->left != nullptr && atCat->right == nullptr ) {
      cout << atCat->getName() << " begat " << ((Cat*) atCat->left)->getName() << endl;
      dfsPreorder( (Cat*) atCat->left );
      return;
   }

   if( atCat->left == nullptr && atCat->right != nullptr ) {
      cout << atCat->getName() << " begat " << ((Cat*) atCat->right)->getName() << endl;
      dfsPreorder( (Cat*) atCat->right );
      return;
   }
}


/// Depth First Search - Forward In-Order Traversal... printing cats
/// to support CatEmpire::catList
void CatEmpire::dfsInorder( Cat* atCat ) const noexcept {
   assert( atCat != nullptr );

   if( atCat->left != nullptr )
      dfsInorder( (Cat*) atCat->left );

   cout << atCat->getName() << endl;

   if( atCat->right != nullptr )
      dfsInorder( (Cat*) atCat->right );
}


/// Depth First Search - Reverse Inorder Traversal... printing cats
/// to support CatEmpire::catFamilyTree
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
