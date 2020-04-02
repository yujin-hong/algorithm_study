#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int fl=0;

void bin_sch(int n, int st, int la)  {
//    cout<<n<<" "<<st<<" "<<la<<'\n';
    int mid = v[(st+la)/2];
    if(mid==n) {
        fl=1;
        return;
    }
    if(st>=la) return;

    if(n>mid) bin_sch(n, (st+la)/2+1, la);
    else bin_sch(n, st, (st+la)/2-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int tmp;
        cin>>tmp;
//        cout<<tmp<<'\n';
        bin_sch(tmp, 0, n-1);
        cout<<fl<<'\n';
        fl=0;
    }
    return 0;
}
