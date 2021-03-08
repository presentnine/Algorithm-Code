#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef struct node{//Ʈ�� ���
    int x;
    node* left, * right;
    node(int d, node* l, node* r) :x(d), left(l), right(r) {};
}node;

bool comp(vector<int> a, vector<int> b) {
        return a[1] > b[1];
}

void insert(node* head, int data) {//Ʈ�� ���� �Լ�
    while (head!=NULL) {
        if (data<head->x) {
            head = head->left;
        }
        else {//head.data<data
            head = head->right;
        }
    }
    head= new node(data, NULL, NULL);
}
//���� ��ȸ
void preorder(node* head, vector<int> &answer, unordered_map<int, int> nodeName) {
    if (head == NULL)
        return;
    answer.push_back(nodeName[head->x]);
    preorder(head->left, answer, nodeName);
    preorder(head->right, answer, nodeName);
}
//���� ��ȸ
void postorder(node* head, vector<int>& answer, unordered_map<int, int> nodeName) {
    if (head == NULL)
        return;
    postorder(head->left, answer, nodeName);
    postorder(head->right, answer, nodeName);
    answer.push_back(nodeName[head->x]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    unordered_map<int, int> nodeName;
    vector<int> first; //���� ��ȸ ����� ����� ����
    vector<int> second; //���� ��ȸ ����� ����� ����

    for (int i = 0; i < nodeinfo.size(); i++)//���� x��ǥ�� Ű ������ �� �ε��� ����
        nodeName.insert(make_pair(nodeinfo[i][0], i + 1));

    sort(nodeinfo.begin(), nodeinfo.end(), comp);//y��ǥ ���� ����

    node* head = new node(nodeinfo[0][0], NULL, NULL);//��� �ʱ�ȭ

    for (int i = 1; i < nodeinfo.size(); i++) {//�յ��� ��� ����
        insert(head, nodeinfo[i][0]);
    }
    
    preorder(head, first, nodeName);//���� ��ȸ ����
    postorder(head, second, nodeName);//���� ��ȸ ����
    //��� ���� ���̱�
    answer.push_back(first);
    answer.push_back(second);

    return answer;
}