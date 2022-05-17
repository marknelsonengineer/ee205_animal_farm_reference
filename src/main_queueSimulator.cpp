///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
//          ee205_animal_farm - EE 205 - Spr 2022
//
/// Interactively run a simulation of a Queue
///
/// @file main_queueSimulator.cpp
/// @version 1.0
///
/// @author Mark Nelson <marknels@hawaii.edu>
/// @date   05_May_2022
///////////////////////////////////////////////////////////////////////////////

#include "Utility/QueueSimulator.h"


/// The entry point for queueSimulator
///
/// Interactively run a simulation of a Queue
int main() {
   QueueSimulator::printQueueSimulatorHeader();

   QueueSimulator queueSimulator;
   queueSimulator.runQueueSimulator( true );
}
