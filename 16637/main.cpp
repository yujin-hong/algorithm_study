#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;
int n;
int ans=INT_MIN;

int calc(int ind) {
    if(v[ind]==10) {
        return v[ind-1]+v[ind+1];
    } else if(v[ind]==11) {
        return v[ind-1]*v[ind+1];
    } else if(v[ind]==12) {
        return v[ind-1]-v[ind+1];
    }
}

void go(int ind, int res, int oper) {
//    cout<<ind<<" "<<res<<" "<<oper<<'\n';
    if(ind>n-1) {
        if(res>=ans) ans=res;
        return;
    }
    if(oper==10) {
        go(ind+2, res+v[ind], v[ind+1]);
        go(ind+4, res+calc(ind+1), v[ind+3]);
    } else if(oper==11) {
        go(ind+2, res*v[ind], v[ind+1]);
        go(ind+4, res*calc(ind+1), v[ind+3]);
    } else if(oper==12) {
        go(ind+2, res-v[ind], v[ind+1]);
        go(ind+4, res-calc(ind+1), v[ind+3]);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) {
        char tmp;
        cin>>tmp;
        if(tmp=='+')
            v.push_back(10);
        else if(tmp=='*')
            v.push_back(11);
        else if(tmp=='-')
            v.push_back(12);
        else
            v.push_back(tmp-48);
    }
    go(0,0,10);
    cout << ans << endl;
    return 0;
}
