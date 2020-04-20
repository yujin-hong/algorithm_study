#include <iostream>

using namespace std;
int arr[51][51];

int dx[4]={0,-1, 0, 1};
int dy[4]={-1, 0, 1, 0};
int ans=1;
    int n,m;

void dfs(int sx, int sy, int d, int c) {
//    cout<<sx<<" "<<sy<<" "<<d<<" "<<c<<'\n';
    if(c>=4) {
//        cout<<"holy shit"<<'\n';
        int tmp;
        if(d+1==4) tmp=0;
        else tmp=d+1;
        int tx=sx-dx[tmp];
        int ty=sy-dy[tmp];
//        cout<<tx<<" "<<ty<<'\n';
        if(tx>=0 && tx<n && ty>=0 && ty<m) {
//            cout<<"not hre?"<<'\n';
            if(arr[tx][ty]==2 || arr[tx][ty]==0) {
//                cout<<"222?"<<'\n';
                dfs(tx, ty, d, 0);
            }
        }
        return;
    }
    int tx=sx+dx[d];
    int ty=sy+dy[d];
//    cout<<"============"<<tx<<" "<<ty<<" "<<arr[tx][ty]<<'\n';
    int tmp;
    if(d==0) tmp=3;
    else tmp=d-1;
    if(tx>=0 && tx<n && ty>=0 && ty<m && arr[tx][ty]==0) {
//        cout<<tx<<" "<<ty<<'\n';
        arr[tx][ty]=2;
        ans++;
        dfs(tx, ty, tmp, 0);
    } else {
        dfs(sx, sy, tmp, c+1);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    int sx, sy, d;
    cin>>sx>>sy>>d;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    arr[sx][sy]=2;
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    dfs(sx, sy, d, 0);
    cout<<ans<<'\n';
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    return 0;
}
