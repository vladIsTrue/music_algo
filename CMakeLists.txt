cmake_minimum_required (VERSION 3.12)

project ("Kursach" VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include(GNUInstallDirs)

add_subdirectory("src")
