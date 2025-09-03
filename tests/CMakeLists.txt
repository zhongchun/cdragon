include(FetchContent)

set(googletest_SOURCE_DIR "${CMAKE_SOURCE_DIR}/thirdparty/googletest")

FetchContent_Declare(
        googletest
        SOURCE_DIR
        ${googletest_SOURCE_DIR}
        # https://github.com/google/googletest.git GIT_TAG release-1.13.0
)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

FetchContent_MakeAvailable(googletest)

add_executable(
        run_tests
        ../src/strings_util.cpp
        ../src/strings.cpp
        ../src/jsons.cpp
        strings_test.cpp
        jsons_test.cpp
        vector_test.cpp
        iterator_test.cpp
        smart_pointers.cpp
)

target_include_directories(run_tests PRIVATE ../src)

target_link_libraries(run_tests gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(run_tests)
