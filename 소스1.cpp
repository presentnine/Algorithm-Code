#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string result = "";

    for (int i = 0; i < s.size();) {
        if ('0' <= s[i] && s[i] <= '9') {
            result += s[i++];
        }
        else {
            switch (s[i]) {
            case 'z':
                result += "0";
                i += 4;
                break;
            case'o':
                result += "1";
                i += 3;
                break;
            case't':
                if (s[i + 1] == 'w') {
                    result += "2";
                    i += 3;
                }
                else {
                    result += "3";
                    i += 5;
                }
                break;
            case 'f':
                if (s[i + 1] == 'o') {
                    result += "4";
                    i += 4;
                }
                else {
                    result += "5";
                    i += 4;
                }
                break;
            case 's':
                if (s[i + 1] == 'i') {
                    result += "6";
                    i += 3;
                }
                else {
                    result += "7";
                    i += 5;
                }
                break;
            case 'e':
                result += "8";
                i += 5;
                break;
            case 'n':
                result += "9";
                i += 4;
                break;
            default:
                break;
            }
        }
    }

    answer = stoi(result);

    return answer;
}