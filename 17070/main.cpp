#include <iostream>

using namespace std;

int a[17][17];
int n;
int ans=0;

bool checkstat(int i, int j, int stat) {
    if(stat==1) {
        if(j+1<n && a[i][j+1]==0) return true;
    } else if(stat==2) {
        if(i+1<n && j+1<n && a[i][j+1]==0 && a[i+1][j+1]==0 && a[i+1][j]==0) return true;
    } else if(stat==3) {
        if(i+1<n && a[i+1][j]==0) return true;
    }
    return false;
}

void go(int i, int j, int stat) {
//    cout<<i<<" "<<j<<" "<<stat<<'\n';
    if(i>n-1 || j>n-1)
        return;
    if(i==n-1 && j==n-1) {
        ans=ans+1;
        return;
    }

    if(stat==1) {
        if(checkstat(i,j,1)) go(i,j+1,1);
        if(checkstat(i,j,2)) go(i+1, j+1, 2);
    } else if(stat==2) {
        if(checkstat(i,j,1)) go(i,j+1,1);
        if(checkstat(i,j,2)) go(i+1, j+1, 2);
        if(checkstat(i,j,3)) go(i+1, j, 3);
    } else if(stat==3) {
        if(checkstat(i,j,2)) go(i+1, j+1, 2);
        if(checkstat(i,j,3)) go(i+1, j, 3);
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int tmp;
            cin>>tmp;
            a[i][j]=tmp;
        }
    }
    go(0,1,1);
    cout << ans << '\n';
    return 0;
}
