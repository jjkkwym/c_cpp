set(CMAKE_EXE_LINKER_FLAGS "-Wl,-Map=err.map")

add_executable(json_test json_test.c)
target_link_libraries(json_test cjson misc)

add_executable(log_test log_test.c)
target_link_libraries(log_test cjson misc)

add_executable(cmd cmd.c)
target_link_libraries(cmd cjson misc)

# add_executable(at_cmd at_cmd.c)
# target_link_libraries(at_cmd cjson misc pthread)
#set(CMAKE_EXE_LINKER_FLAGS "-Wl,-Map=err.map")
#add_executable(err_code err_code.c)
#target_link_libraries(err_code cjson misc)
add_executable(err_code err_code.c)
target_link_libraries(err_code cjson misc)

add_executable(test test.c)
target_link_libraries(test cjson misc)

add_executable(serial serial.c)
target_link_libraries(serial cjson misc)