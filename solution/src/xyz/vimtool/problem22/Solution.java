package xyz.vimtool.problem22;

import java.util.ArrayList;
import java.util.List;

/**
 * 22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * [
 * "((()))",
 * "(()())",
 * "(())()",
 * "()(())",
 * "()()()"
 * ]
 *
 * 使用回溯法，每次添加一个括号，一直递归得到字符串
 *
 * @author zhangzheng
 * @version 1.0.0
 * @date 2017-8-1
 */
public class Solution {

    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        backtrack(list, "(", 1, 0, n);
        return list;
    }

    public void backtrack(List<String> list, String str, int open, int close, int max){

        if(str.length() == max*2){
            list.add(str);
            return;
        }

        if(open < max) {
            backtrack(list, str+"(", open+1, close, max);
        }
        if(close < open) {
            backtrack(list, str+")", open, close+1, max);
        }
    }
}
