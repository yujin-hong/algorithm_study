#include <iostream>
#include <queue>

using namespace std;

int m,n;
char a[51][51];
int visited[51][51];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

queue<pair<int, int>> waterq;
queue<pair<int, int>> beaq;
pair<int, int> des;
pair<int, int> start;

void bfs() {
    while(!beaq.empty()) {
        int wqsize = waterq.size();
        for(int p=0;p<wqsize;p++) {
            pair<int, int> fr = waterq.front();
            int frx = fr.first;
            int fry = fr.second;
            waterq.pop();
            for(int i=0;i<4;i++) {
                int nx = frx+dx[i];
                int ny = fry+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !(nx==des.first && ny==des.second)) {
                    if(visited[nx][ny]==0) {
                        waterq.push(make_pair(nx, ny));
                        visited[nx][ny]=-1;
                    }
                }
            }
        }
        int bqsize = beaq.size();
        for(int p=0;p<bqsize;p++) {
            pair<int, int> fr = beaq.front();
            int frx = fr.first;
            int fry = fr.second;
            beaq.pop();
            for(int i=0;i<4;i++) {
                int nx = frx+dx[i];
                int ny = fry+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n) {
                    if(visited[nx][ny]==0) {
                        beaq.push(make_pair(nx, ny));
                        visited[nx][ny]=visited[frx][fry]+1;
                    }
                }
            }
        }
//        for(int i=0;i<m;i++) {
//            for(int j=0;j<n;j++) {
//                cout<<visited[i][j]<<" ";
//            }
//            cout<<'\n';
//        }
//        cout<<'\n'<<'\n';
    }
}
int main()
{
    freopen("input.txt","r",stdin);


    cin>>m>>n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            char tmp;
            cin>>tmp;
            if(tmp=='D') {
                des=make_pair(i,j);
            } else if(tmp=='S') {
                start=make_pair(i,j);
                beaq.push(make_pair(i,j));
                visited[i][j]=1;
            } else if(tmp=='*') {
                visited[i][j]=-1;
                waterq.push(make_pair(i,j));
            } else if(tmp=='X') {
                visited[i][j]=-1;
            }
            a[i][j]=tmp;
        }
    }
    bfs();
    if(visited[des.first][des.second]==0) cout<<"KAKTUS";
    else cout<<visited[des.first][des.second]-1<<'\n';

//    cout<<des.first<<" "<<des.second<<'\n';
//    cout<<start.first<<" "<<start.second<<'\n';

//    cout << "Hello world!" << endl;
    return 0;
}
