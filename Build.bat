set curDir=%CD%
set "curDir=%curDir:\=/%"
echo "%curDir%"

mkdir build
cd build
cmake ../project -DCMAKE_MODULE_PATH=%curDir%/project/cmake
cd ..