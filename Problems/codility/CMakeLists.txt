cmake_minimum_required(VERSION 2.8)

SET(PARENT_PROJECT codility)
project (${PARENT_PROJECT})

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/binary_gap "${CMAKE_CURRENT_BINARY_DIR}/binary_gap")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/CyclicRotation "${CMAKE_CURRENT_BINARY_DIR}/CyclicRotation")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/OddOccurrencesInArray "${CMAKE_CURRENT_BINARY_DIR}/OddOccurrencesInArray")


