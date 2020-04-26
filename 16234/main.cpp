#include <iostream>
#include <math.h>
#include <queue>

using namespace std;
int arr[51][51];

int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int ans=-1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    int l, r;
    cin>>l>>r;
//    cout<<l<<" "<<r<<'\n';
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    while(1) {
//cout<<"=========================="<<'\n';
        ans++;
        int num=1;
        int check[51][51]={0,};
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(check[i][j]==0) {
//                    cout<<"new! "<<i<<" "<<j<<'\n';
                    check[i][j]=num;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i,j));
                    int samen=0;
                    int tsum=0;
                    vector<pair<int, int>> vv;
                    while(!q.empty()) {
                        int tx=q.front().first;
                        int ty=q.front().second;
                        vv.push_back(make_pair(tx, ty));
                        samen++;
                        tsum=tsum+arr[tx][ty];
//                        cout<<"tx: "<<tx<<" "<<ty<<'\n';
                        q.pop();
                        for(int k=0;k<4;k++) {
                            if(tx+dx[k]>=0 && tx+dx[k]<n && ty+dy[k]>=0 && ty+dy[k]<n && check[tx+dx[k]][ty+dy[k]]==0) {
                                int tmp = abs(arr[tx][ty]-arr[tx+dx[k]][ty+dy[k]]);
//                                cout<<"try: "<<tx+dx[k]<<' '<<ty+dy[k]<<' '<<tmp<<'\n';
                                if(tmp>=l && tmp<=r) {
//                                    cout<<"hrer: "<<tx+dx[k]<<" "<<ty+dy[k]<<" "<<num<<'\n';
                                    check[tx+dx[k]][ty+dy[k]]=num;
                                    q.push(make_pair(tx+dx[k], ty+dy[k]));
                                }
                            }
                        }
                    }
                    for(int i=0;i<vv.size();i++) {
                        arr[vv[i].first][vv[i].second]=tsum/samen;
                    }
                    num++;
                }
            }
        }
        if(num>n*n) {
//            cout<<"finish"<<'\n';
            break;
        }
//        for(int k=1;k<num;k++) {
//            vector<pair<int, int>> tv;
//            int sum=0;
//            for(int i=0;i<n;i++) {
//                for(int j=0;j<n;j++) {
//                    if(check[i][j]==k) {
//                        sum=sum+arr[i][j];
//                        tv.push_back(make_pair(i,j));
//                    }
//                }
//            }
//            int newval = sum/tv.size();
//            for(int i=0;i<tv.size();i++) {
//                arr[tv[i].first][tv[i].second]=newval;
//            }
//        }
//        for(int i=0;i<n;i++) {
//            for(int j=0;j<n;j++) {
//                cout<<check[i][j]<<" ";
//            }
//            cout<<'\n';
//        }
    }
    cout << ans << '\n';
    return 0;
}
