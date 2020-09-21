#include <iostream>
#include <queue>

using namespace std;
int arr[1001][1001];
int visited[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
int step = -1;
int n,m;

bool check(int x, int y) {
    return (x>=0 && x<m && y>=0 && y<n);
}
void bfs() {
    while(!q.empty()){
        step++;
        int qsize = q.size();
        for(int j=0;j<qsize;j++) {
            pair<int, int> top = q.front();
            int tx = top.first;
            int ty = top.second;
//            cout<<tx<<' '<<ty<<'\n';
            q.pop();
            for(int i=0;i<4;i++) {
                int px = tx+dx[i];
                int py = ty+dy[i];
                if(check(px, py) && arr[px][py]==0 && visited[px][py]==0) {
                    visited[px][py]=1;
                    arr[px][py]=1;
                    q.push(make_pair(px, py));
                }
            }
        }
    }
}

int get_ans() {
    bfs();
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]==0) return -1;
        }
    }
    return step;
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            int tmp;
            cin>>tmp;
            if(tmp==1) {
                q.push(make_pair(i, j));
                visited[i][j]=1;
            }
            arr[i][j]=tmp;
        }
    }
    if(q.size()==0) cout<<0<<'\n';
    else cout<<get_ans()<<'\n';
//    cout << "Hello world!" << endl;
    return 0;
}
