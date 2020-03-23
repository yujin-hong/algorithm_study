#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;
int dp[100001];

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

    dp[0]=v[0];

    for(int i=1;i<num;i++) {
        dp[i]=max(v[i], dp[i-1]+v[i]);
    }
    int ans=INT_MIN;

    for(int i=0;i<num;i++) {
        if(dp[i]>ans) ans=dp[i];
    }
    cout << ans << '\n';
    return 0;
}
