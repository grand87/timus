cmake_minimum_required(VERSION 2.8)

SET(PARENT_PROJECT geeksforgeeks)
project (${PARENT_PROJECT})

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/kadanes-algorithm "${CMAKE_CURRENT_BINARY_DIR}/kadanes-algorithm")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/is-sudoku-valid "${CMAKE_CURRENT_BINARY_DIR}/is-sudoku-valid")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/number-of-unique-paths "${CMAKE_CURRENT_BINARY_DIR}/number-of-unique-paths")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/sum-terms-nth-row "${CMAKE_CURRENT_BINARY_DIR}/sum-terms-nth-row")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/paths-to-reach-origin "${CMAKE_CURRENT_BINARY_DIR}/paths-to-reach-origin")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/find-duplicates-in-an-array "${CMAKE_CURRENT_BINARY_DIR}/find-duplicates-in-an-array")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/trapping-rain-water "${CMAKE_CURRENT_BINARY_DIR}/trapping-rain-water")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/rotate-array-by-n-elements "${CMAKE_CURRENT_BINARY_DIR}/rotate-array-by-n-elements")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/pair-with-given-sum-in-a-sorted-array "${CMAKE_CURRENT_BINARY_DIR}/pair-with-given-sum-in-a-sorted-array")

