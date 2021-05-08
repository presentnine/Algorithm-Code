#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int nodeinfor[20001];

bool check(int V, int E) {
	int node1, node2;
	queue<pair<int, int>> q;
	memset(nodeinfor, 0, sizeof(nodeinfor));

	for (int i = 0; i < E; i++) {
		cin >> node1 >> node2;

		if (i == 0) {
			nodeinfor[node1] = -1;
			nodeinfor[node2] = 1;
		}

		//둘 다 없는 경우
		if (nodeinfor[node1] == 0 && nodeinfor[node2] == 0)
			q.push({ node1, node2 });
		else {
			if (nodeinfor[node1] != 0) {//node1의 팀이 정해진 경우
				if (nodeinfor[node2] != 0) {//node2도 팀이 있는 경우
					if (nodeinfor[node1] + nodeinfor[node2] != 0)//둘이 한 집합에 있으면
						return false;
				}
				else {//node2의 팀은 없다면
					nodeinfor[node2] = nodeinfor[node1] * -1;
				}
			}
			else if (nodeinfor[node2] != 0) {//node2의 팀이 정해진 경우
				if (nodeinfor[node1] != 0) {//node1도 팀이 있는 경우
					if (nodeinfor[node1] + nodeinfor[node2] != 0)//둘이 한 집합에 있으면
						return false;
				}
				else {//node1의 팀은 없다면
					nodeinfor[node1] = nodeinfor[node2] * -1;
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
		if (nodeinfor[node1] == 0 && nodeinfor[node2] == 0)
			q.push({ node1, node2 });
		else {
			if (nodeinfor[node1] != 0) {//node1의 팀이 정해진 경우
				if (nodeinfor[node2] != 0) {//node2도 팀이 있는 경우
					if (nodeinfor[node1] + nodeinfor[node2] != 0)//둘이 한 집합에 있으면
						return false;
				}
				else {//node2의 팀은 없다면
					nodeinfor[node2] = nodeinfor[node1] * -1;
				}
			}
			else if (nodeinfor[node2] != 0) {//node2의 팀이 정해진 경우
				if (nodeinfor[node1] != 0) {//node1도 팀이 있는 경우
					if (nodeinfor[node1] + nodeinfor[node2] != 0)//둘이 한 집합에 있으면
						return false;
				}
				else {//node1의 팀은 없다면
					nodeinfor[node1] = nodeinfor[node2] * -1;
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