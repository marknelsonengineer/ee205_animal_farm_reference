///////////////////////////////////////////////////////////////////////////////
//         University of Hawaii, College of Engineering
//         ee205_animal_farm - EE 205 - Spr 2023
//
/// An Abstract Tree class
///
/// @file Tree.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   22_May_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Container.h"

/// Holds Node classes in a generic Tree
class Tree : public Container {
protected:  ////////////////////// Protected Members ///////////////////////////
   Node* root = nullptr;  ///< The root for the tree

public:  /////////////////////////// Public Methods ////////////////////////////
   void removeAll() noexcept override;        ///< Remove all of the Nodes from this Tree

   void dump() const noexcept override;
   bool validate() const noexcept override;   ///< Ensure the object is valid
};
