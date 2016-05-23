/*
 *create by xiao
 *email:kezy-5566@163.com
 *time :2016-5-23
 *Palindrome Number:
 *	Determine wheter an integer is a palindrome.Do this without extra space.
 */

#include <stdio.h>

int reverse(int x)//数字反转
{
	int m = x;
	long long n = 0;
	while((m/10) != 0) {
		n = n*10 + m%10;
		m /= 10;
	}
	n = n*10 + m%10;
	if (n > 2147483647 || n < -2147483648)
		return 0;
	else 
		return (int)n;
}

bool isPalindrome(int x)//回文数
{
	if (x < 0)
		return false;
	if (x == reverse(x))
		return true;
	else 
		return false;
}

int main()
{
	int x = 107829348;
	int res = reverse(x);
	printf("Integer:%d\nReverse:%d\n",x,res);
	return 0;
}
