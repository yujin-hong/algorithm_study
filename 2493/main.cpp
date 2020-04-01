#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> v;
stack<int> sval;
stack<int> sind;

int main()
{
    freopen("input.txt","r",stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int nmax=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        int tmp;
        cin>>tmp;
        if(tmp>nmax) {
            cout<<0<<" ";
            nmax=tmp;
            sval.push(tmp);
            sind.push(i);
        } else {
            if(tmp<v[i-1]) {
                cout<<i<<" ";
                sval.push(v[i-1]);
                sind.push(i-1);
            } else {
                while(1) {
                    int high = sval.top();
                    if(high>tmp) {
                        cout<<sind.top()+1<<" ";
                        sval.push(tmp);
                        sind.push(i);
                        break;
                    } else {
                        sval.pop();
                        sind.pop();
                    }
                }
            }
        }
        v.push_back(tmp);
    }
    return 0;
}
