file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(Kin ${SOURCES} ${HEADERS})
target_link_libraries(Kin PUBLIC UtilsLib config eigen ${GLOBAL_LIBS} VisualsLib)
target_include_directories(Kin PUBLIC include)


