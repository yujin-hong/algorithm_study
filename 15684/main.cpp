#include <iostream>
#include <vector>

using namespace std;
vector<int> v[11];
int ver, n, hor;

void dfs(int ind) {
    if(v[ind].size()%2==0) {
        int fmin=INT_MAX, fmax=INT_MIN;
        for(int i=0;i<v[ind].size();i++) {
            for(int j=0;j<v[ind].size();j++) {
            }
        }
        if(fmin<)
        dfs(ind+1);
    } else {
        set<int> s;
        for(int i=0;i<v[ind-1].size();i++) {
            s.insert(v[ind-1][i]);
        }
        for(int i=0;i<v[ind+1].size();i++) {
            s.insert(v[ind-1][i]);
        }
        for(int i=1;i<=hor;i++) {

        }
    }

}
int main()
{
    freopen("input.txt","r",stdin);
    int ans=0;
    cin>>ver>>n>>hor;
    for(int i=0;i<n;i++) {
        int r,c;
        cin>>r>>c;
        v[c].push_back(r);
    }
    for(int i=1;i<=ver;i++) {
        if(v[i].size()%2!=0) {
            ans++;
        }
    }
    if(ans>3) {
        ans=-1;
    } else {
        dfs(1);

    }
    cout << ans << '\n';
    return 0;
}
