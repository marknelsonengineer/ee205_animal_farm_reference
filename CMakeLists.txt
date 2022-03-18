cmake_minimum_required(VERSION 3.20)

project(ee205_lab08d_animal_farm_1_to_clion
        VERSION 2.0
        DESCRIPTION "All animals are equal"
        LANGUAGES CXX )

message( STATUS "CMAKE_SOURCE_DIR = [${CMAKE_SOURCE_DIR}]" )

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set(DOC_BUILD_DIR "${PROJECT_BINARY_DIR}/generated_docs")

# @todo Add mscgen and dia to Doxygen
#find_package(Doxygen
#        REQUIRED dot
#        OPTIONAL_COMPONENTS mscgen dia)
find_package(Doxygen
        REQUIRED dot
        OPTIONAL_COMPONENTS mscgen dia)
if (DOXYGEN_FOUND)
   message(STATUS "Generating documentation using Doxygen")

   set(DOXYGEN_PROJECT_NUMBER "2.0")
   set(DOXYGEN_PROJECT_BRIEF "All animals are equal")
   set(DOXYGEN_GENERATE_HTML YES)
   set(DOXYGEN_PROJECT_LOGO "images/animal_farm_logo.jpg")
   set(DOXYGEN_GENERATE_TREEVIEW YES)
   set(DOXYGEN_DISABLE_INDEX NO)
   set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
   set(DOXYGEN_MULTILINE_CPP_IS_BRIEF YES)
   set(DOXYGEN_TAB_SIZE 3)
   set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
   set(DOXYGEN_ALIASES "pattern=@par Design Pattern:^^")
   set(DOXYGEN_SORT_MEMBERS_CTORS_1ST YES)
   set(DOXYGEN_IMAGE_PATH images/)
   set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
   set(DOXYGEN_CLANG_ASSISTED_PARSING YES)
   set(DOXYGEN_EXTRACT_PRIVATE YES)
   set(DOXYGEN_EXTRACT_PRIV_VIRTUAL YES)
   set(DOXYGEN_EXTRACT_STATIC YES)
   set(DOXYGEN_EXTRACT_LOCAL_METHODS YES)
   set(DOXYGEN_INTERNAL_DOCS YES)
   set(DOXYGEN_QUIET NO)
   set(DOXYGEN_HTML_TIMESTAMP YES)
   set(DOXYGEN_PAPER_TYPE letter)
   set(DOXYGEN_HIDE_UNDOC_RELATIONS NO)
   set(DOXYGEN_CALLER_GRAPH YES)
   set(DOXYGEN_HAVE_DOT YES)
   set(DOXYGEN_UML_LOOK YES)
   set(DOXYGEN_UML_LIMIT_NUM_FIELDS 50)
   set(DOXYGEN_TEMPLATE_RELATIONS YES)
   set(DOXYGEN_DOT_IMAGE_FORMAT svg)
   set(DOXYGEN_INTERACTIVE_SVG YES)
   set(DOXYGEN_DOT_GRAPH_MAX_NODES 100)
   set(DOXYGEN_DOT_UML_DETAILS YES)
   set(DOXYGEN_DOT_TRANSPARENT YES)
   set(DOXYGEN_CALL_GRAPH YES)
   set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/generated_docs)

   message(STATUS "PROJECT_BINARY_DIR = [${PROJECT_BINARY_DIR}]")
   message(STATUS "DOXYGEN_OUTPUT_DIRECTORY = [${DOXYGEN_OUTPUT_DIRECTORY}]")

   doxygen_add_docs(doc
           ${CMAKE_SOURCE_DIR}/src
           ${CMAKE_SOURCE_DIR}/README.md
           ALL
           COMMENT "Generating doxygen documentation for ${PROJECT_NAME} to ${DOXYGEN_OUTPUT_DIRECTORY}"
           )

else (DOXYGEN_FOUND)
   message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

add_executable(ee205_lab08d_animal_farm_1_to_clion src/main.cpp src/config.h src/catDatabase.cpp src/catDatabase.h src/addCats.cpp src/addCats.h src/updateCats.cpp src/updateCats.h src/deleteCats.cpp src/deleteCats.h src/reportCats.cpp src/reportCats.h)
