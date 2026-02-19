#include <iostream>        // C++ 标准输入输出
#include <iomanip>         // 格式化：setw / setfill
using namespace std;

int main() {
    int a,b,c;             // 开始：时 分 秒
    int d,e,f;             // 结束：时 分 秒

    /* 1. 读入，冒号当分隔符 */
    scanf("%d:%d:%d %d:%d:%d",&a,&b,&c,&d,&e,&f);

    /* 2. 全部折成秒，避免借位 */
    int startSec = a*3600 + b*60 + c;
    int endSec   = d*3600 + e*60 + f;
    int diffSec  = endSec - startSec;   // 净训练秒数
	/* 3. 秒 → 时、分、秒 */
	int h = diffSec / 3600;            // 整除得小时
	int m = (diffSec % 3600) / 60;     // 剩下来再除60得分钟
	int s = diffSec % 60;              // 最后余数是秒
	/* 4. 输出：分、秒不足两位左补0 */
	cout << h << ':'                    // 小时无需补0
	     << setw(2) << setfill('0') << m << ':'
	     << setw(2) << setfill('0') << s << '\n';
	
	return 0;
}

