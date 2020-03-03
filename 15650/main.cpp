#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
vector<int> a;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        v.push_back(i);
        if(i<=m)
            a.push_back(1);
        else
            a.push_back(0);
    }
//    for(int i=0;i<a.size();i++)
//        cout<<a[i]<<" ";
    do {
        for(int i=0;i<n;i++) {
            if(a[i]!=0)
                cout<<v[i]<<" ";
        }
        cout<<'\n';
    } while(prev_permutation(a.begin(), a.end()));

    return 0;
}
