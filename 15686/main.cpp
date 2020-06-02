#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> hv;

int arr[51][51];
int ans=INT_MAX;
int n,m;

void go(int ind, int num) {
//    cout<<ind<<" "<<num<<'\n';
    if(num>=v.size()-m) {
//        cout<<"==========="<<'\n';
        vector<pair<int, int>> t;
        int sum=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
//                cout<<arr[i][j]<<' ';
                if(arr[i][j]==2) {
                    t.push_back(make_pair(i,j));
                }
            }
//            cout<<'\n';
        }
        if(t.size()>0) {
            for(int i=0;i<hv.size();i++) {
                int hx = hv[i].first;
                int hy = hv[i].second;
                int nmin=INT_MAX;
                for(int j=0;j<t.size();j++) {
                    int tx = t[j].first;
                    int ty = t[j].second;
                    int dis = abs(hx-tx) + abs(hy-ty);
//                    cout<<"dis: "<<dis<<'\n';
                    if(dis<nmin) nmin=dis;
                }
                sum=sum+nmin;
            }
//            cout<<"sum: "<<sum<<'\n';
            if(sum<ans) ans=sum;
        }
        return;
    }
    if(ind>=v.size()) {
        return;
    }

    int x=v[ind].first;
    int y=v[ind].second;
    arr[x][y]=0;
    go(ind+1, num+1);
    arr[x][y]=2;
    go(ind+1, num);

}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int tmp;
            cin>>tmp;
            if(tmp==2) {
                v.push_back(make_pair(i,j));
            } else if(tmp==1) {
                hv.push_back(make_pair(i,j));
            }
            arr[i][j]=tmp;
        }
    }
    go(0,0);
    cout << ans << '\n';
    return 0;
}
