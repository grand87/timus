cmake_minimum_required(VERSION 2.8)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_definitions(-DLOCAL_TEST)

project (AlgoPractice)

find_program(CLANG_FORMAT_EXE NAMES "clang-format" DOC "Path to clang-format executable" )
if(NOT CLANG_FORMAT_EXE)
	message(STATUS "clang-format not found.")
else()
	message(STATUS "clang-format found: ${CLANG_FORMAT_EXE}")
	set(CLANG_FORMAT_STYLE_FILE "file")
	set(DO_CLANG_FORMAT "${CLANG_FORMAT_EXE}" "-i -style=${CLANG_FORMAT_STYLE_FILE}")
endif()

include(helper)

add_definitions(-DLOCAL_TESTS)

include_directories(${PROJECT_SOURCE_DIR}/../utils)

SUBDIRLIST(PROJECTS_SUBDIRS "${PROJECT_SOURCE_DIR}/../Problems")
FOREACH(subdir ${PROJECTS_SUBDIRS})
  ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/../Problems/${subdir} "${CMAKE_CURRENT_BINARY_DIR}/${subdir}")
ENDFOREACH()
