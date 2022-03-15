cmake_minimum_required(VERSION 3.20)
project(ee205_lab08d_animal_farm_1_to_clion)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

add_executable(ee205_lab08d_animal_farm_1_to_clion main.cpp config.h catDatabase.cpp catDatabase.h addCats.cpp addCats.h updateCats.cpp updateCats.h deleteCats.cpp deleteCats.h reportCats.cpp reportCats.h)
