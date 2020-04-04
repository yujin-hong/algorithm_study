#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
int ans=0;

void go(vector<string> board) {
    set<pair<int, int>> se;
    int fl=0;
    for(int i=0;i<board.size()-1;i++) {
        string tmp = board[i];
        for(int j=0;j<tmp.size()-1;j++) {
            char now = tmp[j];
            if(now=='0') continue;
//            cout<<"now: "<<now<<'\n';
            if(now==board[i][j+1] && now==board[i+1][j] && now==board[i+1][j+1]) {
//                cout<<"suc: "<<i<<" "<<j<<'\n';
                se.insert(make_pair(i,j));
                se.insert(make_pair(i,j+1));
                se.insert(make_pair(i+1, j));
                se.insert(make_pair(i+1, j+1));
            }
        }
    }

    for(auto i=se.begin();i!=se.end();i++) {
        fl=1;
        ans++;
        pair<int, int> p=*i;
        for(int k=p.first;k>0;k--) {
            board[k][p.second]=board[k-1][p.second];
        }
        board[0][p.second]='0';
    }
    for(int i=0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<"================"<<'\n';

    if(fl==0) return;
    else go(board);


}

int solution(int m, int n, vector<string> board) {
    go(board);
    int answer = ans;
    return answer;
}
int main()
{
    vector<string> s={"AAAAA", "AAAAA", "AAAAA", "AAAAA"};
    cout<<solution(4,5,s)<<'\n';
//    cout << "Hello world!" << endl;
    return 0;
}
