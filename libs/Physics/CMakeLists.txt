file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(Physics ${SOURCES} ${HEADERS})
target_link_libraries(Physics PUBLIC UtilsLib config eigen ${GLOBAL_LIBS} VisualsLib)
target_include_directories(Physics PUBLIC include PRIVATE ${CMAKE_SOURCE_DIR}/libs/Player/include)

# add_subdirectory(test)
