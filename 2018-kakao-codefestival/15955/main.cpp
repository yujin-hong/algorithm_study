#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> v;
int visited[250001];
int ans;

void go(int sx, int sy, int dx, int dy, int xmax, int bust) {
//    cout<<sx<<" "<<sy<<" "<<dx<<" "<<dy<<'\n';
    if(ans==1) return;
    if((dx-sx)*(dx-sx)+(dy-sy)*(dy-sy)<=xmax*xmax) {
        ans=1;
//        cout<<"its done!"<<'\n';
        return;
    }
    for(int i=0;i<v.size();i++) {
        if(bust==1) {
            if(visited[i]==0) {
                int tx = v[i].first;
                int ty = v[i].second;
                if(sx==tx || sy==ty) {
                    visited[i]=1;
                    go(tx, ty, dx, dy, xmax,1);
                    visited[i]=0;
                } else {
                    go(tx, sy, dx, dy, xmax,0);
                    go(sx, ty, dx, dy, xmax,0);
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    int p,q;
    cin>>p>>q;
    for(int i=0;i<p;i++) {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    for(int i=0;i<q;i++) {
        int start, fin, xmax;
        cin>>start>>fin>>xmax;
        memset(visited,0,sizeof(visited));
        int sx = v[start-1].first;
        int sy = v[start-1].second;
        int ex = v[fin-1].first;
        int ey = v[fin-1].second;
//        if(xmax==0) {
        visited[start-1]=1;
        ans=0;
        go(sx, sy, ex, ey, xmax, 1);
        if(ans==0) {
            cout<<"NO"<<'\n';
        } else {
            cout<<"YES"<<'\n';
        }
//        }
//        cout<<"ans: "<<ans<<"========end"<<'\n';
    }

//    cout << "Hello world!" << endl;
    return 0;
}
