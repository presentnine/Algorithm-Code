#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void check(int n, vector<int> weak, vector<int> dist, int count, int& answer) { //���ȣ��
    int length;
    int minNextWeakSize = 15;
    vector<int> nextDist;

    if (weak.size() == 0) {//��������
        if (count < answer)
            answer = count;
        return;
    }

    if (count == answer - 1 || dist.size() == 0)//��������
        return;

    length = dist[dist.size() - 1];//���� �Լ����� ����� ���̴� ���� ū ����
    nextDist.assign(dist.begin(), dist.end() - 1);//���ο� dist���� ����

    for (int i = 0; i < weak.size(); i++) {//��ü weak�� ���� �ݺ�
        vector<int> nextWeak;
        int pos = weak[i];

        if (pos + length >= n) {//��ġ���� ���̸�ŭ�� n�� �Ѿ ���
            for (int j = 0; j < weak.size(); j++) {//���ο� weak���� ����
                if ((pos + length) % n < weak[j] && weak[j] < pos)
                    nextWeak.push_back(weak[j]);
            }
        }
        else {//��ġ���� ���̸�ŭ�� n���� ���� ���
            for (int j = 0; j < weak.size(); j++) {//���ο� weak���� ����
                if (!(pos <= weak[j] && weak[j] <= pos + length))
                    nextWeak.push_back(weak[j]);
            }
        }

        if (nextWeak.size() <= minNextWeakSize) {//���ȣ�� ����
            minNextWeakSize = nextWeak.size();
            check(n, nextWeak, nextDist, count + 1, answer);
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10;
    sort(dist.begin(), dist.end()); //�Ÿ� ���� ����

    check(n, weak, dist, 0, answer); //Ȯ�� �Լ� ȣ��

    if (answer == 10) //���� ã�� ���� ���
        answer = -1;

    return answer;
}