set(DAY 03)
project("${YEAR}-${DAY}" DESCRIPTION "Advent of Code ${YEAR}-${DAY}")

add_executable(${PROJECT_NAME} src/day.cpp src/day.h)
set(CONFIG_FILE dayinfo.h)

target_sources(${PROJECT_NAME}
        PRIVATE
        src/main.cpp
        src/day.h

        )
target_link_libraries(${PROJECT_NAME} PRIVATE AdventOfCodeLib)
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
set(MAIN_PROJ $PROJECT_NAME)
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/input.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
configure_file(${CMAKE_SOURCE_DIR}/versioninfo.h.in ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG_FILE})
include_directories("${PROJECT_BINARY_DIR}")