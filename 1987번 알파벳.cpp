#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> map;

int DFS(int R, int C, int r, int c, vector<bool>& visited) {//DFS 탐색
	int result;

	if (0 > r || r >= R || 0 > c || c >= C)//위치 검사
		return 0;

	int pos = map[r][c] - 'A';

	if (visited[pos] == true)//알파벳 중복
		return 0;
	else {//새로운 알파벳일 경우
		visited[pos] = true;//해당 탐색 체크

		result = DFS(R, C, r + 1, c, visited);
		result = max(result, DFS(R, C, r, c + 1, visited));
		result = max(result, DFS(R, C, r - 1, c, visited));
		result = max(result, DFS(R, C, r, c - 1, visited));

		visited[pos] = false;//탐색 해제

		return 1 + result;
	}
}

int main() {
	vector<bool> visited(26, false);//각 알파벳 중복 검사 벡터
	int R, C;
	int answer;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {//보드 초기화
		vector<char> temp;
		string elem;
		cin >> elem;
		for (int j = 0; j < C; j++) {
			temp.push_back(elem[j]);
		}
		map.push_back(temp);
	}

	answer = DFS(R, C, 0, 0, visited);

	cout << answer;

	return 0;
}

//초기엔 unordered_set을 통해 알파벳 입력과 삭제를 반복 -> 시간 초과
//이후 unordered_set을 복제하고 넘기는 방식 -> 시간 초과
//길이 26의 벡터를 복제하고 넘기는 방식 -> 시간 초과
//최종 길이 26의 벡터를 체크하고 해당 부분 탐색 완료후 체크 해제 방식 -> 통과