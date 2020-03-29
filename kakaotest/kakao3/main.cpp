#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;
vector<string> okaylist[9];
set<set<string>> anss;
void go(int index, set<string> s, int des) {
    if(index==des) {
        anss.insert(s);
        return;
    }
    for(int i=0;i<okaylist[index].size();i++) {
        if(s.count(okaylist[index][i])==0) {
            s.insert(okaylist[index][i]);
            go(index+1, s, des);
            s.erase(okaylist[index][i]);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for(int i=0;i<banned_id.size();i++) {
        string nowbaned = banned_id[i];
        for(int j=0;j<user_id.size();j++) {
            int fl=1; // check this user id is okay
            string nowuserid = user_id[j];
            for(int k=0;k<nowbaned.size();k++) {
                if(nowbaned[k]!='*') {
                    if(nowbaned[k]!=nowuserid[k]) {
                        fl=0;
                        break;
                    }
                }
            }
            if(fl==1 && nowuserid.size()==nowbaned.size()) {
                okaylist[i].push_back(nowuserid);
            }
        }
    }

    for(int i=0;i<okaylist[0].size();i++) {
        set<string> s;
        s.insert(okaylist[0][i]);
        go(1, s, banned_id.size());
    }

    int answer = anss.size();
    return answer;
}
