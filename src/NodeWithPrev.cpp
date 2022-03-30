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
bool NodeWithPrev::dump() const {

   Node::dump();
   FORMAT_LINE( "NodeWithPrev", "prev" ) << prev << endl ;

   return true ;
}
