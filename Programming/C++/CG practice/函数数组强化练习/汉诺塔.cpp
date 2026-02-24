#include <iostream>

using namespace std;

void han(int n, char Fr, char To, char Mid);

int step=
1
;

int main()

{
    int n;
    cin >> n;
    han(n, 'A', 'C', 'B');
    return 0;

}
void han(int n, char Fr, char To, char Mid)

{
    if (n == 1)
       cout<<step++<<":move"<<n<<"# from "<<Fr<<" to "<<To<<endl;       /* Remark1 */
    else

    {
	han(n-1,Fr,Mid,To);         
	cout<<step++<<":move"<<n<<"# from "<<Fr<<" to "<<To<<endl;    
	  /* Remark2 */        
	han(n-1,Mid,To,Fr);

      }

}


