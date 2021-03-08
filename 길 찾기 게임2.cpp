#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {//Ʈ�� ���
    int x;
    int index;
    node* left, * right;
    node(int X, int I, node* l, node* r) :x(X), index(I), left(l), right(r) {};
}node;

bool comp(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

void insert(node* head, int x, int data) {//Ʈ�� ���� �Լ�
    while (1) {
        if (x < head->x) {
            if (head->left == NULL) {
                head->left = new node(x, data, NULL, NULL);
                return;
            }
            else {
                head = head->left;
            }
        }
        else {//head.data<data
            if (head->right == NULL) {
                head->right = new node(x, data, NULL, NULL);
                return;
            }
            else {
                head = head->right;
            }
        }
    }
}

//���� ��ȸ
void preorder(node* head, vector<int>& answer) {
    if (head == NULL)
        return;
    answer.push_back(head->index);
    preorder(head->left, answer);
    preorder(head->right, answer);
}
//���� ��ȸ
void postorder(node* head, vector<int>& answer) {
    if (head == NULL)
        return;
    postorder(head->left, answer);
    postorder(head->right, answer);
    answer.push_back(head->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<int> first; //���� ��ȸ ����� ����� ����
    vector<int> second; //���� ��ȸ ����� ����� ����

    for (int i = 0; i < nodeinfo.size(); i++)//���� �ε��� ����
        nodeinfo[i].push_back(i + 1);

    sort(nodeinfo.begin(), nodeinfo.end(), comp);//y��ǥ ���� ����

    node* head = new node(nodeinfo[0][0], nodeinfo[0][2], NULL, NULL);//��� �ʱ�ȭ

    for (int i = 1; i < nodeinfo.size(); i++)//�յ��� ��� ����
        insert(head, nodeinfo[i][0], nodeinfo[i][2]);

    preorder(head, first);//���� ��ȸ ����
    postorder(head, second);//���� ��ȸ ����
    //��� ���� ���̱�
    answer.push_back(first);
    answer.push_back(second);

    return answer;
}