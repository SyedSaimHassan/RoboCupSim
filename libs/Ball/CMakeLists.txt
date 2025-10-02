file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(Ball ${SOURCES} ${HEADERS})
target_link_libraries(Ball PUBLIC eigen ${GLOBAL_LIBS} config)
target_include_directories(Ball PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

