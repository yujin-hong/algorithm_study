#include <iostream>
#include <queue>

using namespace std;

int visited[100001];
queue<int> q;

int main()
{
    int a,b;
    cin>>a>>b;
    visited[a]=1;
    q.push(a);
    int top;
    while(!q.empty()) {
        for(int i=0;i<q.size();i++) {
            top = q.front();
//            cout<<top<<'\n';
            if(top==b) break;
            int nowvis = visited[top];
            q.pop();
            if(top-1>=0 && visited[top-1]==0) {
                visited[top-1]=nowvis+1;
                q.push(top-1);
            }
            if(top+1<=100000 && visited[top+1]==0) {
                visited[top+1]=nowvis+1;
                q.push(top+1);
            }
            if(top*2<=100000 && visited[top*2]==0) {
                visited[top*2]=nowvis+1;
                q.push(top*2);
            }
        }
        if(top==b) break;
    }


    cout << visited[b]-1 << endl;
    return 0;
}
