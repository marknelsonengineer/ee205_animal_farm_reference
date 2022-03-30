///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// A Node with a previous member.  This can be used with a DoublyLinkedList.
///
/// @file NodeWithPrev.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   30_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

/// A Node with a previous member.
///
/// This can be used with a DoublyLinkedList.
class NodeWithPrev : public Node {
   friend class DoublyLinkedList;

protected:  ////////////////////// Protected Members ///////////////////////////
   NodeWithPrev* next = nullptr;  ///< Point to the next Node in the list or `nullptr`
                                  ///< if it's the last Node in the list.

   NodeWithPrev* prev = nullptr;  ///< Point to the previous Node in the list or
                                  ///< `nullptr` if it's the first Node in the list.

public:  /////////////////////////// Public Methods ////////////////////////////
   bool dump() const override;  ///< Output the contents of this object
   bool validate() const noexcept override;  ///< Check the Node

};
