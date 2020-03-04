#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n,m;
int visited[8];

void go(int acc, vector<int> &a, int prev) {
    if(acc==m) {
        for(int i=0;i<m;i++) {
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    bool done[10001] = {false, };
    for(int i=0;i<n;i++) {
        if(done[v[i]]==false && v[i]>=prev) {
            done[v[i]]=true;
//            visited[i]=1;
            a.push_back(v[i]);
            go(acc+1, a, v[i]);
//            visited[i]=0;
            a.pop_back();
        }
    }
}
int main()
{
    cin>>n>>m;
    vector<int> p;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    go(0,p,0);
    return 0;
}
