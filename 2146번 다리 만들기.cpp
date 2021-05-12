#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> map;//지도
int islandType[100][100] = { 0, };//섬 구분 지도
int visited[100][100] = { 0, };

struct infor {//위치 정보 구조체
	int r, c, cost;
};

bool check(int N, int r, int c) {//탐색할 만한 곳인지
	if (0 == r || r == N - 1 || 0 == c || c == N - 1) //지도의 가장자리는 탐색 ok
		return true;
	//상하좌우 모두 육지면 탐색 X
	if (map[r + 1][c] == 1 && map[r - 1][c] == 1 && map[r][c + 1] == 1 && map[r][c - 1] == 1)
		return false;

	return true;
}

void paintIsland(int N, int r, int c, int island) {//BFS 기반 섬 구분
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));

	while (!q.empty()) {
		int hereR, hereC;
		hereR = q.front().first;
		hereC = q.front().second;
		q.pop();

		if (0 > hereR || hereR >= N || 0 > hereC || hereC >= N) //인덱스 밖
			continue;

		if (map[hereR][hereC] == 0 || visited[hereR][hereC] == 1) //바다거나 방문해봤으면
			continue;

		visited[hereR][hereC] = 1;
		islandType[hereR][hereC] = island;

		q.push(make_pair(hereR + 1, hereC));
		q.push(make_pair(hereR - 1, hereC));
		q.push(make_pair(hereR, hereC + 1));
		q.push(make_pair(hereR, hereC - 1));
	}
}

int calDist(int N, int r, int c, int island) {//BFS 기반 최단경로(다리 길이) 탐색
	memset(visited, 0, sizeof(visited));
	queue<infor> q;
	q.push({ r,c,0 });

	while (!q.empty()) {
		infor here = q.front(); q.pop();

		if (0 > here.r || here.r >= N || 0 > here.c || here.c >= N) //인덱스 밖
			continue;

		if (visited[here.r][here.c] == 1) //방문해봤으면
			continue;

		if (islandType[here.r][here.c] > island) //현 위치의 섬이 지금과 다르면
			return here.cost - 1; //다리 길이 반환

		if (here.cost > 0 && islandType[here.r][here.c] == island)//동일한 섬의 지점이면
			continue;

		visited[here.r][here.c] = 1;
		here.cost++;

		--here.r;//상
		q.push(here);
		++here.r; ++here.c;//우
		q.push(here);
		here.c -= 2;//좌
		q.push(here);
		++here.c; ++here.r;//하
		q.push(here);
	}

	return 10000;
}

int main() {
	int N, tmp, island = 0;
	int answer = 10000;
	cin >> N;

	for (int i = 0; i < N; i++) {//맵 초기화
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			temp.push_back(tmp);
		}
		map.push_back(temp);
	}

	for (int i = 0; i < N; i++) //섬 구분
		for (int j = 0; j < N; j++)
			if (map[i][j] == 1 && islandType[i][j] == 0)
				paintIsland(N, i, j, ++island);

	for (int startIsland = 1; startIsland < island; startIsland++)//최단 다리 길이 탐색
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (islandType[i][j] == startIsland && check(N, i, j))
					answer = min(answer, calDist(N, i, j, startIsland));

	cout << answer;

	return 0;
};