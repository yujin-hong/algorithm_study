#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int dp[1001];

int main()
{
    // freopen("input.txt","r",stdin);
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    dp[0]=1;
    for(int i=1;i<tc;i++) {
        int fl=1;
        int nmax=1;
        for(int j=0;j<i;j++) {
            if(v[j]<v[i]) {
                fl=0;
                nmax=max(nmax, dp[j]);
            }
        }
        if(fl==0) dp[i]=nmax+1;
        else dp[i]=1;
    }
    int ans=dp[0];
    for(int i=1;i<tc;i++) {
        ans=max(dp[i], ans);
    }
    cout << ans << '\n';
    return 0;
}
