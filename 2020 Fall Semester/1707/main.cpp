#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

vector<int> vec[20001];
int visited[20001];

int bfs(int ind) {
    queue<int> q;
    visited[ind]=1;
    q.push(ind);
    while(!q.empty()) {
        int top = q.front();
        int color = !visited[top];
//        cout<<top<<'\n';
        q.pop();
        vector<int> nodes = vec[top];
        for(int i=0;i<nodes.size();i++){
            if(visited[nodes[i]]==-1) {
//                cout<<"i will push: "<<nodes[i]<<" visited: "<<color<<'\n';
                q.push(nodes[i]);
                visited[nodes[i]]=color;
            } else {
                if(visited[nodes[i]]!=color) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main()
{
    //use bfs
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int j=0;j<num;j++) {
        int v, e;
        cin>>v>>e;
        memset(vec, 0, sizeof(vec));
        memset(visited, -1, sizeof(visited));
        for(int i=0;i<e;i++) {
            int a, b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        int res;
        for(int i=1;i<=v;i++) {
            if(visited[i]==-1) {
                res = bfs(i);
                if(res == 0) break;
            }
        }
        if(res==0) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
    return 0;
}
