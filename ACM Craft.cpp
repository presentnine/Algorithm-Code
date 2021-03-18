#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& cache, vector<vector<int>>& rule, vector<int>& buildTime, int building) {
	int result = 0;

	if (cache[building] != -1)//캐시값 반환
		return cache[building];

	for (int i = 0; i < rule[building].size(); i++) {//이 노드에서 퍼져 나가는 노드들의 대해 재귀 호출
		result = max(result, search(cache, rule, buildTime, rule[building][i]));
	}

	return cache[building] = result + buildTime[building];//현 노드 건설시간 + 결과 반환
}

int main() {
	int T;
	vector<int> answer;

	cin >> T;//전체 테스트케이스 입력

	for (int i = 0; i < T; i++) {
		int N, K, W;

		cin >> N >> K;//건물 개수, 건설 규칙 개수 입력

		vector<int> buildTime(N + 1, 0);
		vector<int> cache(N + 1, -1);//캐시 배열-> -1이냐 0이냐에 따라 갈림
		vector<vector<int>> rule;
		int temp;

		for (int j = 1; j <= N; j++)//각 건물의 건설 시간 입력
			cin >> buildTime[j];

		for (int j = 0; j < N + 1; j++) {//건설 순서 규칙 배열 초기화
			vector<int> tempV2;
			rule.push_back(tempV2);
		}

		for (int j = 0; j < K; j++) {//건설 순서 입력
			int building1, building2;
			cin >> building1 >> building2;
			rule[building2].push_back(building1);
		}

		cin >> W;//목표 건물 입력

		answer.push_back(search(cache, rule, buildTime, W));
	}

	for (int i = 0; i < T; i++)
		cout << answer[i] << endl;

	return 0;
}