#include <iostream>
#include <vector>

using namespace std;

vector<int> connection[50001];//단순 노드 연결관계 저장
int parent[50001];//노드의 부모
int check[50001];//공통 조상 찾기
bool visited[50001];//노드 정리를 위한 방문 배열

int findMinCommonAncestor(int node1, int node2, int temp) {//최소 공통 조상 찾기
	int tempNode1 = node1, tempNode2 = node2;

	while (1) {
		if (tempNode1 != 0) {
			if (check[tempNode1] == temp)
				return tempNode1;

			check[tempNode1] = temp;
			tempNode1 = parent[tempNode1];
		}

		if (tempNode2 != 0) {
			if (check[tempNode2] == temp)
				return tempNode2;

			check[tempNode2] = temp;
			tempNode2 = parent[tempNode2];
		}
	}

	return 1;
}

void treeSort(int node) {//부모 노드 정리
	for (int i = 0; i < connection[node].size(); i++) {
		if (!visited[connection[node][i]]) {
			visited[connection[node][i]] = true;
			parent[connection[node][i]] = node;
			treeSort(connection[node][i]);
		}
	}
}

int main() {
	int N, M;
	int node1, node2;
	vector<int> result;

	parent[1] = 0;
	cin >> N;

	for (int i = 1; i < N; i++) {//연결 관계 저장
		cin >> node1 >> node2;
		connection[node1].push_back(node2);
		connection[node2].push_back(node1);
	}

	visited[1] = true;
	treeSort(1);//트리 정리

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> node1 >> node2;
		result.push_back(findMinCommonAncestor(node1, node2, i + 1));
	}

	
	for (int i = 0; i < M; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}