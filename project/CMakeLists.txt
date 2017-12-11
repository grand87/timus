cmake_minimum_required(VERSION 2.8)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project (AlgoPractice)

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/../Problems/Timus "${CMAKE_CURRENT_BINARY_DIR}/Timus")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/../Problems/Different "${CMAKE_CURRENT_BINARY_DIR}/Different")
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/../Problems/HackerRank "${CMAKE_CURRENT_BINARY_DIR}/HackerRank")
