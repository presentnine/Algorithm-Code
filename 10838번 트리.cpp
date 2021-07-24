#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int pathColor[100001] = { 0, };
int nodeParent[100001] = { 0, };
int visited[100001];

int findCommonAncestor(int a,int b, int temp) {
	int aAncestor = a;
	int bAncestor = b;
	int time = 1000;

	if (a == b)
		return a;

	while (time-- > 0) {
		if (aAncestor != -1) {
			if (visited[aAncestor] == temp)
				return aAncestor;

			visited[aAncestor] = temp;

			aAncestor = nodeParent[aAncestor];
		}
		
		if (bAncestor != -1) {
			if (visited[bAncestor] == temp)
				return bAncestor;

			visited[bAncestor] = temp;

			bAncestor = nodeParent[bAncestor];
		}
	}

	return 0;
}

int main() {
	int N, K;
	int r, a, b, c;
	int commonAncestor, tempA, tempB;
	vector<int> result;

	cin >> N >> K;

	nodeParent[0] = -1;

	for (int i = 0; i < K; i++) {
		cin >> r;

		if (r == 2) {
			//cin >> a >> b;
			scanf("%d %d", &a, &b);
			nodeParent[a] = b;
		}
		else {
			//cin >> a >> b;
			scanf("%d %d", &a, &b);
			commonAncestor = findCommonAncestor(a, b, i + 1);
			tempA = a;
			tempB = b;
			if (r == 1) {
				//cin >> c;
				scanf_s("%d", &c);

				while (tempA != commonAncestor) {
					pathColor[tempA] = c;
					tempA = nodeParent[tempA];
				}

				while (tempB != commonAncestor) {
					pathColor[tempB] = c;
					tempB = nodeParent[tempB];
				}
			}
			else {
				unordered_set<int> color;

				while (tempA != commonAncestor) {
					color.insert(pathColor[tempA]);
					tempA = nodeParent[tempA];
				}

				while (tempB != commonAncestor) {
					color.insert(pathColor[tempB]);
					tempB = nodeParent[tempB];
				}

				printf("%d\n", color.size());
				
				//result.push_back(color.size());
			}
		}
	}
	
	/*
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
		*/
	return 0;
}