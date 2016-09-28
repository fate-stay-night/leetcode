package test;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by xiao on 9/28/16.
 */
public class ThreeSum {
    public static void main(String[] args) {
        int[] sum = {0,0,0,14,-12};
        List<List<Integer>> li = threeSum(sum);
        for (List<Integer> m : li) {
            for (Integer n : m) {
                System.out.println(n);
            }
        }

    }

    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        for (int i = 0 ; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.length - 1; j++) {
                if (j > (i+1) && nums[j] == nums[j-1])
                    continue;
                for (int m = j + 1; m < nums.length; m++) {
                    if (m > j+1 && nums[m] == nums[m-1])
                        continue;
                    if ((nums[i] + nums[j] + nums[m]) == 0) {
                        List<Integer> tmp = new ArrayList<>();
                       if (nums[i] < nums[j] && nums[i] < nums[m]) {
                           tmp.add(nums[i]);
                           tmp.add(Math.min(nums[j], nums[m]));
                           tmp.add(Math.max(nums[j], nums[m]));
                       } else {
                           tmp.add(Math.min(nums[j], nums[m]));
                           tmp.add(Math.min(nums[i], Math.max(nums[j], nums[m])));
                           tmp.add(Math.max(nums[i], Math.max(nums[j], nums[m])));
                       }
                       if (!result.contains(tmp))
                           result.add(tmp);
                    }
                }
            }
        }
        return result;
    }
    public static List<List<Integer>> threeToSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for (int i = 0 ; i < nums.length - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    List<Integer> tmp = new ArrayList<>();
                    tmp.add(nums[i]);
                    tmp.add(nums[left]);
                    tmp.add(nums[right]);
                    result.add(tmp);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1])
                        left++;
                    while (left < right && nums[right] == nums[right+1])
                        right--;
                } else if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                }
            }
        }
        return result;
    }
}
