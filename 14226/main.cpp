#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, int>> q;
int visited[1001][1001];

int main()
{
    int des;
    cin>>des;
    int len=0;
    int fl=0;
    q.push(make_pair(1,0));
    visited[1][0]=1;
    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            pair<int, int> top = q.front();
            vector<int> tmpx;
            vector<int> tmpy;
            q.pop();
            int nx = top.first;
            int ny = top.second;
//            cout<<nx<<" "<<ny<<'\n';
            tmpx.push_back(nx-1);
            tmpy.push_back(ny);
            tmpx.push_back(nx);
            tmpy.push_back(nx);
            tmpx.push_back(nx+ny);
            tmpy.push_back(ny);
            for(int i=0;i<tmpx.size();i++) {
                int tx = tmpx[i];
                int ty = tmpy[i];
                if(tx>=0 && ty>=0 && tx<=1001 && ty<=1001) {
                    if(tx==des) {
                        fl=1;
                        break;
                    }
                    if(visited[tx][ty]==0) {
                        visited[tx][ty]=1;
                        q.push(make_pair(tx,ty));
                    }
                }
            }
            if(fl==1) break;
        }
        len++;
        if(fl==1) break;
    }
    cout << len << '\n';
    return 0;
}
