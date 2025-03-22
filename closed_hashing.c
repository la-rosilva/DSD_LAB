#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5  // Size of the hash table
#define EMPTY -1       // Represents an empty slot in the hash table

// Hash function: Modulo operation
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key into the hash table using linear probing
void insert(int hashTable[], int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;  // Linear probing
        if (index == originalIndex) {  // Table is full
            printf("Hash table is full! Cannot insert key: %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

// Function to search for a key in the hash table
int search(int hashTable[], int key, int *comparisons) {
    int index = hashFunction(key);
    int originalIndex = index;
    *comparisons = 0;

    while (hashTable[index] != EMPTY) {
        (*comparisons)++;
        if (hashTable[index] == key) {
            return index;  // Key found
        }
        index = (index + 1) % TABLE_SIZE;  // Linear probing
        if (index == originalIndex) {
            break;  // Full cycle completed
        }
    }
    return -1;  // Key not found
}

// Function to print the hash table
void printHashTable(int hashTable[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY) {
            printf("[%d]: EMPTY\n", i);
        } else {
            printf("[%d]: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;  // Initialize hash table with EMPTY
    }

    int numKeys, key, comparisons;
    printf("Enter the number of keys to insert: ");
    scanf("%d", &numKeys);

    printf("Enter %d keys:\n", numKeys);
    for (int i = 0; i < numKeys; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    printHashTable(hashTable);

    // Search operation
    printf("\nEnter key to search: ");
    scanf("%d", &key);

    int result = search(hashTable, key, &comparisons);
    if (result != -1) {
        printf("Key %d found at index %d with %d comparisons.\n", key, result, comparisons);
    } else {
        printf("Key %d not found. Number of comparisons: %d\n", key, comparisons);
    }

    return 0;
}

