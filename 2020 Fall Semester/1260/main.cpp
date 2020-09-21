#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

vector<int> v[1001];
int checked[1001];

void dfs(int ind) {
    cout<<ind<<' ';
    checked[ind]=1;
    vector<int> nodes = v[ind];
    for(int i=0;i<nodes.size();i++) {
        if(checked[nodes[i]]==0) {
            dfs(nodes[i]);
        }
    }
}

void bfs(int ind) {
    queue<int> q;
    q.push(ind);
    checked[ind]=1;
    while(!q.empty()) {
        int top = q.front();
        cout<<top<<' ';
        q.pop();
        vector<int> nodes = v[top];
        for(int i=0;i<nodes.size();i++) {
            if(checked[nodes[i]]==0) {
                checked[nodes[i]]=1;
                q.push(nodes[i]);
            }
        }
    }
}
int main()
{
    freopen("input.txt","r", stdin);
    int n,m,st;
    cin>>n>>m>>st;
    for(int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        sort(v[i+1].begin(), v[i+1].end());
    }

    dfs(st);
    memset(checked, 0, sizeof(checked));
    cout<<'\n';
    bfs(st);
//    cout << "Hello world!" << endl;
    return 0;
}
