cmake_minimum_required(VERSION 2.8)

SET(PARENT_PROJECT geeksforgeeks)
project (${PARENT_PROJECT})

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/kadanes-algorithm "${CMAKE_CURRENT_BINARY_DIR}/kadanes-algorithm")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/is-sudoku-valid "${CMAKE_CURRENT_BINARY_DIR}/is-sudoku-valid")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/number-of-unique-paths "${CMAKE_CURRENT_BINARY_DIR}/number-of-unique-paths")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/sum-terms-nth-row "${CMAKE_CURRENT_BINARY_DIR}/sum-terms-nth-row")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/paths-to-reach-origin "${CMAKE_CURRENT_BINARY_DIR}/paths-to-reach-origin")
