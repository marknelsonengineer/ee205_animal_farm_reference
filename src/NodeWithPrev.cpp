///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file NodeWithPrev.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "config.h"
#include "NodeWithPrev.h"

using namespace std;


/// @returns `true` if everything worked correctly.  `false` if something went
///          wrong
///
/// #### Sample Output
/// @code
///     ==============================================
///     Cat     name                Kali
///     Cat     gender              Female
///     Cat     breed               Shorthair
///     Cat     isFixed             false
///     Cat     weight              1.3
/// @endcode
/// @todo update this output
///
void NodeWithPrev::dump() const {

   Node::dump();
   FORMAT_LINE_FOR_DUMP( "NodeWithPrev", "prev" ) << prev << endl ;
}


/// This method checks the Node.  If something is not right,
/// print out a message and stop the validation.  It will not throw an
/// exception.
///
/// @return True if the Node is healthy
bool NodeWithPrev::validate() const noexcept {
   Node::validate();

   if( prev == nullptr ) {
      return true;  /// `nullptr` is a valid value for the previous pointer.
   }

   /// @internal Perform a rudimentary recursive loop test and ensure
   ///           the prev pointer does not refer back to itself.
   ///           This also has the benefit of dereferencing the
   ///           pointer and ensuring it points to a valid address.
   if( prev == prev->prev ) {
      cout << PROGRAM_NAME << ": Recursive loop detected:  prev points to itself!" ;
      return false;
   }

   return true;
}
