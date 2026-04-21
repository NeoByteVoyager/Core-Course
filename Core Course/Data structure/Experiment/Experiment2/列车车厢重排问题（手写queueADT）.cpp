#include<bits/stdc++.h>
using namespace std;

template <typename T>
class MyQueue {
private:
    // 队列只需要单向链表
    struct Node {
        T val;
        Node* next;
        Node(T v) : val(v), next(nullptr) {}
    };

    Node* head; // 队头指针
    Node* tail; // 队尾指针
    int count;  // 记录元素个数

public:
    MyQueue() : head(nullptr), tail(nullptr), count(0) {}

    // 拷贝构造函数 
    MyQueue(const MyQueue& other) : head(nullptr), tail(nullptr), count(0) {
        Node* curr = other.head;
        while (curr != nullptr) {
            push(curr->val);
            curr = curr->next;
        }
    }

    // 赋值运算符重载
    MyQueue& operator=(const MyQueue& other) {
        if (this == &other) return *this;
        while (!empty()) pop(); 
        Node* curr = other.head;
        while (curr != nullptr) {
            push(curr->val);
            curr = curr->next;
        }
        return *this;
    }

    ~MyQueue() {
        while (!empty()) pop();
    }

    bool empty() const {
        return count == 0;
    }

    // 获取队头元素
    T front() const {
        return head->val;
    }

    // 获取队尾元素
    T back() const {
        return tail->val;
    }

    // 入队：加在单向链表的尾部
    void push(T x) {
        Node* newNode = new Node(x);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    // 出队：从单向链表的头部删除
    void pop() {
        if (empty()) return;
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr; // 如果删空了，尾指针也要置空
        }
        delete temp;
        count--;
    }
};


vector<int> seq;
vector<MyQueue<int>> qi;
int res = 0, cur = 1; 

void add(int x){
    int idx = -1, max_val = -1; 
    for(int i = 0; i < qi.size(); i++){
        if(!qi[i].empty() && qi[i].back() < x) {
            if(qi[i].back() > max_val){
                idx = i;
                max_val = qi[i].back();
            }
        }
        else if(qi[i].empty() && max_val == -1) idx = i;
    }
    
    if(idx == -1){ 
        res++; 
        MyQueue<int> q; 
        qi.push_back(q);
        qi[qi.size()-1].push(x); 
    }
    else{
         qi[idx].push(x); 
    }
    
    while(true){
        int flag = false;
        for(int i = 0; i < qi.size(); i++){
            if(!qi[i].empty() && qi[i].front() == cur){
                qi[i].pop();
                cur++;
                flag = true;
            }
        }
        if(!flag) break;
    }
}

int main(){
    int x; 
    while(cin >> x){
        seq.push_back(x);
    }
    for(int i = seq.size()-1; i >= 0; i--){
        add(seq[i]);
    }
    cout << res;
    return 0;
}
