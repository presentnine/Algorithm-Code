#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[1000][1000][2] = { 0, };

struct infor {//��ġ ���� ����ü
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

		if (0 > here.r || here.r >= N || 0 > here.c || here.c >= M)//�ε��� ��
			continue;

		if (here.r == N - 1 && here.c == M - 1) //��ǥ����
			return here.cost;

		if(visited[here.r][here.c][here.used] == 1)//�湮�� ���
			continue;

		if (map[here.r][here.c] == 1) {//�� ������ ��
			if (here.used == 1) //�̹� ���� �μ̴ٸ�
				continue;
			else //���� �ν����� ���ٸ�
				here.used = 1;
		}

		visited[here.r][here.c][here.used] = 1;

		++here.cost;

		++here.r;//��
		q.push(here);
		--here.r; ++here.c;//��
		q.push(here);
		here.c -= 2;//��
		q.push(here);
		++here.c; --here.r;//��
		q.push(here);
	}

	return -1;
}

int main() {
	int N, M;
	int answer;
	vector<vector<int>> map;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {//�ʱ�ȭ
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