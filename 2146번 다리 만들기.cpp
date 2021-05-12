#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> map;//����
int islandType[100][100] = { 0, };//�� ���� ����
int visited[100][100] = { 0, };

struct infor {//��ġ ���� ����ü
	int r, c, cost;
};

bool check(int N, int r, int c) {//Ž���� ���� ������
	if (0 == r || r == N - 1 || 0 == c || c == N - 1) //������ �����ڸ��� Ž�� ok
		return true;
	//�����¿� ��� ������ Ž�� X
	if (map[r + 1][c] == 1 && map[r - 1][c] == 1 && map[r][c + 1] == 1 && map[r][c - 1] == 1)
		return false;

	return true;
}

void paintIsland(int N, int r, int c, int island) {//BFS ��� �� ����
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));

	while (!q.empty()) {
		int hereR, hereC;
		hereR = q.front().first;
		hereC = q.front().second;
		q.pop();

		if (0 > hereR || hereR >= N || 0 > hereC || hereC >= N) //�ε��� ��
			continue;

		if (map[hereR][hereC] == 0 || visited[hereR][hereC] == 1) //�ٴٰų� �湮�غ�����
			continue;

		visited[hereR][hereC] = 1;
		islandType[hereR][hereC] = island;

		q.push(make_pair(hereR + 1, hereC));
		q.push(make_pair(hereR - 1, hereC));
		q.push(make_pair(hereR, hereC + 1));
		q.push(make_pair(hereR, hereC - 1));
	}
}

int calDist(int N, int r, int c, int island) {//BFS ��� �ִܰ��(�ٸ� ����) Ž��
	memset(visited, 0, sizeof(visited));
	queue<infor> q;
	q.push({ r,c,0 });

	while (!q.empty()) {
		infor here = q.front(); q.pop();

		if (0 > here.r || here.r >= N || 0 > here.c || here.c >= N) //�ε��� ��
			continue;

		if (visited[here.r][here.c] == 1) //�湮�غ�����
			continue;

		if (islandType[here.r][here.c] > island) //�� ��ġ�� ���� ���ݰ� �ٸ���
			return here.cost - 1; //�ٸ� ���� ��ȯ

		if (here.cost > 0 && islandType[here.r][here.c] == island)//������ ���� �����̸�
			continue;

		visited[here.r][here.c] = 1;
		here.cost++;

		--here.r;//��
		q.push(here);
		++here.r; ++here.c;//��
		q.push(here);
		here.c -= 2;//��
		q.push(here);
		++here.c; ++here.r;//��
		q.push(here);
	}

	return 10000;
}

int main() {
	int N, tmp, island = 0;
	int answer = 10000;
	cin >> N;

	for (int i = 0; i < N; i++) {//�� �ʱ�ȭ
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			temp.push_back(tmp);
		}
		map.push_back(temp);
	}

	for (int i = 0; i < N; i++) //�� ����
		for (int j = 0; j < N; j++)
			if (map[i][j] == 1 && islandType[i][j] == 0)
				paintIsland(N, i, j, ++island);

	for (int startIsland = 1; startIsland < island; startIsland++)//�ִ� �ٸ� ���� Ž��
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (islandType[i][j] == startIsland && check(N, i, j))
					answer = min(answer, calDist(N, i, j, startIsland));

	cout << answer;

	return 0;
};