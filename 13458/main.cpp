#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int ans;

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    int b;
    cin>>b;
    for(int i=0;i<n;i++) {
        v[i]=v[i]-b;
        if(v[i]<0) v[i]=0;
    }
    ans=n;
    int c;
    cin>>c;
    for(int i=0;i<n;i++) {
        if(v[i]%c==0)
            ans=ans+v[i]/c;
        else
            ans=ans+(v[i]/c)+1;
    }
    cout << ans << '\n';
    return 0;
}
