cmake_minimum_required(VERSION 2.8)

SET(PARENT_PROJECT geeksforgeeks)
project (${PARENT_PROJECT})

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/kadanes-algorithm "${CMAKE_CURRENT_BINARY_DIR}/kadanes-algorithm")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/is-sudoku-valid "${CMAKE_CURRENT_BINARY_DIR}/is-sudoku-valid")
