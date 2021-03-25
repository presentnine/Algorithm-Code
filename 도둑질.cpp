#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> cache;

int search(vector<int> money, int N, int start, int nextStartIndex) {
    int result = 0;

    if (start == 0) {
        if (nextStartIndex % N == N - 1 || nextStartIndex % N == 0)
            return 0;

        if (cache[start][nextStartIndex] != -1)
            return cache[start][nextStartIndex];

        for (int i = nextStartIndex; i < nextStartIndex + 2 && (i % N != N - 1); i++)
            result = max(result, money[i % N] + search(money, N, start, (i + 2) % N));
    }
    else if (start == 1) {
        if (nextStartIndex % N == 0 || nextStartIndex % N == 1)
            return 0;

        if (cache[start][nextStartIndex] != -1)
            return cache[start][nextStartIndex];

        for (int i = nextStartIndex; i < nextStartIndex + 2 && (i % N != 0); i++)
            result = max(result, money[i % N] + search(money, N, start, (i + 2) % N));
    }
    else {//start==2
        if (nextStartIndex % N == 1 || nextStartIndex % N == 2)
            return 0;

        if (cache[start][nextStartIndex] != -1)
            return cache[start][nextStartIndex];

        for (int i = nextStartIndex; i < nextStartIndex + 2 && (i % N != 1); i++)
            result = max(result, money[i % N] + search(money, N, start, (i + 2) % N));
    }

    return cache[start][nextStartIndex] = result;
}

int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    
    for (int i = 0; i < 3; i++) {
        vector<int> temp(N, -1);
        cache.push_back(temp);
    }

    answer = max(money[0] + search(money, N, 0, 2), money[1] + search(money, N, 1, 3 % N));
    answer = max(answer, money[2] + search(money, N, 2, 4 % N));

    return answer;
}