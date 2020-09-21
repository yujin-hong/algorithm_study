#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[1001];

int visited[1001];

void bfs(int ind) {
    queue<int> q;
    q.push(ind);
    visited[ind]=1;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        vector<int> nodes = v[top];
        for(int i=0;i<nodes.size();i++) {
            if(visited[nodes[i]]==0) {
                q.push(nodes[i]);
                visited[nodes[i]]=1;
            }
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        if(visited[i]==0) {
            bfs(i);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
