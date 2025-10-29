file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(HW ${SOURCES} ${HEADERS})
target_link_libraries(HW PUBLIC UtilsLib config eigen ${GLOBAL_LIBS} VisualsLib)
target_include_directories(HW PUBLIC include)


