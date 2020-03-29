#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    for(int i=0;i<board.size();i++) {
        if(board[i][moves[0]-1]!=0) {
            // cout<<board[i][moves[0]-1]<<'\n';
            s.push(board[i][moves[0]-1]);
            board[i][moves[0]-1]=0;
            break;
        }
    }

    for(int i=1;i<moves.size();i++) {
        int beforenum;
        if(s.size()==0) {
            beforenum = -1;
        } else {
            beforenum = s.top();
        }
        int nowrow = moves[i];
        for(int j=0;j<board.size();j++) {
            if(board[j][nowrow-1]!=0) {
                int nownum = board[j][nowrow-1];
                // cout<<beforenum<<" "<<nownum<<'\n';
                if(beforenum==nownum) {
                    answer=answer+2;
                    s.pop();
                } else {
                    s.push(nownum);
                }
                board[j][nowrow-1]=0;
                break;
            }
        }
    }
    return answer;
}
