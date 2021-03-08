#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//내림차순 수열 길이 최대값 찾기
void findDSC(vector<int>& dscCache, vector<int>& sequence, int N, int high) {

	for (int i = N - 1; i > high; i--) {
		if (sequence[i] < sequence[high] && dscCache[i] >= dscCache[high])
			dscCache[high] = dscCache[i] + 1;
	}
	//가장 왼쪽 요소의 경우 자동적으로 길이가 1
	if (dscCache[high] == -1)
		dscCache[high] = 1;

	return;
}
//오름차순 수열 길이 최대값 찾기
void findASC(vector<int>& ascCache, vector<int>& sequence, int N, int high) {

	for (int i = 0; i < high; i++) {
		if (sequence[i] < sequence[high] && ascCache[i] >= ascCache[high])
			ascCache[high] = ascCache[i] + 1;
	}
	//가장 오른쪽 요소의 경우 자동적으로 길이가 1
	if (ascCache[high] == -1)
		ascCache[high] = 1;

	return;
}
//메인 함수
int main() {
	int N, temp, answer = 0;
	vector<int> sequence;

	cin >> N; //수열의 크기 입력
	//수열 구성 입력
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sequence.push_back(temp);
	}
	//캐시 배열 생성
	vector<int> ascCache(N, -1);
	vector<int> dscCache(N, -1);
	//오름차순 캐시 배열 채우기
	for (int i = 0; i < N; i++)
		findASC(ascCache, sequence, N, i);
	//내림차순 캐시 배열 채우기
	for (int i = N - 1; i >= 0; i--)
		findDSC(dscCache, sequence, N, i);
	//최대 길이 찾기
	for (int i = 0; i < N; i++) {
		answer = max(answer, ascCache[i] + dscCache[i] - 1);
	}

	cout << answer;

	return 0;
}