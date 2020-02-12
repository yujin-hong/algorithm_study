#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int calc(vector<int> &a) {
    int sum=0;
    for(int i=0;i<a.size()-1;i++) {
        sum=sum+abs(a[i]-a[i+1]);
    }
    return sum;
}

int main()
{
    int ans=0;
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    do {
        int tmp1 = calc(v);
        if(tmp1>ans) ans=tmp1;
    } while(next_permutation(v.begin(), v.end()));

    cout<<ans<<'\n';
    return 0;
}
