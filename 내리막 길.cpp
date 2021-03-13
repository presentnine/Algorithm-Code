#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> cache;

int searchRoute(int M, int N, vector<vector<int>> &map, int r, int c, int prev) {
	int result = 0;

	if (r<0 || r>=M || c<0 || c>=N) //�ε��� ���� ��
		return 0;

	if (map[r][c] >= prev) //���� ���� ���� ���ų� ���� ��� 
		return 0;

	if (r == M - 1 && c == N - 1) //���� ������ ���
		return 1;

	if (cache[r][c] != -1) //�� ���� ���� ���� �ƴ� ��� ĳ�� ��ȯ
		return cache[r][c];
	//�����¿� �� Ž��
	result += searchRoute(M, N, map, r, c + 1, map[r][c]);
	result += searchRoute(M, N, map, r + 1, c, map[r][c]);
	result += searchRoute(M, N, map, r, c - 1, map[r][c]);
	result += searchRoute(M, N, map, r - 1, c, map[r][c]);
	
	return cache[r][c] = result;//������ ĳ�� ��ȯ
}

int main() {
	int M, N, answer = 0;
	vector<vector<int>> map;

	cin >> M >> N;

	for (int i = 0; i < M; i++) {//����, ĳ�� ���� ����
		vector<int> temp(N, 0);
		vector<int> temp2(N, -1);//-1�� ���� ���� ���� ������� �� ���� ������� ����
		cache.push_back(temp2);

		for (int j = 0; j < N; j++)
			cin >> temp[j];

		map.push_back(temp);
	}

	answer = searchRoute(M, N, map, 0, 0, 10001);

	cout << answer;

	return 0;
}