cmake_minimum_required(VERSION 3.20)

project(cdragon)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(thirdparty)

add_executable(cdragon src/main.cpp
        src/strings.cpp
        src/jsons.cpp
        src/strings_util.cpp
)

enable_testing()

add_subdirectory(tests)
