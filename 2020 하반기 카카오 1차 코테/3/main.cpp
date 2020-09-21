#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
vector<tuple<int, string, string, string, string>> v;

vector<string> parse_using_delimeter(string str, string delimeter) {
    vector<string> temp;
    size_t pos = 0;
    string token;
    while((pos = str.find(delimeter)) != string::npos) {
        token = str.substr(0,pos);
        temp.push_back(token);
        str.erase(0, pos+delimeter.length());
    }
    temp.push_back(str);
    return temp;
}

tuple<int, string, string, string, string> parse(string str, string delimeter) {
    vector<string> temp = parse_using_delimeter(str, delimeter);
//    cout<<temp[0]<<' '<<temp[1]<<' '<<temp[2]<<' '<<temp[3]<<' '<<temp[4]<<'\n';
    return make_tuple(stoi(temp[4]), temp[0], temp[1], temp[2], temp[3]);
}

tuple<int, string, string, string, string> parse_query(string str, string delimeter) {
    vector<string> temp = parse_using_delimeter(str, delimeter);
    vector<string> t = parse_using_delimeter(temp[3], " ");
//    cout<<temp[0]<<' '<<temp[1]<<' '<<temp[2]<<' '<<t[0]<<' '<<t[1]<<'\n';
    return make_tuple(stoi(t[1]), temp[0], temp[1], temp[2], t[0]);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i=0;i<info.size();i++) {
        v.push_back(parse(info[i], " "));
    }
    sort(v.begin(), v.end(), greater<tuple<int, string, string, string, string>>());
//    for(int i=0;i<info.size();i++) {
//        cout<<get<0>(v[i])<<'\n';
//    }
    for(int i=0;i<query.size();i++) {
        int countnum = 0;
        tuple<int, string, string, string, string> q = parse_query(query[i], " and ");
        for(int j=0;j<v.size();j++) {
            tuple<int, string, string, string, string> user = v[j];
            if(get<0>(user)>=get<0>(q)) {
               if((get<1>(q)=="-" || get<1>(q) == get<1>(user))
               && (get<2>(q)=="-" || get<2>(q) == get<2>(user))
               && (get<3>(q)=="-" || get<3>(q) == get<3>(user))
               && (get<4>(q)=="-" || get<4>(q) == get<4>(user))) countnum++;
            } else {
                break;
            }
        }
        answer.push_back(countnum);
    }
    return answer;
}

int main()
{
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    vector<int> res = solution(info, query);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<' ';
    }
    return 0;
}
