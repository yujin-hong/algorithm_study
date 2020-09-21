#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n,m;
    vector<char> v;
    vector<int> refine;
//    char a[16];
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        char tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());


    for(int i=0;i<n;i++) {
        refine.push_back(0);
    }
    for(int i=0;i<m-n;i++) {
        refine.push_back(1);
    }

    do {
        int odd = 0;
        int even = 0;
        vector<char> ans;

        for(int i=0;i<m;i++) {
            if(refine[i]==0) {
                if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u') {
                    odd++;
                } else {
                    even++;
                }
                ans.push_back(v[i]);
            }
        }

        if(odd>=1 && even >=2) {
            for(int i=0;i<ans.size();i++) {
                cout<<ans[i];
            }
            cout<<'\n';
        }

    } while(next_permutation(refine.begin(), refine.end()));
    return 0;
}
