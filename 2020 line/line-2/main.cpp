#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> comp(string str1, string str2, string answer) {
//    cout<<str1<<" "<<str2<<'\n';
    int tmp=0;
    int n=0;
    int nmax=0;
    for(int i=0;i<str1.size();i++) {
//        cout<<"tes: "<<str1[i]<<" "<<str2[i]<<" "<<answer[i]<<'\n';
        if(str1[i]==str2[i] && answer[i]!=str1[i]) {
            n++;
            tmp++;
        } else {
            if(tmp>nmax) nmax=tmp;
            tmp=0;
        }
    }
    if(tmp>nmax) nmax=tmp;
//    cout<<"nmax: "<<nmax<<" n: "<<n<<'\n';
    return make_pair(nmax, n);
}
int solution(string answer_sheet, vector<string> sheets) {
    int answer = 0;
    vector<int> turn;
    turn.push_back(0);
    turn.push_back(0);
    for(int i=2;i<sheets.size();i++) turn.push_back(1);
    do {
        int tmpans=0;
        vector<string> cmp;
        for(int i=0;i<turn.size();i++) {
            if(turn[i]==0) cmp.push_back(sheets[i]);
        }
        pair<int, int> ansset = comp(cmp[0], cmp[1], answer_sheet);
        tmpans=ansset.second+ansset.first*ansset.first;
        if(tmpans>answer) answer=tmpans;
        // for(int i=0;i<cmp.size();i++) {
        //     cout<<cmp[i]<<" ";
        // }
        // cout<<'\n';

    } while(next_permutation(turn.begin(), turn.end()));
    return answer;
}
int main()
{
    cout<<solution("4132315142", {"3241523133", "4121314445", "3243523133", "4433325251", "2412313253"})<<'\n';
    return 0;
}
