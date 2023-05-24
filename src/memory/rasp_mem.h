

#include <stdlib.h>
extern void *rasp_debug_memory_alloc(size_t size, char *file, size_t line);
extern void *rasp_debug_memory_realloc(void * data, size_t size, char *file, size_t line);
extern void rasp_debug_memory_free(void *data, char *file, size_t line);
extern void rasp_debug_memory_print();

// Macros for memory debugging

#ifdef RASP_MEMORY_DEBUG
#define malloc(n) rasp_debug_memory_alloc(n, __FILE__, __LINE__)
#define realloc(n, m) rasp_debug_memory_realloc(n, m, __FILE__, __LINE__)
#define free(n) rasp_debug_memory_free(n, __FILE__, __LINE__)
#endif

typedef struct {
    size_t block_size;
    size_t array_allocated;
    size_t array_length;
    void *data;
} RaspArray;

// Array memory functions
extern RaspArray *rasp_array_init(size_t block_size);
extern void rasp_array_add(RaspArray *array, void *item);
extern void rasp_array_free(RaspArray *array);
extern void rasp_array_delete(RaspArray *array, size_t idx);
