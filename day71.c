// Day 71 - Question 1: Hash Table Using Quadratic Probing
// Close
// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

typedef struct {
    int* table;
    int size;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

// --- INSERT WITH QUADRATIC PROBING ---
void insert(HashTable* ht, int key) {
    int m = ht->size;
    int h_k = key % m;
    
    for (int i = 0; i < m; i++) {
        int index = (h_k + i * i) % m;
        if (ht->table[index] == EMPTY || ht->table[index] == DELETED) {
            ht->table[index] = key;
            return;
        }
    }
}

// --- SEARCH WITH QUADRATIC PROBING ---
int search(HashTable* ht, int key) {
    int m = ht->size;
    int h_k = key % m;
    
    for (int i = 0; i < m; i++) {
        int index = (h_k + i * i) % m;
        if (ht->table[index] == EMPTY) {
            return 0; // Stop if we hit an empty slot
        }
        if (ht->table[index] == key) {
            return 1; // Found it
        }
    }
    return 0;
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    HashTable* ht = createTable(m);

    char command[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", command, &key);
        if (strcmp(command, "INSERT") == 0) {
            insert(ht, key);
        } else if (strcmp(command, "SEARCH") == 0) {
            if (search(ht, key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}
