#include <iostream>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

int arr[1001][1001];
int visited[1001][1001][2];
//int wall[1001][1001];
//deque<pair<int,int>> q;
queue<tuple<int,int,int>> q;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int m,n;

int val = -1;

void bfs() {
    while(!q.empty()) {
        tuple<int, int, int> fir = q.front();
        int fx = get<0>(fir);
        int fy = get<1>(fir);
        int wall = get<2>(fir);
        q.pop();
//        cout<<fx<<" "<<fy<<" "<<wall<<" "<<visited[fx][fy][wall]<<'\n';
        if(fx==m-1 && fy==n-1) {
            val = wall;
//            cout<<"ans: "<<visited[fx][fy][wall]<<'\n';
            break;
        }
        for(int i=0;i<4;i++) {
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n) {
                    if(wall==0) {
                        int tp = arr[nx][ny];
                        if(visited[nx][ny][tp]==0) {
                            visited[nx][ny][tp]=visited[fx][fy][0]+1;
                            q.push(make_tuple(nx, ny, tp));
                        }
                    } else {
                        if(arr[nx][ny]==0 && visited[nx][ny][1]==0) {
                            visited[nx][ny][1]=visited[fx][fy][1]+1;
                            q.push(make_tuple(nx, ny, 1));
                        }
                    }
//                if(visited[nx][ny]==0) {
//                cout<<"this is nx,ny "<<nx<<" "<<ny<<'\n';
//
//                    cout<<"arr val: "<<arr[nx][ny]<<'\n';
//                    if(arr[nx][ny]==0) {
//                        visited[nx][ny]=visited[fx][fy]+1;
//                        wall[nx][ny]=wall[fx][fy];
//                        q.push(make_pair(nx, ny));
//                    }
//                    if(arr[nx][ny]==1 && wall[fx][fy]==0) {
//                        visited[nx][ny]=visited[fx][fy]+1;
//                        wall[nx][ny]=1;
//                        q.push(make_pair(nx, ny));
//                    }
//                }

            }

        }

    }
}

int main()
{
    freopen("input.txt","r", stdin);
    cin>>m>>n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            char chtmp;
            cin>>chtmp;
            int tmp = (int)chtmp-48;
            arr[i][j]=tmp;
        }
    }
    visited[0][0][0]=1;
    q.push(make_tuple(0,0,0));
    bfs();
    if(val!=-1) {
        cout << visited[m-1][n-1][val] << '\n';
    } else {
        cout<<-1<<'\n';
    }

    return 0;
}
