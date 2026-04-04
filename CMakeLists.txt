cmake_minimum_required(VERSION 3.10.0)
project(myProject_lab2 VERSION 0.1.0 LANGUAGES C CXX) # CXX is for C++

set(CMAKE_CXX_STANDARD 17)# standard of C++ is 17

add_executable(myProject_lab2 
src/main.cpp 
src/fact.cpp
src/fibonacci.cpp
src/power2.cpp
src/subtraction.cpp
src/sum.cpp
) # executable file is myProject_lab2

