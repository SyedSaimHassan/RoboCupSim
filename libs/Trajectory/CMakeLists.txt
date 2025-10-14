file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(Traj ${SOURCES} ${HEADERS})
target_link_libraries(Traj PUBLIC eigen ${GLOBAL_LIBS})
target_include_directories(Traj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)