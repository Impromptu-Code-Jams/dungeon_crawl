project(IRoom)

add_library(
    ${PROJECT_NAME}
        INTERFACE
)

target_include_directories(
    ${PROJECT_NAME}
        INTERFACE
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
            $<INSTALL_INTERFACE:include>
)

#################################################################

project(SpikeTrapRoom)

set(SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/SpikeTrapRoom.cpp"
)

add_library(
    ${PROJECT_NAME}
        ${SOURCE_FILES}
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
