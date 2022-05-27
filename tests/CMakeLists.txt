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
### @see https://www.jetbrains.com/help/clion/boost-test-support.html#add-boost-tests
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

   add_executable (All_Boost_Tests ../src/config.h ../src/Utility/Random.h ../src/Utility/Random.cpp ../src/Animal/Animal.h ../src/Animal/Animal.cpp ../src/Container/Node.h ../src/Utility/Gender.h ../src/Utility/Weight.h ../src/Utility/Weight.cpp ../src/Utility/Trim.h ../src/Utility/Trim.cpp ../src/Utility/Name.h ../src/Utility/Name.cpp ../src/Animal/Mammal/Mammal.h ../src/Animal/Mammal/Mammal.cpp ../src/Utility/Color.h ../src/Animal/Mammal/Cat/Cat.h ../src/Animal/Mammal/Cat/Cat.cpp ../src/Animal/AnimalFactory.h ../src/Animal/AnimalFactory.cpp ../src/Container/Node.h ../src/Container/Container.h ../src/Container/Container.cpp ../src/Container/List.h ../src/Container/List.cpp ../src/Container/SinglyLinkedList.h ../src/Container/SinglyLinkedList.cpp ../src/Container/DoublyLinkedList.h ../src/Container/DoublyLinkedList.cpp ../src/Container/Queue.h ../src/Container/BinarySearchTree.h ../src/Container/BinarySearchTree.cpp ../src/Animal/Mammal/Cat/CatEmpire.cpp ../src/Animal/Mammal/Cat/CatEmpire.h ../src/Utility/QueueSimulator.h ../src/Utility/QueueSimulator.cpp test_Animal.cpp test_Cat.cpp test_Container.cpp test_DoublyLinkedList.cpp test_Gender.cpp test_Name.cpp test_Queue.cpp test_Random.cpp test_SinglyLinkedList.cpp test_BinarySearchTree.cpp test_Trim.cpp test_Weight.cpp ../src/Animal/Mammal/Dog/Dog.cpp ../src/Animal/Mammal/Dog/Dog.h ../src/Animal/Bird/Bird.h ../src/Animal/Bird/Bird.cpp ../src/Animal/Bird/Finch.h ../src/Animal/Bird/Finch.cpp ../src/Animal/Bird/Chicken.h ../src/Animal/Bird/Chicken.cpp test_Bird.cpp ../src/Container/Tree.cpp ../src/Container/Tree.h test_OptimusCat.cpp test_DomainSpecificContainers.cpp ../src/Animal/Mammal/Cat/CatWrangler.h ../src/Container/Stack.h ../src/Animal/Mammal/Cat/CatQueue.h ../src/Animal/Mammal/Cat/CatStack.h ../src/Utility/Gender.cpp ../src/Utility/Color.cpp ../src/Container/Array.cpp ../src/Container/Array.h ../src/Animal/Mammal/Cat/CatPride.cpp ../src/Animal/Mammal/Cat/CatPride.h test_DynamicArray.cpp ../src/Container/DynamicArray.cpp ../src/Container/DynamicArray.h test_CatPride.cpp)
   target_link_libraries (All_Boost_Tests ${Boost_LIBRARIES})

else (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message("BOOST Test needs to be installed to do unit testing")
endif (Boost_UNIT_TEST_FRAMEWORK_FOUND)
