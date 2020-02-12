#include <iostream>

using namespace std;

int go(int num) {
    if(num<2) return 0;
    for(int i=2;i*i<=num;i++) {
//        cout<<i<<" ";
        if(num%i==0) return 0;
    }
    return 1;
}
int main()
{
    freopen("input.txt","r",stdin);
    int num, sum=0;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
//        cout<<tmp<<'\n';
        sum=sum+go(tmp);
    }
    cout << sum << endl;
    return 0;
}
