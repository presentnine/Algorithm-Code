#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<string> map;
int visited[50][50];

struct infor {//��ġ ����
	int r, c, cost;
};

bool check(int R, int C, int r, int c) {//Ž���� ���� ������
	if (0 == r || r == R - 1 || 0 == c || c == C - 1) //������ �����ڸ��� Ž�� ok
		return true;
	//�����¿� ��� ������ Ž�� X
	if (map[r + 1][c] == 'L' && map[r - 1][c] == 'L' && map[r][c + 1] == 'L' && map[r][c - 1] == 'L')
		return false;

	return true;
}

int findTheLongestWay(int R, int C, int r, int c) {//���� �� �ִܰ�� Ž��
	int maxPathCost = 0;
	queue<infor> q;
	memset(visited, 0, sizeof(visited));

	q.push({ r, c, 0 });

	while (!q.empty()) {
		infor here = q.front(); q.pop();

		if (0 > here.r || here.r >= R || 0 > here.c || here.c >= C)//�ε��� ��
			continue;

		if (map[here.r][here.c] == 'W' || visited[here.r][here.c] == 1)//�ٴٰų� �湮������ ������
			continue;

		visited[here.r][here.c] = 1;
		maxPathCost = max(maxPathCost, here.cost);//�ִ� ��� ����

		++here.cost;

		--here.r;//��
		q.push(here);
		++here.r; ++here.c;//��
		q.push(here);
		here.c -= 2;//��
		q.push(here);
		++here.c; ++here.r;//��
		q.push(here);
	}

	return maxPathCost;
}

int main() {
	int R, C;
	int answer = 0;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {//���� �ʱ�ȭ
		string s;
		cin >> s;
		map.push_back(s);
	}

	for (int i = 0; i < R; i++) {//Ž��
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'L'&&check(R,C,i,j)) {
				answer = max(answer, findTheLongestWay(R, C, i, j));
			}
		}
	}

	cout << answer;

	return 0;
}