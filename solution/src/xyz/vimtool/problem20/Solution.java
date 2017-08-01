package xyz.vimtool.problem20;

import java.util.Stack;

/**
 * 20. Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 * @author zhangzheng
 * @version 1.0.0
 * @date 2017-8-1
 */
public class Solution {

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (Character c : s.toCharArray()) {
            if ("([{".contains(c.toString())) {
                stack.push(c);
            } else if (")]}".contains(c.toString())) {
                if (stack.empty()) {
                    return false;
                }
                Character pop = stack.pop();
                switch (c) {
                    case ')':
                        if (!pop.equals('(')) {
                            return false;
                        }
                        break;
                    case ']':
                        if (!pop.equals('[')) {
                            return false;
                        }
                        break;
                    case '}':
                        if (!pop.equals('{')) {
                            return false;
                        }
                        break;
                }
            }
        }
        return stack.empty();
    }
}
