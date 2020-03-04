#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int arr[1001][1001];
int visited[1001][1001];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

queue<pair<int,int>> q;

int main()
{
    freopen("input.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int tmp;
            cin>>tmp;
            arr[i][j]=tmp;
            if(tmp==1) {
                visited[i][j]=1;
                q.push(make_pair(i,j));
            }
        }
    }
    int len=1;
    while(!q.empty()) {
        int qsize = q.size();
//        cout<<qsize<<'\n';
        for(int i=0;i<qsize;i++) {
            pair<int,int> tmp = q.front();
//            cout<<tmp.first<<" "<<tmp.second<<'\n';
            q.pop();
            for(int j=0;j<4;j++) {
                int nx = tmp.first+dx[j];
                int ny = tmp.second+dy[j];
                if(nx>=0 && ny>=0 && nx<n && ny<m) {
                    if(visited[nx][ny]==0 && arr[nx][ny]==0) {
                        arr[nx][ny]=len;
                        visited[nx][ny]=1;
                        q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        len++;
    }

//    for(int i=0;i<n;i++) {
//        for(int j=0;j<m;j++) {
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    len=len-2;

    int fl=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]==0) {
                fl=1;
                break;
            }
        }
        if(fl==1) {
            len=-1;
            break;
        }
    }
    cout << len << '\n';
    return 0;
}
