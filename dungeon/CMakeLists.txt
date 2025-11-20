cmake_minimum_required(VERSION 3.28)

add_library(RoomApi)

target_sources(RoomApi
    PRIVATE RoomApi.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES RoomApi.h
)

################################################################

add_library(DungeonEngine)

target_sources(DungeonEngine
    PRIVATE
      CombatManager.cpp
      DungeonEngine.cpp
      GetCh.h
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES 
        CombatManager.h
        DungeonEngine.h
)

target_link_libraries(
    DungeonEngine
        PUBLIC
            IRoom
)
add_subdirectory(tests)
