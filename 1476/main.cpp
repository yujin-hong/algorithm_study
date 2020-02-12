#include <iostream>

using namespace std;

int main()
{
    long long ans;

//    freopen("input.txt","r",stdin);
    int e, s, m;
    int num=0;
    cin>>e>>s>>m;
    while(1) {
        ans=28*num+s;
        if((ans-1)%15==(e-1) && (ans-1)%19==(m-1)) {
            cout<<ans<<'\n';
            break;
        } else {
            num++;
        }
    }

    return 0;
}
