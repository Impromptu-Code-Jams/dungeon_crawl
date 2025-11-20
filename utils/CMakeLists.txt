cmake_minimum_required(VERSION 3.28)

project(Utils)

add_library(
    ${PROJECT_NAME}
        INTERFACE
)

target_sources(
    ${PROJECT_NAME}
        INTERFACE
            FILE_SET HEADERS
            BASE_DIRS .
            FILES
                GetSingleChar.h
)
