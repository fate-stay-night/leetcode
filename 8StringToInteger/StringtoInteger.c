/*
 *create by xiao
 *email : kezy-5566@163.com
 *time : 2016-5-23
 *String to Integer (atoi)
 *	Implement atoi to convert a string to an integer.
 *	Hint: Carefully consider all possible input cases. If you want a 
 *	challenge, please do not see below and ask yourself what are the
 *	possible input cases.
 *	Notes: It is intended for this problem to be specified vaguely(ie,
 *	no given input specs). You are responsible to gather all the input
 *	requirements up front.
 */

#include <stdio.h>
#include <string.h>

int myAtoi(char *str)
{
	double num = 0;
	int flag = 0;//标志是否有正负
	int sig = 0;//标明空格是否可以忽略
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 32 && sig == 0)
			continue;
		if (str[i] > 57 || str[i] < 48) { 
			sig++;
			if (num != 0) {
				if (flag != 0)
					num = num * flag;
				if (num > 2147483647)
					num = 2147483647;
				if (num < -2147483648)
					num = -2147483648;
				return num;
			} else {
				if (str[i] == 43 && flag == 0) {
					flag = 1;
				} else if (str[i] == 45 && flag == 0) {
					flag = -1;
				} else 
					return num;
			}
		} else {
			sig++;
			num = num * 10 + str[i] - 48;
		}
	}
	if (flag != 0)
		num = flag * num;
	if (num > 2147483647)
		num = 2147483647;
	if (num < -2147483648)
		num = -2147483648;
	return num;
}

int main(int argc,char *argv[])
{
	char *s = argv[1];
	int num = myAtoi(s);
	printf("%s\n",s);
	printf("%d\n",num);
}
