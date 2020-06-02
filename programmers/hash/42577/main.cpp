#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i=0;i<phone_book.size();i++) {
        string s = phone_book[i];
        for(int j=1;j<s.size();j++) {
            string ts = s.substr(0,j);
            auto iter = find(phone_book.begin(), phone_book.end(), ts);
            if(iter!=phone_book.end()) {
                answer=false;
                break;
            }
        }
        if(answer==false) break;
    }
    return answer;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
