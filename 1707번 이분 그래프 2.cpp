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

		//�� �� ���� ���
		if (nodeinfor[node1] == 0 && nodeinfor[node2] == 0)
			q.push({ node1, node2 });
		else {
			if (nodeinfor[node1] != 0) {//node1�� ���� ������ ���
				if (nodeinfor[node2] != 0) {//node2�� ���� �ִ� ���
					if (nodeinfor[node1] + nodeinfor[node2] != 0)//���� �� ���տ� ������
						return false;
				}
				else {//node2�� ���� ���ٸ�
					nodeinfor[node2] = nodeinfor[node1] * -1;
				}
			}
			else if (nodeinfor[node2] != 0) {//node2�� ���� ������ ���
				if (nodeinfor[node1] != 0) {//node1�� ���� �ִ� ���
					if (nodeinfor[node1] + nodeinfor[node2] != 0)//���� �� ���տ� ������
						return false;
				}
				else {//node1�� ���� ���ٸ�
					nodeinfor[node1] = nodeinfor[node2] * -1;
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
		if (nodeinfor[node1] == 0 && nodeinfor[node2] == 0)
			q.push({ node1, node2 });
		else {
			if (nodeinfor[node1] != 0) {//node1�� ���� ������ ���
				if (nodeinfor[node2] != 0) {//node2�� ���� �ִ� ���
					if (nodeinfor[node1] + nodeinfor[node2] != 0)//���� �� ���տ� ������
						return false;
				}
				else {//node2�� ���� ���ٸ�
					nodeinfor[node2] = nodeinfor[node1] * -1;
				}
			}
			else if (nodeinfor[node2] != 0) {//node2�� ���� ������ ���
				if (nodeinfor[node1] != 0) {//node1�� ���� �ִ� ���
					if (nodeinfor[node1] + nodeinfor[node2] != 0)//���� �� ���տ� ������
						return false;
				}
				else {//node1�� ���� ���ٸ�
					nodeinfor[node1] = nodeinfor[node2] * -1;
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