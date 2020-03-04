#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1001];
int visited[1001];

void dfs(int start) {
    visited[start]=1;
    vector<int> tmp = v[start];
    for(int i=0;i<tmp.size();i++) {
        if(visited[tmp[i]]==0) {
            visited[tmp[i]]=1;
            dfs(tmp[i]);
        }
    }
}
int main()
{
    int ans=0;
    freopen("input.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++) {
        int p,q;
        cin>>p>>q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    for(int i=1;i<=m;i++) {
        if(visited[i]==0) {
            dfs(i);
            ans=ans+1;
        }
    }
    cout << ans << '\n';
    return 0;
}
