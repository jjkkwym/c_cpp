file(GLOB_RECURSE SRCS ./*.c)
file(GLOB_RECURSE HEADERS ./*,h)

add_library(cjson STATIC ${SRCS})

target_include_directories(cjson PUBLIC .)
