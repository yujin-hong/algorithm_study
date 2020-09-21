#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;
int num;
int maxnum = INT_MIN;
int minnum = INT_MAX;
void go(int res, int ind, int pl, int mi, int mul, int div) {
    if(pl<0 || mi<0 || mul<0 || div<0) return;

    if(ind==num) {
        if(res>maxnum) maxnum = res;
        if(res<minnum) minnum = res;
        return;
    }

    go(res+v[ind], ind+1, pl-1, mi, mul, div);
    go(res-v[ind], ind+1, pl, mi-1, mul, div);
    go(res*v[ind], ind+1, pl, mi, mul-1, div);
    go(res/v[ind], ind+1, pl, mi, mul, div-1);
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int pl, mi, mul, div;
    cin>>pl>>mi>>mul>>div;
    go(v[0], 1, pl, mi, mul, div);

    cout << maxnum <<'\n';
    cout << minnum <<'\n';
    return 0;
}
