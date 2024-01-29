set curDir=%CD%
set "curDir=%curDir:\=/%"
echo "%curDir%"

mkdir build
cd build
cmake ../project -G "Visual Studio 17 2022" -DCMAKE_MODULE_PATH=%curDir%/project/cmake
cd ..