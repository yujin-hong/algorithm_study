#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int arr[101][101];
int visited[101][101];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

int ans=INT_MAX;
int n,m;

void dfs(int x, int y, int len) {
//    cout<<x<<" "<<y<<" "<<len<<'\n';
    visited[x][y]=1;
    if(x<0 || y<0 || x>=n || y>=m) return;
    if(x==n-1 && y==m-1) {
        if(len<ans) ans=len;
        return;
    }
    for(int i=0;i<4;i++) {
        int tmpx = x+dx[i];
        int tmpy = y+dy[i];
        if(arr[tmpx][tmpy]==1 && visited[tmpx][tmpy]==0) {
            dfs(tmpx, tmpy, len+1);
            visited[tmpx][tmpy]=0;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char chtmp;
            cin>>chtmp;
            int tmp=(int)chtmp-48;
            arr[i][j]=tmp;
        }
    }
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    dfs(0, 0, 1);
    cout<<ans<<'\n';

    return 0;
}
