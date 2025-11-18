cmake_minimum_required(VERSION 3.28)

project(DungeonCrawl)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(rooms)
add_subdirectory(dungeon)

################################################################

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/main.cpp"
)

add_executable(
    ${PROJECT_NAME}
        ${SOURCE_FILES}
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            Dungeon
            IRoom
            SpikeTrapRoom
)

install(
    TARGETS
        ${PROJECT_NAME}
    DESTINATION
        bin
)
