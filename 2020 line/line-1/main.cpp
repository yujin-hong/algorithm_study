#include <string>
#include <vector>
#include <iostream>

using namespace std;
int check[5];
int solution(string inputString) {
    int answer = -1;
    int ans=0;
    int fl=0;
    for(int i=0;i<inputString.size();i++) {
        char ch=inputString[i];
        if(ch=='(') {check[0]++; ans++;}
        else if(ch=='{') {check[1]++; ans++;}
        else if(ch=='[') {check[2]++; ans++;}
        else if(ch=='<') {check[3]++; ans++;}
        else if(ch==')') check[0]--;
        else if(ch=='}') check[1]--;
        else if(ch==']') check[2]--;
        else if(ch=='>') check[3]--;
        if(check[0]<0 || check[1]<0 || check[2]<0 || check[3]<0) {
            answer=-1;
            fl=1;
            break;
        }
    }
    if(fl==0 &&check[0]==0 && check[1]==0 && check[2]==0 && check[3]==0) {
        answer=ans;
    }
    return answer;
}

int main()
{
    cout << solution("if ") << endl;
    return 0;
}
