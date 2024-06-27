#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[1010];
int V[1010];
int dp[1010][100010];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &W[i], &V[i]);
		//scanf("%d%d", W + i, V + i);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (W[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			  // 만약 같은 물건을 2개 이상 고를 수 있다면,
			  //dp[i][j] = max(dp[i - 1][j], dp[i][j - W[i]] + V[i]);
		}
	}
	printf("%d", dp[N][K]);
}