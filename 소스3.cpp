#include <string>
#include <vector>
#include <stack>

using namespace std;

int result[1000000] = { 0, };

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    int pos = k;
    int lastPos = n - 1;
    stack<int> s;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'D') {
            for (int j = 0; j < stoi(cmd[i].substr(1));) {
                ++pos;
                if (result[pos] == 0)
                    ++j;
            }
        }
        else if (cmd[i][0] == 'U') {
            for (int j = 0; j < stoi(cmd[i].substr(1));) {
                --pos;
                if (result[pos] == 0)
                    ++j;
            }
        }
        else if (cmd[i][0] == 'C') {
            s.push(pos);
            result[pos] = -1;

            if (pos == lastPos) {
                while (result[--pos] == -1);
                lastPos = pos;
            }
            else {
                while (result[++pos] == -1);
            }
        }
        else { //"Z"
            result[s.top()] = 0;
            s.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        if (result[i] == 0)
            answer += 'O';
        else
            answer += 'X';
    }

    return answer;
}