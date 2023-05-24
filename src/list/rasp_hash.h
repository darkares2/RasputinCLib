
// Define the structure for linked list nodes.
typedef struct node {
    int value;
    struct node *next;
} node;

// Define the structure for the hash table.
typedef struct hash_table {
    int size;
    node **list;
} hash_table;
extern hash_table* create_hash_table(int size);
extern void insert(hash_table *t, int key);
extern node* search(hash_table *t, int key);
