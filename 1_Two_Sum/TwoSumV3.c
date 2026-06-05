// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:

//     2 <= nums.length <= 104
//     -109 <= nums[i] <= 109
//     -109 <= target <= 109
//     Only one valid answer exists.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Node {
    int key;
    int index;
    struct Node *next;
} Node;

#define HASH_SIZE 10001
Node *table[HASH_SIZE];

int hash(int key) {
    if (key < 0){
        key = -key;
    }
    return key % HASH_SIZE;
}

void insert(Node **table, int key, int index){
    int h = hash(key);

    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->index = index;

    node->next = table[h];
    table[h] = node;
}

Node *find(Node **table, int key){
    int h = hash(key);

    Node *cur = table[h];

    while (cur){
        if (cur->key == key){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    for (int i = 0; i < HASH_SIZE; i++) {
        table[i] = NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int complemento = target - nums[i];
        Node *found = find(table, complemento);

        if (found){
            int *resposta = malloc(2 * sizeof(int));

            resposta[0] = found->index;
            resposta[1] = i;
            return resposta;
        }

        insert(table, nums[i], i);
    }
    *returnSize = 0;
    return 0;
}

int main(void) {
    int nums[] = {2,7,11,15};
    int *returnSize = malloc(sizeof(int));
    int target = 9;

    int *result = twoSum(nums, sizeof(nums), target, returnSize);

    printf("[");
    for(int i = 0; i < *returnSize; i++) {
        if (i < *returnSize - 1){
            printf("%d,", result[i]);
        }else{
            printf("%d", result[i]);
        }
    }
    printf("]");

    free(result);
    free(returnSize);

    return 0;
}
