# Collect sources and headers
file(GLOB_RECURSE GAMECONTROLLER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE GAMECONTROLLER_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
)

# Create the library
add_library(GameController
    ${GAMECONTROLLER_SOURCES}
    ${GAMECONTROLLER_HEADERS} # optional, just for IDEs
)

# Tell CMake where the headers live
target_include_directories(GameController PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link against Qt5 Widgets (or other Qt modules you need)
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)

target_link_libraries(GameController PUBLIC
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    config
    Ball
    VisualsLib
    PlayerManager
)
