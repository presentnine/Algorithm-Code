#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string word, vector<string> pages) {
    int answer = 0;
    double bestScore = 0;
    vector<double> scoreBoard(pages.size(), 0);
    unordered_map<string, int> urlToIndex;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    for (int i = 0; i < pages.size(); i++) {//각 페이지 url 추출 후 저장
        string url = "";

        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        for (int j = pages[i].find("<meta property=\"og:url\" content=\"") + 33; pages[i][j] != '\"'; j++)
            url += pages[i][j];

        urlToIndex[url] = i;
    }

    for (int i = 0; i < pages.size(); i++) {//점수 계산
        double basicScore = 0;
        int pos = 0;
        int bodyStart = pages[i].find("<body>") + 6;
        int linkCount = 0;
        vector<string> linkList;
        //기본 점수 계산
        pos = pages[i].find(word, bodyStart);
        while (pos != -1) {
            if (!('a' <= pages[i][pos - 1] && pages[i][pos - 1] <= 'z') && !('a' <= pages[i][pos + word.size()] && pages[i][pos + word.size()] <= 'z'))
                basicScore++;

            pos = pages[i].find(word, pos + 1);
        }
        scoreBoard[i] += basicScore;

        //각 연결된 링크 점수 분배
        pos = pages[i].find("<a href=\"", bodyStart);
        while (pos != -1) {
            string link = "";
            linkCount++;

            for (int j = pos + 9; pages[i][j] != '\"'; j++)
                link += pages[i][j];

            //해당 링크가 page 중에 있는 링크인지 확인
            if (urlToIndex.find(link) != urlToIndex.end())
                linkList.push_back(link);

            pos = pages[i].find("<a href=\"", pos + 1);
        }

        for (int j = 0; j < linkList.size(); j++) {//해당 page 점수 추가
            scoreBoard[urlToIndex[linkList[j]]] += basicScore / linkCount;
        }
    }
    //최종 점수와 인덱스 확인
    for (int i = 0; i < scoreBoard.size(); i++) {
        if (scoreBoard[i] > bestScore) {
            bestScore = scoreBoard[i];
            answer = i;
        }
    }

    return answer;
}