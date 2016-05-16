/*
 *create by xiao 
 *time :2016-5-12
 *Longest Palindromic Substring:
 *	Given a string S, find the longest palindromic substring in S.You 
 *	may assume that the maximum length of S is 1000, and there exists
 *	one unique longest palindromic substring.
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

//判断字符串是否为回文，如是则返回长度，不是则返回0
//默认传入的字符串长度大于0
int ispalindrome(char *str, int len)
{
	int i = 0;
	for ( i = 0; i < (len/2); i++) {
		if (*(str + i) != *(str + len -1 -i))
			return 0;
		else 
			continue;
	}
	return len;
}
char *longestPalindrome(char *s) 
{
	int max = 0;
	char *subs = NULL;
	int num = 0;
	int subnum;
	int slen = strlen(s);
	for (num = 0; num < slen; num++) {
		for (subnum = slen - num; subnum > 0; subnum--) {
			if (max >= subnum)
				break;
			if (ispalindrome(s + num,subnum) > max) {
				max = subnum;
				if (subs)
					free(subs);
				subs = (char *)malloc(subnum + 1);
				strncpy(subs, s + num, subnum);
				break;
			}
		}
	}
	return subs;
}

int main(int argc, char *argv[])
{
	char *s = "mkcmccmcjih";
	char *ss = longestPalindrome(s);
	printf("src:%s\ndest:%s\n",s,ss);
	free(ss);
	return 0;
}
