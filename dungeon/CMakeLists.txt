cmake_minimum_required(VERSION 3.28)

project(Dungeon)

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/DungeonEngine.cpp"
)

add_library(
    ${PROJECT_NAME}
        STATIC
        ${SOURCE_FILES}
        
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

