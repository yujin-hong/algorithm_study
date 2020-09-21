#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int arr_size = 100000;
pair<int, int> arr[100001];

vector<int> solution(int n) {
    for(int i=1;i<=arr_size;i++) {
        if(i<10) {
            arr[i]=make_pair(0, i);
        } else {
            string s = to_string(i);
            int min_count = INT_MAX;
            int alone_num;

            //first_res
            string first_num = s.substr(0, s.size()/2);
            string second_num = s.substr(s.size()/2, s.size()-s.size()/2);
            int add_num = 1;
            if(second_num.size()!=1 && second_num[0]=='0') {
                for(int j=0;j<second_num.size();j++) {
                    if(second_num[j]=='0') add_num++;
                    else break;
                }
                if(second_num[second_num.size()-1]=='0') add_num = add_num-1;
            }
            int first_num_long = stoi(first_num);
            int second_num_long = stoi(second_num);
            int sample_result = first_num_long + second_num_long;
            pair<int, int> sample_res_pair = arr[sample_result];
            if(sample_res_pair.first<min_count) {
                min_count = sample_res_pair.first+add_num;
                alone_num = sample_res_pair.second;
            }

            if(s.size()%2!=0) {
                add_num = 1;
                first_num = s.substr(0, s.size()/2+1);
                second_num = s.substr(s.size()/2+1, s.size()-s.size()/2-1);
//                cout<<first_num<<' '<<second_num<<'\n';
                if(second_num.size()!=1 && second_num[0]=='0') {
                    for(int j=0;j<second_num.size();j++) {
                        if(second_num[j]=='0') add_num++;
                        else break;
                    }
                    if(second_num[second_num.size()-1]=='0') add_num = add_num-1;
                }

                int first_num_long = stoi(first_num);
                int second_num_long = stoi(second_num);
                int sample_result = first_num_long + second_num_long;
                pair<int, int> sample_res_pair = arr[sample_result];
                if(sample_res_pair.first<min_count) {
                    min_count = sample_res_pair.first+add_num;
                    alone_num = sample_res_pair.second;
                }

            }
            arr[i] = make_pair(min_count, alone_num);
        }
//        cout<<i<<' '<<arr[i].first<<' '<<arr[i].second<<'\n';
    }

    vector<int> answer;
    if(n<=100000) {
        answer.push_back(arr[n].first);
        answer.push_back(arr[n].second);
    } else {
        string s = to_string(n);
        int min_count = INT_MAX;
        int alone_num;

        //first_res
        string first_num = s.substr(0, s.size()/2);
        string second_num = s.substr(s.size()/2, s.size()-s.size()/2);
        int add_num = 1;
        if(second_num.size()!=1 && second_num[0]=='0') {
            for(int j=0;j<second_num.size();j++) {
                if(second_num[j]=='0') add_num++;
                else break;
            }
            if(second_num[second_num.size()-1]=='0') add_num = add_num-1;
        }
        int first_num_long = stoi(first_num);
        int second_num_long = stoi(second_num);
        int sample_result = first_num_long + second_num_long;
        pair<int, int> sample_res_pair = arr[sample_result];
        if(sample_res_pair.first<min_count) {
            min_count = sample_res_pair.first+add_num;
            alone_num = sample_res_pair.second;
        }

        if(s.size()%2!=0) {
            add_num = 1;
            first_num = s.substr(0, s.size()/2+1);
            second_num = s.substr(s.size()/2+1, s.size()-s.size()/2-1);
    //                cout<<first_num<<' '<<second_num<<'\n';
            if(second_num.size()!=1 && second_num[0]=='0') {
                for(int j=0;j<second_num.size();j++) {
                    if(second_num[j]=='0') add_num++;
                    else break;
                }
                if(second_num[second_num.size()-1]=='0') add_num = add_num-1;
            }

            int first_num_long = stoi(first_num);
            int second_num_long = stoi(second_num);
            int sample_result = first_num_long + second_num_long;
            pair<int, int> sample_res_pair = arr[sample_result];
            if(sample_res_pair.first<min_count) {
                min_count = sample_res_pair.first+add_num;
                alone_num = sample_res_pair.second;
            }
        }
        answer.push_back(min_count);
        answer.push_back(alone_num);
    }
    return answer;
}

int main()
{
    vector<int> res = solution(1000000001);
    for(int i=0;i<res.size();i++) {
        cout<<res[i]<<' ';
    }
    return 0;
}
