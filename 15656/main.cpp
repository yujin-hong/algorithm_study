#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[8];
vector<int> v;
int n,m;

void go(int acc, vector<int> &a) {
//    cout<<acc<<" ";
    if(acc==m) {
        for(int i=0;i<m;i++) {
            cout<<a[i]<<" ";
        }
//        cout<<i+1<<'\n';
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++) {
//            cout<<i<<" ";
//    cout<<visited[i]<<'\n';
//        if(visited[i]==0) {
//            visited[i]=1;
            a.push_back(v[i]);
            go(acc+1, a);
//            visited[i]=0;
            a.pop_back();
//        }
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
    go(0, p);
    return 0;
}
