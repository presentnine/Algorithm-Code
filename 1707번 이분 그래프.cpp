#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int nodeinfor[20001];

bool check(int V, int E) {
	unordered_map<int, int> team;
	int node1, node2;
	queue<pair<int, int>> q;
	memset(nodeinfor, 0, sizeof(nodeinfor));

	for (int i = 0; i < E; i++) {
		cin >> node1 >> node2;

		if (i == 0) {
			team.insert({ node1, -1 });
			team.insert({ node2, 1 });
		}

		//둘 다 없는 경우
		if (team.find(node1) == team.end() && team.find(node2) == team.end())
			q.push({ node1, node2 });
		else {
			auto node1infor = team.find(node1);
			auto node2infor = team.find(node2);
			if (node1infor != team.end()) {//node1의 팀이 정해진 경우
				if (node2infor != team.end()) {//node2도 팀이 있는 경우
					if (node1infor->second + node2infor->second != 0)//둘이 한 집합에 있으면
						return false;
				}
				else {//node2의 팀은 없다면
					team[node2] = node1infor->second * -1;
				}
			}
			else if (node2infor != team.end()) {//node2의 팀이 정해진 경우
				if (node1infor != team.end()) {//node1도 팀이 있는 경우
					if (node1infor->second + node2infor->second != 0)//둘이 한 집합에 있으면
						return false;
				}
				else {//node2의 팀은 없다면
					team[node1] = node2infor->second * -1;
				}
			}
			else {//둘다 없는 경우
				q.push({ node1, node2 });
			}
		}
	}

	while (!q.empty()) {
		node1 = q.front().first;
		node2 = q.front().second;
		q.pop();

		//둘 다 없는 경우
		if (team.find(node1) == team.end() && team.find(node2) == team.end())
			q.push({ node1, node2 });
		else {
			auto node1infor = team.find(node1);
			auto node2infor = team.find(node2);
			if (node1infor != team.end()) {//node1의 팀이 정해진 경우
				if (node2infor != team.end()) {//node2도 팀이 있는 경우
					if (node1infor->second + node2infor->second != 0)//둘이 한 집합에 있으면
						return false;
				}
				else {//node2의 팀은 없다면
					team[node2] = node1infor->second * -1;
				}
			}
			else if (node2infor != team.end()) {//node2의 팀이 정해진 경우
				if (node1infor != team.end()) {//node1도 팀이 있는 경우
					if (node1infor->second + node2infor->second != 0)//둘이 한 집합에 있으면
						return false;
				}
				else {//node2의 팀은 없다면
					team[node1] = node2infor->second * -1;
				}
			}
			else {//둘다 없는 경우
				q.push({ node1, node2 });
			}
		}
	}

	return true;
}

int main() {
	int K, V, E;
	vector<string> answer;

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> V >> E;

		if (check(V, E))
			answer.push_back("YES");
		else
			answer.push_back("NO");
	}

	for (int i = 0; i < K; i++) {
		cout << answer[i] << endl;
	}

	return 0;
}