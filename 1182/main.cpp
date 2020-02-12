#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int sum=0;
int n, s;

void go(int prev_sum, int now_ind) {
//    cout<<prev_sum<<" "<<now_ind<<'\n';
    if(now_ind >= n) {
        if(prev_sum == s) sum=sum+1;
        return;
    }
    go(prev_sum, now_ind+1);
    go(prev_sum+v[now_ind], now_ind+1);
}

int main()
{
    freopen("input.txt","r", stdin);
    cin>>n>>s;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    go(0, 0);
    if(s==0) sum=sum-1;
    cout << sum << '\n';
    return 0;
}
