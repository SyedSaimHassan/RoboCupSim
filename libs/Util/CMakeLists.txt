file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(UtilsLib ${SOURCES} ${HEADERS})
target_link_libraries(UtilsLib PRIVATE ${GLOBAL_LIBS} eigen)
target_include_directories(UtilsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

