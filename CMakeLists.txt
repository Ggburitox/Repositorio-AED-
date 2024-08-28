cmake_minimum_required(VERSION 3.26)
project(RepositorioAED)

set(CMAKE_CXX_STANDARD 17)

add_executable(RepositorioAED main.cpp
        cmake-build-debug/ForwardList.h)
