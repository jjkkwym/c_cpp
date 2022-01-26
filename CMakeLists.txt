cmake_minimum_required(VERSION 3.5.1)

project(c_cpp)

add_subdirectory(src)

add_subdirectory(libs)

add_subdirectory(test)

add_subdirectory(program)

add_subdirectory(app)

add_custom_target(LS COMMAND ls -l)