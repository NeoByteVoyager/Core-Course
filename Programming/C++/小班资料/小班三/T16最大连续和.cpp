#include <iostream>

using namespace std;
void getMaxSum(int a[], int n, int &Left, int &Right);

int main()
{
    int n;
    cin>>n;

    int *p=new int[n];

    for(int i=0; i<n; i++)
        cin>>p[i];

    int Left, Right;
    getMaxSum(p, n, Left, Right);

    cout<<Left<<" "<<Right<<endl;
    delete[] p;

    return 0;
}

void getMaxSum(int a[], int n, int &Left, int &Right)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int tempStart = 0;
    Left = 0;
    Right = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum > maxSum) {
            maxSum = sum;
            Left = tempStart;
            Right = i;
        }
        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;
        }
    }
}

