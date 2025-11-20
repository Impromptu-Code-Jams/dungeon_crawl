cmake_minimum_required(VERSION 3.28)

project(Entities)

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/Player.cpp"
    "${PROJECT_SOURCE_DIR}/Enemy.cpp"
)

set(HEADER_FILES
    "${PROJECT_SOURCE_DIR}/Player.hpp"
    "${PROJECT_SOURCE_DIR}/Item.hpp"
    "${PROJECT_SOURCE_DIR}/Effect.hpp"
    "${PROJECT_SOURCE_DIR}/Enemy.hpp"

)

add_library(
    ${PROJECT_NAME}
        STATIC
        ${SOURCE_FILES}
        ${HEADER_FILES}
        
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

