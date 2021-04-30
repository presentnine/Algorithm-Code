#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> map;

int DFS(int R, int C, int r, int c, vector<bool>& visited) {//DFS Ž��
	int result;

	if (0 > r || r >= R || 0 > c || c >= C)//��ġ �˻�
		return 0;

	int pos = map[r][c] - 'A';

	if (visited[pos] == true)//���ĺ� �ߺ�
		return 0;
	else {//���ο� ���ĺ��� ���
		visited[pos] = true;//�ش� Ž�� üũ

		result = DFS(R, C, r + 1, c, visited);
		result = max(result, DFS(R, C, r, c + 1, visited));
		result = max(result, DFS(R, C, r - 1, c, visited));
		result = max(result, DFS(R, C, r, c - 1, visited));

		visited[pos] = false;//Ž�� ����

		return 1 + result;
	}
}

int main() {
	vector<bool> visited(26, false);//�� ���ĺ� �ߺ� �˻� ����
	int R, C;
	int answer;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {//���� �ʱ�ȭ
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

//�ʱ⿣ unordered_set�� ���� ���ĺ� �Է°� ������ �ݺ� -> �ð� �ʰ�
//���� unordered_set�� �����ϰ� �ѱ�� ��� -> �ð� �ʰ�
//���� 26�� ���͸� �����ϰ� �ѱ�� ��� -> �ð� �ʰ�
//���� ���� 26�� ���͸� üũ�ϰ� �ش� �κ� Ž�� �Ϸ��� üũ ���� ��� -> ���