cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME reverse-array-in-groups)

project (${PROJECT_NAME})

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall ${CMAKE_CXX_FLAGS}")
    set(CMAKE_CXX_FLAGS "-Werror ${CMAKE_CXX_FLAGS}")
endif (CMAKE_COMPILER_IS_GNUCXX)

if(MSVC)
    set(CMAKE_CXX_FLAGS "/W3 ${CMAKE_CXX_FLAGS}")
    #set(CMAKE_CXX_FLAGS "/WX ${CMAKE_CXX_FLAGS}")
    set(CMAKE_CXX_FLAGS "/MP ${CMAKE_CXX_FLAGS}")
	set(CMAKE_CXX_FLAGS "/bigobj ${CMAKE_CXX_FLAGS}")
endif(MSVC)

if(BUILD_WINDOWS)
    add_definitions("-DSK_IGNORE_STDINT_DOT_H")
endif(BUILD_WINDOWS)

if(BUILD_ANDROID)
    add_definitions("-DSK_BUILD_FOR_ANDROID_NDK")
endif(BUILD_ANDROID)

include_directories(
    "${PROJECT_SOURCE_DIR}/"
    )

FILE(GLOB SRCS
    ${PROJECT_SOURCE_DIR}/*.h
    ${PROJECT_SOURCE_DIR}/*.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER ${PARENT_PROJECT})
