#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
vector<tuple<int, int, int>> v;
vector<pair<int, int>> ansv;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back(make_tuple(a,b,i));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<num;i++) {
        int n=0;
        for(int j=0;j<i;j++) {
            if(get<0>(v[i])<get<1>(v[j]) && get<0>(v[i])>get<0>(v[j])) n++;
        }
        ansv.push_back(make_pair(get<2>(v[i]), n));
//        cout<<get<0>(v[i])<<' '<<get<1>(v[i])<<' '<<get<2>(v[i])<<'\n';
    }
    sort(ansv.begin(), ansv.end());
    for(int i=0;i<ansv.size();i++) {
        cout<<ansv[i].second<<'\n';
    }
//    cout << "Hello world!" << endl;
    return 0;
}
