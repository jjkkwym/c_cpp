add_executable(json_test json_test.c)
target_link_libraries(json_test cjson misc)

add_executable(log_test log_test.c)
target_link_libraries(log_test cjson misc)