#include <string>
#include <vector>

using namespace std;

int solution4(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> route;

    for (int i = 0; i < n; i++) {//격자 생성
        vector<int> temp(m, 0);
        route.push_back(temp);
    }
    route[0][0] = 1;//시작 위치 경우의 수 1 대입

    for (int i = 0; i < puddles.size(); i++) { //웅덩이 표시
        route[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }

    for (int i = 0; i < n; i++) {//행
        for (int j = 0; j < m; j++) {//열
            if (route[i][j] != -1) {//해당 위치가 웅덩이가 아니라면
                if (i > 0 && route[i - 1][j] != -1)//위쪽이 있고 웅덩이가 아니라면
                    route[i][j] += route[i - 1][j];
                if (j > 0 && route[i][j - 1] != -1)//왼쪽이 있고 웅덩이가 아니라면
                    route[i][j] += route[i][j - 1];

                route[i][j] = route[i][j] % 1000000007;//추가적인 연산 진행
            }
        }
    }

    return route[n - 1][m - 1]; //학교의 위치 값이 정답
}