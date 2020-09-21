#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n,m;
int ans = 0;

void go(int ind, int sum, int use_count) {
//    cout<<ind<<' '<<sum<<'\n';

    if(ind>=n) {
        if(use_count>0 && sum==m) {
//            cout<<"==========answer"<<'\n';
            ans++;
        }
        return;
    }
    go(ind+1, sum+v[ind], use_count+1);
    go(ind+1, sum, use_count);
}

int main()
{
    freopen("input.txt","r", stdin);

    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    go(0, 0, 0);

    cout << ans << '\n';
    return 0;
}
