#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(a==0) return b;
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    else return gcd(a%b, b);
}
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int m;
        int sum=0;
        vector<int> v;
        cin>>m;
        for(int j=0;j<m;j++) {
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int j=0;j<m-1;j++) {
            for(int k=j+1;k<m;k++) {
//                cout<<v[j]<<" "<<v[k]<<" "<<gcd(v[j], v[k])<<'\n';
                sum=sum+gcd(v[j], v[k]);
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
