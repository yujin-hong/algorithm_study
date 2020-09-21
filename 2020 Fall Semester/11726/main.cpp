#include <iostream>

using namespace std;

int main()
{
    int ans[1001];
    int DIV_NUM = 10007;

    int n;
    cin>>n;
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<=1000;i++) {
        ans[i]=(ans[i-1]+ans[i-2])%DIV_NUM;
    }
    cout<<ans[n]<<'\n';

//    cout << "Hello world!" << endl;
    return 0;
}
