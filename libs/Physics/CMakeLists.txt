file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(Physics ${SOURCES} ${HEADERS})
target_link_libraries(Physics PUBLIC UtilsLib config eigen ${GLOBAL_LIBS} VisualsLib PlayerManager)
target_include_directories(Physics PUBLIC include)


target_include_directories(Physics PUBLIC include)

# add_subdirectory(test)
