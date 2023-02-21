###############################################################################
##                University of Hawaii, College of Engineering
##                ee205_animal_farm - EE 205 - Spring 2023
##
### CMake manages the building of source code.
###
### @see https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html
###
### @file   CMakeLists.txt
### @author Mark Nelson <marknels@hawaii.edu>
###############################################################################

cmake_minimum_required(VERSION 3.25)

project(ee205_animal_farm
        VERSION     4.0
        DESCRIPTION "All animals are equal, but some animals are more equal than others"
        LANGUAGES   CXX )

message( STATUS "CMAKE_SOURCE_DIR = [${CMAKE_SOURCE_DIR}]" )

set(CMAKE_CXX_STANDARD     17)    # It's time... plus you get string_view
set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_FLAGS       "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set(CMAKE_CXX_CLANG_TIDY
      clang-tidy;
      )

set(DOC_BUILD_DIR "${PROJECT_BINARY_DIR}/generated_docs")

find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)

if (DOXYGEN_FOUND)
   message(STATUS "Generating documentation using Doxygen")

   # Project
   set(DOXYGEN_PROJECT_NUMBER ${CMAKE_PROJECT_VERSION})
   set(DOXYGEN_PROJECT_BRIEF ${PROJECT_DESCRIPTION})
   set(DOXYGEN_PROJECT_LOGO "images/animal_farm_logo.jpg")
   set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/generated_docs)
   set(DOXYGEN_STRIP_FROM_PATH ${PROJECT_PARENT_DIR})
   set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
   set(DOXYGEN_TAB_SIZE 3)
   set(DOXYGEN_ALIASES "pattern=@par Design Pattern: ")  # Create a custom @pattern tag
   set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
   set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

   # Build
   set(DOXYGEN_EXTRACT_PRIVATE YES)
   set(DOXYGEN_EXTRACT_PRIV_VIRTUAL YES)
   set(DOXYGEN_EXTRACT_PACKAGE YES)
   set(DOXYGEN_EXTRACT_STATIC YES)
   set(DOXYGEN_EXTRACT_LOCAL_METHODS YES)
   set(DOXYGEN_INTERNAL_DOCS YES)
   set(DOXYGEN_CASE_SENSE_NAMES YES)
   set(DOXYGEN_SORT_MEMBERS_CTORS_1ST YES)   # Put constructors first

   # Messages
   set(DOXYGEN_QUIET YES)
#  set(DOXYGEN_WARN_AS_ERROR FAIL_ON_WARNINGS)   # @todo Consider turning this off for students

   # Input
   set(DOXYGEN_IMAGE_PATH images/)
   set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "README.md")

   # Source Browser
   set(DOXYGEN_SOURCE_BROWSER YES)           # @todo Turn this off for students
   set(DOXYGEN_STRIP_CODE_COMMENTS NO)
   set(DOXYGEN_CLANG_ASSISTED_PARSING YES)
   set(DOXYGEN_CLANG_OPTIONS "-std=c++17 -I /usr/include/llvm -I /usr/lib/clang/14.0.6/include" )

   # Index

   # HTML
   set(DOXYGEN_GENERATE_HTML YES)
   set(DOXYGEN_HTML_EXTRA_STYLESHEET "html/extraStyleSheet.css")
   set(DOXYGEN_HTML_COLORSTYLE LIGHT)
   set(DOXYGEN_HTML_TIMESTAMP YES)
   set(DOXYGEN_GENERATE_TREEVIEW YES)

   # LaTeX

   # RTF

   # Man

   # XML

   # Docbook

   # Autogen

   # Pearlmod

   # Preprocessor
   set(DOXYGEN_MACRO_EXPANSION YES)
   set(DOXYGEN_EXPAND_ONLY_PREDEF YES)

   # External

   # Dot
   set(DOXYGEN_HAVE_DOT YES)
   set(DOXYGEN_DOT_NUM_THREADS 1)
   set(DOXYGEN_UML_LOOK YES)
   set(DOXYGEN_UML_LIMIT_NUM_FIELDS 100)
   set(DOXYGEN_DOT_UML_DETAILS YES)
   set(DOXYGEN_DOT_WRAP_THRESHOLD 80)
   set(DOXYGEN_TEMPLATE_RELATIONS YES)
   set(DOXYGEN_CALL_GRAPH YES)
   set(DOXYGEN_CALLER_GRAPH YES)
   set(DOXYGEN_DOT_IMAGE_FORMAT svg)
   set(DOXYGEN_INTERACTIVE_SVG YES)
   set(DOXYGEN_DOT_GRAPH_MAX_NODES 100)
   set(DOXYGEN_DOT_MULTI_TARGETS YES)

#  set(DOXYGEN_DOT_TRANSPARENT YES)
#  set(DOXYGEN_FULL_SIDEBAR NO)
#  set(DOXYGEN_DISABLE_INDEX NO)
#  set(DOXYGEN_PAPER_TYPE letter)
#  set(DOXYGEN_VERBATIM_HEADERS YES)

   message(STATUS "DOXYGEN_OUTPUT_DIRECTORY = [${DOXYGEN_OUTPUT_DIRECTORY}]")

   doxygen_add_docs(Doxygen
           ${CMAKE_SOURCE_DIR}/src
           ${CMAKE_SOURCE_DIR}/README.md
           ${CMAKE_SOURCE_DIR}/CONTRIBUTE.md
           ${CMAKE_SOURCE_DIR}/DOXYGEN.md
           ${CMAKE_SOURCE_DIR}/RELEASE.md
           ${CMAKE_SOURCE_DIR}/tests/INSTALLING_BOOST_TESTS.md
           ${CMAKE_SOURCE_DIR}/Statistics.md
           ALL
           COMMENT "Generating doxygen documentation for ${PROJECT_NAME} to ${DOXYGEN_OUTPUT_DIRECTORY}"
           )

   add_custom_command(TARGET Doxygen
           PRE_BUILD
           COMMAND rsync --recursive --mkpath --checksum --delete ${CMAKE_SOURCE_DIR}/images ${DOXYGEN_OUTPUT_DIRECTORY}/html
           COMMENT "Updating images directory"
           )

   add_custom_command(TARGET Doxygen
           PRE_BUILD
           COMMAND ./bin/stats.py
           COMMENT "Updating statistics"
           WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
           )

   add_custom_command(TARGET Doxygen
           POST_BUILD
           COMMAND rsync --recursive --checksum --delete --compress --stats ${DOXYGEN_OUTPUT_DIRECTORY}/html/ marknels@uhunix.hawaii.edu:~/public_html/ee205/${CMAKE_PROJECT_NAME}
           COMMENT "Pushing files to UHUnix"
           )

else (DOXYGEN_FOUND)
   message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

message(STATUS "PROJECT_BINARY_DIR = [${PROJECT_BINARY_DIR}]")

add_subdirectory(tests)

# Group related source files together... This is the module-level dependency map for Animal Farm
set(SOURCE_FILES_GENERAL                                 src/config.h src/Utility/Random.h src/Utility/Random.cpp)
set(SOURCE_FILES_ANIMALS         ${SOURCE_FILES_GENERAL} src/Animal/Animal.h src/Animal/Animal.cpp src/Container/Node.h src/Utility/Gender.h src/Utility/Gender.cpp src/Utility/Weight.h src/Utility/Weight.cpp src/Utility/Trim.h src/Utility/Trim.cpp src/Utility/Name.h src/Utility/Name.cpp)
set(SOURCE_FILES_MAMMALS         ${SOURCE_FILES_ANIMALS} src/Animal/Mammal/Mammal.h src/Animal/Mammal/Mammal.cpp src/Utility/Color.h src/Utility/Color.cpp)
set(SOURCE_FILES_CATS            ${SOURCE_FILES_MAMMALS} src/Animal/Mammal/Cat/Cat.h src/Animal/Mammal/Cat/Cat.cpp)
set(SOURCE_FILES_DOGS            ${SOURCE_FILES_MAMMALS} src/Animal/Mammal/Dog/Dog.cpp src/Animal/Mammal/Dog/Dog.h)
set(SOURCE_FILES_BIRDS           ${SOURCE_FILES_ANIMALS} src/Animal/Bird/Bird.h src/Animal/Bird/Bird.cpp src/Animal/Bird/Finch.h src/Animal/Bird/Finch.cpp src/Animal/Bird/Chicken.cpp src/Animal/Bird/Chicken.h)
set(SOURCE_FILES_ANIMAL_FACTORY  ${SOURCE_FILES_CATS} ${SOURCE_FILES_DOGS} ${SOURCE_FILES_BIRDS} src/Animal/AnimalFactory.h src/Animal/AnimalFactory.cpp)

set(SOURCE_FILES_LISTS ${SOURCE_FILES_GENERAL} src/Container/Node.h src/Container/Container.h src/Container/Container.cpp src/Container/List.h src/Container/List.cpp)
set(SOURCE_FILES_SINGLY_LINKED_LISTS ${SOURCE_FILES_LISTS} src/Container/SinglyLinkedList.h src/Container/SinglyLinkedList.cpp)
set(SOURCE_FILES_DOUBLY_LINKED_LISTS ${SOURCE_FILES_LISTS} src/Container/DoublyLinkedList.h src/Container/DoublyLinkedList.cpp)
set(SOURCE_FILES_QUEUES ${SOURCE_FILES_DOUBLY_LINKED_LISTS} src/Container/Queue.h)
set(SOURCE_FILES_STACKS ${SOURCE_FILES_SINGLY_LINKED_LISTS} src/Container/Stack.h)
set(SOURCE_FILES_TREES ${SOURCE_FILES_LISTS} src/Container/BinarySearchTree.h src/Container/BinarySearchTree.cpp src/Container/Tree.cpp src/Container/Tree.h)

set(SOURCE_FILES_CAT_EMPIRE   ${SOURCE_FILES_CATS} ${SOURCE_FILES_TREES} ${SOURCE_FILES_QUEUES} src/Animal/Mammal/Cat/CatEmpire.cpp src/Animal/Mammal/Cat/CatEmpire.h)
set(SOURCE_FILES_CAT_WRANGLER ${SOURCE_FILES_CATS} ${SOURCE_FILES_DOUBLY_LINKED_LISTS} src/Animal/Mammal/Cat/CatWrangler.h)
set(SOURCE_FILES_CAT_QUEUE    ${SOURCE_FILES_CATS} ${SOURCE_FILES_QUEUES} src/Animal/Mammal/Cat/CatQueue.h)
set(SOURCE_FILES_CAT_STACK    ${SOURCE_FILES_CATS} ${SOURCE_FILES_STACKS} src/Animal/Mammal/Cat/CatStack.h)

add_executable(catBegat       src/main_catBegat.cpp ${SOURCE_FILES_CAT_EMPIRE})
add_executable(catFamilyTree  src/main_catFamilyTree.cpp ${SOURCE_FILES_CAT_EMPIRE})
add_executable(catGenerations src/main_catGenerations.cpp ${SOURCE_FILES_CAT_EMPIRE})
add_executable(catList        src/main_catList.cpp ${SOURCE_FILES_CAT_EMPIRE})
add_executable(catTail        src/main_catTail.cpp ${SOURCE_FILES_CAT_EMPIRE})

add_executable(catTemplate      src/main_catTemplate.cpp      ${SOURCE_FILES_CATS})
add_executable(singlyLinkedList src/main_singlyLinkedList.cpp ${SOURCE_FILES_ANIMAL_FACTORY} ${SOURCE_FILES_SINGLY_LINKED_LISTS})
add_executable(doublyLinkedList src/main_doublyLinkedList.cpp ${SOURCE_FILES_DOUBLY_LINKED_LISTS} ${SOURCE_FILES_ANIMAL_FACTORY})
add_executable(scratch          src/main_scratch.cpp          ${SOURCE_FILES_BIRDS} ${SOURCE_FILES_TREES})

add_executable(queueSimulator src/main_queueSimulator.cpp ${SOURCE_FILES_QUEUES} src/Utility/QueueSimulator.h src/Utility/QueueSimulator.cpp)
