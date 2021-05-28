#include <iostream>
#include <cstring>

using namespace std;

int tree[10001][2];//Ʈ�� ���� ����
int call[10001] = { 0, };//��� ȣ�� Ƚ�� ����(��Ʈ ��� �ľǿ�)
int mostLeft[10001];//������ ���� ����
int mostRight[10001] = { 0, };//������ ���� ������

void inorder(int node, int level, int& cnt, int& maxLevel) {//���� ��ȸ
	if (tree[node][0] != -1)
		inorder(tree[node][0], level + 1, cnt, maxLevel);

	if (level > maxLevel)//Ʈ�� �ִ� ���� üũ
		maxLevel = level;
	
	if (mostLeft[level] > cnt)//�ڽ��� ��ġ�� �ش� ���� ���� ��������
		mostLeft[level] = cnt;

	if (mostRight[level] < cnt)//����������
		mostRight[level] = cnt;

	++cnt;

	if (tree[node][1] != -1)
		inorder(tree[node][1], level + 1, cnt, maxLevel);
}

int main() {
	int N;
	int parent, child1, child2;
	int root = 1;
	int ansLevel = 1, ansWidth = 1;
	int cnt = 1, maxLevel = 1;
	cin >> N;

	memset(mostLeft, 10001, sizeof(mostLeft));

	for (int i = 0; i < N; i++) {//��� �Է� �ޱ�
		cin >> parent >> child1 >> child2;

		tree[parent][0] = child1;
		tree[parent][1] = child2;

		++call[parent];
		if (child1 != -1)
			++call[child1];
		if (child2 != -1)
			++call[child2];
	}

	for (int i = 1; i <= N; i++)//��Ʈ ��� Ž��
		if (call[i] == 1)
			root = i;
	
	inorder(root, 1, cnt, maxLevel);//���� ��ȸ

	for (int i = 2; i <= maxLevel; i++) //������ �ʺ� Ȯ��
		if (ansWidth < mostRight[i] - mostLeft[i] + 1) {
			ansWidth = mostRight[i] - mostLeft[i] + 1;
			ansLevel = i;
		}

	cout << ansLevel << " " << ansWidth << endl;

	return 0;
}