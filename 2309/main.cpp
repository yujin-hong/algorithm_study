#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v;
vector<int> ans;
int fl = 0;
void go(int ind, int sum, int n) {
//    cout<<ind<<" "<<sum<<" "<<n<<'\n';
    if(n>7 || sum>100 || ind>9) return;
    if(n==7 && sum==100) {
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<<'\n';
        }
        fl=1;
    }
    if(fl==1) return;
    ans.push_back(v[ind]);
    go(ind+1, sum+v[ind], n+1);
    ans.pop_back();
    go(ind+1, sum, n);
}
int main()
{
    freopen("input.txt","r",stdin);
    for(int i=0;i<9;i++) {
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
//    for(int i=0;i<9;i++) {
//        cout<<v[i]<<" ";
//    }
    go(0, 0, 0);

    return 0;
}
