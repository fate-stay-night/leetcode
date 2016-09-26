package test;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by xiao on 9/26/16.
 */
public class RomanToInteger {
    public static void main(String[] args){
        String ro = "MCMXCVI";
        System.out.println(ro + "to integer is " + romanToInt(ro));
    }

    public static int romanToInt(String s){
        int len = s.length();
        if (s == null || len == 0) {
            return 0;
        }
        Map<Character, Integer> map = new HashMap<Character, Integer>(){{
            put('I', 1);
            put('V', 5);
            put('X', 10);
            put('L', 50);
            put('C', 100);
            put('D', 500);
            put('M', 1000);

        }};

        int result = map.get(s.charAt(len - 1));
        for (int i = len - 2 ; i >= 0; i--)
            if (map.get(s.charAt(i + 1)).intValue() > map.get(s.charAt(i)).intValue()) {
                result -= map.get(s.charAt(i));
            } else {
                result += map.get(s.charAt(i));
            }
        return result;
    }
}

