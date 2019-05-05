cmake_minimum_required(VERSION 2.8)

SET(PARENT_PROJECT leetcode)
project (${PARENT_PROJECT})

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/subsets "${CMAKE_CURRENT_BINARY_DIR}/subsets")
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/median-of-two-sorted-arrays "${CMAKE_CURRENT_BINARY_DIR}/median-of-two-sorted-arrays")