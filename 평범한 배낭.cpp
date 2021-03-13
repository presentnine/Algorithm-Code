#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> cache;//캐시 배열
//완전 탐색 코드
int search(vector<pair<int, int>> &goods, int N, int K, int index, int totalWeight) {
	int result = 0;
	
	if (totalWeight >= K)//현재 총 무게 >= 버틸 수 있는 무게
		return 0;

	if (index == N)//끝에 도달
		return 0;

	if (goods[index].first + totalWeight > K)//현재 담을 물품의 무게와 총 무게의 합 > K
		return 0;

	if (cache[index][totalWeight] != -1)//캐시 값 반환
		return cache[index][totalWeight];

	for (int i = index + 1; i < N; i++) {//기본적인 완전 탐색
		result = max(result, search(goods, N, K, i, totalWeight + goods[index].first));
	}

	return cache[index][totalWeight] = goods[index].second + result;//캐시 저장 후 반환
}

int main()
{
	int N, K;
	vector<pair<int, int>> goods; //무게, 가치
	int tmp1, tmp2;
	int answer = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {//무게와 가치를 담을 배열과 캐시 배열 초기화
		cin >> tmp1 >> tmp2;
		goods.push_back(make_pair(tmp1, tmp2));

		vector<int> temp(K, -1);
		cache.push_back(temp);
	}

	for (int i = 0; i < N; i++) {//탐색
		answer = max(answer, search(goods, N, K, i, 0));
	}

	cout << answer << endl;

	return 0;
}