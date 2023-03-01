///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A general-purpose list-based collection class.
///
/// @file List.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>

#include "../config.h"
#include "List.h"

using namespace std;


/// @param aNode Check this Node to see if it's in the List
///
/// @return `true` if `aNode` is in the List.  `false` if it's not.
bool List::isIn(const Node *aNode) const {

   Container::isIn( aNode );

   Node* currentNode = head;

   while( currentNode != nullptr ) {
      if( aNode == currentNode ) {
         return true;
      }
      currentNode = currentNode->next;
   }

   return false;  // Never found aNode in the List
}


/// This method depends on the Node's > operator.
///
/// @return `true` if the List is sorted.  `false` if it's not.
bool List::isSorted() const noexcept {
   assert( validate() );

   if( count <= 1 ) { // SPECIAL CASE:  The List is empty or only has one item...
      return true;
   }

   for( Node* i = head ; i->next != nullptr ; i = i->next ) {
      if( *i > *i->next ) {  // If the previous is greater than the next
         return false;       // ...then the List is *not* sorted
      }
   }

   return true;  // Everything looks kosher
}


/// @return The first Node in the List.  If the List is empty, return `nullptr`.
Node* List::getFirst() const noexcept {
   return head;
}


/// @param currentNode Start here
///
/// @return Return the Node that follows `currentNode` in the List
Node* List::getNext( const Node *currentNode) {
   /// @throws invalid_argument If `currentNode` is `nullptr`
   if( currentNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": currentNode must have a value." );
   }

   return currentNode->next;
}


void List::removeAll() noexcept {
   assert( validate() );

   while( head != nullptr ) {
      removeFront();
   }

   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": All Nodes have been deleted" << endl ;
   #endif

   assert( validate() );
   assert( isEmpty() );
}


/// Print the List and then each Node in it
///
/// #### Sample Output
/**@verbatim
Container           this                0x7ffe0bd54ce0
Container           count               10
List                head                0x7ffe0bd54ce0
================================================================================
================================================================================
Object              class               Finch
Object              this                0x973980
Node                next                0x973850
Node                prev                0
Node                left                0
Node                right               0
Animal              kingdom             Animalia
Animal              classification      Aves
Animal              species             Vestiaria coccinea
Animal              gender              Male
Animal              weight              0.00422841 out of 0.0595249 Pound
Bird                name                Finch 9
...
@endverbatim */
void List::dump() const noexcept {
   Container::dump();

   FORMAT_LINE_FOR_DUMP( "List", "head" )  << this  << std::endl ;
}


/// If something is not right, print a message and stop the validation.
/// It will not throw an exception.
///
/// @note This method calls `validate()` on each Node.
///
/// @return `true` if the List is healthy.  `false` if otherwise.
bool List::validate() const noexcept {
   assert( Container::validate() );

   /// If `head` is `nullptr`, then `count == 0`.
   if( head == nullptr ) {
      assert( count == 0 );
      assert( isEmpty() );
   } else {
      assert( count != 0 );
      assert( !isEmpty() );
   }

   /// If the list only has 1 Node, ensure the count == 1.
   if( head != nullptr ) {
      if( head->next == nullptr ) {
         assert( count == 1 );
      }
   }

   /// Count the number of nodes and ensure `count` is correct.
   Container::t_size forwardCount = 0;
   Node* currentNode = head;
   // Count forward through the List
   while( currentNode != nullptr ) {
      assert( currentNode->validate() ) ;  /// Validate every node in the list.
      forwardCount++;
      currentNode = currentNode->next;
   }
   assert( size() == forwardCount );

   #ifdef DEBUG
   // cout << PROGRAM_NAME ": List is valid" << endl;
   #endif

   return true;
} // validate()


Node* List::getRandomNode() const noexcept {
   assert( validate() );

   Node* currentNode = head;  // head is nullptr if the list is empty
   int randomIndex = 0;  // The default value if the list is empty

   if( !isEmpty() ) {
      uniform_int_distribution<>randomIndexGenerator( 0, size() - 1 );
      randomIndex = randomIndexGenerator( ANIMAL_FARM_RNG );
   }

   // cout << "Size = " << size() << "   randomIndex = " << randomIndex << endl;

   while( randomIndex > 0 ) {
      assert( currentNode != nullptr );
      currentNode = currentNode->next;
      randomIndex--;
   }

   if( isEmpty() ) { assert( currentNode == nullptr ); }
   if( !isEmpty() ) { assert( currentNode != nullptr ); }

   return currentNode;
}
