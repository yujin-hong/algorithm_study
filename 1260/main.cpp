#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

vector<int> a[1001];
queue<int> q;
bool visited[1001];
void dfs(int start) {
    cout<<start<<' ';
    visited[start]=true;
    vector<int> tmp = a[start];
    for(int i=0;i<tmp.size();i++) {
        if(visited[tmp[i]]==false)
            dfs(tmp[i]);
    }

}


void bfs(int start) {
    visited[start] = true;
    cout<<start<<' ';
    q.push(start);
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        for(int i=0;i<a[top].size();i++) {
            if(visited[a[top][i]]==false) {
                visited[a[top][i]]=true;
                cout<<a[top][i]<<' ';
                q.push(a[top][i]);
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int n,m,v;
    cin>>n>>m>>v;
    int p,q;
    for(int i=0;i<m;i++) {
        cin>>p>>q;
        a[p].push_back(q);
        a[q].push_back(p);
    }
    for(int i=1;i<=n;i++) {
        sort(a[i].begin(), a[i].end());
//        cout<<i<<" ";
//        for(int j=0;j<a[i].size();j++) {
//            cout<<a[i][j]<<" ";
//        }
//        cout<<'\n';
    }
    dfs(v);
    cout<<'\n';
    memset(visited, false, sizeof(visited));
//    cout<<"bfs start"<<'\n';
    bfs(v);
    return 0;
}
