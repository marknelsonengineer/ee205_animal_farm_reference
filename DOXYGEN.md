Doxygen Notes
=============

Doxygen is the de facto standard tool for generating documentation from annotated C++ sources

Doxygen's website is:  https://www.doxygen.nl/index.html

#### Notes:
   - I prefer compile my own version of Doxygen
   - We use dot

#### To integrate Doxygen with CLion
   - TODO

#### To Run Doxygen
   - Install dot graphviz

#### To Build Doxygen from Source
   - `wget https://www.doxygen.nl/files/doxygen-1.9.4.src.tar.gz`
   - `gunzip -c doxygen-1.9.4.src.tar.gz | tar -xvf -`
   - `cd doxygen-1.9.4`
   - `mkdir build`
   - `cd build`
   - `cmake -G "Unix Makefiles" -Dbuild_search=ON "-DCMAKE_FIND_LIBRARY_SUFFIXES=.a" -Duse_libclang=NO -Denable_coverage=ON -Denable_parse=ON ..`
   - `make`
   - `make test`
   - `sudo make install`
