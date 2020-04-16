#include <iostream>
#include <queue>

using namespace std;

int visited[11][11];
int check[11][11][11][11];

queue<pair<int, int>> rq;
queue<pair<int, int>> bq;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    int n,m;
    int bx, by;
    pair<int, int> b;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            if(ch=='#') visited[i][j]=-1;
            else if(ch=='R') rq.push(make_pair(i,j));
            else if(ch=='B') bq.push(make_pair(i,j));
            else if(ch=='O') visited[i][j]=-2;
        }
    }

    int num=1;
    int ans=0;
    while(!rq.empty() && !bq.empty()) {
//        if(num>10) {ans=-1; break;}
        int rqsize = rq.size();
        cout<<"==================== "<<rqsize<<'\n';

        for(int i=0;i<rqsize;i++) {
            int rx = rq.front().first;
            int ry = rq.front().second;
            int bx = bq.front().first;
            int by = bq.front().second;
            cout<<rx<<" "<<ry<<" "<<bx<<" "<<by<<'\n';
            rq.pop();
            bq.pop();
            for(int j=0;j<4;j++) {
                int bfl=0;
                int ttbx=bx;
                int ttby=by;
                int ttrx=rx;
                int ttry=ry;
                while(1) {
                    ttbx=ttbx+dx[j];
                    ttby=ttby+dy[j];
                    if(ttbx==rx && ttby==ry) bfl=1;
                    if(visited[ttbx][ttby]!=0) break;
                }
                int rfl=0;
                while(1) {
                    ttrx=ttrx+dx[j];
                    ttry=ttry+dy[j];
                    if(bx==ttrx && by==ttry) rfl=1;
                    if(visited[ttrx][ttry]!=0) break;
                }
                cout<<"tt"<<ttrx<<" "<<ttry<<" "<<ttbx<<" "<<ttby<<'\n';

                if(visited[ttrx][ttry]==-2) {
                    if(visited[ttrx][ttry]==visited[ttbx][ttby]) continue;
                    else {ans=num; break;}
                } else if(visited[ttbx][ttby]==-2) {
                    continue;
                } else {
//                    cout<<"go to queue"<<'\n';
                    if(check[ttrx-(rfl+1)*dx[j]][ttry-(rfl+1)*dy[j]][ttbx-(bfl+1)*dx[j]][ttby-(bfl+1)*dy[j]]==0) {
                        bq.push(make_pair(ttbx-(bfl+1)*dx[j], ttby-(bfl+1)*dy[j]));
                        rq.push(make_pair(ttrx-(rfl+1)*dx[j], ttry-(rfl+1)*dy[j]));
                        check[ttrx-(rfl+1)*dx[j]][ttry-(rfl+1)*dy[j]][ttbx-(bfl+1)*dx[j]][ttby-(bfl+1)*dy[j]]=1;
                    }
                }
                cout<<rq.size()<<'\n';

//                    if(visited[tx][ty]==-2) {
////                            cout<<"hohohoho"<<'\n';
//                        if(bx==tx && by==ty) {
//                            ans=-1;
//                        } else {
//                            ans=num;
//                        }
//                        break;
//                    }
//                    if(bx==tx && by==ty) { bx=bx-dx[j]; by=by-dy[j]; }


//                    q.push(make_pair(tx-dx[j], ty-dy[j]));
//                }
            }
//            cout<<"nowans: "<<ans<<'\n';
            if(ans!=0) break;
        }
        if(ans!=0) break;
        num++;
    }
//    cout<<"origin: "<<ans<<'\n';
    if(ans==0) ans=-1;
    cout <<ans << '\n';
    return 0;
}
