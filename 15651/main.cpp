#include <iostream>
#include <vector>

using namespace std;

int visited[8];
int n,m;

void go(int acc, vector<int> &a, int prev) {
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
        if(i>=prev) {
            a.push_back(i+1);
            go(acc+1, a, i);
//            visited[i]=0;
            a.pop_back();
        }

//        }
    }
}
int main()
{
    cin>>n>>m;
    vector<int> p;
//    for(int i=1;i<=n;i++) {
//        v.push_back(i);
//    }
    go(0, p, 0);
    return 0;
}
