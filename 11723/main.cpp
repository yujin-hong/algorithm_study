#include <iostream>
#include <vector>
#include <set>

using namespace std;

int a[21];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    cout<<num<<'\n';
    for(int i=0;i<num;i++) {
        string str;
        int tmp;
        cin>>str;
//        cout<<str<<'\n';
        if(str=="add") {
            cin>>tmp;
            a[tmp]=1;
        } else if (str=="check") {
            cin>>tmp;
            cout<<a[tmp]<<'\n';
        } else if(str=="remove") {
            cin>>tmp;
            a[tmp]=0;
        } else if(str=="toggle") {
            cin>>tmp;
            a[tmp]=!a[tmp];
        } else if(str=="all") {
            for(int i=1;i<=20;i++) {
                a[i]=1;
            }
        } else if(str=="empty") {
            for(int i=1;i<=20;i++) {
                a[i]=0;
            }
        }
    }
    return 0;
}
