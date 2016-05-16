/*
 *create by xiao 
 *time :2016-5-12
 *Longest Palindromic Substring:
 *	Given a string S, find the longest palindromic substring in S.You 
 *	may assume that the maximum length of S is 1000, and there exists
 *	one unique longest palindromic substring.
 *use Manacher's Algorithm
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

char *transString(char *s)
{
	int len = strlen(s);
	char *st = (char *)malloc(2*len + 1 + 1);
	strcat(st, "#");
	int i = 0;
	while (i < strlen(s)) {
		strncat(st, s+i,1);
		strcat(st, "#");
		i++;
	}	
	return st;
}

char *longestPalindrome(char *s)
{
	int len = strlen(s);
	if (len == 0) return "";
	char *T = transString(s);
	int tlen = strlen(T);
	int *P = (int *)calloc(tlen, sizeof(int));
	memset(P, 0 ,tlen * sizeof(int));
	int id = 0, mx= 0;
	for (int i = 0; i < tlen; i++) {
		P[i] = mx > i ? (P[2 * id -1] < (mx-i) ? P[2*id -1] : mx-i) : 0;
		while (*(T+i+P[i]) == *(T+i-P[i])) {
			P[i]++;
		}
		if (i + P[i] > mx) {
			id = i;
			mx = i + P[i];
		}
	}

	int maxlen = 0, centerIndex = 0;
	for (int i = 0; i < tlen; i++) {
		printf("%d\n",P[i]);
		if (P[i] > maxlen) {
			maxlen = P[i];
			centerIndex = i;
		}
	}
	free(T);
	free(P);
	char *subs = (char *)malloc(maxlen * sizeof(char));
	strcpy(subs,s+(centerIndex-maxlen)/2);
	return subs;

}

int main(int argc, char *argv[])
{
	char *s = "ababa";
	char *ss = longestPalindrome(s);
	printf("src:%s\ndest:%s\n",s,ss);
	free(ss);
	return 0;
}
