#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//�������� ���� ���� �ִ밪 ã��
void findDSC(vector<int>& dscCache, vector<int>& sequence, int N, int high) {

	for (int i = N - 1; i > high; i--) {
		if (sequence[i] < sequence[high] && dscCache[i] >= dscCache[high])
			dscCache[high] = dscCache[i] + 1;
	}
	//���� ���� ����� ��� �ڵ������� ���̰� 1
	if (dscCache[high] == -1)
		dscCache[high] = 1;

	return;
}
//�������� ���� ���� �ִ밪 ã��
void findASC(vector<int>& ascCache, vector<int>& sequence, int N, int high) {

	for (int i = 0; i < high; i++) {
		if (sequence[i] < sequence[high] && ascCache[i] >= ascCache[high])
			ascCache[high] = ascCache[i] + 1;
	}
	//���� ������ ����� ��� �ڵ������� ���̰� 1
	if (ascCache[high] == -1)
		ascCache[high] = 1;

	return;
}
//���� �Լ�
int main() {
	int N, temp, answer = 0;
	vector<int> sequence;

	cin >> N; //������ ũ�� �Է�
	//���� ���� �Է�
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sequence.push_back(temp);
	}
	//ĳ�� �迭 ����
	vector<int> ascCache(N, -1);
	vector<int> dscCache(N, -1);
	//�������� ĳ�� �迭 ä���
	for (int i = 0; i < N; i++)
		findASC(ascCache, sequence, N, i);
	//�������� ĳ�� �迭 ä���
	for (int i = N - 1; i >= 0; i--)
		findDSC(dscCache, sequence, N, i);
	//�ִ� ���� ã��
	for (int i = 0; i < N; i++) {
		answer = max(answer, ascCache[i] + dscCache[i] - 1);
	}

	cout << answer;

	return 0;
}