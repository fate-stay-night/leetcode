package xyz.vimtool.problem17;

import java.util.ArrayList;
import java.util.List;

/**
 * 17. Letter Combinations of a Phone Number
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 *
 * @author zhangzheng
 * @version 1.0.0
 * @date 2017-8-1
 */
public class Solution {

    public List<String> letterCombinations(String digits) {
        String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> result = new ArrayList<>();
        if (digits.contains("0") || digits.contains("1") || digits.isEmpty()) {
            return result;
        }

        result.add("");

        for (int i = 0; i < digits.length(); i++) {
            List<String> tempRes = new ArrayList<>();
            String chars = map[digits.charAt(i) - '0'];
            for (int m = 0; m < chars.length(); m++) {
                for (String aResult : result) {
                    tempRes.add(aResult + chars.substring(m, m + 1));
                }
            }
            result = tempRes;
        }
        return result;
    }
}
