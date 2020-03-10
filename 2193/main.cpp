#include <iostream>

using namespace std;

int arr[91][2];

int main()
{
    int tmp;
    cin>>tmp;
    arr[1][1]=1;
    arr[2][0]=1;
    for(int i=3;i<=90;i++) {
        arr[i][0]=arr[i-1][0]+arr[i-1][1];
        arr[i][1]=arr[i-1][0];
    }
    cout<<arr[tmp][0]+arr[tmp][1]<<'\n';

//    cout << "Hello world!" << endl;
    return 0;
}
