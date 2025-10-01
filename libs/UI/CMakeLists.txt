    file(GLOB_RECURSE SOURCES "src/*.cpp")
    file(GLOB_RECURSE HEADERS "include/*.h")

    add_library(VisualsLib ${SOURCES} ${HEADERS})
    target_link_libraries(VisualsLib PRIVATE utils_lib state_lib cfg_lib vis_lib kin_lib)
    target_include_directories(VisualsLib PUBLIC include)

    # add_subdirectory(demo)
    # add_subdirectory(test)