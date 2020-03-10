#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int ans[10001][3];

int main()
{
    freopen("input.txt","r",stdin);
    int tmp;
    cin>>tmp;
    for(int i=0;i<tmp;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    ans[0][1]=v[0];
    ans[0][2]=max(ans[0][0], ans[0][1]);
    ans[1][0]=v[0];
    ans[1][1]=v[0]+v[1];
    ans[1][2]=max(ans[1][0], ans[1][1]);
    ans[2][0]=ans[1][1];
    ans[2][1]=max(ans[0][0]+v[1]+v[2], ans[1][0]+v[2]);
    ans[2][2]=max(ans[2][0], ans[2][1]);


    for(int i=3;i<tmp;i++) {
        ans[i][1]=max(ans[i-3][2]+v[i-1]+v[i], ans[i-2][2]+v[i]);
        ans[i][0]=ans[i-1][2];
        ans[i][2]=max(ans[i][0], ans[i][1]);
    }
//    for(int i=0;i<tmp;i++) {
//        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<'\n';
//    }
    cout << max(ans[tmp-1][0], ans[tmp-1][1]) << '\n';
    return 0;
}
