#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[1000][1000][2] = { 0, };

struct infor {//위치 정보 구조체
	int r, c;
	int cost;
	int used;
};

int BFS(vector<vector<int>> &map, int N, int M) {
	queue<infor> q;
	infor start = { 0,0,1,0 };
	q.push(start);

	while (!q.empty()) {
		infor here = q.front();
		q.pop();

		if (0 > here.r || here.r >= N || 0 > here.c || here.c >= M)//인덱스 밖
			continue;

		if (here.r == N - 1 && here.c == M - 1) //목표지점
			return here.cost;

		if(visited[here.r][here.c][here.used] == 1)//방문한 경우
			continue;

		if (map[here.r][here.c] == 1) {//현 지점이 벽
			if (here.used == 1) //이미 벽을 부셨다면
				continue;
			else //벽을 부신적이 없다면
				here.used = 1;
		}

		visited[here.r][here.c][here.used] = 1;

		++here.cost;

		++here.r;//하
		q.push(here);
		--here.r; ++here.c;//우
		q.push(here);
		here.c -= 2;//좌
		q.push(here);
		++here.c; --here.r;//상
		q.push(here);
	}

	return -1;
}

int main() {
	int N, M;
	int answer;
	vector<vector<int>> map;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {//초기화
		vector<int> tmp(M, 0);
		string s;
		cin >> s;
		
		for (int j = 0; j < M; j++)
			tmp[j] = s[j] - '0';

		map.push_back(tmp);
	}

	answer = BFS(map, N, M);

	cout << answer;
	
	return 0;
}