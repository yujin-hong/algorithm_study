#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;

int calc(vector<int> &a) {
    int sum=0;
    for(int i=0;i<n-1;i++) {
        sum=sum+abs(a[i]-a[i+1]);
    }
    return sum;
}

int main()
{
    int ans=0;
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    do {
        for(int i=0;i<n;i++) {
            int tmpv = calc(v);
            if(tmpv>ans) ans=tmpv;
        }

    } while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}
