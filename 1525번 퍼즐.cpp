#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
unordered_set<string> visited;//�ߺ� ����

struct infor {//���� ���� ����ü
	string puzzle;
	int r, c, times;
};

int search(string puzzle, int startR, int startC) {
	queue<infor> q;
	q.push({ puzzle, startR, startC, 0 });

	while (!q.empty()) {
		infor now = q.front(); q.pop();
		string nowPuzzle = now.puzzle;
		int nowR = now.r;
		int nowC = now.c;
		int nowTimes = now.times;
		char a, b;

		if (visited.find(nowPuzzle) != visited.end())//�̹� �غ� ����̶�� pass
			continue;

		if (nowPuzzle == "123456780")//�°� Ǯ���ٸ�
			return nowTimes;

		visited.insert(nowPuzzle);//�ߺ� ���� ǥ��

		++nowTimes;
		a = nowPuzzle[3 * nowR + nowC];//�� ��ġ char ����

		if (nowR > 0) {//���� �̵�
			b = nowPuzzle[3 * nowR + nowC - 3];
			nowPuzzle[3 * nowR + nowC - 3] = a;
			nowPuzzle[3 * nowR + nowC] = b;

			q.push({ nowPuzzle, nowR - 1, nowC, nowTimes });

			nowPuzzle[3 * nowR + nowC - 3] = b;
			nowPuzzle[3 * nowR + nowC] = a;
		}

		if (nowR < 2) {//�Ʒ��� �̵�
			b = nowPuzzle[3 * nowR + nowC + 3];
			nowPuzzle[3 * nowR + nowC + 3] = a;
			nowPuzzle[3 * nowR + nowC] = b;

			q.push({ nowPuzzle, nowR + 1, nowC, nowTimes });

			nowPuzzle[3 * nowR + nowC + 3] = b;
			nowPuzzle[3 * nowR + nowC] = a;
		}

		if (nowC > 0) {//�����̵�
			b = nowPuzzle[3 * nowR + nowC - 1];
			nowPuzzle[3 * nowR + nowC - 1] = a;
			nowPuzzle[3 * nowR + nowC] = b;

			q.push({ nowPuzzle, nowR , nowC - 1, nowTimes });

			nowPuzzle[3 * nowR + nowC - 1] = b;
			nowPuzzle[3 * nowR + nowC] = a;
		}

		if (nowC < 2) {//�������̵�
			b = nowPuzzle[3 * nowR + nowC + 1];
			nowPuzzle[3 * nowR + nowC + 1] = a;
			nowPuzzle[3 * nowR + nowC] = b;

			q.push({ nowPuzzle, nowR, nowC + 1, nowTimes });

			nowPuzzle[3 * nowR + nowC + 1] = b;
			nowPuzzle[3 * nowR + nowC] = a;
		}
	}

	return -1;
}

int main() {
	string puzzle = "", temp;
	int startR, startC;

	for (int i = 0; i < 3; i++) {//�ʱ�ȭ
		for (int j = 0; j < 3; j++) {
			cin >> temp;
			if (temp == "0") {
				startR = i;
				startC = j;
			}
			puzzle += temp;
		}
	}

	cout << search(puzzle, startR, startC);

	return 0;
}