///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// A general-purpose Binary Search Tree
///
/// Trees do not preach learning and precepts.  They preach, undeterred by
/// particulars, the ancient law of life.
///
/// @file BinarySearchTree.cpp
/// @author Mark Nelson <marknels@hawaii.edu>
///////////////////////////////////////////////////////////////////////////////

// Set to trace the flow of execution through this code
// #define TRACE

#include <cassert>
#include <random> // For test_bulk_erase_from_Tree

#include "../config.h"
#include "BinarySearchTree.h"


using namespace std;


void BinarySearchTree::add( Node* newNode ) {
   TRACE_START

   /// @throws invalid_argument If `newNode` is `nullptr`.
   if( newNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": newNode can't be nullptr" );
   }

   /// @throws domain_error If `newNode` is not valid.
   if( !newNode->validate() ) {
      throw domain_error( PROGRAM_NAME ": newNode is not valid" );
   }

   /// @throws logic_error If `newNode` is already in the Tree.
   if( isIn( newNode ) ) {
      throw logic_error( PROGRAM_NAME ": Node is already in Tree!" );
   }

   assert( validate() );
   // Do the deed

   newNode->reset();   // These should already be null, but I'd like to make sure

   if( root == nullptr ) {  // If the BST is empty, then...
      root = newNode;
   } else {
      add( root, newNode );
   }

   // Done
   count++;
   assert( validate() );

   #ifdef DEBUG
   // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
   // newNode->dump();
   #endif

   TRACE_END
}


/// This method assumes that it is called by `add( Node* newNode )` and its
/// validations will run on it.
void BinarySearchTree::add( Node* atNode, Node* newNode ) {
   TRACE_START

   /// @throws invalid_argument If `atNode` is `nullptr`.
   if( atNode == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": atNode can't be nullptr" );
   }

   assert( atNode->validate() );

   /// @throws logic_error If `newNode` is already in the Tree.
   if( isIn( newNode ) ) {
      throw logic_error( PROGRAM_NAME ": Node is already in the Tree!" );
   }

   if( *newNode < *atNode ) {             // If newNode < atNode...
      if( atNode->left == nullptr ) {
         atNode->left = newNode;        // Hang it on the left side
      } else {
         add( atNode->left, newNode );  // Or descend to the left
      }
   }

   if( *newNode > *atNode ) {           // If newNode > atNode...
      if( atNode->right == nullptr ) {
         atNode->right = newNode;       // Hang it on the right side
      } else {
         add( atNode->right, newNode ); // Or descend to the right
      }
   }
   #ifdef DEBUG
      // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
      // newNode->dump();
   #endif

   TRACE_END
}


/// @param aNode Check aNode to see if it's in the BinarySearchTree
///
/// @return `true` if `aNode` is in the BinarySearchTree.  `false` if it's not.
bool BinarySearchTree::isIn( const Node* aNode ) const {
   TRACE_START
   Container::isIn( aNode );  // Container::isIn does basic checks, but doesn't know about the storage engine

   return isIn( root, aNode );
}


/// This method assumes that it is called by `isIn( Node* aNode )`
///
/// @param atNode The Node to start searching...
/// @param aNode  The Node to look for
///
/// @return `true` if `aNode` is in the BinarySearchTree.  `false` if it's not.
bool BinarySearchTree::isIn( const Node* atNode, const Node* aNode ) const {
   TRACE_START

   if( atNode == nullptr ) {
      return false;  // We've reached the end of the Tree and haven't found our node
   }

   if( atNode == aNode ) {
      return true;  // We've found the node we are looking for!
   }

   if( *aNode < *atNode ) {  // If aNode is < atNode, go left
      return isIn( atNode->left, aNode );
   }

   return isIn( atNode->right, aNode );  // Otherwise, go right
}


/// Do a pre-order traversal and dump every object in the BinarySearchTree
///
/// #### Sample Output
/**@verbatim
Container           this                0x7ffd447c4610
Container           count               10
Tree                root                0x72ceb0
================================================================================
================================================================================
Object              class               Finch
Object              this                0x72ceb0
Node                next                0
Node                prev                0
Node                left                0
Node                right               0x72d000
Animal              kingdom             Animalia
Animal              classification      Aves
Animal              species             Vestiaria coccinea
Animal              gender              Female
Animal              weight              0.035289 out of 0.0595249 Pound
Bird                name                Finch 0
@endverbatim */
void BinarySearchTree::dump() const noexcept {
   Tree::dump();

   dump( root );
}


/// Do a pre-order traversal and dump every object in the BinarySearchTree
void BinarySearchTree::dump( Node* atNode ) const noexcept {
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
/// @return `true` if the BinarySearchTree is healthy.  `false` if otherwise.
bool BinarySearchTree::validate() const noexcept {
   assert( Tree::validate() );

   #ifdef DEBUG
   Container::t_size treeCount = 0;
   #endif

   assert( validate( root, treeCount ));

   assert( size() == treeCount );

   #ifdef DEBUG
   // cout << PROGRAM_NAME ": BinarySearchTree is valid" << endl;
   #endif

   return true;
}


/// This method assumes that it is called by `validate()`
bool BinarySearchTree::validate( Node* atNode, Container::t_size& treeCount ) const noexcept {
   if( atNode == nullptr )
      return true;  // Looks good so far

   assert( atNode->validate() );  // Do an in-order traversal
   treeCount += 1;

   if( atNode->left != nullptr ) {
      assert( *atNode > *atNode->left );
      assert( validate( atNode->left, treeCount ));
   }

   if( atNode->right != nullptr ) {
      assert( *atNode->right > *atNode );
      assert( validate( atNode->right, treeCount ));
   }

   return true;
}


/// Removes nodeToRemove from the BinarySearchTree, but does not `delete` the Node from memory.
///
/// #### Internal
/// This algorithm differs significantly from standard BST delete algorithms as
/// they typically "swap" two nodes.  Because Animal Farm can have many different
/// kinds of Animals (Classes), you can't swap two nodes (in-place)... instead, you
/// actually need to remove one node and move another node into its place.
///
/// @see *ADTs, Data Structures and Problem Solving with CPP, Second Edition*
///      by Larry Nyhoff page 684.  I inlined the `search2` function
///      and replaced the swap functionality with moving two Nodes.
///
/// @return Returns nodeToRemove.
Node* BinarySearchTree::remove( Node* nodeToRemove ) {
   TRACE_START

   /// @throws invalid_argument If `nodeToRemove` is `nullptr`.
   if( nodeToRemove == nullptr ) {
      throw invalid_argument( PROGRAM_NAME ": nodeToRemove can't be nullptr" );
   }

   /// @throws domain_error If `nodeToRemove` is not valid.
   if( !nodeToRemove->validate() ) {
      throw domain_error( PROGRAM_NAME ": nodeToRemove is not valid" );
   }

   /// @throws logic_error If `nodeToRemove` is not in the BinarySearchTree.
   if( !isIn( nodeToRemove )) {
      throw logic_error( PROGRAM_NAME ": nodeToRemove is not in the BinarySearchTree!" );
   }

   assert( validate() );
   // Do the deed

   Node* parent = nullptr;        // The parent of the Node to be deleted.  If the root Rode is deleted, parent == nullptr
   Node* currentLocation = root;  // Search for the Node to be deleted.

   while( true ) {
      if( *currentLocation > *nodeToRemove ) {          // Descend left
         parent = currentLocation;
         currentLocation = currentLocation->left;
      } else if ( *nodeToRemove > *currentLocation ) {  // Descend right
         parent = currentLocation;
         currentLocation = currentLocation->right;
      } else {                                          // We must be at nodeToRemove
         break;
      }
   }

   // At this point, we've found the nodeToRemove...
   // And we have its parent Node (which is nullptr if the Node to remove is the root)
   assert( currentLocation == nodeToRemove );
   // cout << "currentLocation=" << currentLocation << endl;
   // cout << "         parent=" << parent << endl;

   if( currentLocation->left != nullptr && currentLocation->right != nullptr ) {
      // The node has 2 children...

      // successor is found by going right once and then left as far as possible
      Node* successor = currentLocation->right;  // First, go right...
      Node* successorParent = currentLocation;   // successorParent is self-explanatory

      while( successor->left != nullptr ) {      // Then, go left as far as you can...
         successorParent = successor;
         successor = successor->left;
      }

      // cout << "      successor=" << successor << endl;
      // cout << "successorParent=" << successorParent << endl;

      // Let's put the successor where it belongs.  There are 3 cases:
      if( parent == nullptr ) {  // The first case is when the node we are removing is the root node...
         root = successor;
      } else if( parent->left == currentLocation ) {  // The second & third cases hang successor off of the parent
         parent->left = successor;
      } else if( parent->right == currentLocation) {
         parent->right = successor;
      } else {
         assert( false );  // We should never get here
      }

      // Now, fixup successor parent by detaching the successor.  There are 2 cases:
      if( currentLocation == successorParent ) {
         // Do nothing... the currentLocation is the Node we are going to delete
      } else {
         assert( successorParent->left == successor );  // Otherwise, we *know* the successor is its parent's left node
         successorParent->left = successor->right;      // So set it's left node to whatever successor's right node is pointing to
      }

      // Finally, put successor in its place
      successor->left = currentLocation->left;
      if( currentLocation == successorParent) {
         // Do nothing... the currentLocation is the Node we are going to delete
      } else {
         successor->right = currentLocation->right;  // Reattach successor's subtree to it's right branch
      }

   } else {
      // The Node has 0 or 1 children...

      // subtree has the 0 or 1 children
      Node* subtree = currentLocation->left;
      if( subtree == nullptr ) {
         subtree = currentLocation->right;
      }

      if( parent == nullptr ) {
         root = subtree;
      } else if( parent->left == currentLocation ) {
         parent->left = subtree;
      } else {
         parent->right = subtree;
      }
   }

   nodeToRemove->reset();
   /// currentLocation is nodeToRemove and it's now fully detached

   // Done
   count--;
   assert( validate() );

   #ifdef DEBUG
   // cout << PROGRAM_NAME << ": " << __PRETTY_FUNCTION__ << endl;
   // nodeToRemove->dump();
   #endif

   TRACE_END

   return nodeToRemove;
}


/// @return A random Node from the BinarySearchTree.
Node* BinarySearchTree::getRandomNode() const noexcept {
   if( isEmpty() ) {
      return nullptr;  /// If the BinarySearchTree is empty return `nullptr`.
   }

   if( size() == 1 ) {
      return root ;
   }

   uniform_int_distribution<> randomIndexGenerator( 0, size()-1 );
   int randomIndex = randomIndexGenerator( ANIMAL_FARM_RNG );
   // FORMAT_LINE_FOR_DUMP( "BinarySearchTree", "randomIndex" )  << randomIndex  << std::endl ;

   return getRandomNode( root, &randomIndex );
}


Node* BinarySearchTree::getRandomNode( Node* aNode, int* nodesLeft ) const noexcept {
   assert( aNode != nullptr );
   Node* returnNode = aNode;

   if( aNode->left != nullptr && *nodesLeft >= 0 )
      returnNode = getRandomNode( aNode->left, nodesLeft );

   if( *nodesLeft == 0 ) {
      // aNode->dump();
      return aNode;
   }
   *nodesLeft -= 1;

   // FORMAT_LINE_FOR_DUMP( "BinarySearchTree", "count" )  << count  << std::endl ;
   // FORMAT_LINE_FOR_DUMP( "BinarySearchTree", "nodesLeft" )  << *nodesLeft  << std::endl ;
   // FORMAT_LINE_FOR_DUMP( "BinarySearchTree", "aNode" )  << aNode  << std::endl ;
   // FORMAT_LINE_FOR_DUMP( "BinarySearchTree", "returnNode" )  << returnNode  << std::endl ;

   if( aNode->right != nullptr && *nodesLeft >= 0 )
      returnNode = getRandomNode( aNode->right, nodesLeft );

   return returnNode;
}
