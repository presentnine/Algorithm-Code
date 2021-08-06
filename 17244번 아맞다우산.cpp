#include <iostream>
#include <queue>

using namespace std;

char map[50][50];
int xCount, xAnswerBit;
int visited[50][50][1 << 5];

struct infor {
	int r, c, xBit, time;
};

int BFS(int startR, int startC,int N, int M) {
	queue<infor> q;
	q.push({ startR, startC, 0, 0 });

	while (!q.empty()) {
		infor here = q.front(); q.pop();

		//벽 또는 밖이면
		if (map[here.r][here.c] == '#' || 0 > here.r || M <= here.r || 0 > here.c || N <= here.c)
			continue;

		if (map[here.r][here.c] == 'E') //나가는 문이라면
			if (here.xBit == xAnswerBit) //물건 개수도 맞다면
				return here.time;
		
		if (visited[here.r][here.c][here.xBit] == 1) //이미 중복되게 온 곳이면
			continue;

		if ('0' <= map[here.r][here.c] && map[here.r][here.c] < '0' + xCount) { //물건인 경우 처리
			here.xBit |= (1 << (map[here.r][here.c] - '0'));
		}

		visited[here.r][here.c][here.xBit] = 1; //방문 표시
		++here.time;

		++here.c;
		q.push(here);
		--here.c; ++here.r;
		q.push(here);
		--here.r; --here.c;
		q.push(here);
		++here.c; --here.r;
		q.push(here);
	}

	return -1;
}

int main() {
	int N, M;
	int startR = 0, startC = 0;
	string temp;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> temp;

		for (int j = 0; j < N; j++) {
			switch (temp[j])
			{
			case 'S':
				startR = i;
				startC = j;
				map[i][j] = temp[j];
				break;
			case 'X':
				map[i][j] = '0' + xCount++;
				break;
			default:
				map[i][j] = temp[j];
				break;
			}
		}
	}

	xAnswerBit = (1 << xCount) - 1;

	cout << BFS(startR, startC, N, M);

	return 0;
}