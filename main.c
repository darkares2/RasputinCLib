#include <stdio.h>
#include <stdlib.h>
#include "rasp_mem.h"
#include "rasp_hash.h"

// Count the number of set bits in a 32-bit integer
int pop(unsigned x) {
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333); x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

void fun() {
    int x = pop(0x0F0AA00F);
    printf("x: %d\n", x);
}

int main() {
    void *buf = malloc(500);

    hash_table *my_table = create_hash_table(5);

    insert(my_table, 10);
    insert(my_table, 20);
    insert(my_table, 30);

    node *found_node = search(my_table, 20);

    if (found_node != NULL) {
        printf("Found: %d\n", found_node->value);
    } else {
        printf("Not Found\n");
    }
    rasp_debug_memory_print();
    free(buf);
    rasp_debug_memory_print();

    fun();

    return 0;
}


