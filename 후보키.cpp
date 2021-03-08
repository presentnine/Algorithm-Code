#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int tupleSize = relation.size();
    int columnSize = relation[0].size();
    vector<string> answerKeySet;//�ε������ �̷���� ����� Ű�� ����

    for (int i = 1; i <= columnSize; i++) {//Ű�� ����� �÷� ����
        vector<bool> combination(columnSize - i, false);
        combination.insert(combination.end(), i, true);

        do {//Ű ���� �� ����
            unordered_set<string> keySet;
            bool isRightKey = true;
            string keyIndex = "";

            for (int k = 0; k < columnSize; k++) {//����� �÷� �ε������ �̷���� ���ڿ� ���� -> �ּҼ� ������ ���
                if (combination[k]) {
                    keyIndex += to_string(k);
                }
            }

            for (int k = 0; k < answerKeySet.size(); k++) {//�̹� �ּҼ��� �����ϴ� Ű���� �ε��� ���տ� ����
                if (includes(keyIndex.begin(),keyIndex.end(),answerKeySet[k].begin(), answerKeySet[k].end())) {
                    isRightKey = false;
                    break;
                }
            }

            if (!isRightKey)//�ش� �ε��� ���� ��ü�� ���� ������ �ǳʶ�
                continue;

            for (int j = 0; j < tupleSize; j++) {//Ű ���� �� unordered_set�� insert
                string key = "";
                for (int k = 0; k < columnSize; k++) {
                    if (combination[k]) {
                        key += relation[j][k] + "/";
                    }
                }
                keySet.insert(key);
            }

            if (keySet.size() == tupleSize) {//unordered_set�� ũ�Ⱑ Ʃ���� ũ��� �����ϴٸ� �˸��� Ű �׷�
                answerKeySet.push_back(keyIndex);
                answer++;
            }

        } while (next_permutation(combination.begin(), combination.end()));
    }

    return answer;
}