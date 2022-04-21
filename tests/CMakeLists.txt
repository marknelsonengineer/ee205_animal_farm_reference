set (Boost_USE_STATIC_LIBS OFF)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

# 'Boost_Tests_run' is the target name
add_executable (Boost_Tests_run test_Gender.cpp ../src/Gender.h test_Weight.cpp ../src/Weight.h ../src/Weight.cpp test_Animal.cpp ../src/Animal.h ../src/Animal.cpp ../src/Mammal.h ../src/Mammal.cpp test_Cat.cpp ../src/Node.h ../src/Cat.h ../src/Cat.cpp ../src/Color.h test_DoublyLinkedList.cpp ../src/List.h ../src/List.cpp ../src/SinglyLinkedList.h ../src/SinglyLinkedList.cpp test_SinglyLinkedList.cpp ../src/DoublyLinkedList.h ../src/DoublyLinkedList.cpp)
target_link_libraries (Boost_Tests_run ${Boost_LIBRARIES})
