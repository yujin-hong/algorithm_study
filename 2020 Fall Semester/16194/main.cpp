#include <iostream>
#include <climits>

using namespace std;

int card[1001];
int dp[1001];

int main()
{
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        cin>>card[i];
    }
    dp[1] = card[0];
    for(int i=2;i<=num;i++) {
        int ans = card[i-1];
        for(int j=1;j<i;j++) {
            int tmp = dp[j]+card[i-j-1];
            if(tmp<ans) ans = tmp;
        }
        dp[i] = ans;
//        cout<<i<<' '<<ans<<'\n';
    }
    cout << dp[num] << '\n';
    return 0;
}
