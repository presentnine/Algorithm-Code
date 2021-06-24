#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> nodeInfor[10001];//��� ���� ���� ����
vector<int> linkWeight[10001];//���� ����ġ ����
int cache[10001]; //���� ���α׷��ֿ�

int search(int node) {//����Լ��� ���� �Ÿ� ���
	int dist = 0;
	if (nodeInfor[node].size() == 0)
		return 0;

	if (cache[node] != -1)
		return cache[node];

	for (int i = 0; i < nodeInfor[node].size(); i++) {
		dist = max(dist, linkWeight[node][i] + search(nodeInfor[node][i]));
	}

	return cache[node] = dist;
}

void calDistDFS(int node, int &answer) {//Ư�� ��带 �߽����� ���� ���
	vector<int> distance;
	if (nodeInfor[node].size() > 0) {//���� ��尡 �ƴϸ�
		for (int i = 0; i < nodeInfor[node].size(); i++) {
			distance.push_back(linkWeight[node][i] + search(nodeInfor[node][i]));
		}

		sort(distance.begin(), distance.end(), greater<int>());//����

		if(distance.size() == 1)//�ڽ� ��尡 �ϳ��� ������
			answer = max(answer, distance[0]);
		else//�� ��
			answer = max(answer, distance[0] + distance[1]);
	}

	for (int i = 0; i < nodeInfor[node].size(); i++) {//�ڽ� ���� ������ ��� �ݺ�
		calDistDFS(nodeInfor[node][i], answer);
	}
}

int main() {
	int n, answer = 0;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	
	for (int i = 0; i < n - 1; i++) {//�Է� ����
		int parent, child, weight;
		cin >> parent >> child >> weight;

		nodeInfor[parent].push_back(child);
		linkWeight[parent].push_back(weight);
	}

	calDistDFS(1, answer);

	cout << answer;

	return 0;
}