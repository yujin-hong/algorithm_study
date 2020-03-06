#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> q;
//priority_queue<pair<int, int>> q;
int visited[100001];

int main()
{
    int n,m;
    int fl=-1;
    cin>>n>>m;
    q.push(make_pair(0,n));
    visited[n]=1;
    while(!q.empty()) {
        vector<pair<int, int>> tmpv;
        pair<int, int> tmp = q.top();
        q.pop();
        int tx = tmp.first;
        int ty = tmp.second;
//            cout<<tx<<" "<<ty<<'\n';
//        cout<<"============="<<'\n';

        tmpv.push_back(make_pair(tx, ty*2));

        tmpv.push_back(make_pair(tx+1, ty+1));
        tmpv.push_back(make_pair(tx+1, ty-1));
//        sort(tmpv.begin(), tmpv.end());
        for(int i=0;i<tmpv.size();i++) {
            int nx = tmpv[i].first;
            int ny = tmpv[i].second;
            if(ny==m) {
                fl=nx;
            }
            if(nx>=0 && ny>=0 && ny<=100001) {

                if(visited[ny]==0) {
//            cout<<nx<<" "<<ny<<'\n';

                    q.push(make_pair(nx, ny));
                    visited[ny]=1;
                }
            }
        }
        if(fl!=-1)
            break;
//        cout<<"============="<<'\n';
    }
    cout << fl << '\n';
    return 0;
}
