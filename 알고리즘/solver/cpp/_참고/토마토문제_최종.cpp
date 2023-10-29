#include <iostream>
#include <queue>
using namespace std;

#define X -1

int n, m;
int grid[1010][1010];

struct coor {
	int x, y;
};

queue<struct coor> q;

int main() {

	scanf("%d %d", &m, &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			scanf("%d", &grid[i][j]);
			if (grid[i][j] == 1)
				q.push({ i, j });
		}
	}


	while (!q.empty()) {
		auto c = q.front();
		q.pop();

		int dx[] = { 1, -1, 0, 0 };
		int dy[] = { 0, 0, 1, -1 };

		for (int i = 0; i < 4; i++) {
			int nx = c.x + dx[i];
			int ny = c.y + dy[i];
			if (!(1 <= nx && nx <= n && 1 <= ny && ny <= m))
				continue;
			if (grid[nx][ny] == X)
				continue;
			if (grid[nx][ny] == 0) {
				grid[nx][ny] = grid[c.x][c.y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	int max = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == 0) {
				printf("-1");
				return 0;
			}
			if (grid[i][j] > max)
				max = grid[i][j];
		}
	}

	printf("%d", max - 1);

}