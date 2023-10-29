#include <iostream>
#include <algorithm>
using namespace std;

#define X 5000

int dp[5010] = { 0, X, X, 1, X, 1 };
int N;

int main() {
	scanf("%d", &N);
	for (int i = 6; i <= N; i++)
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);

	if (dp[N] >= X) {
		printf("-1");
		return 0;
	}

	printf("%d", dp[N]);
}
