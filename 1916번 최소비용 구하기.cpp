#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321
//다익스트라 알고리즘을 사용한 최소 비용 계산 함수
int calMinPrice(vector<vector<pair<int, int>>> infor, int startPoint, int endPoint, int N) {
	vector<int> distance(N + 1, INF);//출발점과 다른 점들간의 비용 벡터
	distance[startPoint] = 0;
	priority_queue<pair<int, int>> pq;//우선순위 큐
	pq.push(make_pair(0, startPoint));//거리: 0, 시작정점

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (distance[here] < cost)//이미 거리가 지금보다 짧으면 무시
			continue;

		for (int i = 0; i < infor[here].size(); i++) {
			int next = infor[here][i].first;
			int nextCost = infor[here][i].second + cost;

			if (distance[next] > nextCost) {
				distance[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}

	return distance[endPoint];
}

int main() {
	int N, M, startPoint, endPoint;
	int startC, endC, cost;
	vector<vector<pair<int, int>>> infor;

	cin >> N >> M;

	for (int i = 0; i <= N; i++) {//버스의 정보를 담을 벡터 초기화
		vector<pair<int, int>> temp;
		infor.push_back(temp);
	}

	for (int i = 0; i < M; i++) {//버스의 정보 저장
		cin >> startC >> endC >> cost;
		infor[startC].push_back(make_pair(endC, cost));
	}

	cin >> startPoint >> endPoint;//출발점, 도착점

	cout << calMinPrice(infor, startPoint, endPoint, N);//결과 출력

	return 0;
}