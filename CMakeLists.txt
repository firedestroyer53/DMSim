cmake_minimum_required(VERSION 3.14)
project(DMSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- SDL2 setup ---
set(SDL2_ROOT "C:/SDL2/SDL2-2.32.8/x86_64-w64-mingw32")

# Include SDL2 headers
include_directories(${SDL2_ROOT}/include)

# Link SDL2 libraries
link_directories(${SDL2_ROOT}/lib)

# --- Main executable ---
add_executable(DMSim
        ProjectRunner.cpp
        Person.cpp
        Command.cpp
        BigCommands.cpp
        GraphicsRunner.cpp
        GraphicsRunner.h
)

# Link SDL2 libraries
target_link_libraries(DMSim SDL2main SDL2)

# Copy SDL2.dll to executable folder after build
add_custom_command(TARGET DMSim POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_ROOT}/bin/SDL2.dll"
        $<TARGET_FILE_DIR:DMSim>
)
