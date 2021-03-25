#include <iostream>
#include <vector>

using namespace std;

vector<int> buildList(vector<int> A, int n) {//�迭 �ʱ�ȭ �Լ�
	for (int i = 0; i < n; i++)
		A[i] = i + 1;

	return A;
}

vector<int> remove(vector<int> A, int n, int removePos) {//��� ���� �Լ�
	if (removePos >= n) {
		printf("�߸��� ��ġ�Դϴ�.");
		exit(1);
	}

	for (int i = removePos + 1; i < n; i++)
		A[i - 1] = A[i];

	return A;
}

int runSimulationVer2(vector<int> A, int n, int k) {//����ũ, ���� ����, �ǳʶ� ����
	int r = 0;

	while (n > 1) {
		r = (r + k) % n;
		A = remove(A, n, r);
		n--;
	}

	return A[0];
}

int main() {
	int n;//���� �� ����
	int k;//�ǳʶ� ����

	cout << "���� ������ �Է��ϼ���: ";
	cin >> n;

	cout << "�ǳʶ� ���� ������ �Է��ϼ���: ";
	cin >> k;

	vector<int> cakeCandle(n);

	cakeCandle = buildList(cakeCandle, n);

	cout << runSimulationVer2(cakeCandle, n, k) << "�� ° ���Դϴ�." << endl;

	return 0;
}