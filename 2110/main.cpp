#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> v;
int n,m;
int ans=INT_MIN;

void go(int st, int en) {
    if(st>=en) return;
    int mid = (st+en)/2;
//    cout<<st<<' '<<mid<<' '<<en<<'\n';
//    int rtot = INT_MIN;
//    for(int i=0;i<v.size();i++) {
        int fir = v[0];
        int tot=1;
        for(int j=1;j<v.size();j++) {
//                cout<<"v[j] "<<v[j]<<'\n';
            if(v[j]>=fir+mid) {
//                cout<<"here v[j] "<<v[j]<<'\n';
                tot++;
                fir=v[j];
            }
        }
//        if(tot>rtot) rtot = tot;
//    }
//    cout<<mid<<' '<<rtot<<'\n';
    if(tot<m) {
        go(st, mid);
    } else {
        if(mid>ans) ans=mid;
        go(mid+1, en);
    }
}
int main()
{
    freopen("input.txt","r",stdin);

    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    go(1, v[v.size()-1]-v[0]);

    cout << ans << '\n';
    return 0;
}
