#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cache;

int searchRoute(int n, vector<vector<int>>& map, int r, int c, int prev) {
	int result = 0;

	if (r < 0 || r >= n || c < 0 || c >= n) //�ε��� ���� ��
		return 0;

	if (map[r][c] <= prev) //���� ���̺��� �۰ų� ���� ��� 
		return 0;

	if (cache[r][c] != -1) //�� ���� ���� ���� �ƴ� ��� ĳ�� ��ȯ
		return cache[r][c];

	//�����¿� �� Ž��
	result = max(result, searchRoute(n, map, r, c + 1, map[r][c]));
	result = max(result, searchRoute(n, map, r + 1, c, map[r][c]));
	result = max(result, searchRoute(n, map, r, c - 1, map[r][c]));
	result = max(result, searchRoute(n, map, r - 1, c, map[r][c]));

	return cache[r][c] = result + 1;//������ ĳ�� ��ȯ
}

int main1() {
	int n;
	int answer = 0;
	vector<vector<int>> map;

	cin >> n;
	
	for (int i = 0; i < n; i++) {//ĳ�� ����, �� ���� �ʱ�ȭ
		vector<int> temp(n, 0);
		vector<int> temp2(n, -1);
		
		for (int j = 0; j < n; j++)
			cin >> temp[j];

		map.push_back(temp);
		cache.push_back(temp2);
	}
	
	for (int i = 0; i < n; i++) {//��� ������ ���� Ž�� ����
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