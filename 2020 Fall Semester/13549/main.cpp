#include <iostream>
#include <deque>

using namespace std;
int n,m;
int visited[100001];
deque<pair<int, int>> q;

bool check_range(int t) {
    return (t>=0 && t<=100000);
}

int bfs() {
    q.push_back(make_pair(0, n));
    visited[n]=1;
    while(!q.empty()) {
        pair<int, int> top = q.front();
        int time = top.first;
        int ind = top.second;
//        cout<<time<<' '<<ind<<'\n';
        if(ind==m) return time;
        q.pop_front();

        int tx = ind*2;
        if(check_range(tx) && visited[tx]==0) {
            q.push_front(make_pair(time, tx));
            visited[tx]=1;
        }

        tx = ind-1;
        if(check_range(tx) && visited[tx]==0) {
            q.push_back(make_pair(time+1, tx));
            visited[tx]=1;
        }

        tx = ind+1;
        if(check_range(tx) && visited[tx]==0) {
            q.push_back(make_pair(time+1, tx));
            visited[tx]=1;
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
