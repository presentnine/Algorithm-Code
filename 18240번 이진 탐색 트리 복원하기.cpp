#include <iostream>
#include <vector>

using namespace std;

int levelNodeCount[300001] = { 0, };//������ ��� ����
vector<int> tree[300001]; //Ʈ�� �ڷᱸ��(������ vector)
int levelIndex[300001] = { 0, };//Ʈ�� �ڷᱸ�� ������ vector�� �ε���

void inorder(int level, int& nodeNumber) {//���� ��ȸ�� ���� ���� ����
	if (levelNodeCount[level] == 0)
		return;

	inorder(level + 1, nodeNumber);

	--levelNodeCount[level];
	tree[level].push_back(nodeNumber++);

	inorder(level + 1, nodeNumber);
}

int main() {
	int N, inputDepth;
	bool isValid = true;
	vector<int> input;//�Է� ����� vector

	cin >> N;

	levelNodeCount[0] = 1;//��Ʈ ��� ���� �ʱ�ȭ

	for (int i = 1; i < N; i++) {
		cin >> inputDepth;
		if (levelNodeCount[inputDepth - 1] * 2 < ++levelNodeCount[inputDepth]) //Ÿ�缺 ����
			isValid = false;

		input.push_back(inputDepth);
	}

	if (isValid) {//�ռ� �Է��� Ÿ���ϴٸ�
		int nodeNumber = 1;

		inorder(0, nodeNumber);

		//��� ���
		cout << tree[0][0] << " ";
		for (int i = 0; i < N - 1; i++)
			cout << tree[input[i]][levelIndex[input[i]]++] << " ";
	}
	else {//Ÿ������ ������
		cout << "-1";
	}
	
	return 0;
}