#include <iostream>
#include <queue>

using namespace std;

int visited[1000001];
queue<int> q;
int num;
int step = -1;

bool check_range(int x) {
    return x>=0;
}
int bfs() {
    q.push(num);
    visited[num]=1;
    while(!q.empty()) {
        step++;
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            int top = q.front();
            if(top==1) return step;
            q.pop();
            if(top%3==0 && check_range(top/3) && visited[top/3]==0) {
                visited[top/3]=1;
                q.push(top/3);
            }
            if(top%2==0 && check_range(top/2) && visited[top/2]==0) {
                visited[top/2]=1;
                q.push(top/2);
            }
            if(check_range(top-1) && visited[top-1]==0) {
                visited[top-1]=1;
                q.push(top-1);
            }
        }
    }
}
int main()
{
    cin>>num;
    cout<<bfs()<<'\n';
    return 0;
}
