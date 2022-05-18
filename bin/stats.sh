#!/bin/bash

# @todo header

function print_title {
  printf "Project Statistics\n"
  printf "==================\n"
  printf "\n"
}

function processSourceFiles {
   rowHeader=("$1")
   shift

   arr=("$@")
   file_count=0
   raw_lines=0
   raw_bytes=0
   working_lines=0
   working_bytes=0

   for i in "${arr[@]}"; do
      # processFile "$i"
      ((file_count+=1))
      ((raw_lines+=`wc -l "$i" | awk '{print $1}'`))
      ((raw_bytes+=`wc -c "$i" | awk '{print $1}'`))
      ((working_lines+=`gcc -fpreprocessed -dD -E "$i" 2> /dev/null | sed 1,2d | grep "\S" | wc -l | awk '{print $1}'`))
      ((working_bytes+=`gcc -fpreprocessed -dD -E "$i" 2> /dev/null | sed 1,2d | grep "\S" | wc -c | awk '{print $1}'`))
   done

   printf "|%s|%'d|%'d|%'d|%'d|%'d|\n" "$rowHeader" "$file_count" $raw_lines $raw_bytes $working_lines $working_bytes
}

function process_row {
   array=()
   while IFS=  read -r -d $'\0'; do
      array+=("$REPLY")
   done < <(eval "${2} -print0")
   processSourceFiles "${1}" "${array[@]}"
}

function print_table_1 {
   printf "| Type         | Files | Lines | Bytes | Working Lines | Working Bytes |\n"
   printf "|--------------|------:|------:|------:|--------------:|--------------:|\n"
   process_row '.h'  'find ../src -name "*.h"'
   process_row '.cpp Sources' 'find ../src -name "*.cpp"'
   process_row '.cpp Tests' 'find ../tests -name "*.cpp"'
}

function print_number_of_unit_tests {
   printf "\n"
   unit_tests=`grep "BOOST_.*_TEST_CASE" ../tests/* | wc -l | awk '{print $1}'`
   printf "Number of unit tests:  %d\n" $unit_tests
}

function print_number_of_individual_tests {
   printf "\n"
   unit_tests=`egrep "BOOST_CHECK|BOOST_REQUIRE" ../tests/* | wc -l | awk '{print $1}'`
   printf "Number of individual tests:  %d\n" $unit_tests
}

function print_number_of_commits {
   printf "\n"
   unit_tests=`git rev-list --all --count`
   printf "Number of commits:  %d\n" $unit_tests
}


function print_date {
   printf "\n"
   printf "Automatically generated on %s\n" "`date`"
}

print_title
print_table_1
print_number_of_unit_tests
print_number_of_individual_tests
# print_number_of_commits  # Broken because remote directory is not a git repo
print_date
