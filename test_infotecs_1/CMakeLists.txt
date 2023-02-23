cmake_minimum_required(VERSION 3.5)

project(test_infotecs_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_C_COMPILER gcc)
add_executable(test_infotecs_1 main.cpp stringprocessing.cpp stringprocessing.h socket.cpp socket.h streams.h streams.cpp)

install(TARGETS test_infotecs_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
