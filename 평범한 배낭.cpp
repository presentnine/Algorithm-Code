#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int>b) {
	return a.first > b.first;
}

int search(vector<pair<int, int>> &goods, vector<pair<int, int>> &cache, int N, int K, int index, int totalWeight) {
	int result = 0;
	
	if (totalWeight >= K)
		return 0;

	if (index == N)
		return 0;

	if (goods[index].first + totalWeight > K)
		return 0;

	if (cache[index].first + totalWeight <= K && cache[index].second != -1)
		return cache[index].second;

	for (int i = index + 1; i < N; i++) {
		result = max(result, search(goods, cache, N, K, i, totalWeight + goods[index].first));
	}

	return cache[index].second = goods[index].second + result;
}

int main()
{
	int N, K;
	vector<pair<int, int>> goods; //무게, 가치
	int tmp1, tmp2;
	int answer = 0;
	vector<pair<int, int>> cache;//여기서 가지는 최소 무게, 최대 가치

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		goods.push_back(make_pair(tmp1, tmp2));
		cache.push_back(make_pair(0, 0));
	}

	sort(goods.begin(), goods.end(), compare);

	vector<int> cache2(N, -1);

	for (int i = 0; i < N; i++) {
		answer = max(answer, search(goods, cache, N, K, i, 0));
	}

	cout << answer << endl;

	for (int i = 0; i < N; i++)
		cout << cache2[i] << " ";

	return 0;
}