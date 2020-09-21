#include <iostream>

using namespace std;

int dp[1001][11];
int div_num = 10007;

int main()
{
    int num;
    cin>>num;
    for(int i=0;i<10;i++) {
        dp[1][i] = 10-i;
    }
    for(int i=2;i<=num;i++) {
        for(int j=0;j<10;j++) {
            int sum = 0;
            for(int k=j;k<10;k++) {
                sum=sum+dp[i-1][k];
            }
            dp[i][j] = sum;
        }
    }

    cout << dp[num][0] << '\n';
    return 0;
}
