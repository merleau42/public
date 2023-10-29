#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s1[1010]; int len1;
char s2[1010]; int len2;
int DP[1010][1010];

int main() {
	//scanf(%s, s1+1)
	scanf("%s", &s1[1]);
	scanf("%s", &s2[1]);
	
	//strlen(s1 + 1);
	len1 = strlen(&s1[1]);
	len2 = strlen(&s2[1]);

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i] == s2[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	printf("%d", DP[len1][len2]);
}