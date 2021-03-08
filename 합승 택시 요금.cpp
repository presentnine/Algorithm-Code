#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 98765432

//우선 순위 큐를 사용한 다익스트라
int dijkstra(int n, int start, vector<vector<int>> graph, int s, int a, int b) {
    vector<int> distance(n + 1, INF);
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (distance[here] < cost)
            continue;

        for (int i = 1; i <= n; i++) {
            int newDist = cost + graph[here][i];

            if (newDist < distance[i]) {
                distance[i] = newDist;
                pq.push(make_pair(-newDist, i));
            }
        }
    }

    return distance[s] + distance[a] + distance[b];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> graph;

    for (int i = 0; i < n + 1; i++) {
        vector<int> temp(n + 1, INF);
        temp[i] = 0;
        graph.push_back(temp);
    }

    for (int i = 0; i < fares.size(); i++) {
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int i = 1; i <= n; i++)
        answer = min(answer, dijkstra(n, i, graph, s, a, b));

    return answer;
}