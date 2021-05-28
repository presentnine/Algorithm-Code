#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;
char map[50][50];
unordered_set<string> visited;//�ߺ� ����

typedef struct infor {//ť�� ������ ���� ����ü
	int r, c, time;
	string getKey;//���� ���� �ִ� Ű
}infor;

int BFS(int startR, int startC, int N, int M) {
	queue<infor> q;
	q.push({startR, startC, 0, "......" });//���� ��ġ

	while (!q.empty()) {
		infor now = q.front(); q.pop();
		//�ε��� ��, ���� ���
		if (now.r < 0 || N <= now.r || now.c < 0 || M <= now.c || map[now.r][now.c] == '#')
			continue;
		//Ż�� ������ ������ ���
		if (map[now.r][now.c] == '1')
			return now.time;
		//�ߺ��� ���
		if (visited.find(to_string(now.r) + now.getKey + to_string(now.c)) != visited.end())
			continue;
		//���� ���(Ű�� ������ pass)
		if ('A' <= map[now.r][now.c] && map[now.r][now.c] <= 'F')
			if (now.getKey[map[now.r][now.c] - 'A'] == '.')
				continue;
		//Ű�� ���
		if ('a' <= map[now.r][now.c] && map[now.r][now.c] <= 'f')
			now.getKey[map[now.r][now.c] - 'a'] = 'o';
		//�湮 ǥ��
		visited.insert(to_string(now.r) + now.getKey + to_string(now.c));
		//�ð� ������ �����¿� ť�� �Է�
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

	for (int i = 0; i < N; i++) {//���� �ʱ�ȭ
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