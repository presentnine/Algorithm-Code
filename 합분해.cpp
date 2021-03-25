#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache;

long long search(int N, int K, int acc, int count) {//Ž�� �Լ�
	long long result = 0;

	if (count == K)//Ƚ���� ä�� ���
		if (acc == N)//N�� �´ٸ�
			return 1;
		else//�ƴ϶��
			return 0;

	if (acc > N)//�̹� �Ѿ �����
		return 0;

	if (cache[acc][count] != -1)//ĳ�ð� Ȯ��
		return cache[acc][count];

	for (int i = 0; i <= N - acc; i++)//0���� N - acc����
		result += search(N, K, acc + i, count + 1) % 1000000000;

	return cache[acc][count] = result % 1000000000;
}

int main() {
	int N, K;

	cin >> N >> K;

	for (int i = 0; i <= N; i++) {//ĳ�� �迭 ����
		vector<long long> temp(K + 1, -1);
		cache.push_back(temp);
	}

	cout << search(N, K, 0, 0);

	return 0;
}