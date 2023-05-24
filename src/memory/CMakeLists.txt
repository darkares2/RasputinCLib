add_library(rasp_mem rasp_mem.c rasp_mem_array.c)

target_include_directories(rasp_mem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
