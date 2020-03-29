#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
//    cout<<s<<'\n';
    vector<int> arr[501];
    int check[501];
    vector<int> answer;
    int maxsize=0;
    for(int i=1;i<s.size();) {
//         cout<<s[i]<<'\n';
        if(s[i]=='{') {
            int size;
            vector<int> v;
            string tmp="";
            while(1) {
                i++;
                if(s[i]=='}') {
                    v.push_back(stoi(tmp));
                    size=v.size();
                    cout<<"size: "<<size<<'\n';
                    for(int j=0;j<v.size();j++) {
                        cout<<"v contents: "<<v[j]<<'\n';
                    }
                    if(size>maxsize) maxsize=size;
                    arr[size]=v;
                    break;
                }
                if(s[i]==',') {
//                    cout<<tmp<<'\n';
                    v.push_back(stoi(tmp));
                    tmp="";
                    continue;
                }
                tmp=tmp+s[i];
//                cout<<"num: "<<s[i]<<'\n';
//                v.push_back(s[i]-48);
            }
            i++;
        }
        i++;
    }
//    cout<<"maxsize: "<<maxsize<<'\n';
    for(int i=1;i<=maxsize;i++) {
        vector<int> v = arr[i];
        for(int j=0;j<v.size();j++) {
//            cout<<v[j]<<" ";
            if(check[v[j]]==0) {
                answer.push_back(v[j]);
                check[v[j]]=1;
                break;
            }
//            cout<<v[j]<<" ";
        }
//        cout<<'\n';
    }
//    cout<<"ans!!"<<'\n';
    for(int i=0;i<answer.size();i++) {
        cout<<answer[i]<<" ";
    }
    return answer;
}

int main() {
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4},{2,1,3,4,100000}}";
    solution(s);
}
