package test;

import java.util.Arrays;

/**
 * @author zhangzheng
 * @date 2016/11/17
 */
public class ThreeSumClosest {
    public static void main(String[] args) {
        int[] num = {0,2,1,-3};

        System.out.println(threeSumClosest(num, 1));
    }

    /**
     * Given an array S of n integers, find three integers in S
     * such that the sum is closest to a given number, target.
     * Return the sum of the three integers.
     * You may assume that each input would have exactly one solution.
     *  For example, given array S = {-1 2 1 -4}, and target = 1.
     *  The sum that is closest to the target is 2.(-1 + 2 + 1 = 2).
     */
    public static int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int temp = Integer.MAX_VALUE;
        int result = 0;

        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > target) {
                    if (sum - target < temp) {
                        temp = sum - target;
                        result = sum;
                    }
                    right--;
//                    while (left < right && nums[right] == nums[right+1]) {
//                        right--;
//                    }
                } else if (sum < target) {
                    if (target -sum < temp) {
                        temp = target - sum;
                        result = sum;
                    }
                    left++;
//                    while (left < right && nums[left] == nums[left-1]) {
//                        left++;
//                    }
                } else if (sum == target) {
                    return sum;
                }
            }
        }
        return result;
    }
}
