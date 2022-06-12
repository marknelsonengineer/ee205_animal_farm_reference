///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// A dynamic Array that holds Nodes
///
/// @file DynamicArray.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Array.h"
#include "Node.h"

/// A dynamic Array that holds Nodes
class DynamicArray : public Array {
public:  //////////////////////////// Constructors /////////////////////////////
   DynamicArray( Container::t_size newMaxSize );  ///< Create a new Dynamic Array

protected:  ///////////////////////// Member Variables /////////////////////////
   Node* array[];  ///< Holds a pointer to the dynamic array

};
