project(DungeonTests)

set(FILES
    DungeonEngineTest.cpp
    RoomApiTest.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${FILES}
)

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC
            "../dungeon"
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            gtest_main
            DungeonEngine
            RoomApi
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})