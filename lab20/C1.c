#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- Data Structure for a Hash Table Entry ---
// This struct will hold both the key and its corresponding value.
typedef struct {
    int key;
    int value;
    int is_occupied; // Use a flag to check if the slot is empty, occupied, etc.
} Entry;

// Define constants for the hash table
#define TABLE_SIZE 20

// Function to calculate the hash key
// H(x) = (x mod 18) + 2
int hash_function(int key) {
    return (key % 18) + 2;
}

// Function to insert a key-value pair into the hash map
void insert(Entry table[], int key, int value) {
    int initial_index = hash_function(key);
    int current_index = initial_index;
    int i = 0; // Probe counter

    // Linear probing to find an empty slot
    do {
        // If the current slot is empty, insert the new entry
        if (table[current_index].is_occupied == 0) {
            table[current_index].key = key;
            table[current_index].value = value;
            table[current_index].is_occupied = 1; // Mark as occupied
            printf("Inserted key: %d, value: %d at index %d\n", key, value, current_index);
            return;
        }

        // If the slot is taken, move to the next one
        current_index = (current_index + 1) % TABLE_SIZE;
        i++;

    } while (i < TABLE_SIZE);

    printf("Failed to insert key: %d. The hash table is full.\n", key);
}

// Function to retrieve a value for a given key
int get_value(Entry table[], int key) {
    int initial_index = hash_function(key);
    int current_index = initial_index;
    int i = 0; // Probe counter

    // Linear probing to find the key
    do {
        // If the current slot is occupied and the key matches, we found it
        if (table[current_index].is_occupied == 1 && table[current_index].key == key) {
            printf("Found key: %d, returning value: %d\n", key, table[current_index].value);
            return table[current_index].value;
        }

        // If we hit an empty slot, the key is not in the table
        if (table[current_index].is_occupied == 0) {
            printf("Key not found: %d\n", key);
            return -1; // Return -1 to indicate the key was not found
        }

        // Keep probing
        current_index = (current_index + 1) % TABLE_SIZE;
        i++;

    } while (i < TABLE_SIZE);

    // If the loop finishes, the key was not found
    printf("Key not found: %d\n", key);
    return -1;
}

// Function to display the contents of the hash table
void display_table(Entry table[]) {
    printf("\n--- Final Hash Map Contents ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %2d: ", i);
        if (table[i].is_occupied) {
            printf("Key: %d, Value: %d\n", table[i].key, table[i].value);
        } else {
            printf("Empty\n");
        }
    }
    printf("-------------------------------\n");
}

int main() {
    // 1. Initialize the hash table
    Entry hash_table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].is_occupied = 0; // All slots are initially empty
    }

    // Seed the random number generator
    srand(time(NULL));

    // 2. Generate and insert random key-value pairs
    printf("Inserting 5 random key-value pairs:\n");
    for (int i = 0; i < 5; i++) {
        int key = (rand() % 1000) + 1; // Random key between 1 and 1000
        int value = (rand() % 10000) + 1; // Random value between 1 and 10000
        insert(hash_table, key, value);
    }
    
    // 3. Display the final table
    display_table(hash_table);

    // 4. Test the lookup function with some keys
    // You can replace these with keys that were inserted above
    printf("\nTesting retrieval of values:\n");
    get_value(hash_table, hash_table[2].key); // Example: Look up the key at index 2
    get_value(hash_table, 9999); // Example: Look up a key that doesn't exist

    return 0;
}
