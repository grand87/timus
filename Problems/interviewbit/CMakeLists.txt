cmake_minimum_required(VERSION 2.8)

SET(PARENT_PROJECT interviewbit)
project (${PARENT_PROJECT})

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/unique-paths-in-a-grid "${CMAKE_CURRENT_BINARY_DIR}/unique-paths-in-a-grid")
