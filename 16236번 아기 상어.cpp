#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> space;
int visited[20][20];

typedef struct infor {//��ġ ����
	int r, c;
	int time;
}infor;

bool simulation(int N, int& sharkR, int& sharkC, int& size, int& eatCount, int& totalTime) {
	queue<infor> q; //BFS�� ����� ť
	queue<infor> candidate; //�ĺ����� ��Ƴ��� ť
	bool result = false;
	int minTime = 9999;
	int finalRow = 20, finalCol = 20;

	infor pos = { sharkR, sharkC, 0 };
	q.push(pos);
	memset(visited, 0, sizeof(visited));

	while (!q.empty()) {
		infor temp = q.front();
		q.pop();
		//�ε��� ���̰ų� �̹� ������ �湮�غ� ��
		if (0 > temp.r || temp.r >= N || 0 > temp.c || temp.c >= N || visited[temp.r][temp.c] == 1)
			continue;

		//����Ⱑ �۰� �ּ� �ð��̸� �ĺ��� ť�� �߰�
		if (space[temp.r][temp.c] < size && space[temp.r][temp.c] != 0 && temp.time<=minTime) {
			candidate.push(temp);
			minTime = temp.time;
			result = true;
		}
		else if (space[temp.r][temp.c] == size|| space[temp.r][temp.c] == 0) {//���ų� 0 -> �̵�
			visited[temp.r][temp.c] = 1;
			++temp.time;

			--temp.r;//��
			q.push(temp);
			++temp.r; --temp.c;//����
			q.push(temp);
			temp.c += 2;// ������
			q.push(temp);
			--temp.c; ++temp.r;//�Ʒ�
			q.push(temp);
		}
	}

	while (!candidate.empty()) {//�ĺ����� �ִٸ�
		if (finalRow > candidate.front().r) {//�� ���� �ִٸ�
			finalRow = candidate.front().r;
			finalCol = candidate.front().c;
		}
		else if (finalRow == candidate.front().r) {//������ �ִ��� ����
			finalCol = min(finalCol, candidate.front().c);
		}
		candidate.pop();
	}

	if (result) {//����� ���� ���� ������Ʈ
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

	for (int i = 0; i < N; i++) {//���� �ʱ�ȭ
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