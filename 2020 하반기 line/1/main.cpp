#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];


int solution(vector<vector<int>> boxes) {
    int countnum=0;

    int boxsize = boxes.size();
    for(int i=0;i<boxsize;i++) {
        vector<int> box = boxes[i];
        arr[box[0]]++;
        if(arr[box[0]]%2==0) {countnum++;}
        arr[box[1]]++;
        if(arr[box[1]]%2==0) {countnum++;}
    }
    int answer = boxsize-countnum;
    return answer;
}
int main()
{
    vector<vector<int>> boxes = {{1, 2}, {2, 1}, {3, 3}, {4, 5}, {5, 6}, {7, 8}};
    cout << solution(boxes) << endl;
    return 0;
}
