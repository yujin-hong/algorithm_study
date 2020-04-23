#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[151][151];


int solution(int n, int m, int k) {
    for(int i=1;i<=k;i++) {
        dp[1][i]=1;
    }
    for(int i=2;i<151;i++) {
        for(int j=2;j<151;j++) {
            for(int p=j-k;p<j;p++) {
                if(p>0)
                    dp[i][j]=(long long)(dp[i][j]+(long long)dp[i-1][p]%1000000007)%1000000007;
            }
        }
    }
    long long answer;

    if(n%2==0) {
        cout<<dp[n/2][m/2]<<'\n';
        answer=(long long) ((long long)dp[n/2][m/2]%1000000007*(long long)dp[n/2][m/2]%1000000007)*2%1000000007;
    }
    else
        answer=(long long) ((long long)dp[n/2][m/2]%1000000007*(long long)dp[n/2+1][m/2]*2)%1000000007;

    return answer;
}

int main()
{
    cout << solution(3,8,4) << endl;
    return 0;
}
