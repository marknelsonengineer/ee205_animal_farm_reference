set (Boost_USE_STATIC_LIBS OFF)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

# 'Boost_Tests_run' is the target name
add_executable (Boost_Tests_run test_Gender.cpp ../src/Gender.h)
target_link_libraries (Boost_Tests_run ${Boost_LIBRARIES})
