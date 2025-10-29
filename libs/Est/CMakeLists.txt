file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(Est ${SOURCES} ${HEADERS})
target_link_libraries(Est PUBLIC eigen config ${GLOBAL_LIBS})
target_include_directories(Est PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(Demo "src/KF.cpp")
target_link_libraries(Demo
Est config
)