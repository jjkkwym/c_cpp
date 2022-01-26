add_subdirectory(utils_standard_c)

# add all libraries link static libs to all_libs
file(GLOB_RECURSE SRCS ./*.c)
file(GLOB_RECURSE HEADERS ./*.h)

add_library(whole_libs STATIC ${SRCS})
target_include_directories(whole_libs PUBLIC utils_standard_c log cJSON)