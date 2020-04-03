#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<vector<string>> sentvec;
    vector<string> answer;
    map<string, string> m;

    for(int i=0;i<record.size();i++) {
        string nowstr="";
        vector<string> sent;
        for(int j=0;j<record[i].size();j++) {
            if(record[i][j]==' ') {
                sent.push_back(nowstr);
                nowstr="";
            } else {
                nowstr+=record[i][j];
            }
        }
        sent.push_back(nowstr);
        sentvec.push_back(sent);
    }
    for(int i=0;i<sentvec.size();i++) {
        // check one line
//        string oneans="";

        if(sentvec[i][0]=="Enter") {
            m[sentvec[i][1]]=sentvec[i][2];
        } else if(sentvec[i][0]=="Change") {
            m[sentvec[i][1]]=sentvec[i][2];
        }
//        for(int j=0;j<sentvec[i].size();j++) {
//            cout<<sentvec[i][j]<<'\n';
//        }
//        cout<<'\n';
    }
    for(int i=0;i<sentvec.size();i++) {
        string oneans;
        if(sentvec[i][0]=="Enter") {
            oneans=m[sentvec[i][1]]+"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            answer.push_back(oneans);
        } else if(sentvec[i][0]=="Leave") {
            oneans=m[sentvec[i][1]]+"´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            answer.push_back(oneans);
        }
    }
    return answer;
}

int main() {
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> ans = solution(record);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<'\n';
    }
    return 0;
}
