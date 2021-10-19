file(GLOB_RECURSE SRCS ./*.c)
file(GLOB_RECURSE HEADERS ./*,h)

add_library(misc STATIC ${SRCS})

target_include_directories(misc PUBLIC log list)