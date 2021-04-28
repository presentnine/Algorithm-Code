#include <iostream>
#include <vector>

using namespace std;

vector<int> buildList2(vector<int> A, int n) {//�迭 �ʱ�ȭ
	for (int i = 0; i < n; i++)
		A[i] = i + 1;

	return A;
}

int runSimulationVer1(vector<int> A, int n, int k) {//����ũ, ���� ����, �ǳʶ� ����
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
	int n;//���� �� ����
	int k;//�ǳʶ� ����

	cout << "���� ������ �Է��ϼ���: ";
	cin >> n;

	cout << "�ǳʶ� ���� ������ �Է��ϼ���: ";
	cin >> k;

	vector<int> cakeCandle(n);

	cakeCandle = buildList2(cakeCandle, n);

	cout << runSimulationVer1(cakeCandle, n, k) <<"�� ° ���Դϴ�."<< endl;

	return 0;
}