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

string convert_longlong(long long time) {
    int hour = time/3600;
    string shour = to_string(hour);
    if(shour.size()==1) shour = "0"+shour;
    int remain = time%3600;
    int minute = remain/60;
    string smin = to_string(minute);
    if(smin.size()==1) smin = "0"+smin;
    int second = remain%60;
    string ssecond = to_string(second);
    if(ssecond.size()==1) ssecond = "0"+ssecond;
    return shour+":"+smin+":"+ssecond;
}

//string add_time(string start, string play) {
//    vector<string> unrefined_add_time;
//    vector<string> splitted_start = parse_using_delimeter(start, ":");
//    vector<string> splitted_play = parse_using_delimeter(play, ":");
//    for(int i=0;i<3;i++) {
//        unrefined_add_time.push_back(splitted_start[i]+splitted_play[i]);
//    }
//
//    string start_hour =
//}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    long long answer_time=0;
    sort(logs.begin(), logs.end());
    long long expired_time = convert_time(play_time);
    long long long_adv_time = convert_time(adv_time);
    long long max_sample_play_time = 0;
    long long last_end_time = 0;

    for(int i=0;i<logs.size();i++) {
        string log = logs[i];
        long long end_time = convert_time(parse_using_delimeter(log, "-")[1]);
        if(end_time>last_end_time) last_end_time = end_time;
    }

    for(int i=0;i<logs.size();i++){
        string log = logs[i];
//        cout<<log<<'\n';
        long long start_time = convert_time(parse_using_delimeter(log, "-")[0]);
        long long end_time = convert_time(parse_using_delimeter(log, "-")[1]);
        long long sample_end_time = start_time+long_adv_time;
        if(sample_end_time>expired_time) break;

        long long sample_play_time = long_adv_time;
        if(end_time<sample_end_time) sample_play_time = end_time-start_time;
        for(int j=i+1;j<logs.size();j++) {
            string test_log = logs[j];
            long long test_start_time = convert_time(parse_using_delimeter(test_log, "-")[0]);
            long long test_end_time = convert_time(parse_using_delimeter(test_log, "-")[1]);
            if(test_start_time>=sample_end_time) break;

            if(test_end_time<sample_end_time) sample_play_time = sample_play_time + (test_end_time-test_start_time);
            else sample_play_time = sample_play_time + (sample_end_time-test_start_time);
        }
//        cout<<convert_longlong(start_time)<<' '<<convert_longlong(sample_play_time)<<'\n';
        if(sample_play_time > max_sample_play_time) {
            max_sample_play_time = sample_play_time;
            answer_time = start_time;
        }

    }
//    cout<<"asdfasdfasdf"<<'\n';
//    cout<<"ans time: "<<convert_longlong(answer_time)<<'\n';
//    sort(logs.begin(), logs.end(), greater<string>());
//    if(answer_time==0 && logs[logs.size()-1])
    if(answer_time == 0) {
        if(last_end_time-long_adv_time>0) answer_time = last_end_time-long_adv_time;
    }

    answer = convert_longlong(answer_time);
    return answer;
}

int main()
{
    string play_time = "99:59:59";
    string adv_time = "25:00:00";
    vector<string> logs = {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"};
    cout << solution(play_time, adv_time, logs)<< endl;
    return 0;
}
