#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache;

long long search(int N, int K, int acc, int count) {//탐색 함수
	long long result = 0;

	if (count == K)//횟수는 채운 경우
		if (acc == N)//N에 맞다면
			return 1;
		else//아니라면
			return 0;

	if (acc > N)//이미 넘어선 경우라면
		return 0;

	if (cache[acc][count] != -1)//캐시값 확인
		return cache[acc][count];

	for (int i = 0; i <= N - acc; i++)//0부터 N - acc까지
		result += search(N, K, acc + i, count + 1) % 1000000000;

	return cache[acc][count] = result % 1000000000;
}

int main() {
	int N, K;

	cin >> N >> K;

	for (int i = 0; i <= N; i++) {//캐시 배열 생성
		vector<long long> temp(K + 1, -1);
		cache.push_back(temp);
	}

	cout << search(N, K, 0, 0);

	return 0;
}