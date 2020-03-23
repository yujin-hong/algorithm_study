#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int dpi[1001], dpd[1001];

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
    dpi[0]=1;
    for(int i=1;i<num;i++) {
        int nmax=1;
        for(int j=0;j<i;j++) {
            if(v[j]<v[i]) {
                if(dpi[j]+1>nmax) nmax=dpi[j]+1;
            }
        }
        dpi[i]=nmax;
    }

    dpd[num-1]=1;
    for(int i=num-2;i>=0;i--) {
        int nmax=1;
        for(int j=i+1;j<num;j++) {
            if(v[j]<v[i]) {
                if(dpd[j]+1>nmax) nmax=dpd[j]+1;
            }
        }
        dpd[i]=nmax;
    }
    int ans=0;
    for(int i=0;i<num;i++) {
        int anstmp = dpi[i]+dpd[i]-1;
        if(anstmp>ans) ans=anstmp;
    }
    cout << ans << '\n';
    return 0;
}
