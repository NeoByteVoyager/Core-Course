#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int need;  // 需要找零的金额（美分）
    int p, n, d, q;  // pennies, nickels, dimes, quarters 的数量
    
    // 循环读取输入，直到文件结束
    while (cin >> need >> p >> n >> d >> q) {
        // 初始化最优解为"无解"
        int best_pc = -1, best_nc = -1, best_dc = -1, best_qc = -1;
        int min_coins = 2100000000;  // 设置一个很大的初始值
        
        // 枚举 quarters 的可能数量，从 0 到最多可用的数量
        int max_qc = min(q, need / 25);
        for (int qc = 0; qc <= max_qc; ++qc) {
            // 使用 qc 个 quarters 后的剩余金额
            int after_q = need - qc * 25;
            
            // 枚举 dimes 的可能数量
            int max_dc = min(d, after_q / 10);
            for (int dc = 0; dc <= max_dc; ++dc) {
                // 使用 qc 个 quarters 和 dc 个 dimes 后的剩余金额
                int after_d = after_q - dc * 10;
                
                // 计算可以使用的 nickels 数量（尽可能多用）
                int max_nc = min(n, after_d / 5);
                int nc = max_nc;
                int after_n = after_d - nc * 5;
                
                // 检查 pennies 是否足够
                if (after_n <= p) {
                    // 找到可行解
                    int pc = after_n;
                    int total_coins = qc + dc + nc + pc;
                    
                    // 更新最优解（总硬币数最少）
                    if (total_coins < min_coins) {
                        min_coins = total_coins;
                        best_pc = pc;
                        best_nc = nc;
                        best_dc = dc;
                        best_qc = qc;
                    }
                }
            }
        }
        
        // 输出结果
        if (best_pc != -1) {
            cout << best_pc << " " << best_nc << " " << best_dc << " " << best_qc << endl;
        } else {
            cout << "Not enough change" << endl;
        }
    }
    
    return 0;
}
