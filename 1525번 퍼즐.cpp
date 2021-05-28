#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
unordered_set<string> visited;//중복 여부

struct infor {//상태 정보 구조체
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

		if (visited.find(nowPuzzle) != visited.end())//이미 해본 방법이라면 pass
			continue;

		if (nowPuzzle == "123456780")//맞게 풀었다면
			return nowTimes;

		visited.insert(nowPuzzle);//중복 여부 표시

		++nowTimes;
		a = nowPuzzle[3 * nowR + nowC];//현 위치 char 저장

		if (nowR > 0) {//위쪽 이동
			b = nowPuzzle[3 * nowR + nowC - 3];
			nowPuzzle[3 * nowR + nowC - 3] = a;
			nowPuzzle[3 * nowR + nowC] = b;

			q.push({ nowPuzzle, nowR - 1, nowC, nowTimes });

			nowPuzzle[3 * nowR + nowC - 3] = b;
			nowPuzzle[3 * nowR + nowC] = a;
		}

		if (nowR < 2) {//아래쪽 이동
			b = nowPuzzle[3 * nowR + nowC + 3];
			nowPuzzle[3 * nowR + nowC + 3] = a;
			nowPuzzle[3 * nowR + nowC] = b;

			q.push({ nowPuzzle, nowR + 1, nowC, nowTimes });

			nowPuzzle[3 * nowR + nowC + 3] = b;
			nowPuzzle[3 * nowR + nowC] = a;
		}

		if (nowC > 0) {//왼쪽이동
			b = nowPuzzle[3 * nowR + nowC - 1];
			nowPuzzle[3 * nowR + nowC - 1] = a;
			nowPuzzle[3 * nowR + nowC] = b;

			q.push({ nowPuzzle, nowR , nowC - 1, nowTimes });

			nowPuzzle[3 * nowR + nowC - 1] = b;
			nowPuzzle[3 * nowR + nowC] = a;
		}

		if (nowC < 2) {//오른쪽이동
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

	for (int i = 0; i < 3; i++) {//초기화
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