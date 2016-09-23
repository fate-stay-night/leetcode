package test;

/**
 * Created by xiao on 9/23/16.
 */
public class IntegerToRoman {
    public static void main(String[] args) {
        int num = 3274;
        System.out.println(num + " to Roman is " + intToRoman(num));
    }

    public static String intToRoman(int num) {
        String toRoman = new String();
        String[][] sRoman = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                {"", "M", "MM", "MMM"}};
        int i = 0;
        while (num != 0) {
            toRoman = sRoman[i][num%10] + toRoman;
            num /= 10;
            i++;
        }
        return toRoman;
    }
}
