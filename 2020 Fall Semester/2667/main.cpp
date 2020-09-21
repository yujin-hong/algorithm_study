#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[26][26];
int visited[26][26];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int sx, int sy) {
    int total_num = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy]=1;
    while(!q.empty()) {
        total_num++;
        pair<int, int> top = q.front();
        int tx = top.first;
        int ty = top.second;
        q.pop();
        for(int i=0;i<4;i++) {
            int px = tx+dx[i];
            int py = ty+dy[i];
            if(arr[px][py]==1 && visited[px][py]==0) {
                visited[px][py]=1;
                q.push(make_pair(px, py));
            }
        }
    }
    return total_num;
}
int main()
{
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++){
            char c;
            cin>>c;
            arr[i][j] = c-48;
//            cout<<arr[i][j]<<' ';
        }
//        cout<<'\n';
    }

    vector<int> house_nums;

    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            if(arr[i][j]==1 && visited[i][j]==0) {
                house_nums.push_back(bfs(i,j));
            }
        }
    }
    sort(house_nums.begin(), house_nums.end());

    cout<<house_nums.size()<<'\n';

    for(int i=0;i<house_nums.size();i++) {
        cout<<house_nums[i]<<'\n';
    }
//    cout << "Hello world!" << endl;
    return 0;
}
