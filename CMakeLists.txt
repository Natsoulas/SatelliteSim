cmake_minimum_required(Version 3.25.2)
project(fast VERSION 0.1.0)
set (CMAKE_CXX STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)