#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int dp[1001];
vector<int> dpv[1001];

int main()
{
    freopen("input.txt","r",stdin);
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    dp[0]=1;
    dpv[0].push_back(v[0]);
    for(int i=1;i<tc;i++) {
        int fl=1;
        int nmax=0;
        int maxind;
        for(int j=0;j<i;j++) {
            if(v[j]<v[i]) {
                fl=0;
                if(dp[j]>nmax) {
                    nmax=dp[j];
                    maxind=j;
                }
            }
        }
        if(fl==0) {
            dp[i]=nmax+1;
            dpv[i]=dpv[maxind];
            dpv[i].push_back(v[i]);
        } else {
            dp[i]=1;
            dpv[i].push_back(v[i]);
        }
    }
    int ans=0;
    int ansind;
    for(int i=0;i<tc;i++) {
        if(dp[i]>ans) {
            ans=dp[i];
            ansind=i;
        }
    }
    cout << ans << '\n';
    for(int i=0;i<dpv[ansind].size();i++) {
        cout<<dpv[ansind][i]<<" ";
    }
    return 0;
}
