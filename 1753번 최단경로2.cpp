#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 98765432

vector<pair<int, int>> graph[20001];//정점들의 링크 가중치 연결리스트
vector<int> nodeGraph(20001, INF);//시작 정점의 탐색 cost 벡터

void dijkstra(int K) {//다익스트라 알고리즘
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, K));

	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (nodeGraph[here] < cost) //이미 최저값이 있다면 넘어간다.
			continue;
		//나온 정점과 연결되어있는 정점들의 거리 최신화
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int newDist = cost + graph[here][i].second;

			if (newDist < nodeGraph[next]) {
				nodeGraph[next] = newDist;
				pq.push(make_pair(-newDist, next));
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V, E, K;//정점의 개수 V, 간선의 개수 E, 시작정점 K
	int u, v, w;

	cin >> V >> E >> K;

	nodeGraph[K] = 0; //입력받은 시작정점의 cost 값 0 초기화

	for (int i = 0; i < E; i++) {//연결리스트 형태로 저장
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {//답안 출력
		if (nodeGraph[i] == INF)
			cout << "INF\n";
		else
			cout << nodeGraph[i] << "\n";
	}

	return 0;
}