#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
vector<int> result;
vector<int> v;

void go(int pl, int mi, int mul, int div, int res, int ind) {
    if(pl<0 || mi<0 || mul<0 || div<0) {
        return;
    }
    if(ind==num) {
        result.push_back(res);
        return;
    }
    go(pl-1, mi, mul, div, res+v[ind], ind+1);
    go(pl, mi-1, mul, div, res-v[ind], ind+1);
    go(pl, mi, mul-1, div, res*v[ind], ind+1);
    go(pl, mi, mul, div-1, res/v[ind], ind+1);
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>num;

    for(int i=0;i<num;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    go(a,b,c,d,v[0], 1);
    auto res = minmax_element(result.begin(), result.end());
    cout<<*res.second<<'\n'<<*res.first<<'\n';
}
