#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[11][11];

int num;

bool visited[11];

vector<int> ans;

void go(int start, int sum, int depth, int fin) {

//    cout<<depth<<" "<<start<<" "<<sum<<'\n';

    if(depth==num-1) {
//        cout<<"==============="<<'\n';
//        cout<<sum+a[start][fin]<<'\n';
        if(a[start][fin]!=0)
            ans.push_back(sum+a[start][fin]);
        return;
    }
    for(int i=0;i<num;i++) {
        if(a[start][i]!=0 && visited[i]==false) {
            visited[i]=true;
            go(i, sum+a[start][i], depth+1, fin);
            visited[i]=false;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    cin>>num;
    for(int i=0;i<num;i++) {
        for(int j=0;j<num;j++) {
            int tmp;
            cin>>tmp;
            a[i][j]=tmp;
        }
    }
//    for(int i=0;i<num;i++) {
//        for(int j=0;j<num;j++) {
//            cout<<a[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
    for(int i=0;i<num;i++) {
        visited[i]=true;
        go(i, 0, 0, i);
        visited[i]=false;
    }
    auto a = min_element(ans.begin(), ans.end());
    cout<<*a<<'\n';
    return 0;
}
