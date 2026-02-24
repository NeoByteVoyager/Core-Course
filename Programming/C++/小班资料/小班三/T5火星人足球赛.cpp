#include <bits/stdc++.h>
using namespace std;

struct RedEvent {
    string team;
    int player;
    int time;
    int type;  // 0 = 主队, 1 = 客队
};

int main() {
    string home, away;
    cin >> home >> away;

    int n;
    cin >> n;

    map<int,int> yellowH, yellowA;  // 每个球员黄牌数
    map<int,int> redH, redA;        // 是否已罚下

    vector<RedEvent> ans;

    while(n--) {
        int t, num;
        char team, card;
        cin >> t >> team >> num >> card;

        if(team == 'h') {
            // 主队
            if(redH[num]) continue;
            if(card == 'r') {
                redH[num] = 1;
                ans.push_back({home, num, t, 0});
            } else {
                // 黄牌
                if(yellowH[num] == 1) {
                    redH[num] = 1;
                    ans.push_back({home, num, t, 0});
                } else {
                    yellowH[num] = 1;
                }
            }
        } else {
            // 客队
            if(redA[num]) continue;
            if(card == 'r') {
                redA[num] = 1;
                ans.push_back({away, num, t, 1});
            } else {
                if(yellowA[num] == 1) {
                    redA[num] = 1;
                    ans.push_back({away, num, t, 1});
                } else {
                    yellowA[num] = 1;
                }
            }
        }
    }

    if(ans.empty()) {
        cout << "No Red Card";
        return 0;
    }

    sort(ans.begin(), ans.end(), [](auto &a, auto &b){
        if(a.time != b.time) return a.time < b.time;
        if(a.type != b.type) return a.type < b.type;
        return a.player > b.player; // 编号大的排前面
    });

    for(auto &e : ans) {
        cout << e.team << " " << e.player << " " << e.time << "\n";
    }

    return 0;
}

