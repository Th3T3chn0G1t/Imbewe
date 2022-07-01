cmake_minimum_required(VERSION 3.23)

project(imbewe)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB imbewe imbewe/*.cpp imbewe/include/*.hpp)
add_executable(imbewe ${imbewe})
