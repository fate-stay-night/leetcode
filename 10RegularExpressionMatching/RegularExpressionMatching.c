/*
 *create by zhangzheng 
 *email : kezy-5566@163.com
 *time : 2016-5-23
 *Regular Expression Matching:
 *	Implement regular expression matching with support for '.' and '*'.
 *	'.' Matching any single character.
 *	'*' Matching zero or more of the preceding element.
 *	The matching should cover the entire input string (not partial).
 *	
 *	The funtion prototype should be:
 *	bool isMatch(const char *s, const char *p)
 *
 *	Some examples:
 *	isMatch("","aa") -> false
 *	isMatch("aa","a") -> false
 *	isMatch("aa","aa") -> true
 *	isMatch("aaa","aa") -> false
 *	isMatch("aa","a*") -> true
 *	isMatch("aa",".*") -> true
 *	isMatch("ab",".*") -> true
 *	isMatch("aab","c*a*b") -> true
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char *s, char *p)
{
	if (*p == '\0') 
		return *s == '\0';
	
	//当下一个字符不是*号时，需要字符匹配
	if (*(p+1) != '*') {
		if (*s != '\0' && (*p == '.' || *s == *p))
			return isMatch(s+1, p+1);
		else 
			return false;
	} else {
		while (*s != '\0' && (*p == '.' || *s == *p)){
		//后续还需要比较，所以需要判断之后是否匹配，不匹配则跳到下个字符
			if (isMatch(s, p+2)) 
				return true;
			s++;
		}	
		return isMatch(s, p+2);
	}
}


int main(int args, char **argv)
{
	char *s = "aad";
	char *p = "aa.*";

	if (args > 2) {
		s = argv[1];
		p = argv[2];
	}

	if (isMatch(s, p))
		printf("%s and %s matching True\n", s, p);
	else
		printf("%s and %s matching False\n", s, p);

}
