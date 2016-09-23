/*************************************************************************
    > File Name: IntegerToRoman.c
    > Author: zhang zheng
    > E-mail: kezy-5566@163.com 
    > Created Time: Fri 23 Sep 2016 03:07:43 PM CST
    Integer to Roman:
    	Given an integer, convert it to a roman numeral.
	Input is guaranteed to be within the range from 1 to 3999.
 ************************************************************************/

#include<stdio.h>
char* intToRoman(int num) {
	char *roman = (char *)malloc(20);
    //memset(roman, 0, strlen(roman));
	char temp[20]="";
	char *s[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
		     "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
		     "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
		     "", "M", "MM", "MMM"};
	int count = 0;
	int m = 0;
	while (num != 0) {
		if (strcmp(s[num % 10+count], "") != 0) {
			strcpy(temp, roman);
			strcpy(roman, s[num % 10 + count]);
			strcat(roman, temp);
		}
		num /= 10;
		count += 10;
	}
	return roman;
}


char* intToRoman(int num) {
	char *roman = (char *)malloc(40);
	memset(roman, 0, strlen(roman));
	char *s[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
		     "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
		     "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
		     "", "M", "MM", "MMM"};
	int n[4] = {0, 10, 20, 30};
	int i = 0;
	for (i; num != 0; i++) {
		n[i] = n[i] + num % 10;
		num /= 10;
	}
    
	for (int j = i-1; j >= 0; j--) {
		if (strcmp(s[n[j]], "") != 0)
			strcat(roman, s[n[j]]);
	}
	return roman;
}
