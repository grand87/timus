set curDir=%CD%
set "curDir=%curDir:\=/%"
echo "%curDir%"

mkdir build
cd build
cmake ../project -G "Visual Studio 15 2017" -DCMAKE_MODULE_PATH=%curDir%/project/cmake
cd ..