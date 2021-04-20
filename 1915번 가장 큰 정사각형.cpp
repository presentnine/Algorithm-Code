#include <iostream>
#include <vector>

using namespace std;

int main3() {
	vector<vector<int>> arr;
	vector<vector<int>> result;
	vector<vector<int>> result2;
	vector<vector<int>> result3;
	int n, m;
	int answer = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> temp(m, 0);
		vector<int> temp2(m, -1);
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			temp[j] = s[j] - '0';
		}
		arr.push_back(temp);
		result.push_back(temp2);
		result2.push_back(temp2);
		result3.push_back(temp2);
	}

	for (int i = 0; i < n; i++) {//오른쪽 누적량 계산
		int count = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (arr[i][j] == 1)
				result[i][j] = ++count;
			else
				result[i][j] = count = 0;
		}
	}

	for (int j = 0; j < m; j++) {//아래쪽 누적량 계산
		int count = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j] == 1)
				result2[i][j] = ++count;
			else
				result2[i][j] = count = 0;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result3[i][j] = min(result[i][j], result2[i][j]);

	for (int i = 1; i < n; i++) {//배열의 오른쪽
		int row = i, col = m - 1;
		int dist = result3[i][m - 1];
		while (--col >= 0 && --row >= 0) {
			if (result3[row][col] > result3[row + 1][col + 1])
				result3[row][col] = result3[row + 1][col + 1] + 1;
			else
				result3[row][col] = result3[row][col];
		}
	}

	for (int j = 1; j < m; j++) {//배열의 아래쪽
		int row = n - 1, col = j;
		int dist = result3[n - 1][j];
		while (--col >= 0 && --row >= 0) {
			if (result3[row][col] > result3[row + 1][col + 1])
				result3[row][col] = result3[row + 1][col + 1] + 1;
			else
				result3[row][col] = result3[row][col];
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			answer = max(answer, result3[i][j]);

	cout << answer * answer;

	return 0;
}