cmake_minimum_required(VERSION 3.11)

project(Turing CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Boost 1.78.0 REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(turing-machine src/main.cpp src/turing_machine.h src/turing_machine.cpp)
target_link_libraries(turing-machine PRIVATE Threads::Threads)

