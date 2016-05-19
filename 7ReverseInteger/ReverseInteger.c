/*
 *create by xiao
 *time :2016-5-19
 *email:kezy-5566@163.com
 *Reverse Integer:
 *	Reverse digits of an integer.
 *	Example1:x = 123, return 321
 *	Example2:x = -123,return -321
 */

#include <stdio.h>

int reverse(int x)
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

int main()
{
	int x = 107829348;
	int res = reverse(x);
	printf("Integer:%d\nReverse:%d\n",x,res);
	return 0;
}
