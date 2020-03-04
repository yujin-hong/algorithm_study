#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int ans;

int dfs(int start, int visited[], vector<int> v[], int color[]) {
    visited[start] = 1;
    vector<int> tmp = v[start];
    for(int i=0;i<tmp.size();i++) {
        if(visited[tmp[i]]==0) {
            visited[tmp[i]]=1;
            color[tmp[i]]=!color[start];
            dfs(tmp[i], visited, v, color);
        }
    }
    for(int i=1;i<tmp.size();i++) {
        if(color[tmp[i]]!=color[tmp[i-1]]) {
            ans=0;
        }
        if(ans==0) break;
    }
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        ans=1;
        vector<int> v[20001];
        int visited[20001]={0,};
        int color[20001]={-1,};
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        for(int j=0;j<tmp2;j++) {
            int p,q;
            cin>>p>>q;
            v[p].push_back(q);
            v[q].push_back(p);
        }
        color[1]=1;
        for(int j=1;j<=tmp1;j++) {
            dfs(j, visited, v, color);
            if(ans==0) break;
        }
        if(ans==0) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';


    return 0;
}
