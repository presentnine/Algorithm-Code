#include <iostream>
#include <vector>

using namespace std;

vector<int> buildList(vector<int> A, int n) {//배열 초기화 함수
	for (int i = 0; i < n; i++)
		A[i] = i + 1;

	return A;
}

vector<int> remove(vector<int> A, int n, int removePos) {//요소 제거 함수
	if (removePos >= n) {
		printf("잘못된 위치입니다.");
		exit(1);
	}

	for (int i = removePos + 1; i < n; i++)
		A[i - 1] = A[i];

	return A;
}

int runSimulationVer2(vector<int> A, int n, int k) {//케이크, 초의 개수, 건너뛸 개수
	int r = 0;

	while (n > 1) {
		r = (r + k) % n;
		A = remove(A, n, r);
		n--;
	}

	return A[0];
}

int main() {
	int n;//초의 총 개수
	int k;//건너뛸 개수

	cout << "초의 개수를 입력하세요: ";
	cin >> n;

	cout << "건너뛸 초의 개수를 입력하세요: ";
	cin >> k;

	vector<int> cakeCandle(n);

	cakeCandle = buildList(cakeCandle, n);

	cout << runSimulationVer2(cakeCandle, n, k) << "번 째 초입니다." << endl;

	return 0;
}