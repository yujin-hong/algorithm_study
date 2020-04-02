#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int solution(string s) {
    if(s.size()==1) return 1;
    int answer = INT_MAX;
    int start=0;
    string oldsubs="";
    string nowsubs="";

    for(int i=1;i<=s.size()/2;i++) {
        int len=0;
        int num=0;
//        nowsubs="";
        for(int j=0;j<s.size();) {
            nowsubs="";
            for(int k=j;k<j+i;k++) {
                if(k<s.size())
                    nowsubs=nowsubs+s[k];
            }
            if(nowsubs==oldsubs) {
                num++;
            } else {
                if(num>1) {
                    string snum=to_string(num);
                    len=len+snum.size();
                }
                len=len+nowsubs.size();
                oldsubs=nowsubs;
                num=1;
            }
//            cout<<nowsubs<<" "<<len<<'\n';
            j=j+i;
        }
        if(num>1) {
            string snum=to_string(num);
            len=len+snum.size();
        }
        if(len<answer) answer=len;
//        cout<<"hoho: "<<nowsubs.size()<<'\n';
//        cout<<i<<" "<<len<<'\n';
    }
    return answer;
}

int main() {
    cout<<solution("aaaaaaaaaa")<<'\n';
}
