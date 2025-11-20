cmake_minimum_required(VERSION 3.28)

add_library(RoomApi)

target_sources(RoomApi
    PRIVATE RoomApi.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES RoomApi.h
)

################################################################

set(FILES
    "CombatManager.h"
    "CombatManager.cpp"
    "DungeonEngine.h"
    "DungeonEngine.cpp"
)

add_library(
    Dungeon
        STATIC
        ${FILES}
        
)

target_include_directories(
    Dungeon
        PUBLIC
            ${PROJECT_SOURCE_DIR}
)

target_link_libraries(
    Dungeon
        PUBLIC
            IRoom
)

