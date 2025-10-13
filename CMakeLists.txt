cmake_minimum_required(VERSION 3.14)
project(DMSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- SDL2 setup ---
set(SDL2_ROOT "C:/SDL2/SDL2-2.32.8/x86_64-w64-mingw32")
include_directories(${SDL2_ROOT}/include)
link_directories(${SDL2_ROOT}/lib)

# --- Core library ---
add_library(DMSimLib
        Person.cpp
        Command.cpp
        BigCommands.cpp
        GraphicsRunner.cpp
        Node.h
        LinkedList.h
)

# --- Main executable ---
add_executable(DMSim ProjectRunner.cpp)
target_link_libraries(DMSim PRIVATE DMSimLib SDL2main SDL2)

# --- Tests ---
add_subdirectory(Tests)
