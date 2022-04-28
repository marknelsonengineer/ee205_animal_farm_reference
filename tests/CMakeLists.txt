set (Boost_USE_STATIC_LIBS OFF)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

# 'Boost_Tests_run' is the target name
add_executable (Boost_Tests_run test_Gender.cpp ../src/Utility/Gender.h test_Weight.cpp ../src/Utility/Weight.h ../src/Utility/Weight.cpp test_Animal.cpp ../src/Animal/Animal.h ../src/Animal/Animal.cpp ../src/Animal/Mammal.h ../src/Animal/Mammal.cpp test_Cat.cpp ../src/Container/Node.h ../src/Animal/Cat.h ../src/Animal/Cat.cpp ../src/Utility/Color.h ../src/Container/Container.cpp ../src/Container/Container.h test_Container.cpp ../src/Container/List.h ../src/Container/List.cpp ../src/Container/SinglyLinkedList.h ../src/Container/SinglyLinkedList.cpp test_SinglyLinkedList.cpp test_DoublyLinkedList.cpp ../src/Container/DoublyLinkedList.h ../src/Container/DoublyLinkedList.cpp ../src/Container/Tree.cpp ../src/Container/Tree.h)
target_link_libraries (Boost_Tests_run ${Boost_LIBRARIES})
