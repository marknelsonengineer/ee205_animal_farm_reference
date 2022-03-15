///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   14_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "catDatabase.h"

/// All of these functions return true if they succeed
extern bool updateCatName    ( const size_t index, const char*              name    ) ;  ///< Give the cat a new name.  Must not be empty.  All cats deserve a name.
extern bool fixCat           ( const size_t index                                   ) ;  ///< Fix the cat (you can't un-fix a cat).  You can, somewhat cruelly, repeatedly fix the cat.
extern bool updateCatWeight  ( const size_t index, const float              weight  ) ;  ///< Update the cat's weight.  Must be >0 or -1 if unknown
extern bool updateCatCollar1 ( const size_t index, const enum Color         color   ) ;  ///< Update the first part of the cat collar
extern bool updateCatCollar2 ( const size_t index, const enum Color         color   ) ;  ///< Update the second part of the cat collar
extern bool updateLicense    ( const size_t index, const unsigned long long license ) ;  ///< Update the license
