project(IRoom)

set(FILES
    "${PROJECT_SOURCE_DIR}/IRoom.h"
)

add_library(
    ${PROJECT_NAME}
        INTERFACE
            ${FILES}
)

target_include_directories(
    ${PROJECT_NAME}
        INTERFACE
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:include>
)

#################################################################

project(SpikeTrapRoom)

set(FILES
    "${PROJECT_SOURCE_DIR}/SpikeTrapRoom.h"
    "${PROJECT_SOURCE_DIR}/SpikeTrapRoom.cpp"
)

add_library(
    ${PROJECT_NAME}
        ${FILES}
)

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:include>
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            IRoom
)

install(
    TARGETS
        ${PROJECT_NAME}
    DESTINATION
        lib
)
