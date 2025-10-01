file(GLOB LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/config/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/config/*.h
)

add_library(config ${LIB_SOURCES})

target_link_libraries(UI
    PRIVATE
        ${GLOBAL_LIBS}
)
