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

set(FILES
    "${PROJECT_SOURCE_DIR}/CombatManager.h"
    "${PROJECT_SOURCE_DIR}/CombatManager.cpp"
    "${PROJECT_SOURCE_DIR}/DungeonEngine.h"
    "${PROJECT_SOURCE_DIR}/DungeonEngine.cpp"
)

add_library(
    ${PROJECT_NAME}
        STATIC
        ${FILES}
        
)

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC
            ${PROJECT_SOURCE_DIR}
)

target_link_libraries(
    Dungeon
        PRIVATE
            IRoom
)

