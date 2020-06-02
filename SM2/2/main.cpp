#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
vector<int> tv[300001];
vector<vector<int>> team;
queue<int> q;

int visited[300001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long ans=0;
//    freopen("input.txt","r",stdin);
    int n,m;
    cin>>n>>m;

    v.push_back(make_pair(0,0));

    for(int i=0;i<n;i++) {
        int tx, ty;
        cin>>tx>>ty;
        v.push_back(make_pair(tx, ty));
    }

    for(int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        tv[a].push_back(b);
        tv[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        vector<int> tmp;
        if(tv[i].size()==0) {
            tmp.push_back(i);
            team.push_back(tmp);
            visited[i]=1;
        }
        else {
            if(visited[i]==0) {
                q.push(i);
                visited[i]=1;
                while(!q.empty()) {
                    int qtop = q.front();
                    tmp.push_back(qtop);
                    q.pop();
                    for(int j=0;j<tv[qtop].size();j++) {
                        if(visited[tv[qtop][j]]==0) {
                            q.push(tv[qtop][j]);
                            visited[tv[qtop][j]]=1;
                        }
                    }
                }
                team.push_back(tmp);
            }
        }
    }
    for(int i=0;i<team.size();i++) {
        int xmax=INT_MIN, xmin=INT_MAX;
        int ymax=INT_MIN, ymin=INT_MAX;
        for(int j=0;j<team[i].size();j++) {
            int player = team[i][j];
            xmax=max(xmax,v[player].first);
            xmin=min(xmin,v[player].first);
            ymax=max(ymax,v[player].second);
            ymin=min(ymin,v[player].second);
//            cout<<team[i][j]<<" ";
        }
//        cout<<xmax<<' '<<xmin<<' '<<ymax<<' '<<ymin<<'\n';
        long long abil = (long long)(xmax-xmin)*2 + (long long)(ymax-ymin)*2;
        if(abil>ans) ans=abil;
//        cout<<"abil: "<<abil<<'\n';
    }
    cout << ans << '\n';
    return 0;
}
