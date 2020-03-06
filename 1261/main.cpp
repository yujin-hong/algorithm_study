#include <iostream>
#include <deque>

using namespace std;

int a[101][101];
int visited[101][101];
deque<pair<int, int>> q;
int n,m;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs() {
    while(!q.empty()) {
        pair<int, int> fir = q.front();
        int fx = fir.first;
        int fy = fir.second;
//        cout<<fx<<" "<<fy<<" "<<visited[fx][fy]<<'\n';
        if(fx==m-1 && fy==n-1) break;
        q.pop_front();
        for(int i=0;i<4;i++) {
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n) {
                if(visited[nx][ny]==0) {
                    visited[nx][ny]=visited[fx][fy]+a[nx][ny];
                    if(a[nx][ny]==0) {
                        q.push_front(make_pair(nx, ny));
                    } else {
                        q.push_back(make_pair(nx, ny));
                    }
                }
            }
        }
    }

}
int main()
{
    freopen("input.txt","r",stdin);

    cin>>n>>m;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            char chtmp;
            cin>>chtmp;
            int tmp = (int)chtmp-48;
            a[i][j]=tmp;
        }
    }
//    for(int i=0;i<m;i++) {
//        for(int j=0;j<n;j++) {
//            cout<<a[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    visited[0][0]=1;
    q.push_front(make_pair(0,0));
    bfs();
    cout<<visited[m-1][n-1]-1;

    return 0;
}
