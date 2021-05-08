#include <string>
#include <vector>

using namespace std;

bool check(vector<string> place, int r, int c) {
    if ((r + 2) < 5) { //³²
        if (place[r + 2][c] == 'P' && place[r + 1][c] != 'X')
            return false;
        if (place[r + 1][c] == 'P')
            return false;
    }
    if ((r + 1) < 5 && (c + 1) < 5) { //³²µ¿
        if (place[r + 1][c + 1] == 'P'
            && (place[r + 1][c] != 'X' || place[r][c + 1] != 'X'))
            return false;
    }
    if ((c + 2) < 5) { //µ¿
        if (place[r][c + 2] == 'P' && place[r][c + 1] != 'X')
            return false;
        if (place[r][c + 1] == 'P')
            return false;
        
    }
    if (0 <= (r - 1) && (c + 1) < 5) { //ºÏµ¿
        if (place[r - 1][c + 1] == 'P'
            && (place[r - 1][c] != 'X' || place[r][c + 1] != 'X'))
            return false;
    }
    if (0 <= (r - 2)) { //ºÏ
        if (place[r - 2][c] == 'P' && place[r - 1][c] != 'X')
            return false;
        if (place[r - 1][c] == 'P')
            return false;
    }
    if (0 <= (r - 1) && 0 <= (c - 1)) { //ºÏ¼­
        if (place[r - 1][c - 1] == 'P'
            && (place[r - 1][c] != 'X' || place[r][c - 1] != 'X'))
            return false;
    }
    if (0 <= (c - 2)) { //¼­
        if (place[r][c - 2] == 'P' && place[r][c - 1] != 'X')
            return false;
        if (place[r][c - 1] == 'P')
            return false;
    }
    if ((r + 1) < 5 && 0 <= (c - 1)) { //³²¼­
        if (place[r + 1][c - 1] == 'P'
            && (place[r + 1][c] != 'X' || place[r][c - 1] != 'X'))
            return false;
    }
    return true;
}

bool search(vector<string> place) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (place[i][j] == 'P') {
                if (!check(place, i, j))
                    return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; i++) {
        if (search(places[i]))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}