#include <iostream>

using namespace std;
int arr[1000001];
long long n=1000000009;

int dp(int num) {
    if(arr[num]>0) return arr[num];
    arr[num]=(dp(num-1)%n+dp(num-2)%n+dp(num-3)%n)%n;
    return arr[num];
}
int main()
{
    int num;
    cin>>num;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        cout<<dp(tmp)<<'\n';
    }
//    cout << "Hello world!" << endl;
    return 0;
}
