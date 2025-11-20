cmake_minimum_required(VERSION 3.28)

add_library(IRoom INTERFACE)

target_sources(IRoom
    PUBLIC FILE_SET HEADERS BASE_DIRS . FILES
        IRoom.h
)

target_link_libraries(
    IRoom
        INTERFACE
            RoomApi
)

#################################################################

add_library(SpikeTrapRoom)

target_sources(SpikeTrapRoom
    PRIVATE SpikeTrapRoom.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES SpikeTrapRoom.h
)

target_link_libraries(
    SpikeTrapRoom
        PRIVATE
            IRoom
)

install(
    TARGETS
        SpikeTrapRoom
)

add_subdirectory(tests)
