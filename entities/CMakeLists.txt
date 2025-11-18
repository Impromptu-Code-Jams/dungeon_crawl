cmake_minimum_required(VERSION 3.28)

project(Entities)

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/Player.cpp"
)

set(HEADER_FILES
    "${PROJECT_SOURCE_DIR}/Player.hpp"
    "${PROJECT_SOURCE_DIR}/Consumable.hpp"
    "${PROJECT_SOURCE_DIR}/Weapon.hpp"
    "${PROJECT_SOURCE_DIR}/Spell.hpp"    
    "${PROJECT_SOURCE_DIR}/Entity.h"
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

