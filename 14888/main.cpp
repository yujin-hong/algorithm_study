#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> a;
vector<int> ans;
int calc(vector<int> &p, vector<int> &q) {
    int ans = p[0];
    for(int i=0;i<q.size();i++) {
        if(q[i]==0)
            ans = ans+p[i+1];
        else if(q[i]==1)
            ans = ans-p[i+1];
        else if(q[i]==2)
            ans = ans*p[i+1];
        else if(q[i]==3)
            ans = ans/p[i+1];
    }
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<4;i++) {
        int tmp;
        cin>>tmp;
        for(int j=0;j<tmp;j++) {
            a.push_back(i);
        }
    }
//    for(int i=0;i<a.size();i++) {
//        cout<<a[i]<<" ";
//    }
    do {
        ans.push_back(calc(v, a));
    } while(next_permutation(a.begin(), a.end()));
    auto realans = minmax_element(ans.begin(), ans.end());
    cout<<*realans.second<<'\n'<<*realans.first<<'\n';
    return 0;
}
