#include <stdio.h>
#include <stdlib.h>
#include "rasp_mem.h"
#include "rasp_hash.h"


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

    return 0;
}
