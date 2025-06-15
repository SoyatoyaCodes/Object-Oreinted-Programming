cmake_minimum_required(VERSION 3.10)
project(lecture1)

file(GLOB SOURCES *.cpp)

foreach(src ${SOURCES})
    get_filename_component(exec_name ${src} NAME_WE)
    add_executable(${exec_name} ${src})
endforeach()
