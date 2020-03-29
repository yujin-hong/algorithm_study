#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> v;
int cost[250001];
int ind[250001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    int p,q;
    cin>>p>>q;
    for(int i=0;i<p;i++) {
        int x,y;
        cin>>x>>y;
        v.push_back(make_tuple(x,y,i));
    }
    sort(v.begin(), v.end());
    for(int i=0;i<p;i++) {
//        cout<<get<0>(v[i])<<" "<<get<1>(v[i])<<'\n';
        ind[get<2>(v[i])]=i;
    }
//    for(int i=0;i<p;i++) {
//        cout<<ind[i]<<'\n';
//    }
    for(int i=0;i<p-1;i++) {
        int sx = get<0>(v[i]);
        int sy = get<1>(v[i]);
        int nx = get<0>(v[i+1]);
        int ny = get<1>(v[i+1]);
        cost[i]=min(abs(nx-sx), abs(ny-sy));
    }
//    for(int i=0;i<p-1;i++) {
//        cout<<cost[i]<<'\n';
//    }
    for(int i=0;i<q;i++) {
        int start, fin, xmax;
        cin>>start>>fin>>xmax;
        long long sum=0;
        int ans=1;
        int st = min(ind[start], ind[fin]);
        int en = max(ind[start], ind[fin]);
//        cout<<st<<" "<<en<<'\n';
        for(int j=st-1;j<en-1;j++) {
            sum=sum+cost[j];
            if(sum>xmax) {
                ans=0;
                break;
            }
        }
        if(ans==1) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

//    cout << "Hello world!" << endl;
    return 0;
}
