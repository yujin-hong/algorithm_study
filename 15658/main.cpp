#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> a;
vector<int> p;
vector<int> rans;

int calc(vector<int> &num, vector<int> &check) {
    vector<int> tmp;
    for(int i=0;i<check.size();i++) {
        if(check[i]==1) {
            tmp.push_back(a[i]);
        }
    }
    int ans;
    do {
        ans = num[0];
        int j=1;
        for(int i=0;i<tmp.size();i++) {
            if(tmp[i]==0)
                ans = ans+num[j++];
            else if(tmp[i]==1)
                ans = ans-num[j++];
            else if(tmp[i]==2)
                ans = ans*num[j++];
            else if(tmp[i]==3)
                ans = ans/num[j++];
        }
        rans.push_back(ans);
    } while(next_permutation(tmp.begin(), tmp.end()));
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
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
    for(int i=0;i<a.size();i++) {
        if(i<num-1)
            p.push_back(1);
        else
            p.push_back(0);
    }

    sort(p.begin(), p.end());
    do {
        calc(v,p);
    } while(next_permutation(p.begin(), p.end()));
    auto realans = minmax_element(rans.begin(), rans.end());
    cout<<*realans.second<<'\n'<<*realans.first<<'\n';


    return 0;
}
