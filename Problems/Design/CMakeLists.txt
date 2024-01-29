cmake_minimum_required(VERSION 2.8)

SET(PARENT_PROJECT Design)
project (${PARENT_PROJECT})

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/0001_non-leaf-abstract-classes "${CMAKE_CURRENT_BINARY_DIR}/0001_non-leaf-abstract-classes")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/0002_alternatives-to-abstract-functions "${CMAKE_CURRENT_BINARY_DIR}/0002_alternatives-to-abstract-functions")
