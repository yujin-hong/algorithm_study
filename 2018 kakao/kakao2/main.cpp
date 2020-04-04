#include <string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

string tmp="";
int ans;

int solution(string dartResult) {
    ans=0;
    vector<int> ansvec;

    for(int i=0;i<dartResult.size();i++) {
        char ch = dartResult[i];
//        cout<<ch<<'\n';
        if(ch=='S') {
            ans=ans+pow(stoi(tmp),1);
            ansvec.push_back(pow(stoi(tmp),1));
            tmp="";
        } else if(ch=='D') {
            ans=ans+pow(stoi(tmp),2);
            ansvec.push_back(pow(stoi(tmp),2));
            tmp="";
        } else if(ch=='T') {
            ans=ans+pow(stoi(tmp),3);
            ansvec.push_back(pow(stoi(tmp),3));
            tmp="";
        } else if(ch=='*') {
//            cout<<ansvec.size()<<'\n';
            ans=ans+ansvec[ansvec.size()-1];
            ansvec[ansvec.size()-1]*=2;
            if(ansvec.size()>1) {
                ans=ans+ansvec[ansvec.size()-2];
                ansvec[ansvec.size()-2]*=2;
            }
        } else if(ch=='#') {
            ans=ans-2*ansvec[ansvec.size()-1];
            ansvec[ansvec.size()-1]*=(-1);
        } else {
//            cout<<"number"<<'\n';
            tmp=tmp+ch;
        }
//        cout<<"ch: "<<ch<<" ans: "<<ans<<'\n';
    }
    int answer = ans;
    return answer;
}

int main()
{
    cout<< solution("1S2D*3T")<<'\n';
    cout<<solution("1D2S#10S")<<'\n';
    cout<<solution("1D2S0T")<<'\n';
    cout<<solution("1S*2T*3S")<<'\n';
    cout<<solution("1D#2S*3S")<<'\n';
    cout<<solution("1T2D3D#")<<'\n';
    cout<<solution("1D2S3T*")<<'\n';

    cout << "Hello world!" << endl;
    return 0;
}
