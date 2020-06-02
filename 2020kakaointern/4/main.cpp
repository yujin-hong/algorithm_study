#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int nmin=INT_MAX;
int visitval[26][26];

void dfs(int x, int y, int str, int cur, int prevx, int prevy, vector<vector<int>> board) {
    if(x==board.size()-1 && y==board.size()-1) {
        int res = str*100+(cur-1)*500;
        cout<<res<<'\n';
        if(res<nmin) nmin=res;
        return;
    }
    int tmpval = str*100+(cur-1)*500;

    if(tmpval>visitval[x][y]) return;
    else visitval[x][y]=str*100+(cur-1)*500;

    for(int i=0;i<4;i++) {
        int px=x+dx[i];
        int py=y+dy[i];
        if(px>=0 && py>=0 && px<board.size() && py<board.size() && board[px][py]==0) {
            board[px][py]=1;
            if(prevx==dx[i] && prevy==dy[i]) {
                dfs(px, py, str+1, cur, dx[i], dy[i], board);
            } else {
                dfs(px, py, str+1, cur+1, dx[i], dy[i], board);
            }
            board[px][py]=0;
        }
    }

}
int solution(vector<vector<int>> board) {
    int answer = 0;
    for(int i=0;i<26;i++) {
        for(int j=0;j<26;j++) {
            visitval[i][j]=INT_MAX;
        }
    }
    dfs(0, 0, 0, 0, 0, 0, board);
//    cout<<nmin<<'\n';
    answer=nmin;

//    for(int i=0;i<board.size();i++) {
//        for(int j=0;j<board.size();j++) {
//            cout<<board[i][j]<<' ';
//        }
//        cout<<'\n';
//    }

    return answer;
}
int main()
{
    cout<<"ans: "<<solution({{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}})<<'\n';
    cout << "Hello world!" << endl;
    return 0;
}
