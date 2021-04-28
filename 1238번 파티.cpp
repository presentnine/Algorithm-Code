#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000001

int dist[1001][1001];

int main() {
	int N, M, X;
	int p1, p2, cost;
	int answer = -1;

	cin >> N >> M >> X;

	for (int i = 1; i <= N; i++) {//그래프 초기화
		for (int j = 1; j <= N; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {//비용 입력
		cin >> p1 >> p2 >> cost;
		dist[p1][p2] = cost;
	}

	for (int k = 1; k <= N; k++) //플로이드-와샬 알고리즘 사용
		for (int i = 1; i <= N; i++)
			if(dist[i][k]!=INF) //길이 없는 경우는 탐색 X
				for (int j = 1; j <= N; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
	

	for (int i = 1; i <= N; i++) //최대값 탐색
		answer = max(answer, dist[i][X] + dist[X][i]);

	cout << answer;

	return 0;
}