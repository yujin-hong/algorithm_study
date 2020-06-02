#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int arr[9][9];
vector<pair<int, int>> v;
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int nmin=INT_MAX;
    int n,m;

void go(int ind, int rarr[9][9]) {
//    cout<<"-=================="<<'\n';
//    cout<<ind<<'\n';
//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cout<<rarr[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    if(ind==v.size()) {
        int sum=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(rarr[i][j]==0) {
                    sum++;
                }
            }
        }
//        cout<<sum<<'\n';
        if(sum<nmin) nmin=sum;
        return;
    }
    int x=v[ind].first;
    int y=v[ind].second;
    int t=rarr[x][y];
    int tarr[9][9];

    if(t==1) {
        for(int i=0;i<4;i++) {
            for(int p=0;p<n;p++) {
                for(int q=0;q<m;q++) {
                    tarr[p][q]=rarr[p][q];
                }
            }
            int tx=x;
            int ty=y;
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                tx=tx+dx[i];
                ty=ty+dy[i];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            go(ind+1, tarr);
        }
    } else if(t==2) {
        for(int i=0;i<2;i++) {
            for(int p=0;p<n;p++) {
                for(int q=0;q<m;q++) {
                    tarr[p][q]=rarr[p][q];
                }
            }
            int tx=x;
            int ty=y;
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                tx=tx+dx[i];
                ty=ty+dy[i];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            tx=x;
            ty=y;
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                tx=tx+dx[i+2];
                ty=ty+dy[i+2];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            go(ind+1, tarr);
        }
    } else if(t==3) {
        for(int i=0;i<4;i++) {
            for(int p=0;p<n;p++) {
                for(int q=0;q<m;q++) {
                    tarr[p][q]=rarr[p][q];
                }
            }
            int tx=x;
            int ty=y;
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                tx=tx+dx[i];
                ty=ty+dy[i];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            tx=x;
            ty=y;
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                int tmp=i+1;
                if(tmp>=4) tmp=tmp-4;
                tx=tx+dx[tmp];
                ty=ty+dy[tmp];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            go(ind+1, tarr);
        }
    } else if(t==4) {
        for(int i=0;i<4;i++) {
            for(int p=0;p<n;p++) {
                for(int q=0;q<m;q++) {
                    tarr[p][q]=rarr[p][q];
                }
            }
            int tx=x;
            int ty=y;
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                tx=tx+dx[i];
                ty=ty+dy[i];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            tx=x;
            ty=y;
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                int tmp=i+1;
                if(tmp>=4) tmp=tmp-4;
                tx=tx+dx[tmp];
                ty=ty+dy[tmp];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            tx=x;
            ty=y;
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                int tmp=i+2;
                if(tmp>=4) tmp=tmp-4;
                tx=tx+dx[tmp];
                ty=ty+dy[tmp];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            go(ind+1, tarr);
        }
    } else {
        int tx=x;
        int ty=y;
        for(int p=0;p<n;p++) {
            for(int q=0;q<m;q++) {
                tarr[p][q]=rarr[p][q];
            }
        }
        for(int i=0;i<4;i++) {
            while(tx>=0 && ty>=0 && tx<n && ty<m && arr[tx][ty]!=6) {
                tx=tx+dx[i];
                ty=ty+dy[i];
                if(tarr[tx][ty]==0) tarr[tx][ty]=-1;
            }
            tx=x;
            ty=y;
        }
        go(ind+1, tarr);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp;
            cin>>tmp;
            if(tmp!=0 && tmp!=6) v.push_back(make_pair(i,j));
            arr[i][j]=tmp;
        }
    }
    go(0, arr);
    cout << nmin << '\n';
    return 0;
}
