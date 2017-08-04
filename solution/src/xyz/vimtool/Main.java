package xyz.vimtool;

import xyz.vimtool.problem22.Solution;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        Solution solution = new Solution();
//        List<String> list = solution.generateParenthesis(3);
//        List<String> list = generateParenthesis(5);
        String[] list = {};

        System.out.println(list.length);
    }

    public static List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        backtracking(list, "(", n - 1, n);
        return list;
    }

    public static void backtracking(List<String> list, String s, int open, int close) {

        if (open == 0 && close == 0) {
            list.add(s);
            return;
        }

        if (open > 0) {
            backtracking(list, s + "(", open - 1, close);
        }

        if (close > open) {
            backtracking(list, s + ")", open, close - 1);
        }
    }
}
