#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[200][200];
int visited[200][200][31];

typedef struct infor {
	int r, c, time, K;
}infor;

int BFS(int K, int W, int H) {
	queue<infor> q;
	q.push({ 0,0,0,K });

	while (!q.empty()) {
		infor now = q.front(); q.pop();
		//안되는 위치인 경우(방문 여부, 장애물 포함)
		if (now.r < 0 || now.r >= H || now.c < 0 || now.c >= W
			|| visited[now.r][now.c][now.K] != -1 || map[now.r][now.c] == 1)
			continue;

		if (now.r == H - 1 && now.c == W - 1)//목적지에 도달한 경우
			return now.time;

		visited[now.r][now.c][now.K] = 1;

		++now.time;
		//기본적인 상하좌우 넣기
		++now.r;
		q.push(now);
		--now.r; ++now.c;
		q.push(now);
		now.c -= 2;
		q.push(now);
		++now.c; --now.r;
		q.push(now);
		++now.r;

		//말의 움직임
		if (now.K > 0) {
			--now.K;

			now.c += 2; --now.r;
			q.push(now);
			now.r += 2;
			q.push(now);
			--now.c; ++now.r;
			q.push(now);
			now.r -= 4;
			q.push(now);
			now.c -= 2;
			q.push(now);
			now.r += 4;
			q.push(now);
			--now.c; --now.r;
			q.push(now);
			now.r -= 2;
			q.push(now);
		}
	}

	return -1;
}

int main() {
	int K, W, H;
	int answer;

	cin >> K >> W >> H;
	memset(visited, -1, sizeof(visited));

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> map[i][j];

	answer = BFS(K, W, H);

	cout << answer;

	return 0;
}