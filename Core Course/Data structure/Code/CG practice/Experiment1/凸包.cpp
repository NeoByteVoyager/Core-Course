#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 定义平面点结构体
struct Point {
    long long x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

// 全局变量，用于存储凸包内部点 X 的坐标
double X_x = 0.0, X_y = 0.0;

// 计算叉积 (p2-p1) x (p3-p1)
// 返回值 > 0: 左转 (逆时针夹角 < 180)
// 返回值 < 0: 右转 (逆时针夹角 > 180)
// 返回值 = 0: 共线
long long crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

// 计算点到内部点 X 的距离平方
double distSquare(Point p, double cx, double cy) {
    return (p.x - cx) * (p.x - cx) + (p.y - cy) * (p.y - cy);
}

// 极角排序的比较函数
bool comparePolar(const Point& a, const Point& b) {
    // 使用 atan2 计算相对于中心点 X 的极角 [-pi, pi]
    double angleA = atan2(a.y - X_y, a.x - X_x);
    double angleB = atan2(b.y - X_y, b.x - X_x);
    
    // 如果角度不同，按极角从小到大排
    if (abs(angleA - angleB) > 1e-9) {
        return angleA < angleB;
    }
    // 如果角度相同（共射线），按距离从小到大排
    return distSquare(a, X_x, X_y) < distSquare(b, X_x, X_y);
}

// 输出要求的字典序比较函数（按 x 升序，x 相同按 y 升序）
bool compareOutput(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

// 双向循环链表的节点定义
struct Node {
    Point p;
    Node* next;
    Node* prev;
    Node(Point pt) : p(pt), next(nullptr), prev(nullptr) {}
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    // 预处理：去重，防止相同坐标的点干扰判断
    sort(pts.begin(), pts.end(), compareOutput);
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    n = pts.size();

    // ==========================================
    // 步骤 1) 处理退化情况
    // ==========================================
    if (n < 3) {
        for (const auto& p : pts) cout << p.x << " " << p.y << endl;
        return 0;
    }

    // 判断是否所有点都共线
    bool all_collinear = true;
    int non_collinear_idx = -1;
    for (int i = 2; i < n; ++i) {
        if (crossProduct(pts[0], pts[1], pts[i]) != 0) {
            all_collinear = false;
            non_collinear_idx = i; // 找到了不共线的第三个点
            break;
        }
    }

    if (all_collinear) {
        // 全共线，直接输出最短直线的两个端点（因为之前排序过，头尾就是端点）
        cout << pts.front().x << " " << pts.front().y << endl;
        cout << pts.back().x << " " << pts.back().y << endl;
        return 0;
    }

    // 补充说明 1 & 2：计算不共线三点的质心，作为内部点 X
    X_x = (pts[0].x + pts[1].x + pts[non_collinear_idx].x) / 3.0;
    X_y = (pts[0].y + pts[1].y + pts[non_collinear_idx].y) / 3.0;

    // ==========================================
    // 步骤 2) 按极角排序并构建双向循环链表
    // ==========================================
    sort(pts.begin(), pts.end(), comparePolar);

    Node* head = new Node(pts[0]);
    Node* curr = head;
    Node* min_y_node = head; // 记录 y 最小的点（起点 p）

    for (int i = 1; i < n; ++i) {
        Node* newNode = new Node(pts[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
        
        // 寻找 y 坐标最小的点 (y相同找x最小)
        if (pts[i].y < min_y_node->p.y || (pts[i].y == min_y_node->p.y && pts[i].x < min_y_node->p.x)) {
            min_y_node = newNode;
        }
    }
    // 闭合成循环链表
    curr->next = head;
    head->prev = curr;
    
    // ==========================================
    // 步骤 3) 删除非极点的点
    // ==========================================
    Node* p = min_y_node;
    Node* x = p;
    Node* rx = x->next;

    // 只要 rx 还没有绕行完一整圈回到 p 就继续
    while (rx != p) {
        Node* rrx = rx->next;
        // 如果 x, rx, rrx 逆时针夹角 <= 180 度 (即叉积 <= 0，发生右转或共线)
        if (crossProduct(x->p, rx->p, rrx->p) <= 0) {
            // 从链表中删除 rx
            rx->prev->next = rx->next;
            rx->next->prev = rx->prev;
            Node* toDelete = rx;
            
            rx = x;
            x = rx->prev;
            delete toDelete;
            
            // 边缘情况处理：如果不断回退导致 rx 回到了起点 p，我们强制前进一步以防止死循环终止
            if (rx == p) {
                x = rx;
                rx = rx->next;
            }
        } else {
            // 发生左转，继续向前推进
            x = rx;
            rx = rrx;
        }
    }

    // 收集形成凸包的所有极点
    vector<Point> hull;
    Node* temp = p;
    do {
        hull.push_back(temp->p);
        temp = temp->next;
    } while (temp != p);

    // ==========================================
    // 输出部分
    // ==========================================
    sort(hull.begin(), hull.end(), compareOutput);
    for (const auto& pt : hull) {
        cout << pt.x << " " << pt.y << endl;
    }

    return 0;
}
