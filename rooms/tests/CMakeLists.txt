### GTest
project(UnitTests)

set(FILES
    SpikeRoomTest.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Testing")

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

### Benchmark
project(BenchmarkTests)

set(FILES
    Benchmark.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Testing")

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC
            "../rooms"
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            benchmark::benchmark
            SpikeTrapRoom
)
