#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;
int befdp[100002];
int afdp[100002];

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    befdp[0]=v[0];
    for(int i=1;i<n;i++) {
        befdp[i]=max(befdp[i-1]+v[i], v[i]);
    }

    afdp[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--) {
        afdp[i]=max(afdp[i+1]+v[i], v[i]);
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++) {
        int tmp=max(befdp[i]+afdp[i]-v[i], befdp[i]+afdp[i+1]-v[i+1]);
        if(tmp>ans) ans=tmp;
    }
    cout << ans << '\n';
    return 0;
}
