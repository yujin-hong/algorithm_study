#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
// 다 넘어버리면 그때는 끝에부터 시간 조정
long long convert_time(string time) {
    long long converted_time;
    vector<string> splitted_time = parse_using_delimeter(time, ":");
    return stoll(splitted_time[0])*3600 + stoll(splitted_time[1])*60 + stoll(splitted_time[2]);
}

//string convert_longlong(long long time) {
//    int hour = time/3600;
//    string shour = to_string(hour);
//    if(shour.size()==1) shour = "0"+shour;
//    int remain = time%3600;
//    int minute = remain/60;
//    string smin = to_string(minute);
//    if(smin.size()==1) smin = "0"+smin;
//    int second = remain%60;
//    string ssecond = to_string(second);
//    if(ssecond.size()==1) ssecond = "0"+ssecond;
//    return shour+":"+smin+":"+ssecond;
//}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    long long answer_time=0;
    vector<pair<long long, int>> v;
    vector<pair<long long, int>> people_for_time;

    for(int i=0;i<logs.size();i++) {
        string log = logs[i];
        long long start_time = convert_time(parse_using_delimeter(log, "-")[0]);
        long long end_time = convert_time(parse_using_delimeter(log, "-")[1]);
        v.push_back(make_pair(start_time, 1));
        v.push_back(make_pair(end_time, -1));
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for(int i=0;i<v.size();i++) {
        sum=sum+v[i].second;
        people_for_time.push_back(make_pair(v[i].first, sum));
//        cout<<v[i].first<<' '<<v[i].second<<'\n';
    }
    for(int i=0;i<people_for_time.size();i++) {
        cout<<people_for_time[i].first<<' '<<people_for_time[i].second<<'\n';
    }
    return answer;
}
int main()
{
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};
    cout << solution(play_time, adv_time, logs)<< endl;
    return 0;
}
