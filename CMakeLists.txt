cmake_minimum_required(Version 3.25.2)
project(fast VERSION 0.1.0)
set (CMAKE_CXX STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/lib/eigen/cmake")
include_directories("include/")
include_directories("lib/")

add_executable(fast
    src/main.cpp
)
