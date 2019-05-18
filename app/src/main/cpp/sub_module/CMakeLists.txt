cmake_minimum_required(VERSION 3.4.1)

set(UTILS_SOURCE
        sub_module.cpp
        )

#sub_module 本目录的
add_library(sub_module
        STATIC
        ${UTILS_SOURCE}
        )
target_link_libraries(sub_module)