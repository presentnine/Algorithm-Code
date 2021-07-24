#include <iostream>

using namespace std;
long long cache[61] = { 0, }; //���� ���α׷��ֿ� ĳ��

long long search(int H) { //���ȣ�� ��� Ž��
	long long result = 0;

	if (cache[H] != 0) //ĳ�� �� ��ȯ
		return cache[H];

	for (int i = 0; i <= H - 2; i++)
		result += search(i);

	return cache[H] = 1 + 2 * result;
}

int main() {
	int H;
	long long answer;

	cin >> H;
	//Ʈ�� ������ 0, 1�� ��� �� ����
	cache[0] = 1;
	cache[1] = 1;

	answer = search(H);

	cout << answer;

	return 0;
}