#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[9][9];
vector<pair<int, int>> bv;
vector<pair<int, int>> vv;
queue<pair<int, int>> q;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int nmax = 0;

int main()
{
    freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp;
            cin>>tmp;
            if(tmp==0) {
                bv.push_back(make_pair(i,j)); //place where wall ok
            } else if(tmp==2) {
                vv.push_back(make_pair(i,j));
            }
            arr[i][j]=tmp;
        }
    }
    vector<int> tmpv;

    for(int i=0;i<bv.size();i++) {
        if(i<3)
            tmpv.push_back(0);
        else
            tmpv.push_back(1);
    }
    do {
        int sum=0;
        int tarr[9][9];

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                tarr[i][j]=arr[i][j];
            }
        }

        for(int i=0;i<vv.size();i++) {
            q.push(vv[i]);
        }

        for(int i=0;i<bv.size();i++) {
            if(tmpv[i]==0) {
//                cout<<bv[i].first<<" "<<bv[i].second<<'\n';
                tarr[bv[i].first][bv[i].second]=1;
            }
        }
//        for(int i=0;i<n;i++) {
//            for(int j=0;j<m;j++) {
//                cout<<tarr[i][j]<<" ";
//            }
//            cout<<'\n';
//        }

        while(!q.empty()) {
            int tx = q.front().first;
            int ty = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int rx=tx+dx[i];
                int ry=ty+dy[i];
                if(rx>=0 && rx<n && ry>=0 && ry<m && tarr[rx][ry]==0) {
//                    cout<<"go inside: "<<rx<<" "<<ry<<'\n';
                    q.push(make_pair(rx, ry));
                    tarr[rx][ry]=2;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(tarr[i][j]==0)
                    sum=sum+1;
            }
        }
//        cout<<sum<<'\n';
        if(sum>nmax) nmax=sum;

    } while(next_permutation(tmpv.begin(), tmpv.end()));
    cout<<nmax<<'\n';
//    cout << "Hello world!" << endl;
    return 0;
}
