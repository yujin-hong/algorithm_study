#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>

using namespace std;
char arr[1001];
string solution(int n, vector<vector<int>> delivery) {
    vector<tuple<int, int, int>> v;
    for(int i=0;i<delivery.size();i++) {
        tuple<int, int, int> t=make_tuple(delivery[i][2], delivery[i][0], delivery[i][1]);
        v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<tuple<int,int,int>>());
    for(int i=0;i<delivery.size();i++) {
        tuple<int, int, int> t=v[i];
//        cout<<get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<'\n';
        if(get<0>(t)==1) {
            arr[get<1>(t)]='O';
            arr[get<2>(t)]='O';
        } else {
            if(arr[get<1>(t)]=='O') {
                arr[get<2>(t)]='X';
            } else if(arr[get<2>(t)]=='O') {
                arr[get<1>(t)]='X';
            }
        }
    }
    string answer = "";
    for(int i=1;i<=n;i++) {
        if(arr[i]==NULL) arr[i]='?';
        answer=answer+arr[i];
//        cout<<i<<" "<<arr[i]<<'\n';
    }
    return answer;
}

int main()
{
    solution(6, {{1,3,1},{3,5,0},{5,4,0},{2,5,0}});
    cout << "Hello world!" << endl;
    return 0;
}
