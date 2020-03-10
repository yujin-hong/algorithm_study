#include <iostream>

using namespace std;

int arr[100001][4];
int dpans[100001];

int dp(int n) {
    return ((long long)arr[n][1]+arr[n][2]+arr[n][3])%1000000009;
}
int main()
{
    int num;
    cin>>num;
    arr[1][1]=1;
    arr[2][2]=1;
    arr[3][1]=1;
    arr[3][2]=1;
    arr[3][3]=1;

    for(int i=4;i<=100000;i++) {
        for(int j=1;j<=3;j++) {
            int ans=0;
            for(int k=1;k<=3;k++) {
                if(k!=j) {
                    ans=(ans+arr[i-j][k]%1000000009)%1000000009;
                }
            }
//            cout<<i<<" "<<j<<" "<<ans<<'\n';
            arr[i][j]=ans;
        }
    }

    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        cout<<dp(tmp)<<'\n';
    }
    return 0;
}
