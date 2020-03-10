#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;

int arr[1001];

int go(int num) {
    for(int i=2;i<=num;i++) {
        int ans=INT_MAX;
        for(int j=1;j<=i;j++) {
            ans=min(ans,v[j-1]+arr[i-j]);
        }
        arr[i]=ans;
    }
    return arr[num];
}
int main()
{
     freopen("input.txt","r",stdin);
    int num;
    cin>>num;
    for(int i=0;i<num;i++) {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    arr[1]=v[0];
    cout<<go(num);
//    cout << "Hello world!" << endl;
    return 0;
}
