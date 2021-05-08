#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int nodeinfor[20001];

void check(int node, int team, vector<vector<int>>& graph, bool& result) {
	nodeinfor[node] = team;

	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (nodeinfor[next] == 0)
			check(next, team * -1, graph, result);
		else
			if (team == nodeinfor[next]) {
				result = false;
				return;
			}
	}
}

int main() {
	int K, V, E;
	vector<string> answer;
	cin >> K;

	for (int i = 0; i < K; i++) {		
		int node1, node2;
		bool result = true;
		vector<vector<int>> graph;
		cin >> V >> E;

		memset(nodeinfor, 0, sizeof(nodeinfor));

		for (int j = 0; j <= V; j++) {
			vector<int> temp;
			graph.push_back(temp);
		}

		for (int j = 0; j < E; j++) {
			cin >> node1 >> node2;
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}

		for (int j = 1; j <= V && result; j++)
			if (nodeinfor[j] == 0)
				check(j, 1, graph, result);
		
		if (result)
			answer.push_back("YES");
		else
			answer.push_back("NO");
	}
	
	for (int i = 0; i < K; i++)
		cout << answer[i] << endl;
	
	return 0;
}