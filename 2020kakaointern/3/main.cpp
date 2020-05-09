#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <climits>
#include <map>

using namespace std;

int nmin=INT_MAX;

void go(int st, int en, int des, vector<string> gems) {
    if(st>en) return;
//    cout<<st<<' '<<en<<'\n';
    int mid = (st+en)/2;
    int flag=0;
    map<string, int> m;

    for(int i=0;i<mid;i++) {
        m[gems[i]]++;
    }
    if(m.size()==des) {
        if(mid<nmin) nmin=mid;
        flag=1;
    }

    for(int i=mid;i<gems.size();i++) {
        m[gems[i-mid]]--;
        if(m[gems[i-mid]]==0)
            m.erase(gems[i-mid]);
        m[gems[i]]++;
//        for(auto iter=m.begin();iter!=m.end();iter++) {
//            cout<<iter->first<<" "<<iter->second<<'\n';
//        }
        if(m.size()==des) {
            if(mid<nmin) nmin=mid;
            flag=1;
            break;
        }
    }
    if(flag==0) go(mid+1, en, des, gems);
    else go(st, mid-1, des, gems);
}
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s;
    for(int i=0;i<gems.size();i++) {
        s.insert(gems[i]);
    }
//    cout<<s.size()<<'\n';
    go(1, gems.size(), s.size(), gems);

    map<string, int> m;

    for(int i=0;i<nmin;i++) {
        m[gems[i]]++;
    }
    if(m.size()==s.size()) {
        answer.push_back(1);
        answer.push_back(nmin);
    } else {
        for(int i=nmin;i<gems.size();i++) {
            m[gems[i-nmin]]--;
            if(m[gems[i-nmin]]==0)
                m.erase(gems[i-nmin]);
            m[gems[i]]++;
            for(auto iter=m.begin();iter!=m.end();iter++) {
                cout<<iter->first<<" "<<iter->second<<'\n';
            }
            cout<<"================"<<'\n';
            if(m.size()==s.size()) {
                answer.push_back(i-nmin+2);
                answer.push_back(i+1);
                break;
            }
        }
    }

    cout<<nmin<<'\n';
    cout<<answer[0]<<' '<<answer[1]<<'\n';
    return answer;
}

int main()
{
    solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"});
    cout << "Hello world!" << endl;
    return 0;
}
