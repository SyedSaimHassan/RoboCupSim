file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

add_library(PhysicsLib ${SOURCES} ${HEADERS})
target_link_libraries(PhysicsLib PUBLIC VisualsLib UtilsLib config eigen ${GLOBAL_LIBS})
target_include_directories(PhysicsLib PUBLIC include)


add_subdirectory(demo)
# add_subdirectory(test)