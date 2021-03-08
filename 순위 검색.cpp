#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(), 0);
    vector<vector<string>> queryInfor;
    vector<int> queryScore;

    for (int i = 0; i < query.size(); i++) {//쿼리문 전처리
        vector<string> token;
        istringstream ss(query[i]);
        string stringBuffer;
        int pos = 0;

        while (getline(ss, stringBuffer, ' ')) {
            if (stringBuffer != "and") {
                if (stringBuffer != "-")
                    token.push_back(stringBuffer + " ");
                else
                    token.push_back(" ");
            }
        }

        queryInfor.push_back(token);
        queryScore.push_back(stoi(token[4]));
    }

    for (int i = 0; i < info.size(); i++) {
        for (int j = 0; j < query.size(); j++) {
            int current = 0;
            int count = 0;

            for (; count < 4; count++) {
                current = info[i].find(queryInfor[j][count], current);
                if (current == -1)
                    break;
                else
                    current += queryInfor[j][count].size();
            }

            if (count == 4) {
                int applicantScore = stoi(info[i].substr(current));
                if (applicantScore >= queryScore[j])
                    answer[j]++;
            }
        }
    }

    return answer;
}