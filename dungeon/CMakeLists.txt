cmake_minimum_required(VERSION 3.28)

add_library(RoomApi)

target_sources(RoomApi
    PRIVATE RoomApi.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES RoomApi.h
)

################################################################

add_library(Dungeon)

target_sources(Dungeon
    PRIVATE DungeonEngine.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES
        entities/Entity.h
        DungeonEngine.h
)

target_link_libraries(
    Dungeon
        PRIVATE
            IRoom
)

