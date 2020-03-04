#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[26][26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int visited[26][26];
int len;
vector<int> v;
void dfs(int x, int y) {
    visited[x][y]=1;
    for(int i=0;i<4;i++) {
        int tmpx = x+dx[i];
        int tmpy = y+dy[i];
        if(visited[tmpx][tmpy]==0 && arr[tmpx][tmpy]==1) {
            len=len+1;
            visited[tmpx][tmpy]=1;
            dfs(tmpx, tmpy);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int tmp;
            char chtmp;
            cin>>chtmp;
            tmp=(int)chtmp-48;
            arr[i][j]=tmp;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]==1 && visited[i][j]==0) {
                len=1;
                dfs(i, j);
                v.push_back(len);
                ans=ans+1;
            }
        }
    }
    cout<<ans<<'\n';
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<'\n';
    }
    return 0;
}
