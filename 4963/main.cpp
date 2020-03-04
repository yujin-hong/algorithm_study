#include <iostream>
#include <cstring>

using namespace std;

int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};
int visited[51][51];
int arr[51][51];

void dfs(int x, int y) {
    visited[x][y]=1;
    for(int i=0;i<8;i++) {
        int tmpx = x+dx[i];
        int tmpy = y+dy[i];
        if(arr[tmpx][tmpy]==1 && visited[tmpx][tmpy]==0) {
            dfs(tmpx, tmpy);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    while(1) {
        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr));
        int ans=0;
        int a, b;
        cin>>a>>b;
        if(a==0 && b==0) break;
        for(int i=0;i<b;i++) {
            for(int j=0;j<a;j++) {
                int tmp;
                cin>>tmp;
                arr[i][j]=tmp;
            }
        }
//        for(int i=0;i<a;i++) {
//            for(int j=0;j<b;j++) {
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<'\n';
//        }
        for(int i=0;i<b;i++) {
            for(int j=0;j<a;j++) {
                if(arr[i][j]==1 && visited[i][j]==0) {
                    dfs(i,j);
                    ans=ans+1;
                }
            }
        }
        cout<<ans<<'\n';
    }
//    cout << "Hello world!" << endl;
    return 0;
}
