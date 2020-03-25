#include <iostream>
#include <climits>

using namespace std;
int dp[100001];

int main()
{
    for(int i=1;i*i<=100000;i++) {
        dp[i*i]=1;
    }

    for(int i=1;i<=100000;i++) {
//        cout<<i<<" "<<dp[i]<<'\n';
        int nmax=INT_MAX;
        if(dp[i]==0) {
            for(int j=1;j*j<i;j++) {
//                cout<<j<<'\n';
//                cout<<dp[1]<<'\n';
//                cout<<dp[j*j]<<'\n';
//                cout<<dp[i-j*j]<<'\n';
                nmax=min(nmax, dp[j*j]+dp[i-j*j]);
            }
            dp[i]=nmax;
        }
    }
    int n;
    cin>>n;
    cout << dp[n] << '\n';
    return 0;
}
