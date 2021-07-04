#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool compare(string a, string b) {//�ܼ� ���̼� ����
	return a.size() < b.size();
}

string search(int n, vector<string> phoneNumbers) {
	int minSize = phoneNumbers[0].size();

	unordered_set<string> phoneNumbersSet;

	phoneNumbersSet.insert(phoneNumbers[0]);//�� ó�� ��ȭ��ȣ�� �׳� ����

	for (int i = 1; i < n; i++) {//������ ��ȭ��ȣ�鿡 ����
		for (int j = minSize; j <= phoneNumbers[i].size(); j++) {//�ּ� ��������� �ϳ��� �ø���
			string s = phoneNumbers[i].substr(0, j);

			if (phoneNumbersSet.find(s) != phoneNumbersSet.end())//�ռ� ��ȭ��ȣ�� �߿� �ִٸ�
				return "NO";
		}

		phoneNumbersSet.insert(phoneNumbers[i]);//�� ��ȭ��ȣ�� ���� ����
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

		for (int j = 0; j < n; j++) {//��ȭ��ȣ ����
			cin >> temp;
			phoneNumbers.push_back(temp);
		}

		sort(phoneNumbers.begin(), phoneNumbers.end(), compare);//����

		answer.push_back(search(n, phoneNumbers));
	}

	for (int i = 0; i < t; i++)
		cout << answer[i] << endl;

	return 0;
}