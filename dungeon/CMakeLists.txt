cmake_minimum_required(VERSION 3.28)

project(RoomApi)

set(FILES
    "${PROJECT_SOURCE_DIR}/RoomApi.h"
    "${PROJECT_SOURCE_DIR}/RoomApi.cpp"
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

################################################################

project(Dungeon)

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
    ${PROJECT_NAME}
        PRIVATE
            IRoom
)

