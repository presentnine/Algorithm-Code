#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {//트리 노드
    int x;
    int index;
    node* left, * right;
    node(int X, int I, node* l, node* r) :x(X), index(I), left(l), right(r) {};
}node;

bool comp(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

void insert(node* head, int x, int data) {//트리 삽입 함수
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

//전위 순회
void preorder(node* head, vector<int>& answer) {
    if (head == NULL)
        return;
    answer.push_back(head->index);
    preorder(head->left, answer);
    preorder(head->right, answer);
}
//후위 순회
void postorder(node* head, vector<int>& answer) {
    if (head == NULL)
        return;
    postorder(head->left, answer);
    postorder(head->right, answer);
    answer.push_back(head->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<int> first; //전위 순회 결과가 저장될 벡터
    vector<int> second; //후위 순회 결과가 저장될 벡터

    for (int i = 0; i < nodeinfo.size(); i++)//점의 인덱스 저장
        nodeinfo[i].push_back(i + 1);

    sort(nodeinfo.begin(), nodeinfo.end(), comp);//y좌표 기준 정렬

    node* head = new node(nodeinfo[0][0], nodeinfo[0][2], NULL, NULL);//헤더 초기화

    for (int i = 1; i < nodeinfo.size(); i++)//잇따른 노드 삽입
        insert(head, nodeinfo[i][0], nodeinfo[i][2]);

    preorder(head, first);//전위 순회 실행
    postorder(head, second);//후위 순회 실행
    //결과 벡터 붙이기
    answer.push_back(first);
    answer.push_back(second);

    return answer;
}