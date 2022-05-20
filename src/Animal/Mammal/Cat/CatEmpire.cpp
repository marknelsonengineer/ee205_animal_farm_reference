///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A specialized Binary Search Tree that holds Cats
///
/// @file CatEmpire.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include <cassert>
#include <string>

#include "CatEmpire.h"
#include "../../../Container/Queue.h"

using namespace std;


/// Return the ordinal number suffix of a number.
///
/// Ordinal numbers always have a suffix tacked onto the end; cardinal numbers do not.
///
///   - Ordinal numbers indicate position or order in relation to other numbers.
///   - Cardinal numbers, on the other hand, express a quantity of something.
///
/// @see https://www.grammarly.com/blog/how-to-write-ordinal-numbers-correctly/'
/// @see https://en.wikipedia.org/wiki/English_numerals#Ordinal_numbers
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


/// Print a pedigree of Cats
///
/// A pedigree is a record of decedents.  In our case, we will implement a DFS
/// preorder search to print our pedigree.  The rules are:
///
///   - If the Tree is empty, print `No cats!`
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


/// Print a Family Tree of Cats
///
/// Visualize the Tree from Left-to-right.  Here are the rules:
///
///   - If the Tree is empty, print `No cats!`
///   - You’ll need to keep track of your depth, so pass 1 into depth and then
///     increment depth on each call to `dfsInorderReverse`
///   - Do a reverse in-order traversal... recursing down the right side of
///     the Tree first, then print the parent, then recurse down the left side.
///     This will print the family tree on its side.
///   - Print a Cat name with these rules:
///     - Assume that each Cat name is ~6 characters... print `6 * depth-1`
///       spaces and then print the Cat’s name:
///       - <code>cout << string( 6 * (depth-1), ' ' ) << atCat->name;</code>
///     - If the Cat node is a leaf node (both `left` and `right == nullptr`), just print `endl`
///     - If the node has **both** a `left` and `right` child, print `<` and `endl`
///     - If the node has a `left` **XOR** `right` child, print either `/` or `\` as appropriate
///
/// You should end up with a family tree that looks like this:
///
/**
@verbatim
                         Yummy
                   Young<
                         Vevina
             Valeska/
       Tiernan<
             Sweetie\
                   Starkitty\
                               Salvador
                         Roosevelt<
                                     Reena\
                                           Petty\
                                                 Orianna
                               Olympia/
 Mila<
             Manning\
                         Idola
                   Chrome<
                         Cade
       Avion<
             Adony
@endverbatim
 */
///
void CatEmpire::catFamilyTree() const noexcept {
   if( topCat == nullptr ) {
      cout << "No cats!" << endl;
      return;
   }

   dfsInorderReverse( topCat, 1 );
}


/// Print an alphabetized list of Cats
///
/// If the Tree is empty, print `No cats!`  If the tree is not empty, use an
/// in-order DFS to alphabetically traverse the Tree and print Cats.
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


/// Print Cats by generation
///
/// Before CatEmpire::catGenerations is called, the CatEmpire's Binary
/// Search Tree will be populated with some number of Cats.
/// CatEmpire::catGenerations will use a breadth first search (BFS) to iterate
/// over the Tree and print Cats by their generation.
///
/// This is implemented by using **both** Tree and Queue (DoublyLinkedList) in
/// combination.  Remember that Node has `left`, `right`, `prev` and `next`
/// pointers.  We will use them all.
///
/// An algorithm for BFS with level tracking is suggested in [this StackOverflow answer](https://stackoverflow.com/a/31248992/4886240)
///
/// You should end up with a BFS that looks like this:
///
///     1st Generation
///       Mila
///     2nd Generation
///       Avion  Tiernan
///     3rd Generation
///       Adony  Manning  Sweetie  Valeska
///     4th Generation
///       Chrome  Starkitty  Young
///     5th Generation
///       Cade  Idola  Roosevelt  Vevina  Yummy
///     6th Generation
///       Olympia  Salvador
///     7th Generation
///       Reena
///     8th Generation
///       Petty
///     9th Generation
///       Orianna
///
void CatEmpire::catGenerations() const {
   Queue catQueue;

   int level = 1;

   string generation = "1st Generation";
   cout << generation << endl;
   catQueue.push( topCat );
   catQueue.push( new Cat( "END OF " + generation ) );  // This is the marker for the end of the generation
   // catQueue.push( nullptr );

   while( !catQueue.empty() ) {
      Cat* aCat = (Cat*) catQueue.front();   // Peek at the front of the queue...
      Cat* aCatLeft = (Cat*) aCat->left;     // Get the left subtree
      Cat* aCatRight = (Cat*) aCat->right;   // Get the right subtree
      catQueue.pop();                        // Remove the Cat from the Queue (this resets the Node's pointers, which is why we have to get them first)

      if( aCat->getName().find( "END OF " ) != string::npos ) {
         level++;
         generation = to_string(level) + getEnglishSuffix( level ) + " Generation";
         catQueue.push( new Cat( "END OF " + generation ) );  // This is the marker for the end of the generation
         // catQueue.push( nullptr );

         cout << endl;

         if( ((Cat*) catQueue.front())->getName().find("END OF ") != string::npos )
            break;

         cout << generation << endl;
//       printf("%d%s Generation\n", level, getEnglishSuffix( level ) );

         continue;
      }

      cout << "  " << aCat->getName();
      //aCat->dump();

      if( aCatLeft != nullptr ) {
         catQueue.push( aCatLeft );
      }
      if( aCatRight != nullptr ) {
         catQueue.push( aCatRight );
      }
   }
}


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
void CatEmpire::dfsInorderReverse( Cat* atCat, unsigned long depth ) const noexcept {
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


/// Populate tailList from Cats in `this` class in reverse order
///
/// @param tailList A new CatEmpire Tree (but it's effectively a linked list)
///
/// It will create a new Tree that looks like this:
///
/**
@verbatim
Yummy\
      Young\
            Vevina\
                  Valeska\
                        Tiernan\
                              Sweetie\
                                    Starkitty\
                                          Salvador\
                                                Roosevelt\
                                                      Reena\
                                                            Petty\
                                                                  Orianna\
                                                                        Olympia\
                                                                              Mila\
                                                                                    Manning\
                                                                                          Idola\
                                                                                                Chrome\
                                                                                                      Cade\
                                                                                                            Avion\
                                                                                                                  Adony
@endverbatim
 */
///
void CatEmpire::catTail( CatEmpire* tailList ) const noexcept {
   assert( tailList->empty() );

   if( topCat == nullptr ) {
      cout << "No cats!" << endl;
      return;
   }

   catTail( topCat, tailList );
}


/// Reverse In-order Traversal... copying Cats from this list into `tailList`
/// to support CatEmpire::catTail
void CatEmpire::catTail( Cat* atCat, CatEmpire* tailList ) const {
   assert( atCat != nullptr );
   assert( tailList != nullptr );

   if( atCat->right != nullptr )
      catTail( (Cat*) atCat->right, tailList );

   Cat* newCat = new Cat( *atCat );

   tailList->insert( newCat );

   if( atCat->left != nullptr )
      catTail( (Cat*) atCat->left, tailList );
}
