#include<bits/stdc++.h>
using namespace std;

// 定义节点结构
struct Node{
    int bound;      // 理论上界（最大可能割边数）
    int level;      // 当前正在做决定的顶点编号 (1 到 n)
    int current_val;// 当前实际割边数（辅助剪枝）
    vector<bool> x; // 当前解向量
    
    // 优先队列是大顶堆，bound大的先出队
    bool operator<(const Node& other) const {
        return bound < other.bound;
    }
};

int n, m;
vector<pair<int,int>> edges; // 存储所有边

// 计算上界函数 (核心剪枝逻辑)
// level: 当前已经决定了 1...level 的归属
int calBound(Node& u) {
    int potential_loss = 0;
    
    for(auto& e : edges){
        int p = e.first;
        int q = e.second;
        
        // 只有当条边的两个端点都已经做过决定(<= level)时，我们才能判断这条边是否"完蛋"了
        if(p <= u.level && q <= u.level){
            // 如果两端点都在同一个集合（同为0 或 同为1），这条边一定不是割边
            if(u.x[p] == u.x[q]){
                potential_loss++;
            }
        }
        // 如果有任一端点还没决定，我们乐观地假设它能成为割边，不计入损失
    }
    
    return m - potential_loss;
}

// 计算当前实际割边数 (用于更新最优解)
int getActualCut(Node &u){
    int res = 0;
    for(auto& e : edges){
        int p = e.first;
        int q = e.second;
        // 只有两端状态不同才算割边
        if(u.x[p] != u.x[q]){
            res++;
        }
    }
    return res;
}

int main(){

     ifstream fin("input.txt");
     ofstream fout("output.txt");
    
    
    if(!(fin >> n >> m)) return 0;
    
    for(int i = 0; i < m; i++){
        int u, v;
        fin >> u >> v;
        edges.push_back({u, v});
    }
     // --- 开始计时 ---
    clock_t start_time = clock();
    // 初始化根节点
    Node root;
    root.level = 0;
    root.current_val = 0;
    root.x.resize(n + 1, false); // 默认为0
    root.bound = m; // 初始上界为所有边
    
    priority_queue<Node> pq;
    pq.push(root);
    
    int best_res = -1;
    vector<bool> best_x;
    
    while(!pq.empty()){
        Node u = pq.top();
        pq.pop();
        
        // 剪枝：如果当前结点的上界不大于已知的最优解，没必要继续
        if(u.bound <= best_res) continue;
        
        // 到达叶子节点 (所有点都决定完了)
        if(u.level == n){
            int current_cut = getActualCut(u);
            if(current_cut > best_res){
                best_res = current_cut;
                best_x = u.x;
            }
            continue;
        }
        
        // 扩展子节点：进入下一层
        int next_lvl = u.level + 1;
        
        // 分支1：将顶点 next_lvl 放入集合 U (x=1)
        {
            Node v = u; // 复制父节点状态
            v.level = next_lvl;
            v.x[next_lvl] = true;
            v.bound = calBound(v); // 必须重新计算 bound
            
            // 只有当 理论上界 > 当前最优解 时才推入队列
            if(v.bound > best_res) {
                pq.push(v);
            }
        }
        
        // 分支2：将顶点 next_lvl 不放入集合 U (x=0)
        {
            Node v = u; 
            v.level = next_lvl;
            v.x[next_lvl] = false;
            v.bound = calBound(v); 
            
            if(v.bound > best_res) {
                pq.push(v);
            }
        }
    }
     // --- 结束计时 ---
    clock_t end_time = clock();
    
    cout << best_res << endl;
    for(int i = 1; i <= n; i++){
        cout << (best_x[i] ? 1 : 0) << (i == n ? "" : " ");
    }
    cout << endl;
    
    // 输出运行时间（毫秒）
    cout<<"n:"<<n<<" "<<"m:"<<m<<endl;
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
    cout << "Running Time: " << duration << " ms" << endl; 
    
    return 0;
}
