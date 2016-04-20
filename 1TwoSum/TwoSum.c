/*
*Create by xiao
*Two Sum
*	Given an array of integers, return indices of the two numbers such that
*	they add up to a specific target.You may assume that each input would 
*	have exactly one solution.
*	Example:
*	Given nums = [2, 7, 11, 15], target = 9,
*	Because nums[0] + nums[1] = 2 + 7 = 9,
*	return [0, 1]. 
*/

/*
*Note: The return array must be malloced, assume caller calls free().
*/

int *twoSum(int *nums, int numsSize, int target)
{
	int *indexnums = (int *)malloc(2 * sizeof(int));
	int i = 0, j = 0;
	while (i < numsSize) {
		while (j < numsSize) {
			if (i == j) {
				j++;
				continue;
			}
			if ((nums[j] + nums[j]) == target){
				*indexnums = i;
				*(indexnums + 1) = j;
				return indexnums;
			} else {
				j++;
			}
		}
		i++;
		j = i + 1;
	}
	return indexnums;
}

