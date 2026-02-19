#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> board;
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

// 判断合法移动
bool valid(int x,int y){
    return x>=0 && x<m && y>=0 && y<n && board[x][y]==0;
}

// 计算下一步可走格子数（Warnsdorff 规则）
int countNext(int x,int y){
    int cnt=0;
    for(int i=0;i<8;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(valid(nx,ny)) cnt++;
    }
    return cnt;
}

// Warnsdorff DFS
bool dfs(int x,int y,int step){
    board[x][y] = step;
    if(step==m*n){
        // 回到起点检查是否可连
        for(int i=0;i<8;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx==0 && ny==0) return true;
        }
        board[x][y] = 0;
        return false;
    }
    vector<pair<int,pair<int,int>>> nextSteps;
    for(int i=0;i<8;i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(valid(nx,ny)){
            nextSteps.push_back({countNext(nx,ny),{nx,ny}});
        }
    }
    sort(nextSteps.begin(), nextSteps.end());
    for(auto &p: nextSteps){
        if(dfs(p.second.first, p.second.second, step+1)) return true;
    }
    board[x][y] = 0;
    return false;
}

int main(){
    ifstream fin("input.txt");
    fin >> m >> n;
    fin.close();

    board.assign(m, vector<int>(n,0));
    dfs(0,0,1);

    ofstream fout("output.txt");
    // 输出坐标顺序
    vector<pair<int,int>> pos(m*n+1);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            pos[board[i][j]] = {i,j};
        }
    }
    for(int i=1;i<=m*n;i++){
        fout << "(" << pos[i].first << "," << pos[i].second << ")";
    }
    fout << endl;

    // 输出棋盘步数矩阵
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            fout << board[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();
    return 0;
}

