project(Tests)

set(FILES
    SpikeRoomTest.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${FILES}
)

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC
            "../rooms"
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            gtest_main
            SpikeTrapRoom
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
