#include <stdio.h>
#include <stdlib.h>

int main() {
    struct mybits {
        unsigned char part1:2;
        unsigned char part2:3;
        unsigned char part3:3;
    };
    printf("Hello world\n");
    struct mybits fun;
    fun.part1 = 1;
    fun.part2 = 2;
    fun.part3 = 3;
    printf("Hi there: %d,%d,%d\n", fun.part1, fun.part2, fun.part3);
    fun.part3 = 6;
    printf("Hi there: %d,%d,%d\n", fun.part1, fun.part2, fun.part3);

    typedef struct {
        char name[50];
    } Person;

    // allocate memory for 100 Person structs
    Person* people = (Person*)malloc(sizeof(Person) * 100);
    if (people == NULL) {
        printf("Memory allocation failed\n");
        return 1; // return an error code
    }

    // fill the structs with data
    for (int i = 0; i < 100; i++) {
        snprintf(people[i].name, 50, "Person %d", i);
    }

    // print the names
    for (int i = 0; i < 100; i++) {
        printf("%s\n", people[i].name);
    }

    // free the memory
    free(people);


    return 0;
}
