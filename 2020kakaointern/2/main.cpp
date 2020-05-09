#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<string> operate(queue<string> q, string oper) {
    queue<string> returnq;
    long long numtmp;
    int flag=0;
    while(!q.empty()) {
        string tmp = q.front();
        q.pop();
        if(tmp=="-" || tmp=="+" || tmp=="*") {
            if(tmp==oper) {
                flag=1;
            } else {
                returnq.push(to_string(numtmp));
                returnq.push(tmp);
                flag=0;
            }
        } else {
            long long num=stoll(tmp);
            if(flag==1) {
                if(oper=="-")
                    numtmp=numtmp-num;
                else if(oper=="*")
                    numtmp=numtmp*num;
                else
                    numtmp=numtmp+num;
            } else {
                numtmp=num;
            }
        }
    }
    returnq.push(to_string(numtmp));

//    while(!returnq.empty()) {
//        cout<<returnq.front()<<' ';
//        returnq.pop();
//    }
    return returnq;
}

long long solution(string expression) {
    long long answer = 0;
    string tmp="";
    queue<string> q;
    for(int i=0;i<expression.size();i++) {
        if(expression[i]=='-' || expression[i]=='+' || expression[i]=='*') {
            q.push(tmp);
            string extmp;
            extmp.push_back(expression[i]);
            q.push(extmp);
            tmp="";
        } else {
            tmp=tmp+expression[i];
        }
    }
    q.push(tmp);
//    while(!q.empty()) {
//        cout<<q.front()<<' ';
//        q.pop();
//    }
    vector<string> v = {"-", "+", "*"};
    sort(v.begin(), v.end());
    do {
        queue<string> testq=q;
//        cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<'\n';
        for(int i=0;i<3;i++) {
            testq=operate(testq, v[i]);
//            queue<string> tmpq=testq;
//            while(!tmpq.empty()) {
//                cout<<tmpq.front()<<' ';
//                tmpq.pop();
//            }
//            cout<<'\n';
        }
        long long ans = abs(stoll(testq.front()));
        if(ans>answer) answer=ans;
    } while(next_permutation(v.begin(), v.end()));
    return answer;
}
int main()
{
    cout<<"ans: "<<solution("50*6-3*2")<<'\n';
//    cout << "Hello world!" << endl;
    return 0;
}
