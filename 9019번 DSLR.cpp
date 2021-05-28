#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int visited[10000];

string Fill(string s) {
	switch (s.size()) {
	case 1:
		return "000" + s;
	case 2:
		return "00" + s;
	case 3:
		return "0" + s;
	default:
		return s;
	}
}

string D(string s) {
	int n = stoi(s);
	n = (2 * n) % 10000;
	return to_string(n);
}

string S(string s) {
	int n = stoi(s) - 1;
	if (n == -1)
		return "9999";
	else
		return to_string(n);
}

string L(string s) {
	string result = Fill(s);
	return result.substr(1, 3) + result.substr(0, 1);
}

string R(string s) {
	string result = Fill(s);
	return result.substr(3) + result.substr(0, 3);
}

string search(string start, string goal) {
	queue<pair<string, string>> q;
	string ans = "";
	memset(visited, 0, sizeof(visited));
	q.push({ start, "" });

	while (!q.empty()) {
		string reg = q.front().first;
		string route = q.front().second;
		q.pop();

		if (visited[stoi(reg)] == 1) //레지스터 중복이면
			continue;

		if (Fill(reg) == Fill(goal)) {//정답 결과 확인
			ans = route;
			break;
		}

		visited[stoi(reg)] = 1;

		q.push({ D(reg), route + "D" });
		q.push({ S(reg), route + "S" });
		q.push({ L(reg), route + "L" });
		q.push({ R(reg), route + "R" });
	}

	return ans;
}

int main() {
	int T;
	vector<string> answer;
	string start, goal, result;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> start >> goal;
		result = search(start, goal);
		answer.push_back(result);
	}

	for (int i = 0; i < T; i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}