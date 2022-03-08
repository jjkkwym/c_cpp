add_executable(app_test_libs app_test_libs.c)
target_link_libraries(app_test_libs whole_libs)

add_executable(sum sum.cpp)
target_link_libraries(sum whole_libs)

add_executable(store store.c)
target_link_libraries(store whole_libs)