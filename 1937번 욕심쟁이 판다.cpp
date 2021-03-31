#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache;

int searchRoute(int n, vector<vector<int>>& map, int r, int c, int prev) {
	int result = 0;

	if (r < 0 || r >= n || c < 0 || c >= n) //인덱스 범위 밖
		return 0;

	if (map[r][c] <= prev) //이전 높이보다 작거나 같은 경우 
		return 0;

	if (cache[r][c] != -1) //한 번도 가본 길이 아닌 경우 캐시 반환
		return cache[r][c];

	//상하좌우 길 탐색
	result = max(result, searchRoute(n, map, r, c + 1, map[r][c]));
	result = max(result, searchRoute(n, map, r + 1, c, map[r][c]));
	result = max(result, searchRoute(n, map, r, c - 1, map[r][c]));
	result = max(result, searchRoute(n, map, r - 1, c, map[r][c]));

	return cache[r][c] = result + 1;//저장한 캐시 반환
}

int main1() {
	int n;
	int answer = 0;
	vector<vector<int>> map;

	cin >> n;
	
	for (int i = 0; i < n; i++) {//캐시 벡터, 맵 벡터 초기화
		vector<int> temp(n, 0);
		vector<int> temp2(n, -1);
		
		for (int j = 0; j < n; j++)
			cin >> temp[j];

		map.push_back(temp);
		cache.push_back(temp2);
	}
	
	for (int i = 0; i < n; i++) {//모든 지점에 대해 탐색 진행
		for (int j = 0; j < n; j++) {
			if (cache[i][j] == -1)
				answer = max(answer, searchRoute(n, map, i, j, 0));
			else
				answer = max(answer, cache[i][j]);
		}
	}

	cout << answer;

	return 0;
}