#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compare(string a, string b) {//단순 길이순 정렬
	return a.size() < b.size();
}

string search(int n, vector<string> phoneNumbers) {
	int minSize = phoneNumbers[0].size();

	unordered_set<string> phoneNumbersSet;

	phoneNumbersSet.insert(phoneNumbers[0]);//맨 처음 전화번호는 그냥 저장

	for (int i = 1; i < n; i++) {//이후의 전화번호들에 대해
		for (int j = minSize; j <= phoneNumbers[i].size(); j++) {//최소 사이즈부터 하나씩 늘리며
			string s = phoneNumbers[i].substr(0, j);

			if (phoneNumbersSet.find(s) != phoneNumbersSet.end())//앞선 전화번호들 중에 있다면
				return "NO";
		}

		phoneNumbersSet.insert(phoneNumbers[i]);//현 전화번호를 최종 저장
	}

	return "YES";
}

int main() {
	int t, n;
	string temp;
	vector<string> answer;

	cin >> t;

	for (int i = 0; i < t; i++) {
		vector<string> phoneNumbers;
		cin >> n;

		for (int j = 0; j < n; j++) {//전화번호 저장
			cin >> temp;
			phoneNumbers.push_back(temp);
		}

		sort(phoneNumbers.begin(), phoneNumbers.end(), compare);//정렬

		answer.push_back(search(n, phoneNumbers));
	}

	for (int i = 0; i < t; i++)
		cout << answer[i] << endl;

	return 0;
}