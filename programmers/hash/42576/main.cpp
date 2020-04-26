#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<participant.size();i++) {
        if(completion[i]!=participant[i]) {
            answer=participant[i];
            break;
        }
    }
    return answer;
}

int main()
{
    cout << solution({"a", "b", "c"}, {"a", "b"}) << endl;
    return 0;
}
