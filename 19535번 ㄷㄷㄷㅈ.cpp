#include <iostream>
#include <vector>

using namespace std;

vector<int> treeInfor[300001];

int main1() {
	int N, u, v;
	long long D = 0;
	long long G = 0;

	cin >> N;

	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		treeInfor[u].push_back(v);
		treeInfor[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {//트리 파악
		long long childNum = treeInfor[i].size();
		if (childNum >= 2) {
			for (int j = 0; j < childNum; j++) {//ㄷ트리 파악
				D += (childNum - 1) * (treeInfor[treeInfor[i][j]].size() - 1);
			}
			if (childNum >= 3) {//ㅈ트리 파악
				G += childNum * (childNum - 1) * (childNum - 2) / 6;
			}
		}
	}

	D /= 2;//ㄷ트리의 경우 중복 제거

	if (D > G * 3)
		cout << "D" << endl;
	else if (D < G * 3)
		cout << "G" << endl;
	else
		cout << "DUDUDUNGA" << endl;

	return 0;
}