#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[2001];
int visited[2001];

int n,m;
int ans=0;

void dfs(int start, int length) {
//    cout<<start<<" "<<length<<'\n';
    if(length==4) {
//        cout<<"eyyy?"<<'\n';
        ans=1;
        return;
    }
    vector<int> tmp = v[start];
    for(int i=0;i<tmp.size();i++) {
//        cout<<"this is arr val "<<tmp[i]<<'\n';
        if(visited[tmp[i]]==0) {
            visited[tmp[i]]=1;
            dfs(tmp[i],length+1);
            visited[tmp[i]]=0;
            if(ans==1) return;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int p,q;
        cin>>p>>q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    for(int i=0;i<n;i++) {
//        cout<<"hhhhh"<<'\n';
        visited[i]=1;
        dfs(i,0);
        visited[i]=0;
        if(ans==1) break;
    }
    cout << ans << endl;
    return 0;
}
