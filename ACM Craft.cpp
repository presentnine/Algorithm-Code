#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& cache, vector<vector<int>>& rule, vector<int>& buildTime, int building) {
	int result = 0;

	if (cache[building] != -1)//ĳ�ð� ��ȯ
		return cache[building];

	for (int i = 0; i < rule[building].size(); i++) {//�� ��忡�� ���� ������ ������ ���� ��� ȣ��
		result = max(result, search(cache, rule, buildTime, rule[building][i]));
	}

	return cache[building] = result + buildTime[building];//�� ��� �Ǽ��ð� + ��� ��ȯ
}

int main() {
	int T;
	vector<int> answer;

	cin >> T;//��ü �׽�Ʈ���̽� �Է�

	for (int i = 0; i < T; i++) {
		int N, K, W;

		cin >> N >> K;//�ǹ� ����, �Ǽ� ��Ģ ���� �Է�

		vector<int> buildTime(N + 1, 0);
		vector<int> cache(N + 1, -1);//ĳ�� �迭-> -1�̳� 0�̳Ŀ� ���� ����
		vector<vector<int>> rule;
		int temp;

		for (int j = 1; j <= N; j++)//�� �ǹ��� �Ǽ� �ð� �Է�
			cin >> buildTime[j];

		for (int j = 0; j < N + 1; j++) {//�Ǽ� ���� ��Ģ �迭 �ʱ�ȭ
			vector<int> tempV2;
			rule.push_back(tempV2);
		}

		for (int j = 0; j < K; j++) {//�Ǽ� ���� �Է�
			int building1, building2;
			cin >> building1 >> building2;
			rule[building2].push_back(building1);
		}

		cin >> W;//��ǥ �ǹ� �Է�

		answer.push_back(search(cache, rule, buildTime, W));
	}

	for (int i = 0; i < T; i++)
		cout << answer[i] << endl;

	return 0;
}