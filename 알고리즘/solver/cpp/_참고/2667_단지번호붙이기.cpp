#include <iostream>
#include <algorithm>
using namespace std;

int N;
int grid[30][30];
int cnt = 2;
int ap[1000];

/*
// Bad performance
void dfs(int x, int y) {
	if (!(0 <= x && x < N && 0 <= y && y < N))
		return;
	if (grid[x][y] != 1)
		return;

	grid[x][y] = cnt;
	ap[cnt]++;

	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);
}
*/

//Better performance
void dfs(int x, int y) {

	grid[x][y] = cnt;
	ap[cnt]++;

	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!(0 <= nx && nx < N && 0 <= ny && ny < N))
			continue;
		if (grid[nx][ny] != 1)
			continue;

		dfs(nx, ny);
	}
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char line[100];
		scanf("%s", line);
		for (int j = 0; j < N; j++) {
			grid[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 1) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	
	printf("%d\n", cnt - 2);

	//sort(ap + 2, ap + cnt);
	sort(&ap[2], &ap[cnt]);

	for (int i = 2; i < cnt; i++)
		printf("%d\n", ap[i]);
}