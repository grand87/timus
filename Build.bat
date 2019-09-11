mkdir build
cd build
cmake ../project -G "Visual Studio 14 2015" -DCMAKE_MODULE_PATH=%CD%/../project/cmake
cd ..