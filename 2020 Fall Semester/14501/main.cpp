#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int num;
int ans = 0;

void go(int day, int sum) {
    if(day==num) {
        if(sum>ans) ans=sum;
        return;
    }
    if(day+v[day].first<=num) {
        go(day+v[day].first, sum+v[day].second);
    }
    go(day+1, sum);
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>num;
    for(int i=0;i<num;i++) {
        int t, p;
        cin>>t>>p;
        v.push_back(make_pair(t, p));
    }
    go(0, 0);
    cout << ans <<'\n';
    return 0;
}
