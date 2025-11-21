cmake_minimum_required(VERSION 3.28)

project(DungeonCrawl)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/1b96fa13f549387b7549cc89e1a785cf143a1a50.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG main) # need main for benchmark::benchmark

FetchContent_MakeAvailable(
        googletest
        googlebenchmark)

enable_testing()
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Enable testing of the benchmark library." FORCE)

set(my_list "benchmark;benchmark_main;gmock;gmock_main;gtest;gtest_main")
foreach(loop_var IN LISTS my_list)
    set_target_properties(${loop_var} PROPERTIES FOLDER "Testing/Dependencies")
endforeach()

add_subdirectory(rooms)
add_subdirectory(dungeon)

################################################################

add_executable(
    DungeonCrawl
        main.cpp
)

target_link_libraries(
    DungeonCrawl
        PRIVATE
            Dungeon
            IRoom
            SpikeTrapRoom
)

install(
    TARGETS
        DungeonCrawl
)
