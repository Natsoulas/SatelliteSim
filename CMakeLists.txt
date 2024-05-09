cmake_minimum_required(VERSION 3.25.2)
project(satsim VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/lib/eigen/cmake")
include_directories("${CMAKE_SOURCE_DIR}/include/")
include_directories("${CMAKE_SOURCE_DIR}/lib/eigen")

add_executable(satsim
    src/main.cpp
)
