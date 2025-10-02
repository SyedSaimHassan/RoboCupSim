file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(config ${SOURCES} ${HEADERS})
target_link_libraries(config PUBLIC eigen)
target_link_directories(config PUBLIC include)