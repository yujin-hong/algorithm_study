#include <iostream>
#include <cstring>
using namespace std;

int arr[101][101];
int check[101][101];
int hor[101];
int ver[101];
int main()
{
    freopen("input.txt","r",stdin);
    int a, b;
    cin>>a>>b;
    int ans=a*2;
    for(int i=0;i<a;i++) {
        for(int j=0;j<a;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<a;i++) {
        int num=1;
        for(int j=1;j<a;j++) {
            if(arr[i][j]==arr[i][j-1]) {
                num++;
            } else if(arr[i][j]==arr[i][j-1]+1) {
                if(num>=b) {
                    for(int k=1;k<=b;k++) {
                        check[i][j-k]=1;
                    }
                    num=1;
                } else {
                    hor[i]=1;
                    break;
                }
            } else if(arr[i][j]==arr[i][j-1]-1) {
                num=1;
            } else {
                hor[i]=1;
                break;
            }
        }
        if(hor[i]==0) {
            num=1;
            for(int j=a-1;j>0;j--) {
                if(arr[i][j-1]==arr[i][j]) {
                    num++;
                } else if(arr[i][j-1]==arr[i][j]+1) {
                    if(num>=b) {
                        for(int k=0;k<b;k++) {
                            if(check[i][j+k]==0) {
                                check[i][j+k]=1;
                            } else {
                                hor[i]=1;
                                break;
                            }
                        }
                        if(hor[i]==1) break;
                        num=1;
                    } else {
                        hor[i]=1;
                        break;
                    }
                } else if(arr[i][j-1]==arr[i][j]-1) {
                    num=1;
                } else {
                    hor[i]=1;
                    break;
                }
            }
        }
    }
    memset(check, 0, sizeof(check));
    for(int i=0;i<a;i++) {
        int num=1;
        for(int j=1;j<a;j++) {
            if(arr[j][i]==arr[j-1][i]) {
                num++;
            } else if(arr[j][i]==arr[j-1][i]+1) {
                if(num>=b) {
                    for(int k=1;k<=b;k++) {
                        check[j-k][i]=1;
                    }
                    num=1;
                } else {
                    ver[i]=1;
                    break;
                }
            } else if(arr[j][i]==arr[j-1][i]-1) {
                num=1;
            } else {
                ver[i]=1;
                break;
            }
        }
        if(ver[i]==0) {
            num=1;
            for(int j=a-1;j>0;j--) {
                if(arr[j-1][i]==arr[j][i]) {
                    num++;
                } else if(arr[j-1][i]==arr[j][i]+1) {
                    if(num>=b) {
                        for(int k=0;k<b;k++) {
                            if(check[j+k][i]==0) {
                                check[j+k][i]=1;
                            } else {
                                ver[i]=1;
                                break;
                            }
                        }
                        if(ver[i]==1) break;
                        num=1;
                    } else {
                        ver[i]=1;
                        break;
                    }
                } else if(arr[j-1][i]==arr[j][i]-1) {
                    num=1;
                } else {
                    ver[i]=1;
                    break;
                }
            }

        }
    }
//    for(int i=0;i<a;i++) {
//        cout<<i<<' '<<hor[i]<<'\n';
////        ans=ans-hor[i];
//    }
    for(int i=0;i<a;i++) {
//        cout<<i<<' '<<ver[i]<<'\n';
        ans=ans-hor[i]-ver[i];
    }
    cout << ans << '\n';
    return 0;
}
