cmake_minimum_required(VERSION 3.5)

project(test_infotecs_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_infotecs_2 main.cpp socket.h socket.cpp)

install(TARGETS test_infotecs_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
