#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> space;
int visited[20][20];

typedef struct infor {//위치 정보
	int r, c;
	int time;
}infor;

bool simulation(int N, int& sharkR, int& sharkC, int& size, int& eatCount, int& totalTime) {
	queue<infor> q; //BFS에 사용할 큐
	queue<infor> candidate; //후보군을 모아놓을 큐
	bool result = false;
	int minTime = 9999;
	int finalRow = 20, finalCol = 20;

	infor pos = { sharkR, sharkC, 0 };
	q.push(pos);
	memset(visited, 0, sizeof(visited));

	while (!q.empty()) {
		infor temp = q.front();
		q.pop();
		//인덱스 밖이거나 이미 이전에 방문해본 곳
		if (0 > temp.r || temp.r >= N || 0 > temp.c || temp.c >= N || visited[temp.r][temp.c] == 1)
			continue;

		//물고기가 작고 최소 시간이면 후보자 큐에 추가
		if (space[temp.r][temp.c] < size && space[temp.r][temp.c] != 0 && temp.time<=minTime) {
			candidate.push(temp);
			minTime = temp.time;
			result = true;
		}
		else if (space[temp.r][temp.c] == size|| space[temp.r][temp.c] == 0) {//같거나 0 -> 이동
			visited[temp.r][temp.c] = 1;
			++temp.time;

			--temp.r;//위
			q.push(temp);
			++temp.r; --temp.c;//왼쪽
			q.push(temp);
			temp.c += 2;// 오른쪽
			q.push(temp);
			--temp.c; ++temp.r;//아래
			q.push(temp);
		}
	}

	while (!candidate.empty()) {//후보군이 있다면
		if (finalRow > candidate.front().r) {//더 위에 있다면
			finalRow = candidate.front().r;
			finalCol = candidate.front().c;
		}
		else if (finalRow == candidate.front().r) {//같으면 최대한 왼쪽
			finalCol = min(finalCol, candidate.front().c);
		}
		candidate.pop();
	}

	if (result) {//결과에 따른 변수 업데이트
		sharkR = finalRow;
		sharkC = finalCol;
		++eatCount;
		if (size == eatCount) {
			++size;
			eatCount = 0;
		}
		space[finalRow][finalCol] = 0;
		totalTime += minTime;
	}

	return result;
}

int main() {
	int N;
	int sharkR, sharkC;
	int size = 2;
	int eatCount = 0;
	int totalTime = 0;
	bool simulationResult;
	cin >> N;

	for (int i = 0; i < N; i++) {//공간 초기화
		vector<int> temp;
		int n;
		for (int j = 0; j < N; j++) {
			cin >> n;
			if (n == 9) {
				sharkR = i;
				sharkC = j;
				n = 0;
			}
			temp.push_back(n);
		}
		space.push_back(temp);
	}

	while (simulation(N, sharkR, sharkC, size, eatCount, totalTime));

	cout << totalTime;

	return 0;
}