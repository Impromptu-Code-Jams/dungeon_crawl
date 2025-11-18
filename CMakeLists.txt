cmake_minimum_required(VERSION 3.28)

project(DungeonCrawl)

set(CMAKE_CXX_STANDARD 23)

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
