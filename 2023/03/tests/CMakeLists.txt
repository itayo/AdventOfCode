
project("${YEAR}-${DAY}-TESTS" DESCRIPTION "Advent of Code ${YEAR}-${DAY}")

add_executable(${PROJECT_NAME}
        ../src/day.h
        ../src/day.cpp
        tests.cpp
)
target_link_libraries(
        ${PROJECT_NAME}
        GTest::gtest_main
        AdventOfCodeLib
        ${YEAR}-${DAY}-day
)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/testInput1.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/testInput2.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)