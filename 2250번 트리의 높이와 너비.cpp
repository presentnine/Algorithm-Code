#include <iostream>
#include <cstring>

using namespace std;

int tree[10001][2];//트리 구조 저장
int call[10001] = { 0, };//노드 호출 횟수 저장(루트 노드 파악용)
int mostLeft[10001];//레벨별 가장 왼쪽
int mostRight[10001] = { 0, };//레벨별 가장 오른쪽

void inorder(int node, int level, int& cnt, int& maxLevel) {//중위 순회
	if (tree[node][0] != -1)
		inorder(tree[node][0], level + 1, cnt, maxLevel);

	if (level > maxLevel)//트리 최대 깊이 체크
		maxLevel = level;
	
	if (mostLeft[level] > cnt)//자신의 위치가 해당 레벨 가장 왼쪽인지
		mostLeft[level] = cnt;

	if (mostRight[level] < cnt)//오른쪽인지
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

	for (int i = 0; i < N; i++) {//노드 입력 받기
		cin >> parent >> child1 >> child2;

		tree[parent][0] = child1;
		tree[parent][1] = child2;

		++call[parent];
		if (child1 != -1)
			++call[child1];
		if (child2 != -1)
			++call[child2];
	}

	for (int i = 1; i <= N; i++)//루트 노드 탐색
		if (call[i] == 1)
			root = i;
	
	inorder(root, 1, cnt, maxLevel);//중위 순회

	for (int i = 2; i <= maxLevel; i++) //레벨별 너비 확인
		if (ansWidth < mostRight[i] - mostLeft[i] + 1) {
			ansWidth = mostRight[i] - mostLeft[i] + 1;
			ansLevel = i;
		}

	cout << ansLevel << " " << ansWidth << endl;

	return 0;
}