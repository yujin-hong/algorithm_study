#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, int>> v;
int nmax = INT_MIN;
int n;

void go(int prev_sum, int next_ind) {
//    cout<<prev_sum<<" "<<next_ind<<'\n';
    if(next_ind>n) {
        return;
    }
    if(prev_sum>nmax) nmax = prev_sum;

    go(prev_sum, next_ind+1);
//    cout<<v[next_ind].second<<" "<<v[next_ind].first<<'\n';
    if(next_ind<n)
        go(prev_sum+v[next_ind].second, next_ind+v[next_ind].first);
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) {
        int p, q;
        cin>>p>>q;
        v.push_back(make_pair(p, q));
    }
    go(0,0);
    cout << nmax << '\n';
    return 0;
}
