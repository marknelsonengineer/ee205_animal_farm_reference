///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// An Abstract Tree class
///
/// @file Tree.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   22_May_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>  // For assert

#include "../config.h"
#include "Tree.h"

using namespace std;


/// Output the contents of this object
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
...
@endverbatim */
void Tree::dump() const noexcept {
   Container::dump();

   FORMAT_LINE_FOR_DUMP( "Tree", "root" ) << root << std::endl ;

   PRINT_HEADING_FOR_DUMP ;
}


bool Tree::validate() const noexcept {
   assert( Container::validate() );

   /// If `root` is `nullptr, then `count == 0`.
   if( root == nullptr ) {
      assert( count == 0 );
      assert( isEmpty() );
   } else {
      assert( count != 0 );
      assert( !isEmpty() );
   }

   /// If the Tree only has 1 Node, ensure the count == 1.
   if( root != nullptr ) {
      if( root->left == nullptr && root->right == nullptr ) {
         assert( count == 1 );
      }
   }

   return true;
}


void Tree::removeAll() noexcept {
   TRACE_START

   assert( validate() );

   while( root != nullptr ) {
      remove( root );
   }

   assert( validate() );
   assert( isEmpty() );

   TRACE_END
}
