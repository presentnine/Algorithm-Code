#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> infoScore;

    for (int i = 0; i < info.size(); i++) {//info 贸府
        vector<string> token;
        istringstream ss(info[i]);
        string stringBuffer;

        while (getline(ss, stringBuffer, ' ')) {
            token.push_back(stringBuffer);
        }

        for (int j = 0; j <= 4; j++) {
            vector<int> temp;

            //temp 氦磐 盲快扁
            for (int k = 0; k < j; k++)
                temp.push_back(0);

            for (int k = 0; k < 4-j; k++)
                temp.push_back(1);

            do {
                string infoKey = "";

                for (int l = 0; l < 4; l++) {
                    if (temp[l] == 1)
                        infoKey += token[l];
                    else
                        infoKey += "-";
                }

                infoScore[infoKey].push_back(stoi(token[4]));

            } while (next_permutation(temp.begin(), temp.end()));
        }
    }

    for (auto i = infoScore.begin(); i != infoScore.end();i++) {
        sort(i->second.begin(), i->second.end());
    }

    for (int i = 0; i < query.size(); i++) {//query 贸府
        vector<string> token;
        istringstream ss(query[i]);
        string stringBuffer;
        string queryKey = "";
        int queryScore;

        while (getline(ss, stringBuffer, ' ')) {
            if (stringBuffer != "and")
                token.push_back(stringBuffer);
        }

        for (int j = 0; j < 4; j++)
            queryKey += token[j];

        queryScore = stoi(token[4]);

        vector<int> scores = infoScore[queryKey];

        int index = lower_bound(scores.begin(), scores.end(), queryScore) - scores.begin();

        answer.push_back(scores.size() - index);
    }

    return answer;
}