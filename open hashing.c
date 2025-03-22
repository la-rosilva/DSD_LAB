#include <stdio.h>
#include <stdlib.h>

// Node structure for chaining
struct Node {
    int key;
    struct Node* next;
};

// Hash table structure
struct HashTable {
    int size;
    struct Node** table;  // Array of linked list heads
};

// Hash function: Modulo operation
int hashFunction(int key, int size) {
    return key % size;
}

// Function to create a new hash table
struct HashTable* createHashTable(int size) {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    hashTable->size = size;
    hashTable->table = (struct Node**)malloc(size * sizeof(struct Node*));

    for (int i = 0; i < size; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Function to insert a key into the hash table
void insert(struct HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = hashTable->table[index];

    hashTable->table[index] = newNode;
}

// Function to print the hash table
void printHashTable(struct HashTable* hashTable) {
    printf("\nHash Table (size = %d):\n", hashTable->size);
    for (int i = 0; i < hashTable->size; i++) {
        printf("[%d]:", i);
        struct Node* temp = hashTable->table[i];
        while (temp) {
            printf(" -> %d", temp->key);
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }
}

// Function to insert user-defined keys into the hash table
void runExperiment(int tableSize, int numKeys) {
    struct HashTable* hashTable = createHashTable(tableSize);
    int key;

    printf("Enter %d numbers to insert:\n", numKeys);
    for (int i = 0; i < numKeys; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    double loadFactor = (double)numKeys / tableSize;
    printf("\nFor Hash Table Size = %d, Number of Keys = %d, Load Factor (\u03BB) = %.2f\n", tableSize, numKeys, loadFactor);

    printHashTable(hashTable);

    free(hashTable->table);
    free(hashTable);
}

int main() {
    int tableSize, numKeys;

    printf("Enter hash table size: ");
    scanf("%d", &tableSize);

    printf("Enter number of keys to insert: ");
    scanf("%d", &numKeys);

    runExperiment(tableSize, numKeys);

    return 0;
}
