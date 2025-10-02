file(GLOB_RECURSE SOURCES "src/.cpp")
file(GLOB_RECURSE HEADERS "include/.h")

add_library(config ${SOURCES} ${HEADERS})
target_link_libraries(config PUBLIC eigen ${GLOBAL_LIBS})
target_include_directories(config PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

