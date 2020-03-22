#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
int a[51][51];
vector<pair<int, int>> v;
vector<int> per;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int nmax = INT_MIN;
int main()
{
    freopen("input.txt","r",stdin);
    int n,m,g,r;
    cin>>n>>m>>g>>r;
    int bae=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp;
            cin>>tmp;
            if(tmp==2) {
                v.push_back(make_pair(i,j));
                bae++;
            }
            a[i][j]=tmp;
        }
    }
    for(int i=0;i<bae-g-r;i++) {
        per.push_back(0);
    }
    for(int i=0;i<g;i++) {
        per.push_back(1);
    }
    for(int i=0;i<r;i++) {
        per.push_back(2);
    }

//    for(int i=0;i<bae;i++) {
//        cout<<v[i].first<<" "<<v[i].second<<'\n';
//    }


    do {
        int flo=0;
        //do each case: pick position of red and green
        int redvis[51][51]={0,};
        int greenvis[51][51]={0,};
        queue<pair<int, int>> redq;
        queue<pair<int, int>> greenq;

        for(int i=0;i<per.size();i++) {
//            cout<<per[i]<<" ";
            if(per[i]==1) {
                greenq.push(v[i]);
                greenvis[v[i].first][v[i].second]=1;
            } else if(per[i]==2) {
                redq.push(v[i]);
                redvis[v[i].first][v[i].second]=1;
            }
        }
//        cout<<'\n';
        int step=2;
        while(!greenq.empty() && !redq.empty()) {
            int qsize = greenq.size();
            for(int k=0;k<qsize;k++) {
                int tx = greenq.front().first;
                int ty = greenq.front().second;
                greenq.pop();
                if(a[tx][ty]!=0 && redvis[tx][ty]==greenvis[tx][ty])
                    continue;
                for(int i=0;i<4;i++) {
                    int nx=tx+dx[i];
                    int ny=ty+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && greenvis[nx][ny]==0 && a[nx][ny]!=0) {
                        greenq.push(make_pair(nx, ny));
                        greenvis[nx][ny]=step;
                    }
                }
            }
            int rqsize = redq.size();
            for(int k=0;k<rqsize;k++) {
                int tx = redq.front().first;
                int ty = redq.front().second;
                redq.pop();
                if(a[tx][ty]!=0 && redvis[tx][ty]==greenvis[tx][ty])
                    continue;
                for(int i=0;i<4;i++) {
                    int nx=tx+dx[i];
                    int ny=ty+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && redvis[nx][ny]==0 && a[nx][ny]!=0) {
                        redq.push(make_pair(nx, ny));
                        redvis[nx][ny]=step;
                    }
                }
            }
            step++;
        }

//        while(!redq.empty()) {
//
//        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(redvis[i][j]==greenvis[i][j] && redvis[i][j]!=0)
                    flo++;
            }
        }
//        for(int i=0;i<n;i++) {
//            for(int j=0;j<m;j++) {
//                cout<<greenvis[i][j]<<" ";
//            }
//            cout<<'\n';
//        }
//        cout<<'\n';
//        for(int i=0;i<n;i++) {
//            for(int j=0;j<m;j++) {
//                cout<<redvis[i][j]<<" ";
//            }
//            cout<<'\n';
//        }
        if(flo>nmax) nmax=flo;
//        cout<<"flo: "<<flo<<'\n';
    } while(next_permutation(per.begin(), per.end()));
    cout<<nmax<<'\n';
    return 0;
}
