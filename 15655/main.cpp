#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
vector<int> p;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<n;i++) {
        if(i<m)
            p.push_back(0);
        else
            p.push_back(1);
    }
    sort(v.begin(), v.end());
    do {
        for(int i=0;i<n;i++) {
            if(p[i]==0)
                cout<<v[i]<<" ";
        }
        cout<<'\n';

    } while(next_permutation(p.begin(), p.end()));
    return 0;
}
