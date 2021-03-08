#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> usedAlpabet;
    vector<int> Alpabet(26, 0);
    int usedAlpabetSize;
    
    //사용한 문자들 확인
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        for (int j = 0; j < orders[i].length(); j++) {
            Alpabet[orders[i][j] - 'A']++;
        }
    }
    //사용한 문자들만 따로 저장
    for (int i = 0; i < 26; i++) {
        if (Alpabet[i] != 0)
            usedAlpabet.push_back(i + 'A');
    }
    usedAlpabetSize = usedAlpabet.size();
    //사용한 문자들 바탕으로 조합 생성
    for (int i = 0; i < course.size(); i++) {//단품 개수
        vector<int> temp;//조합에 사용할 임시 벡터
        vector<pair<string, int>> rank;//메뉴 조합, 횟수
        int max = 2;//횟수 중 최대값

        //temp 벡터 채우기
        for (int j = 0; j < usedAlpabetSize - course[i]; j++)
            temp.push_back(0);

        for (int j = 0; j < course[i]; j++)
            temp.push_back(1);

        do {//단품 개수 바탕 코스 조합 생성
            string menu = "";
            int count = 0;
            //메뉴 생성
            for (int j = 0; j < usedAlpabetSize; j++) {
                if (temp[j] == 1) {
                    menu += usedAlpabet[j];
                }
            }
            //orders에서 확인
            for (int j = 0; j < orders.size(); j++) {
                if (includes(orders[j].begin(), orders[j].end(), menu.begin(), menu.end()))
                    count++;
            }

            if (count >= max) {
                rank.push_back(make_pair(menu, count));
                max = count;
            }

        } while (next_permutation(temp.begin(), temp.end()));

        for (int j = 0; j < rank.size(); j++)//최대값만 저장
            if (rank[j].second == max)
                answer.push_back(rank[j].first);
    }
   
    sort(answer.begin(), answer.end());

    return answer;
}