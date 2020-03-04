#include <iostream>
#include <cstring>
#include <climits>
#include <queue>

using namespace std;

int arr[101][101];
int visited[101][101];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

int ans=INT_MAX;
int n,m;

queue<pair<int, int>> q;

int bfs(int x, int y) {
    visited[x][y]=1;
    q.push(make_pair(x, y));
    int len=0;
    while(!q.empty()) {
        int qsize = q.size();
        for(int j=0;j<qsize;j++) {
            pair<int, int> tmp = q.front();
            q.pop();
//            cout<<len<<" ";
            for(int i=0;i<4;i++) {
                int tmpx = tmp.first+dx[i];
                int tmpy = tmp.second+dy[i];
                if(tmp.first==n-1 && tmp.second==m-1) return len+1;
                if(tmpx<0 || tmpy<0 || tmpx>=n || tmpy>=m) continue;
                if(visited[tmpx][tmpy]==0 && arr[tmpx][tmpy]==1) {
                    visited[tmpx][tmpy]=1;
                    q.push(make_pair(tmpx, tmpy));
                }
            }
        }
        len++;

    }
    return len;
//    cout<<"llen: "<<len<<'\n';
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
    cout<<bfs(0, 0)<<'\n';
//    cout<<ans<<'\n';

    return 0;
}
