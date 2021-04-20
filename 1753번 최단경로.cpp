#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 98765432

void dijkstra(vector<int> &nodeGraph, vector<vector<pair<int, int>>> graph,int V, int K) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(K, 0));

	while (!pq.empty()) {
		int here = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		if (nodeGraph[here] < cost) //이미 최저값이 있다면 넘어간다.
			continue;
		//나온 정점과 연결되어있는 정점들의 거리 최신화
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int newDist = cost + graph[here][i].second;

			if (newDist < nodeGraph[next]) {
				nodeGraph[next] = newDist;
				pq.push(make_pair(next, -newDist));
			}
		}
	}
}

int main() {
	int V, E, K;//정점의 개수 V, 간선의 개수 E, 시작정점 K
	vector<vector<pair<int, int>>> graph;
	int u, v, w;

	cin >> V >> E >> K;

	vector<int> nodeGraph(V + 1, INF);
	nodeGraph[K] = 0;

	for (int i = 0; i <= V; i++) {
		vector<pair<int, int>> temp;
		graph.push_back(temp);
	}

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	dijkstra(nodeGraph, graph, V, K);

	for (int i = 1; i <= V; i++) {
		if (nodeGraph[i] == INF)
			cout << "INF";
		else
			cout << nodeGraph[i];
		cout << endl;
	}

	return 0;
}