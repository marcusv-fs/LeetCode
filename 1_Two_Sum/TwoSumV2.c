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

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (i != j){
                if(nums[i] + nums[j] == target){
                    int *resp = malloc(2 * sizeof(int));
                    resp[0] = i;
                    resp[1] = j;
                    return resp;
                }
            }
        }
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
