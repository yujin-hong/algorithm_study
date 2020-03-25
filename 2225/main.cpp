#include <iostream>

using namespace std;

int dp[201][201];
long long modnum = 1000000000;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<201;i++) {
        dp[1][i]=1;
    }
    for(int i=2;i<201;i++) {
        for(int j=0;j<201;j++) {
            int sum=0;
            for(int k=0;k<=j;k++) {
                sum=(long long)(sum+dp[i-1][k])%modnum;
            }
            dp[i][j]=sum;
        }
    }

    cout << dp[k][n] << '\n';
    return 0;
}
