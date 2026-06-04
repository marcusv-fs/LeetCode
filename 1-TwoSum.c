/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
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
    return NULL;
}