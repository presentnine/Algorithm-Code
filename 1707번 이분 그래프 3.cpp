#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int nodeinfor[20001];

void check(int node, int team, vector<vector<int>>& graph, bool& result) {//DFS 기반
	nodeinfor[node] = team;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (nodeinfor[next] == 0) //연결 노드의 팀이 정해지지 않은 경우
			check(next, team * -1, graph, result);
		else
			if (team == nodeinfor[next]) {//이미 팀이 정해져있는데 계산과 다른 경우
				result = false;
				return;
			}
	}
}

int main() {
	int K, V, E;
	vector<string> answer;
	cin >> K;

	for (int i = 0; i < K; i++) {//케이스 마다		
		int node1, node2;
		bool result = true;
		vector<vector<int>> graph;
		cin >> V >> E;

		memset(nodeinfor, 0, sizeof(nodeinfor));

		for (int j = 0; j <= V; j++) {//정점 연결리스트 초기화
			vector<int> temp;
			graph.push_back(temp);
		}

		for (int j = 0; j < E; j++) {//노드 연결 저장
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}

		for (int j = 1; j <= V && result; j++)//노드 탐색
			if (nodeinfor[j] == 0)
				check(j, 1, graph, result);
		
		if (result) //결과에 따라
			answer.push_back("YES");
		else
			answer.push_back("NO");
	}
	
	for (int i = 0; i < K; i++)
		cout << answer[i] << endl;
	
	return 0;
}