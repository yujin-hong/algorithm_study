#include <iostream>
#include <vector>

using namespace std;

int mise[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans=0;

int main()
{
    freopen("input.txt","r",stdin);
    int m, n, t, sx, sy;
    cin>>n>>m>>t;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>mise[i][j];
            if(mise[i][j]==-1) {
                sx = i;
                sy = j;
            }
        }
    }

    for(int i=0;i<t;i++) {
        sx=sx-1;
        int arr[51][51]={0,};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mise[i][j]!=0 && mise[i][j]!=-1) {
                    int sepmise = mise[i][j]/5;
                    int dist = 0;
                    for(int k=0;k<4;k++) {
                        int tx = i+dx[k];
                        int ty = j+dy[k];
                        if(tx>=0 && tx<n && ty>=0 && ty<m && mise[tx][ty]!=-1) {
                            arr[tx][ty]=arr[tx][ty]+sepmise;
                            dist++;
                        }
                    }
                    arr[i][j]=arr[i][j]-sepmise*dist;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                mise[i][j] = mise[i][j]+arr[i][j];
            }
        }
//        for(int i=0;i<n;i++) {
//            for(int j=0;j<m;j++) {
//                cout<<mise[i][j]<<' ';
//            }
//            cout<<'\n';
//        }
        mise[sx][sy]=0;
        int n1 = mise[0][0];
        int n2 = mise[0][n-1];
        int n3 = mise[sx][0];
        int n4 = mise[sx][n-1];

        for(int i=1;i<m-1;i++) {
            mise[0][i-1]=mise[0][i];
        }
        for(int i=m-1;i>0;i--) {
            mise[sx][i]=mise[sx][i-1];
        }
        for(int i=1;i<sx;i++) {
            mise[i-1][m-1]=mise[i][m-1];
        }
        for(int i=sx;i>0;i--) {
            mise[i][0]=mise[i-1][0];
        }
        mise[1][0]=n1;
        mise[0][m-2]=n2;
        mise[sx][1]=n3;
        mise[sx-1][m-1]=n4;
        mise[sx][sy]=-1;

        sx=sx+1;
        mise[sx][sy]=0;
        n1 = mise[sx][0];
        n2 = mise[n-1][0];
        n3 = mise[sx][m-1];
        n4 = mise[n-1][m-1];
        //n1, n3
        for(int i=m-1;i>0;i--) {
            mise[sx][i]=mise[sx][i-1];
        }
        //n1, n2
        for(int i=sx;i<n-2;i++) {
            mise[i][0]=mise[i+1][0];
        }
        //n3, n4
        for(int i=n-1;i>sx;i--) {
            mise[i][m-1]=mise[i-1][m-1];
        }
        //n2, n4
        for(int i=0;i<m-2;i++) {
            mise[n-1][i]=mise[n-1][i+1];
        }
        mise[sx][1]=n1;
        mise[n-2][0]=n2;
        mise[sx+1][m-1]=n3;
        mise[n-1][m-2]=n4;
        mise[sx][sy]=-1;

    }
//    cout<<"================================"<<'\n';
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans=ans+mise[i][j];
//                cout<<mise[i][j]<<' ';
            }
//            cout<<'\n';
        }
    cout << ans+2 << '\n';
    return 0;
}
