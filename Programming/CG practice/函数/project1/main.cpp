# include "yang.h"
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        PrintBlank(n-i);      // 打印前导空格
        PrintCombine(i);      // 打印第i行的系数
        printf("\n");         // 换行
    }
    return 0;
}

