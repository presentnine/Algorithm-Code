#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void check(int n, vector<int> weak, vector<int> dist, int count, int& answer) { //재귀호출
    int length;
    int minNextWeakSize = 15;
    vector<int> nextDist;

    if (weak.size() == 0) {//종료조건
        if (count < answer)
            answer = count;
        return;
    }

    if (count == answer - 1 || dist.size() == 0)//종료조건
        return;

    length = dist[dist.size() - 1];//현재 함수에서 사용할 길이는 가장 큰 길이
    nextDist.assign(dist.begin(), dist.end() - 1);//새로운 dist벡터 생성

    for (int i = 0; i < weak.size(); i++) {//전체 weak에 대해 반복
        vector<int> nextWeak;
        int pos = weak[i];

        if (pos + length >= n) {//위치부터 길이만큼이 n을 넘어선 경우
            for (int j = 0; j < weak.size(); j++) {//새로운 weak벡터 생성
                if ((pos + length) % n < weak[j] && weak[j] < pos)
                    nextWeak.push_back(weak[j]);
            }
        }
        else {//위치부터 길이만큼이 n보다 작을 경우
            for (int j = 0; j < weak.size(); j++) {//새로운 weak벡터 생성
                if (!(pos <= weak[j] && weak[j] <= pos + length))
                    nextWeak.push_back(weak[j]);
            }
        }

        if (nextWeak.size() <= minNextWeakSize) {//재귀호출 제한
            minNextWeakSize = nextWeak.size();
            check(n, nextWeak, nextDist, count + 1, answer);
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10;
    sort(dist.begin(), dist.end()); //거리 벡터 정렬

    check(n, weak, dist, 0, answer); //확인 함수 호출

    if (answer == 10) //답을 찾지 못한 경우
        answer = -1;

    return answer;
}