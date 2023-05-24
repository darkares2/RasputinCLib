#include <pthread.h>
#include <string.h>
#undef RASP_MEMORY_DEBUG
#include "rasp_mem.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

RaspArray *rasp_array_init(size_t block_size) {
    pthread_mutex_lock(&lock);
    RaspArray *array = malloc(sizeof(RaspArray));
    array->block_size = block_size;
    array->array_length = 0;
    array->array_allocated = 10;
    array->data = malloc(array->array_allocated * block_size);
    pthread_mutex_unlock(&lock);
    return array;
}

void rasp_array_add(RaspArray *array, void *item) {
    pthread_mutex_lock(&lock);
    if (array->array_length >= array->array_allocated) {
        array->array_allocated *= 2;
        array->data = realloc(array->data, array->block_size * array->array_allocated);
    }
    memcpy(array->data + (array->block_size * array->array_length), item, array->block_size);
    array->array_length++;
    pthread_mutex_unlock(&lock);
}

void rasp_array_free(RaspArray *array) {
    pthread_mutex_lock(&lock);
    free(array->data);
    free(array);
    pthread_mutex_unlock(&lock);
}

void rasp_array_delete(RaspArray *array, size_t idx) {
    pthread_mutex_lock(&lock);
    array->array_length--;
    memcpy(array->data + (array->block_size * idx), array->data + (array->block_size * (idx+1)), (array->block_size * (array->array_length - idx)));
    pthread_mutex_unlock(&lock);
}
