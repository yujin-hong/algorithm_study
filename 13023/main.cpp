#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> v[2001];
bool visited[2001];

int fl=0;

void dfs(int start, int depth) {
//    cout<<start<<" "<<depth<<'\n';
    if(fl==1) return;
    if(depth==4) fl=1;
    visited[start] = true;
    vector<int> tmp = v[start];
    for(int i=0;i<tmp.size();i++) {
//        cout<<tmp[i]<<' ';
        if(visited[tmp[i]]==false) {
            dfs(tmp[i], depth+1);
            visited[tmp[i]]=false;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int a,b;
    cin>>a>>b;
    for(int i=0;i<b;i++) {
        int p,q;
        cin>>p>>q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    for(int i=0;i<a;i++) {
//        cout<<"=================="<<'\n';
        dfs(i,0);
        if(fl==1)
            break;
        memset(visited, false, sizeof(visited));
    }
    cout<<fl<<'\n';
    return 0;
}
