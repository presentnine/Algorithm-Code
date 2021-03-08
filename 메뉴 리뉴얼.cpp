#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> usedAlpabet;
    vector<int> Alpabet(26, 0);
    int usedAlpabetSize;
    
    //����� ���ڵ� Ȯ��
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
        for (int j = 0; j < orders[i].length(); j++) {
            Alpabet[orders[i][j] - 'A']++;
        }
    }
    //����� ���ڵ鸸 ���� ����
    for (int i = 0; i < 26; i++) {
        if (Alpabet[i] != 0)
            usedAlpabet.push_back(i + 'A');
    }
    usedAlpabetSize = usedAlpabet.size();
    //����� ���ڵ� �������� ���� ����
    for (int i = 0; i < course.size(); i++) {//��ǰ ����
        vector<int> temp;//���տ� ����� �ӽ� ����
        vector<pair<string, int>> rank;//�޴� ����, Ƚ��
        int max = 2;//Ƚ�� �� �ִ밪

        //temp ���� ä���
        for (int j = 0; j < usedAlpabetSize - course[i]; j++)
            temp.push_back(0);

        for (int j = 0; j < course[i]; j++)
            temp.push_back(1);

        do {//��ǰ ���� ���� �ڽ� ���� ����
            string menu = "";
            int count = 0;
            //�޴� ����
            for (int j = 0; j < usedAlpabetSize; j++) {
                if (temp[j] == 1) {
                    menu += usedAlpabet[j];
                }
            }
            //orders���� Ȯ��
            for (int j = 0; j < orders.size(); j++) {
                if (includes(orders[j].begin(), orders[j].end(), menu.begin(), menu.end()))
                    count++;
            }

            if (count >= max) {
                rank.push_back(make_pair(menu, count));
                max = count;
            }

        } while (next_permutation(temp.begin(), temp.end()));

        for (int j = 0; j < rank.size(); j++)//�ִ밪�� ����
            if (rank[j].second == max)
                answer.push_back(rank[j].first);
    }
   
    sort(answer.begin(), answer.end());

    return answer;
}