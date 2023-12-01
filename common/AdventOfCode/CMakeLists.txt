project("AdventOfCodeLib")


add_library(${PROJECT_NAME} STATIC ../../2021/01/src/main.cpp)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/fileread.cpp
        inc/fileread.h
)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/inc/aoc>
)
