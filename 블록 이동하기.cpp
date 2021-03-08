#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct infor {//����� ���� ����ü
    int x1, y1, x2, y2;
    char state;
    int time;
};

void check(vector<vector<int>>& board, infor next, unordered_set<string>& visited, int size, queue<infor> &q) {
    int x1 = next.x1, y1 = next.y1, x2 = next.x2, y2 = next.y2;
    //��ǥ�� �������� ���
    if (x1 < 0 || x1 >= size || y1 < 0 || y1 >= size)
        return;
    if (x2 < 0 || x2 >= size || y2 < 0 || y2 >= size)
        return;
    //����� ��ġ�� ���� ���
    if (board[x1][y1] == 1)
        return;
    if (board[x2][y2] == 1)
        return;
    //����� �̹� �� ���� �ִ� ���
    if (visited.find(to_string(x1) + '/' + to_string(y1) + '/' + to_string(x2) + '/' + to_string(y2)) != visited.end())
        return;
    //���� �Ϸ� ���� ó��
    visited.insert(to_string(x1) + '/' + to_string(y1) + '/' + to_string(x2) + '/' + to_string(y2));
    q.push(next);
    return;
}

int solution(vector<vector<int>> board) {
    int size = board.size();
    queue<infor> q;
    unordered_set<string> visited; //�ߺ� Ȯ��
    infor start;
    vector<vector<int>> mov = { {-1,0}, {1,0}, {0,-1}, {0,1} }; //�����¿�

    //���� ���� ���� �� ť�� ��� ����
    start.x1 = start.y1 = start.x2 = start.time = 0;
    start.y2 = 1;
    start.state = 'g';
    visited.insert("0/0/0/1");
    q.push(start);
    //BFS �̿�
    while (!q.empty()) {
        infor pos = q.front(); q.pop();//�ϳ��� �����´�.

        if ((pos.x1 == size - 1 && pos.y1 == size - 1) || (pos.x2 == size - 1 && pos.y2 == size - 1))
            return pos.time;

        infor next;
        pos.time += 1;
        
        for (int i = 0; i < 4; i++) {//�⺻���� �̵�(�����¿�)
            next = pos;
            next.x1 += mov[i][0]; next.x2 += mov[i][0];
            next.y1 += mov[i][1]; next.y2 += mov[i][1];
            check(board, next, visited, size, q);
        }

        if (pos.state == 'g') {//�� ����� ������ ����� ȸ��
            pos.state = 's';

            if (pos.x1 < size - 1 && board[pos.x1 + 1][pos.y1] == 0 && board[pos.x2 + 1][pos.y2] == 0) {//�Ʒ��� ȸ���� ����
                next = pos; //��1 ���� �ð�
                next.y2 = next.y1;
                next.x2 = next.x1 + 1;
                check(board, next, visited, size, q);

                next = pos; //��2 ���� �ݽð�
                next.y1 = next.y2;
                next.x1 = next.x2 + 1;
                check(board, next, visited, size, q);
            }

            if (pos.x1 > 0 && board[pos.x1 - 1][pos.y1] == 0 && board[pos.x2 - 1][pos.y2] == 0) {//���� ȸ���� ����
                next = pos; //��1 ���� �ݽð�
                next.y2 = next.y1;
                next.x2 = next.x1 - 1;
                check(board, next, visited, size, q);

                next = pos; //��2 ���� �ð�
                next.y1 = next.y2;
                next.x1 = next.x2 - 1;
                check(board, next, visited, size, q);
            }

        }
        else {//�� ����� ������ ����� ȸ��
            pos.state = 'g';

            if (pos.y1 < size - 1 && board[pos.x1][pos.y1 + 1] == 0 && board[pos.x2][pos.y2 + 1] == 0) {//������ ȸ���� ����
                next = pos; //��1 ���� �ݽð�
                next.y2 = next.y1 + 1;
                next.x2 = next.x1;
                check(board, next, visited, size, q);

                next = pos; //��2 ���� �ð�
                next.y1 = next.y2 + 1;;
                next.x1 = next.x2;
                check(board, next, visited, size, q);
            }

            if (pos.y1 > 0 && board[pos.x1][pos.y1 - 1] == 0 && board[pos.x2][pos.y2 - 1] == 0) {//���� ȸ���� ����
                next = pos; //��1 ���� �ð�
                next.y2 = next.y1 - 1;
                next.x2 = next.x1;
                check(board, next, visited, size, q);

                next = pos; //��2 ���� �ݽð�
                next.y1 = next.y2 - 1;
                next.x1 = next.x2;
                check(board, next, visited, size, q);
            }
        }
    }
    return 0;
}