#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int visited[9];
vector<vector<int>> ans;
void go(vector<int> v, int st, vector<vector<string>> relation) {
    if(st>=relation[0].size()) return;
//    for(int i=0;i<v.size();i++) {
//        cout<<v[i]<<" ";
//    }
//    cout<<st<<'\n';
    set<string> s;
    for(int j=0;j<relation.size();j++) {
        string tmp="";
        for(int i=0;i<v.size();i++) {
            tmp=tmp+relation[j][v[i]]+',';
        }
        s.insert(tmp+relation[j][st]);
    }
    v.push_back(st);
    if(s.size()==relation.size()) {
//        cout<<"good"<<'\n';
        ans.push_back(v);
        return;
//        go(v, st+1, relation);
    }
    for(int i=st+1;i<relation[0].size();i++) {
        go(v, i, relation);
    }
}

int solution(vector<vector<string>> relation) {
    vector<int> v={};
    for(int i=0;i<relation[0].size();i++) {
        go(v, i, relation);
    }
    sort(ans.begin(), ans.end());
    int answer=ans.size();
    for(int i=0;i<ans.size();i++) {
        vector<int> testv = ans[i];
        int fl=0;
        for(int j=0;j<testv.size();j++) {
            vector<int> tv=testv;
            tv.erase(tv.begin()+j);
            for(int k=0;k<ans.size();k++) {
                if(tv==ans[k]) {
                    answer--;
                    fl=1;
                    break;
                }
            }
            if(fl==1) break;
        }
    }

//    int answer = 0;
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<string>> relation={{"100","ryan","music", "2"},{"200","apeach","math", "2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    cout<<solution(relation)<<'\n';
    return 0;
}
