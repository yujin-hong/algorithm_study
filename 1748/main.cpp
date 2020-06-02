#include <iostream>

using namespace std;

int main()
{
    int num;
    long long ans=0;
    cin>>num;
    int dig = 1;
    int tmp=1;
    while(num/dig>=10) {
//        cout<<num<<' '<<dig<<' '<<num/dig<<'\n';
        ans=ans+tmp*dig*9;
        dig=dig*10;
//        cout<<"ans:"<<ans<<'\n';
        tmp++;
    }
//    cout<<ans<<'\n';
//        cout<<num<<' '<<dig<<' '<<'\n';
    ans=ans+(num-dig+1)*tmp;
    cout << ans << '\n';
    return 0;
}
