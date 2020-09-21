#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int visited[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
    int n,m;

int bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    int step = 0;
    while(!q.empty()) {
        int qsize = q.size();
        step++;
        for(int j=0;j<qsize;j++) {
            pair<int, int> top = q.front();
            int tx = top.first;
            int ty = top.second;
            if(tx == n-1 && ty == m-1) return step;
            q.pop();
            for(int i=0;i<4;i++) {
                int px = tx+dx[i];
                int py = ty+dy[i];
                if(arr[px][py]==1 && visited[px][py]==0) {
                    q.push(make_pair(px, py));
                    visited[px][py]=1;
                }
            }
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char c;
            cin>>c;
            arr[i][j]=c-48;
        }
    }

    cout<<bfs(0,0)<<'\n';

//    cout << "Hello world!" << endl;
    return 0;
}
