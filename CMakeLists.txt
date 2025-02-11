cmake_minimum_required(VERSION 3.11)

project(Turing CXX)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Boost 1.78.0 REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost найден: ${Boost_INCLUDE_DIRS}")
endif()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(TURING_MACHINE src/turing_machine.h src/turing_machine.cpp)
set(USER_INTERFACE src/user_interface.h src/user_interface.cpp)

add_executable(turing-machine src/main.cpp ${TURING_MACHINE} ${USER_INTERFACE})
target_include_directories(turing-machine PRIVATE ${CMAKE_SOURCE_DIR}/src ${Boost_INCLUDE_DIRS})
target_link_libraries(turing-machine PRIVATE Threads::Threads)
