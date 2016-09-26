/*************************************************************************
    > File Name: RomanToInteger.c
    > Author: zhang zheng
    > E-mail: kezy-5566@163.com 
    > Created Time: Mon 26 Sep 2016 05:19:47 PM CST
    Roman to Integer:
    	Given a roman numeral, convert it to an integer.
    	Input is guaranteed to be within the range from 1 to 3999.
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int romanToInt(char *s)
{
	int len = strlen(s);
	if (strlen == 0)
		return 0;
	int map[26] = {0};
	map['I' - 'A'] = 1;
	map['V' - 'A'] = 5;
	map['X' - 'A'] = 10;
	map['L' - 'A'] = 50;
	map['C' - 'A'] = 100;
	map['D' - 'A'] = 500;
	map['M' - 'A'] = 1000;

	int result = map[*(s+len-1) - 'A'];
	for (int i = len - 2; i >= 0; i--) {
		if (map[*(s + i + 1) - 'A'] > map[*(s + i) - 'A']){
			result -= map[*(s + i) - 'A'];
		} else {
			result += map[*(s + i) - 'A'];
		}
	}
	printf("%d\n", result);
	return result;
	
}

int main()
{
	char *s = "MCMXCVI";
	int num = romanToInt(s);
	return 0;
}


