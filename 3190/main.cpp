#include <iostream>
#include <deque>
//#include <pair>

using namespace std;
int arr[101][101];
int dir[10001];

deque<pair<int, int>> q;

int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=0;i<=n+1;i++) {
        arr[0][i]=1;
        arr[n+1][i]=1;
        arr[i][0]=1;
        arr[i][n+1]=1;
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        arr[a][b]=2;
    }

    int k;
    cin>>k;
    for(int i=0;i<k;i++) {
        int a;
        char c;
        cin>>a>>c;
        if(c=='D') dir[a]=1;
        else dir[a]=-1;
    }

    int d=1;
    int sx=1;
    int sy=1;
    q.push_front(make_pair(sx, sy));
    arr[sx][sy]=1;
    int num=0;

    while(1) {
//        for(int i=0;i<=n+1;i++) {
//            for(int j=0;j<=n+1;j++) {
//                cout<<arr[i][j]<<' ';
//            }
//            cout<<'\n';
//        }
//        cout<<"============================"<<'\n';
//        cout<<dir[num]<<'\n';
        int nx, ny;
        d=d+dir[num];
        if(d>4) d=1;
        else if(d<1) d=4;

        if(d==1) {
            nx=sx;
            ny=sy+1;
        } else if(d==2) {
            nx=sx+1;
            ny=sy;
        } else if(d==3) {
            nx=sx;
            ny=sy-1;
        } else {
            nx=sx-1;
            ny=sy;
        }

        if(arr[nx][ny]==0) {
            int tailx = q.back().first;
            int taily = q.back().second;
            q.pop_back();
            arr[tailx][taily]=0;
            q.push_front(make_pair(nx, ny));
            arr[nx][ny]=1;
            sx=nx;
            sy=ny;
        } else if(arr[nx][ny]==1) {
            break;
        } else if(arr[nx][ny]==2) {
            q.push_front(make_pair(nx, ny));
            arr[nx][ny]=1;
            sx=nx;
            sy=ny;
        }
        num++;

    }


//    cout<<"ans!!!!"<<'\n';
    cout << num+1 << '\n';
    return 0;
}
