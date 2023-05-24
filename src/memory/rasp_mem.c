#include <stdio.h>
#include <stdbool.h>
#undef RASP_MEMORY_DEBUG
#include "rasp_mem.h"

RaspArray *alloc_array = NULL;
typedef struct {
    char *file;
    size_t line;
    size_t size;
    void *data;
    bool active;
} Alloc_info;

void *rasp_debug_memory_alloc(size_t size, char *file, size_t line) {
    if (alloc_array == NULL) {
        alloc_array = rasp_array_init(sizeof(Alloc_info));
    }
    Alloc_info info;
    info.file = file;
    info.size = size;
    info.line = line;
    info.active = true;
    info.data = malloc(size);

    rasp_array_add(alloc_array, &info);

    return info.data;
}

void *rasp_debug_memory_realloc(void *data, size_t size, char *file, size_t line) {
    Alloc_info *ptr = alloc_array->data;
    for(int idx = 0; idx < alloc_array->array_length ; ++idx) {
        if (ptr[idx].data == data) {
            ptr[idx].data = realloc(data, size);
            ptr[idx].size = size;
            ptr[idx].file = file;
            ptr[idx].line = line;
            return ptr[idx].data;
        }
    }
    
    return NULL;
}


void rasp_debug_memory_free(void *data, char *file, size_t line) {
    Alloc_info *ptr = alloc_array->data;
    for(int idx = 0; idx < alloc_array->array_length ; ++idx) {
        if (ptr[idx].data == data) {
            free(ptr[idx].data);
            rasp_array_delete(alloc_array, idx);
            break;
        }
    }
}

void rasp_debug_memory_print() {
    Alloc_info *ptr = alloc_array->data;
    printf("Active allocations:\n");
    for(int idx = 0; idx < alloc_array->array_length ; ++idx) {
        printf("%s:%zu (%zu)\n", ptr[idx].file, ptr[idx].line, ptr[idx].size);
    }
    printf("--------------------------------------------\n");
}




