#include <iostream>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        int arr[2][100001];
        int ans[100001][2];
        cin>>tmp;
        for(int j=0;j<2;j++) {
            for(int k=0;k<tmp;k++) {
                int tp;
                cin>>tp;
                arr[j][k]=tp;
            }
        }
//        for(int j=0;j<2;j++) {
//            for(int k=0;k<tmp;k++) {
//                cout<<arr[j][k]<<" ";
//            }
//            cout<<'\n';
//        }
        ans[0][0]=arr[0][0];
        ans[0][1]=arr[1][0];
        ans[1][0]=arr[0][1]+arr[1][0];
        ans[1][1]=arr[0][0]+arr[1][1];
        for(int j=2;j<tmp;j++) {
            ans[j][0]=max(ans[j-1][1], ans[j-2][1])+arr[0][j];
            ans[j][1]=max(ans[j-1][0], ans[j-2][0])+arr[1][j];
        }
        for(int j=0;j<tmp;j++) {
            cout<<ans[j][0]<<" "<<ans[j][1]<<'\n';
        }
        cout<<max(ans[tmp-1][0], ans[tmp-1][1])<<'\n';
    }
    return 0;
}
