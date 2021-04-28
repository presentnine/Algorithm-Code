#include <iostream>
#include <vector>

using namespace std;

vector<int> buildList2(vector<int> A, int n) {//배열 초기화
	for (int i = 0; i < n; i++)
		A[i] = i + 1;

	return A;
}

int runSimulationVer1(vector<int> A, int n, int k) {//케이크, 초의 개수, 건너뛸 개수
	int r = 0;
	int N = n;

	while (n > 1) {
		int i = 0;

		while (i < k) {
			r = (r + 1) % N;
			if (A[r] != 0)
				i++;
		}

		A[r] = 0;
		n--;

		while (A[r] == 0)
			r = (r + 1) % N;
	}

	return A[r];
}

int main2() {
	int n;//초의 총 개수
	int k;//건너뛸 개수

	cout << "초의 개수를 입력하세요: ";
	cin >> n;

	cout << "건너뛸 초의 개수를 입력하세요: ";
	cin >> k;

	vector<int> cakeCandle(n);

	cakeCandle = buildList2(cakeCandle, n);

	cout << runSimulationVer1(cakeCandle, n, k) <<"번 째 초입니다."<< endl;

	return 0;
}