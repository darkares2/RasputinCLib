#include <stdio.h>
#include <stdlib.h>
#include "rasp_mem.h"
#include "rasp_hash.h"

hash_table* create_hash_table(int size) {
    hash_table* new_table;

    if (size < 1) return NULL;

    // Allocate memory for the hash table structure.
    if ((new_table = malloc(sizeof(hash_table))) == NULL) {
        return NULL;
    }

    // Allocate memory for the array of linked lists.
    if ((new_table->list = malloc(sizeof(node *) * size)) == NULL) {
        return NULL;
    }

    // Initialize the linked lists as NULL.
    for (int i = 0; i < size; i++) {
        new_table->list[i] = NULL;
    }

    new_table->size = size;

    return new_table;
}

unsigned int hash(hash_table *t, int key) {
    // Simple modulus hash function.
    return key % t->size;
}

void insert(hash_table *t, int key) {
    unsigned int index = hash(t, key);
    node *new_node;

    // Allocate memory for a new node.
    new_node = malloc(sizeof(node));
    new_node->value = key;

    // Insert at the beginning of the list.
    new_node->next = t->list[index];
    t->list[index] = new_node;
}

node* search(hash_table *t, int key) {
    unsigned int index = hash(t, key);
    node *current_node = t->list[index];

    while (current_node != NULL && current_node->value != key) {
        current_node = current_node->next;
    }

    return current_node;
}

