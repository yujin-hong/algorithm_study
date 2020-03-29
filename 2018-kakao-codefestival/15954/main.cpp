#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> v;
double nmin=INT_MAX;

int main()
{
    freopen("input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int m=k;m<=n;m++) {
    for(int i=0;i<=n-m;i++) {
        // start point
//        cout<<"i: "<<i<<'\n';
        double ans;
        double sum=0;
        for(int j=i;j<i+m;j++) {
            sum=sum+v[j];
        }
        double avg = sum/m;
        double realsum=0;
        for(int j=i;j<i+m;j++) {
            realsum=realsum+(v[j]-avg)*(v[j]-avg);
        }
        ans=sqrt(realsum/m);
        if(ans<nmin) nmin = ans;
//        cout<<"ans: "<<ans<<'\n';
    }
    }
    cout.precision(11);
    cout << nmin << '\n';
    return 0;
}
