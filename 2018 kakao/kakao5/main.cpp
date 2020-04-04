#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    vector<string> str1sub;
    vector<string> str2sub;
    vector<string> inter;

    for(int i=0;i<str1.size();i++) {
        if(str1[i]>='a'&&str1[i]<='z') {
            str1[i]=str1[i]+'A'-'a';
        }
    }
    for(int i=0;i<str1.size()-1;i++) {
        string tmp="";
        if(str1[i]>='A' &&str1[i]<='Z'&&str1[i+1]>='A'&&str1[i+1]<='Z') {
            tmp=tmp+str1[i]+str1[i+1];
        }
        if(tmp!="")
            str1sub.push_back(tmp);
    }
//    for(int i=0;i<str1sub.size();i++) {
//        cout<<str1sub[i]<<" ";
//    }
//    cout<<"==============="<<'\n';
    for(int i=0;i<str2.size();i++) {
        if(str2[i]>='a'&&str2[i]<='z') {
            str2[i]=str2[i]+'A'-'a';
        }
    }
    for(int i=0;i<str2.size()-1;i++) {
        string tmp="";
        if(str2[i]>='A' &&str2[i]<='Z'&&str2[i+1]>='A'&&str2[i+1]<='Z') {
            tmp=tmp+str2[i]+str2[i+1];
        }
        if(tmp!="")
            str2sub.push_back(tmp);
    }
//    for(int i=0;i<str2sub.size();i++) {
//        cout<<str2sub[i]<<" ";
//    }
    sort(str1sub.begin(), str1sub.end());
    sort(str2sub.begin(), str2sub.end());

    set_intersection(str1sub.begin(), str1sub.end(), str2sub.begin(), str2sub.end(), back_inserter(inter));
//    cout<<"inter size: "<<inter.size()<<'\n';
    if(str1sub.size()==0 && str2sub.size()==0) return 65536;
    int answer = (double)inter.size()/(double)(str1sub.size()+str2sub.size()-inter.size())*65536;
    return answer;
}

int main()
{
    cout<<solution("aa1+aa2", "AAAA12")<<'\n';
    cout << "Hello world!" << endl;
    return 0;
}
