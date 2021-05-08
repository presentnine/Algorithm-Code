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

		//�� �� ���� ���
		if (team.find(node1) == team.end() && team.find(node2) == team.end())
			q.push({ node1, node2 });
		else {
			auto node1infor = team.find(node1);
			auto node2infor = team.find(node2);
			if (node1infor != team.end()) {//node1�� ���� ������ ���
				if (node2infor != team.end()) {//node2�� ���� �ִ� ���
					if (node1infor->second + node2infor->second != 0)//���� �� ���տ� ������
						return false;
				}
				else {//node2�� ���� ���ٸ�
					team[node2] = node1infor->second * -1;
				}
			}
			else if (node2infor != team.end()) {//node2�� ���� ������ ���
				if (node1infor != team.end()) {//node1�� ���� �ִ� ���
					if (node1infor->second + node2infor->second != 0)//���� �� ���տ� ������
						return false;
				}
				else {//node2�� ���� ���ٸ�
					team[node1] = node2infor->second * -1;
				}
			}
			else {//�Ѵ� ���� ���
				q.push({ node1, node2 });
			}
		}
	}

	while (!q.empty()) {
		node1 = q.front().first;
		node2 = q.front().second;
		q.pop();

		//�� �� ���� ���
		if (team.find(node1) == team.end() && team.find(node2) == team.end())
			q.push({ node1, node2 });
		else {
			auto node1infor = team.find(node1);
			auto node2infor = team.find(node2);
			if (node1infor != team.end()) {//node1�� ���� ������ ���
				if (node2infor != team.end()) {//node2�� ���� �ִ� ���
					if (node1infor->second + node2infor->second != 0)//���� �� ���տ� ������
						return false;
				}
				else {//node2�� ���� ���ٸ�
					team[node2] = node1infor->second * -1;
				}
			}
			else if (node2infor != team.end()) {//node2�� ���� ������ ���
				if (node1infor != team.end()) {//node1�� ���� �ִ� ���
					if (node1infor->second + node2infor->second != 0)//���� �� ���տ� ������
						return false;
				}
				else {//node2�� ���� ���ٸ�
					team[node1] = node2infor->second * -1;
				}
			}
			else {//�Ѵ� ���� ���
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