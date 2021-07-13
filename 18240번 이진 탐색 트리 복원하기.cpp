#include <iostream>
#include <vector>

using namespace std;

int levelNodeCount[300001] = { 0, };//레벨별 노드 개수
vector<int> tree[300001]; //트리 자료구조(레벨별 vector)
int levelIndex[300001] = { 0, };//트리 자료구조 레벨별 vector의 인덱스

void inorder(int level, int& nodeNumber) {//중위 순회를 통해 숫자 삽입
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
	vector<int> input;//입력 저장용 vector

	cin >> N;

	levelNodeCount[0] = 1;//루트 노드 개수 초기화

	for (int i = 1; i < N; i++) {
		cin >> inputDepth;
		if (levelNodeCount[inputDepth - 1] * 2 < ++levelNodeCount[inputDepth]) //타당성 조사
			isValid = false;

		input.push_back(inputDepth);
	}

	if (isValid) {//앞선 입력이 타당하다면
		int nodeNumber = 1;

		inorder(0, nodeNumber);

		//답안 출력
		cout << tree[0][0] << " ";
		for (int i = 0; i < N - 1; i++)
			cout << tree[input[i]][levelIndex[input[i]]++] << " ";
	}
	else {//타당하지 않으면
		cout << "-1";
	}
	
	return 0;
}