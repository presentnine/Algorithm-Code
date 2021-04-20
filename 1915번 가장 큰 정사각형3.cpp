#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> arr;
	vector<vector<int>> result;
	int n, m;
	int answer = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {//�ʱ� �ʿ��� ���� �ʱ�ȭ
		vector<int> temp(m, 0);
		vector<int> temp2(m, -1);
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			temp[j] = s[j] - '0';
		}
		arr.push_back(temp);
		result.push_back(temp2);
	}

	for (int i = 0; i < n; i++) {//������ ���� ������ ���
		int count = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (arr[i][j] == 1)
				result[i][j] = ++count;
			else
				result[i][j] = count = 0;
		}
	}

	for (int j = 0; j < m; j++) {//�Ʒ��� ���� ������ ���
		int count = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j] == 1)
				result[i][j] = min(result[i][j], ++count);
			else
				result[i][j] = count = 0;
		}
	}

	for (int i = 1; i < n; i++) {//�迭�� ������
		int row = i, col = m - 1;
		int dist = result[i][m - 1];
		while (--col >= 0 && --row >= 0) {
			if (result[row][col] > result[row + 1][col + 1])
				result[row][col] = result[row + 1][col + 1] + 1;
			else
				result[row][col] = result[row][col];
		}
	}

	for (int j = 1; j < m; j++) {//�迭�� �Ʒ���
		int row = n - 1, col = j;
		int dist = result[n - 1][j];
		while (--col >= 0 && --row >= 0) {
			if (result[row][col] > result[row + 1][col + 1])
				result[row][col] = result[row + 1][col + 1] + 1;
			else
				result[row][col] = result[row][col];
		}
	}

	for (int i = 0; i < n; i++)//�ִ밪 ���
		for (int j = 0; j < m; j++)
			answer = max(answer, result[i][j]);

	cout << answer * answer; //���� ���

	return 0;
}