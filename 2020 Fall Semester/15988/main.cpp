#include <iostream>

using namespace std;

long long div_num = 1000000009;
int ans[1000001];

int main()
{

    ans[1]=1;
    ans[2]=2;
    ans[3]=4;
    for(int i=4;i<=1000000;i++) {
        ans[i] = (ans[i-1]+ans[i-2]+ans[i-3])%div_num;
    }
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int n;
        cin>>n;
        cout<<ans[n]<<'\n';
    }
    return 0;
}
