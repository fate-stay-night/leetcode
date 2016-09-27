/*************************************************************************
    > File Name: LongestCommonPrefix.c
    > Author: zhang zheng
    > E-mail: kezy-5566@163.com
    > Created Time: Tue 27 Sep 2016 10:49:00 AM CST
    Longest Common Prefix:
    	Write a function to find the longest common prefix string amongst
	an array of strings.
 ************************************************************************/

#include <stdio.h>
#include <string.h>

//char *longestCommonPrefix(char **strs, int strsSize)
//{
//	if (strsSize == 0)
//		return "";
//	char *str = *strs;
//	for (int i = 1; i < strsSize; i++) {
//		int j = 0;
//		while (*(str+j) && *(*(strs+i)+j) && *(str+j) == *(*(strs+i)+j))
//			j++;
//		*(str+j) = 0;
//	}
//	return str;
//}


char *longestCommonPrefix(char **strs, int strsSize)
{
	if (strsSize == 0)
		return "";
	char *str = strs[0];
	for (int i = 1; i < strsSize; i++) {
		int j = 0;
		while (str[j] && strs[i][j] && str[j] == strs[i][j])
			j++;
		str[j] = 0;
	}
	return str;
}

int main()
{
	char *str[] = {"dddhello", "ddworld","dddbuhh"};
	printf("%s\n", str[2]);
	char *str2 = longestCommonPrefix(str, 3);
	printf("%s\n", str2);
	return 0;
}

