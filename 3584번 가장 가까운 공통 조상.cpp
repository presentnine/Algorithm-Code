#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;

int reverseNodeInfor[10001];//�������� Ʈ�� ������ ���� �迭

int findCommonAncestor(int node1, int node2, int N) {//���� ���� ã�� �Լ�
	unordered_set<int> node1Ancestor;//node1�� ������� ����� �ڷ� ����

	int node1Parent = node1, node2Parent = node2;

	while (reverseNodeInfor[node1Parent] != -1) {//node1���� ���� ����(�ڱ� �ڽ� ����)
		node1Ancestor.insert(node1Parent);
		node1Parent = reverseNodeInfor[node1Parent];
	}
	//node2�� ������ �Ž��� �ö󰡸� �������� ã��
	while (reverseNodeInfor[node2Parent] != -1) {
		if (node1Ancestor.find(node2Parent) != node1Ancestor.end())
			break;
		else
			node2Parent = reverseNodeInfor[node2Parent];
	}

	return node2Parent;
}

int main() {
	int T, N;
	int parent, child, node1, node2;
	vector<int> answer;

	cin >> T;

	for (int i = 0; i < T; i++) {//�ϳ��� ���̽� �Է� �޾� ���
		cin >> N;

		memset(reverseNodeInfor, -1, sizeof(reverseNodeInfor));

		for (int i = 1; i < N; i++) {
			cin >> parent >> child;
			reverseNodeInfor[child] = parent;
		}

		cin >> node1 >> node2;

		answer.push_back(findCommonAncestor(node1, node2, N));
	}

	for (int i = 0; i < T; i++) //�� ���
		cout << answer[i] << endl;

	return 0;
}