#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
int visited[100001];

int main()
{
    int n,m;
    cin>>n>>m;
    q.push(n);
    visited[n]=1;
    int len=0;
    int fl=0;
    while(!q.empty()) {
        int qsize = q.size();
        for(int i=0;i<qsize;i++) {
            int val = q.front();
//            cout<<val<<" ";
            if(val==m) {
                fl=1;
                break;
            }
            q.pop();
            if(visited[val-1]==0 && val-1>=0) {
                visited[val-1]=1;
                q.push(val-1);
            }
            if(m>=n) {
                if(visited[val+1]==0 && val+1>=0 && val+1<=100000) {
                    visited[val+1]=1;
                    q.push(val+1);
                }
                if(visited[val*2]==0 && val*2>=0 && val*2<=100000) {
                    visited[val*2]=1;
                    q.push(val*2);
                }
            }
        }
//        cout<<"====================================================="<<'\n';

        if(fl==1) break;
        len=len+1;

    }


    cout << len << '\n';
    return 0;
}
