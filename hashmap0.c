//Doesn't handle collision

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int key;
    int value;
    int is_filled;
}HashEntry;

#define TABLE_SIZE 1000
HashEntry hashtable[TABLE_SIZE];

int hash(int key)
{
    if (key < 0) key = -key;
    return key%TABLE_SIZE;
}

void insert(int key, int value)
{
    int index = hash(key);

    if(hashtable[index].is_filled)
    {
        index = (index + 1) % TABLE_SIZE;
    }
    hashtable[index].key = key;
    hashtable[index].value = value;
    hashtable[index].is_filled = 1;
}

int search(int key)
{
    int index = hash(key);
    int start = index;

    while(hashtable[index].is_filled)
    {
        if(hashtable[index].key == key)
        {
            return hashtable[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
        if(index == start) break;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) 
    {
        int complement = target - nums[i];
        int foundIndex = search(complement);

        printf("i = %d, nums[i] = %d, complement = %d\n", i, nums[i], complement);

        if (foundIndex != -1) 
        {
            printf("Found complement %d at index %d\n", complement, foundIndex);
            result[0] = foundIndex;
            result[1] = i;
            return result;
        }

        printf("Complement not found. Inserting %d at index %d\n", nums[i], i);
        insert(nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}

