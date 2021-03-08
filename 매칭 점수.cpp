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
    
    for (int i = 0; i < pages.size(); i++) {//�� ������ url ���� �� ����
        string url = "";

        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        for (int j = pages[i].find("<meta property=\"og:url\" content=\"") + 33; pages[i][j] != '\"'; j++)
            url += pages[i][j];

        urlToIndex[url] = i;
    }

    for (int i = 0; i < pages.size(); i++) {//���� ���
        double basicScore = 0;
        int pos = 0;
        int bodyStart = pages[i].find("<body>") + 6;
        int linkCount = 0;
        vector<string> linkList;
        //�⺻ ���� ���
        pos = pages[i].find(word, bodyStart);
        while (pos != -1) {
            if (!('a' <= pages[i][pos - 1] && pages[i][pos - 1] <= 'z') && !('a' <= pages[i][pos + word.size()] && pages[i][pos + word.size()] <= 'z'))
                basicScore++;

            pos = pages[i].find(word, pos + 1);
        }
        scoreBoard[i] += basicScore;

        //�� ����� ��ũ ���� �й�
        pos = pages[i].find("<a href=\"", bodyStart);
        while (pos != -1) {
            string link = "";
            linkCount++;

            for (int j = pos + 9; pages[i][j] != '\"'; j++)
                link += pages[i][j];

            //�ش� ��ũ�� page �߿� �ִ� ��ũ���� Ȯ��
            if (urlToIndex.find(link) != urlToIndex.end())
                linkList.push_back(link);

            pos = pages[i].find("<a href=\"", pos + 1);
        }

        for (int j = 0; j < linkList.size(); j++) {//�ش� page ���� �߰�
            scoreBoard[urlToIndex[linkList[j]]] += basicScore / linkCount;
        }
    }
    //���� ������ �ε��� Ȯ��
    for (int i = 0; i < scoreBoard.size(); i++) {
        if (scoreBoard[i] > bestScore) {
            bestScore = scoreBoard[i];
            answer = i;
        }
    }

    return answer;
}