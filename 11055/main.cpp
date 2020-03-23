#include <iostream>
#include <vector>

using namespace std;

int dp[1001];
vector<int> v;

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    dp[0]=v[0];
    for(int i=1;i<n;i++) {
        int nmax=v[i];
        for(int j=0;j<i;j++) {
            if(v[j]<v[i]) {
                if(dp[j]+v[i]>nmax) nmax=dp[j]+v[i];
            }
        }
        dp[i]=nmax;
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        if(dp[i]>ans) ans=dp[i];
    }
    cout<<ans<<'\n';
    return 0;
}
