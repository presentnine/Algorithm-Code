#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> cache;

int searchRoute(int M, int N, vector<vector<int>> &map, int r, int c, int prev) {
	int result = 0;

	if (r<0 || r>=M || c<0 || c>=N) //인덱스 범위 밖
		return 0;

	if (map[r][c] >= prev) //이전 높이 보다 높거나 같은 경우 
		return 0;

	if (r == M - 1 && c == N - 1) //끝에 도달한 경우
		return 1;

	if (cache[r][c] != -1) //한 번도 가본 길이 아닌 경우 캐시 반환
		return cache[r][c];
	//상하좌우 길 탐색
	result += searchRoute(M, N, map, r, c + 1, map[r][c]);
	result += searchRoute(M, N, map, r + 1, c, map[r][c]);
	result += searchRoute(M, N, map, r, c - 1, map[r][c]);
	result += searchRoute(M, N, map, r - 1, c, map[r][c]);
	
	return cache[r][c] = result;//저장한 캐시 반환
}

int main() {
	int M, N, answer = 0;
	vector<vector<int>> map;

	cin >> M >> N;

	for (int i = 0; i < M; i++) {//지도, 캐시 벡터 생성
		vector<int> temp(N, 0);
		vector<int> temp2(N, -1);//-1을 통해 길이 없는 경우인지 안 가본 경우인지 구분
		cache.push_back(temp2);

		for (int j = 0; j < N; j++)
			cin >> temp[j];

		map.push_back(temp);
	}

	answer = searchRoute(M, N, map, 0, 0, 10001);

	cout << answer;

	return 0;
}