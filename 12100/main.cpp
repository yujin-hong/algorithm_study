#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int arr[21][21];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int nmax=0;

void go(int tarr[21][21], int n, int dep) {
//    cout<<"==================="<<dep<<'\n';
    if(dep==5) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(tarr[i][j]>nmax) nmax=tarr[i][j];
            }
        }
        return;
    }
    for(int k=0;k<4;k++) {
        int arr[21][21];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                arr[i][j]=tarr[i][j];
            }
        }
//        int starti, startj, endi, endj;
        int fl=0;
        if(k==0) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(arr[j][i]!=0) {
                        int tmp=arr[j][i];
//                        cout<<"here"<<i<<" "<<j<<" "<<tmp<<'\n';
                        arr[j][i]=0;
                        int tx=j, ty=i;
    //                    cout<<"tx: "<<tx<<" "<<ty<<'\n';
                        while(tx>=0 && ty>=0 && tx<n && ty<n && arr[tx][ty]==0) {
//                            cout<<"while tx: "<<tx<<" "<<ty<<'\n';
                            tx=tx+dx[k];
                            ty=ty+dy[k];
    //                        cout<<tx<<" "<<ty<<'\n';
                        }
                        if(tx>=0 && ty>=0 && tx<n && ty<n && arr[tx][ty]==tmp && fl==0) {
                            arr[tx][ty]=tmp*2;
                            fl=1;
                        } else {
                            arr[tx-dx[k]][ty-dy[k]]=tmp;
                            fl=0;
                        }
                    }
                }
            }
        } else if (k==3) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(arr[i][j]!=0) {
                        int tmp=arr[i][j];
//                        cout<<"here"<<i<<" "<<j<<" "<<tmp<<'\n';
                        arr[i][j]=0;
                        int tx=i, ty=j;
    //                    cout<<"tx: "<<tx<<" "<<ty<<'\n';
                        while(tx>=0 && ty>=0 && tx<n && ty<n && arr[tx][ty]==0) {
//                            cout<<"while tx: "<<tx<<" "<<ty<<'\n';
                            tx=tx+dx[k];
                            ty=ty+dy[k];
    //                        cout<<tx<<" "<<ty<<'\n';
                        }
                        if(tx>=0 && ty>=0 && tx<n && ty<n && arr[tx][ty]==tmp && fl==0) {
                            arr[tx][ty]=tmp*2;
                            fl=1;
                        } else {
                            arr[tx-dx[k]][ty-dy[k]]=tmp;
                            fl=0;
                        }
                    }
                }
            }
        } else if(k==2) {
            for(int i=n-1;i>=0;i--) {
                for(int j=n-1;j>=0;j--) {
                    if(arr[j][i]!=0) {
                        int tmp=arr[j][i];
//                        cout<<"here"<<i<<" "<<j<<" "<<tmp<<'\n';
                        arr[j][i]=0;
                        int tx=j, ty=i;
    //                    cout<<"tx: "<<tx<<" "<<ty<<'\n';
                        while(tx>=0 && ty>=0 && tx<n && ty<n && arr[tx][ty]==0) {
//                            cout<<"while tx: "<<tx<<" "<<ty<<'\n';
                            tx=tx+dx[k];
                            ty=ty+dy[k];
    //                        cout<<tx<<" "<<ty<<'\n';
                        }
                        if(tx>=0 && ty>=0 && tx<n && ty<n && arr[tx][ty]==tmp && fl==0) {
                            arr[tx][ty]=tmp*2;
                            fl=1;
                        } else {
                            arr[tx-dx[k]][ty-dy[k]]=tmp;
                            fl=0;
                        }
                    }
                }
            }
        } else {
            for(int i=n-1;i>=0;i--) {
                for(int j=n-1;j>=0;j--) {
                    if(arr[i][j]!=0) {
    //                    cout<<"here"<<i<<" "<<j<<'\n';
                        int tmp=arr[i][j];
                        arr[i][j]=0;
                        int tx=i, ty=j;
    //                    cout<<"tx: "<<tx<<" "<<ty<<'\n';
                        while(tx>=0 && ty>=0 && tx<n && ty<n && arr[tx][ty]==0) {
    //                        cout<<"while tx: "<<tx<<" "<<ty<<'\n';
                            tx=tx+dx[k];
                            ty=ty+dy[k];
    //                        cout<<tx<<" "<<ty<<'\n';
                        }
                        if(tx>=0 && ty>=0 && tx<n && ty<n && arr[tx][ty]==tmp && fl==0) {
                            arr[tx][ty]=tmp*2;
                            fl=1;
                        } else {
                            arr[tx-dx[k]][ty-dy[k]]=tmp;
                            fl=0;
                        }
                    }
                }
            }
        }

//        for(int i=0;i<n;i++) {
//            for(int j=0;j<n;j++) {
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<'\n';
//        }
//        cout<<"============"<<'\n';
        go(arr, n, dep+1);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int tmp;
            cin>>tmp;
            arr[i][j]=tmp;
        }
    }
//    cout<<n<<'\n';
    go(arr, n, 0);
    cout<<nmax<<'\n';
//    cout << "Hello world!" << endl;
    return 0;
}
