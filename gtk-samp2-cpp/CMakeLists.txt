cmake_minimum_required(VERSION 3.20)
project(gtk-sample2-cpp)

set(CMAKE_CPP_STANDARD 2017)

set(SOURCE_FILES main.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtkmm-3.0)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES})
