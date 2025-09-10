#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define NUM_VALUES 15

// Hash function
int hash(int x) {
    return (x % 18) + 2;  // produces values from 2 to 19
}

// Insert using linear probing
void insert(int table[], int value) {
    int index = hash(value);

    // Linear probing
    while (table[index] != -1) {
        index = (index + 1) % SIZE;
    }
    table[index] = value;
}

int main() {
    int table[SIZE];
    int values[NUM_VALUES];

    // Initialize hash table with -1 (empty slots)
    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }

    srand(time(0));

    // Generate 15 random values between 100000 and 999999
    printf("Generated Values:\n");
    for (int i = 0; i < NUM_VALUES; i++) {
        values[i] = (rand() % 900000) + 100000; // range 100000–999999
        printf("%d ", values[i]);
    }
    printf("\n\n");

    // Insert into hash table
    for (int i = 0; i < NUM_VALUES; i++) {
        insert(table, values[i]);
    }

    // Display final hash table
    printf("Final Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != -1)
            printf("Index %2d -> %d\n", i, table[i]);
        else
            printf("Index %2d -> EMPTY\n", i);
    }

    return 0;
}
