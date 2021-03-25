#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> cache;

int search(vector<int> money, int N, int selectZero, int nextStartIndex) {
    int result = 0;

    if (selectZero == 1) {
        if (nextStartIndex >= N - 1)
            return 0;

        if (cache[selectZero][nextStartIndex] != -1)
            return cache[selectZero][nextStartIndex];

        for (int i = nextStartIndex; i < nextStartIndex + 2 && i < N - 1; i++)
            result = max(result, money[i] + search(money, N, selectZero, i + 2));
    }
    else {
        if (nextStartIndex >= N)
            return 0;

        if (cache[selectZero][nextStartIndex] != -1)
            return cache[selectZero][nextStartIndex];

        for (int i = nextStartIndex; i < nextStartIndex + 2 && i < N; i++)
            result = max(result, money[i] + search(money, N, selectZero, i + 2));
    }

    return cache[selectZero][nextStartIndex] = result;
}

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();

    for (int i = 0; i < 2; i++) {
        vector<int> temp(N, -1);
        cache.push_back(temp);
    }

    answer = money[0] + search(money, N, 1, 2);
    answer = max(answer, money[1] + search(money, N, 0, 3));
    answer = max(answer, money[2] + search(money, N, 0, 4));

    return answer;
}