mkdir build
cd build

set curDir=%CD%

cmake ../project -G "Visual Studio 15 2017" -DCMAKE_MODULE_PATH=%curDir%/../project/cmake
cd ..