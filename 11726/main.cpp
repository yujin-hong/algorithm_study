#include <iostream>

using namespace std;
int arr[1001];

int go(int num) {
    for(int i=3;i<=1000;i++) {
        arr[i]=(arr[i-1]%10007+2*arr[i-2]%10007)%10007;
    }
    return arr[num];
}
int main()
{
    int n;
    cin>>n;
    arr[1]=1;
    arr[2]=3;
    cout<<go(n)<<'\n';
//    cout << "Hello world!" << endl;
    return 0;
}
