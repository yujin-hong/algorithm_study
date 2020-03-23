#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int dp[1001];

int main()
{
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    dp[0]=1;
    for(int i=1;i<num;i++) {
        int nmax=1;
        for(int j=0;j<i;j++) {
            if(v[j]>v[i]) {
                if(dp[j]+1>nmax) nmax=dp[j]+1;
            }
        }
        dp[i]=nmax;
    }
    int ans=0;
    for(int i=0;i<num;i++) {
        if(dp[i]>ans) ans=dp[i];
    }
    cout << ans << '\n';
    return 0;
}
