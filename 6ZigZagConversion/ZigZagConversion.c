/*
 *create by xiao
 *time:2016-5-18
 *ZigZag Conversion:
 *	The string "PAYPALISHIRING" is written in a zigzag pattern on a 
 *	given number of rows like this: (you may want to display this 
 *	pattern in a fixed font for better legibility)
 *	P   A   H   N
 *	A P L S I I G
 *	Y   I   R
 *	And then read line by line :"PAHNAPLSIIGYIR"
 *	对应的字母换成数字顺序对应为：
 *	0   4   8   12
 *	1 3 5 7 9 11 13
 *	2   6   10
 *	第一行和最后一行的变化周期为2*numRows-2
 *	中间行的变化周期为(2*numRows-2)-2*i;2*i;(2*numRows-2)-2*i;2*i...
 *	其中i为行号，i=0,1,2...
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *s, int numRows)
{
	if (numRows == 1) return s;
	int len = strlen(s);
	char *st = (char *)calloc(len+1,sizeof(char));
	//处理第0行，第一行和最后一行的元素相差2*numRows-2
	int period = 2*numRows - 2, k=0, index = 0;//行号
	for (index = 0; index < len; index += period)
		st[k++] = *(s+index);
	//处理中间行
	int inter = 0;//中间行的变化周期
	for (index = 1; index < numRows-1; index++) {
		inter = (index << 1);
		for (int j = index; j < len; j += inter) {
			st[k++] = *(s+j);
			inter = period - inter;
		}
	}
	//处理最后一行
	for (index = numRows -1; index < len; index += period)
		st[k++]=*(s+index);
	return st;
}

int main()
{
	char *ss = "PAYPALISHIRING";
	char *s = convert(ss,3);
	printf("Src:%s\nDest:%s\n",ss,s);
	free(s);
	return 0;
}
