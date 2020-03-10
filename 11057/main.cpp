#include <iostream>

using namespace std;
int arr[1001][11];

int main()
{
    int ans=0;
    for(int i=0;i<10;i++) {
        arr[1][i]=1;
    }
    for(int i=2;i<=1000;i++) {
        for(int j=0;j<10;j++) {
            int ans=0;
            for(int k=0;k<=j;k++) {
                ans=((long long) ans+arr[i-1][k])%10007;
            }
            arr[i][j]=ans;
        }
    }
    int tmp;
    cin>>tmp;
    for(int i=0;i<10;i++) {
        ans=((long long)ans+arr[tmp][i])%10007;
    }
    cout<<ans;

//    cout << "Hello world!" << endl;
    return 0;
}
