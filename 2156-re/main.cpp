#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int dp[10001];
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
    dp[0]=v[0];
    dp[1]=v[0]+v[1];
    dp[2]=max(max(dp[1], dp[0]+v[2]), v[1]+v[2]);
    for(int i=3;i<tc;i++) {
        dp[i]=max(max(dp[i-1], dp[i-2]+v[i]), dp[i-3]+v[i-1]+v[i]);
    }
    cout << dp[tc-1] << '\n';
    return 0;
}
