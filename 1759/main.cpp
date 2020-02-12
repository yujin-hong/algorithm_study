#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> v;

int num1, num2;

void go(int num, int ja, int mo, int ind, string str) {
//    cout<<str<<'\n';
    string new_str;
    if(num==num1) {
        if(ja>=2 && mo>=1) {
            cout<<str<<'\n';
        }
        return;
    }
    if(ind==num2) {
        return;
    }
    for(int i=ind;i<num2;i++) {
        new_str = str + v[i];
        if(v[i]=='a' || v[i]=='e' || v[i]=='i' || v[i]=='o' || v[i]=='u') {
            go(num+1, ja, mo+1, i+1, new_str);
        } else {
            go(num+1, ja+1, mo, i+1, new_str);
        }
    }
}
int main()
{
    // freopen("input.txt","r",stdin);
    cin>>num1>>num2;
    for(int i=0;i<num2;i++) {
        char ch;
        cin>>ch;
        v.push_back(ch);
    }
    sort(v.begin(), v.end());


//    for(int i=0;i<num2;i++) {
//        cout<<v[i]<<'\n';
//    }

    go(0, 0, 0, 0, "");

    return 0;
}
