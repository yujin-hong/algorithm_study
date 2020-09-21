#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

bool check_range(int x, int y, int maze_size) {
    return (x>=0 && x<maze_size && y>=0 && y<maze_size);
}

int solution(vector<vector<int>> maze) {
    int answer = 0;

    int maze_size = maze.size();
    q.push(make_pair(0, 0));
    pair<int, int> dir = make_pair(1, 0);
    int dir_ind = 2;
    int next_dir_ind = (dir_ind+1)%4;
    while(!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        if(tx==maze_size-1 && ty == maze_size-1) break;
        q.pop();
        int px = tx+dx[next_dir_ind];
        int py = ty+dy[next_dir_ind];
        if(check_range(px, py, maze_size) && maze[px][py]!=1) {
            answer++;
            q.push(make_pair(px, py));
            dir_ind = next_dir_ind;
            next_dir_ind = (dir_ind+1)%4;
        } else {
            px = tx+dx[dir_ind];
            py = ty+dy[dir_ind];
            if(check_range(px, py, maze_size) && maze[px][py]!=1) {
                answer++;
                q.push(make_pair(px, py));
            } else {
                q.push(make_pair(tx, ty));
                dir_ind = (dir_ind+3)%4;
                next_dir_ind = (dir_ind+1)%4;
            }
        }
    }
    return answer;
}

//void bfs(vector<vector<int>> maze) {
//    int maze_size = maze.size();
//    maze[0][0]=-1;
//    q.push(make_pair(0, 0));
//    pair<int, int> dir = make_pair(1, 0);
//    int dir_ind = 2;
//    int next_dir_ind = (dir_ind+1)%4;
//    while(!q.empty()) {
//        int tx = q.front().first;
//        int ty = q.front().second;
//        cout<<tx<<' '<<ty<<'\n';
//        if(tx==maze_size-1 && ty == maze_size-1) break;
//        q.pop();
//        int px = tx+dx[next_dir_ind];
//        int py = ty+dy[next_dir_ind];
//        if(check_range(px, py, maze_size) && maze[px][py]!=1) {
//            maze[px][py]=-1;
//            q.push(make_pair(px, py));
//            dir_ind = next_dir_ind;
//            next_dir_ind = (dir_ind+1)%4;
//        } else {
//            px = tx+dx[dir_ind];
//            py = ty+dy[dir_ind];
//            if(check_range(px, py, maze_size) && maze[px][py]!=1) {
//                maze[px][py]=-1;
//                q.push(make_pair(px, py));
//            } else {
//                q.push(make_pair(tx, ty));
//                dir_ind = (dir_ind+3)%4;
//                next_dir_ind = (dir_ind+1)%4;
//            }
//        }
//    }
//}
int main()
{
    vector<vector<int>> maze = 	{{0, 1, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 0}, {0, 1, 0, 0, 1, 0}, {0, 1, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0}};
    cout << solution(maze) << '\n';
    return 0;
}
