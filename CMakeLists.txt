cmake_minimum_required(VERSION 3.24.2)

if(NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

project(testproj CXX)

add_executable(test main.cpp candle.cpp candle.h tests.h)
