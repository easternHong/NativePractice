

cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  ${WARNING_FLAGS}  -std=gnu11 -pthread -marm ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} -std=c++11 -pthread ")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wl,--hash-style=gun")


if (${ANDROID_ABI} STREQUAL "x86")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} -std=c++11   -D__X86__")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNING_FLAGS} -std=c++11 -D__ARM__ ")
endif ()


add_library(
        crash-sdk
        SHARED
        native_crash_test.cpp
)


add_subdirectory(breakpad)
include_directories(breakpad)


find_library(
        log-lib
        log)


target_link_libraries(
        crash-sdk breakpad
        ${log-lib})