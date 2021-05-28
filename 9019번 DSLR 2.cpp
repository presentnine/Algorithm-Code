#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int visited[10000];

string search(int start, int goal) {
	queue<pair<int, string>> q;
	int D, S, L, R;
	string ans;
	memset(visited, 0, sizeof(visited));
	q.push({ start, "" });
	visited[start] = 1;

	while (!q.empty()) {
		int reg = q.front().first;
		string route = q.front().second;
		q.pop();

		if (reg == goal) {//정답 확인
			ans = route;
			break;
		}

		D = (reg * 2) % 10000;//명령어 D
		if (visited[D] != 1) {
			visited[D] = 1;
			q.push({ D, route + "D" });
		}

		S = reg - 1;//명령어 S
		if (S == -1)
			S = 9999;
		if (visited[S] != 1) {
			visited[S] = 1;
			q.push({ S, route + "S" });
		}

		L = (reg) % 1000 * 10 + reg / 1000;//명령어 L
		if (visited[L] != 1) {
			visited[L] = 1;
			q.push({ L, route + "L" });
		}

		R = reg / 10 + (reg % 10) * 1000;//명령어 R
		if (visited[R] != 1) {
			visited[R] = 1;
			q.push({ R, route + "R" });
		}
	}

	return ans;
}

int main() {
	int T, start, goal;
	vector<string> answer;
	string result;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> start >> goal;
		result = search(start, goal);
		answer.push_back(result);
	}

	for (int i = 0; i < T; i++)
		cout << answer[i] << "\n";

	return 0;
}