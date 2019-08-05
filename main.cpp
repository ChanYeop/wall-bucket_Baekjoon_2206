#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;

struct souce {
	int x, y, wall, count;
};

int res = 999999;
int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int visit1[1001][1001][2] = { 0 };
int map[1001][1001];
int check1;
queue<souce> q;


int bfs(int x, int y, int count) {
	check1 = 0;
	count = 1;
	q.push({ x,y,check1,count });
	visit1[x][y][0] = 1;
	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		count = q.front().count;
		check1 = q.front().wall;
		q.pop();
		if (x == N && y == M)
			return count;
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 0 && x + dx[i] <= N && y + dy[i] >= 0 && y + dy[i] <= M) {
				if (map[x + dx[i]][y + dy[i]] == 0 && visit1[x + dx[i]][y + dy[i]][check1] == 0) {
					visit1[x + dx[i]][y + dy[i]][check1] = 1;
					q.push({ x + dx[i],y + dy[i],check1,count+1 });
				}
				else if (map[x + dx[i]][y + dy[i]] == 1 && check1 == 0) {
					visit1[x + dx[i]][y + dy[i]][check1+1] = 1;
					q.push({ x + dx[i],y + dy[i],check1+1,count+1 });
				}
			}
		}

	}
	return -1;
	
}

int main() {
	int cnt1 = 0;
	cin >> N >> M;
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= M+1; j++) {
			map[i][j] = 2;
		}
	}
	int a;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf_s("%1d", &a);
			map[i][j] = a;
		}
	}

	res = min(res, bfs(1, 1, 0));
	cout << res << endl;
	return 0;
}