#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
char map[50][50];
unordered_set<string> visited;//중복 여부

typedef struct infor {//큐에 저장할 정보 구조체
	int r, c, time;
	string getKey;//현재 갖고 있는 키
}infor;

int BFS(int startR, int startC, int N, int M) {
	queue<infor> q;
	q.push({startR, startC, 0, "......" });//시작 위치

	while (!q.empty()) {
		infor now = q.front(); q.pop();
		//인덱스 밖, 벽인 경우
		if (now.r < 0 || N <= now.r || now.c < 0 || M <= now.c || map[now.r][now.c] == '#')
			continue;
		//탈출 지점에 도달한 경우
		if (map[now.r][now.c] == '1')
			return now.time;
		//중복인 경우
		if (visited.find(to_string(now.r) + now.getKey + to_string(now.c)) != visited.end())
			continue;
		//문인 경우(키가 없으면 pass)
		if ('A' <= map[now.r][now.c] && map[now.r][now.c] <= 'F')
			if (now.getKey[map[now.r][now.c] - 'A'] == '.')
				continue;
		//키인 경우
		if ('a' <= map[now.r][now.c] && map[now.r][now.c] <= 'f')
			now.getKey[map[now.r][now.c] - 'a'] = 'o';
		//방문 표시
		visited.insert(to_string(now.r) + now.getKey + to_string(now.c));
		//시간 증가후 상하좌우 큐에 입력
		++now.time;

		++now.r;
		q.push(now);
		--now.r; ++now.c;
		q.push(now);
		now.c -= 2;
		q.push(now);
		++now.c; --now.r;
		q.push(now);
	}

	return -1;
}

int main() {
	int N, M, startR, startC;
	int answer;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {//지도 초기화
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '0') {
				startR = i;
				startC = j;
			}
			map[i][j] = s[j];
		}
	}
	
	answer = BFS(startR, startC, N, M);

	cout << answer;

	return 0;
}