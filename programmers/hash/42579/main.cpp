#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first==b.first) {
        return a.second<b.second;
    } else {
        return a.first>b.first;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    map<string, vector<pair<int,int>>> tm;
    for(int i=0;i<genres.size();i++) {
        if(m.count(genres[i])==0) {
            m[genres[i]]=plays[i];
            vector<pair<int, int>> v;
            v.push_back(make_pair(plays[i], i));
            tm[genres[i]]=v;
        } else {
            m[genres[i]]=m[genres[i]]+plays[i];
            vector<pair<int, int>> v=tm[genres[i]];
            v.push_back(make_pair(plays[i], i));
            tm[genres[i]]=v;
        }
    }
    vector<pair<int, string>> v;
    for(auto it=m.begin(); it!=m.end(); it++) {
        v.push_back(make_pair(it->second, it->first));
    }
    for(auto it=tm.begin(); it!=tm.end(); it++) {
        vector<pair<int,int>> vv = it->second;
        sort(vv.begin(), vv.end(), compare);
        tm[it->first]=vv;
    }
    sort(v.begin(), v.end(), greater<pair<int, string>>());
    for(int i=0;i<v.size();i++) {
        answer.push_back(tm[v[i].second][0].second);
        if(tm[v[i].second].size()>1) {
            answer.push_back(tm[v[i].second][1].second);
        }
    }
    return answer;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
