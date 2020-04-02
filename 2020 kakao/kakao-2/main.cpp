#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

bool checkfair(string s) {
    int stnum=0;
    int ennum=0;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(')
            stnum++;
        else
            ennum++;
    }
    if(stnum==ennum) return true;
    else return false;
}

bool checkright(string s) {
    for(int i=0;i<s.size();i++) {
        if(s[i]=='(')
            st.push(1);
        else {
            if(!st.empty())
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

string go(string p) {
    if(checkright(p)) return p;
    string u;
    string v;
    for(int i=2;i<=p.size();i=i+2) {
        u = p.substr(0,i);
        v = p.substr(i);
        if(checkfair(u)) break;
//        cout<<"u: "<<u<<" v: "<<v<<'\n';
    }
    if(checkright(u)) {
        return u+go(v);
    } else {
        string ss="("+go(v)+")";
        string tmp = u.substr(1, u.size()-2);
        for(int i=0;i<tmp.size();i++) {
            if(tmp[i]=='(')
                ss=ss+')';
            else
                ss=ss+'(';
        }
        return ss;
    }
}
string solution(string p) {
    string answer = go(p);
    return answer;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cout<<"ans: "<<solution("()))((()")<<'\n';
}
