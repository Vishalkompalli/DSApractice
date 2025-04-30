#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10000

typedef struct {
    int key;
    int value;
    int is_filled;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

// Hash function (handles negatives)
int hash(int key) {
    if (key < 0) key = -key;
    return (unsigned int)key % TABLE_SIZE;
}

// Reset hashmap
void resetHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].is_filled = 0;
    }
}

// Insert key-value pair
void insert(int key, int value) {
    int index = hash(key);
    while (hashTable[index].is_filled) {
        if (hashTable[index].key == key) break; // overwrite if same key
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
    hashTable[index].is_filled = 1;
}

// Search for key and return its value (index), or -1 if not found
int search(int key) {
    int index = hash(key);
    int start = index;
    while (hashTable[index].is_filled) {
        if (hashTable[index].key == key)
            return hashTable[index].value;
        index = (index + 1) % TABLE_SIZE;
        if (index == start) break; // full loop, not found
    }
    return -1;
}

// Two Sum core function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    resetHashTable();

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex = search(complement);
        if (foundIndex != -1) {
            result[0] = foundIndex;
            result[1] = i;
            return result;
        }
        insert(nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}

// Test code
int main() {
    int nums[] = {3, 2, 4};
    int target = 6;
    int returnSize;

    int* res = twoSum(nums, 3, target, &returnSize);
    if (res) {
        printf("Indices: [%d, %d]\n", res[0], res[1]);
        free(res);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
