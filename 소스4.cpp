#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 98765432

vector<pair<int, int>> graph[1001];
vector<pair<int, int>> reverseGraph[1001];
int visitedTimes[1001] = { 0, };

bool isTrap(int node, vector<int>& traps) {
    for (int i = 0; i < traps.size(); i++) {
        if (traps[i] == node)
            return true;
    }
    return false;
}

void BFS(int here, int end, vector<int>& traps) {

}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    int node1, node2, cost;

    for (int i = 0; i < roads.size(); i++) {
        node1 = roads[i][0]; node2 = roads[i][1]; cost = roads[i][2];
        graph[node1].push_back(make_pair(node2, cost));
        reverseGraph[node2].push_back(make_pair(node1, cost));
    }

    return answer;
}