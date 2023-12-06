set(DAY 05)
project("${YEAR}-${DAY}" DESCRIPTION "Advent of Code ${YEAR}-${DAY}")

add_executable(${PROJECT_NAME} src/day.cpp src/day.h )
add_library(${PROJECT_NAME}-day STATIC )

target_sources(${PROJECT_NAME}-day
        PRIVATE
        src/day.cpp
        src/day.h
        )

target_include_directories(${PROJECT_NAME}-day
        PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        )


target_sources(${PROJECT_NAME}
        PRIVATE
        src/main.cpp
        )
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME}-day PRIVATE Threads::Threads)
target_link_libraries(${PROJECT_NAME}-day PRIVATE AdventOfCodeLib)
target_link_libraries(${PROJECT_NAME} PRIVATE AdventOfCodeLib ${PROJECT_NAME}-day)
target_include_directories(${PROJECT_NAME}
        PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/inc>
        )

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_subdirectory(tests)
