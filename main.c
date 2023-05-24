#include <stdio.h>
#include <stdlib.h>
#include "rasp_mem.h"


int main() {
    void *buf = malloc(500);

    rasp_debug_memory_print();
    free(buf);
    rasp_debug_memory_print();

    return 0;
}
