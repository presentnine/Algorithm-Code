#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321
//���ͽ�Ʈ�� �˰����� ����� �ּ� ��� ��� �Լ�
int calMinPrice(vector<vector<pair<int, int>>> infor, int startPoint, int endPoint, int N) {
	vector<int> distance(N + 1, INF);//������� �ٸ� ���鰣�� ��� ����
	distance[startPoint] = 0;
	priority_queue<pair<int, int>> pq;//�켱���� ť
	pq.push(make_pair(0, startPoint));//�Ÿ�: 0, ��������

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (distance[here] < cost)//�̹� �Ÿ��� ���ݺ��� ª���� ����
			continue;

		for (int i = 0; i < infor[here].size(); i++) {
			int next = infor[here][i].first;
			int nextCost = infor[here][i].second + cost;

			if (distance[next] > nextCost) {
				distance[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}

	return distance[endPoint];
}

int main() {
	int N, M, startPoint, endPoint;
	int startC, endC, cost;
	vector<vector<pair<int, int>>> infor;

	cin >> N >> M;

	for (int i = 0; i <= N; i++) {//������ ������ ���� ���� �ʱ�ȭ
		vector<pair<int, int>> temp;
		infor.push_back(temp);
	}

	for (int i = 0; i < M; i++) {//������ ���� ����
		cin >> startC >> endC >> cost;
		infor[startC].push_back(make_pair(endC, cost));
	}

	cin >> startPoint >> endPoint;//�����, ������

	cout << calMinPrice(infor, startPoint, endPoint, N);//��� ���

	return 0;
}