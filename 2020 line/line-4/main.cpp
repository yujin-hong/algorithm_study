#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
    set<string> numset;
    map<string, int> m;
    vector<vector<string>> answer;

    for(int i=0;i<snapshots.size();i++) {
        // cout<<stoi(snapshots[i][1])<<'\n';
        m[snapshots[i][0]]=stoi(snapshots[i][1]);
    }

    for(int i=0;i<transactions.size();i++) {
        vector<string> s = transactions[i];
        // cout<<"-----"<<'\n';
        if(numset.count(s[0])==0){
            numset.insert(s[0]);
            if(s[1]=="SAVE") {
                if(m.count(s[2])==0) {
                    m[s[2]]=stoi(s[3]);
                } else {
                    m[s[2]]=m[s[2]]+stoi(s[3]);
                }
            } else if(s[1]=="WITHDRAW") {
                if(m.count(s[2])==0) {
                    m[s[2]]=stoi(s[3])*-1;
                } else {
                    m[s[2]]=m[s[2]]-stoi(s[3]);
                }
            }
        } else continue;
    }
    for(auto it=m.begin();it!=m.end();it++) {
        vector<string> tmp;
        tmp.push_back(it->first);
        tmp.push_back(to_string(it->second));
        answer.push_back(tmp);
    }
    return answer;
}
int main()
{
    vector<vector<string>> snapshots = {  {"ACCOUNT1", "100"},  {"ACCOUNT2", "150"}};
    vector<vector<string>> trans = {    {"4", "SAVE", "ACCOUNT3", "500"},{"1", "SAVE", "ACCOUNT2", "100"},
  {"2", "WITHDRAW", "ACCOUNT1", "50"},
  {"1", "SAVE", "ACCOUNT2", "100"},
  {"3", "WITHDRAW", "ACCOUNT2", "30"}};
    vector<vector<string>> s = solution(snapshots, trans);
    for(int i=0;i<s.size();i++) {
        cout<<s[i][0]<<" "<<s[i][1]<<'\n';
    }
//    cout << "Hello world!" << endl;
    return 0;
}
