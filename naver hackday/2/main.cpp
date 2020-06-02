#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<string> id_list, int k) {
    int answer = 0;
    map<string, int> m;
    for(int i=0;i<id_list.size();i++) {
        set<string> namelist;
        string s = id_list[i];
        string name="";
        for(int j=0;j<s.size();j++) {
            if(s[j]==' ') {
                if(namelist.count(name)==0) {
                    namelist.insert(name);
                    if(m.count(name)==0)
                        m.insert(make_pair(name, 1));
                    else {
                        if(m[name]<k) m[name]++;
                    }
                }
                name="";
            } else {
                name=name+s[j];
            }
        }
        if(namelist.count(name)==0) {
            namelist.insert(name);
            if(m.count(name)==0)
                m.insert(make_pair(name, 1));
            else {
                if(m[name]<k) m[name]++;
            }
        }
    }
    for(auto it=m.begin();it!=m.end();it++) {
//        cout<<it->first<<" "<<it->second<<'\n';
        answer=answer+(it->second);
    }
    return answer;
}

int main()
{
    cout << solution({"JAY", "JAY ELLE JAY MAY", "MAY ELLE MAY", "ELLE MAY", "ELLE ELLE ELLE", "MAY"}, 3) << endl;
    return 0;
}
