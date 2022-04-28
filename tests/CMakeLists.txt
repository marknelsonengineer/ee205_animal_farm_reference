set (Boost_USE_STATIC_LIBS OFF)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

# 'Boost_Tests_run' is the target name
add_executable (Boost_Tests_run test_Gender.cpp Utility/Gender.h test_Weight.cpp Utility/Weight.h Utility/Weight.cpp test_Animal.cpp Animal/Animal.h Animal/Animal.cpp Animal/Mammal.h Animal/Mammal.cpp test_Cat.cpp Container/Node.h Animal/Cat.h Animal/Cat.cpp Utility/Color.h Container/Container.cpp Container/Container.h test_Container.cpp Container/List.h Container/List.cpp Container/SinglyLinkedList.h Container/SinglyLinkedList.cpp test_SinglyLinkedList.cpp test_DoublyLinkedList.cpp Container/DoublyLinkedList.h Container/DoublyLinkedList.cpp Container/Tree.cpp Container/Tree.h)
target_link_libraries (Boost_Tests_run ${Boost_LIBRARIES})
