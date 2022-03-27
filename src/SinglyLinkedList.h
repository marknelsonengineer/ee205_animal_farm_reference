///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab10d_animal_farm_3 - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   27_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

class SinglyLinkedList {
protected:
   Node* head = nullptr;
   unsigned int count = 0;

public:
   const bool empty() const ;
   void push_front( Node* newNode );
   Node* pop_front() ;
   unsigned int size() const;

   Node* get_first() const;
   Node* get_next( const Node* currentNode ) const ;

}; // class SingleLinkedList



