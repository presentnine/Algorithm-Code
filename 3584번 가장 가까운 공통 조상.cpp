#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstring>

using namespace std;

int reverseNodeInfor[10001];//뒤집어진 트리 정보를 담을 배열

int findCommonAncestor(int node1, int node2, int N) {//공통 조상 찾기 함수
	unordered_set<int> node1Ancestor;//node1의 조상들이 저장될 자료 구조

	int node1Parent = node1, node2Parent = node2;

	while (reverseNodeInfor[node1Parent] != -1) {//node1들의 조상 저장(자기 자신 포함)
		node1Ancestor.insert(node1Parent);
		node1Parent = reverseNodeInfor[node1Parent];
	}
	//node2의 조상을 거슬러 올라가며 공통조상 찾기
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

	for (int i = 0; i < T; i++) {//하나의 케이스 입력 받아 계산
		cin >> N;

		memset(reverseNodeInfor, -1, sizeof(reverseNodeInfor));

		for (int i = 1; i < N; i++) {
			cin >> parent >> child;
			reverseNodeInfor[child] = parent;
		}

		cin >> node1 >> node2;

		answer.push_back(findCommonAncestor(node1, node2, N));
	}

	for (int i = 0; i < T; i++) //답 출력
		cout << answer[i] << endl;

	return 0;
}