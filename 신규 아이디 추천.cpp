#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string after2 = "";
    bool overlap = false;

    //1단계
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
    //2단계
    for (int i = 0; i < new_id.size(); i++) {
        if ('a' <= new_id[i] && new_id[i] <= 'z' || '0' <= new_id[i] && new_id[i] <= '9'
            || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            after2 += new_id[i];
    }
    //3단계
    for (int i = 0; i < after2.size(); i++) {
        if (after2[i] == '.') {
            if (overlap == false) {
                overlap = true;
                answer += after2[i];
            }
        }
        else {
            answer += after2[i];
            overlap = false;
        }
    }
    //4단계
    if (answer[0] == '.')
        answer = answer.substr(1);
    if (answer[answer.size() - 1] == '.')
        answer = answer.substr(0, answer.size() - 1);
    //5단계
    if (answer.size() == 0)
        answer += 'a';
    //6단계, 7단계
    if (answer.size() >= 16) {
        if (answer[14] != '.')
            answer = answer.substr(0, 15);
        else
            answer = answer.substr(0, 14);
    }
    else if (answer.size() <= 2)
        while (answer.size() != 3)
            answer += answer[answer.size() - 1];

    return answer;
}