#include <string>
#include <vector>
#include <iostream>
#include <map>


using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, vector<string>> m;
    for(int i=0;i<clothes.size();i++) {
        if(m.count(clothes[i][1])==0) {
            vector<string> tmpv;
            tmpv.push_back(clothes[i][0]);
            m.insert(make_pair(clothes[i][1], tmpv));
        } else {
            vector<string> tmpv=m[clothes[i][1]];
            tmpv.push_back(clothes[i][0]);
            m[clothes[i][1]]=tmpv;
        }
    }
    int answer=1;
    for(auto iter=m.begin(); iter!=m.end(); iter++) {
        vector<string> v = iter->second;
        answer=answer*(v.size()+1);
    }
//    cout<<m.size()<<'\n';
    return answer;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
