#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> cache;

int search(vector<pair<int, int>> &goods, int N, int K, int index, int totalWeight) {
	int result = 0;
	
	if (totalWeight >= K)
		return 0;

	if (index == N)
		return 0;

	if (goods[index].first + totalWeight > K)
		return 0;

	if (cache[index][totalWeight] != -1)
		return cache[index][totalWeight];

	for (int i = index + 1; i < N; i++) {
		result = max(result, search(goods, N, K, i, totalWeight + goods[index].first));
	}

	return cache[index][totalWeight] = goods[index].second + result;
}

int main()
{
	int N, K;
	vector<pair<int, int>> goods; //무게, 가치
	int tmp1, tmp2;
	int answer = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		goods.push_back(make_pair(tmp1, tmp2));

		vector<int> temp(K, -1);
		cache.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		answer = max(answer, search(goods, N, K, i, 0));
	}

	cout << answer << endl;

	return 0;
}