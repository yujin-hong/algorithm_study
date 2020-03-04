#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
vector<int> v[1001];
int visited[1001];
queue<int> q;

void dfs(int start) {
    visited[start] = 1;
    cout<<start<<" ";
    vector<int> tmp = v[start];
    for(int i=0;i<tmp.size();i++) {
        if(visited[tmp[i]]==0) {
            visited[tmp[i]]=1;
            dfs(tmp[i]);
//            visited[tmp[i]]=0;
        }
    }
}

void bfs(int start) {
    cout<<start<<" ";
    q.push(start);
    visited[start]=1;
    while(!q.empty()) {
        int next = q.front();
        q.pop();
        vector<int> tmp = v[next];
        for(int i=0;i<tmp.size();i++) {
            if(visited[tmp[i]]==0) {
                visited[tmp[i]]=1;
                q.push(tmp[i]);
                cout<<tmp[i]<<" ";
            }
        }
    }


}
int main()
{
    freopen("input.txt","r",stdin);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++) {
        int p,q;
        cin>>p>>q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    for(int i=1;i<=n;i++) {
        sort(v[i].begin(), v[i].end());
    }
    dfs(k);
    cout<<'\n';
    memset(visited, 0, sizeof(visited));
//    for(int i=0;i<m;i++) {
//        cout<<visited[i]<<" ";
//    }
    bfs(k);

//    cout << "Hello world!" << endl;
    return 0;
}
