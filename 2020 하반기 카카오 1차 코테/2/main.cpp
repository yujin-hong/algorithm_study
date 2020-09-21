#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> s;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i=0;i<orders.size();i++) {
        string str = orders[i];
        for(int j=0;j<str.size();j++) {
            s.insert(str[j]);
        }
    }
    vector<char> temp;
    for(auto iter=s.begin();iter!=s.end();iter++) {
//        char ch = *iter;
        temp.push_back(*iter);
    }
//    for(int i=0;i<temp.size();i++) {
//        cout<<temp[i]<<' ';
//    }
    for(int i=0;i<course.size();i++) {
        vector<int> filter;
        int accept_size = course[i];
        for(int j=0;j<temp.size();j++) {
            if(j<accept_size) {
                filter.push_back(0);
            } else {
                filter.push_back(1);
            }
        }
        vector<pair<int, string>> temp_answer;
        int maxcountnum = 0;
        do {
            vector<char> pairs;
            string pairstring = "";
            int countnum = 0;
            for(int j=0;j<temp.size();j++) {
                if(filter[j]==0) {
                    pairs.push_back(temp[j]);
                    pairstring = pairstring + temp[j];
                }
            }
            //check pairs are included in each orders;
            for(int j=0;j<orders.size();j++) {
                string str = orders[j];
                int fl = 1;
                for(int k=0;k<pairs.size();k++) {
                    char ch = pairs[k];
                    if(str.find(ch) == string::npos) {
                        fl = 0;
                        break;
                    }
                }
                if(fl==1) countnum++;
            }
            if(countnum>=2) {
                if(countnum>=maxcountnum) {
                    temp_answer.push_back(make_pair(countnum, pairstring));
                    maxcountnum = countnum;
                }
//                cout<<pairstring<<'\n';
            }
        } while(next_permutation(filter.begin(), filter.end()));
        for(int j=0;j<temp_answer.size();j++) {
            if(temp_answer[j].first == maxcountnum) {
//                cout<<temp_answer[j].second<<'\n';
                answer.push_back(temp_answer[j].second);
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders = {"XYZ", "XWY", "WXA"};
    vector<int> course = {2,3,4};
    vector<string> res = solution(orders, course);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<'\n';
    }
//    cout << solution(orders, course) << endl;
    return 0;
}
