#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int a[11][11];
int arr[11][11];

int check[6];

int main()
{
    int rightans=0;
    freopen("input.txt","r",stdin);
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            int tmp;
            cin>>tmp;
            a[i][j]=tmp;
        }
    }
    int nmin=INT_MAX;

    for(int start=5;start>0;start--) {
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            arr[i][j]=a[i][j];
        }
    }
    int tr=start;
    int ans=0;
    while(tr>0) {
//        cout<<"tr: "<<tr<<"\n";
        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                if(arr[i][j]==1) {
//                    cout<<"im here"<<'\n';
                    int fl=1;
                    for(int m=0;m<tr;m++) {
                        for(int n=0;n<tr;n++) {
                            if(arr[i+m][j+n]==0) {
                                fl=0;
                                break;
                            }
                        }
                        if(fl==0) break;
                    }
                    if(fl==1 && check[tr]<5) {
//                        cout<<tr<<'\n';
//                        cout<<check[tr]<<'\n';
                        check[tr]++;
                        ans++;
                        for(int m=0;m<tr;m++) {
                            for(int n=0;n<tr;n++) {
                                arr[i+m][j+n]=0;
                            }
                        }
                    }
                }
            }
        }
        tr--;
    }
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            if(arr[i][j]==1) {
                ans=-1;
                break;
            }
        }
        if(ans==-1) break;
    }
//    cout<<"ans: "<<ans<<'\n';
    if(ans!=-1 && ans<nmin) {
        rightans=1;
        nmin=ans;
    }
    }
    if(rightans==0) nmin=-1;
    cout << nmin << '\n';
    return 0;
}
