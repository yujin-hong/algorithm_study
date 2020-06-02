#include <iostream>
#include <stack>
#include <map>

using namespace std;
stack<int> s;
map<int, int> m;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int n;
        cin>>n;
        m.insert(make_pair(n, i+1));
        while(s.size()!=0 && n>s.top()) {
            s.pop();
        }
        if(s.size()==0) {
            cout<<0<<'\n';
        } else {
            cout<<m[s.top()]<<'\n';
        }
        s.push(n);

    }
    return 0;
}
