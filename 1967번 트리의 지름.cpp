#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> nodeInfor[10001];//노드 연결 구조 저장
vector<int> linkWeight[10001];//간선 가중치 저장
int cache[10001]; //동적 프로그래밍용

int search(int node) {//재귀함수를 통한 거리 계산
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

void calDistDFS(int node, int &answer) {//특정 노드를 중심으로 지름 계산
	vector<int> distance;
	if (nodeInfor[node].size() > 0) {//리프 노드가 아니면
		for (int i = 0; i < nodeInfor[node].size(); i++) {
			distance.push_back(linkWeight[node][i] + search(nodeInfor[node][i]));
		}

		sort(distance.begin(), distance.end(), greater<int>());//정렬

		if(distance.size() == 1)//자식 노드가 하나만 있으면
			answer = max(answer, distance[0]);
		else//그 외
			answer = max(answer, distance[0] + distance[1]);
	}

	for (int i = 0; i < nodeInfor[node].size(); i++) {//자식 노드로 내려가 계산 반복
		calDistDFS(nodeInfor[node][i], answer);
	}
}

int main() {
	int n, answer = 0;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	
	for (int i = 0; i < n - 1; i++) {//입력 저장
		int parent, child, weight;
		cin >> parent >> child >> weight;

		nodeInfor[parent].push_back(child);
		linkWeight[parent].push_back(weight);
	}

	calDistDFS(1, answer);

	cout << answer;

	return 0;
}