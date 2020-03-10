#include <iostream>

using namespace std;
int arr[101][11];

int main()
{
    int ans=0;
    for(int i=1;i<10;i++) {
        arr[1][i]=1;
    }
    for(int i=2;i<=100;i++) {
        arr[i][0]=arr[i-1][1];
        for(int j=1;j<=8;j++) {
            arr[i][j]=((long long)arr[i-1][j-1]+arr[i-1][j+1])%1000000000;
        }
        arr[i][9]=arr[i-1][8];
    }
    int tmp;
    cin>>tmp;
    for(int i=0;i<10;i++) {
        ans=((long long)ans+arr[tmp][i])%1000000000;
    }
    cout<<ans;

//    cout << "Hello world!" << endl;
    return 0;
}
