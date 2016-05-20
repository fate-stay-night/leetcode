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
        if (len <= 1) return s;
        char *T = transString(s);
        int tlen = strlen(T);
	printf("T:%s\n",T);
        int *P = (int *)calloc(tlen, sizeof(int));
        memset(P, 0 ,tlen*sizeof(int));
        int id = 0, mx= 0;
        for (int i = 1; i < tlen-1; i++) {
                if (id > 0 && (mx-i) >=0)
                    P[i] = (mx > i) ? (P[2 * id -i] < (mx-i) ? P[2*id -1] : mx-i) : 0;
                // while (*(T+i+1+P[i]) == *(T+i-1-P[i])) {
                //         P[i]++;
                // }
                while ((i-1-P[i])>=0) {
                        if (*(T+i+1+P[i]) == *(T+i-1-P[i]))
                                P[i]++;
                        else 
                                break;
                }
                if (i + P[i] > mx) {
                        id = i;
                        mx = i + P[i];
                }
        }

        int maxlen = 0, centerIndex = 0;
        for (int j = 1; j < tlen-1; j++) {
                if (P[j] > maxlen) {
                        maxlen = P[j];
                        centerIndex = j;
                }
        }
        free(T);
        T=NULL;
        free(P);
        P=NULL;
        char *subs = (char *)malloc(maxlen * sizeof(char)+1);
        memset(subs,0,maxlen*sizeof(char));
        strncat(subs,s+(centerIndex-maxlen)/2,maxlen);
	printf("s:%s\nsubs:%s\n",s,subs);
        return subs;
}


int main(int argc, char *argv[])
{
	char *s = "jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel";
	char *ss = longestPalindrome(s);
	printf("src:%s\ndest:%s\n",s,ss);
	free(ss);
	return 0;
}
