#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef struct node{//트리 노드
    int x;
    node* left, * right;
    node(int d, node* l, node* r) :x(d), left(l), right(r) {};
}node;

bool comp(vector<int> a, vector<int> b) {
        return a[1] > b[1];
}

void insert(node* head, int data) {//트리 삽입 함수
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
//전위 순회
void preorder(node* head, vector<int> &answer, unordered_map<int, int> nodeName) {
    if (head == NULL)
        return;
    answer.push_back(nodeName[head->x]);
    preorder(head->left, answer, nodeName);
    preorder(head->right, answer, nodeName);
}
//후위 순회
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
    vector<int> first; //전위 순회 결과가 저장될 벡터
    vector<int> second; //후위 순회 결과가 저장될 벡터

    for (int i = 0; i < nodeinfo.size(); i++)//점의 x좌표를 키 값으로 한 인덱스 저장
        nodeName.insert(make_pair(nodeinfo[i][0], i + 1));

    sort(nodeinfo.begin(), nodeinfo.end(), comp);//y좌표 기준 정렬

    node* head = new node(nodeinfo[0][0], NULL, NULL);//헤더 초기화

    for (int i = 1; i < nodeinfo.size(); i++) {//잇따른 노드 삽입
        insert(head, nodeinfo[i][0]);
    }
    
    preorder(head, first, nodeName);//전위 순회 실행
    postorder(head, second, nodeName);//후위 순회 실행
    //결과 벡터 붙이기
    answer.push_back(first);
    answer.push_back(second);

    return answer;
}