cmake_minimum_required(VERSION 2.8)

project(SocketPoC)

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

SET(TARGET_HEADERS
    LinuxServer.cpp
    Socket.hpp
   )

SET(TARGET_SOURCES
    main.cpp
    LinuxServer.cpp
    Socket.cpp
    )

add_executable(${PROJECT_NAME} ${TARGET_SOURCES})
