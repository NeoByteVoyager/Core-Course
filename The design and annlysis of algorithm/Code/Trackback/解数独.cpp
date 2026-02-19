#include<bits/stdc++.h>
using namespace std;

    bool r[9][10];
    bool c[9][10];
    bool box[9][10];
    bool solved=false;
    int getIndex(int i,int j){
        return i/3*3+j/3;
    }
    void dfs(vector<vector<char>>&board,int p,int q){
    	cout << string(p, ' ') << "½øÈë(" << p << "," << q << ")" << endl;
        if(q==9){
            if(p==8){
                solved=true;
                return;
            } 
            else {
                dfs(board,p+1,0);
                return;
            }
        }
        if(isdigit(board[p][q])) {
            dfs(board,p,q+1);
            return;
        }
        for(int i=1;i<10;i++){
            int id=getIndex(p,q);
            if(r[p][i]||c[q][i]||box[id][i]) continue;
            r[p][i]=c[q][i]=true;
            board[p][q]='0'+i;
            box[id][i]=true;
            dfs(board,p,q+1);
            if(solved) continue;
            board[p][q]='.';
            box[id][i]=false;
            r[p][i]=c[q][i]=false;
        }
        cout << string(p, ' ') << "·µ»Ø(" << p << "," << q << ")" << endl;
    }
    void solveSudoku(vector<vector<char>>& board) {
    	
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int t=int(board[i][j]-'0');
                    r[i][t]=true;
                    c[j][t]=true;
                    box[getIndex(i,j)][t]=true;
                }
            }
        }
        dfs(board,0,0);
    }

int main(){
	vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}};
	solveSudoku(board);
	return 0;
} 
