#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> spiral(vector<vector<int>> A, int n, int m) {
	int left = 0, right = m - 1, top = 0, bottom = n - 1;
	int value = 1;

	while (left <= right && top <= bottom) {
		for (int i = left; i <= right; i++) {
			A[top][i] = value++;
		}

		top++;

		if (left <= right && top <= bottom)
			for (int i = top; i <= bottom; i++)
				A[i][right] = value++;
		
		right--;

		if (left <= right && top <= bottom)
			for (int i = right; i >= left; i--)
				A[bottom][i] = value++;

		bottom--;

		if (left <= right && top <= bottom)
			for (int i = bottom; i >= top; i--)
				A[i][left] = value++;

		left++;
	}

	return A;
}

int main() {
	int n, m;
	vector<vector<int>> A;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> temp(m, 0);
		A.push_back(temp);
	}

	A = spiral(A, n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%2d ", A[i][j]);
		}
		cout << endl;
	}

	return 0;
}