cmake_minimum_required(VERSION 3.28)

add_library(IRoom INTERFACE)

target_sources(IRoom
    PUBLIC FILE_SET HEADERS BASE_DIRS . FILES
        IRoom.h
)

target_sources(IRoom
    PUBLIC FILE_SET HEADERS BASE_DIRS . FILES
        IRoom.h
)

target_link_libraries(
    IRoom
        INTERFACE
            RoomApi
)

set(FILES
    "ProcGenRoom.h"
    "ProcGenRoom.cpp"
)

#################################################################

add_library(
    SpikeTrapRoom
        STATIC
        ${FILES}
)

target_sources(SpikeTrapRoom
    PRIVATE SpikeTrapRoom.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES SpikeTrapRoom.h
)

target_link_libraries(
    SpikeTrapRoom
        PUBLIC
            IRoom
)

install(
    TARGETS
        SpikeTrapRoom
)

add_subdirectory(tests)

#################################################################

add_library(
    ProcGenRoom
        STATIC
        ${FILES}
)

target_sources(ProcGenRoom
    PRIVATE ProcGenRoom.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES ProcGenRoom.h
)

target_link_libraries(
    ProcGenRoom
        PUBLIC
            IRoom
)

install(
    TARGETS
        ProcGenRoom
)
