#include <iostream>
#include <queue>

using namespace std;

int visited[11][11];

queue<pair<int, int>> q;
queue<pair<int, int>> bq;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    int n,m;
    int bx, by;
    pair<int, int> b;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            if(ch=='#') visited[i][j]=-1;
            else if(ch=='R') q.push(make_pair(i,j));
            else if(ch=='B') {visited[i][j]=-3; bq.push(make_pair(i, j));}
            else if(ch=='O') visited[i][j]=-2;
        }
    }
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cout<<visited[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    int num=1;
    int ans=0;
    while(!q.empty()) {
        for(int i=0;i<q.size();i++) {
            int qx = q.front().first;
            int qy = q.front().second;
            int bx = bq.front().first;
            int by = bq.front().second;
//            cout<<qx<<" "<<qy<<" "<<bx<<" "<<by<<'\n';

            q.pop();
            bq.pop();
            for(int j=0;j<4;j++) {
                int tx = qx+dx[j];
                int ty = qy+dy[j];
//                cout<<"tx: "<<tx<<" "<<ty<<'\n';
                if(visited[tx][ty]==0 || visited[tx][ty]==-2) {
//                    cout<<"tx1: "<<tx<<" "<<ty<<'\n';
                    while(1) {
                        bx=bx+dx[j];
                        by=by+dy[j];
//                        cout<<"bx: "<<bx<<" "<<by<<" "<<visited[bx][by]<<'\n';
                        if(visited[bx][by]!=0) break;
                    }
//                    visited[bx-dx[j]][by-dy[j]]=-3;
//                    visited[tx][ty]=num;
                    while(1) {
                        if(visited[tx][ty]!=0) break;
                        else visited[tx][ty]=num;
                        tx=tx+dx[j];
                        ty=ty+dy[j];
                    }

                    if(visited[tx][ty]==-2) {
//                            cout<<"hohohoho"<<'\n';
                        if(bx==tx && by==ty) {
                            ans=-1;
                        } else {
                            ans=num;
                        }
                        break;
                    }
                    if(bx==tx && by==ty) { bx=bx-dx[j]; by=by-dy[j]; }
//                    else if(visited[tx][ty]==-3) {ans=-1; break;}
//                    cout<<"it will go: b: "<<bx-dx[j]<<" "<<by-dy[j]<<'\n';
//                    cout<<"it will go: r: "<<tx-dx[j]<<" "<<ty-dy[j]<<'\n';

                    q.push(make_pair(tx-dx[j], ty-dy[j]));
                    bq.push(make_pair(bx-dx[j], by-dy[j]));
//                    visited[bx-dx[j]][by-dy[j]]=0;
                }
            }
//            cout<<"nowans: "<<ans<<'\n';
            if(ans!=0) break;
        }
        if(ans!=0) break;
        num++;
    }
//    cout<<"origin: "<<ans<<'\n';
    if(ans>10 || ans==0) ans=-1;
    cout << ans << '\n';
    return 0;
}
