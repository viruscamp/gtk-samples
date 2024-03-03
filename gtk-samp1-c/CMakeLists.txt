cmake_minimum_required(VERSION 3.20)
project(gtk-sample1-c)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

message("GTK_VERSION_MAJOR="${GTK_VERSION_MAJOR})
message("GTK3_VERSION_MAJOR="${GTK3_VERSION_MAJOR})

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES})
