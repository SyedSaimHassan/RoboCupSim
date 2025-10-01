file(GLOB LIB_SOURCES
    *.cpp
    *.h
    Config/*.cpp
    Config/*.h
)

add_library(config ${LIB_SOURCES})

target_link_libraries(config
    PRIVATE
        ${GLOBAL_LIBS}
)
