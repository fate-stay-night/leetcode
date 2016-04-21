/*
*Given a string, find the length of the longest substring without repeating
*characters.
*Examples:
*	Given "abcabcbb", the answer is "abc", which the length is 3.
*	Given "bbbbb", the answer is "b", with the length of 1.
*	Given "pwwkew", the answer is "wke", with the length of 3. Note the
*	answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <stdio.h>
#include <string.h>


int lengthOfLongestSubstring(char *s)
{
	if (s == NULL || strlen(s) == 0)
		return 0;
	char *prepos = s, *start = s;
	int right = 1;
	int max = 1;
	int length = strlen(s);
	for (int i = 0; i < length; i++) {
		if (prepos = memchr(start, *(start + right), right)) {
			right = start + right - prepos;
			start = prepos + 1;
		} else if ((start + right) != (s + length)) {
			right++;
		}
		max = max > right ? max : right;
	}	 
	return max;
}

int main()
{
	char *s = "   ";
	int len = lengthOfLongestSubstring(s);
	printf("%d\n",len);
}
