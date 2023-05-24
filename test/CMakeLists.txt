message(STATUS "Tests - Build type: ${CMAKE_BUILD_TYPE}")

# list all your test source files
set(TEST_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/test_rasp_mem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/test_runner.c
)

# add Unity's source files
list(APPEND TEST_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/../unity/unity.c
)

# add an executable for the test runner
add_executable(run_tests ${TEST_SRC_FILES})

# link the executable to the libraries you're testing (if any)
target_link_libraries(run_tests rasp_mem)
