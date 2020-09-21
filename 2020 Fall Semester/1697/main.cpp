#include <iostream>
#include <queue>

using namespace std;
int n,m;
int visited[100001];
queue<int> q;

bool check_range(int t) {
    return (t>=0 && t<=100000);
}

int bfs() {
    q.push(n);
    visited[n]=1;
    int step = -1;
    while(!q.empty()) {
        step++;
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            int top = q.front();
            q.pop();
//            cout<<top<<'\n';
            if(top==m) return step;
            int t = top-1;
            if(check_range(t) && visited[t]==0) {
                q.push(t);
                visited[t]=1;
            }
            t = top+1;
            if(check_range(t) && visited[t]==0) {
                q.push(t);
                visited[t]=1;
            }
            t = top*2;
            if(check_range(t) && visited[t]==0) {
                q.push(t);
                visited[t]=1;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    cout<<bfs()<<'\n';
//    cout << "Hello world!" << endl;
    return 0;
}
