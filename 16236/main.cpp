#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> vec;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int xpos, ypos, psize, step, fl=0;
int num;
int ans=0;

void start() {
    queue<pair<int, int>> q;
    int visited[21][21] = {0,};
    step=1;
    q.push(make_pair(xpos, ypos));
    visited[xpos][ypos]=1;
    vec[xpos][ypos]=0;
    while(!q.empty()) {
        fl=0;
        int qsize = q.size();
        vector<pair<int, int>> pos;
        int xmin = INT_MAX;
        int ymin = INT_MAX;
        for(int i=0;i<qsize;i++) {
            int px = q.front().first;
            int py = q.front().second;
            q.pop();
            for(int j=0;j<4;j++) {
                int tx = px+dx[j];
                int ty = py+dy[j];
                if(tx>=0 && tx<num && ty>=0 && ty<num) {
                    if(visited[tx][ty]==0 && vec[tx][ty]<=psize) {
                        if(vec[tx][ty]>0 && vec[tx][ty]<psize) {
//                            cout<<"push this: "<<'\n';
//                            cout<<tx<<' '<<ty<<'\n';
                            pos.push_back(make_pair(tx, ty));
                        }
                        q.push(make_pair(tx, ty));
                        visited[tx][ty]=step;
                    }
                }
            }
        }
        if(pos.size()!=0) {
            fl=1;
            sort(pos.begin(), pos.end());
            xpos = pos[0].first;
            ypos = pos[0].second;
//            cout<<"I ate!"<<'\n';
//            cout<<xpos<<' '<<ypos<<' '<<psize<<' '<<step<<'\n';
            break;
        }
        step++;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    psize=2;
    cin>>num;
    for(int i=0;i<num;i++) {
        vector<int> v;
        for(int j=0;j<num;j++) {
            int t;
            cin>>t;
            if(t==9) {
                xpos = i;
                ypos = j;
            }
            v.push_back(t);
        }
        vec.push_back(v);
    }
    int eat=0;
    while(1) {
        if(eat==psize) {eat=0; psize++;}
//        cout<<xpos<<' '<<ypos<<' '<<eat<<' '<<psize<<'\n';
        start();
        if(fl==0) break;
        ans=ans+step;
        eat++;
//        cout<<"ans: "<<ans<<'\n';
    }
    cout << ans << '\n';
    return 0;
}
