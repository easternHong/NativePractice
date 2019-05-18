cmake_minimum_required(VERSION 3.4.1)

set(UTILS_SOURCE
        common.cpp
        )

#sub_module 本目录的
add_library(common
        STATIC
        ${UTILS_SOURCE}
        )
target_link_libraries(common)