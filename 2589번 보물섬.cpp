#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<string> map;
int visited[50][50];

struct infor {//위치 정보
	int r, c, cost;
};

bool check(int R, int C, int r, int c) {//탐색할 만한 곳인지
	if (0 == r || r == R - 1 || 0 == c || c == C - 1) //지도의 가장자리는 탐색 ok
		return true;
	//상하좌우 모두 육지면 탐색 X
	if (map[r + 1][c] == 'L' && map[r - 1][c] == 'L' && map[r][c + 1] == 'L' && map[r][c - 1] == 'L')
		return false;

	return true;
}

int findTheLongestWay(int R, int C, int r, int c) {//가장 긴 최단경로 탐색
	int maxPathCost = 0;
	queue<infor> q;
	memset(visited, 0, sizeof(visited));

	q.push({ r, c, 0 });

	while (!q.empty()) {
		infor here = q.front(); q.pop();

		if (0 > here.r || here.r >= R || 0 > here.c || here.c >= C)//인덱스 밖
			continue;

		if (map[here.r][here.c] == 'W' || visited[here.r][here.c] == 1)//바다거나 방문한적이 있으면
			continue;

		visited[here.r][here.c] = 1;
		maxPathCost = max(maxPathCost, here.cost);//최다 경로 저장

		++here.cost;

		--here.r;//상
		q.push(here);
		++here.r; ++here.c;//우
		q.push(here);
		here.c -= 2;//좌
		q.push(here);
		++here.c; ++here.r;//하
		q.push(here);
	}

	return maxPathCost;
}

int main() {
	int R, C;
	int answer = 0;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {//지도 초기화
		string s;
		cin >> s;
		map.push_back(s);
	}

	for (int i = 0; i < R; i++) {//탐색
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'L'&&check(R,C,i,j)) {
				answer = max(answer, findTheLongestWay(R, C, i, j));
			}
		}
	}

	cout << answer;

	return 0;
}