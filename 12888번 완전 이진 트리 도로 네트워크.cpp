#include <iostream>

using namespace std;
long long cache[61] = { 0, }; //동적 프로그래밍용 캐시

long long search(int H) { //재귀호출 기반 탐색
	long long result = 0;

	if (cache[H] != 0) //캐시 값 반환
		return cache[H];

	for (int i = 0; i <= H - 2; i++)
		result += search(i);

	return cache[H] = 1 + 2 * result;
}

int main() {
	int H;
	long long answer;

	cin >> H;
	//트리 레벨이 0, 1인 경우 한 가지
	cache[0] = 1;
	cache[1] = 1;

	answer = search(H);

	cout << answer;

	return 0;
}