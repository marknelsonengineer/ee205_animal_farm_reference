###############################################################################
###         University of Hawaii, College of Engineering
### @brief  ee205_animal_farm - EE 205 - Spr 2022
###
### CMake manages the building of source code.
###
### @file CMakeLists.txt
### @version 1.0
###
### @see https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html
###
### @author Mark Nelson <marknels@hawaii.edu>
### @date   05_May_2022
###############################################################################

set (Boost_USE_STATIC_LIBS OFF)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

if (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message(STATUS "Generating unit tests using BOOST Unit Test Framework")

   add_executable (All_Boost_Tests test_Gender.cpp ../src/Utility/Gender.h test_Weight.cpp ../src/Utility/Weight.h ../src/Utility/Weight.cpp test_Animal.cpp ../src/Animal/Animal.h ../src/Animal/Animal.cpp ../src/Animal/Mammal.h ../src/Animal/Mammal.cpp test_Cat.cpp ../src/Container/Node.h ../src/Animal/Cat.h ../src/Animal/Cat.cpp ../src/Utility/Color.h ../src/Container/Container.cpp ../src/Container/Container.h test_Container.cpp ../src/Container/List.h ../src/Container/List.cpp ../src/Container/SinglyLinkedList.h ../src/Container/SinglyLinkedList.cpp test_SinglyLinkedList.cpp test_DoublyLinkedList.cpp ../src/Container/DoublyLinkedList.h ../src/Container/DoublyLinkedList.cpp ../src/Container/Tree.cpp ../src/Container/Tree.h test_Tree.cpp ../src/Utility/Random.cpp ../src/Utility/Random.h test_Random.cpp ../src/Container/Queue.h ../src/Utility/QueueSimulator.cpp ../src/Utility/QueueSimulator.h test_Queue.cpp ../src/Animal/AnimalFactory.h ../src/Animal/AnimalFactory.cpp ../src/Utility/Trim.cpp ../src/Utility/Trim.h test_Trim.cpp)
   target_link_libraries (All_Boost_Tests ${Boost_LIBRARIES})

else (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message("BOOST Test needs to be installed to do unit testing")
endif (Boost_UNIT_TEST_FRAMEWORK_FOUND)
