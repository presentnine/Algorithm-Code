#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int tupleSize = relation.size();
    int columnSize = relation[0].size();
    vector<string> answerKeySet;//인덱스들로 이루어진 사용한 키의 집합

    for (int i = 1; i <= columnSize; i++) {//키로 사용할 컬럼 개수
        vector<bool> combination(columnSize - i, false);
        combination.insert(combination.end(), i, true);

        do {//키 조합 후 실험
            unordered_set<string> keySet;
            bool isRightKey = true;
            string keyIndex = "";

            for (int k = 0; k < columnSize; k++) {//사용할 컬럼 인덱스들로 이루어진 문자열 제작 -> 최소성 입증에 사용
                if (combination[k]) {
                    keyIndex += to_string(k);
                }
            }

            for (int k = 0; k < answerKeySet.size(); k++) {//이미 최소성을 만족하는 키들의 인덱스 집합에 검증
                if (includes(keyIndex.begin(),keyIndex.end(),answerKeySet[k].begin(), answerKeySet[k].end())) {
                    isRightKey = false;
                    break;
                }
            }

            if (!isRightKey)//해당 인덱스 조합 자체가 맞지 않으면 건너뜀
                continue;

            for (int j = 0; j < tupleSize; j++) {//키 생성 후 unordered_set에 insert
                string key = "";
                for (int k = 0; k < columnSize; k++) {
                    if (combination[k]) {
                        key += relation[j][k] + "/";
                    }
                }
                keySet.insert(key);
            }

            if (keySet.size() == tupleSize) {//unordered_set의 크기가 튜플의 크기와 동일하다면 알맞은 키 그룹
                answerKeySet.push_back(keyIndex);
                answer++;
            }

        } while (next_permutation(combination.begin(), combination.end()));
    }

    return answer;
}